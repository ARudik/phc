/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Perform a number of whole-program analyses simulteneously.
 *
 * Design of the whole-program optimizer
 *
 *		1. Perform flow-sensitive, context-sensitive analysis. When analysing a
 *		function in multiple contexts, clone the function, and store the clones
 *		in the call-graph. 
 *
 *		2. Before analysing each Basic_block, clear all phc.opt.* annotations.
 *		After analysing each block, each analysis re-annotates the block. At
 *		function-exit, the annotations stay.
 *
 *
 *		3. The analyses data structures' are cloned at split nodes, and
 *		combined at join nodes, whereupon the analysis proceeds for a single
 *		iteration.
 *
 *		4. After the analysis is complete, all the function annotations can be
 *		merged.
 *
 *		5. Once merged, the analyses are re-run over the complete call-graph,
 *		transforming the graph. This iterates until it converges (or a fixed
 *		number of times). This allows evals and includes to be replaced with
 *		their respective code.
 *
 *		6. Once finished, the combined alias-solution is used to annotate the
 *		results for SSA, where-upon DCE is run over the entire program.
 *
 *		7. Finally, code is generated using the (hopefully) well-annotated
 *		code.
 */

#include "process_ir/General.h"

#include "optimize/Edge.h"
#include "optimize/Oracle.h"

#include "Aliasing.h"
#include "Callgraph.h"
#include "CCP.h"
#include "optimize/SCCP.h"
#include "Constant_state.h"
#include "Def_use.h"
#include "Include_analysis.h"
#include "pass_manager/Pass_manager.h"
#include "Type_inference.h"
#include "VRP.h"
#include "Optimization_transformer.h"
#include "Whole_program.h"
#include "WPA.h"

using namespace MIR;
using namespace boost;
using namespace std;

Whole_program::Whole_program (Pass_manager* pm)
: pm (pm)
{
	// First class citizens:
	//		- Aliasing stores the analysis results, and passes them to the
	//		second-class citizens
	//		- Callgraph has a yet unrealized purpose.
	//		- CCP helps resolve branches
	aliasing = new Aliasing (this);
	callgraph = new Callgraph (this);
	ccp = new CCP (this);

	// Second class citizens
	//		- These consume data created by the first-class citizens.

	def_use = new Def_use (this);
//	constant_state = new Constant_state (this);
//	include_analysis = new Include_analysis (this);
//	vrp = new VRP (this);


	register_analysis ("Callgraph", callgraph);
	register_analysis ("CCP", ccp);
	register_analysis ("Def-use", def_use);
//	register_analysis ("Constant_state", constant_state);
//	register_analysis ("Include_analysis", include_analysis);
//	register_analysis ("Type_inference", new Type_inference (this));
//	register_analysis ("VRP", vrp);
}

void
Whole_program::run (MIR::PHP_script* in)
{
	// Perform the whole-program analysis
	invoke_method (
		new Method_invocation (
			NULL,
			new METHOD_NAME (s("__MAIN__")),
			new Actual_parameter_list),
		NULL,
		NULL);

	// Combine the results
	foreach (String* method, *callgraph->get_called_methods ())
	{
		Method_info* info = Oracle::get_method_info (method);

		if (!info->has_implementation ())
			continue;

		// Merge different contexts
		merge_contexts (info);

		// Generate Method_infos from the analysis results
		generate_summary (info);
	}

	// TODO: some kind of iteration. apply_results would be better if the
	// full points-to analysis was recalculated after
	// perform_local_optimizations.

	// Optimize based on analysis results
	foreach (String* method, *callgraph->bottom_up ())
	{
		Method_info* info = Oracle::get_method_info (method);

		if (!info->has_implementation ())
			continue;

		// Apply the results
		apply_results (Oracle::get_method_info (method));

		// TODO: we need to redo alias analysis here to get more precise results.
		// Perform DCE and CP.
		perform_local_optimizations (info);

		// Perform inlining
		// TODO:
	}
}


