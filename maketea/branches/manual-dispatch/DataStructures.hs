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

data Symbol = NT NonTerminal | T Terminal CType | M Marker deriving (Eq,Ord)
data Term = Term Label Symbol Multiplicity deriving Eq
type Label = Maybe String
data Multiplicity = Single | Optional | Vector | VectorOpt | OptVector deriving (Eq)
type NonTerminal = String
type Terminal = String
type Context = (Symbol, Symbol, Multiplicity)
type Marker = String

{-
 - C++ classes
 -}

type Include = String

data CppClass = CppClass {
	  name :: Name 
	, extends :: [Name]
	, sections :: [Section]
	, classid :: Integer
	, friends :: [Name]
	}
data Section = Section Access [Member]
data Access = Private | Protected | Public
data Member = Attribute Decl | Method Decl [Arg] Body | PureVirtual Decl [Arg] 
type Decl = (CType, Name)
type Arg = Decl 
type Body = [String]
type CType = String
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
