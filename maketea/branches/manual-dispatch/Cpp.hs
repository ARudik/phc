module Cpp where

import Text.PrettyPrint
import DataStructures

emptyClass :: Name -> CppClass 
emptyClass n = CppClass {
	  name = n
	, extends = []
	}

symbolToClassname :: Symbol -> Name
symbolToClassname (NT nt) = "AST_" ++ nt

{-
 - Pretty-printing
 -}

instance Show CppClass where
	show = render . docClass

docClass :: CppClass -> Doc
docClass c = text "class" <+> text (name c) <> docExtends (extends c) $+$ braces empty <> semi

docExtends :: [Name] -> Doc
docExtends [] = empty
docExtends cs = text " : " <> (commaSep $ map (\c -> text "virtual public" <+> text c) cs)

commaSep = hsep . punctuate comma
