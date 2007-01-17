{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Construct the TreeVisitor class, and add the pre_visit, visit_children, and
	post_visit to the AST classes
-}

module TreeVisitor where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import GrammarAnalysis
import List 
import ListClasses

{-
	Add calls to the TreeVisitor API
-}
add_visitor_calls :: InheritanceRel -> CppClass -> CppClass
add_visitor_calls ir (CppClass concr name inh vars meth) = CppClass concr name inh vars new_meth
	where
		new_meth = meth ++ case concr of
			Abstract -> 
				[
				 Method (Signature PureVirtual NonStatic Void "visit" [inp]) [], 
				 Method (Signature PureVirtual NonStatic Void "pre_visit" [inp]) [],
				 Method (Signature PureVirtual NonStatic Void "visit_children" [inp]) [],
				 Method (Signature PureVirtual NonStatic Void "post_visit" [inp]) [] 
				]
			Concrete -> 
				[
				 visit,
				 pre_visit ir name, 
				 visit_children name, 
				 post_visit ir name
				]
		inp = Parameter (Variable (Type "Tree_visitor*") "visitor") ""

visit :: Method
visit = Method sig body
	where
		sig = Signature Virtual NonStatic Void "visit" [inp]
		inp = Parameter (Variable (Type "Tree_visitor*") "visitor") ""
		body = 
			[
			 "pre_visit(visitor);",
			 "visit_children(visitor);",
			 "post_visit(visitor);"
			]

pre_visit :: InheritanceRel -> ClassName -> Method
pre_visit ir name = Method sig body
	where
		sig = Signature Virtual NonStatic Void "pre_visit" [inp]
		inp = Parameter (Variable (Type "Tree_visitor*") "visitor") ""
		body = map pre (reverse sc) 
		pre name = "visitor->pre_" ++ (snd (split '_' name)) ++ "(this);"
		sc = all_superclasses ir name

visit_children :: ClassName -> Method
visit_children name = Method sig body
	where
		sig = Signature Virtual NonStatic Void "visit_children" [inp]
		inp = Parameter (Variable (Type "Tree_visitor*") "visitor") ""
		body = ["visitor->children_" ++ (snd (split '_' name)) ++ "(this);"]

post_visit :: InheritanceRel -> ClassName -> Method
post_visit ir name = Method sig body 
	where
		sig = Signature Virtual NonStatic Void "post_visit" [inp]
		inp = Parameter (Variable (Type "Tree_visitor*") "visitor") ""
		body = map post sc 
		post name = "visitor->post_" ++ (snd (split '_' name)) ++ "(this);"
		sc = all_superclasses ir name

{-
	Generate the Tree_visitor class
-}

visitor_class :: Grammar -> CppClass
visitor_class g = CppClass Concrete "Tree_visitor" [] [] 
	([destructor] ++ ast_visitor_methods g ++ token_visitor_methods (terminal_list g) ++ list_visitor_methods g)
	where
		destructor = Method (Signature Virtual NonStatic NoType "~Tree_visitor" []) [] 
token_visitor_methods :: [Symbol] -> [Method]
token_visitor_methods [] = []
token_visitor_methods (t:ts) = methods ++ (token_visitor_methods ts)
	where
		methods = 
			[Method (Signature Virtual NonStatic Void ("pre_" ++ (symbol_to_varname t)) [inp]) [],
			 Method (Signature Virtual NonStatic Void ("children_" ++ (symbol_to_varname t)) [inp]) [],
			 Method (Signature Virtual NonStatic Void ("post_" ++ (symbol_to_varname t)) [inp]) []]
		inp = Parameter (Variable (Type (symbol_to_classname t ++ "*")) "in") ""

ast_visitor_methods :: Grammar -> [Method]
ast_visitor_methods [] = []
ast_visitor_methods ((Disjunction lhs _):rest) = methods ++ (ast_visitor_methods rest)
	where
		methods =
			[Method (Signature Virtual NonStatic Void ("pre_" ++ lhs) [inp]) [],
			 Method (Signature Virtual NonStatic Void ("post_" ++ lhs) [inp]) []]
		inp = Parameter (Variable (Type ("AST_" ++ lhs ++ "*")) "in") ""
ast_visitor_methods ((Conjunction lhs rhs):rest) = methods ++ (ast_visitor_methods rest)
	where
		methods = 
			[Method (Signature Virtual NonStatic Void ("pre_" ++ lhs) [inp]) [],
			 Method (Signature Virtual NonStatic Void ("children_" ++ lhs) [inp]) (default_visit_children rhs),
			 Method (Signature Virtual NonStatic Void ("post_" ++ lhs) [inp]) []]
		inp = Parameter (Variable (Type ("AST_" ++ lhs ++ "*")) "in") ""
		
default_visit_children :: [Term] -> Body
default_visit_children rhs = concatMap f rhs
	where
		f :: Term -> Body
		f term@(label, sym, mult) =
			let 
				var_name = term_to_varname term 
			in 
			if is_marker sym then
				[]
			else
				(if is_optional mult then 
					["if(in->" ++ var_name ++ " != NULL)"]
				else
					[]) ++
				["in->" ++ var_name ++ "->visit(this);"]

list_visitor_methods :: Grammar -> [Method]
list_visitor_methods gr = concatMap f (nub (find_lists gr))
	where
		f :: Symbol -> [Method]
		f sym = [list_pre sym, list_children sym, list_post sym]

list_pre :: Symbol -> Method
list_pre sym = Method (Signature Virtual NonStatic Void ("pre_" ++ symbol_to_varname sym ++ "_list") [param]) []
	where
		param = Parameter (Variable (Type (symbol_to_classname sym ++ "_list*")) "in") ""

list_post :: Symbol -> Method
list_post sym = Method (Signature Virtual NonStatic Void ("post_" ++ symbol_to_varname sym ++ "_list") [param]) []
	where
		param = Parameter (Variable (Type (symbol_to_classname sym ++ "_list*")) "in") ""

list_children :: Symbol -> Method
list_children sym = Method (Signature Virtual NonStatic Void ("children_" ++ symbol_to_varname sym ++ "_list") [param]) body 
	where
		param = Parameter (Variable (Type (symbol_to_classname sym ++ "_list*")) "in") ""
		body =
			[
				"List<" ++ symbol_to_classname sym ++ "*>::const_iterator i;",
				"for(i = in->begin(); i != in->end(); i++)",
				"\tif(*i) (*i)->visit(this);"
			]

{-
	C++ .h and .cpp files
-}

visitor_h :: CppClass -> [Include] -> String
visitor_h cl includes = maketea_header ++ prefix ++ body ++ postfix
	where
		body = show_class_signature cl
		prefix = ppifix "" "\n" "" $
			[
			 "#ifndef _VISITOR_H_",
			 "#define _VISITOR_H_",
			 "",
			 "#include \"ast.h\""
			] ++ (map ("#include " ++) includes) ++
			[
			 ""
			]	
		postfix = "\n#endif // _VISITOR_H_\n"
		
visitor_cpp :: CppClass -> String
visitor_cpp cl = maketea_header ++ "#include \"Tree_visitor.h\"\n\n" ++ body
	where
		body = show_class_methods cl

