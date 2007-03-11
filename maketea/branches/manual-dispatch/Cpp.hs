module Cpp where

import Data.Maybe
import Data.List

import DataStructures
import MakeTeaMonad
import GrammarAnalysis

emptyClass :: Name -> MakeTeaMonad CppClass 
emptyClass n = do
	cid <- getNextClassID
	let getID = Method ("int", "classid") [] ["return " ++ show cid ++ ";"]
	return $ CppClass {
		  name = n
		, extends = []
		, sections = [Section Private [getID]]
		, classid = cid
		, friends = []
		}

emptyAbstractClass :: Name -> CppClass
emptyAbstractClass n = CppClass {
		  name = n
		, extends = []
		, sections = [Section Private [getID]]
		, classid = 0
		, friends = []
		}
	where
		getID = PureVirtual ("int", "classid") []

emptyClassNoID :: Name -> CppClass
emptyClassNoID n = CppClass {
		  name = n
		, extends = []
		, sections = []
		, classid = 0
		, friends = []
		}

findClassID :: Symbol -> MakeTeaMonad Integer
findClassID s = withClasses $ \classes -> do
	cn <- symbolToClassName s
	let (Just cl) = find (\c -> name c == cn) classes
	return (classid cl) 

symbolToClassName :: Symbol -> MakeTeaMonad Name
symbolToClassName (NT nt) = withPrefix $ return . (++ nt)

symbolToVarName :: Symbol -> Name
symbolToVarName (NT nt) = nt

termToType :: Term -> MakeTeaMonad String
termToType (Term _ s m) = do
	cn <- symbolToClassName s
	if isVector m 
		then return ("list<" ++ cn ++ "*>")
		else return cn

termToVarName :: Term -> Name
termToVarName (Term Nothing s m) 
	| isVector m = symbolToVarName s ++ "s" 
	| otherwise = symbolToVarName s
termToVarName (Term (Just n) s m) = n

