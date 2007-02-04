{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Parser to read .tea grammar files
-}

module MakeTeaParser where

import Text.ParserCombinators.Parsec
import qualified Text.ParserCombinators.Parsec.Token as ParsecToken
import Text.ParserCombinators.Parsec.Language
import MakeTeaCpp
import MakeTeaLib

{-
	Configure datatype to represent the grammar
-}

type Include = String
type TerminalName = String
type NonTerminalName = String
type Marker = String
type Term = (Label, Symbol, Multiplicity)
type Grammar = [Rule]
type ValueType = Maybe String

-- Ordering of the definitions is relevant, as they are used to find the most restrictive
-- context, with more restrictive listed first.
data Multiplicity = Single | Vector | Optional | OptVector | VectorOpt
	deriving (Show, Eq)

data Label = NoLabel | Label String
	deriving (Show, Eq)

data Symbol = Terminal TerminalName ValueType | NonTerminal NonTerminalName | Marker Marker 
	deriving (Show, Eq, Ord)

data Rule = Conjunction NonTerminalName [Term] | Disjunction NonTerminalName [Term]
	deriving Show

{-
	Configure lexical analyser
-}

lexer :: ParsecToken.TokenParser ()
lexer = ParsecToken.makeTokenParser (javaStyle {
		reservedNames = ["class", "virtual", "static", "const", "#include"],
		reservedOpNames = ["*", "+", "?", "*?", "?*", "::=", ";", "|", "<", ">", "{", "}", "(", ")", ",", ":"]
	})

lexeme = ParsecToken.lexeme lexer
reserved = ParsecToken.reserved lexer
reservedOp = ParsecToken.reservedOp lexer
whitespace = ParsecToken.whiteSpace lexer
identifier = ParsecToken.identifier lexer

{-	
	Define tokens
-}

lowercase :: Parser Char
lowercase = foldr1 (<|>) (map char ('_':['a'..'z'])) <?> "lowercase letter"

uppercase :: Parser Char
uppercase = foldr1 (<|>) (map char ('_':['A'..'Z'])) <?> "uppercase letter"
 
terminal :: Parser Symbol 
terminal = 
	do
		l <- lexeme (many1 uppercase)
		v <- option Nothing value_type
		return (Terminal l v)

value_type :: Parser ValueType 
value_type = 
	do
		char '<'
		l <- many (noneOf ['>']) 
		char '>'
		whitespace
		return (Just l)

nonterminal :: Parser Symbol
nonterminal = 
	do
		l <- lexeme (many1 lowercase)
		return (NonTerminal l)

marker :: Parser Symbol
marker =
	lexeme (do
		char '"'
		l <- many (noneOf ['"']) 
		char '"'
		return (Marker l)
	)

{-
	Define grammar	
-}

symbol :: Parser Term 
symbol =
	do
		l <- optlabel
		s <- terminal <|> nonterminal <|> marker
		m <- multiplicity
		return (l, s, m)

optlabel :: Parser Label
optlabel = option NoLabel optlabel' 

optlabel' :: Parser Label 
optlabel' =
	try (do
		l <- many1 lowercase
		char ':'
		return (Label l)
	)

multiplicity :: Parser Multiplicity
multiplicity = option Single multiplicity'

multiplicity' :: Parser Multiplicity
multiplicity' =
	do
		reservedOp "*" <|> reservedOp "+"
		return Vector
	<|>
	do
		reservedOp "?"
		return Optional
	<|>
	do
		reservedOp "*?"
		return OptVector
	<|>
	do
		reservedOp "?*"
		return VectorOpt

conjunction :: Parser Rule
conjunction =
	try (do
		(NonTerminal head) <- nonterminal
		reservedOp "::="
		body <- many1 symbol
		reservedOp ";"
		return (Conjunction head body)
	)

disjunction :: Parser Rule
disjunction =
	try (do
		(NonTerminal head) <- nonterminal
		reservedOp "::="
		--body <- sepBy1 (nonterminal <|> terminal) (reservedOp "|")
		body <- sepBy1 symbol (reservedOp "|")
		reservedOp ";"
		return (Disjunction head body) 
	)

rule :: Parser Rule
rule = conjunction <|> disjunction <?> "conjunction or disjunction"

{-
	Include files
-}

include :: Parser Include
include = 
	do
		reserved "#include"
		inc <- many (noneOf ['\n'])
		whitespace
		return inc

{-
	(Simplified) C++ classes
-}

cppclass :: Parser CppClass
cppclass = 
	do
		reserved "class"
		cn <- identifier
		ih <- option [] superclasses 
		reservedOp "{"
		vs <- many variable
		ms <- many method
		reservedOp "}"
		reservedOp ";"
		return (CppClass Concrete cn ih vs ms)

superclasses :: Parser [ClassName]
superclasses =
	do
		reservedOp ":"
		sepBy identifier (reservedOp ",")

variable :: Parser Variable
variable = 
	try (do
		(t,n) <- type_name
		reservedOp ";"
		return (Variable t n)
	)	

type_name :: Parser (Type, String)
type_name =
	try (do
		ts <- type_string
		n <- identifier
		return (Type ts, n) 
	) <|>
	do
		n <- identifier
		return (NoType, n)

type_string :: Parser String
type_string = 
	do
		const <- option "" (do reserved "const"; return "const ")
		rest <- lexeme (many1 (noneOf [' ','\t','(',')']))
		return (const ++ rest)

method :: Parser Method
method =
	try (do
		sig@(Signature v s t mn ps) <- signature
		b <- body 
		case b of 
			Just b -> return (Method sig b)
			Nothing -> return (Method (Signature PureVirtual s t mn ps) [])
	) 

signature :: Parser Signature
signature =
	do
		v <- option NonVirtual (do reserved "virtual"; return Virtual)
		s <- option NonStatic (do reserved "static"; return Static)
		(t,n) <- type_name
		reservedOp "("
		attrs <- sepBy type_name (reservedOp ",")
		reservedOp ")"
		return (Signature v s t n (map (\(t,n) -> Parameter (Variable t n) "") attrs))
	
body :: Parser (Maybe Body)
body =
	do
		char '='
		whitespace
		char '0'
		whitespace
		char ';'
		whitespace
		return Nothing
	<|>
	do
		char '{'
		b <- body1
		char '}'
		whitespace
		return (Just (gtrim (\x -> x == "") (map trim (lines b))))

body1 :: Parser String
body1 =	
	do
		c <- noneOf ['{','}']
		b <- body1 
		return (c:b)
	<|>
	do
		char '{'
		c <- body1
		char '}'
		b <- body1
		return ("{" ++ c ++ "}" ++ b)
	<|>
	do
		return ""

{-
	Overall structure
-}

grammar :: Parser (Grammar, [Include], [CppClass])
grammar = 
	do
		whitespace
		rules <- many rule
		includes <- many include
		classes <- many cppclass
		eof
		return (rules, includes, classes)
