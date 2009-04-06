/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Perform a number of whole-program analyses simulteneously.
 *
 * Design of the whole-program optimizer
 *
 *		1. Perform flow-sensitive, context-sensitive, object-sensitive,
 *		field-sensitive analysis. When analysing a function in multiple
 *		contexts, clone the function, and store the clones in the call-graph. 
 *
 *		2. The analyses provide feedback to the Whole-program analyser. They
 *		resolve types to reduce reduce conservatism at call sites and for call
 *		handlers, and help resolve branches.
 *
 *		3. After the analysis is complete, each function will have one set of
 *		results at each program-point, for each context. These contexts are
 *		then merged.
 *
 *		4. Once merged, the combined alias-solution is used to annotate the
 *		results for SSA, and local optimizations are run on each function
 *
 *		5. Once merged, a transformer is run over each function, bottom-up,
 *		transforming the graph.
 *
 *		6. This whole process iterates until it converges (or a fixed number of
 *		times). This allows evals and includes to be replaced
 *		with their respective code.
 *
 *		7. An optimization annotator then runs across the entire solution,
 *		annotating the MIR using results from relevant program points.
 *
 *		8. Finally, code is generated using the (hopefully) well-annotated
 *		code.
 */


/*
 * Try to list areas in which we must be conservative:
 *
 * include_*
 * require_*
 * eval
 * per-object properties for non-stdClasses
 *
 * Limited conservativeness
 * dl
 * extract
 * compact
 *
 *
 * Areas which we dont support that might take some work (ie exceptions)
 *
 * set_error_handler
 * set_exception_handler
 *
 *
 * Hidden effects:
 *
 * array_indexing for SPL::ArrayAccess
 * handlers of objects of unknown classes
 * __autoload
 *
 
 */

#include "process_ir/General.h"
#include "pass_manager/Pass_manager.h"

#include "optimize/Abstract_value.h"
#include "optimize/Edge.h"
#include "optimize/Method_pruner.h"
#include "optimize/Oracle.h"
#include "optimize/SCCP.h"

#include "Whole_program.h"
#include "WPA.h"

#include "Aliasing.h"
#include "Callgraph.h"
#include "CCP.h"
#include "Constant_state.h"
#include "Debug_WPA.h"
#include "Def_use.h"
#include "Include_analysis.h"
#include "Optimization_annotator.h"
#include "Optimization_transformer.h"
#include "Points_to.h"
#include "Type_inference.h"
#include "VRP.h"

using namespace MIR;
using namespace boost;
using namespace std;

Whole_program::Whole_program (Pass_manager* pm)
: pm (pm)
{
	annotator = new Optimization_annotator (this);
	transformer = new Optimization_transformer (this);
}

void
Whole_program::run (MIR::PHP_script* in)
{
	// Represents __MAIN__'s caller
	Basic_block* outer_bb = new Empty_block (NULL);
	Context outer_cx = Context::outer (outer_bb);

	for (int w = 0; w < 10; w++)
	{
		initialize ();

		foreach_wpa (this)
			wpa->init (outer_cx);

		// Perform the whole-program analysis
		invoke_method (
				new Method_invocation (
					NULL,
					new METHOD_NAME (s("__MAIN__")),
					new Actual_parameter_list),
				outer_cx,
				NULL);

		// Merge different contexts
		merge_contexts ();


		// Optimize based on analysis results
		foreach (String* method, *callgraph->bottom_up ())
		{
			User_method_info* info = Oracle::get_user_method_info (method);

			if (info == NULL)
				continue;

			// Apply the results
			apply_results (info);

			// Summarize the current results
			generate_summary (info);

			// These should converge fairly rapidly, I think
			for (int i = 0; i < 10; i++)
			{
				DEBUG ((i+1) << "th intraprocedural iteration for "
						<< *info->name);

				CFG* before = info->cfg->clone ();

				// Perform DCE and CP, and some small but useful optimizations.
				perform_local_optimizations (info);

				// Inlining and such.
				perform_interprocedural_optimizations (info);

				// Summarize the current results
				generate_summary (info);

				// Check if we can stop iterating.
				if (before->equals (info->cfg))
					break;
			}
		}

		// Check if we can stop iterating the Whole-program solution.
		DEBUG ((w+1) << "th Whole-program pass");
		if (analyses_have_converged ())
			break;

		if (w == 9)
			phc_TODO (); // on the examples I'm running, this shouldnt happen.
	}

	// All the analysis and iteration is done
	foreach (String* method, *callgraph->bottom_up ())
	{
		Method_info* method_info = Oracle::get_method_info (method);

		if (!method_info->has_implementation ())
			continue;

		User_method_info* info = dyc<User_method_info> (method_info);

		// Annotate the statements for code-generation
		annotate_results (info);

		// Replace method implementation with optimized code
		info->method->statements = info->cfg->get_linear_statements ();
	}

	// As a final step, strip all unused functions.	
	strip (in);
}

bool
Whole_program::analyses_have_converged ()
{
	if (old_analyses.size () == 0)
		return false;
	
	List<WPA*>::const_iterator i = old_analyses.begin();
	foreach_wpa (this)
	{
		if (!wpa->equals (*i))
		{
			DEBUG (wpa->name << " has not converged");
			return false;
		}

		i++;
	}

	return true;
}

void
Whole_program::initialize ()
{
	// save the old analyses for iteration
	old_analyses.clear ();
	old_analyses.push_back_all (&analyses);
	analyses.clear ();


	// Create new analyses with empty results
	aliasing = new Aliasing (this);
	callgraph = new Callgraph (this);
	ccp = new CCP (this);
	def_use = new Def_use (this);
	type_inf = new Type_inference (this);
//	constant_state = new Constant_state (this);
//	include_analysis = new Include_analysis (this);
//	vrp = new VRP (this);

	register_analysis ("debug-wpa", new Debug_WPA (this));
	register_analysis ("aliasing", aliasing);
	register_analysis ("callgraph", callgraph);
	register_analysis ("ccp", ccp);
	register_analysis ("def-use", def_use);
	register_analysis ("type-inference", type_inf);
//	register_analysis ("Constant_state", constant_state);
//	register_analysis ("Include_analysis", include_analysis);
//	register_analysis ("VRP", vrp);
}

