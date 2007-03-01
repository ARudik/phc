{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Add constructors to the AST classes	
-}

module Constructors where

import MakeTeaParser
import MakeTeaCpp

{-
	Add a default constructor with no arguments, and a setup constructor with
	an argument for every variable in the class. We do not add constructors to
	abstract classes.
-}

add_constructors :: CppClass -> CppClass
add_constructors cl = case concrete of
		Abstract -> cl
		Concrete -> CppClass concrete name inh vars meth' 
	where
		(CppClass concrete name inh vars meth) = cl
		dc = default_constructor name
		sc = setup_constructor name vars
		meth' = if null vars then sc:meth else dc:sc:meth

-- Default constructor (that does nothing)
default_constructor :: ClassName -> Method
default_constructor cn = Method sig []
	where
		sig = Signature NonVirtual NonStatic NoType cn [] 

-- Setup Constructor for a class (constructor that inits all attributes)
setup_constructor :: ClassName -> [Variable] -> Method
setup_constructor cn vars = Method sig (map f vars)
	where
		sig = Signature NonVirtual NonStatic NoType cn (map (\x -> Parameter x "") vars)
		f :: Variable -> String
		f (Variable _ n) = "this->" ++ n ++ " = " ++ n ++ ";"

{-
	Add a call to init to the constructors of the class, if the class has an init method
-}
add_init :: CppClass -> CppClass
add_init (CppClass concrete name inh vars meth) = CppClass concrete name inh vars new_meth
	where
		has_init = not (null [name | (Method (Signature _ _ _ name _) _) <- meth, name == "init"])
		cs = [x | x <- meth, is_constructor x]
		others = [x | x <- meth, not (is_constructor x)] 
		new_cs = if has_init then map add_init_call cs else cs
		new_meth = new_cs ++ others
		is_constructor (Method (Signature _ _ t _ _) _) = case t of
			NoType -> True
			_ -> False
		add_init_call (Method signature body) = Method signature ("init();":body)
