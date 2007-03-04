module Cpp where

import Text.PrettyPrint
import Data.Maybe
import Data.List

import DataStructures
import MakeTeaMonad
import GrammarAnalysis

emptyClass :: Name -> MakeTeaMonad CppClass 
emptyClass n = do
	cid <- getNextClassID
	let getID = Method ("int", "classid", []) ["return " ++ show cid ++ ";"]
	return $ CppClass {
		  name = n
		, extends = []
		, sections = [Section Private [getID]]
		, classid = cid
		, friends = []
		}

emptyAbstractClass :: Name -> CppClass
emptyAbstractClass n = CppClass {
		  name = n
		, extends = []
		, sections = [Section Private [getID]]
		, classid = 0
		, friends = []
		}
	where
		getID = PureVirtual ("int", "classid", [])

emptyClassNoID :: Name -> CppClass
emptyClassNoID n = CppClass {
		  name = n
		, extends = []
		, sections = []
		, classid = 0
		, friends = []
		}

findClassID :: Symbol -> MakeTeaMonad Integer
findClassID s = withClasses $ \classes -> do
	cn <- symbolToClassName s
	let (Just cl) = find (\c -> name c == cn) classes
	return (classid cl) 

symbolToClassName :: Symbol -> MakeTeaMonad Name
symbolToClassName (NT nt) = withPrefix $ return . (++ nt)

symbolToVarName :: Symbol -> Name
symbolToVarName (NT nt) = nt

termToType :: Term -> MakeTeaMonad String
termToType (_,s,m) = do
	cn <- symbolToClassName s
	if isVector m 
		then return ("list<" ++ cn ++ "*>")
		else return cn

termToVarName :: Term -> Name
termToVarName (Nothing,s,m) 
	| isVector m = symbolToVarName s ++ "s" 
	| otherwise = symbolToVarName s
termToVarName (Just n,s,m) = n

{-
 - Pretty-printing
 -}

showClassHeader :: CppClass -> String
showClassHeader c = render $
	text "class" <+> text (name c) <> docExtends (extends c) $+$
	text "{" $+$ vcat (map docSectionHeader (sections c)) $+$ vcat (map docFriend (friends c)) $+$ text "};" $+$ text ""
	
docExtends :: [Name] -> Doc
docExtends [] = empty
docExtends cs = text " : " <> (commaSep $ map (\c -> text "virtual public" <+> text c) cs)

docSectionHeader :: Section -> Doc
docSectionHeader (Section _ []) = empty
docSectionHeader (Section m ms) = docAccess m <> colon $+$ nest 4 (vcat (map docMemberSignature ms))

docMemberSignature :: Member -> Doc
docMemberSignature (Attribute a) = text a <> semi
docMemberSignature (Method sig body) = docSig Nothing sig <> semi
docMemberSignature (PureVirtual sig) = text "virtual" <+> docSig Nothing sig <+> text "= 0;"

docAccess :: Access -> Doc
docAccess Private = text "private"
docAccess Protected = text "protected"
docAccess Public = text "public"

docFriend :: Name -> Doc
docFriend n = text "friend class" <+> text n <> semi 

showClassImplementation :: CppClass -> String
showClassImplementation c = render . vcat $ map f (sections c)
	where
		f :: Section -> Doc
		f (Section _ ms) = vcat $ map (docMethod (name c)) ms

docMethod :: Name -> Member -> Doc
docMethod cn (Method sig body) = docSig (Just cn) sig $+$ text "{" $+$ nest 4 (docBody body) $+$ text "}" $+$ text ""
docMethod cn _ = empty 

docSig :: Maybe Name -> Sig -> Doc
docSig Nothing (ret, name, args) = text ret <+> text name <> parens (commaSep (map text args))
docSig (Just cn) (ret, name, args) = text ret <+> text (cn ++ "::" ++ name) <> parens (commaSep (map text args))

docBody :: Body -> Doc
docBody = vcat . map text

commaSep = hsep . punctuate comma
