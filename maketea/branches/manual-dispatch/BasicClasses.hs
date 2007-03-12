{-
 - maketea -- generate C++ AST infrastructure
 - (C) 2006-2007 Edsko de Vries and John Gilbert
 -}

module BasicClasses where

import DataStructures
import MakeTeaMonad
import GrammarAnalysis
import Cpp
import Util

createBasicClasses :: MakeTeaMonad () 
createBasicClasses = do
	ast_classes <- withGrammar (mapM (elim createClass))
	token_classes <- withTokens (mapM createTokenClass)
	setClasses (ast_classes ++ token_classes) 

createClass :: Rule a -> MakeTeaMonad Class
createClass (Disj c _) = do
	inh <- directSuperclasses (Exists (NonTerminal c))
	(cn:inhn) <- mapM (toClassName . NonTerminal) (c:inh)
	let c = emptyAbstractClass cn
	prefix <- withPrefix return
	return $ c { 
		  extends = inhn 
		, friends = [prefix ++ "transform"]
		}
createClass r@(Conj c body) = do
	inh <- directSuperclasses (Exists (NonTerminal c))
	(cn:inhn) <- mapM (toClassName . NonTerminal) (c:inh)
	fields <- mapM (elim createField) body 
	let fieldSection = Section [show r] Public fields
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

createTokenClass :: Symbol Terminal -> MakeTeaMonad Class
createTokenClass t@(Terminal n ctype) = do
	inh <- directSuperclasses (Exists t)
	cn <- toClassName t
	inhn <- mapM (toClassName . NonTerminal) inh
	c <- emptyClass cn
	prefix <- withPrefix return
	return $ c {
		  extends = inhn
		, friends = [prefix ++ "transform"]
		}
		
