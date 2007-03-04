module TransformAPI where

import Data.List

import DataStructures 
import GrammarAnalysis
import ContextResolution
import MakeTeaMonad
import Cpp

transformClass :: MakeTeaMonad CppClass
transformClass = do
	sym <- concreteSymbols
	pre <- mapM (ppTransforms "pre_") sym
	post <- mapM (ppTransforms "post_") sym
	children <- withConj $ return . (map transformChildren)
	allTerms <- withConj $ return . nub . concat . (map conjBody)
	transforms <- mapM transform allTerms
	return $ (emptyClassNoID "Tree_transform") {
		  sections = [
		  	  Section Public pre
			, Section Public post 
			, Section Public children
			, Section Private transforms
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


{-
 - API methods
 -}

transformChildren :: Rule Conj -> Member
transformChildren (Conj h ts) = 
	let
		sig = "void children_" ++ h ++ "(" ++ symbolToClassName (NT h) ++ "* in)"
		f t = "in->" ++ termToVarName t ++ " = transform_" ++ termToTransform t ++ "(in->" ++ termToVarName t ++ ");"
	in
		Method sig (map f ts) 

termToTransform :: Term -> Name
termToTransform (_,s,m) 
	| isVector m = symbolToVarName s ++ "_list"
	| otherwise = symbolToVarName s

ppTransforms :: String -> Symbol -> MakeTeaMonad Member 
ppTransforms pp s = do
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
