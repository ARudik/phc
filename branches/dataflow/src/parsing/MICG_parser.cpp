/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Parser for the Macro inline code generator.
 */

#include "MICG_parser.h"

// Uncomment to debug parsing. Useful for finding bugs in the parsed data as
// well as in the parser.
// To debug the AST structure generated by Spirit, enable BOOST_SPIRIT_DEBUG,
// and look for the final concat_match(begin) in the file.
//#define BOOST_SPIRIT_DEBUG
#define BOOST_SPIRIT_DEBUG_PRINT_SOME 80
#define BOOST_SPIRIT_DEBUG_FLAGS BOOST_SPIRIT_DEBUG_FLAGS_NODES

#include <boost/lexical_cast.hpp>
#include <boost/spirit.hpp>
#include <boost/spirit/iterator/position_iterator.hpp>
#include <boost/spirit/tree/ast.hpp>
#include <iostream>
#include "lib/error.h"
#include "lib/Map.h"
#include "MICG_factory.h"
#include "MICG.h"
#include "process_ir/debug.h"

using namespace std;
using namespace boost::spirit;
using namespace boost;
using namespace MICG;


MICG_parser::MICG_parser ()
{
}



struct skip_grammar : public grammar<skip_grammar>
{
	template <typename ScannerT>
	struct definition
	{
		rule<ScannerT> skip;

		definition (skip_grammar const& self)
		{
			BOOST_SPIRIT_DEBUG_TRACE_NODE(skip, false);
			skip = no_node_d[space_p | comment_p ("//") | comment_p ("/*", "*/")];
		}

		rule<ScannerT> const& start() const
		{ 
			return skip;
		}
	};
};



/*
 * Limitations:
 *		- Its hard to put {} around the body of a template. Use @@@ instead.
 *		- Quoted strings dont support escaping of '"'. However, a quoted string
 *		is only used as a parameter to a macro, so thats not a great problem.
 */
struct MICG_grammar : public grammar<MICG_grammar>
{
	// TODO: the duplcation here is tedious
	enum 
	{
		// leave 0 to indicate no ID
		actual_parameter_list_id = 1,
		attr_name_id,
		body_id,
		body_part_list_id,
		c_code_id,
		equals_id,
		expr_id,
		formal_parameter_id,
		formal_parameter_list_id,
		interpolation_id = 10,
		lookup_id,
		macro_call_id,
		macro_id,
		macro_list_id,
		macro_name_id,
		param_name_id,
		quoted_string_id,
		r_id,
		_rule_id,
		_rule_list_id = 20,
		signature_id,
		type_name_id,
	};


	template <typename ScannerT>
	struct definition
	{
#define DECL_RULE(NAME) rule<ScannerT, parser_context<>, parser_tag<NAME##_id> >	NAME;
		DECL_RULE(actual_parameter_list);
		DECL_RULE(attr_name);
		DECL_RULE(body);
		DECL_RULE(body_part_list);
		DECL_RULE(c_code);
		DECL_RULE(equals);
		DECL_RULE(expr);
		DECL_RULE(formal_parameter);
		DECL_RULE(formal_parameter_list);
		DECL_RULE(interpolation);
		DECL_RULE(lookup);
		DECL_RULE(macro);
		DECL_RULE(macro_call);
		DECL_RULE(macro_list);
		DECL_RULE(macro_name);
		DECL_RULE(param_name);
		DECL_RULE(quoted_string);
		DECL_RULE(r);
		DECL_RULE(_rule);
		DECL_RULE(_rule_list);
		DECL_RULE(signature);
		DECL_RULE(type_name);


