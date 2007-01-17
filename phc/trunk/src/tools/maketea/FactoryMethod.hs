{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Factory method for the AST nodes	
-}

module FactoryMethod where

import MakeTeaParser
import MakeTeaCpp
import GrammarAnalysis
import ListClasses
import List

factory_method :: Grammar -> InheritanceRel -> Type -> CppClass 
factory_method gr ih gt = CppClass Concrete "AST_node_factory" [] [] [create, create1] 
	where
		create = Method sig body
		body = prefix ++ ast_classes ++ token_classes ++ list_classes ++ postfix 
		ast_classes = concatMap rule_to_body gr
		token_classes = concatMap terminal_to_body (terminal_list gr)
		list_classes = concatMap list_to_body (nub (find_lists gr))
		prefix =
			[
			 "List<" ++ (show gt) ++ ">::const_iterator i = args->begin();",
			 ""
			]
		postfix =
			[
			 "",
			 "cout << \"AST_node_factory::create: unknown class '\" << name << \"'\" << endl;",
			 "abort();"
			]
		sig = Signature NonVirtual Static (Type (sc ++ "*")) "create" [name, list]
		name = Parameter (Variable (Type "char*") "name") ""
		list = Parameter (Variable (Type ("List<" ++ (show gt) ++ ">*")) "args") ""
		sc = superclass ih
		-- Convenience method for a call to create with one parameter
		create1 = Method (Signature NonVirtual Static (Type (sc ++ "*")) "create" [name, one]) 
			[
			 "List<" ++ (show gt) ++ ">* list = new List<" ++ (show gt) ++ ">;",
			 "list->push_back(arg);",
			 "return create(name, list);"
			]
		one = Parameter (Variable (Type (show gt)) "arg") ""

rule_to_body :: Rule -> Body
-- We cannot instanstiate abstract classes
rule_to_body (Disjunction head body) = []
rule_to_body (Conjunction head body) = 
	[
	 "if(!strcmp(name, \"AST_" ++ head ++ "\")) {",
	 "\tAST_" ++ head ++ "* rv = new AST_" ++ head ++ "();"
	] 
	++ concatMap term_to_body body ++ 
	[
	 "\tassert(i == args->end()); // Check for too many arguments",
	 "\treturn rv;",
	 "}"
	]

term_to_body :: Term -> Body 
term_to_body term@(label, symbol, mult) =
		case symbol of
			Marker _ -> 
				[
				 "\t{",
				 "\t\tassert(i != args->end()); // Check for too few arguments",
				 "\t\tBoolean* boolean = dynamic_cast<Boolean*>(*i++);",
				 "\t\tassert(boolean); // Verify argument type",
				 "\t\trv->" ++ varname ++ " = boolean->value();",
				 "\t}"
				]
			_ -> 
				[
				 "\t{",
				 "\t\tassert(i != args->end()); // Check for too few arguments",
				 "\t\t" ++ classname ++ "* arg;",
				 "\t\targ = dynamic_cast<" ++ classname ++ "*>(*i);",
				 (if is_optional mult then
				 	"\t\tassert(!*i || arg); // Verify argument type"
				  else
				 	"\t\tassert(arg); // Verify argument type"),
				 "\t\trv->" ++ varname ++ " = arg;",
				 "\t\ti++;",
				 "\t}"
				]
	where
		classname = term_to_classname term
		varname = term_to_varname term

{-
	We can only generate code for terminal symbols with a default
	(String*) value
-}
terminal_to_body :: Symbol -> Body 
terminal_to_body term@(Terminal name value) = 
	case value of
		Just t -> []
		Nothing ->
			[
			 "if(!strcmp(name, \"" ++ classname ++ "\")) {",
			 "\tassert(i != args->end()); // Check for too few arguments",
			 "\tString* string = dynamic_cast<String*>(*i++);",
			 "\tassert(string); // Verify argument type",
			 "\t" ++ classname ++ "* rv = new " ++ classname ++ "(string);",
		 	 "\tassert(i == args->end()); // Check for too many arguments",
		 	 "\treturn rv;",
			 "}"
			]
	where
		classname = symbol_to_classname term 

list_to_body :: Symbol -> Body
list_to_body sym = 
		[
		 "if(!strcmp(name, \"" ++ listname ++ "\")) {",
		 "\t" ++ listname ++ "* rv = new " ++ listname ++ ";",
		 "\tfor(; i != args->end(); i++)",
		 "\t{",
		 "\t\t" ++ classname ++ "* arg = dynamic_cast<" ++ classname ++ "*>(*i);",
		 "\t\tassert(!*i || arg); // Verify argument type",
		 "\t\trv->push_back(arg);",
		 "\t}",
		 "\treturn rv;",
		 "}"
		]
	where
		classname = symbol_to_classname sym
		listname = classname ++ "_list" 
