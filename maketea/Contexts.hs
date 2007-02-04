{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Calculate the contexts for all symbols in the grammar	

	WHAT ARE CONTEXTS

	A context is essentially a use of a symbol somewhere in a (concrete) rule in
	the grammar.  There are four possibilities. Consider:

	concrete1 ::= ... 
	concrete2 ::= ...
	concrete3 ::= ...
	concrete4 ::= ...
	concrete5 ::= ...
	concrete6 ::= ...
	abstract1 ::= concrete3 | concrete4
	abstract2 ::= concrete5 | concrete6

	some_concrete_rule ::= concrete1 concrete2* abstract1 abstract2* 

	then, based on the rule "some_concrete_rule", concrete1 occurs in the
	context (concrete1,concrete1,Single) - i.e., as a single instance of itself,
	concrete2 occurs in the context (concrete2,concrete2,Vector), i.e.  as a
	vector of instances of itself. The use of the abstract1 class leads to a
	number of contexts:

	  (abstract1,abstract1,Single)
	  (concrete3,abstract1,Single)
	  (concrete4,abstract1,Single)
	
	And finally, the use of abstract2* yields to the contexts 

	  (abstract2,abstract2,Vector)
	  (concrete5,abstract2,Vector)
	  (concrete6,abstract2,Vector)

	These contexts essentially mean that an instance of concrete5 can be
	replaced by any number of any (concrete) instance of "abstract2".

	REDUCING CONTEXTS

	If there are two or more conflicting contexts for a single symbol, we must
	resolve the contexts to their most specific (restrictive) form.  For
	instance, for the phc grammar, this yields

		(if,statement,Vector)
		(CLASS_NAME,CLASS_NAME,Single)
			(due to contexts CLASS_NAME -> target, CLASS_NAME -> class_name) 
		(INTERFACE_NAME,INTERFACE_NAME,Single)
			(due to contexts INTERFACE_NAME -> INTERFACE_NAME, INTERFACE_NAME -> INTERFACE_NAME*)

	When reducing contexts (a,b,c) (a',b',c'), we take the meet of b and b', and
	opt for the most restrictive Multiplicity (Single over Optional, Single over
	Vector, etc.).

	To see the reason for taking the meet, consider this fragment of the phc grammar:
	
	expr ::= ... | BOOL
	cast ::= CAST expr
	method_invocation ::= target ...
	target ::= expr | CLASS_NAME
	
	The use of "expr" in the rule for cast leads to the context
	(BOOL,expr,Single) The use of "target" in the rule for method_invocation
	leads to the context (BOOL,target,Single)
	
	By taking the meet of "expr" and "target", this gives the context
	(BOOL,expr,Single)
	
	In the case of CLASS_NAME, we have the contexts
	
	  (CLASS_NAME,class_name,Single)
	  (CLASS_NAME,target,Single)
	
	The meet of class_name and target does not exist; hence this gives the
	context
	
	  (CLASS_NAME,CLASS_NAME,Single)
-}

module Contexts where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import GrammarAnalysis
import List
import Debug.Trace

type Context = (ClassName,ClassName,Multiplicity) 	-- As explained above

-- First element of the result is the list of reduced contexts, 
-- the second is the list of rejected contexts
contexts :: Grammar -> InheritanceRel -> ([Context], [Context])
contexts gr ih = (with_missing, rejected)
	where
		all = all_contexts gr gr
		sorted = nub (sortBy f all)
		reduced = reduce_contexts ih sorted 
		with_missing = add_missing_contexts gr reduced 
		rejected = list_diff sorted with_missing 
		f (sym,_,_) (sym',_,_) = compare sym sym'

-- Reduce the contexts (assumes conflicting contexts are in consecutive
-- locations in the list)
reduce_contexts :: InheritanceRel -> [Context] -> [Context] 
reduce_contexts ih [] = []
reduce_contexts ih ((sym,ctxt,mult):(sym',ctxt',mult'):tail) | sym == sym' 
	= reduce_contexts ih ((reduce_context ih (sym,ctxt,mult) (sym',ctxt',mult')):tail)
reduce_contexts ih (a:tail) = (a:reduce_contexts ih tail)

-- Reduce two contexts (a,b,mult) and (a',b',mult'), assuming a == a'
reduce_context :: InheritanceRel -> Context -> Context -> Context
reduce_context ih (a,b,mult) (a',b',mult') = (a, meet, meet_mult mult mult')
	where
		sub = common_subclass ih b b' 
		meet = case sub of 
			Just cn -> cn 
			Nothing -> error ("internal error: " ++ show b ++ " and " ++ show b' ++ " don't have a common subclass")

meet_mult :: Multiplicity -> Multiplicity -> Multiplicity
meet_mult a b | a == b = a
meet_mult Single _ = Single  
meet_mult Vector Optional = Single 
meet_mult Vector OptVector = Vector
meet_mult Vector VectorOpt = Vector
meet_mult Optional OptVector = Single
meet_mult Optional VectorOpt = Optional
meet_mult OptVector VectorOpt = Vector
meet_mult a b = meet_mult b a  -- meet is commutative

-- Find all contexts for non-terminals used in the RHS of productions
all_contexts :: Grammar -> Grammar -> [Context]
all_contexts gr [] = []
all_contexts gr ((Disjunction _ _):rest) = all_contexts gr rest
all_contexts gr ((Conjunction _ rhs):rest) = (concatMap f rhs) ++ (all_contexts gr rest)
	where
		f :: Term -> [Context]
		f ctxt@(label, sym, mult) =
			if is_marker sym then
				[]
			else if is_concrete gr sym then
				[(symbol_to_classname sym, symbol_to_classname sym,mult)]
			else 
				(symbol_to_classname sym, symbol_to_classname sym,mult):
				[(term_to_classname concrete, symbol_to_classname sym,mult) | concrete <- find_instances gr sym]

-- Add contexts for classes whose context is not already known (i.e., who are only
-- used on the LHS of productions). We add contexts for disjunctions as well as 
-- conjunctions, because we must be able to give the corresponding pre_ and post_ transform
-- methods an appropriate (covariant) return type.
add_missing_contexts :: Grammar -> [Context] -> [Context]
add_missing_contexts [] ctxts = ctxts
add_missing_contexts ((Disjunction lhs rhs):tail) ctxts
		= add_missing_contexts tail (ctxt:ctxts')
	where
		(old_ctxt, ctxts') = let c = partition (\(cn,_,_) -> cn == "AST_" ++ lhs) ctxts in (fst c, snd c)
		rhs_ctxts :: [Context]
		rhs_ctxts = map (\x -> find_context (term_to_classname x) ctxts) rhs
		vs :: [Bool]
		vs = map (\(_, _, mult) -> is_vector mult) rhs_ctxts
		ctxt =
			-- TODO: Is this a correct solution?
			if null old_ctxt then
				("AST_" ++ lhs, "AST_" ++ lhs, Single) 
			else 
				let 
					(a,b,mult) = head old_ctxt
				in
					if and (is_vector mult:vs) then
						(a, b, Vector)
					else if not (or vs) then
						(a, b, Single)
					else
						error ("Error: cannot deal with mixed multiplicity in rule for " ++ show lhs)

add_missing_contexts ((Conjunction lhs _):tail) ctxts 
		= add_missing_contexts tail (ctxt ++ ctxts) 
	where
		ctxt = case [c | c@(sym, _, _) <- ctxts, "AST_" ++ lhs == sym] of
			[] -> [("AST_" ++ lhs,"AST_" ++ lhs,Single)]
			_ -> []

-- Find context finds a context (a,a',mult) for a classname a
-- find_context will fail if the context could not be found
find_context :: ClassName -> [Context] -> Context
find_context a [] = error ("No context found for " ++ a)
find_context a ((a',b,c):_) | a == a' = (a,b,c) 
find_context a (_:tail) = find_context a tail 
