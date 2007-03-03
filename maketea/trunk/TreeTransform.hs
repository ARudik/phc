{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Construct the TreeTransform class, and add the pre_transform, transform_children,
	post_transform and transform methods to the AST classes
-}

module TreeTransform where

import MakeTeaParser
import MakeTeaCpp
import MakeTeaLib
import List 
import GrammarAnalysis
import Contexts
import ListClasses

{-
	Add calls to the TreeTransform API
-}
add_transform_calls :: [Context] -> CppClass -> CppClass
add_transform_calls ctxts (CppClass concr name inh vars meth) = CppClass concr name inh vars new_meth
	where
		new_meth = meth ++ case concr of 
			Abstract -> 
				[
				 Method (Signature PureVirtual NonStatic rt "transform" [inp]) [], 
				 Method (Signature PureVirtual NonStatic rt "pre_transform" [inp]) [],
				 Method (Signature PureVirtual NonStatic Void "transform_children" [inp]) [],
				 Method (Signature PureVirtual NonStatic rt "post_transform" [inp]) [] 
				]
			Concrete -> 
				[
				 transform rt context, 
				 pre_post_transform "pre_" rt context,
				 transform_children cn,
				 pre_post_transform "post_" rt context
				] 
		context@(sym, ctxt, mult) = find_context name ctxts
		rt = Type (ctxt ++ (if is_vector mult then "_list*" else "*"))
		cn = snd (split '_' name)
		inp =	Parameter (Variable (Type "Tree_transform*") "transform") ""

-- transform calls pre_transform, transform_children and post_transform in turn
transform :: Type -> Context -> Method
transform rt (sym, ctxt, mult) = Method sig body 
	where
		sig = Signature Virtual NonStatic rt "transform" [inp]
		inp =	Parameter (Variable ttp "transform") ""
		ttp = Type "Tree_transform*"
		body =
				[
				 t ++ "* node = pre_transform(transform);"
				] ++
				if is_vector mult then
				[
				 t ++ "::const_iterator i;",
				 t ++ "* new_v = new " ++ t ++";",
				 "for(i = node->begin(); i != node->end(); i++)",
				 "{",
				 "\tif(*i)",
				 "\t{",
				 "\t\t(*i)->transform_children(transform);",
				 "\t\t" ++ t ++ "* ret_v = (*i)->post_transform(transform);",
				 "\t\tnew_v->push_back_all(ret_v);",
				 "\t}",
				 "\telse",
				 "\t{",
				 "\t\tnew_v->push_back(NULL);",
				 "\t}",
				 "}",
				 "return new_v;"
				]
				else
				[
				 "node->transform_children(transform);",
				 "return node->post_transform(transform);"
				]
		t = ctxt ++ (if is_vector mult then "_list" else "")

-- prefix should be either "pre_" or "post_"
pre_post_transform :: String -> Type -> Context -> Method
pre_post_transform prefix rt (sym, ctxt, mult) = Method sig body
	where
		sig = Signature Virtual NonStatic rt (prefix ++ "transform") [inp]
		inp = Parameter (Variable ttp "transform") ""
		ttp = Type "Tree_transform*"
		body = 
			if is_vector mult then
				[
				 ctxt ++ "_list* new_v = new " ++ ctxt ++ "_list;",
				 "transform->" ++ prefix ++ classname_to_varname sym ++ "(this, new_v);",
				 "return new_v;"
				]
			else
				["return transform->" ++ prefix ++ classname_to_varname sym ++ "(this);"]

transform_children :: ClassName -> Method
transform_children cn = Method sig body
	where
		sig = Signature Virtual NonStatic Void "transform_children" [inp]
		inp = Parameter (Variable ttp "transform") ""
		ttp = Type "Tree_transform*"
		body = ["transform->children_" ++ cn ++ "(this);"]

{-
	Contents of the C files
-}

transform_h :: CppClass -> [Include] -> String
transform_h cl includes = maketea_header ++ prefix ++ body ++ postfix
	where
		body = show_class_signature cl
		prefix = ppifix "" "\n" "" $
			[
			 "#ifndef _TRANSFORM_H_",
			 "#define _TRANSFORM_H_",
			 "",
			 "#include \"ast.h\""
			] ++ (map ("#include " ++) includes) ++
			[
			 ""
			] 	
		postfix = "\n#endif // _TRANSFORM_H_\n"
		
transform_cpp :: CppClass -> String
transform_cpp cl = maketea_header ++ "#include \"Tree_transform.h\"\n\n" ++ body
	where
		body = show_class_methods cl

{-
	Construct the TreeTransform class	
-}

transform_class :: Grammar -> [Context] -> CppClass 
transform_class gr ctxts = CppClass Concrete "Tree_transform" [] [] ([destructor] ++ pp ++ ch ++ tc ++ lt) 
	where
		pp = pre_post_methods gr ctxts
		ch = default_transform_children gr ctxts 
		tc = token_children (terminal_list gr)
		lt = list_transform_methods gr ctxts
		destructor = Method (Signature Virtual NonStatic NoType "~Tree_transform" []) [] 
{-
	The pre_transform and post_transform methods
-}

