module TransformAPI where

import DataStructures 
import GrammarAnalysis
import ContextResolution
import Cpp

transformClass :: MakeTeaMonad CppClass
transformClass = do
	sym <- concreteSymbols
	pre <- mapM preTransforms sym
	return $ (emptyClass "Tree_transform") {
		  sections = [Section Public pre]
		}

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
