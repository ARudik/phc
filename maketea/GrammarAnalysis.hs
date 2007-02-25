{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Various analyses of the grammar	
-}

module GrammarAnalysis where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import List

type InheritanceRel = [(ClassName,ClassName)] -- (subclass,superclass)

{-
	Work out the inheritance relation between all classes.
	Result is [(subclass,superclass)] 
-}
inheritance_relation :: Grammar -> InheritanceRel 
inheritance_relation [] = [] 
inheritance_relation ((Conjunction _ _):rest) = inheritance_relation rest
inheritance_relation ((Disjunction head body):rest) 
	= [(term_to_classname x, "AST_" ++ head) | x <- body] ++ (inheritance_relation rest)

{-
	Direct superclasses 
-}
direct_superclasses :: InheritanceRel -> ClassName -> [ClassName]
direct_superclasses ir classname = [y | (x,y) <- ir, x == classname]

{-
	Transitive/Reflexive closure of `direct_superclasses'
	The order of the classes in the result list is from most specific to least specific
-}
all_superclasses :: InheritanceRel -> ClassName -> [ClassName]
all_superclasses ir classname = nub (classname : (dsc ++ (concat (map (all_superclasses ir) dsc))))
	where
		dsc = direct_superclasses ir classname

{-
	Direct subclasses	
-}
direct_subclasses :: InheritanceRel -> ClassName -> [ClassName]
direct_subclasses ir classname = [x | (x,y) <- ir, y == classname]

{-
	Transitive/Reflexive closure of `direct_subclasses'
	The order of the classes in the result list is from least specific (i.e., the class itself)
	to most specific 
-}
all_subclasses :: InheritanceRel -> ClassName -> [ClassName]
all_subclasses ir classname = nub (classname : (dsc ++ (concat (map (all_subclasses ir) dsc))))
	where
		dsc = direct_subclasses ir classname

{-
	Find a least specific common subclass of two classes (if it exists)
-}

common_subclass :: InheritanceRel -> ClassName -> ClassName -> Maybe ClassName
common_subclass ir a b = case di of (x:_) -> Just x ; [] -> Nothing
	where
		da = all_subclasses ir a
		db = all_subclasses ir b
		di = list_intersection da db

{-
	The "top" of the class hierarchy
-}
superclass :: InheritanceRel -> ClassName
superclass ir = check_unique (foldr1 list_intersection (map (all_superclasses ir) cns))
	where
		cns = map fst ir 
		check_unique [x] = x
		check_unique all = error ("No unique superclass found " ++ show all)

{-
	Extract the list of all terminals from the grammar 
-}

terminal_list :: Grammar -> [Symbol]
terminal_list g = nub (concat (map extract_terminals g))
	where
		extract_terminals :: Rule -> [Symbol]
		extract_terminals (Disjunction _ body) = [x | (_, x, _) <- body, is_terminal x]
		extract_terminals (Conjunction _ body) = [x | (_, x, _) <- body, is_terminal x]
		is_terminal :: Symbol -> Bool
		is_terminal (Terminal _ _) = True
		is_terminal _ = False
		
{-
	Extract a list of classnames from a list of classes
-}

class_names :: [CppClass] -> [ClassName]
class_names cl = [cn | (CppClass _ cn _ _ _) <- cl]

{-
	Sort the list of classes topologically based on their inheritance
	relation (this is a stable sort). Classes that are inherited from but not
	defined anywhere, are assumed "outside" classes and are not taken into
	account in the ordering (i.e., if a class A inherits from a class B, but we
	have no definition of class B, class B is not required to be defined before class A).
-}

order_classes :: [CppClass] -> [CppClass]
order_classes classes = order_classes' outside_class_defs classes
	where
		outside_class_defs = [CppClass Concrete x [] [] [] | x <- outside_classes]
		outside_classes = list_diff all_inherited all_classes
		all_inherited = nub (concat [x | (CppClass _ _ x _ _) <- classes])
		all_classes = class_names classes

