module DataStructures where

import Control.Monad.State
import Util

{-
 - Definition of EBNF
 -}

type Grammar = [Exists Rule]

data Conj
data Disj
data Rule :: * -> * where
	Disj :: NonTerminal -> [Symbol] -> Rule Disj
	Conj :: NonTerminal -> [Term] -> Rule Conj

data Symbol = NT NonTerminal deriving (Eq,Ord)
type Term = (Label, Symbol, Multiplicity)
type Label = Maybe String
data Multiplicity = Single | Optional | Vector | VectorOpt | OptVector deriving (Eq)
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
	, friends :: [Name]
	}
data Section = Section Access [Member]
data Access = Private | Protected | Public
data Member = Attribute String | Method Sig Body | PureVirtual Sig
type Sig = (ReturnType, Name, [Arg])
type ReturnType = String
type Arg = String
type Body = [String]
type Name = String  

{-
 - The maketea monad (means we don't have to manually carry a lot of state around)
 -}

type MakeTeaMonad a = State MakeTeaState a
data MakeTeaState = MTS {
	  prefix :: String
	, grammar :: Grammar  
	, nextClassID :: Integer
	, contexts :: Maybe [Context]
	, classes :: Maybe [CppClass]
	}