void
Whole_program::analyse_function (Basic_block* context, CFG* cfg, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
	// This is very similar to run() from Sparse_conditional_visitor, except
	// that it isnt sparse.

	WPA* wpa;
	string name;

	cfg->dump_graphviz (s("Function entry"));

	// 1. Initialize:
	Edge_list* cfg_wl = new Edge_list (cfg->get_entry_edge ());

	foreach (Edge* e, *cfg->get_all_edges ())
		e->is_executable = false;

	// Process the entry blocks first (there is no edge here)
	DEBUG ("Initing functions");
	forward_bind (context, cfg, actuals, lhs);


	// 2. Stop when CFG-worklist is empty
	while (cfg_wl->size () > 0)
	{
		Edge* e = cfg_wl->front();
		cfg_wl->pop_front ();


		// Analyse the block, storing per-basic-block results.
		// This does not update the block structure.

		bool changed = analyse_block (e->get_target ());

		// Always pass through at least once.
		if (e->is_executable == false)
			changed = true;

		// Tell successors that we are executable.
		e->is_executable = true;

		// Add next	block(s)
		if (changed)
		{
			if (Branch_block* branch = dynamic_cast<Branch_block*> (e->get_target ()))
				cfg_wl->push_back_all (get_branch_successors (branch));
			else if (!isa<Exit_block> (e->get_target ()))
				cfg_wl->push_back (e->get_target ()->get_successor_edges ()->front ());
		}
	}

	backward_bind (context, cfg);
}

Edge_list*
Whole_program::get_branch_successors (Branch_block* bb)
{
	Edge_list* result = new Edge_list;

	if (!ccp->branch_is_true (bb->branch))
		result->push_back (bb->get_false_successor_edge ());

	if (!ccp->branch_is_false (bb->branch))
		result->push_back (bb->get_true_successor_edge ());

	return result;
}

void
Whole_program::register_analysis (string name, WPA* analysis)
{
	assert (!analyses.has (name));
	analyses[name] = analysis;
}

Method_info_list*
Whole_program::get_possible_receivers (Method_invocation* in)
{
	Method_info_list* result = new Method_info_list;

	// If there is a target or a variable_method, there may be > 1 methods that
	// match it.
	if (in->target)
		phc_TODO ();

	if (isa<Variable_method> (in->method_name))
		phc_TODO ();

	String* name = dyc<METHOD_NAME> (in->method_name)->value;

	// This assumes there is only 1 function of that name, which is true. If
	// there are multiple versions, they are lowered to different names before
	// MIR.
	Method_info* info = Oracle::get_method_info (name);
	if (info == NULL)
		phc_TODO ();

	result->push_back (info);

	return result;	
}

void
Whole_program::invoke_method (Method_invocation* in, Basic_block* context, MIR::VARIABLE_NAME* lhs)
{
	Method_info_list* receivers = get_possible_receivers (in);

	// Need to clone the information and merge it when it returns.
	if (receivers->size () > 1)
		phc_TODO ();

	
	foreach (Method_info* receiver, *receivers)
	{
		// TODO: where should I clone the actuals?
		analyse_method_info (receiver, context, in->actual_parameters, lhs);
	}
}

void
Whole_program::analyse_method_info (Method_info* info,
												Basic_block* context,
												MIR::Actual_parameter_list* actuals,
												MIR::VARIABLE_NAME* lhs)
{
	if (info->has_implementation ())
		analyse_function (context, info->cfg, actuals, lhs);
	else
	{
		if (lhs)
			phc_TODO ();

		// Get as precise information as is possible with pre-baked summary
		// information.
		analyse_summary (info, context, actuals, lhs);
	}
}

