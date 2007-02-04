{-
 	phc -- the open source PHP compiler
	See license/readme.license for licensing information

	Schema module

	TODO:
		o abstract_group generates some _optional types that are not required. Can remove
		  these with some further grammar analysis

-}

module Schema where

import MakeTeaParser
import GrammarAnalysis
import ListClasses
import List

xml_schema :: Grammar -> String
xml_schema gmr = 
			"<?xml version=\"1.0\"?>\n\n"
			
		++	"<xs:schema \n" 
		++	"	xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
		++	"	xmlns=\"http://www.phpcompiler.org/phc-1.0\"\n"
		++	"	targetNamespace=\"http://www.phpcompiler.org/phc-1.0\"\n"
		++	"	elementFormDefault=\"qualified\">\n\n"
		
		++ "<!-- root element -->\n\n"
		++	"<xs:element name=\"AST_" ++ (start_nonterminal_name gmr) ++ "\" type=\"AST_" ++ (start_nonterminal_name gmr)  ++ "\"/>\n\n"
		
		++	"<!-- built in support for attributes on nodes -->\n\n"
		
		++	"<xs:complexType name=\"attrs\">\n"
		++	"	<xs:sequence minOccurs=\"0\" maxOccurs=\"unbounded\">\n"
		++	"		<xs:element name=\"attr\">\n"
		++	"			<xs:complexType mixed=\"true\">\n"
		++	"				<xs:sequence minOccurs=\"0\" maxOccurs=\"unbounded\">\n"
		++	"					<xs:any/>\n"
		++ "				</xs:sequence>\n"
		++	"				<xs:attribute name=\"key\" type=\"xs:string\"/>\n"
		++	"			</xs:complexType>\n"
		++	"		</xs:element>\n"
		++	"	</xs:sequence>\n"
		++	"</xs:complexType>\n\n"
		
		++ "<!-- choice groups representing abstract class types -->\n\n"
		++	abstract_groups gmr gmr
		
		++ "\n\n<!-- complex types representing lists -->\n\n"
		++	list_types gmr
		
		++ "\n\n<!-- complex types for concrete classes (compound rules) -->\n\n"
		++	concrete_types gmr gmr
		
		++ "\n\n<!-- complex types for terminal symbols -->\n\n"
		++ token_types gmr
		
		++	"</xs:schema>"

-- Construct a set of <xs:group><xs:choice>...</xs:choice></xs:group>s that
-- correspond to the abstract classes in the grammar, reachable from the first rule
abstract_groups :: Grammar -> Grammar -> String
abstract_groups _ [] = []
abstract_groups gmr ((Disjunction lhs rhs):tail) = (abstract_group gmr lhs rhs) ++ (abstract_groups gmr tail)
abstract_groups gmr ((Conjunction _ _):tail) = abstract_groups gmr tail

abstract_group :: Grammar -> NonTerminalName -> [Term] -> String
abstract_group gmr lhs rhs = 
	if elem lhs (reachable_nts gmr) then
		(	"<xs:group name=\"AST_" ++ lhs ++ "\">\n"
		++	"<xs:choice>\n"
		++	concat (map (group_body gmr) rhs)
		++	"</xs:choice>\n"
		++	"</xs:group>\n\n"	

		++	"<xs:group name=\"AST_" ++ lhs ++ "_optional\">\n"
		++	"<xs:choice>\n"
		++	"<xs:element name=\"AST_" ++ lhs ++ "\" nillable=\"true\"/> <!-- should only have xs:nill=true in instances -->\n"
		++	"<xs:group ref=\"AST_" ++ lhs ++ "\"/>\n"
		++	"</xs:choice>\n"
		++	"</xs:group>\n\n" )
	else
		""
		
group_body :: Grammar -> Term -> String
group_body gmr t@(label, sym, mult) = 
	if is_concrete_xs_type gmr t then	
		"<xs:element name=\"" ++ (symbol_to_xs_name sym mult) 
			++ "\" type=\"" ++ (symbol_to_xs_type gmr sym mult) 
			++ "\" nillable=\"false\"/>\n"
	else
		"<xs:group ref=\"" ++ (symbol_to_xs_type gmr sym mult) ++ "\"/>\n"

-- reachable_nts takes a grammar and returns a list of all non-terminal names that are reachable
-- from the first rule in the grammar
reachable_nts :: Grammar -> [NonTerminalName]
reachable_nts gmr = rntc gmr [(start_nonterminal_name gmr)]

rntc :: Grammar -> [NonTerminalName] -> [NonTerminalName]
rntc gmr names =
	if (length names) == (length iters) then names else (rntc gmr iters)
	where
		iters = nub (names ++ [z | (_, NonTerminal z, _) <- (concatMap rhs [y | y <- gmr, elem (lhs y) names])])

-- Given a grammar, construct a set of xs:complexTypes for all the vector
-- types that occur in it.
list_types :: Grammar -> String
list_types gmr = concat (map (list_type gmr) unique_list_types)
	where
		all_terms = concat [rhs | (Conjunction lhs rhs) <- gmr]
		unique_terms = nubBy lt_equal all_terms
		unique_list_types = [x | x@(_, _, mult) <- unique_terms, is_vector mult]
		lt_equal (_, s1, m1) (_, s2, m2) = (s1 == s2) && ( (m1 == m2) || ((m1 == Vector) && (m2 == OptVector)) || ((m1 == OptVector) && (m2 == Vector)) )
		lt_equal _ _ = False

