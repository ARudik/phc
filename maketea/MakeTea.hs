{-
 	phc -- the open source PHP compiler
	See license/readme.license for licensing information

	Main module 
-}

module MakeTea where

import List
import MakeTeaParser 
import MakeTeaLib
import MakeTeaCpp
import GrammarAnalysis 
import SkeletonClasses
import Constructors
import CloneMethods
import TreeTransform
import TreeVisitor
import Contexts
import ListClasses
import PatternMatching
import DeepEquality
import Schema
import FactoryMethod

{-
	process_grammar is invoked from Main.
	
	When process_grammar is called, it is passed the command line arguments,
	the grammar (i.e., [Rule]), and a list of the partial classes that have
	been specified in the grammar file.

	"inheritance_relation" uses the grammar to figure out which classes
	should inherit from which other classes

	"skeleton_classes" uses the grammar and the inheritance relation to
	create skeleton classes; the skeleton classes define their superclasses
	and the definitions for the variables, but do not contain any methods.

	"list_classes" generates specialised list classes for all non-terminals in
	the grammar

	"superclass" finds the class that all other classes in the AST hierarchy
	inherit from; this is used for the return type of, and the argument to, the
	clone methods. If no single unique superclass is found, the program aborts.

	"add_constructors" then adds constructors to these classes; a default
	constructor with no arguments and an empty body, and a setup constructor
	with an argument for each variable in the class.

	"add_transform_calls" adds the "transform", "pre_transform",
	"transform_children" and "post_transform" methods to the classes. The
	implementation of these methods is relatively straightforward, and consists
	mainly of calls to a TreeTransform object (the TreeTransform class itself is
	generated separately)

	"add_visitor_calls" does a similar thing for the TreeVisitor API 

	"add_match_pattern" then adds a pattern match method to each class; note
	that we run this before "merge_class", so that the variables added by mixin
	classes does get get compared

	"map merge_class" then merges these skeleton classes with the partial
	classes from the grammar definition

	"add_init" adds a call to "init" to the constructors, if the class
	defines an init method (which must have come from the partial class).
	Note that we cannot add constructors after merging, because the setup
	constructor should not get arguments for any extra variables the partial
	class might add.

	"add_clone_method" then adds a clone method to each class, based on the
	list of variables (note that because we call this function after
	"map merge_class", this list now includes the variables from the merged in
	partial classes)

	"wildcard" adds the wildcard class used for pattern matching

	Finally, "order_classes" then orders the classes so that if class B
	inherits from class A, A will be defined before class A.

	We then output the class declarations to "ash.h", and the class
	definitions to "ast.cpp"; the contents of these files are generated by
	"ast_h" and "ast_cpp", respectively.
-}
process_grammar :: [String] -> Grammar -> [Include] -> [CppClass] -> IO ()
process_grammar args grammar includes partial_classes =
	do
		-- Basic analyses of the grammar
		let ih = inheritance_relation grammar
		let (cx, rejected) = contexts grammar ih 
		-- Construct the AST classes bit by bit as described above
		let sk = skeleton_classes ih grammar
		let ac = map add_constructors sk
		let tc = map (add_transform_calls cx) ac
		let vc = map (add_visitor_calls ih) tc
		let lc = (list_classes grammar ih) ++ vc 
		let pm = map (add_match_method (Type "Object*")) lc 
		let mc = map (merge_class partial_classes) pm 
		let cm = map (add_clone_method (Type "Object*")) mc
		let de = map (add_deep_equals_method (Type "Object*")) cm
		let ai = map add_init de 
		let wc = (wildcard (Type "Object*") (class_names ai)) : ai
		let fm = (factory_method grammar ih (Type "Object*"):wc)
		let oc = order_classes fm
		-- Construct the Tree_transform and Tree_visitor classes
		let tr = transform_class grammar cx
		let vi = visitor_class grammar 
		-- Construct an XML Schema representation of the grammar
		let xs = xml_schema grammar
		-- Generate code
		writeFile "ast.h" (ast_h oc includes)
		writeFile "ast.cpp" (ast_cpp oc)
		writeFile "Tree_transform.h" (transform_h tr includes)
		writeFile "Tree_transform.cpp" (transform_cpp tr)
		writeFile "Tree_visitor.h" (visitor_h vi includes)
		writeFile "Tree_visitor.cpp" (visitor_cpp vi)
		writeFile "README.TreeTransform" (readme_TreeTransform cx rejected)
		writeFile "schema.xsd" xs

readme_TreeTransform :: [Context] -> [Context] -> String
readme_TreeTransform accepted rejected =
	"The following contexts have been accepted:\n\n" ++
	(ppifix "" "" "\n" (map show accepted)) ++
	"\n\nThe following contexts have been rejected:\n\n" ++ 
	(ppifix "" "" "\n" (map show rejected)) 

{-
	Find the corresponding class in the list of partial classes (if any), and
	merge in the list of superclasses, variables and methods.
-}
merge_class :: [CppClass] -> CppClass -> CppClass
merge_class partial_classes cl 
	| matches == [] = cl
	| otherwise = merge_class' cl (head matches) 
	where
		matches = [c | c <- partial_classes, c == cl]
		merge_class' (CppClass concr1 nm1 inh1 vars1 meth1) (CppClass concr2 nm2 inh2 vars2 meth2) =
			CppClass (orc concr1 concr2) nm1 (inh1 ++ inh2) (vars1 ++ vars2) (meth1 ++ meth2)
		orc Abstract _ = Abstract
		orc _ x = x
