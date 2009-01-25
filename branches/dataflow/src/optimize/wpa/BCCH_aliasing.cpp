/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Flow-, field-, and context-sensitive alias analysis, in a similar fashion to
 *
 * Michael Hind and Michael Burke and Paul Carini and Jong-Deok Choi,
 * Interprocedural pointer alias analysis
 * ACM Trans. Program. Lang. Syst., 1999
 *
 * We use an infinite call-string approach, and assume that other peoples
 * research can be used to constrain the memory usage at a later date. There is
 * one points-to graph per program point (which corresponds to a basic block
 * for us).
 */

#include "BCCH_aliasing.h"
#include "Points_to.h"
#include "Whole_program.h"

using namespace MIR;
using namespace boost;
using namespace std;

BCCH_aliasing::BCCH_aliasing (Whole_program* wp)
: WPA (wp)
{
	ptg = new Points_to;
}


void
BCCH_aliasing::use_summary_results (Method_info* info, MIR::Actual_parameter_list* in, MIR::VARIABLE_NAME* lhs)
{
	if (lhs)
		phc_TODO ();

	if (info->can_touch_globals)
		phc_TODO ();

	if (info->can_touch_locals)
		phc_TODO ();

	if (info->return_by_ref)
		phc_TODO ();

	// We model each parameter, and the return value, for:
	//		- can they alias other parameters (keep it simple, we can do more
	//		complicated thing for functions we analyse, such as 'aliases a field
	//		of param1'.
	//		- can they alias a global variable
	foreach (Parameter_info* pinfo, *info->params)
	{
		if (pinfo->pass_by_reference)
			phc_TODO ();

		if (pinfo->is_callback)
			phc_TODO ();

		if (pinfo->can_touch_objects)
			phc_TODO ();

		// Magic methods are handled in the callgraph.
	}

	// TODO: does this create alias relationships
	// TODO: how does this affect the callgraph
	//		- need to look at types for that
}



void
BCCH_aliasing::forward_bind (CFG* caller_cfg, CFG* callee_cfg, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
	string callee_ns = *callee_cfg->method->signature->method_name->value;
	string caller_ns;
	if (caller_cfg) 
		caller_ns = *caller_cfg->method->signature->method_name->value;


	ptg->open_scope (callee_ns);

	if (actuals->size () != callee_cfg->method->signature->formal_parameters->size ())
		phc_TODO ();


	Actual_parameter_list::const_iterator i = actuals->begin ();
	foreach (Formal_parameter* fp, *callee_cfg->method->signature->formal_parameters)
	{
		if (fp->var->default_value)
			phc_TODO ();

		Actual_parameter* ap = *i;
		if (fp->is_ref || ap->is_ref)
		{
			phc_TODO ();
			// $fp =& $ap;
//			ptg->set_reference (
//				ptg->get_var (callee_ns, fp->var->variable_name),
//				ptg->get_var (caller_ns, dyc<VARIABLE_NAME> (ap->rvalue)));
		}
		else
		{
			// $fp = $ap;
			phc_TODO ();
		}
	}

	if (lhs)
	{
		// TODO: do this upon return instead
		phc_TODO ();
		/*
		if (return_by_ref)
			set_reference
		else
			set_value
		*/
	}
}

void
BCCH_aliasing::backward_bind (CFG* caller_cfg, CFG* callee_cfg)
{
	phc_TODO ();

	// TODO: handle returns

	ptg->close_scope (*callee_cfg->method->signature->method_name->value);
}

void
BCCH_aliasing::analyse_block (Basic_block* bb)
{
	string name;
	WPA* wpa;

	// Pre-hooks (applies to this aswell)
	foreach (tie (name, wpa), wp->analyses)
		wpa->pre_annotate (bb, ptg);

	visit_block (bb);
	dump();

	// Post-hooks (applies to this aswell)
	foreach (tie (name, wpa), wp->analyses)
		wpa->post_annotate (bb, ptg);
}




