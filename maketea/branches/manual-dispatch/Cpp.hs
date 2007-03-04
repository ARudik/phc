module Cpp where

import Text.PrettyPrint
import DataStructures

emptyClass :: Name -> CppClass 
emptyClass n = CppClass {
	  name = n
	, extends = []
	, sections = []
	}

symbolToClassName :: Symbol -> Name
symbolToClassName (NT nt) = "AST_" ++ nt

symbolToVarName :: Symbol -> Name
symbolToVarName (NT nt) = nt

{-
 - Pretty-printing
 -}

instance Show CppClass where
	show = render . docClass

docClass :: CppClass -> Doc
docClass c = 
	text "class" <+> text (name c) <> docExtends (extends c) $+$
	text "{" $+$ vcat (map docSection (sections c)) $+$ text "};" $+$ text ""

docSection :: Section -> Doc
docSection (Section _ []) = empty
docSection (Section m ms) = docAccess m <> colon $+$ nest 4 (vcat (map docMember ms))

docAccess :: Access -> Doc
docAccess Private = text "private"
docAccess Protected = text "protected"
docAccess Public = text "public"

docMember :: Member -> Doc
docMember (Attribute a) = text a <> semi
docMember (Method sig body) = docSignature sig $+$ text "{" $+$ nest 4 (docBody body) $+$ text "}"

docSignature :: Signature -> Doc
docSignature = text

docBody :: Body -> Doc
docBody = vcat . map text

docExtends :: [Name] -> Doc
docExtends [] = empty
docExtends cs = text " : " <> (commaSep $ map (\c -> text "virtual public" <+> text c) cs)

commaSep = hsep . punctuate comma
