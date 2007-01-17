{-
	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Deep equality. See PatternMatching for a comparison. 
-}

module DeepEquality where

import MakeTeaParser
import MakeTeaCpp

{-
	Add a "deep_equals" method that compares every variable in a class to a variable
	in another class. The type of the argument must be passed in.
-}
add_deep_equals_method :: Type -> CppClass -> CppClass
add_deep_equals_method argt cl = CppClass concrete cn inh vars ((deep_equals_method argt cl):meth)
	where
		(CppClass concrete cn inh vars meth) = cl 

{-
	Match methods for a class
-}
deep_equals_method :: Type -> CppClass -> Method
deep_equals_method argt cl = Method signature body 
	where
		(CppClass concrete cn inh vars methods) = cl
		signature = Signature Virtual NonStatic (Type "bool") "deep_equals" [Parameter (Variable argt "other") ""]	
		init =
			[
				cn ++ "* that = dynamic_cast<" ++ cn ++ "*>(other);",
				"if(!that) return false;",
				""
			]
		body = init ++ parent_deep_equals ++ [""] ++ (concatMap compare vars) ++ ["", "return true;"]
		parent_deep_equals = map (\x -> "if(!" ++ x ++ "::deep_equals(that)) return false;") inh
		compare :: Variable -> [String]
		compare (Variable t n) =
			if
				not (is_pointer t)
			then
				["if(" ++ n ++ " != that->" ++ n ++ ") return false;"]
			else
				[
				 "if(" ++ n ++ " == NULL)",
				 "\t{ if(that->" ++ n ++ " != NULL) return false; }",
				 "else",
				 "\t{ if(!" ++ n ++ "->deep_equals(that->" ++ n ++ ")) return false; }"
				]