void
Whole_program::analyse_summary (Method_info* info, Basic_block* context, Actual_parameter_list* actuals, VARIABLE_NAME* lhs)
{
	// TODO: We'll pretend for now that these have the same length. We should
	// probably have a final Parameter_info which models the remaining
	// actuals, with pass_by_ref etc (which is a bit different than the
	// current Oracle solution of is_param_x_pass_by_ref).
	if (info->params->size () != actuals->size ())
		phc_TODO ();

	// TODO: what about functions with callbacks
	callgraph->add_summary_call (context, info);

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
Whole_program::apply_results (Method_info* info)
{
	if (!info->has_implementation ())
		return;

	foreach (Basic_block* bb, *info->cfg->get_all_bbs ())
	{
		// We apply all results through aliasing. Its the only place we have all
		// the information we need (ie is this type weird, is it making an
		// implicit call, can we actually replace $x with its value, etc. Since
		// we need this information for tons of differernt optimizations, its
		// best to have a single transformer applying the results.
		//
		// Additionally, the results are indexed by the name the Points-to
		// analyser gives them, so we need acceess to this while these
		// transformations are running.
		if (Statement_block* sb = dynamic_cast<Statement_block*> (bb))
		{
			Statement* old = sb->statement->clone ();

			transformer->visit_block (bb);

			if (sb->statement->equals (old))
				DEBUG ("No changes in BB: " << bb->ID);
			else
				DEBUG ("BB " << bb->ID << " changed");
		}

	}
	info->cfg->dump_graphviz (s("Apply results"));
}

void
Whole_program::perform_local_optimizations (Method_info* info)
{
	if (info->has_implementation ())
		pm->run_local_optimization_passes (this, info->cfg);
}

void
Whole_program::generate_summary (Method_info* info)
{
	// it already has a summary
	if (!info->has_implementation ())
		return;

	// TODO
//	phc_TODO ();
}

void
Whole_program::merge_contexts (Method_info* info)
{
	// TODO: once we have a function that's called from multiple different
	// places.
}

bool
Whole_program::analyse_block (Basic_block* bb)
{
	DEBUG ("Analysing BB: " << bb->ID);

	// Merge results from predecessors
	foreach_wpa (this)
		wpa->pull_results (bb);

	// Do the aliasing (and hence other analyses)
	visit_block (bb);

	// Create OUT sets from the results 
	foreach_wpa_nd (this)
		wpa->aggregate_results (bb);

	// Dump
	dump (bb);

	// Calculate fix-point
	bool changed = false;
	foreach_wpa_nd (this)
		changed |= wpa->solution_changed (bb);


	return changed;
}

void
Whole_program::dump (Basic_block* bb)
{
	foreach_wpa (this)
	{
		wpa->dump (bb);
		cdebug << endl;
	}
}

void
Whole_program::forward_bind (Basic_block* context, CFG* callee_cfg, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
	string callee_ns = *callee_cfg->method->signature->method_name->value;
	string caller_ns;
	if (context) 
	{
		caller_ns = *context->cfg->method->signature->method_name->value;
		callgraph->add_user_call (context, callee_cfg);
	}

	phc_TODO (); // move these to Aliasing
	// Give the CFG access to the PTG results
//	callee_cfg->in_ptgs = &in_ptgs;
//	callee_cfg->out_ptgs = &out_ptgs;

//	ptg->open_scope (callee_ns);

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
			// $fp =& $ap;
			assign_by_ref (callee_cfg->get_entry_bb (),
					P (callee_ns, fp->var->variable_name),
					P (caller_ns, dyc<VARIABLE_NAME> (ap->rvalue)));
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

	// Store results in the entry block
	phc_TODO (); // move these to Aliasing
//	out_ptgs[callee_cfg->get_entry_bb ()->ID] = ptg->clone ();
//	in_ptgs[callee_cfg->get_entry_bb ()->ID] = ptg->clone ();
	dump (callee_cfg->get_entry_bb ());
}


void
Whole_program::backward_bind (Basic_block* context, CFG* callee_cfg)
{
	if (callee_cfg->method->is_main ())
		return;

	phc_TODO ();

//	ptg->close_scope (*callee_cfg->method->signature->method_name->value);

	// TODO: we need to handle returns for all the analyses, not just here
//	wp->def_use->backward_bind (context, callee_cfg);
}


/*
 * Analysis
 */

void
Whole_program::visit_global (Statement_block* bb, MIR::Global* in)
{
	assign_by_ref (bb,
			P (ST (bb), in->variable_name),
			P ("__MAIN__", in->variable_name));
}


void
Whole_program::visit_assign_var (Statement_block* bb, MIR::Assign_var* in)
{
	string ns = ST (bb);
	Path* lhs = P (ns, in->lhs);
	Path* rhs;

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
			phc_TODO ();
			break;

		// Straightforward
		case Array_access::ID:
		case Field_access::ID:
		case VARIABLE_NAME::ID:
		case Variable_variable::ID:
			rhs = P (ns, in->rhs);
			break;

		// Values
		case BOOL::ID:
		case INT::ID:
		case NIL::ID:
		case REAL::ID:
		case STRING::ID:
			assign_scalar (bb, lhs, dyc<Literal> (in->rhs));
			return;

		// Need to use analysis results before putting into the graph
		case Foreach_get_key::ID:
		case Foreach_get_val::ID:
		case Foreach_has_key::ID:
		case Cast::ID:
			phc_TODO ();
			break;


		// Interprocedural stuff
		case New::ID:
			handle_new (bb, dyc<New> (in->rhs), in->lhs);
			phc_TODO ();
			break;

		case Method_invocation::ID:
			handle_method_invocation (bb, dyc<Method_invocation> (in->rhs), in->lhs);
			phc_TODO ();
			break;

		default:
			phc_unreachable ();
			break;
	}

	assert (rhs);
	if (in->is_ref)
		assign_by_ref (bb, lhs, rhs);
	else
		assign_by_copy (bb, lhs, rhs);
}