void
BCCH_aliasing::visit_global (Statement_block* bb, MIR::Global* in)
{
	// These dont really change anything
	// TODO: these might set a var to NULL, from uninit
	// TODO: merge from trunk, it removes the semantics changing ones
	if (bb->cfg->method->is_main ())
		return;

	if (isa<Variable_variable> (in->variable_name))
		phc_TODO ();

	VARIABLE_NAME* var_name = dyc<VARIABLE_NAME> (in->variable_name);
	phc_TODO ();
/*	ptg->set_reference (
		ptg->get_var (NAME (bb), var_name),
		ptg->get_var ("__MAIN__", var_name));
*/
}


void
BCCH_aliasing::visit_assign_var (Statement_block* bb, MIR::Assign_var* in)
{
	string ns = NAME (bb);
	Index_node* lhs = VN (ns, in->lhs);
	PT_node* rhs = NULL;

	switch(in->rhs->classid())
	{
		// Does not affect pointer analysis
		// TODO: except to call object properties!!
		case Bin_op::ID:
		case Isset::ID:
		case Param_is_ref::ID:
		case Unary_op::ID:
		case Instanceof::ID:
		case Constant::ID:
			break;

		case VARIABLE_NAME::ID:
			rhs =	VN (ns, dyc<VARIABLE_NAME> (in->rhs));
			break;

		default:
			phc_TODO ();
			break;

		// Not in the graph
		case BOOL::ID:
		case INT::ID:
		case NIL::ID:
		case REAL::ID:
		case STRING::ID:
			break;

		// Need to use analysis results before putting into the graph
		case Variable_variable::ID:
		case Field_access::ID:
		case Foreach_get_key::ID:
		case Foreach_get_val::ID:
		case Foreach_has_key::ID:
		case Cast::ID:
			phc_TODO ();
			break;

		case Array_access::ID:
		{
			phc_TODO ();
//			Array_access* aa = dyc<Array_access> (in->rhs);
//			Location* array = ptg->get_var (ns, aa->variable_name);
//			Location* index =
//				ptg->get_var (ns, dyc<VARIABLE_NAME> (aa->index));

			phc_TODO ();
//			rhs = ptg->get_indexed_location (array, index);
			break;
		}

		// Interprocedural stuff
		case New::ID:
			handle_new (bb, dyc<New> (in->rhs), in->lhs);
			phc_TODO ();
			break;

		case Method_invocation::ID:
			handle_method_invocation (bb, dyc<Method_invocation> (in->rhs), in->lhs);
			phc_TODO ();
			break;
	}

	if (in->is_ref)
			ptg->set_reference (lhs, dyc<Index_node> (rhs));
	else
	{
		if (rhs == NULL) // literals
			ptg->set_scalar_value (lhs);
		else
			ptg->copy_value (lhs, dyc<Index_node> (rhs));
	}
}

void
BCCH_aliasing::visit_eval_expr (Statement_block* bb, MIR::Eval_expr* in)
{
	if (isa<New> (in->expr))
		handle_new (bb, dyc<New> (in->expr), NULL);
	else
		handle_method_invocation (bb, dyc<Method_invocation> (in->expr), NULL);
}

// TODO: this should be used in a lot more places
// TODO: non-string go through being ints before being converted to a string
string
BCCH_aliasing::get_index (Literal* lit)
{
	if (STRING* str = dynamic_cast<STRING*> (lit))
		return *str->value;

	// TODO: use embed
	phc_TODO ();
}

void
BCCH_aliasing::handle_method_invocation (Statement_block* bb, MIR::Method_invocation* in, MIR::VARIABLE_NAME* lhs)
{
	wp->invoke_method (in, bb->cfg, lhs);
}

void
BCCH_aliasing::handle_new (Statement_block* bb, MIR::New* in, MIR::VARIABLE_NAME* lhs)
{
	phc_TODO ();
}


void BCCH_aliasing::dump ()
{
	CHECK_DEBUG();
	ptg->dump_graphviz (NULL);
}
