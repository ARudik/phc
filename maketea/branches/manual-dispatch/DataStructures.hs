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
	, classid :: Integer
	}
data Section = Section Access [Member]
data Access = Private | Protected | Public
data Member = Attribute String | Method Sig Body | VirtualMethod Sig
type Sig = String
type Body = [String]
type Name = String  

{-
 - The maketea monad (means we don't have to manually carry a lot of state around)
 -}

type MakeTeaMonad a = State MakeTeaState a
data MakeTeaState = MTS {
	  grammar :: Grammar 
	, nextClassID :: Integer
	, contexts :: Maybe [Context]
	, classes :: Maybe [CppClass]
	}