order_classes' :: [CppClass] -> [CppClass] -> [CppClass]
order_classes' _ [] = [] 
order_classes' visited to_visit = 
		if next == []
		then error $ "cyclic inheritance hierarchy:\n" ++ unlines (map errMsg to_visit) 
		else next ++ (order_classes' (visited ++ next) (list_diff to_visit next))
	where
		next = [c | c <- to_visit, parents_visited c]
		parents_visited :: CppClass -> Bool
		parents_visited (CppClass _ _ inh _ _) = sublist inh (class_names visited)
		errMsg (CppClass _ c inh _ _) = c ++ " inherits from " ++ show inh

{-
	Check whether a symbol is a marker
-}

is_marker :: Symbol -> Bool
is_marker (Marker _) = True
is_marker _ = False

{-
	"Extract" the classname from a terminal or nonterminal symbol
-}

symbol_to_classname :: Symbol -> String
symbol_to_classname (Terminal t _) = "Token_" ++ (tolower t)
symbol_to_classname (NonTerminal nt) = "AST_" ++ nt
symbol_to_classname (Marker _) = "bool"

term_to_classname :: Term -> String
term_to_classname (_, sym, mult) = (symbol_to_classname sym) ++ (if is_vector mult then "_list" else "")

{-
	Extract the variable name from a symbol (NOTE: ignores labels and multiplicity; see also
	term_to_var)
-}

symbol_to_varname :: Symbol -> String
symbol_to_varname (Terminal t _) = tolower t
symbol_to_varname (NonTerminal nt) = nt
symbol_to_varname (Marker m) = "is_" ++ m

{-
	Convert a classname to a variable name
	E.g., "AST_statement" changes to "statement"
	TODO: better way to do this?
-}

classname_to_varname :: ClassName -> VariableName
classname_to_varname = tail . snd . (break (== '_')) 

{-
	Extract the variable name from a term
-}

term_to_varname :: Term -> String
term_to_varname (label, symbol, mult) = case label of
		Label l -> l
		NoLabel -> opt_plural (symbol_to_varname symbol)
	where
		opt_plural s = if is_vector mult then s ++ "s" else s

{-
	True for vectors, False for singletons
-}

is_vector :: Multiplicity -> Bool
is_vector Single = False
is_vector Vector = True
is_vector Optional = False
is_vector OptVector = True
is_vector VectorOpt = True

{-
	Find all instances (concrete and abstract) of a symbol
-}

find_instances :: Grammar -> Symbol -> [Term]
find_instances gr s = find_instances' gr gr s

find_instances' :: Grammar -> Grammar -> Symbol -> [Term]
find_instances' gr ((Conjunction _ _):rest) sym 
	= find_instances' gr rest sym
find_instances' gr ((Disjunction nt rhs):rest) (NonTerminal sym) | nt == sym 
	= foldr (++) [] (map f rhs)
	where
		f :: Term -> [Term]
		f t@(_, x, mult) = if is_concrete gr x || is_vector mult then [t] else (t:find_instances gr x)
find_instances' gr (_:rest) sym 
	= find_instances' gr rest sym

{-
	Find all concrete instances of a symbol
-}

find_concrete_instances :: Grammar -> Symbol -> [Term]
find_concrete_instances gr s = find_concrete_instances' gr gr s

find_concrete_instances' :: Grammar -> Grammar -> Symbol -> [Term]
find_concrete_instances' gr ((Conjunction _ _):rest) sym 
	= find_concrete_instances' gr rest sym
find_concrete_instances' gr ((Disjunction nt rhs):rest) (NonTerminal sym) | nt == sym 
	= foldr (++) [] (map f rhs)
	where
		f :: Term -> [Term]
		f t@(_, x, mult) = if is_concrete gr x || is_vector mult then [t] else find_concrete_instances gr x
find_concrete_instances' gr (_:rest) sym 
	= find_concrete_instances' gr rest sym

{-
	Check whether a non-terminal corresponds to a concrete class
-}

is_concrete :: Grammar -> Symbol -> Bool
is_concrete [] sym = error ("is_concrete: unknown symbol " ++ show sym)
is_concrete _ (Terminal _ _) = True
is_concrete ((Conjunction nt _):rest) (NonTerminal nt') | nt == nt' = True
is_concrete ((Disjunction nt _):rest) (NonTerminal nt') | nt == nt' = False
is_concrete (_:rest) sym = is_concrete rest sym

{-
	Check whether a non-terminal corresponds to an abstract class
-}

is_abstract :: Grammar -> Symbol -> Bool
is_abstract gr = not . is_concrete gr

{-
	Check whether a symbol is optional
-}

is_optional :: Multiplicity -> Bool
is_optional Single = False
is_optional Vector = False
is_optional Optional = True
is_optional OptVector = True
is_optional VectorOpt = False

{-
	The meet of two classes is defined in the usual way, based on the inheritance relation
	Of course, the meet of two classes is not guaranteed to exist
-}

inh_meet :: ClassName -> ClassName -> InheritanceRel -> Maybe ClassName
inh_meet a b inh = 
	if elem a (all_superclasses inh b) then 
		Just b 
	else if elem b (all_superclasses inh a) then
		Just a
	else
		Nothing

