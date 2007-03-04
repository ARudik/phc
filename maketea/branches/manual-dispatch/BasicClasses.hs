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
	let (cn:inhn) = map (symbolToClassName . NT) (c:inh)
	return $ (emptyClass cn) { extends = inhn }
createClass (Conj c body) = do
	inh <- directSuperclasses (NT c)
	let (cn:inhn) = map (symbolToClassName . NT) (c:inh)
	let fields = map createField body 
	let fieldSection = Section Public fields
	return $ (emptyClass cn) { 
		  extends = inhn
		, sections = [fieldSection] 
		}

createField :: Term -> Member
createField (l,s,m) = Attribute (typ ++ " " ++ name l)
	where
		typ = 
			if isVector m 
			then "list<" ++ symbolToClassName s ++ "*>*" 
			else symbolToClassName s ++ "*"
		name Nothing = 
			if isVector m 
			then symbolToVarName s ++ "s"
			else symbolToVarName s
		name (Just n) = n
