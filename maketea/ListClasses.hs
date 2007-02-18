{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Specialised List classes	
-}

module ListClasses where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import GrammarAnalysis
import List

{-
	Traverse the grammar and for every (unique) occurence of foo*,
	define a special class called foo_list
-}
list_classes :: Grammar -> InheritanceRel -> [CppClass]
list_classes grammar ih = map (symbol_to_list_class ih) symbols 
	where
		symbols = nub (find_lists grammar)

{-
	Traverse the grammar and find all lists
-}
find_lists :: Grammar -> [Symbol]
find_lists [] = []
find_lists (Disjunction _ _:tail) = find_lists tail
find_lists (Conjunction _ body:tail) = concatMap f body ++ find_lists tail
	where
		f :: Term -> [Symbol]
		f (_, sym@(Terminal _ _), _) = [sym]
		f (_, sym@(NonTerminal _), _) = [sym]
		f _ = []

{-
	Make a list class foo_list for a symbol foo
-}
symbol_to_list_class :: InheritanceRel -> Symbol -> CppClass
symbol_to_list_class ih sym = CppClass Concrete name extends [] methods 
	where
		name = (symbol_to_classname sym ++ "_list")
		extends = 
			if null (direct_superclasses ih name)
			then ["List<" ++ (symbol_to_classname sym) ++ "*>","AST_node"] 
			else ["List<" ++ (symbol_to_classname sym) ++ "*>"] ++ direct_superclasses ih name 
		methods =
			[
				visit,
				pre_visit,
				visit_children,
				post_visit,
				transform,
				pre_transform,
				transform_children,
				post_transform
			]
		rt = Type (symbol_to_classname sym ++ "_list*")
		treetransform = Parameter (Variable (Type "Tree_transform*") "transform") ""
		visitor = Parameter (Variable (Type "Tree_visitor*") "visitor") ""
		-- Visit methods
		sc = all_superclasses ih name
		visit = Method (Signature Virtual NonStatic Void "visit" [visitor]) 
			[
				"pre_visit(visitor);",
				"visit_children(visitor);",
				"post_visit(visitor);"
			]
		pre_visit = Method (Signature Virtual NonStatic Void "pre_visit" [visitor]) 
			(map pre (reverse sc))
		visit_children = Method (Signature Virtual NonStatic Void "visit_children" [visitor]) 
			[
				"visitor->children_" ++ (symbol_to_varname sym) ++ "_list(this);"
			]
		post_visit = Method (Signature Virtual NonStatic Void "post_visit" [visitor]) 
			(map post sc)
		pre name = "visitor->pre_" ++ (snd (split '_' name)) ++ "(this);"
		post name = "visitor->post_" ++ (snd (split '_' name)) ++ "(this);"
		-- Transform methods
		transform = Method (Signature Virtual NonStatic rt "transform" [treetransform]) 
			[
				symbol_to_classname sym ++ "_list* node = pre_transform(transform);",
				"node->transform_children(transform);",
				"return node->post_transform(transform);"
			]
		pre_transform = Method (Signature Virtual NonStatic rt "pre_transform" [treetransform]) 
			[
				"return transform->pre_" ++ symbol_to_varname sym ++ "_list(this);"
			]
		transform_children = Method (Signature Virtual NonStatic Void "transform_children" [treetransform]) 
			[
				"transform->children_" ++ symbol_to_varname sym ++ "_list(this);"
			]
		post_transform = Method (Signature Virtual NonStatic rt "post_transform" [treetransform]) 
			[
				"return transform->post_" ++ symbol_to_varname sym ++ "_list(this);"
			]
