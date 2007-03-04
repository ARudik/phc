module Cpp where

import DataStructures

instance Show CppClass where
	show (CppClass name) = "class " ++ name ++ " {};"

symbolToClassname :: Symbol -> Name
symbolToClassname (NT nt) = "AST_" ++ nt
