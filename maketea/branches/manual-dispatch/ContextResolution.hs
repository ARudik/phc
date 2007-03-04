module ContextResolution where

import Control.Monad
import Data.List

import DataStructures
import GrammarAnalysis
import MakeTeaMonad

contextResolution :: MakeTeaMonad () 
contextResolution = do
	init <- withGrammar (concatMapM initContexts)
	let sorted = sortBy (\(a,b,c) (a',b',c') -> compare a a') init
	reduced <- reduce sorted
	setContexts reduced

{-
 - reduce does context resolution, reducing two contexts (i,t1,m1) and
 - (i,t2,m2) to a context (i,t,m), where t is the greatest lower bound
 - of t1 and t2 in the inheritance hierarchy, and m is the meet of m1
 - and m2, where the meet of two multiplicities is defined separately,
 - below.
 -}

reduce :: [Context] -> MakeTeaMonad [Context]
reduce [] = return []
reduce [c] = return [c]
reduce ((i1,t1,m1):(i2,t2,m2):cs)
	| i1 == i2 = do
		c <- resolve (i1,t1,m1) (i2,t2,m2)
		cs' <- reduce cs
		return (c:cs')
	| otherwise = do
		cs' <- reduce ((i2,t2,m2):cs)
		return ((i1,t1,m1) : cs')

resolve :: Context -> Context -> MakeTeaMonad Context
resolve (i,t1,m1) (_,t2,m2) = do
	(Just t) <- commonInstance t1 t2
	return (i,t,multMeet m1 m2)

{-
 - The meet m of two multiplicities is defined such that if we have two
 - contexts (i,t,m1) and (i,t,m2), m is the most permissive multiplicity
 - that is safe in a context where m1 is required and in a context where
 - m2 is required.
 -}

multMeet :: Multiplicity -> Multiplicity -> Multiplicity
multMeet m1 m2 | m1 == m2 = m1
multMeet Single _ = Single
multMeet Optional Vector = Single
multMeet Optional VectorOpt = Optional
multMeet Optional OptVector = Single
multMeet Vector VectorOpt = Vector
multMeet Vector OptVector = Vector
multMeet VectorOpt OptVector = Vector
multMeet m1 m2 = multMeet m2 m1 -- multMeet is commutative 

{-
 - initContexts traverses the grammar once. It skips all disjunctions,
 - but traverses the body of each conjunction h ::= ... ; for every term
 - (t,m) it finds in the body of the conjunction, it adds a context
 - (i,t,m), for every instance i of t (see GrammarAnalysis for a
 - definition of "instance of").
 -}

initContexts :: Rule -> MakeTeaMonad [Context]
initContexts (Disj _ _) = return []
initContexts (Conj h ts) = concatMapM f ts
	where
		f :: Term -> MakeTeaMonad [Context]
		f (_,t,m) = do 
		 	is <- allInstances t	
			return (map (\i -> (i,t,m)) is)
