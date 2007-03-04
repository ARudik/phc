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

ruleP :: Parser Rule
ruleP = disjunctionP <|> conjunctionP

-- a disjunction consists of at least two symbols
disjunctionP :: Parser Rule
disjunctionP = try $ 
		do
			head <- nonTerminalP
			reservedOp "::="
			s <- symbolP ; reservedOp "|"
			ss <- symbolP `sepBy` reservedOp "|"
			reservedOp ";"
			return (Disj head (s:ss))

-- a conjunction may be empty
conjunctionP :: Parser Rule
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
			s <- symbolP
			m <- multiplicityP
			return (s, m)

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
