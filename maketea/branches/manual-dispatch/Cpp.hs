module Cpp where

import Data.Maybe
import Data.List

import DataStructures
import MakeTeaMonad
import GrammarAnalysis
import PrettyPrinter
import Util

emptyClass :: Name Class -> MakeTeaMonad Class 
emptyClass n = do
	cid <- getNextClassID
	let getID = Method [] ("int", "classid") [] ["return " ++ show cid ++ ";"]
	return $ Class {
		  name = n
		, comment = []
		, extends = []
		, sections = [Section Private [getID]]
		, classid = cid
		, friends = []
		}

emptyAbstractClass :: Name Class -> Class
emptyAbstractClass n = Class {
		  name = n
		, comment = []
		, extends = []
		, sections = [Section Private [getID]]
		, classid = 0
		, friends = []
		}
	where
		getID = PureVirtual [] ("int", "classid") []

emptyClassNoID :: Name Class -> Class
emptyClassNoID n = Class {
		  name = n
		, comment = []
		, extends = []
		, sections = []
		, classid = 0
		, friends = []
		}

findClassID :: Some Symbol -> MakeTeaMonad Integer
findClassID s = withClasses $ \classes -> do
	cn <- toClassName s
	let cl = find (\c -> name c == cn) classes
	case cl of
		Just cl -> return (classid cl) 
		Nothing -> fail $ "Unknown symbol " ++ show s

{-
 - Translation to C++ class names
 -}

class ToClassName a where
	toClassName :: a -> MakeTeaMonad (Name Class)

instance ToClassName (Symbol a) where
	toClassName = symbolToClassName

instance ToClassName (Some Symbol) where
	toClassName = elim symbolToClassName

instance ToClassName (Term NonMarker) where
	toClassName = termToClassName

symbolToClassName :: Symbol a -> MakeTeaMonad (Name Class)
symbolToClassName (NonTerminal n) = withPrefix $ return . (++ n)
symbolToClassName (Terminal n _) = withPrefix $ return . (++ "_token_" ++ n)

termToClassName :: Term NonMarker -> MakeTeaMonad CType 
termToClassName (Term _ s m) = do
	cn <- elim symbolToClassName s
	if isVector m 
		then return ("list<" ++ cn ++ "*>")
		else return cn

{-
 - Translation to C++ variable names
 -}

class ToVarName a where
	toVarName :: a -> Name Variable 

instance ToVarName (Term a) where
	toVarName = termToVarName

instance ToVarName (Some Term) where
	toVarName = elim termToVarName

instance ToVarName (Symbol a) where
	toVarName = symbolToVarName

instance ToVarName (Some Symbol) where
	toVarName = elim symbolToVarName

termToVarName :: Term a -> Name Variable 
termToVarName (Term Nothing s m) 
	| isVector m = toVarName s ++ "s" 
	| otherwise = toVarName s
termToVarName (Term (Just n) _ _) = n
termToVarName (Marker Nothing m) = m
termToVarName (Marker (Just n) _) = n

symbolToVarName :: Symbol a -> Name Variable 
symbolToVarName (NonTerminal n) = n
symbolToVarName (Terminal n _) = n
