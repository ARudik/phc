module Parser where

import Text.ParserCombinators.Parsec
import qualified Text.ParserCombinators.Parsec.Token as T
import Text.ParserCombinators.Parsec.Language

import DataStructures
import Util

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

maketeaP :: Parser Grammar
maketeaP =
		do
			whiteSpace
			g <- grammarP
			eof
			return g

{-
 - EBNF 
 -}

grammarP :: Parser Grammar
grammarP = many ruleP

ruleP :: Parser (Exists Rule)
ruleP = 
		do
			r <- disjunctionP
			return (Exists r)
	<|> 
		do
			r <- conjunctionP
			return (Exists r)

-- a disjunction consists of at least two symbols
disjunctionP :: Parser (Rule Disj)
disjunctionP = try $ 
		do
			head <- nonTerminalP
			reservedOp "::="
			s <- symbolP ; reservedOp "|"
			ss <- symbolP `sepBy` reservedOp "|"
			reservedOp ";"
			return (Disj head (s:ss))

-- a conjunction may be empty
conjunctionP :: Parser (Rule Conj)
conjunctionP = 
		do
			head <- nonTerminalP
			reservedOp "::="
			body <- many termP
			reservedOp ";"
			return (Conj head body)

symbolP :: Parser Symbol
symbolP = 
		do
			nt <- nonTerminalP
			return (NT nt)

termP :: Parser Term
termP = 
		do
			l <- labelP
			s <- symbolP
			m <- multiplicityP
			return (l, s, m)

labelP :: Parser Label
labelP = option Nothing $ 
		try (do
			id <- identifier
			reservedOp ":"
			return (Just id))

multiplicityP :: Parser Multiplicity
multiplicityP =
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

nonTerminalP :: Parser NonTerminal 
nonTerminalP = identifier 