class Worklist
{
public:
	Edge_list edges; // ordering

public:

	Edge* next ()
	{
		if (size () == 0)
			return NULL;

		Edge* result = edges.front();
		edges.pop_front ();

		return result;
	}

	// TODO: dont add edges if they post-dominate other edges
	void add (Edge* edge)
	{
		edge->is_executable = true;

		// Dont add edges if they are already in the worklist, or if their
		// target post-dominates the target of an edge in the worklist.

		// Note: linear search - this assumes a very small number of edges in
		// the worklist, which is very likely.
		foreach (Edge* existing, edges)
		{
			if (existing == edge)
				return;

			if (existing->get_target ()->is_reverse_dominated_by (
						edge->get_target ()))
				return;
		}

		edges.push_back (edge);
	}

	size_t size ()
	{
		return edges.size ();
	}

};


void
Whole_program::analyse_function (User_method_info* info, Context caller_cx, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
	CFG* cfg = info->cfg;

	// This is very similar to run() from Sparse_conditional_visitor, except
	// that it isnt sparse.

	if (debugging_enabled)
		cfg->dump_graphviz (s("Function entry"));

	// 1. Initialize:
	foreach (Edge* e, *cfg->get_all_edges ())
		e->is_executable = false;

	Worklist wl;
	wl.add (cfg->get_entry_edge ());

	// Process the entry blocks first (there is no edge here)
	DEBUG ("Initing functions");
	forward_bind (
		info,
		Context::contextual (caller_cx, cfg->get_entry_bb()),
		actuals);


	// 2. Stop when CFG-worklist is empty
	while (wl.size () > 0)
	{
		Edge* e = wl.next ();
		DEBUG (wl.size() << " edges in the worklist");

		Basic_block* target = e->get_target ();
		Context cx = Context::contextual (caller_cx, target);

		// Analyse the block, storing per-basic-block results.
		// This does not update the block's structure.
		bool changed = analyse_block (cx);

		// Add next	block(s) if the result has changed, or if this the first
		// time the edge could be executed.
		foreach (Edge* next, *get_successors (cx))
			if (!next->is_executable || changed)
				wl.add (next);
	}

	backward_bind (
		info,
		Context::contextual (caller_cx, cfg->get_exit_bb()),
		lhs);
}

Edge_list*
Whole_program::get_successors (Context cx)
{
	Edge_list* result = new Edge_list;

	Basic_block* bb = cx.get_bb ();

	if (Branch_block* branch = dynamic_cast<Branch_block*> (bb))
	{
		Index_node* cond = VN (SYM (cx), branch->branch->variable_name);

		if (!ccp->branch_known_true (cx, cond->name()))
			result->push_back (branch->get_false_successor_edge ());

		if (!ccp->branch_known_false (cx, cond->name()))
			result->push_back (branch->get_true_successor_edge ());
	}
	else if (!isa<Exit_block> (bb))
	{
		result->push_back (bb->get_successor_edge ());
	}

	return result;
}

