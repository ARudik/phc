module BasicClasses where

import DataStructures
import MakeTeaMonad
import GrammarAnalysis
import Cpp
import Util

createBasicClasses :: MakeTeaMonad () 
createBasicClasses = do
	ast_classes <- withGrammar (mapM (elim createClass))
	-- token_classes <- withTokens (mapM createTokenClass)
	setClasses ast_classes -- (ast_classes ++ token_classes) 

createClass :: Rule a -> MakeTeaMonad Class
createClass (Disj c _) = do
	inh <- directSuperclasses (Exists (NonTerminal c))
	(cn:inhn) <- mapM (symbolToClassName . NonTerminal) (c:inh)
	let c = emptyAbstractClass cn
	prefix <- withPrefix return
	return $ c { 
		  extends = inhn 
		, friends = [prefix ++ "transform"]
		}
createClass (Conj c body) = do
	inh <- directSuperclasses (Exists (NonTerminal c))
	(cn:inhn) <- mapM (symbolToClassName . NonTerminal) (c:inh)
	fields <- mapM (elim createField) body 
	let fieldSection = Section Public fields
	c <- emptyClass cn
	prefix <- withPrefix return
	return $ c { 
		  extends = inhn
		, sections = [fieldSection] ++ sections c 
		, friends = [prefix ++ "transform"]
		}

createField :: Term a -> MakeTeaMonad Member
createField t@(Marker _ _) = do
	let name = termToVarName t
	return (Attribute [] ("bool", name))
createField t@(Term _ _ _) = do
	typ <- toClassName t
	let name = termToVarName t
	return (Attribute [] (typ ++ "*", name))
