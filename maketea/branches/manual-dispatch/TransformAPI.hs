module TransformAPI where

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
	return $ (emptyClassNoID "Tree_transform") {
		  sections = [
		  	  Section Public pre
			, Section Public children
			]
		}

transformChildren :: Rule Conj -> Member
transformChildren (Conj h ts) = 
	let
		sig = "void children_" ++ h ++ "()"
		termToTransform (_,s,m) 
			| isVector m = symbolToVarName s ++ "_list"
			| otherwise = symbolToVarName s
		f t = termToVarName t ++ " = transform_" ++ termToTransform t ++ "(" ++ termToVarName t ++ ");"
	in
		Method sig (map f ts) 

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