void
Whole_program::register_analysis (string name, WPA* analysis)
{
	analyses.push_back (analysis);
	analysis->name = name;
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
Whole_program::invoke_method (Method_invocation* in, Context caller_cx, MIR::VARIABLE_NAME* lhs)
{
	Method_info_list* receivers = get_possible_receivers (in);

	// Need to clone the information and merge it when it returns.
	if (receivers->size () > 1)
		phc_TODO ();

	
	foreach (Method_info* receiver, *receivers)
	{
		// TODO: where should I clone the actuals?
		analyse_method_info (receiver, caller_cx, in->actual_parameters, lhs);
	}

	// Reset the context correctly.
	block_cx = caller_cx;
}

void
Whole_program::analyse_method_info (Method_info* method_info,
												Context caller_cx,
												MIR::Actual_parameter_list* actuals,
												MIR::VARIABLE_NAME* lhs)
{
	if (method_info->has_implementation ())
	{
		User_method_info* info = dyc<User_method_info> (method_info);
		if (info->cfg == NULL)
			info->cfg = new CFG (info->method);

		analyse_function (info, caller_cx, actuals, lhs);
	}
	else
	{
		// Get as precise information as is possible with pre-baked summary
		// information.
		analyse_summary (dyc<Summary_method_info> (method_info), caller_cx, actuals, lhs);
	}
}

void
Whole_program::analyse_summary (Summary_method_info* info, Context caller_cx, Actual_parameter_list* actuals, VARIABLE_NAME* lhs)
{
	CFG* cfg = info->get_cfg ();


	/*
	 * Start the analysis
	 */
	Context entry_cx = Context::contextual (caller_cx, cfg->get_entry_bb ());
	forward_bind (info, entry_cx, actuals);

	// Create OUT sets for the entry node
	foreach_wpa (this)
		wpa->aggregate_results (entry_cx);



	/*
	 * "Perform" the function
	 */

	Context fake_cx = Context::contextual (caller_cx, info->get_fake_bb ());
	pull_results (fake_cx);

	apply_modelled_function (info, fake_cx);

	// Create OUT sets from the results 
	foreach_wpa (this)
		wpa->aggregate_results (fake_cx);



	/*
	 * Backward bind
	 */

	Context exit_cx = Context::contextual (caller_cx, cfg->get_exit_bb ());
	pull_results (exit_cx);

	backward_bind (info, exit_cx, lhs);
}

// BB is the block representing the whole method
void
Whole_program::apply_modelled_function (Summary_method_info* info, Context cx)
{
	// TODO:
	//	If we know all the values for all the parameters, and the function has
	//	no side-effects, call the function on its parameters.
	//
	//	TODO: stop only modelling types.

	// TODO: its difficult to know exactly what this representation should
	// look like when we haven't tried modelling that many functions. Instead,
	// we'll write 'baked-functions', which model it by directly calling
	// Whole_program methods. When we've done a few of these, it should be a
	// lot clearer what we want to model here (also, this allows us model hard
	// functions which might not be modelled with a data approach).

	// TODO: all of these might also return NULL, if they arent called properly.
	// A correct way to handle this would be to parse the zend_parse_parameters
	// using LLVM. For now, the best thing to do is assume that functions are
	// called correctly.


	Path* ret_path = P (SYM (cx), new VARIABLE_NAME (RETNAME));
	if (*info->name == "strlen")
	{
		assign_typed (cx, ret_path, Types ("int"));
	}
	else if (*info->name == "dechex")
	{
		assign_typed (cx, ret_path, Types ("string"));
	}
	else if (*info->name == "print")
	{
		assign_scalar (cx, ret_path, new INT (1));
	}
	else if (*info->name == "is_array")
	{
		assign_typed (cx, ret_path, Types ("bool"));
	}
	else if (*info->name == "is_object")
	{
		assign_typed (cx, ret_path, Types ("bool"));
	}
	else if (*info->name == "trigger_error")
	{
		assign_typed (cx, ret_path, Types ("bool"));
	}
	else if (*info->name == "date_default_timezone_set")
	{
		assign_typed (cx, ret_path, Types ("bool"));
	}
	else if (*info->name == "ob_start")
	{
		// TODO: If first parameter is a callback is set, thats a callback.
		assign_typed (cx, ret_path, Types ("bool"));
	}
	else if (*info->name == "gettimeofday")
	{
		// TODO: parameter could be false

		// If there its parameter is true, it returns a float. Else, if returns a
		// hashtable with 4 ints: sec, usec, minuteswest, dsttime
		string array_name = CX_array_name (cx);
		assign_empty_array (cx, ret_path, array_name);

		assign_typed (cx, P (array_name, "sec"), Types ("int"));
		assign_typed (cx, P (array_name, "usec"), Types ("int"));
		assign_typed (cx, P (array_name, "minuteswest"), Types ("int"));
		assign_typed (cx, P (array_name, "dsttime"), Types ("int"));
	}
	else if (*info->name == "var_dump")
		; // do nothing
	else
		phc_TODO ();
}

void
Whole_program::apply_results (User_method_info* info)
{
	// Since we use information from lots of sources, and we need this
	// information for tons of differernt optimizations, its best to have a
	// single transformer applying the results.
	foreach (Basic_block* bb, *info->cfg->get_all_bbs ())
	{
		// TODO: I should probably use CCP results here to optimize branches.
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
	if (debugging_enabled)
		info->cfg->dump_graphviz (s("Apply results"));
}

void
Whole_program::annotate_results (User_method_info* info)
{
	// Since we use information from lots of sources, and we need this
	// information for tons of different annotations, its best to have a
	// single annotator applying the results.
	foreach (Basic_block* bb, *info->cfg->get_all_bbs ())
		annotator->visit_block (bb);
}

void
Whole_program::perform_local_optimizations (User_method_info* info)
{
	pm->run_local_optimization_passes (this, info->cfg);

	pm->maybe_enable_debug (s("wpa"));
}

void
Whole_program::perform_interprocedural_optimizations (User_method_info* info)
{
	pm->run_ipa_passes (this, info->cfg);

	pm->maybe_enable_debug (s("wpa"));
}

void
Whole_program::strip (MIR::PHP_script* in)
{
	in->transform_children (new Method_pruner ());
}

void
Whole_program::generate_summary (User_method_info* info)
{
	// Simplest possible inlining info - the function does nothing.
	if (info->cfg->get_all_bbs ()->size() == 2)
		info->side_effecting = true;
}

void
Whole_program::merge_contexts ()
{
	foreach_wpa (this)
		wpa->merge_contexts ();
}

bool
Whole_program::analyse_block (Context cx)
{
	DEBUG ("\nAnalysing BB: " << cx << ": " << *cx.get_bb()->get_graphviz_label ());

	// Merge results from predecessors
	pull_results (cx);


	block_cx = cx;
	visit_block (cx.get_bb());


	foreach_wpa (this)
		wpa->aggregate_results (cx);

	dump (cx, "After analysis");

	// Calculate fix-point
	bool changed = false;
	foreach_wpa (this)
		changed |= wpa->solution_changed (cx);

	return changed;
}

void
Whole_program::pull_results (Context cx)
{
	Basic_block* bb = cx.get_bb ();
	
	List<Context>* preds = new List<Context>;

	Edge_list* pred_edges = bb->get_predecessor_edges ();
	foreach (Edge* pred_edge, *pred_edges)
	{
		// Ignore non-executable edges
		if (pred_edge->is_executable)
			preds->push_back (Context::as_peer (cx, pred_edge->get_source ()));
	}

	// Some index nodes may only have existed on one path. If their storage
	// node exists, then we assume that they are NULL on the other paths.
	Index_node_list* possible_nulls = aliasing->get_possible_nulls (preds);

	// Separate the first from the remainder, to simplfiy the remainder.
	Context first = preds->front ();
	preds->pop_front ();


	// Actually pull the results
	foreach_wpa (this)
	{
		wpa->pull_init (cx);
		wpa->pull_first_pred (cx, first);

		foreach (Context pred, *preds)
			wpa->pull_pred (cx, pred);

		// Use possible NULLs
		foreach (Index_node* index, *possible_nulls)
			wpa->pull_possible_null (cx, index);

		wpa->pull_finish (cx);
	}
}

void
Whole_program::dump (Context cx, string comment)
{
	CHECK_DEBUG ();
	foreach_wpa (this)
	{
		// This isnt the greatest means of debugging.
		pm->maybe_enable_debug (s(wpa->name));

		if (!debugging_enabled)
			continue;

		DEBUG (cx << " (" << comment << "): Dumping " << wpa->name);
		wpa->dump (cx, comment);
		cdebug << endl;
	}
	pm->maybe_enable_debug (s("wpa"));
}


/*
 * Analysis from here on in
 */

void
Whole_program::init_superglobals (Context cx)
{
	// TODO: Strictly speaking, functions other than __MAIN__ should have their
	// globals set up before the parameters are copied. However, we'll ignore
	// this minor bug since its broken elsewhere in the compiler.

	// TODO: add HTTP_*
	
	// TODO: we incorrectly mark _SERVER as being an array of strings.
	// However, it actually has "argc", "argv" and "REQUEST_TIME" set, which
	// are not strings.
	

	// Start with globals, since it needs needs to point to MSN
	string MSN = SYM (cx);
	assign_empty_array (cx, P (MSN, new VARIABLE_NAME ("GLOBALS")), MSN);


	// Do the other superglobals
	foreach (VARIABLE_NAME* sg, *PHP::get_superglobals ())
	{
		break; // simplify graph

		if (*sg->value == "GLOBALS")
			continue;

		// Create an empty array
		string array_name = *sg->value;
		assign_empty_array (cx, P (MSN, sg), array_name);

		// We dont know the contents of these arrays.
		// TODO: move all of these into calls to Whole_program
		assign_typed (cx, P (array_name, UNKNOWN), Types("string"));
	}

	// We actually have no idea whats in _SESSION
	assign_unknown (cx, P ("_SESSION", UNKNOWN));

	// argc
	assign_typed (cx, P (MSN, "argc"), Types ("int"));

	// argv
	assign_empty_array (cx, P (MSN, "argv"), "argv");
	assign_typed (cx, P ("argv", UNKNOWN), Types ("string"));
	assign_typed (cx,  P ("argv", "0"), Types ("string"));


	dump (cx, "After superglobals");
}

void
Whole_program::forward_bind (Method_info* info, Context entry_cx, MIR::Actual_parameter_list* actuals)
{
	Context caller_cx = entry_cx.caller ();
	string scope = SYM (entry_cx);

	// Each caller should expect that context can be NULL for __MAIN__.
	foreach_wpa (this)
	{
		wpa->forward_bind (caller_cx, entry_cx);

		// The symtable is an array
		wpa->set_storage (entry_cx, SN (scope), Types ("array"));
	}

	// Special case for __MAIN__. We do it here so that the other analyses
	// have initialized.
	if (caller_cx.is_outer ())
	{
		init_superglobals (entry_cx);
	}

	int i = 0;
	foreach (Actual_parameter* ap, *actuals)
	{
		// Default values
		if (info->default_param (i))
			phc_TODO ();
		else
		{
			// Add a default value of NULL for all variables
			assign_scalar (entry_cx, P (scope, UNKNOWN), new NIL);
		}

		// Actual parameters
		if (ap->is_ref || info->param_by_ref (i))
		{
			// $ap =& $fp;
			assign_by_ref (entry_cx,
					P (scope, info->param_name (i)),
					P (SYM (caller_cx), dyc<VARIABLE_NAME> (ap->rvalue)));
		}
		else
		{
			// $ap = $fp;
			if (isa<VARIABLE_NAME> (ap->rvalue))
			{
				assign_by_copy (entry_cx,
						P (scope, info->param_name (i)),
						P (SYM (caller_cx), dyc<VARIABLE_NAME> (ap->rvalue)));
			}
			else
			{
				assign_scalar (entry_cx,
						P (scope, info->param_name (i)),
						dyc<Literal> (ap->rvalue));
			}
		}

		i++;
	}

	foreach_wpa (this)
		wpa->aggregate_results (entry_cx);

	dump (entry_cx, "After forward_bind");
}


void
Whole_program::backward_bind (Method_info* info, Context exit_cx, MIR::VARIABLE_NAME* lhs)
{
	// Do assignment back to LHS
	//
	// If we do the assignment in the caller, then it will use the result from
	// the IN of the caller, which wont tell us anything. It should use the out
	// of the callee. However, using the callee means we need to ensure the
	// results have propagated. So the callee has 3 BBs: entry, exit and the
	// one where the work is done.
	//
	// The assignment to LHS is done in the context of the callee, and then the
	// results are backwards_bound. This has the added advantage that we can
	// strip the callees results from the solution without worrying. There is a
	// danger that it might make an analysis think that return value somehow
	// escapes. I'm not sure if anything needs to be done about that.

	Context caller_cx = exit_cx.caller ();
	if (lhs)
	{
		if (info->return_by_ref ())
		{
			// $lhs =& $retval;
			assign_by_ref (exit_cx,
					P (SYM (caller_cx), dyc<VARIABLE_NAME> (lhs)),
					P (SYM (exit_cx), new VARIABLE_NAME (RETNAME)));
		}
		else
		{
			// $lhs = $retval;
			assign_by_copy (exit_cx,
					P (SYM (caller_cx), dyc<VARIABLE_NAME> (lhs)),
					P (SYM (exit_cx), new VARIABLE_NAME (RETNAME)));
		}
	}

	// TODO:
	// We want to mark escaping values in the function's exit block. This will
	// tell us important use/def info.
	//
	// At function entry, we should also mark use/defs using escaping info. It
	// may be more accurate to do that on return perhpas.
	//
	// TODO: current we mark index_nodes which are used, and whatever
	// references them. I would not be sure that correctly handle the case
	// where $x aliases $y[0], and $y[0] is used after being passed to a
	// function.

	// Context can be NULL for __MAIN__
	foreach_wpa (this)
		wpa->backward_bind (caller_cx, exit_cx);

	dump (caller_cx, "After backward bind");
}


/*
 * Use whatever information is available to determine the assignments which
 * occur here.
 */

bool
is_must (Index_node_list* indices)
{
	// If the edge between it and its storage node is POSSIBLE, this function
	// is still correct. All that matters is whether we can refer to one index
	// node, or multiple.
	assert (!indices->empty ());

	if (indices->size () > 1)
		return false;
	
	if (indices->front()->index == UNKNOWN)
		return false;

	return true;
}

// Returns the certainty with which assignments can be made to it.
certainty
Whole_program::kill_value (Context cx, Path* plhs)
{
	// do implicit conversions
	Index_node_list* lhss = get_named_indices (cx, plhs, (Indexing_flags)(IMPLICIT_CONVERSION));

	// TODO: dont kill fields of abstract storage nodes

	// Don't kill if this refers to more than 1 index_node, which means we
	// don't know what variable to kill.
	if (!is_must (lhss))
		return POSSIBLE;


	// There shoudlnt be any may-refs.
	assert (aliasing->get_references (cx, lhss->front (), POSSIBLE)->empty());

	foreach (Index_node* node, *get_all_referenced_names (cx, plhs))
		foreach_wpa (this)
		{
			wpa->kill_value (cx, node);
		}

	return DEFINITE;
}

void
Whole_program::assign_by_ref (Context cx, Path* plhs, Path* prhs)
{
	// Should we separate the assignment by value and the assignment by ref.
	phc_TODO ();
	Index_node_list* lhss = get_named_indices (cx, plhs);
	Index_node_list* rhss = get_named_indices (cx, prhs, RECORD_USES);

	bool killable = is_must (lhss);

	// Send the results to the analyses for all variables which could be
	// overwritten.
	foreach (Index_node* lhs, *lhss)
	{
		if (killable) // only 1 result
		{
			foreach_wpa (this)
				wpa->kill_reference (cx, lhs);
		}

		// We don't need to worry about propagating values to LHSS' aliases, as
		// the aliasing relations are killed above.
	
		foreach (Index_node* rhs, *rhss)
		{
			foreach_wpa (this)
			{
				wpa->create_reference (cx, lhs, rhs,
					(killable && is_must (rhss)) ? DEFINITE : POSSIBLE);

				phc_TODO ();
//				wpa->assign_value (bb,
//					lhs->name (),
//					rhs->name (),
//					(killable && is_must (rhss)) ? DEFINITE : POSSIBLE);
			}
		}
	}
}


void
Whole_program::assign_scalar (Context cx, Path* plhs, Literal* lit)
{
	certainty cert = kill_value (cx, plhs);
	foreach (Index_node* node, *get_all_referenced_names (cx, plhs))
	{
		foreach_wpa (this)
		{
			wpa->set_scalar (cx, ABSVAL (node),
					Abstract_value::from_literal (lit));

			wpa->assign_value (cx, node, ABSVAL (node), DEFINITE);
		}
	}
}

void
Whole_program::assign_typed (Context cx, Path* plhs, Types types)
{
	// Split scalars, objects and arrays here.
	Types scalars = Type_inference::get_scalar_types (types);
	Types array = Type_inference::get_array_types (types);
	Types objects = Type_inference::get_object_types (types);

	certainty cert = kill_value (cx, plhs);
	foreach (Index_node* node, *get_all_referenced_names (cx, plhs))
	{
		Alias_name name = node->name();
		foreach_wpa (this)
		{
			if (scalars.size ())
			{
				wpa->set_scalar (cx, ABSVAL (node),
						Abstract_value::from_types (scalars));

				wpa->assign_value (cx, node, ABSVAL(node), cert);
			}



			if (array.size ())
				phc_TODO ();

			if (objects.size ())
				phc_TODO ();

			//	wpa->assign_storage (bb, ref->name(),
			//								CX_array_name (bb)->name(), POSSIBLE);

			//	wpa->assign_storage (bb, ref->name(),
			//								CX_object_name (bb)->name(), POSSIBLE);
		}
	}
}

void
Whole_program::assign_empty_array (Context cx, Path* plhs, string unique_name)
{
	certainty cert = kill_value (cx, plhs);
	foreach (Index_node* node, *get_all_referenced_names (cx, plhs))
	{
		foreach_wpa (this)
		{
			wpa->set_storage (cx, SN(unique_name), Types ("array"));
			wpa->assign_value (cx, node, SN(unique_name), cert);
		}
	}

	// All the arrays entries are NULL.
	assign_scalar (cx, P (unique_name, UNKNOWN), new NIL);
}

void
Whole_program::assign_unknown (Context cx, Path* plhs)
{
	// This assigns a value which is unknown, but is not as bad as
	// ruin_everything (ie, it doesnt link to all the other objects, arrays,
	// etc. Is this being used right?

	certainty cert = kill_value (cx, plhs);

	// Unknown may be an array, a scalar or an object, all of which have
	// different properties. We must be careful to separate these.
	foreach (Index_node* node, *get_all_referenced_names (cx, plhs))
	{
		// When assigning to different references:
		//		- scalar values are copied (though they are conceptually shared,
		//		we deal with that through functions like this).
		//		- the array is shared, not copied. It will have a unique name.
		//		- the object is shared, and will have a unique name.
		foreach_wpa (this)
		{
			// TODO: this is really not good enough. The array looks empty, the
			// object may reference anything. I suspect this is only suitable
			// for _SESSION, when nothing else really exists. Even then, the
			// array and object shouldnt be empty. It might be sufficient to
			// have UNKNOWN fields pointing to themselves, and marking them as
			// abstract.

			wpa->set_scalar (cx, ABSVAL (node), Abstract_value::unknown ());
			wpa->assign_value (cx, node, ABSVAL (node), POSSIBLE);

			wpa->set_storage (cx, CX_array_node (cx), Types ("array"));
			wpa->assign_value (cx, node, CX_array_node (cx), POSSIBLE);

			wpa->set_storage (cx, CX_object_node (cx), Types ("object"));
			wpa->assign_value (cx, node, CX_object_node (cx), POSSIBLE);
		}
	}
}



void
Whole_program::assign_by_copy (Context cx, Path* plhs, Path* prhs)
{
	// foreach values V pointed to by PRHS:
	//	switch V.type:
	//		Scalar:
	//			- foreach alias A of PLHS, set the value of A::ABSVAL using V.
	//		Array:
	//			- foreach alias A of PLHS, create a copy of V, with a new name.
	//		Objects:
	//			- foreach alias A of PLHS, point from A to V.

	certainty cert = kill_value (cx, plhs);

	// For objects, copy the edge. For arrays, copy the whole thing. For
	// scalars, copy the scalar (if unknown). It seems clear that we need an
	// unknown object here, if the type is not known to not be an object.
	Index_node_list* rhss = get_named_indices (cx, prhs, RECORD_USES);

	// If there is more than 1 RHSs, we cant say for sure which we're copying
	// from.
	if (rhss->size () > 1)
		cert = POSSIBLE;

	foreach (Index_node* lhs, *get_all_referenced_names (cx, plhs))
	{
		foreach (Index_node* rhs, *rhss)
		{
			copy_value (cx, lhs, rhs, cert);
		}
	}
}

void
Whole_program::copy_value (Context cx, Index_node* lhs, Index_node* rhs, certainty cert)
{
	// Get the value for each RHS. Copy it using the correct semantics.
	Storage_node_list* values = aliasing->get_values (cx, rhs);

	// If there is more than 1 value, it can't be definite.
	if (values->size () > 1)
		cert = POSSIBLE;

	foreach (Storage_node* st, *values)
	{
		// Get the type of the value
		Types types = type_inf->get_types (cx, st->name());
		// TODO: handle bottom

		// It must be either all scalars, array, list of classes, or bottom.
		Types scalars = Type_inference::get_scalar_types (types);
		Types array = Type_inference::get_array_types (types);
		Types objects = Type_inference::get_object_types (types);

		assert (!scalars.empty() ^ !array.empty() ^ !objects.empty());

		if (scalars.size())
		{
			foreach_wpa (this)
			{
				wpa->set_scalar (cx, ABSVAL (lhs),
						get_abstract_value (cx, st->name()));

				wpa->assign_value (cx, lhs, ABSVAL (lhs), cert);
			}
		}

		if (array.size())
		{
			// We need to do a deep copy here.
			Storage_node* new_array = CX_array_node (cx);

			// create the new array
			foreach_wpa (this)
				wpa->set_storage (cx, new_array, Types ("array"));

			// Get all the indices
			foreach (Index_node* index, *aliasing->get_indices (cx, st))
			{
				// TODO: I think these are not killed, but should be, if allowable.
				copy_value (cx,
						new Index_node (new_array->storage, index->index),
						index,
						aliasing->get_cert (cx, st, index));
			}

			// LHS points to NEW_ARRAY.
			foreach_wpa (this)
				wpa->assign_value (cx, lhs, new_array, cert);
		}

		if (objects.size ())
		{
			// Just point to the object.
			foreach_wpa (this)
				wpa->assign_value (cx, lhs, st, cert);
		}
	}
}

void
Whole_program::record_use (Context cx, Index_node* node)
{
	// TODO: this marks it as a use, not a must use. Is there any difference
	// as far as analyses are concerned? If so, fix this. If not, remove the
	// may-uses.

	// TODO: once type-inferences is built, here would be a good place to
	// call/check for the handlers.
	
	foreach_wpa (this)
		wpa->record_use (cx, node, POSSIBLE);
}



void
Whole_program::ruin_everything (Context cx, Path* plhs)
{
	// For every storage node we can reach, mark its "*" index as completely
	// unknown.
	phc_TODO ();
}


/*
 * Return the range of possible values for INDEX. This is used to
 * disambiguate for indexing other nodes. It returns a set of strings. If
 * only 1 string is returned, it must be that value. If more than one strings
 * are returned, it may be any of them. NULL may be returned, indicating that it may be all possible values.
 */
String_list*
Whole_program::get_string_values (Context cx, Index_node* node)
{
	Lattice_cell* result = ccp->get_value (cx, node->name ());

	if (result == TOP)
		return new String_list (s(""));

	if (result == BOTTOM)
		return new String_list (s(UNKNOWN));

	// TODO: this isnt quite right, we need to cast to a string.
	return new String_list (
		dyc<Literal_cell> (result)->value->get_value_as_string ());
}


Abstract_value*
Whole_program::get_abstract_value (Context cx, Alias_name name)
{
	return new Abstract_value (
							ccp->get_value (cx, name), 
							type_inf->get_value (cx, name));
}

Abstract_value*
Whole_program::get_bb_out_abstract_value (Context cx, Alias_name name)
{
	return new Abstract_value (
							ccp->outs[cx][name.str()],
							type_inf->outs[cx][name.str()]);
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
 *
 *
 *	TODO: there is a bit of a problem here with implicit creation of values. If
 *	we're looking to the the assignment $x[$i] = 5, we need to create $x.
 *	Likewise for $y =& $x[$i] or anything in the form $y =& $x->$f.
 */
Index_node_list*
Whole_program::get_named_indices (Context cx, Path* path, Indexing_flags flags)
{
	// Debugging
//	path->dump(); 	cdebug << endl;

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
		// TODO: propagate record_uses?
		// Lookup the storage nodes indexed by LHS
		foreach (Index_node* st_index, *get_named_indices (cx, p->lhs, flags))
		{
			foreach (Storage_node* pointed_to, *aliasing->get_values (cx, st_index))
			{
				string name = pointed_to->storage;

				// Implicit array/field creation
				if (isa<Value_node> (pointed_to))
				{
					// TODO: this could be a string, which is very difficult to handle
					// TODO: an array is only implicitly created for NULL/uninit.
					// Other scalars will go to NULL instead.
					// TODO: these cases should clearly be dealt with in the caller.

					name = CX_array_node (cx)->storage;

					// TODO: i'm not very happy about this
					if (flags & IMPLICIT_CONVERSION)
						assign_empty_array (cx, p->lhs, name);
				}

				lhss.insert (name);
			}
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
		foreach (Index_node* field_index, *get_named_indices (cx, p->rhs, flags))
		{
			// Record this use regardless of RECORD_USES
			record_use (cx, field_index);

			// This should return a set of possible names, 1 known name
			// (including "*" indicating it could be anything).
			foreach (String* value, *get_string_values (cx, field_index))
				rhss.insert (*value);
		}
	}

	assert (rhss.size ());


	// Combine the results
	Index_node_list* result = new Index_node_list;

	foreach (string lhs, lhss)
		foreach (string rhs, rhss)
		{
			if (flags & RECORD_USES)
				record_use (cx, new Index_node (lhs, rhs));

			result->push_back (new Index_node (lhs, rhs));
		}

	return result;
}

Index_node*
Whole_program::get_named_index (Context cx, Path* name, Indexing_flags flags)
{
	Index_node_list* all = get_named_indices (cx, name, flags);

	// TODO: can this happen
	assert (all->size());

	if (all->size () > 1)
		return NULL;

	return all->front();
}



Index_node_list*
Whole_program::get_all_referenced_names (Context cx, Path* path, Indexing_flags flags)
{
	Map<Alias_name, Index_node*> names;

	Index_node_list* lhss = get_named_indices (cx, path, flags);

	foreach (Index_node* lhs, *lhss)
	{
		// Handle all the aliases/indirect assignments.
		Index_node_list* refs = aliasing->get_references (cx, lhs, PTG_ALL);
		refs->push_back (lhs);

		foreach (Index_node* ref, *refs)
		{
			names[ref->name()] = ref;
		}
	}

	return names.values ();
}

/*
 * Analysis
 */

void
Whole_program::visit_global (Statement_block* bb, MIR::Global* in)
{
	string ns = SYM (block_cx);

	assign_by_ref (block_cx,
			P (ns, in->variable_name),
			P ("__MAIN__", in->variable_name));
}


void
Whole_program::visit_assign_array (Statement_block* bb, MIR::Assign_array* in)
{
	string ns = SYM (block_cx);
	Path* lhs = P (ns, in);

	if (isa<Literal> (in->rhs))
	{
		assign_scalar (block_cx, lhs, dyc<Literal> (in->rhs));
	}
	else
	{
		Path* rhs = P (ns, in->rhs);

		if (in->is_ref)
			assign_by_ref (block_cx, lhs, rhs);
		else
			assign_by_copy (block_cx, lhs, rhs);
	}
}


void
Whole_program::visit_foreach_reset (Statement_block* bb, MIR::Foreach_reset* in)
{
	string ns = SYM (block_cx);

	// mark the array as used
	record_use (block_cx, VN (ns, in->array));

	// Mark iterator as defined. The iterator does nothing for us otherwise.
	Alias_name iter (ns, *in->iter->value);
	
	// We dont use Whole_programm::assign_unknown because we havent got a Path
	// for an iterator. We also don't need to worry about kills and such. Note
	// that we dont want a path, as that would create an index into the
	// array's storage node, which isnt what we want to model.
	phc_TODO ();
/*	foreach_wpa (this)
		wpa->assign_unknown (block_cx, iter, DEFINITE);*/
}

void
Whole_program::visit_foreach_end (Statement_block* bb, MIR::Foreach_end* in)
{
	string ns = SYM (block_cx);

	// Mark the array as used
	record_use (block_cx, VN (ns, in->array));

	// Mark both a use and a def on the iterator
	Alias_name iter (ns, *in->iter->value);
	phc_TODO ();
//	record_use (block_cx, iter.ind());

/*	foreach_wpa (this)
		wpa->assign_unknown (block_cx, iter, DEFINITE);*/
}


void
Whole_program::visit_eval_expr (Statement_block* bb, MIR::Eval_expr* in)
{
	saved_plhs = NULL;
	saved_lhs = NULL;
	visit_expr (bb, in->expr);
}

void
Whole_program::visit_unset (Statement_block* bb, MIR::Unset* in)
{
	string ns = SYM (block_cx);

	Index_node_list* indices = get_named_indices (block_cx, P (ns, in));

	// Send the results to the analyses for all variables which could be
	// overwritten.
	foreach (Index_node* index, *indices)
		foreach_wpa (this)
			wpa->kill_reference (block_cx, index);
}

void
Whole_program::visit_branch_block (Branch_block* bb)
{
	string ns = SYM (block_cx);

	record_use (block_cx, VN (ns, bb->branch->variable_name));
}


void
Whole_program::visit_pre_op (Statement_block* bb, Pre_op* in)
{
	string ns = SYM (block_cx);

	// ++ and -- won't affect objects.
	Path* path = P (ns, in->variable_name);

	// I'm not really sure how to get a good interface on all this.
	Index_node* n = VN (ns, in->variable_name);

	// Case where we know the value
	MIR::Literal* value = ccp->get_lit (block_cx, n->name());
	if (value)
	{
		Literal* result = PHP::fold_pre_op (value, in->op);
		assign_scalar (block_cx, path, result);
		return;
	}

	// Maybe we know the type?
	Type_cell* tc = dyc<Type_cell> (type_inf->get_value (block_cx, n->name()));
	assert (tc != TOP); // would be NULL in CCP
	if (tc == BOTTOM)
	{
		assign_unknown (block_cx, path);
		return;
	}

	assign_typed (block_cx, path, tc->types);
}

void
Whole_program::visit_assign_field (Statement_block*, MIR::Assign_field*)
{
	phc_TODO ();
}

void
Whole_program::visit_assign_var_var (Statement_block*, MIR::Assign_var_var*)
{
	phc_TODO ();
}

void
Whole_program::visit_foreach_next (Statement_block*, MIR::Foreach_next*)
{
	phc_TODO ();
}

void
Whole_program::visit_assign_next (Statement_block* bb, MIR::Assign_next* in)
{
	string ns = SYM (block_cx);

	// TODO: _next_ is one larger than the largest positive integer element

	Path* lhs = P (ns, in);

	if (isa<Literal> (in->rhs))
	{
		assign_scalar (block_cx, lhs, dyc<Literal> (in->rhs));
	}
	else
	{
		Path* rhs = P (ns, in->rhs);

		if (in->is_ref)
			assign_by_ref (block_cx, lhs, rhs);
		else
			assign_by_copy (block_cx, lhs, rhs);
	}
}

void
Whole_program::visit_return (Statement_block*, MIR::Return*)
{
	phc_TODO ();
}

void
Whole_program::visit_static_declaration (Statement_block*, MIR::Static_declaration*)
{
	phc_TODO ();
}

void
Whole_program::visit_throw (Statement_block*, MIR::Throw*)
{
	phc_TODO ();
}

void
Whole_program::visit_try (Statement_block*, MIR::Try*)
{
	phc_TODO ();
}

/*
 * Assign_vars from here
 */ 
void
Whole_program::visit_assign_var (Statement_block* bb, MIR::Assign_var* in)
{
	string ns = SYM (block_cx);

	saved_plhs = P (ns, in->lhs);
	saved_lhs = in->lhs;
	saved_is_ref = in->is_ref;

	switch (in->rhs->classid())
	{
		case Bin_op::ID:
		case Cast::ID:
		case Constant::ID:
		case Foreach_get_val::ID:
		case Foreach_has_key::ID:
		case Instanceof::ID:
		case Isset::ID:
		case Param_is_ref::ID:
		case Unary_op::ID:
			assert (!in->is_ref);
			// fall-through

		case Array_access::ID:
		case Field_access::ID:
		case Foreach_get_key::ID:
		case Method_invocation::ID:
		case New::ID:
		case VARIABLE_NAME::ID:
		case Variable_variable::ID:
			visit_expr (bb, in->rhs);
			break;

		// Values
		case BOOL::ID:
		case INT::ID:
		case NIL::ID:
		case REAL::ID:
		case STRING::ID:
			assert (!in->is_ref);
			assign_scalar (block_cx, saved_plhs, dyc<Literal> (in->rhs));
			break;

		default:
			phc_unreachable ();
			break;
	}

	saved_lhs = NULL;
	saved_plhs = NULL;
}



void
Whole_program::visit_array_access (Statement_block* bb, MIR::Array_access* in)
{
	if (saved_is_ref)
		phc_TODO ();

	string ns = SYM (block_cx);

	assign_by_copy (block_cx, saved_plhs, P (ns, in));
}

void
Whole_program::visit_bin_op (Statement_block* bb, MIR::Bin_op* in)
{
	string ns = SYM (block_cx);

	Abstract_value* left = get_abstract_value (block_cx, in->left);
	Abstract_value* right = get_abstract_value (block_cx, in->right);

	if (isa<Literal_cell> (left->lit) && isa<Literal_cell> (right->lit))
	{
		Literal* result = PHP::fold_bin_op (
					dyc<Literal_cell> (left->lit)->value,
					in->op,
					dyc<Literal_cell> (right->lit)->value);

		assign_scalar (block_cx, saved_plhs, result);
		return;
	}

	// TODO: record uses

	Types types = type_inf->get_bin_op_types (block_cx, left, right, *in->op->value);

	assign_typed (block_cx, saved_plhs, types);
}

Abstract_value*
Whole_program::get_abstract_value (Context cx, MIR::Rvalue* rval)
{
	string ns = SYM (cx);

	if (isa<Literal> (rval))
		return Abstract_value::from_literal (dyc<Literal> (rval));

	// The variables are not expected to already have the same value. Perhaps
	// there was an assignment to $x[0], and we are accessing $x[$i].
	Index_node_list* indices = get_named_indices (cx, P (ns, dyc<VARIABLE_NAME> (rval)));

	if (indices->size () > 1)
		phc_TODO ();
	
	return get_abstract_value (cx, indices->front()->name ());
}

void
Whole_program::visit_cast (Statement_block* bb, MIR::Cast* in)
{
	string ns = SYM (block_cx);

	Alias_name operand = VN (ns, in->variable_name)->name();

	MIR::Literal* lit = ccp->get_lit (block_cx, operand);
	if (lit)
	{
		Literal* result = PHP::cast_to (in->cast, lit);
		if (result)
		{
			assign_scalar (block_cx, saved_plhs, result);
			return;
		}
	}

	// We've handled casts for known scalars to scalars. We still must handle
	// casts to objects, casts to arrays, and casts from unknown values to
	// other scalar types.


	if (*in->cast->value == "array")
	{
		if (lit && isa<NIL> (lit))
		{
			// Most common case: create an empty array
			assign_empty_array (block_cx, saved_plhs, CX_array_name (block_cx));
		}
		else
			phc_TODO ();

	}
	else if (*in->cast->value == "object")
	{
		phc_TODO ();
	}
	else
		phc_unreachable ();
}

void
Whole_program::visit_constant (Statement_block* bb, MIR::Constant* in)
{
	string ns = SYM (block_cx);

	phc_TODO ();

	Literal* lit = PHP::fold_constant (in);
	if (lit)
	{
		assign_scalar (block_cx, saved_plhs, lit);
		return;
	}

	// Assign_unknown_typed (Types (sitrng, bool, null, etc
	phc_TODO ();
}

void
Whole_program::visit_field_access (Statement_block* bb, MIR::Field_access* in)
{
	phc_TODO ();
}

void
Whole_program::visit_foreach_get_key (Statement_block* bb, MIR::Foreach_get_key* in)
{
	phc_TODO ();
}

void
Whole_program::visit_foreach_get_val (Statement_block* bb, MIR::Foreach_get_val* in)
{
	phc_TODO ();
}

void
Whole_program::visit_foreach_has_key (Statement_block* bb, MIR::Foreach_has_key* in)
{
	phc_TODO ();
}

void
Whole_program::visit_instanceof (Statement_block* bb, MIR::Instanceof* in)
{
	phc_TODO ();
}

void
Whole_program::visit_isset (Statement_block* bb, MIR::Isset* in)
{
	phc_TODO ();
}

void
Whole_program::visit_method_invocation (Statement_block* bb, MIR::Method_invocation* in)
{
	if (saved_is_ref)
		phc_TODO ();

	invoke_method (in, block_cx, saved_lhs);
}

void
Whole_program::visit_new (Statement_block* bb, MIR::New* in)
{
	phc_TODO ();
}

void
Whole_program::visit_param_is_ref (Statement_block* bb, MIR::Param_is_ref* in)
{
	phc_TODO ();
}

void
Whole_program::visit_unary_op (Statement_block* bb, MIR::Unary_op* in)
{
	phc_TODO ();
}

void
Whole_program::visit_variable_name (Statement_block* bb, MIR::VARIABLE_NAME* in)
{
	if (saved_is_ref)
		phc_TODO ();

	string ns = SYM (block_cx);

	assign_by_copy (block_cx, saved_plhs, P (ns, in));
}

void
Whole_program::visit_variable_variable (Statement_block* bb, MIR::Variable_variable* in)
{
	phc_TODO ();
}
