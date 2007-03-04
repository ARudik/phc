module Cpp where

import Text.PrettyPrint
import DataStructures
import MakeTeaMonad
import GrammarAnalysis

emptyClass :: Name -> MakeTeaMonad CppClass 
emptyClass n = do
	cid <- getNextClassID
	let getID = Method "int classid()" ["return " ++ show cid ++ ";"]
	return $ CppClass {
		  name = n
		, extends = []
		, sections = [Section Public [getID]]
		, classid = cid
		}

emptyAbstractClass :: Name -> CppClass
emptyAbstractClass n = CppClass {
		  name = n
		, extends = []
		, sections = [Section Public [getID]]
		, classid = 0
		}
	where
		getID = VirtualMethod "int classid() = 0"

emptyClassNoID :: Name -> CppClass
emptyClassNoID n = CppClass {
		  name = n
		, extends = []
		, sections = []
		, classid = 0
		}

symbolToClassName :: Symbol -> Name
symbolToClassName (NT nt) = "AST_" ++ nt

symbolToVarName :: Symbol -> Name
symbolToVarName (NT nt) = nt

termToType :: Term -> String
termToType (l,s,m) 
	| isVector m = "list<" ++ symbolToClassName s ++ "*>*"
	| otherwise = symbolToClassName s ++ "*"

termToVarName :: Term -> Name
termToVarName (Nothing,s,m) 
	| isVector m = symbolToVarName s ++ "s" 
	| otherwise = symbolToVarName s
termToVarName (Just n,s,m) = n

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
docMember (Method sig body) = docSig sig $+$ text "{" $+$ nest 4 (docBody body) $+$ text "}"
docMember (VirtualMethod sig) = text "virtual" <+> docSig sig <> semi 

docSig :: Sig -> Doc
docSig = text

docBody :: Body -> Doc
docBody = vcat . map text

docExtends :: [Name] -> Doc
docExtends [] = empty
docExtends cs = text " : " <> (commaSep $ map (\c -> text "virtual public" <+> text c) cs)

commaSep = hsep . punctuate comma
