{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	For every symbol c where this is necessary, we generate a specialised list
	class c_list, which will inherit from List<c*>. 

	We must be careful with covariance. If there is a context (c', c, Vector)
	that means that there will be methods in c' that return a c_list (in
	particular, the pre_ and post_ transform methods). For that to be correct
	(covariantly), c_list must inherit from whatever pre_method returns in all
	superclasses of c'. More precisely, for all superclasses s of c', we must
	find the context (s, s', m), and c_list must inherit whatever class
	represents (s', m).
-}

module ListClasses where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import GrammarAnalysis
import Contexts
import List
import Debug.Trace

{-
	Traverse the grammar and for every (unique) occurence of foo*,
	define a special class called foo_list
-}
list_classes :: Grammar -> [Context] -> InheritanceRel -> [CppClass]
list_classes gr cx ih = map (make_list_class cx ih) (find_lists gr cx) 

find_lists :: Grammar -> [Context] -> [ClassName]
find_lists gr cx = nub (from_contexts ++ expl_lists gr)
	where
		from_contexts = [c | (_, c, m) <- cx, is_vector m]

-- All explicitely mentioned lists 
expl_lists :: Grammar -> [ClassName]
expl_lists [] = []
expl_lists (Disjunction nt _:tail) = expl_lists tail 
expl_lists (Conjunction nt body:tail) = concatMap f body ++ expl_lists tail
	where
		f :: Term -> [ClassName]
 		f (_, sym, m) = if is_vector m then [symbol_to_classname sym] else []

{-
	Make a list class foo_list for a symbol foo
-}
make_list_class :: [Context] -> InheritanceRel -> ClassName -> CppClass
make_list_class cx ih cn = CppClass Concrete name extends [] methods 
	where
		name = cn ++ "_list"
		extends = ("List<" ++ cn ++ "*>") : covariance cx ih cn 
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

{-
	covariance c works out what list_c needs to inherit from 
	(see remark at the top of this file)

	Note that a class should never inherit from itself, and every class should
	inherit from AST_node.
-}

covariance :: [Context] -> InheritanceRel -> ClassName -> [ClassName]
covariance cx ih c = nub . filter (/= (c ++ "_list")) $ "AST_node":map f cx_s 
	where
		-- Map a context to a classname
		f (_, cn, m) = if is_vector m then cn ++ "_list" else cn
		-- Context for each superclass s
		cx_s = map (flip find_context cx) ss
		-- Superclasses of c's
		ss = (concatMap (direct_superclasses ih) c's)
		-- Find out which classes return a c_list
		c's = [c' | (c',c0,m) <- cx, c == c0, is_vector m]
