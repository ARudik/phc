module BasicClasses where

import DataStructures
import MakeTeaMonad
import Cpp

createBasicClasses :: MakeTeaMonad () 
createBasicClasses = do
	classes <- withGrammar (mapM createClass)
	setClasses classes

createClass :: Rule -> MakeTeaMonad CppClass
createClass (Disj c _) = return (CppClass (symbolToClassname (NT c)))
createClass (Conj c _) = return (CppClass (symbolToClassname (NT c)))