		definition (MICG_grammar const& self)
		{
			BOOST_SPIRIT_DEBUG_RULE(actual_parameter_list);
			BOOST_SPIRIT_DEBUG_RULE(attr_name);
			BOOST_SPIRIT_DEBUG_RULE(body);
			BOOST_SPIRIT_DEBUG_RULE(body_part_list);
			BOOST_SPIRIT_DEBUG_RULE(c_code);
			BOOST_SPIRIT_DEBUG_RULE(equals);
			BOOST_SPIRIT_DEBUG_RULE(expr);
			BOOST_SPIRIT_DEBUG_RULE(formal_parameter);
			BOOST_SPIRIT_DEBUG_RULE(interpolation);
			BOOST_SPIRIT_DEBUG_RULE(lookup);
			BOOST_SPIRIT_DEBUG_RULE(macro);
			BOOST_SPIRIT_DEBUG_RULE(macro_call);
			BOOST_SPIRIT_DEBUG_RULE(macro_list);
			BOOST_SPIRIT_DEBUG_RULE(macro_name);
			BOOST_SPIRIT_DEBUG_RULE(param_name);
			BOOST_SPIRIT_DEBUG_RULE(quoted_string);
			BOOST_SPIRIT_DEBUG_RULE(r);
			BOOST_SPIRIT_DEBUG_RULE(_rule);
			BOOST_SPIRIT_DEBUG_RULE(_rule_list);
			BOOST_SPIRIT_DEBUG_RULE(signature);
			BOOST_SPIRIT_DEBUG_RULE(type_name);

			attr_name = lexeme_d[leaf_node_d[+(alpha_p | '_')]];
			macro_name = lexeme_d[leaf_node_d[+(alpha_p | '_')]];
			param_name = lexeme_d[leaf_node_d[+(upper_p | '_')]];
			quoted_string = lexeme_d[leaf_node_d[confix_p ('"', *anychar_p, '"')]];
			type_name = lexeme_d[leaf_node_d[+lower_p]];
			
			// A signature line
			formal_parameter = type_name >> param_name;
			// TODO: do we need aroot_node_d? i dont think it does anything.
			formal_parameter_list = root_node_d [list_p(formal_parameter, ',')];
			signature = macro_name >> '(' >> formal_parameter_list >> ')';

			// A rule line
			lookup = param_name >> "." >> attr_name;
			expr = lookup | param_name | quoted_string;
			equals = expr >> "==" >> expr;
			_rule = "where" >> (equals | lookup);
			_rule_list = *_rule;

			// Bodies
			// We don't want c_code to take in macro_call, interpolation, or @@@.
			// However, we do want to allow '$' and '\\' in c_code. So we allow
			// them as the first character only. Since we match interpolation and
			// macro_call before c_code, if C_code stops on $ and \\, it will try
			// macro_call and interpolation before it incorporates '$' and '\\'.
			c_code = lexeme_d[leaf_node_d[(anychar_p - '@') >> *(anychar_p - (ch_p('\\') | '$' | '@'))]];

			actual_parameter_list = list_p (param_name | quoted_string, ", ");
			macro_call = ('\\' >> macro_name >> '(' >> actual_parameter_list >> ");");

			interpolation = ('$' >> param_name) | ("${" >> lookup >> '}');

			// A template
			body_part_list = *(macro_call | interpolation | c_code);
			body = "@@@" >> body_part_list >> "@@@";
			macro = signature >> _rule_list >> body;

			macro_list = *macro;
			r = macro_list;
		}

		rule<ScannerT, parser_context<>, parser_tag<r_id> > const& start() const
		{ 
			return r;
		}
	};
};

typedef position_iterator<char const *> pos_iter_t;
typedef tree_match<pos_iter_t, node_iter_data_factory<> >::container_t container;
typedef node_iter_data<pos_iter_t> tree_node_t;
typedef tree_match<pos_iter_t, node_iter_data_factory<> > tree_match_t;
typedef tree_match_t::tree_iterator tree_iter_t;


