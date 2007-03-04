module BasicClasses where

import DataStructures
import MakeTeaMonad
import GrammarAnalysis
import Cpp

createBasicClasses :: MakeTeaMonad () 
createBasicClasses = do
	classes <- withGrammar (mapM createClass)
	setClasses classes

createClass :: Rule -> MakeTeaMonad CppClass
createClass (Disj c _) = do
	inh <- directSuperclasses (NT c)
	let (cn:inhn) = map (symbolToClassname . NT) (c:inh)
	return $ (emptyClass cn) { extends = inhn }
createClass (Conj c _) = do
	inh <- directSuperclasses (NT c)
	let (cn:inhn) = map (symbolToClassname . NT) (c:inh)
	return $ (emptyClass cn) { extends = inhn }
