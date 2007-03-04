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
	(cn:inhn) <- mapM (symbolToClassName . NT) (c:inh)
	let c = emptyAbstractClass cn
	prefix <- withPrefix return
	return $ c { 
		  extends = inhn 
		, friends = [prefix ++ "transform"]
		}
createClass (Conj c body) = do
	inh <- directSuperclasses (NT c)
	(cn:inhn) <- mapM (symbolToClassName . NT) (c:inh)
	fields <- mapM createField body 
	let fieldSection = Section Public fields
	c <- emptyClass cn
	prefix <- withPrefix return
	return $ c { 
		  extends = inhn
		, sections = [fieldSection] ++ sections c 
		, friends = [prefix ++ "transform"]
		}

createField :: Term -> MakeTeaMonad Member
createField t = do
	typ <- termToType t
	let name = termToVarName t
	return (Attribute (typ ++ "* " ++ name))
