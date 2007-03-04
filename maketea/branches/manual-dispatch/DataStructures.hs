module DataStructures where

import Control.Monad.State

{-
 - Definition of EBNF
 -}

type Grammar = [Rule]
data Rule = Disj NonTerminal [Symbol] | Conj NonTerminal [Term] deriving Show
data Symbol = NT NonTerminal deriving (Show,Eq,Ord)
type Term = (Label, Symbol, Multiplicity)
type Label = Maybe String
data Multiplicity = Single | Optional | Vector | VectorOpt | OptVector deriving (Show,Eq)
type NonTerminal = String
type Context = (Symbol, Symbol, Multiplicity)

{-
 - C++ classes
 -}

data CppClass = CppClass {
	  name :: Name 
	, extends :: [Name]
	, sections :: [Section]
	}
data Section = Section Access [Member]
data Access = Private | Protected | Public
type Member = String
type Name = String  

{-
 - The maketea monad (means we don't have to manually carry a lot of state around)
 -}

type MakeTeaMonad a = State MakeTeaState a
data MakeTeaState = MTS {
	  grammar :: Grammar 
	, contexts :: Maybe [Context]
	, classes :: Maybe [CppClass]
	}
