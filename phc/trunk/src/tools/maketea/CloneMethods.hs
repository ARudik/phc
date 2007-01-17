{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Add clone methods to the AST nodes
-}

module CloneMethods where

import MakeTeaParser
import MakeTeaCpp

{-
	Add a clone method that copies or clones every variable in a class.
	The type of the partial clone argument must be passed in.
-}
add_clone_method :: Type -> CppClass -> CppClass
add_clone_method argt cl 
		= CppClass concrete cn inh vars ((clone_method argt cl):methods)
	where
		(CppClass concrete cn inh vars methods) = cl

{-
	Clone methods for a class
-}
clone_method :: Type -> CppClass -> Method
clone_method argt cl 
		= Method signature (init ++ parent_clone ++ body ++ ["", "return clone;"])
	where
		(CppClass concrete cn inh vars meth) = cl
		signature = Signature Virtual NonStatic rt "deep_clone" [Parameter (Variable argt "partial_result") "NULL"] 
		init = case concrete of
			Concrete ->
				[
				 cn ++ "*" ++ " clone;",
				 "",
				 "if(partial_result)",
				 	"\tclone = dynamic_cast<" ++ cn ++ "*>(partial_result);",
				 "else", 
				 	"\tclone = new " ++ cn ++ "();",
				 "assert(clone);",
				 ""
				]
			Abstract ->	
				[
				 "// abstract class",
				 cn ++ "*" ++ " clone = dynamic_cast<" ++ cn ++ "*>(partial_result);",
				 "assert(clone);",
				 ""
				]
		rt = Type (cn ++ "*")
		parent_clone = map (++ "::deep_clone(clone);") inh
		body = concatMap f vars
		f :: Variable -> [String]
		f (Variable t n) = 
			if 
				not (is_pointer t)	
			then 
				["", "clone->" ++ n ++ " = " ++ n ++ ";"]
			else 
				[
				 "",
				 "if(" ++ n ++ ")",
					"\tclone->" ++ n ++ " = " ++ n ++ "->deep_clone();",
				 "else", 
				 	"\tclone->" ++ n ++ " = NULL;",
				 "assert(!" ++ n ++ " || clone->" ++ n ++ ");"
				]
	
