module DataStructures where

type Grammar = [Rule]

data Rule = Disj NonTerminal [Symbol] | Conj NonTerminal [Term]
	deriving Show

data Symbol = NT NonTerminal
	deriving Show

type Term = (Symbol, Multiplicity)

data Multiplicity = Single | Optional | Vector | VectorOpt | OptVector
	deriving Show

type NonTerminal = String
