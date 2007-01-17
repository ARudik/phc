{-
	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Add pattern matching. Note that pattern matching without wildcards is the 
	same as deep equality as far as this module is concerned, but the difference is
	in the main module; the "match" function gets added before the mixin code, and
	does thus not take into account the mixin code (e.g., line numbers and 
	comments), whereas the "deep_equals" method gets added after the mixin code,
	and therefore _does_ take into account line numbers etc.
-}

module PatternMatching where

import MakeTeaParser
import MakeTeaCpp

{-
	Add a "match" method that compares every variable in a class to a variable
	in another class. The type of the argument must be passed in.
-}
add_match_method :: Type -> CppClass -> CppClass
add_match_method argt cl = CppClass concrete cn inh vars new_meth
	where
		new_meth = [try_match argt cl, replace_wildcards argt cl] ++ meth
		(CppClass concrete cn inh vars meth) = cl 

{-
	try_match tries if there is a match, but does not replace wildcards	
-}
try_match :: Type -> CppClass -> Method
try_match argt cl = Method signature body 
	where
		(CppClass concrete cn inh vars methods) = cl
		signature = Signature Virtual NonStatic (Type "bool") "try_match" [Parameter (Variable argt "pattern") ""]	
		init =
			[
				cn ++ "* that = dynamic_cast<" ++ cn ++ "*>(pattern);",
				"if(!that) return false;",
				""
			]
		body = init ++ parent_matches ++ [""] ++ (concatMap compare vars) ++ ["", "return true;"]
		parent_matches = map (\x -> "if(!" ++ x ++ "::try_match(that)) return false;") inh
		compare :: Variable -> [String]
		compare (Variable t n) =
			if
				not (is_pointer t)
			then
				["if(" ++ n ++ " != that->" ++ n ++ ") return false;"]
			else
				[
				 "if(dynamic_cast<void*>(that->" ++ n ++ ") == dynamic_cast<void*>(WILDCARD))",
				 "\t{ /* ignore */ }",
				 "else if(" ++ n ++ " == NULL)",
				 "\t{ if(that->" ++ n ++ " != NULL) return false; }",
				 "else",
				 "\t{ if(!" ++ n ++ "->try_match(that->" ++ n ++ ")) return false; }"
				]

{-
	replace_wildcards assumes that there is a match, and replaces the wildcards
	in the pattern
-}
replace_wildcards :: Type -> CppClass -> Method
replace_wildcards argt cl = Method signature body 
	where
		(CppClass concrete cn inh vars methods) = cl
		signature = Signature Virtual NonStatic (Type "void") "replace_wildcards" [Parameter (Variable argt "pattern") ""]	
		init =
			[
				cn ++ "* that = dynamic_cast<" ++ cn ++ "*>(pattern);",
				"assert(that);",
				""
			]
		body = init ++ parent_matches ++ [""] ++ (concatMap compare vars)
		parent_matches = map (\x -> x ++ "::replace_wildcards(that);") inh
		compare :: Variable -> [String]
		compare (Variable t n) =
			if
				not (is_pointer t)
			then
				[]
			else
				[
				 "if(dynamic_cast<void*>(that->" ++ n ++ ") == dynamic_cast<void*>(WILDCARD))",
				 "\t{ that->" ++ n ++ " = " ++ n ++ "; }",
				 "else if(" ++ n ++ " != NULL)",
				 "\t{ " ++ n ++ "->replace_wildcards(that->" ++ n ++ "); }"
				]

{-
	The Wildcard class
-}
wildcard :: Type -> [ClassName] -> CppClass
wildcard argt inh = CppClass Concrete "Wildcard" ("String":inh) [] methods
	where
		methods = 
			[
			 visit, 
			 pre_visit, 
			 visit_children,
			 post_visit,
			 transform,
			 pre_transform,
			 transform_children,
			 post_transform,
			 get_source_rep,
			 get_value_as_string,
			 deep_clone,
			 deep_equals,
			 match,
			 try_match,
			 replace_wildcards
			]
		get_source_rep = Method (Signature Virtual NonStatic (Type "String*") "get_source_rep" []) (not_understood True "get_source_rep")
		get_value_as_string = Method (Signature Virtual NonStatic (Type "String*") "get_value_as_string" []) (not_understood True "get_value_as_string")
		visit = Method (Signature Virtual NonStatic Void "visit" [Parameter (Variable (Type "Tree_visitor*") "visitor") ""]) (not_understood False "visit")
		pre_visit = Method (Signature Virtual NonStatic Void "pre_visit" [Parameter (Variable (Type "Tree_visitor*") "visitor") ""]) (not_understood False "pre_visit")
		visit_children = Method (Signature Virtual NonStatic Void "visit_children" [Parameter (Variable (Type "Tree_visitor*") "visitor") ""]) (not_understood False "visit_children")
		post_visit = Method (Signature Virtual NonStatic Void "post_visit" [Parameter (Variable (Type "Tree_visitor*") "visitor") ""]) (not_understood False "post_visit")
		transform = Method (Signature Virtual NonStatic (Type "Wildcard*") "transform" [Parameter (Variable (Type "Tree_transform*") "transform") ""]) (not_understood True "transform")
		pre_transform = Method (Signature Virtual NonStatic (Type "Wildcard*") "pre_transform" [Parameter (Variable (Type "Tree_transform*") "pre_transform") ""]) (not_understood True "pre_transform")
		transform_children = Method (Signature Virtual NonStatic Void "transform_children" [Parameter (Variable (Type "Tree_transform*") "transform_children") ""]) (not_understood False "transform_children")
		post_transform = Method (Signature Virtual NonStatic (Type "Wildcard*") "post_transform" [Parameter (Variable (Type "Tree_transform*") "post_transform") ""]) (not_understood True "post_transform")
		deep_equals = Method (Signature Virtual NonStatic (Type "bool") "deep_equals" [Parameter (Variable argt "pattern") ""]) (not_understood True "deep_equals")
		deep_clone = Method (Signature Virtual NonStatic (Type "Wildcard*") "deep_clone" [Parameter (Variable argt "partial_result") ""]) 
			[
				"// Wildcard should not be inherited from",
				"assert(partial_result == NULL);",
				"// The only Wildcard instance is a singleton",
				"return this;"
			]
		match = Method (Signature Virtual NonStatic (Type "bool") "match" [Parameter (Variable argt "pattern") ""]) (not_understood True "match")
		try_match = Method (Signature Virtual NonStatic (Type "bool") "try_match" [Parameter (Variable argt "pattern") ""]) (not_understood True "try_match")
		replace_wildcards = Method (Signature Virtual NonStatic (Type "void") "replace_wildcards" [Parameter (Variable argt "pattern") ""]) (not_understood False "replace_wildcards")
		not_understood :: Bool -> String -> Body 
		not_understood ret fn =
			[
				"cout << \"Invalid call to '" ++ fn ++ "' on a wildcard object!\" << endl;",
				"assert(false);"
			] ++ (if ret then ["return 0;"] else [])
		
