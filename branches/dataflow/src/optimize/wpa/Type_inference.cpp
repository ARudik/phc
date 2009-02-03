/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Type-inference.
 *
 */

#include "Aliasing.h"
#include "Type_inference.h"
#include "Whole_program.h"
#include "Points_to.h"

using namespace MIR;
using namespace std;
using namespace boost;

/*
string
Type_inference::get_type (Value_node* val)
{
	if (Lit_node* lit = dynamic_cast<Lit_node*> (val))
		return demangle (lit->lit);
	else if (Array_node* an = dynamic_cast<Array_node*> (val))
		return "array";
	else
		phc_TODO ();
}
*/
Type_inference::Type_inference (Whole_program* wp)
: WPA (wp)
{
}

bool
Type_inference::is_object (String* name)
{
	if (*name == "STRING")
		return false;
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
	return; // TODO

	int index = 0;
	string method_name = *info->method_name;
	phc_TODO ();
	/*
	foreach (Parameter_info* pinfo, *info->params)
	{
		Actual_parameter* ap = actuals->at(index);
		if (!isa<Literal> (ap->rvalue)) // literals arent objects
		{
			Location* loc = wp->bcch_aliasing->ptg->get_location (
				method_name,
				dyc<VARIABLE_NAME> (ap->rvalue));

			foreach (String* type, *get_types (loc))
			{
				if (!is_basic_type (type))
					phc_TODO ();
			}
			
		}

		index++;
	}*/
}

void
Type_inference::forward_bind (CFG* caller_cfg, CFG* callee_cfg, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
}

void
Type_inference::backward_bind (CFG* caller_cfg, CFG* callee_cfg)
{
}


/*
String_list*
Type_inference::get_types (Location* loc)
{
	String_list* result = new String_list;

//	foreach (Value_node* end, *loc->get_pointees<Value_node>())
//	{
		// TODO: get the type from the object, etc.
//		result->push_back (s (demangle (end->lit, false)));
//	}

	return result;
}
*/
void
Type_inference::dump()
{
	// Traverse the points-to graph. For each variable in it, find the types
	// it may point to.
/*	foreach (Location* loc, *wp->bcch_aliasing->ptg->get_nodes<Loc_node> ())
	{
		cdebug << *node->var_name->value << ": [ ";

		foreach (String* type_name, *get_types (node))
		{
			cdebug << *type_name << ", ";
		}

		cdebug << "]" << endl;
	}
	*/
}