{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Skeleton AST classes	
-}

module SkeletonClasses where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import GrammarAnalysis

{-
	Based on the grammar, derive a set of skeleton classes that define their
	superclasses, and their instance variables, but do not contain any
	methods.
-}
skeleton_classes :: InheritanceRel -> Grammar -> [CppClass]
skeleton_classes ir grammar = ast_classes ++ token_classes 
	where
		ast_classes =  map (rule_to_class ir) grammar
		token_classes = map (terminal_to_class ir) (terminal_list grammar)
	
{-
	Disjunctive rules lead to abstract classes with no instance variables,
	but conjunctive rules lead to classes with an instance variable for each
	term in the right hand side of the rule.
-}
rule_to_class :: InheritanceRel -> Rule -> CppClass
rule_to_class ir (Disjunction head body) = CppClass Abstract name inherits_from [] [] 
	where
		name = "AST_" ++ head
		inherits_from = direct_superclasses ir name
rule_to_class ir (Conjunction head body) = CppClass Concrete name inherits_from attrs [] 
	where
		name = "AST_" ++ head
		inherits_from = direct_superclasses ir name 
		attrs = map term_to_variable body

{-
	The class for a terminal symbol has at least one "value" attribute, the
	type of which defaults to String* if it not specified in the grammar. If it
	_is_ specified, the class will have an additional "source_rep" attribute
	which will be a String*.

	For convenience, the class with also get a "get_value_as_string" method, 
	_if_ the value attribute is the default String*. Otherwise, this will have
	to be supplied by the user. 

	If the type of the "value" is specified to be empty, the value attribute is
	omitted, but a source_rep attribute is added.

	If the class has a source_rep attribute, it will also be supplied with a 
	get_source_rep method.
-}
terminal_to_class :: InheritanceRel -> Symbol -> CppClass
terminal_to_class ir term@(Terminal name vtype) = 
		case vtype of
			Nothing -> CppClass Concrete cn inherits_from [value "String*"] [get_value_as_string]
			Just "" -> CppClass Concrete cn inherits_from [source_rep] [get_source_rep]
			Just t -> CppClass Concrete cn inherits_from [value t, source_rep] [get_source_rep]
	where
		cn = symbol_to_classname term 
		inherits_from = direct_superclasses ir cn 
		source_rep = Variable (Type "String*") "source_rep"
		value t = Variable (Type t) "value"
		get_value_as_string = Method (Signature Virtual NonStatic (Type "String*") "get_value_as_string" []) ["return value;"]
		get_source_rep = Method (Signature Virtual NonStatic (Type "String*") "get_source_rep" []) ["return source_rep;"]

{- 
	Convert a term from a RHS in a conjunction to a variable of the appropriate type
-}

term_to_variable :: Term -> Variable
term_to_variable term@(label, symbol, mult) = Variable t (term_to_varname term)
	where
		st = term_to_classname term 
		t = case symbol of
			Marker m -> Type st
			_ -> Type (st ++ "*")

{-
	The contents of the generated files (unparsing, basically).
-}

ast_h :: [CppClass] -> [Include] -> String
ast_h classes includes = maketea_header ++ prefix ++ body ++ postfix
	where
		body = list_of_classes ++ "\n" ++ class_definitions
		prefix = ppifix "" "\n" "" $
			["#ifndef _AST_H_",
			 "#define _AST_H_",
			 ""
			 ] ++ (map ("#include " ++) includes) ++
			 [
			 "",
			 "class Tree_transform;",
			 "class Tree_visitor;",
			 ""
			]
		postfix = "\nextern Wildcard* WILDCARD;\n\n#endif // _AST_H_\n"
		list_of_classes = ppifix "class " ";\n" "" (class_names classes)
		class_definitions = ppifix "" "" "\n" (map show_class_signature classes)

ast_cpp :: [CppClass] -> String
ast_cpp classes = maketea_header ++ prefix ++ body 
	where
		prefix = ppifix "" "\n" ""
			[
			 "#include \"ast.h\"",
			 "#include \"Tree_transform.h\"",
			 "#include \"Tree_visitor.h\"",
			 "",
			 "Wildcard* WILDCARD = new Wildcard;",
			 ""
			]
		body = ppifix "" "" "\n" (map show_class_methods classes) 

