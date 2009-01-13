/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Type-inference.
 *
 */

#include "BCCH_aliasing.h"
#include "Type_inference.h"
#include "Whole_program.h"

using namespace MIR;
using namespace std;
using namespace boost;

Type_inference::Type_inference (Whole_program* wp)
: WPA (wp)
{
}

/* I cant bring myself to call this 'scalar' when it includes arrays. */
bool
Type_inference::is_basic_type (String* name)
{
	if (*name == "STRING")
		return true;
	else
		phc_TODO ();
}


void
Type_inference::use_summary_results (Method_info* info, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
	// Handle magic methods. If any parameter can have a magic method, and is
	// an object, invoke the method from Whole_program. We do not need to get
	// the list of receivers here, as Whole_program will query us to find them
	// out separately. We only need to know whether or not there is an
	// invocation.

	int index = 0;
	foreach (Parameter_info* pinfo, *info->params)
	{
		Actual_parameter* ap = actuals->at(index);
		if (!isa<Literal> (ap->rvalue)) // literals arent objects
		{
			PT_node* node = wp->bcch_aliasing->ptg->get_node (
				dyc<VARIABLE_NAME> (ap->rvalue));

			foreach (String* type, *get_types (dyc<Var_node> (node)))
			{
				if (!is_basic_type (type))
					phc_TODO ();
			}
		}

		index++;
	}
}

void
Type_inference::initialize_function (MIR::Method* in, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
	phc_TODO ();
}

void
Type_inference::finalize_function (MIR::Method* in)
{
	phc_TODO ();
}



String_list*
Type_inference::get_types (Var_node* node)
{
	String_list* result = new String_list;

	foreach (Atom_node* end, *node->get_pointees<Atom_node>())
	{
		// HACK
		result->push_back (s (demangle (end->atom, false)));
	}

	return result;
}

void
Type_inference::dump()
{
	// Traverse the points-to graph. For each variable in it, find the types
	// it may point to.
	foreach (Var_node* node, *wp->bcch_aliasing->ptg->get_nodes<Var_node> ())
	{
		cdebug << *node->var_name->value << ": [ ";

		foreach (String* type_name, *get_types (node))
		{
			cdebug << *type_name << ", ";
		}

		cdebug << "]" << endl;
	}
}