/* Extract the structure from the Boost AST, and put it into the maketea MICG.
 *
 * There are 3 kinds of node:
 *		- maketea tokens: their value is available in the node
 *		- conjunctions: their contructor arguments are available as their children
 *		- syntax tokens: these have an _id of 0, and must be ignored. Although we
 *		can remove tokens from the Boost AST (by marking them with
 *		no_node_d[...]), I've left them in, as the annotations to remove them
 *		makes the grammar very unreadable.
 */

Object* create_micg_node (tree_iter_t tree);

List<Object*>* create_micg_list (container trees)
{
	List<Object*>* result = new List<Object*>;
	for (tree_iter_t tree = trees.begin (); tree != trees.end (); tree++)
	{
		Object* obj = create_micg_node (tree);

		// Ignore syntax tokens
		if (obj == NULL)
			continue;

		result->push_back (obj);
	}

	return result;
}

/*
 * Spirit will not create empty lists, or lists of 1 element, instead producing
 * nothing, or just a single node. Hack it.
 *
 * This checks position INDEX to see if it is a T_list. If not, add empty list,
 * or, if there is a T there, wrap it in a list.
 *
 * This checks types, so it assumes that one T_list is not followed by another.
 */
template <class T>
Object_list*
check_argument_list (Object_list* in, unsigned int index)
{
	// Too short. Add it in last position.
	if (index > in->size ())
	{
		assert (in->size () == index + 1);
		in->push_back (new List<T*>);
		return in;
	}

	// Check if its already perfect.
	if (isa<List<T*> > (in->at(index)))
		return in;

	Object* subject = in->at (index);
	Object_list* result = new Object_list;
	foreach (Object* obj, *in)
	{
		if (obj == subject)
		{
			// An unwrapper node: wrap it
			if (isa<T> (obj))
			{
				result->push_back (new List<T*> (dyc<T> (obj)));
				continue;
			}
			else // Empty list: add a list.
				result->push_back (new List<T*>);
		}

		result->push_back (obj);
	}
	return result;
}


Map<long, string> names;

Object*
create_micg_node (tree_iter_t iter)
{
	Object *result;


	long id = iter->value.id ().to_long ();
	assert (id == 0 || names[id] != "");
	String* value = s(string (iter->value.begin(), iter->value.end()));
	DEBUG ("entering " << id << " (" << names[id] << ")");

	switch (id)
	{
		/*
		 * Conjunctions and lists
		 */
		case MICG_grammar::body_id:
		case MICG_grammar::equals_id:
		case MICG_grammar::formal_parameter_id:
		case MICG_grammar::lookup_id:
		case MICG_grammar::macro_call_id:
		case MICG_grammar::macro_id:
		case MICG_grammar::signature_id:

		case MICG_grammar::actual_parameter_list_id:
		case MICG_grammar::body_part_list_id:
		case MICG_grammar::formal_parameter_list_id:
		case MICG_grammar::macro_list_id:
		case MICG_grammar::_rule_list_id:
		{
			Object_list* params = create_micg_list (iter->children);

			// Hack for Spirit 'bug' (see comment at definition). We need one of
			// these for each conjunction with a list argument.
			if (id == MICG_grammar::macro_id)
				params = check_argument_list<Rule> (params, 1);
			else if (id == MICG_grammar::signature_id)
				params = check_argument_list<Formal_parameter> (params, 1);
			else if (id == MICG_grammar::body_id)
				params = check_argument_list<Body_part> (params, 0);
			else if (id == MICG_grammar::macro_call_id)
				params = check_argument_list<Actual_parameter> (params, 1);

			result = Node_factory::create (names[id].c_str(), params);
			assert (result);

			if (Node* node = dynamic_cast<Node*> (result))
			{
				node->assert_valid ();
				file_position pos = iter->value.begin().get_position ();
				node->attrs->set ("phc.line_number", new ::Integer (pos.line));
				node->attrs->set ("phc.column_number", new ::Integer (pos.column));
			}

			break;
		}

		/* Disjunctions (ignore) */
		case MICG_grammar::expr_id:
		case MICG_grammar::interpolation_id:
		case MICG_grammar::_rule_id:
		{
			Object_list* list = create_micg_list (iter->children);
			assert (list->size () == 1);
			result = list->front ();
			break;
		}

		/*
		 * Tokens
		 */

		case MICG_grammar::quoted_string_id:
			// Strip off the ""s
			value = new String (value->substr (1, value->size() - 2));
			// Fallthrough

		case MICG_grammar::attr_name_id:
		case MICG_grammar::c_code_id:
		case MICG_grammar::macro_name_id:
		case MICG_grammar::param_name_id:
		case MICG_grammar::type_name_id:
		{
			assert (*value != "");
			DEBUG (" - " << value);

			result = Node_factory::create (
					names[id].c_str(),
					new Object_list (value));

			assert (result);
			Node* node = dyc<Node> (result);
			node->assert_valid ();

			file_position pos = iter->value.begin().get_position ();
			node->attrs->set ("phc.line_number", new ::Integer (pos.line));
			node->attrs->set ("phc.column_number", new ::Integer (pos.column));
			break;
		}


		/* Ignore syntactic tokens */
		case 0:
			result = NULL;
			break;


		default:
			cerr << "havent handled node with ID: " << id << endl;
			phc_unreachable ();
	}



	DEBUG ("leaving " << id << " (" << names[id] << ")");
	return result;
}