list_type :: Grammar -> Term -> String
list_type gmr (label , sym, mult) = 
			"<xs:complexType name=\"" ++ (symbol_to_xs_type gmr sym mult) ++ "\">\n"
		++	"<xs:sequence>\n"
		++ "<xs:element name=\"attrs\" type=\"attrs\"/>\n"
		++	"<xs:sequence minOccurs=\"0\" maxOccurs=\"unbounded\">\n"
		++	list_content
		++	"</xs:sequence>\n"
		++ "</xs:sequence>\n"
		++ "</xs:complexType>\n\n"
	where
		list_content = 
			if (is_concrete gmr sym) then
					"<xs:element name=\"" ++ (symbol_to_classname sym) ++ "\" type=\"" ++ (symbol_to_classname sym)
				++	case mult of
						Vector	 	-> "\" nillable=\"false\"/>\n"
						VectorOpt 	-> "\" nillable=\"true\"/>\n"
						_ 				-> error "list_content"
			else
				"<xs:group ref=\"" ++ (list_type_to_single sym mult) ++ "\"/>\n"

-- Given a grammar, construct types for all the terminals.
token_types :: Grammar -> String
token_types gmr = var_and_source_rep ++ concat (map token_type terminals)
	where
		terminals = terminal_list gmr
		var_and_source_rep = 
				"<xs:complexType name=\"encoded_string\">\n"
			++	"	<xs:simpleContent>\n"
			++	"		<xs:extension base=\"xs:string\">\n"
			++	"			<xs:attribute name=\"encoding\" type=\"xs:string\" default=\"none\"/>\n"
			++	"		</xs:extension>\n"
			++	"	</xs:simpleContent>\n"
			++	"</xs:complexType>\n\n"

token_type :: Symbol -> String
token_type t@(Terminal name vtype) = 
		"<xs:complexType name=\"" ++ (symbol_to_classname t) ++ "\">\n"
	++ "<xs:sequence>\n"
	++ "<xs:element name=\"attrs\" type=\"attrs\"/>\n"
	++	case vtype of
			Nothing	-> "<xs:element name=\"value\" type=\"encoded_string\"/>\n"
			Just x 	->	(if (x == "") then 
								"" 
							else 
								"<xs:element name=\"value\" type=\"encoded_string\"/>\n") 
							++ "<xs:element name=\"source_rep\" type=\"encoded_string\"/>\n"
	++ "</xs:sequence>\n"
	++	"</xs:complexType>\n\n"

token_type _ = error "Can't create a terminal type for a non-terminal token type -- token_type\n"

-- Given a grammar construct a set of xs:complexTypes that correspond to the
-- compound statements bodies
concrete_types :: Grammar -> Grammar -> String
concrete_types _ [] = []
concrete_types g ((Disjunction _ _):tail) = concrete_types g tail
concrete_types g ((Conjunction lhs rhs):tail) = (concrete_type g lhs rhs) ++ (concrete_types g tail)

concrete_type :: Grammar -> NonTerminalName -> [Term] -> String
concrete_type g lhs rhs = 
		"<xs:complexType name=\"AST_" ++ lhs ++ "\">\n"
	++	"<xs:sequence>\n"
	++	"<xs:element name=\"attrs\" type=\"attrs\"/>\n"
	++	concat (map (xsd_body g) rhs)
	++ "</xs:sequence>\n"
	++	"</xs:complexType>\n\n"

xsd_body :: Grammar -> Term -> String
xsd_body g t@(label, sym, mult) =
	if (is_marker sym) || (is_concrete_xs_type g t) then 
		"<xs:element name=\"" ++ (symbol_to_xs_name sym mult) 
			++ "\" type=\"" ++ (symbol_to_xs_type g sym mult) 
			++ "\" nillable=\"" ++ (if (is_nillable sym mult) then "true" else "false") ++ "\"/>\n"
	else
		"<xs:group ref=\"" ++ (symbol_to_xs_type g sym mult) ++ "\"/>\n"

is_concrete_xs_type :: Grammar -> Term -> Bool
is_concrete_xs_type gmr (label, sym, mult) = is_concrete gmr sym || 
	(case mult of
		Vector 		-> True
		OptVector 	-> True
		VectorOpt	-> True
		_				-> False)

is_nillable :: Symbol -> Multiplicity -> Bool
is_nillable (Marker _) m = False
is_nillable _ m = 
	case m of
		Optional	-> True
		OptVector	-> True
		_		-> False

symbol_to_xs_type :: Grammar -> Symbol -> Multiplicity -> String
symbol_to_xs_type _ (Marker _) _ = "xs:boolean"
symbol_to_xs_type gmr s m = 
	case m of
		Single 		-> name
		Vector 		-> name ++ "_list"
		Optional 	-> name ++ (if (is_concrete gmr s) then "" else "_optional")
		OptVector 	-> name ++ "_list"
		VectorOpt 	-> name ++ "_list_optionals"
	where
		name = symbol_to_classname s

symbol_to_xs_name :: Symbol -> Multiplicity -> String
symbol_to_xs_name s m =
	case m of
		Single 		-> name
		Vector 		-> name ++ "_list"
		Optional 	-> name
		OptVector 	-> name ++ "_list"
		VectorOpt 	-> name ++ "_list"
	where
		name = symbol_to_classname s

start_nonterminal_name :: Grammar -> NonTerminalName
start_nonterminal_name (first_rule:tail) = lhs first_rule

lhs :: Rule -> NonTerminalName
lhs (Conjunction name _) = name
lhs (Disjunction name _) = name

rhs :: Rule -> [Term]
rhs (Conjunction _ terms) = terms
rhs (Disjunction _ terms) = terms

list_type_to_single :: Symbol -> Multiplicity -> String
list_type_to_single s m =
	case m of
		OptVector	-> name
		Vector		-> name
		VectorOpt	-> name ++ "_optional"
		_				-> error "Error in list_type_to_single"
	where
		name = symbol_to_classname s
