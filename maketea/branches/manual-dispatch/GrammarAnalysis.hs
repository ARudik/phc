module GrammarAnalysis where

import Data.List
import Data.Maybe

import DataStructures
import MakeTeaMonad

{-
 - isAbstract nt is true if nt is defined by a disjunction
 -}

isAbstract :: NonTerminal -> MakeTeaMonad Bool
isAbstract nt = do
	r <- findRuleFor nt
	return (case r of
		Disj _ _ -> True
		Conj _ _ -> False)

{-
 - findRuleFor nt finds the rule in the grammar that defines nt
 -}

findRuleFor :: NonTerminal -> MakeTeaMonad Rule
findRuleFor nt = withGrammar f
	where
		f [] = fail $ "Unknown non-terminal " ++ show nt
		f (r@(Disj nt' _):rs) 
			| nt == nt' = return r 
			| otherwise = f rs
		f (r@(Conj nt' _):rs)
			| nt == nt' = return r
			| otherwise = f rs

{-
 - The instances of a symbol s always includes s itself. For abstract symbols
 - defined by a disjunction x1 .. xn, the instances of s also include all
 - instances of the xs. The instances will be returned in order from general to
 - more specific (that is, if t is an instance of t', t' will be reported
 - before t).
 -}

allInstances :: Symbol -> MakeTeaMonad [Symbol]
allInstances i@(NT nt) = do
	r <- findRuleFor nt
	case r of
		Conj _ _ -> do
			return [i]
		Disj _ xs -> do
			is <- mapM allInstances xs
			return (i:concat is)

{-
 - commonInstance finds the most general common instance of two symbols, if it
 - exists.
 -}

commonInstance :: Symbol -> Symbol -> MakeTeaMonad (Maybe Symbol)
commonInstance s1 s2 = do
	is1 <- allInstances s1
	is2 <- allInstances s2
	return (find (`elem` is2) is1)

{-
 - The direct superclasses of a symbol c are all those symbols s which are
 - defined by a rule s ::= ... | c | ...
 -}

directSuperclasses :: Symbol -> MakeTeaMonad [NonTerminal]
directSuperclasses c = withGrammar $ return . catMaybes . (map f)
	where
		f :: Rule -> Maybe NonTerminal 
		f (Disj s cs) = if c `elem` cs then Just s else Nothing
		f (Conj _ _)  = Nothing

{-
 - isVector is true for Vector, VectorOpt and OptVector
 -}

isVector :: Multiplicity -> Bool
isVector Single = False
isVector Optional = False
isVector Vector = True
isVector VectorOpt = True
isVector OptVector = True

{-
 - All concrete symbols (that is, non-terminal symbols that are defined as a
 - conjunction, and terminal symbols) in the grammar
 -}

concreteSymbols :: MakeTeaMonad [Symbol]
concreteSymbols = withGrammar $ return . catMaybes . (map f)
	where
		f :: Rule -> Maybe Symbol
		f (Disj _ _) = Nothing
		f (Conj c _) = Just (NT c)
