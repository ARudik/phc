module DataStructures where

import Control.Monad.State

{-
 - Definition of EBNF
 -}

type Grammar = [Rule]
data Rule = Disj NonTerminal [Symbol] | Conj NonTerminal [Term] deriving Show
data Symbol = NT NonTerminal deriving (Show,Eq,Ord)
type Term = (Symbol, Multiplicity)
data Multiplicity = Single | Optional | Vector | VectorOpt | OptVector deriving (Show,Eq)
type NonTerminal = String
type Context = (Symbol, Symbol, Multiplicity)

{-
 - The maketea monad (means we don't have to manually carry a lot of state around)
 -}

type MakeTeaMonad a = State MakeTeaState a
type MakeTeaState = Grammar
