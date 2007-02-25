{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	For each context (_, c, Vector), we generate a specialised list class 
	AST_c_list for c. AST_c_list will inherit from List<c*> so that it can
	be treated like a standard STL list. In addition, in order to make 
	covariance work, we need to find all superclasses s of c, and their
	contexts (s, s', m). If m is not a vector, AST_c_list must inherit from s;
	otherwise, AST_c_list must inherit from AST_s_list.

	Then, for all remaining symbols s that appear as a vector in the grammar,
	we generate a list class which does inherits only from AST_node.
-}

module ListClasses where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import GrammarAnalysis
import Contexts
import List

{-
	Traverse the grammar and for every (unique) occurence of foo*,
	define a special class called foo_list
-}
list_classes :: Grammar -> [Context] -> InheritanceRel -> [CppClass]
list_classes gr cx ih = map (make_list_class cx ih) (find_lists gr cx) 

find_lists :: Grammar -> [Context] -> [ClassName]
find_lists gr cx = nub (from_contexts ++ remaining_lists gr)
	where
		from_contexts = [c | (_, c, v) <- cx, is_vector v]

remaining_lists :: Grammar -> [ClassName]
remaining_lists [] = []
remaining_lists (Disjunction _ _:tail) = remaining_lists tail
remaining_lists (Conjunction _ body:tail) 
		= concatMap f body ++ remaining_lists tail
	where
		f :: Term -> [ClassName]
 		f (_, sym, mult) 
			| is_vector mult = [symbol_to_classname sym]
			| otherwise = []


{-
	Make a list class foo_list for a symbol foo
-}
make_list_class :: [Context] -> InheritanceRel -> ClassName -> CppClass
make_list_class cx ih cn = CppClass Concrete name extends [] methods 
	where
		name = cn ++ "_list"
		extends = 
			let (_, _, m) = find_context cn cx in
			if is_vector m 
			then ("List<" ++ cn ++ "*>") : map inh (direct_superclasses ih cn)
			else ["List<" ++ cn ++ "*>", "AST_node"] 
		inh s = 
			let (_, s', m) = find_context s cx in 
			if is_vector m then s' ++ "_list" else s'
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
		rt = Type (cn ++ "_list*")
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
				"visitor->children_" ++ (classname_to_varname cn) ++ "_list(this);"
			]
		post_visit = Method (Signature Virtual NonStatic Void "post_visit" [visitor]) 
			(map post sc)
		pre name = "visitor->pre_" ++ (snd (split '_' name)) ++ "(this);"
		post name = "visitor->post_" ++ (snd (split '_' name)) ++ "(this);"
		-- Transform methods
		transform = Method (Signature Virtual NonStatic rt "transform" [treetransform]) 
			[
				cn ++ "_list* node = pre_transform(transform);",
				"node->transform_children(transform);",
				"return node->post_transform(transform);"
			]
		pre_transform = Method (Signature Virtual NonStatic rt "pre_transform" [treetransform]) 
			[
				"return transform->pre_" ++ classname_to_varname cn ++ "_list(this);"
			]
		transform_children = Method (Signature Virtual NonStatic Void "transform_children" [treetransform]) 
			[
				"transform->children_" ++ classname_to_varname cn ++ "_list(this);"
			]
		post_transform = Method (Signature Virtual NonStatic rt "post_transform" [treetransform]) 
			[
				"return transform->post_" ++ classname_to_varname cn ++ "_list(this);"
			]
