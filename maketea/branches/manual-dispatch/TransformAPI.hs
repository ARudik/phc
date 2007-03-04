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
	c_children <- withConj $ return . (map chConcrete)
	{- Internal methods -}
	allTerms <- withConj $ return . nub . concat . (map conjBody)
	transforms <- mapM transform allTerms
	abs <- abstractSymbols
	a_pre <- mapM (ppAbstract "pre_") abs
	a_post <- mapM (ppAbstract "post_") abs
	a_children <- mapM chAbstract abs
	return $ (emptyClassNoID "Tree_transform") {
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
transform t@(l,s,m) | isVector m = do
	let sig = termToType t ++ "* transform_" ++ termToTransform t ++ "(" ++ termToType t ++ "* in)" 
	let body = [
		  termToType t ++ "::const_iterator i;"
		, termToType t ++ "* out1 = new " ++ termToType t ++ ";"
		, termToType t ++ "* out2 = new " ++ termToType t ++ ";"
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
	return (Method sig body)
transform t@(l,s,m) | not (isVector m) = do
	let sig = termToType t ++ "* transform_" ++ termToTransform t ++ "(" ++ termToType t ++ "* in)"
	let body =  [
		  termToType t ++ "* out;"
		, ""
		, "out = pre_" ++ symbolToVarName s ++ "(in);"
		, "children_" ++ symbolToVarName s ++ "(out);"
		, "out = post_" ++ symbolToVarName s ++ "(out);"
		, ""
		, "return out;"
		]
	return (Method sig body)

ppAbstract :: String -> NonTerminal -> MakeTeaMonad Member 
ppAbstract pp nt = 
	do
		(_,s',m) <- findContext (NT nt)
		let fnName = pp ++ symbolToVarName (NT nt)
		let inType = symbolToClassName s' ++ "*"
		conc <- concreteInstances (NT nt)
		if isVector m 
			then do
				let outType = "list<" ++ symbolToClassName s' ++ "*>*"
				let sig = "void " ++ fnName ++ "(" ++ inType ++ " in, " ++ outType ++ " out)";
				cases <- concatMapM listCase conc	
				let body = ["switch(in->classid())", "{"] ++ cases ++ ["}"]
				return $ Method sig body 
			else do
				let outType = symbolToClassName s' ++ "*"
				let sig = outType ++ " " ++ fnName ++ "(" ++ inType ++ " in)"
				cases <- concatMapM nonListCase conc	
				let body = ["switch(in->classid())", "{"] ++ cases ++ ["}"]
				return $ Method sig body; 
	where
		nonListCase s = do
			cid <- findClassID s
			return [
				  "case " ++ show cid ++ ": " ++
				  "return " ++ pp ++ symbolToVarName s ++ "(dynamic_cast<" ++ symbolToClassName s ++ "*>(in));"
				]
		listCase s = do
			cid <- findClassID s
			(_,s',m) <- findContext s
			let t' = (undefined, s', m)
			-- Context for the symbol may be more restrictive
			if isVector m 
				then return [
					  "case " ++ show cid ++ ": "
					, "\t{"
					, "\t\t" ++ termToType t' ++ "* local_out = new " ++ termToType t' ++ ";"
					, "\t\t" ++ termToType t' ++ "::const_iterator i;" 
					, "\t\t" ++ pp ++ symbolToVarName s ++ "(dynamic_cast<" ++ symbolToClassName s ++ "*>(in), local_out);" 
					, "\t\tfor(i = local_out->begin(); i != local_out->end(); i++)"
					, "\t\t\tout->push_back(*i);"
					, "\t}"
					, "\tbreak;"
					]
				else return [
					  "case " ++ show cid ++ ": "
					, "\tout->push_back(" ++ pp ++ symbolToVarName s ++ "(dynamic_cast<" ++ symbolToClassName s ++ "*>(in)));"
					, "\tbreak;"
					]


chAbstract :: NonTerminal -> MakeTeaMonad Member
chAbstract nt = 
	do 
		let sig = "void children_" ++ nt ++ "(" ++ symbolToClassName (NT nt) ++ "* in)"
		conc <- concreteInstances (NT nt)
		cases <- concatMapM switchcase conc	
		let body = ["switch(in->classid())", "{"] ++ cases ++ ["}"]
		return (Method sig body)
	where
		switchcase s = do
			cid <- findClassID s
			return [
				  "case " ++ show cid ++ ":"
				, "\tchildren_" ++ symbolToVarName s ++ "(dynamic_cast<" ++ symbolToClassName s ++ "*>(in));"
				, "\tbreak;"
				]
{-
 - API methods
 -}

chConcrete :: Rule Conj -> Member
chConcrete (Conj h ts) = 
	let
		sig = "void children_" ++ h ++ "(" ++ symbolToClassName (NT h) ++ "* in)"
		f t = "in->" ++ termToVarName t ++ " = transform_" ++ termToTransform t ++ "(in->" ++ termToVarName t ++ ");"
	in
		Method sig (map f ts) 

termToTransform :: Term -> Name
termToTransform (_,s,m) 
	| isVector m = symbolToVarName s ++ "_list"
	| otherwise = symbolToVarName s

ppConcrete :: String -> Symbol -> MakeTeaMonad Member 
ppConcrete pp s = do
	(_,s',m) <- findContext s
	let fnName = pp ++ symbolToVarName s
	let inType = symbolToClassName s' ++ "*"
	if isVector m 
		then do
			let outType = "list<" ++ symbolToClassName s' ++ "*>*"
			let sig = "void " ++ fnName ++ "(" ++ inType ++ " in, " ++ outType ++ " out)";
			return $ Method sig []
		else do
			let outType = symbolToClassName s' ++ "*"
			let sig = outType ++ " " ++ fnName ++ "(" ++ inType ++ " in)"
			return $ Method sig ["return in;"]