Macro_list*
MICG_parser::parse (string str)
{
	names[MICG_grammar::actual_parameter_list_id] = "Actual_parameter_list";
	names[MICG_grammar::attr_name_id] = "ATTR_NAME";
	names[MICG_grammar::body_id] = "Body";
	names[MICG_grammar::body_part_list_id] = "Body_part_list";
	names[MICG_grammar::c_code_id] = "C_CODE";
	names[MICG_grammar::equals_id] = "Equals";
	names[MICG_grammar::formal_parameter_id] = "Formal_parameter";
	names[MICG_grammar::formal_parameter_list_id] = "Formal_parameter_list";
	names[MICG_grammar::interpolation_id] = "Interpolation";
	names[MICG_grammar::lookup_id] = "Lookup";
	names[MICG_grammar::macro_call_id] = "Macro_call";
	names[MICG_grammar::macro_id] = "Macro";
	names[MICG_grammar::macro_list_id] = "Macro_list";
	names[MICG_grammar::macro_name_id] = "MACRO_NAME";
	names[MICG_grammar::param_name_id] = "PARAM_NAME";
	names[MICG_grammar::quoted_string_id] = "STRING";
	names[MICG_grammar::_rule_id] = "Rule";
	names[MICG_grammar::_rule_list_id] = "Rule_list";
	names[MICG_grammar::signature_id] = "Signature";
	names[MICG_grammar::type_name_id] = "TYPE_NAME";

	// By using a phrase parser with a white-space skip, comments are ignored,
	// and we can ignore white space.
	MICG_grammar g;
	skip_grammar skipg;

	BOOST_SPIRIT_DEBUG_GRAMMAR(g);
	BOOST_SPIRIT_DEBUG_TRACE_NODE(skipg, false);

	pos_iter_t begin(str.c_str (), str.c_str() + str.size ());
	pos_iter_t end;
	tree_parse_info<pos_iter_t, node_iter_data_factory<> > info = ast_parse(begin, end, g >> end_p, skipg, node_iter_data_factory<>());
	begin.set_tab_chars (1);

	file_position pos = info.stop.get_position ();

	DEBUG ("stop: "
			<< pos.line << ", "
			<< pos.column << "\n"
			<< "full: " << info.full << "\n"
			<< "length: " << info.length << "\n");

	if (!info.full)
		phc_internal_error ("Cannot parse template. Error at line %d, column %d",
			pos.line, pos.column);


	assert (info.trees.size() == 1);

	return dyc<Macro_list> (create_micg_node (info.trees.begin()));
}

