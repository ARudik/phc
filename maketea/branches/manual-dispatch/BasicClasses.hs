module BasicClasses where

import DataStructures
import MakeTeaMonad
import GrammarAnalysis
import Cpp
import Util

createBasicClasses :: MakeTeaMonad () 
createBasicClasses = do
	classes <- withGrammar (mapM (elim createClass))
	setClasses classes

createClass :: Rule a -> MakeTeaMonad CppClass
createClass (Disj c _) = do
	inh <- directSuperclasses (NT c)
	let (cn:inhn) = map (symbolToClassName . NT) (c:inh)
	let c = emptyAbstractClass cn
	return $ c { extends = inhn }
createClass (Conj c body) = do
	inh <- directSuperclasses (NT c)
	let (cn:inhn) = map (symbolToClassName . NT) (c:inh)
	let fields = map createField body 
	let fieldSection = Section Public fields
	c <- emptyClass cn
	return $ c { 
		  extends = inhn
		, sections = [fieldSection] ++ sections c 
		}

createField :: Term -> Member
createField t = Attribute (termToType t ++ "* " ++ termToVarName t)
