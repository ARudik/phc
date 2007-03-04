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
	pre <- mapM preTransforms sym
	children <- withConj $ return . (map transformChildren)
	allTerms <- withConj $ return . nub . concat . (map conjBody)
	transforms <- mapM transform allTerms
	return $ (emptyClassNoID "Tree_transform") {
		  sections = [
		  	  Section Public pre
			, Section Public children
			, Section Private transforms
			]
		}

{-
 - Internal methods
 -}

transform :: Term -> MakeTeaMonad Member
transform t@(l,s,m) = do
	let sig = termToType t ++ " transform_" ++ termToTransform t ++ "(" ++ termToType t ++ " in)" 
	return (Method sig [])

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

preTransforms :: Symbol -> MakeTeaMonad Member 
preTransforms s = do
	(_,s',m) <- findContext s
	let fnName = "pre_" ++ symbolToVarName s
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