void
Whole_program::visit_eval_expr (Statement_block* bb, MIR::Eval_expr* in)
{
	if (isa<New> (in->expr))
		handle_new (bb, dyc<New> (in->expr), NULL);
	else
		handle_method_invocation (bb, dyc<Method_invocation> (in->expr), NULL);
}

void
Whole_program::handle_method_invocation (Statement_block* bb, MIR::Method_invocation* in, MIR::VARIABLE_NAME* lhs)
{
	invoke_method (in, bb, lhs);
}

void
Whole_program::handle_new (Statement_block* bb, MIR::New* in, MIR::VARIABLE_NAME* lhs)
{
	phc_TODO ();
}

/*
 * Use whatever information is available to determine the assignments which
 * occur here.
 */

bool
is_must (Index_node_list* indices)
{
	assert (!indices->empty ());
	return (indices->size () == 1);
}

void
Whole_program::assign_by_ref (Basic_block* bb, Path* plhs, Path* prhs)
{
	Index_node_list* lhss = get_named_indices (bb, plhs);
	Index_node_list* rhss = get_named_indices (bb, prhs);

	bool killable = is_must (lhss);

	// Send the results to the analyses for all variables which could be
	// overwritten.
	foreach (Index_node* lhs, *lhss)
	{
		if (killable) // only 1 result
		{
			foreach_wpa (this)
				wpa->kill_reference (bb, lhs->name ());
		}

		// Note that we don't touch things which alias LHS.

		foreach (Index_node* rhs, *rhss)
		{
			// We don't need to worry about propagating values to LHSS' aliases,
			// as this kills those aliases.
			foreach_wpa (this)
				wpa->assign_by_ref (bb,
					lhs->name (),
					rhs->name (),
					(killable && is_must (rhss)) ? DEFINITE : POSSIBLE);
		}
	}
}

void
Whole_program::assign_scalar (Basic_block* bb, Path* plhs, Literal* lit)
{
	Index_node_list* lhss = get_named_indices (bb, plhs);

	bool killable = is_must (lhss);

	// This is not killing in terms of references, so it assigns to all
	// aliases of lhs.
	foreach (Index_node* lhs, *lhss)
	{
		if (killable) // only 1 result
		{
			foreach_wpa (this)
				wpa->kill_value (bb, lhs->name ());
		}

		// Handle all the aliases/indirect assignments.
		certainty certainties[] = {POSSIBLE, DEFINITE};
		foreach (certainty cert, certainties)
		{
			Index_node_list* refs = aliasing->get_references (bb, lhs, cert);

			// If we can't say the LHSS is killable, we get say its must defs are
			// killable either.
			if (!killable)
				cert = POSSIBLE;

			foreach_wpa (this)
			{
				foreach (Index_node* ref, *refs)
				{
					if (cert == DEFINITE) // must-def
						wpa->kill_value (bb, ref->name ());

					wpa->assign_scalar (bb, ref->name (), lit, cert);
				}
			}
		}

		// Handle LHS itself
		foreach_wpa (this)
		{
			if (killable) // only 1 result
				wpa->kill_value (bb, lhs->name ());

			wpa->assign_scalar (bb,
				lhs->name (),
				lit,
				killable ? DEFINITE : POSSIBLE);
		}
	}
}

