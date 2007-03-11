module Parser where

import Text.ParserCombinators.Parsec
import qualified Text.ParserCombinators.Parsec.Token as T
import Text.ParserCombinators.Parsec.Language
import Data.Char

import DataStructures
import Util
import Cpp

{-
 - Top-level 
 -}

maketeaP :: Parser (Grammar, [Include], [CppClass])
maketeaP =
	do
		whiteSpace
		g <- grammarP
		is <- many includeP
		cs <- many classP
		eof
		return (g, is, cs)

{-
 - Classes
 -}

classP :: Parser CppClass
classP = 
	do
		reserved "class"
		name <- identifier
		inh <- option [] $ do 
			reservedOp ":"
			identifier `sepBy1` comma
		reservedOp "{"
		ss <- many sectionP
		reservedOp "}"
		reservedOp ";"
		return $ (emptyClassNoID name) {
			  extends = inh
			, sections = ss
			}

sectionP :: Parser Section
sectionP = 
	do
		access <- accessP
		members <- many memberP
		return (Section access members)

accessP :: Parser Access
accessP = 
	do
		reserved "private"
		reservedOp ":"
		return Private
	<|> do
		reserved "protected"
		reservedOp ":"
		return Protected
	<|> do
		reserved "public"
		reservedOp ":"
		return Public

memberP :: Parser Member
memberP = try $ do
	cmnt <- commentP
	decl <- declP
	do
		do	
			reservedOp ";"
			return (Attribute cmnt decl)
		<|> do
			args <- parens (declP `sepBy` comma)
			do
				do
					symbol "= 0;"
					return (PureVirtual cmnt decl args)
				<|> do
					body <- lexeme bodyP
					return (Method cmnt decl args [body])
			
commentP :: Parser Comment
commentP = many $ do
	string "//" 
	cmnt <- many (noneOf ['\n'])
	whiteSpace
	return cmnt

bodyP :: Parser String
bodyP = 
	do
		char '{'
		bs <- many body1
		char '}'
		return ("{" ++ concat bs ++ "}")

body1 :: Parser String
body1 = (many1 $ noneOf ['{','}']) <|> bodyP

declP :: Parser Decl
declP = 
	do
		xs <- many1 (lexeme (many1 (alphaNum <|> oneOf ['*','<','>','_'])))
		return (f (init xs), last xs)
	where
		f [] = ""
		f [x] = x
		f (x:x':xs) = x ++ " " ++ x' ++ f xs


{-
 - Includes
 -}

includeP = 
	do
		symbol "#include"
		lexeme (many $ noneOf ['\n'])

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
	<|> do
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
	<|> do
		t <- terminalP
		ctype <- option "String*" $ lexeme (
			between (char '<') (char '>') (many $ noneOf ['>'])) 
		return (T t ctype)
	<|> do
		m <- markerP
		return (M m)

termP :: Parser Term
termP = 
	do
		l <- labelP
		s <- symbolP
		m <- multiplicityP
		return (Term l s m)

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
	<|> do
		reservedOp "*"
		return Vector
	<|> do
		reservedOp "?*"
		return VectorOpt
	<|> do
		reservedOp "*?"
		return OptVector
	<|> do
		reservedOp "+"
		return Vector
	<|> do
		return Single

nonTerminalP :: Parser NonTerminal 
nonTerminalP = try $
	do
		id <- identifier
		if all (isAlpha `implies` isLower) id 
			then return id
			else fail "expected lowercase identifier"

terminalP :: Parser Terminal
terminalP = try $
	do
		id <- identifier
		if all (isAlpha `implies` isUpper) id
			then return id
			else fail "expected uppercase identifier"

markerP :: Parser Marker
markerP = try $
	do
		id <- stringLiteral 
		return id

{-
 - Lexical analysis
 -}

lexer = T.makeTokenParser haskellStyle
	{
		reservedNames = ["class","private","protected","public"]
	,	reservedOpNames = ["|",";","?","*","*?","?*","::=",":","+","{","}","(",")"]
	}

whiteSpace = T.whiteSpace lexer
identifier = T.identifier lexer
reserved = T.reserved lexer
reservedOp = T.reservedOp lexer
stringLiteral = T.stringLiteral lexer
lexeme = T.lexeme lexer
comma = T.comma lexer
symbol = T.symbol lexer

parens p = 
		try (between (symbol "(") (symbol ")") p)
	<|> do
		symbol "()"
		return []

