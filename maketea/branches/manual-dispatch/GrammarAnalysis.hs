module GrammarAnalysis where

import Data.List
import Data.Maybe

import DataStructures
import MakeTeaMonad
import Util

{-
 - isAbstract nt is true if nt is defined by a disjunction
 -}

isAbstract :: Name NonTerminal -> MakeTeaMonad Bool
isAbstract nt = do
	r <- findRuleFor nt
	return (elim isDisj r)

{-
 - Is a rule a disjunction?
 -}

isDisj :: Rule a -> Bool
isDisj (Disj _ _) = True
isDisj (Conj _ _) = False 

{-
 - findRuleFor nt finds the rule in the grammar that defines nt
 -}

findRuleFor :: Name NonTerminal -> MakeTeaMonad (Some Rule)
findRuleFor nt = withGrammar $ (fromJustM $ "Unknown non-terminal " ++ nt) . find (elim f)
	where
		f :: Rule a -> Bool
		f r = ruleHead r == nt 

{-
 - The instances of a symbol s always includes s itself. For abstract symbols
 - defined by a disjunction x1 .. xn, the instances of s also include all
 - instances of the xs. The instances will be returned in order from general to
 - more specific (that is, if t is an instance of t', t' will be reported
 - before t).
 -}

allInstances :: Symbol a -> MakeTeaMonad [Some Symbol]
allInstances i@(NonTerminal nt) = 
	do
		r <- findRuleFor nt
		elim f r	
	where
		f :: Rule a -> MakeTeaMonad [Some Symbol]
		f (Disj _ xs) = do
			is <- mapM (elim allInstances) xs
			return (Exists i:concat is)
		f (Conj _ _) = return [Exists i]
allInstances i@(Terminal _ _) = return [Exists i]

{-
 - Like allInstances, but filtered to include the concrete instances only
 -}

concreteInstances :: Symbol a -> MakeTeaMonad [Some Symbol]
concreteInstances i@(NonTerminal nt) = 
	do
		r <- findRuleFor nt
		elim f r	
	where
		f :: Rule a -> MakeTeaMonad [Some Symbol]
		f (Disj _ xs) = do
			is <- mapM (elim concreteInstances) xs
			return (concat is)
		f (Conj _ _) = return [Exists i]

{-
 - commonInstance finds the most general common instance of two symbols, if it
 - exists.
 -}

commonInstance :: Symbol a -> Symbol b -> MakeTeaMonad (Maybe (Some Symbol))
commonInstance s1 s2 = do
	is1 <- allInstances s1
	is2 <- allInstances s2
	return (find (`elem` is2) is1)

{-
 - The direct superclasses of a symbol c are all those symbols s which are
 - defined by a rule s ::= ... | c | ...
 -}

directSuperclasses :: Some Symbol -> MakeTeaMonad [Name NonTerminal]
directSuperclasses c = withDisj $ return . catMaybes . (map f)
	where
		f :: Rule Disj -> Maybe (Name NonTerminal)
		f (Disj s cs) = if c `elem` cs then Just s else Nothing

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
 - TODO: add terminal symbols
 -}

concreteSymbols :: MakeTeaMonad [Some Symbol]
concreteSymbols = withConj $ return . (map (Exists . NonTerminal . ruleHead))

{-
 - All abstract symbols (that is, non-terminal sysbols that are defined as a
 - disjunction)
 -}

abstractSymbols :: MakeTeaMonad [Name NonTerminal]
abstractSymbols = withDisj $ return . (map ruleHead)

{-
 - The head/body of a rule
 -}

ruleHead :: Rule a -> Name NonTerminal
ruleHead (Disj h _) = h
ruleHead (Conj h _) = h

