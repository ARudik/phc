module TransformAPI where

import Data.List

import DataStructures 
import GrammarAnalysis
import ContextResolution
import MakeTeaMonad
import Cpp
import Util

transformClass :: MakeTeaMonad CppClass
transformClass = do
	{- API methods -}
	conc <- concreteSymbols
	c_pre <- mapM (ppConcrete "pre_") conc
	c_post <- mapM (ppConcrete "post_") conc
	c_children <- withConj $ mapM chConcrete
	{- Internal methods -}
	allTerms <- withConj $ return . nub . concat . (map conjBody)
	transforms <- mapM transform allTerms
	abs <- abstractSymbols
	a_pre <- mapM (ppAbstract "pre_") abs
	a_post <- mapM (ppAbstract "post_") abs
	a_children <- mapM chAbstract abs
	prefix <- withPrefix return
	return $ (emptyClassNoID (prefix ++ "transform")) {
		  sections = [
		  	  Section Public c_pre
			, Section Public c_post 
			, Section Public c_children
			, Section Protected transforms
			, Section Protected a_pre
			, Section Protected a_post
			, Section Protected a_children
			]
		}

{-
 - Internal methods
 -}

transform :: Term -> MakeTeaMonad Member
transform t@(Term l s m) | isVector m = do
	tType <- termToType t
	let decl = (tType ++ "*", termToTransform t)
	let args = [(tType ++ "*", "in")]
	let body = [
		  tType ++ "::const_iterator i;"
		, tType ++ "* out1 = new " ++ tType ++ ";"
		, tType ++ "* out2 = new " ++ tType ++ ";"
		, ""
		, "for(i = in->begin(); i != in->end(); i++)"
		, "\tpre_" ++ symbolToVarName s ++ "(*i, out1);"
		, "for(i = out1->begin(); i != out1->end(); i++)"
		, "\tchildren_" ++ symbolToVarName s ++ "(*i);"
		, "for(i = out1->begin(); i != out1->end(); i++)"
		, "\tpost_" ++ symbolToVarName s ++ "(*i, out2);"
		, ""
		, "return out2;"
		]
	return (Method [] decl args body)
transform t@(Term l s m) | not (isVector m) = do
	tType <- termToType t
	let decl = (tType ++ "*", termToTransform t)
	let args = [(tType ++ "*", "in")]
	let body =  [
		  tType ++ "* out;"
		, ""
		, "out = pre_" ++ symbolToVarName s ++ "(in);"
		, "children_" ++ symbolToVarName s ++ "(out);"
		, "out = post_" ++ symbolToVarName s ++ "(out);"
		, ""
		, "return out;"
		]
	return (Method [] decl args body)

ppAbstract :: String -> NonTerminal -> MakeTeaMonad Member 
ppAbstract pp nt = 
	do
		(_,s',m) <- findContext (NT nt)
		let fnName = pp ++ symbolToVarName (NT nt)
		cn <- symbolToClassName s'
		let inType = cn ++ "*"
		conc <- concreteInstances (NT nt)
		if isVector m 
			then do
				let outType = "list<" ++ cn ++ "*>*"
				let decl = ("void", fnName)
				let args = [(inType, "in"), (outType, "out")]
				cases <- concatMapM listCase conc	
				let body = ["switch(in->classid())", "{"] ++ cases ++ ["}"]
				return $ Method [] decl args body 
			else do
				let outType = cn ++ "*"
				let decl = (outType, fnName)
				let args = [(inType, "in")]
				cases <- concatMapM nonListCase conc	
				let body = ["switch(in->classid())", "{"] ++ cases ++ ["}"]
				return $ Method [] decl args body 
	where
		nonListCase s = do
			cid <- findClassID s
			cn <- symbolToClassName s
			return [
				  "case " ++ show cid ++ ": " ++
				  "return " ++ pp ++ symbolToVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in));"
				]
		listCase s = do
			cid <- findClassID s
			cn <- symbolToClassName s
			(_,s',m) <- findContext s
			let t' = Term undefined s' m
			tType' <- termToType t'
			-- Context for the symbol may be more restrictive
			if isVector m 
				then return [
					  "case " ++ show cid ++ ": "
					, "\t{"
					, "\t\t" ++ tType' ++ "* local_out = new " ++ tType' ++ ";"
					, "\t\t" ++ tType' ++ "::const_iterator i;" 
					, "\t\t" ++ pp ++ symbolToVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in), local_out);" 
					, "\t\tfor(i = local_out->begin(); i != local_out->end(); i++)"
					, "\t\t\tout->push_back(*i);"
					, "\t}"
					, "\tbreak;"
					]
				else return [
					  "case " ++ show cid ++ ": "
					, "\tout->push_back(" ++ pp ++ symbolToVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in)));"
					, "\tbreak;"
					]


chAbstract :: NonTerminal -> MakeTeaMonad Member
chAbstract nt = 
	do 
		cn <- symbolToClassName (NT nt)
		let decl = ("void", "children_" ++ nt)
		let args = [(cn ++ "*", "in")]
		conc <- concreteInstances (NT nt)
		cases <- concatMapM switchcase conc	
		let body = ["switch(in->classid())", "{"] ++ cases ++ ["}"]
		return (Method [] decl args body)
	where
		switchcase s = do
			cid <- findClassID s
			cn <- symbolToClassName s
			return [
				  "case " ++ show cid ++ ":"
				, "\tchildren_" ++ symbolToVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in));"
				, "\tbreak;"
				]
{-
 - API methods
 -}

chConcrete :: Rule Conj -> MakeTeaMonad Member
chConcrete (Conj h ts) = do
	cn <- symbolToClassName (NT h)
	let decl = ("void", "children_" ++ h)
	let args = [(cn ++ "*", "in")]
	let f t = "in->" ++ termToVarName t ++ " = " ++ termToTransform t ++ "(in->" ++ termToVarName t ++ ");"
	return (Method [] decl args (map f ts))

termToTransform :: Term -> Name
termToTransform (Term _ s m) 
	| isVector m = "transform_" ++ symbolToVarName s ++ "_list"
	| otherwise = "transform_" ++ symbolToVarName s

ppConcrete :: String -> Symbol -> MakeTeaMonad Member 
ppConcrete pp s = do
	(_,s',m) <- findContext s
	let fnName = pp ++ symbolToVarName s
	cn <- symbolToClassName s
	cn' <- symbolToClassName s'
	let inType = cn ++ "*"
	if isVector m 
		then do
			let outType = "list<" ++ cn' ++ "*>*"
			let decl = ("void", fnName)
			let args = [(inType, "in"), (outType, "out")]
			return $ Method [] decl args ["out->push_back(in);"]
		else do
			let outType = cn' ++ "*"
			let decl = (outType, fnName)
			let args = [(inType, "in")]
			return $ Method [] decl args ["return in;"]
