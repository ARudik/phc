module Parser where

import DataStructures
import Text.ParserCombinators.Parsec
import qualified Text.ParserCombinators.Parsec.Token as T
import Text.ParserCombinators.Parsec.Language

{-
 - Lexical analysis
 -}

lexer = T.makeTokenParser javaStyle
	{
		reservedOpNames = ["|",";","?","*","*?","?*","::="]
	}

whiteSpace = T.whiteSpace lexer
identifier = T.identifier lexer
reservedOp = T.reservedOp lexer

{-
 - Top-level 
 -}

maketeaInput :: Parser Grammar
maketeaInput =
		do
			whiteSpace
			g <- grammar
			eof
			return g

{-
 - EBNF 
 -}

grammar :: Parser Grammar
grammar = many rule 

rule :: Parser Rule
rule = disjunction <|> conjunction

-- a disjunction consists of at least two symbols
disjunction :: Parser Rule
disjunction = try $ 
		do
			head <- nonTerminal
			reservedOp "::="
			s <- symbol ; reservedOp "|"
			ss <- symbol `sepBy` reservedOp "|"
			reservedOp ";"
			return (Disj head (s:ss))

-- a conjunction may be empty
conjunction :: Parser Rule
conjunction = 
		do
			head <- nonTerminal
			reservedOp "::="
			body <- many term
			reservedOp ";"
			return (Conj head body)

symbol :: Parser Symbol
symbol = 
		do
			nt <- nonTerminal
			return (NT nt)

term :: Parser Term
term = 
		do
			s <- symbol
			m <- multiplicity
			return (s, m)

multiplicity :: Parser Multiplicity
multiplicity =
		do
			reservedOp "?"
			return Optional 
	<|>
		do
			reservedOp "*"
			return Vector
	<|>
		do
			reservedOp "?*"
			return VectorOpt
	<|>
		do
			reservedOp "*?"
			return OptVector
	<|>
		do
			return Single

nonTerminal :: Parser NonTerminal 
nonTerminal = identifier 