void
Whole_program::assign_by_copy (Basic_block* bb, Path* plhs, Path* prhs)
{
	Index_node_list* lhss = get_named_indices (bb, plhs);
	Index_node_list* rhss = get_named_indices (bb, prhs);

	bool killable = is_must (lhss);

	// This is not killing in terms of references, so it assigns to all
	// aliases of lhs.
	foreach (Index_node* lhs, *lhss)
	{
		if (killable) // only 1 result
		{
			foreach_wpa (this)
				wpa->kill_value (bb, lhs->name ());
		}

		// Handle all the aliases/indirect assignments.
		certainty certainties[] = {POSSIBLE, DEFINITE};
		foreach (certainty cert, certainties)
		{
			Index_node_list* refs = aliasing->get_references (bb, lhs, cert);

			// If we can't say the LHSS is killable, we get say its must defs
			// are killable either.
			if (!killable)
				cert = POSSIBLE;

			foreach_wpa (this)
			{
				foreach (Index_node* ref, *refs)
				{
					if (cert == DEFINITE) // must-def
						wpa->kill_value (bb, ref->name ());

					foreach (Index_node* rhs, *rhss)
						wpa->assign_by_copy (bb,
							ref->name (),
							rhs->name (),
							is_must (rhss) ? cert : POSSIBLE);
				}
			}
		}

		// Handle LHS itself
		foreach (Index_node* rhs, *rhss) // TODO refactor this better
		{
			foreach_wpa (this)
			{
				if (killable) // only 1 result
					wpa->kill_value (bb, lhs->name ());

				wpa->assign_by_copy (bb,
					lhs->name (),
					rhs->name (),
					is_must (rhss) ? DEFINITE : POSSIBLE);
			}
		}
	}
}


void
Whole_program::record_use (Basic_block* bb, Index_node* index_node)
{
	// TODO: this marks it as a use, not a must use. Is there any difference
	// as far as analyses are concerned? If so, fix this. If not, remove the
	// may-uses.

	// TODO: once type-inferences is built, here would be a good place to
	// call/check for the handlers.
	
	foreach_wpa (this)
		wpa->record_use (bb, index_node->name(), POSSIBLE);
}


/*
 * Return the range of possible values for INDEX. This is used to
 * disambiguate for indexing other nodes. It returns a set of strings. If
 * only 1 string is returned, it must be that value. If more than one strings
 * are returned, it may be any of them.
 */
String_list*
Whole_program::get_string_values (Basic_block* bb, Index_node* index)
{
	Lattice_cell* result = ccp->ins[bb->ID][index->name ().str()];

	if (result == BOTTOM || result == TOP)
		phc_TODO ();

	// TODO: this isnt quite right, we need to cast to a string.
	return new String_list (
		dyc<Literal_cell> (result)->value->get_value_as_string ());
}

/*
 * Return the set of names which PATH might lead to.
 *
 * Its also a little bit of a catch-all function. Since it processes uses of
 * index_nodes, it must mark them as used, and check types to see if there
 * are any handlers that need to be called. It checks CCP to see the range of
 * variables that might be looked up, and any other analysis which can reduce
 * the range of the results.
 *
 * Suppose we get a single result, x. Can we say that a def to this must-def x?
 *		- I believe that scalars cant affect this
 *		- I think we can say that.
 */
Index_node_list*
Whole_program::get_named_indices (Basic_block* bb, Path* path)
{
	Indexing* p = dyc<Indexing> (path);


	// Get the set of storage nodes representing the LHS.
	Set<string> lhss;

	if (ST_path* st = dynamic_cast <ST_path*> (p->lhs))
	{
		// 1 named storage node
		lhss.insert (st->name);
	}
	else
	{
		// Lookup the storage nodes indexed by LHS
		foreach (Index_node* st_index, *get_named_indices (bb, p->lhs))
		{
			foreach (Storage_node* pointed_to,
						*aliasing->get_points_to (bb, st_index, PTG_ALL))
				lhss.insert (pointed_to->storage);
		}
	}


	// Get the names of the fields of the storage nodes.
	Set<string> rhss;

	if (Index_path* st = dynamic_cast <Index_path*> (p->rhs))
	{
		// 1 named field of the storage nodes
		rhss.insert (st->name);
	}
	else
	{
		// The name of the field must be looked up
		foreach (Index_node* field_index, *get_named_indices (bb, p->rhs))
		{
			// TODO: better place for this - its here because we know this is a
			// use. This doesnt intercept all uses, but I think it gets all the
			// ones in this function.
			record_use (bb, field_index);
			foreach (String* value, *get_string_values (bb, field_index))
				rhss.insert (*value);
		}
	}


	// Combine the results
	Index_node_list* result = new Index_node_list;

	foreach (string lhs, lhss)
		foreach (string rhs, rhss)
			result->push_back (new Index_node (lhs, rhs));

	return result;
}

Index_node*
Whole_program::get_named_index (Basic_block* bb, Path* name)
{
	Index_node_list* all = get_named_indices (bb, name);

	// TODO: can this happen
	assert (all->size());

	if (all->size () > 1)
		return NULL;

	return all->front ();
}