pre_post_methods :: Grammar -> [Context] -> [Method]
pre_post_methods gr [] = []
pre_post_methods gr ((fr,to,mult):tail) 
	-- TODO: This is a bit of a hack. We should only generate pre and post
	-- methods for concrete classes, but the context records the classname, 
	-- not the non-terminal name, whereas is_concrete expects the symbol name
	-- (non-terminal name). So, we check if the name starts with "AST_", and
	-- if it does, we use classname_t_varname to remove the AST_ part, convert
	-- it back to a non-terminal symbol, and then apply is_concrete (if the
	-- prefix is not "AST_", it must be "Token_", and must be concrete by
	-- definition).
	| take 4 fr /= "AST_" || is_concrete gr (NonTerminal (classname_to_varname fr)) 
		= (pre:post:pre_post_methods gr tail)
	| otherwise
		= pre_post_methods gr tail
	where
		pre = Method (sig "pre_") body 
		post = Method (sig "post_") body
		sig prefix = 
			if is_vector mult then
				Signature Virtual NonStatic Void (prefix ++ (classname_to_varname fr)) [inp, outp]
			else
				Signature Virtual NonStatic ret (prefix ++ (classname_to_varname fr)) [inp]
		body =
			if is_vector mult then
				["out->push_back(in);"]
			else
				["return in;"]
		ret = Type (to ++ "*")
		inp = Parameter (Variable (Type (fr ++ "*")) "in") "" 
		outp = Parameter (Variable (Type (to ++ "_list*")) "out") "" 


{-
	Default implemenation of children_xxx for each concrete class 
-}

default_transform_children :: Grammar -> [Context] -> [Method]
default_transform_children [] _ = []
default_transform_children (Disjunction _ _:tail) ctxts = default_transform_children tail ctxts
default_transform_children (Conjunction lhs rhs:tail) ctxts = (method:default_transform_children tail ctxts)
	where
		method = Method sig body
		sig = Signature Virtual NonStatic Void ("children_" ++ lhs) [inp]
		inp = Parameter (Variable (Type ("AST_" ++ lhs ++ "*")) "in") ""
		body = concatMap f rhs 
		f :: Term -> Body
		f term@(label, sym, mult) =
			let 
				var_name = term_to_varname term 
			in 
			if is_marker sym then
				[]
			else
				(if is_optional mult then ["if(in->" ++ var_name ++ " != NULL) "] else []) ++
				["in->" ++ var_name ++ " = in->" ++ var_name ++ "->transform(this);"]

{-
	Empty implemenation of transform_children for each token class
-}

token_children :: [Symbol] -> [Method]
token_children [] = []
token_children (t:ts) = (method:token_children ts)
	where
		method = Method sig body
		sig = Signature Virtual NonStatic Void ("children_" ++ (symbol_to_varname t)) [inp]
		inp = Parameter (Variable (Type (symbol_to_classname t ++ "*")) "in") ""
		body = []

{-
	Implementation of pre_, children_ and post_ for all list classes	
-}
list_transform_methods :: Grammar -> [Context] -> [Method]
list_transform_methods gr cx = concatMap f (find_lists gr cx)
	where
		f :: ClassName -> [Method]
		f cn = [list_pre cn, list_children cx cn, list_post cn]

list_pre :: ClassName -> Method
list_pre cn = Method (Signature Virtual NonStatic (Type (cn ++ "_list*")) ("pre_" ++ classname_to_varname cn ++ "_list") [param]) body
	where
		param = Parameter (Variable (Type (cn ++ "_list*")) "in") ""
		body = ["return in;"]

list_post :: ClassName -> Method
list_post cn = Method (Signature Virtual NonStatic (Type (cn ++ "_list*")) ("post_" ++ classname_to_varname cn ++ "_list") [param]) body
	where
		param = Parameter (Variable (Type (cn ++ "_list*")) "in") ""
		body = ["return in;"]

list_children :: [Context] -> ClassName -> Method
list_children ctxts cn = Method (Signature Virtual NonStatic Void ("children_" ++ classname_to_varname cn ++ "_list") [param]) body
	where
		param = Parameter (Variable (Type (cn ++ "_list*")) "in") ""
		(_, _, mult) = find_context cn ctxts
		body = 
			[
				cn ++ "_list*" ++ " new_v = new " ++ cn ++ "_list;",
				"List<" ++ cn ++ "*>::const_iterator i;",
				"for(i = in->begin(); i != in->end(); i++)",
				"\tif(*i)"
			]
			++
			(if is_vector mult then
				["\t{",
				 "\t\t" ++ cn ++ "_list*" ++ " ret_v = (*i)->transform(this);",
				 "\t\tnew_v->push_back_all(ret_v);",
				 "\t}"]
			else
				["\t\tnew_v->push_back((*i)->transform(this));"])
			++
			[
				"\telse",
				"\t\tnew_v->push_back(NULL);",
				"",
				"in->clear();", "in->push_back_all(new_v);"
			]
