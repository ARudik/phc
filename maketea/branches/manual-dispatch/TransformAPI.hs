{-
 - maketea -- generate C++ AST infrastructure
 - (C) 2006-2007 Edsko de Vries and John Gilbert
 -
 - TODO: Deal with NULLs.
 -}

module TransformAPI where

import Data.List

import DataStructures 
import GrammarAnalysis
import ContextResolution
import MakeTeaMonad
import Cpp
import Util

transformClass :: MakeTeaMonad Class
transformClass = do
	{- API methods -}
	conc <- concreteSymbols
	c_pre <- mapM (ppConcrete "pre_") conc
	c_post <- mapM (ppConcrete "post_") conc
	c_children <- withConj $ mapM chConcrete
	c_children_t <- withTokens $ mapM chToken
	{- Internal methods -}
	transforms <- withNonMarkers $ mapM transform . nubBy eqTermTransform
	abs <- usedAbstractSymbols
	a_pre <- mapM (ppAbstract "pre_") abs
	a_post <- mapM (ppAbstract "post_") abs
	a_children <- mapM chAbstract abs
	prefix <- withPrefix return
	return $ (emptyClassNoID (prefix ++ "transform")) {
		  sections = [
		  	  Section ["The pre-transform gets called before the children of the node are transformed"] Public c_pre
			, Section ["The post-transform gets called after the children of the node have been transformed"] Public c_post 
			, Section ["Transform the children of the node"] Public c_children
			, Section ["Tokens don't have children, so these methods do nothing by default"] Public c_children_t
			, Section ["Call the pre-transform, transform-children post-transform methods in order", "Do not override unless you know what you are doing"] Protected transforms
			, Section ["Invoke the right pre-transform (manual dispatching)","Do not override unless you know what you are doing"] Protected a_pre
			, Section ["Invoke the right post-transform (manual dispatching)","Do not override unless you know what you are doing"] Protected a_post
			, Section ["Invoke the right transform-children (manual dispatching)","Do not override unless you what you are doing"] Protected a_children
			]
		}

-- True if both terms have the same transform
eqTermTransform :: Term NonMarker -> Term NonMarker -> Bool 
eqTermTransform (Term _ s m) (Term _ s' m') 
	= s == s' && isVector m == isVector m'

{-
 - Internal methods
 -
 - We create a "transform" method for every term t@(_,s,m) *that occurs* in the
 - grammar. This has consequences for the possible shapes of the context
 - (s,s',m') for s.
 -
 - First, we must have that s == s':
 -
 - * s' can never be more general than s, since there is an explicit occurence
 - of s in the grammar.
 - 
 - * Then, s is either a concrete symbol (a terminal symbol or a non-terminal
 - symbol defined by a conjunction) or an abstract symbol (a non-terminal
 - symbol defined by a disjunction). 
 - 
 - * If s is a concrete symbol, the fact that there is an explicit occurence of
 - s in the grammar means that we must have that s == s'.
 - 
 - * If s is an abstract symbol. If there are no terms (_,i,_) in the grammar,
 - where i in an instance of s, the context for all instances i of s will be
 - (i,s,_). If there *are* explicit references to instances of i in the
 - grammar, than for those instances the context will be more restrictive --
 - *but* that will not affect the context for s itself! Therefore, also in this
 - case, s == s'.
 -
 - It is however quite possible that m /= m' (we may have a list of Xs
 - somewhere, but a single X somewhere else; the context for X will then be
 - (X,_,Single), but we still need to be able to transform a list of Xs. Of
 - course, when (not (isVector m)), then we must have that (not (isVector m'))
 - (if there is an explicit reference to a single X in the grammar, the context
 - for must be (X,_,Single) or (X,_,Optional).
 -}

transform :: Term NonMarker -> MakeTeaMonad Member
transform t@(Term l s m) | isVector m = do
	(_,_,m') <- findContext s
	tType <- toClassName t
	let decl = (tType ++ "*", termToTransform t)
	let args = [(tType ++ "*", "in")]
	let body = if isVector m' then [
		  tType ++ "::const_iterator i;"
		, tType ++ "* out1 = new " ++ tType ++ ";"
		, tType ++ "* out2 = new " ++ tType ++ ";"
		, ""
		, "for(i = in->begin(); i != in->end(); i++)"
		, "\tpre_" ++ toVarName s ++ "(*i, out1);"
		, "for(i = out1->begin(); i != out1->end(); i++)"
		, "\tchildren_" ++ toVarName s ++ "(*i);"
		, "for(i = out1->begin(); i != out1->end(); i++)"
		, "\tpost_" ++ toVarName s ++ "(*i, out2);"
		, ""
		, "return out2;"
		] else [
		  tType ++ "::const_iterator i;"
		, tType ++ "* out1 = new " ++ tType ++ ";"
		, tType ++ "* out2 = new " ++ tType ++ ";"
		, ""
		, "for(i = in->begin(); i != in->end(); i++)"
		, "\tout1->push_back(pre_" ++ toVarName s ++ "(*i));"
		, "for(i = out1->begin(); i != out1->end(); i++)"
		, "\tchildren_" ++ toVarName s ++ "(*i);"
		, "for(i = out1->begin(); i != out1->end(); i++)"
		, "\tout2->push_back(post_" ++ toVarName s ++ "(*i));"
		, ""
		, "return out2;"
		]	
	return (Method [] decl args body)
transform t@(Term l s m) | not (isVector m) = do
	tType <- toClassName t
	let decl = (tType ++ "*", termToTransform t)
	let args = [(tType ++ "*", "in")]
	let body =  [
		  tType ++ "* out;"
		, ""
		, "out = pre_" ++ toVarName s ++ "(in);"
		, "children_" ++ toVarName s ++ "(out);"
		, "out = post_" ++ toVarName s ++ "(out);"
		, ""
		, "return out;"
		]
	return (Method [] decl args body)

ppAbstract :: String -> Name NonTerminal -> MakeTeaMonad Member 
ppAbstract pp nt = 
	do
		(_,s',m) <- findContext (Exists (NonTerminal nt))
		let fnName = pp ++ toVarName (NonTerminal nt)
		cn <- toClassName s'
		let inType = cn ++ "*"
		conc <- concreteInstances (NonTerminal nt)
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
		nonListCase :: Some Symbol -> MakeTeaMonad Body
		nonListCase s = do
			cid <- findClassID s
			cn <- toClassName s
			return [
				  "case " ++ show cid ++ ": " ++
				  "return " ++ pp ++ toVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in));"
				]
		listCase :: Some Symbol -> MakeTeaMonad Body
		listCase s = do
			cid <- findClassID s
			cn <- toClassName s
			(_,s',m) <- findContext s
			let t' = Term undefined s' m
			tType' <- toClassName t'
			-- Context for the symbol may be more restrictive
			if isVector m 
				then return [
					  "case " ++ show cid ++ ": "
					, "\t{"
					, "\t\t" ++ tType' ++ "* local_out = new " ++ tType' ++ ";"
					, "\t\t" ++ tType' ++ "::const_iterator i;" 
					, "\t\t" ++ pp ++ toVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in), local_out);" 
					, "\t\tfor(i = local_out->begin(); i != local_out->end(); i++)"
					, "\t\t\tout->push_back(*i);"
					, "\t}"
					, "\tbreak;"
					]
				else return [
					  "case " ++ show cid ++ ": "
					, "\tout->push_back(" ++ pp ++ toVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in)));"
					, "\tbreak;"
					]


chAbstract :: Name NonTerminal -> MakeTeaMonad Member
chAbstract nt = 
	do 
		cn <- toClassName (NonTerminal nt)
		let decl = ("void", "children_" ++ nt)
		let args = [(cn ++ "*", "in")]
		conc <- concreteInstances (NonTerminal nt)
		cases <- concatMapM switchcase conc	
		let body = ["switch(in->classid())", "{"] ++ cases ++ ["}"]
		return (Method [] decl args body)
	where
		switchcase s = do
			cid <- findClassID s
			cn <- toClassName s
			return [
				  "case " ++ show cid ++ ":"
				, "\tchildren_" ++ toVarName s ++ "(dynamic_cast<" ++ cn ++ "*>(in));"
				, "\tbreak;"
				]
{-
 - API methods
 -}

chConcrete :: Rule Conj -> MakeTeaMonad Member
chConcrete (Conj h ts) = do
	cn <- toClassName (NonTerminal h)
	let decl = ("void", "children_" ++ h)
	let args = [(cn ++ "*", "in")]
	let 
		f :: Term NonMarker -> String
		f t = "in->" ++ termToVarName t ++ " = " ++ termToTransform t ++ "(in->" ++ termToVarName t ++ ");"
	return (Method [] decl args (map f (nonMarkers ts)))

chToken :: Symbol Terminal -> MakeTeaMonad Member
chToken t@(Terminal n _) = do
	cn <- toClassName t
	let decl = ("void", "children_" ++ toVarName t)
	let args = [(cn ++ "*", "in")]
	return (Method [] decl args [])

termToTransform :: Term NonMarker -> Name Method
termToTransform (Term _ s m) 
	| isVector m = "transform_" ++ toVarName s ++ "_list"
	| otherwise = "transform_" ++ toVarName s

ppConcrete :: String -> Some Symbol -> MakeTeaMonad Member 
ppConcrete pp s = do
	(_,s',m) <- findContext s
	let fnName = pp ++ toVarName s
	cn <- toClassName s
	cn' <- toClassName s'
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
