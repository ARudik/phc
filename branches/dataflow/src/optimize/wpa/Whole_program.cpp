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

#include "Whole_program.h"
#include "Worklist.h"
#include "WPA.h"

#include "Debug_WPA.h"
#include "Aliasing.h"
#include "Callgraph.h"
#include "Constant_state.h"
#include "Def_use.h"
#include "Include_analysis.h"
#include "Value_analysis.h"
#include "VRP.h"

#include "Optimization_annotator.h"
#include "Optimization_transformer.h"
#include "Stat_collector.h"
#include "Points_to.h"

#define ANON ""

using namespace MIR;
using namespace boost;
using namespace std;

Whole_program::Whole_program (Pass_manager* pm)
: pm (pm)
{
	annotator = new Optimization_annotator (this);
	transformer = new Optimization_transformer (this);
	stat_coll = new Stat_collector (this);
}

void
Whole_program::run (MIR::PHP_script* in)
{
	// Represents __MAIN__'s caller
	Basic_block* outer_bb = new Empty_block (NULL);
	Context* outer_cx = Context::outer (outer_bb);

	for (int w = 0; w < 10; w++)
	{
		initialize (outer_cx);

		// Perform the whole-program analysis
		invoke_method (
				outer_cx,
				NULL,
				new Method_invocation (
					NULL,
					new METHOD_NAME (s("__MAIN__")),
					new Actual_parameter_list));

		finish_stacks ();

		// Merge different contexts
		merge_contexts ();

		dump (new Context, R_OUT, "after context merge");


		// Optimize based on analysis results
		foreach (Method_info* mi, *callgraph->bottom_up ())
		{
			User_method_info* info = dynamic_cast<User_method_info*> (mi);

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

				CFG* before = info->get_cfg ()->clone ();

				// Perform DCE and CP, and some small but useful optimizations.
				perform_local_optimizations (info);

				// Inlining and such.
				perform_interprocedural_optimizations (info);

				// Summarize the current results
				generate_summary (info);

				// Check if we can stop iterating.
				if (before->equals (info->get_cfg ()))
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
	foreach (Method_info* mi, *callgraph->bottom_up ())
	{
		User_method_info* info = dynamic_cast<User_method_info*> (mi);

		if (info == NULL)
			continue;

		// Annotate the statements for code-generation
		annotate_results (info);
	
		collect_stats (info);	

		// Replace method implementation with optimized code
		info->get_method ()->statements = info->get_cfg ()->get_linear_statements ();
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
Whole_program::initialize (Context* outer_cx)
{
	// save the old analyses for iteration
	old_analyses.clear ();
	old_analyses.push_back_all (&analyses);
	analyses.clear ();


	// Create new analyses with empty results
	aliasing = new Aliasing (this);
	callgraph = new Callgraph (this);
	constants = new Constant_state (this);
	def_use = new Def_use (this);
	values = new Value_analysis (this);
//	include_analysis = new Include_analysis (this);
//	vrp = new VRP (this);

	register_analysis ("debug-wpa", new Debug_WPA (this));
	register_analysis ("aliasing", aliasing);
	register_analysis ("callgraph", callgraph);
	register_analysis ("constants", constants);
	register_analysis ("def-use", def_use);
	register_analysis ("values", values);
//	register_analysis ("Include_analysis", include_analysis);
//	register_analysis ("VRP", vrp);


	/*
	 * Set up this iteration:
	 */

	FWPA->init (outer_cx);

	init_stacks ();

	// This will be here for a while.
	create_empty_storage (outer_cx, "array", "FAKE");
}

void
Whole_program::analyse_function (User_method_info* info, Context* caller_cx, MIR::Actual_parameter_list* actuals, MIR::VARIABLE_NAME* lhs)
{
	CFG* cfg = info->get_cfg ();

	// This is very similar to run() from Sparse_conditional_visitor, except
	// that it isnt sparse.

	if (debugging_enabled)
		cfg->dump_graphviz (s("Function entry"));

	// 1. Initialize:
	Worklist wl;
	wl.add (cfg->get_entry_edge ());

	// Process the entry blocks first (there is no edge here)
	DEBUG ("Initing functions");
	Context* entry_cx = Context::contextual (caller_cx, cfg->get_entry_bb ());
	forward_bind (
		info,
		entry_cx,
		actuals);


	// 2. Stop when CFG-worklist is empty
	while (wl.size () > 0)
	{
		Edge* e = wl.next ();
		DEBUG (wl.size() << " edges in the worklist");

		Basic_block* target = e->get_target ();
		Context* target_cx = Context::contextual (caller_cx, target);

		BB_list* preds = new BB_list;

		Edge_list* pred_edges = target->get_predecessor_edges ();
		foreach (Edge* pred_edge, *pred_edges)
		{
			// Ignore non-executable edges
			if (wl.is_executable (pred_edge))
				preds->push_back (pred_edge->get_source ());
		}

		// Merge results from predecessors
		pull_results (target_cx, preds);



		// Analyse the block, storing per-basic-block results.
		// This does not update the block's structure.
		bool changed = analyse_block (target_cx);

		// Add next	block(s) if the result has changed, or if this the first
		// time the edge could be executed.
		foreach (Edge* next, *get_successors (target_cx))
			if (!wl.is_executable (next) || changed)
				wl.add (next);
	}

	backward_bind (
		info,
		Context::contextual (caller_cx, cfg->get_exit_bb ()),
		lhs);
}

Edge_list*
Whole_program::get_successors (Context* cx)
{
	Edge_list* result = new Edge_list;

	Basic_block* bb = cx->get_bb ();

	if (Branch_block* branch = dynamic_cast<Branch_block*> (bb))
	{
		Index_node* cond = VN (cx->symtable_name (), branch->branch->variable_name);

		Abstract_value* absval = get_abstract_value (cx, R_WORKING, cond->name ());

		if (not absval->known_true ())
			result->push_back (branch->get_false_successor_edge ());

		if (not absval->known_false ())
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
Whole_program::get_possible_receivers (Context* cx, Result_state state, Method_invocation* in)
{
	return get_possible_receivers (cx, state, in->target, in->method_name);
}

Method_info_list*
Whole_program::get_possible_receivers (Context* cx, Result_state state, Param_is_ref* in)
{
	return get_possible_receivers (cx, state, in->target, in->method_name);
}

Method_info_list*
Whole_program::get_possible_receivers (Context* cx, Result_state state, Target* target, Method_name* method_name)
{
	Method_info_list* result = new Method_info_list;

	if (isa<Variable_method> (method_name))
		phc_TODO ();

	String* name = dyc<METHOD_NAME> (method_name)->value;

	// If there is a target or a variable_method, there may be > 1 methods that
	// match it.
	if (target)
	{
		String_list* classnames = new String_list;
		if (CLASS_NAME* classname = dynamic_cast<CLASS_NAME*> (target))
		{
			classnames->push_back (classname->value);
		}
		else
		{
			VARIABLE_NAME* obj = dyc<VARIABLE_NAME> (target);
			Types* types = values->get_types (cx, state, VN (cx->symtable_name (), obj)->name());

			// Wrap them
			foreach (string type, *types)
				classnames->push_back (s (type));
		}

		foreach (String* type, *classnames)
		{
			Class_info* classinfo = Oracle::get_class_info (type);

			// If this returns NULL, then its type doesn't represent a class,
			// therefore a run-time error will occur. So we can pretend this isnt
			// a receiver. (We shouldn't issue a warning, since this path might
			// not be realizable in practice).
			if (classinfo == NULL)
				continue;

			Method_info* info = classinfo->get_method_info (name);
			if (info == NULL)
				phc_TODO (); // Method doesnt exist, try __call

			result->push_back (info);
		}

	}
	else
	{
		// This assumes there is only 1 function of that name, which is true. If
		// there are multiple versions, they are lowered to different names before
		// MIR.
		Method_info* info = Oracle::get_method_info (name);
		result->push_back (info);
	}


	assert (result->size () > 0);

	return result;	
}

// New is slightly different, since it's Class_name is not the same as
// Method_invocation's target. Also, it must search for both __construct and
// the old style constructor.
Method_info_list*
Whole_program::get_possible_receivers (Context* cx, Result_state state, New* in)
{
	if (isa<Variable_class> (in->class_name))
		phc_TODO ();

	CLASS_NAME* class_name = dyc<CLASS_NAME> (in->class_name);

	Class_info* class_info = Oracle::get_class_info (class_name->value);

	// Find the constructor
	Method_info* constructor = class_info->get_method_info (s("__construct"), false);

	// Look for the old-style constructor
	if (constructor == NULL)
		constructor = class_info->get_method_info (class_name->value, false);

	if (constructor)
		return new Method_info_list (constructor);
	else
		return new Method_info_list ();
}



void
Whole_program::instantiate_object (Context* caller_cx, MIR::VARIABLE_NAME* self, New* in)
{
	Method_info_list* receivers = get_possible_receivers (caller_cx, R_WORKING, in);

	// Get the classes (there might not be receivers, even when there are classes)
	if (isa<Variable_class> (in->class_name))
		phc_TODO ();

	CLASS_NAME* class_name = dyc<CLASS_NAME> (in->class_name);

	// Allocate memory
	string obj = assign_path_empty_object (block_cx (), saved_plhs (), *class_name->value, ANON);


	// Assign members
	Class_info* class_info = Oracle::get_class_info (class_name->value);
	foreach (Attribute* attr, *class_info->get_attributes ())
	{
		assign_attribute (block_cx (), obj, attr);
	}


	// If there isn't a constructor, ignore it.
	if (receivers->size ())
	{
		invoke_method (
				caller_cx,
				NULL,
				self,
				receivers,
				in->actual_parameters);
	}
}

void
Whole_program::assign_attribute (Context* cx, string obj, MIR::Attribute* attr)
{
	// Although obj is just allocated, it may be abstract.
	if (not isa<Literal> (attr->var->default_value))
		phc_TODO ();

	assign_path_scalar (cx, P (obj, attr->var->variable_name), dyc<Literal> (attr->var->default_value));
}


void
Whole_program::invoke_method (Context* caller_cx, MIR::VARIABLE_NAME* lhs, MIR::Method_invocation* in)
{
	invoke_method (
		caller_cx,
		lhs,
		dynamic_cast<VARIABLE_NAME*> (in->target),
		get_possible_receivers (caller_cx, R_WORKING, in),
		in->actual_parameters);
}

void
Whole_program::invoke_method (Context* caller_cx, VARIABLE_NAME* lhs, VARIABLE_NAME* target, Method_info_list* receivers, Actual_parameter_list* params)
{
	// Make $this explicit, if necessary.
	if (target)
	{
		params = params->clone ();
		params->push_front (new Actual_parameter (false, target));
	}

	// Need to clone the information and merge it when it returns.
	if (receivers->size () != 1)
		phc_TODO ();

	
	FWPA->pre_invoke_method (caller_cx);

	foreach (Method_info* receiver, *receivers)
	{
		analyse_method_info (receiver, caller_cx, params, lhs);
	}

	FWPA->post_invoke_method (caller_cx);
}


void
Whole_program::analyse_method_info (Method_info* method_info,
												Context* caller_cx,
												MIR::Actual_parameter_list* actuals,
												MIR::VARIABLE_NAME* lhs)
{
	if (method_info->has_implementation ())
	{
		analyse_function (dyc<User_method_info> (method_info), caller_cx, actuals, lhs);
	}
	else
	{
		// Get as precise information as is possible with pre-baked summary
		// information.
		analyse_summary (dyc<Summary_method_info> (method_info), caller_cx, actuals, lhs);
	}
}

void
Whole_program::analyse_summary (Summary_method_info* info, Context* caller_cx, Actual_parameter_list* actuals, VARIABLE_NAME* lhs)
{
	CFG* cfg = info->get_cfg ();

	/*
	 * Start the analysis (init_ and finish_block are done in forward_bind)
	 */
	Context* entry_cx = Context::contextual (caller_cx, cfg->get_entry_bb ());
	forward_bind (info, entry_cx, actuals);

	dump (entry_cx, R_OUT, "Upon summary entry (" + *caller_cx->get_bb()->get_graphviz_label () + ")");


	/*
	 * "Perform" the function
	 */

	Context* fake_cx = Context::contextual (caller_cx, info->get_fake_bb ());

	init_block (fake_cx);

	pull_results (fake_cx, info->get_fake_bb ()->get_predecessors ());

	apply_modelled_function (info, fake_cx, caller_cx);

	finish_block (fake_cx);

	dump (fake_cx, R_OUT, "After fake basic block (" + *caller_cx->get_bb()->get_graphviz_label () + ")");

	phc_pause ();



	/*
	 * Backward bind
	 */

	Context* exit_cx = Context::contextual (caller_cx, cfg->get_exit_bb ());

	init_block (exit_cx);

	pull_results (exit_cx, cfg->get_exit_bb ()->get_predecessors ());

	finish_block (exit_cx);

	// TODO: we only really need 2 blocks here.
	dump (exit_cx, R_OUT, "After summary method (" + *caller_cx->get_bb()->get_graphviz_label () + ")");

	phc_pause ();


	backward_bind (info, exit_cx, lhs);
}

// BB is the block representing the whole method
void
Whole_program::apply_modelled_function (Summary_method_info* info, Context* cx, Context* caller_cx)
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

	// It seems I should use a Vector, but I really would like to access this
	// without having initialized it (and get NULL).
	Map<int, Index_node*> params; 

	string symtable = cx->symtable_name ();
	for (int i = 0; ; i++) // NOTE: lack of cond in loop
	{
		Index_node* param = IN (symtable, *UNNAMED (i));

		// There are two ways to know there is a parameter:
		//		- an actual parameter is passed
		//		- there are formal parameters. 
		if (not aliasing->has_field (cx, R_WORKING, param)
			&& i >= info->formal_param_count ()) // (yes, &&)
			break;


		params[i] = param;
		record_use (cx, param); // use parameters
	}

	Path* ret_path = P (symtable, new VARIABLE_NAME (RETNAME));
	if (false)
	{
		// so that everything else is else-if
	}
	else if (*info->name == "array_push")
	{
		Assign_next* sim = new Assign_next (
				new VARIABLE_NAME (UNNAMED (0)),
				saved_is_ref (),
				new VARIABLE_NAME (UNNAMED (1)));

		visit_assign_next (reinterpret_cast<Statement_block*> (cx->get_bb ()), sim);

		// We may learn to count later
		assign_path_typed (cx, ret_path, new Types ("int"));
	}
	else if (*info->name == "compact")
	{
		// Return an array with a copy of the named parameters.
		string name = assign_path_empty_array (cx, ret_path, ANON);
		foreach (Index_node* param, *params.values ()) // reading
		{
			// For a parameter P1, in this scope SC1, with the caller scope SC0, this is:
			// (ARR -> (SC1 -> P1)) = (SC0 -> (SC1 -> P1))
			Path* lhs = new Indexing (new ST_path (name), P (param->storage, param->index));
			Path* rhs = new Indexing (new ST_path (caller_cx->symtable_name ()), P (param->storage, param->index));
			assign_path_by_copy (cx, lhs, rhs);
		}
	}
	else if (*info->name == "count")
	{
		// TODO: If the parameter is an object, then count can call the interface countable.
		assign_path_typed (cx, ret_path, new Types ("int"));
	}
	else if (*info->name == "date_default_timezone_set")
	{
		coerce_to_string (cx, params[0]);
		assign_path_typed (cx, ret_path, new Types ("bool"));
	}
	else if (*info->name == "debug_zval_dump")
	{
		assign_path_typed (cx, ret_path, new Types ("unset"));
	}
	else if (*info->name == "dechex")
	{
		assign_path_typed (cx, ret_path, new Types ("string"));
	}
	else if (*info->name == "die")
	{
		// TODO: We'd like to model that this path is not executable.
		// do nothing
		// We don't even need to coerce to string, since this path isn't
		// realizable.
	}
	else if (*info->name == "define")
	{
		// Read parameters
		params[0] = coerce_to_string (cx, params[0]);
		Abstract_value* name = get_abstract_value (cx, R_WORKING, params[0]->name ());
		Abstract_value* value = get_abstract_value (cx, R_WORKING, params[1]->name ());
		if (params[3])
			phc_TODO (); // case-insensitive


		if (name->lit == NULL)
		{
			// We dont know if this was redefined or not
			constants->set_unknown_constant (cx, value);
			assign_path_typed (cx, ret_path, new Types ("bool"));
		}
		else
		{
			String* str_name = PHP::get_string_value (name->lit);
			if (constants->is_constant_defined (cx, R_WORKING, *str_name))
			{
				// If its already defined, it cant be redefined
				assign_path_scalar (cx, ret_path, new BOOL (false));
			}
			else
			{
				assign_path_scalar (cx, ret_path, new BOOL (true));
				constants->set_constant (cx, *str_name, value);
			}
		}
	}
	else if (*info->name == "defined")
	{
		params[0] = coerce_to_string (cx, params[0]);

		// TODO: We don't correctly identify is a constant is actually defined.
		assign_path_typed (cx, ret_path, new Types ("bool"));
	}
	else if (*info->name == "empty")
	{
		// TODO: If we modelled POSSIBLY/DEFINITELY on field edges, we'd be able
		// to optimize this.
		assign_path_typed (cx, ret_path, new Types ("bool"));
	}
	else if (*info->name == "explode")
	{
		params[0] = coerce_to_string (cx, params[0]);
		params[1] = coerce_to_string (cx, params[1]);

		assign_path_typed_array (cx, ret_path, new Types ("string"), ANON);
	}
	else if (*info->name == "exit")
	{
		// TODO: see comment in 'die'
		// do nothing
	}
	else if (*info->name == "error_reporting")
	{
		assign_path_typed (cx, ret_path, new Types ("int"));
	}
	else if (*info->name == "file_get_contents")
	{
		params[0] = coerce_to_string (cx, params[0]);

		// string or false
		assign_path_typed (cx, ret_path, new Types ("string", "bool"));
	}
	else if (*info->name == "flush")
	{
		// do nothing
	}
	else if (*info->name == "get_declared_classes")
	{
		// Return an array of strings
		assign_path_typed_array (cx, ret_path, new Types ("string"), ANON);
	}
	else if (*info->name == "get_parent_class")
	{
		assign_path_typed (cx, ret_path, new Types ("string" ,"bool"));
	}
	else if (*info->name == "gettimeofday")
	{
		// TODO handle better
		bool can_be_float = true;
		bool can_be_array = true;

		if (aliasing->has_field (cx, R_WORKING, params[0])) // TODO: just use params[0]?
		{
			Abstract_value* absval = get_abstract_value (cx, R_WORKING, params[0]->name());

			if (absval->known_true ())
				can_be_array = false;

			else if (absval->known_false ())
				can_be_float = false;
		}
		else
		{
			can_be_float = false;
		}

		// How to do both?
		if (can_be_float && can_be_array)
			phc_TODO ();

		// it cant be neither
		assert (can_be_float || can_be_array);
	
		if (can_be_float)
			assign_path_typed (cx, ret_path, new Types ("real"));
		else if (can_be_array)
		{
			// Cut-and-pasted: but this all needs to be fixed. We need to call this from 

			// If there its parameter is true, it returns a float. Else, if returns a
			// hashtable with 4 ints: sec, usec, minuteswest, dsttime
			string name = assign_path_empty_array (cx, ret_path, ANON);

			assign_path_typed (cx, P (name, "sec"), new Types ("int"));
			assign_path_typed (cx, P (name, "usec"), new Types ("int"));
			assign_path_typed (cx, P (name, "minuteswest"), new Types ("int"));
			assign_path_typed (cx, P (name, "dsttime"), new Types ("int"));

		}
	}
	else if (*info->name == "getrandmax")
	{
		// Really, this is a pure function with on parameters. This should be inlined.
		assign_path_typed (cx, ret_path, new Types ("int"));
	}
	else if (*info->name == "in_array")
	{
		assign_path_typed (cx, ret_path, new Types ("bool"));
	}
	else if (*info->name == "is_array")
	{
		Abstract_value* absval = get_abstract_value (cx, R_WORKING, params[0]->name());

		// If the array type is the only type, this is true.
		if (*absval->types == Types ("array"))
		{
			assign_path_scalar (cx, ret_path, new BOOL (true));
		}
		else if (Type_info::get_array_types (absval->types)->size () == 0)
		{
			assign_path_scalar (cx, ret_path, new BOOL (false));
		}
		else
		{
			assign_path_typed (cx, ret_path, new Types ("bool"));
		}
	}
	else if (*info->name == "is_object")
	{
		Abstract_value* absval = get_abstract_value (cx, R_WORKING, params[0]->name());
		bool all_objects = true;
		bool no_objects = true;
		foreach  (string type, *absval->types)
		{
			if (type == "array" || Type_info::is_scalar (type))
				all_objects = false;
			else
				no_objects = false;
		}

		if (all_objects)
		{
			assign_path_scalar (cx, ret_path, new BOOL (true));
		}
		else if (no_objects)
		{
			assign_path_scalar (cx, ret_path, new BOOL (false));
		}
		else
		{
			assign_path_typed (cx, ret_path, new Types ("bool"));
		}
	}
	// max: see min
	else if (*info->name == "min" || *info->name == "max")
	{
		Abstract_value* absval = get_abstract_value (cx, R_WORKING, params[0]->name());
		if (absval->types->has ("array"))
			phc_TODO ();


		Types* result = new Types;
		foreach (Index_node* param, *params.values ())
		{
			Abstract_value* absval = get_abstract_value (cx, R_WORKING, param->name());

			// Can only return scalars (um, probably).
			result = result->set_union (Type_info::get_scalar_types (absval->types));
		}

		assign_path_typed (cx, ret_path, result);
	}
	else if (*info->name == "number_format")
	{
		params[2] = coerce_to_string (cx, params[2]);
		params[3] = coerce_to_string (cx, params[3]);
		assign_path_typed (cx, ret_path, new Types ("string"));
	}
	else if (*info->name == "ob_end_clean")
	{
		assign_path_typed (cx, ret_path, new Types ("bool"));
	}
	else if (*info->name == "ob_start")
	{
		if (params[0])
			phc_TODO (); // If first parameter is set, thats a callback.
		
		assign_path_typed (cx, ret_path, new Types ("bool"));
	}
	else if (*info->name == "print")
	{
		params[0] = coerce_to_string (cx, params[0]);
		assign_path_scalar (cx, ret_path, new INT (1));
	}
	else if (*info->name == "printf")
	{
		params[0] = coerce_to_string (cx, params[0]);
		assign_path_typed (cx, ret_path, new Types ("int"));
	}
	else if (*info->name == "rand")
	{
		assign_path_typed (cx, ret_path, new Types ("int"));
	}
	else if (*info->name == "range")
	{
		// Returns an array with a range of values of the given type.
		Abstract_value* absval0 = get_abstract_value (cx, R_WORKING, params[0]->name());
		Abstract_value* absval1 = get_abstract_value (cx, R_WORKING, params[1]->name());
		Types* merged = absval0->types->set_union (absval1->types);

		assign_path_typed_array (cx, ret_path, merged, ANON);
	}
	else if (*info->name == "readdir")
	{
		// string or false
		assign_path_typed (cx, ret_path, new Types ("string", "bool"));
	}
	else if (*info->name == "shell_exec")
	{
		params[0] = coerce_to_string (cx, params[0]);
		assign_path_typed (cx, ret_path, new Types ("string"));
	}
	else if (*info->name == "srand")
	{
		// do nothing
	}
	else if (*info->name == "strlen")
	{
		// TODO: we can tell the length
		params[0] = coerce_to_string (cx, params[0]);
		assign_path_typed (cx, ret_path, new Types ("int"));
	}
	else if (*info->name == "str_repeat")
	{
		params[0] = coerce_to_string (cx, params[0]);
		assign_path_typed (cx, ret_path, new Types ("string"));
	}
	else if (*info->name == "trigger_error")
	{
		params[0] = coerce_to_string (cx, params[0]);
		assign_path_typed (cx, ret_path, new Types ("bool"));
	}
	else if (*info->name == "var_dump")
	{
		// do nothing
	}
	else if (*info->name == "var_export")
	{
		// Return string or NULL depending on true/false.
		Abstract_value* absval1 = get_abstract_value (cx, R_WORKING, params[1]->name());

		Types* types = new Types;
		if (not absval1->known_false ())
			types->insert ("string");

		if (not absval1->known_true())
			types->insert ("unset");

		assign_path_typed (cx, ret_path, types);
	}
	else
	{
		cdebug << *info->name << " not modelled" << endl;
		phc_TODO ();
	}
}

void
Whole_program::apply_results (User_method_info* info)
{
	// Since we use information from lots of sources, and we need this
	// information for tons of differernt optimizations, its best to have a
	// single transformer applying the results.
	foreach (Basic_block* bb, *info->get_cfg ()->get_all_bbs ())
	{
		// TODO: I should probably use CCP results here to optimize branches.
		if (Statement_block* sb = dynamic_cast<Statement_block*> (bb))
		{
			Statement* old = sb->statement->clone ();

			transformer->visit_block (bb);

			if (sb->statement->equals (old))
				DEBUG ("No changes in BB: " << bb->ID);
			else
			{
				DEBUG ("BB " << bb->ID << " changed");
				CTS ("num_bbs_changed_in_opt_trans");
			}	
		}
		else if (isa<Branch_block> (bb))
		{
			transformer->visit_block (bb);
		}
	}
	info->get_cfg ()->clean ();

	if (debugging_enabled)
		info->get_cfg ()->dump_graphviz (s("Apply results"));
}

void
Whole_program::annotate_results (User_method_info* info)
{
	// Since we use information from lots of sources, and we need this
	// information for tons of different annotations, its best to have a
	// single annotator applying the results.
	foreach (Basic_block* bb, *info->get_cfg ()->get_all_bbs ())
		annotator->visit_block (bb);
}

void
Whole_program::collect_stats (User_method_info* info)
{
	if (pm->args_info->stats_given)
	{
		foreach (Basic_block* bb, *info->get_cfg ()->get_all_bbs ())
			stat_coll->visit_block (bb);
		
	}
}

void
Whole_program::perform_local_optimizations (User_method_info* info)
{
	pm->run_local_optimization_passes (this, info->get_cfg ());

	pm->maybe_enable_debug (s("wpa"));
}

void
Whole_program::perform_interprocedural_optimizations (User_method_info* info)
{
	pm->run_ipa_passes (this, info->get_cfg ());

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
	if (info->get_cfg ()->get_all_bbs ()->size() == 2)
		info->set_side_effecting (true);
}

void
Whole_program::merge_contexts ()
{
	FWPA->merge_contexts ();
}


/*
 * If these segfault, its more likely a bug in the analysis than a requirement
 * for a check on the size of the stack.
 */
int
Whole_program::unique_count ()
{
	return unique_counts.top ()++;
}

Context*
Whole_program::block_cx ()
{
	return block_cxs.top ();
}

Path*
Whole_program::saved_plhs ()
{
	return saved_plhss.top ();
}

MIR::VARIABLE_NAME*
Whole_program::saved_lhs ()
{
	return saved_lhss.top ();
}

bool
Whole_program::saved_is_ref ()
{
	return saved_is_refs.top ();
}

/* 
 * There are 2 reasons why we need this:
 *		- some stacks may need to be accessed even if they are empty:
 *			- visiting an eval_expr may need to look at the saved_is_ref, even in the global scope.
 *		- in the outer scope, we still need to use unique_counts
 */
void
Whole_program::init_stacks ()
{
	/* TODO: before I forget, what if we have an eval expr in a method invoked
	 * by an assign_var? we dont want to use the assign_var's result! It should
	 * instead be stored in a local variable (ie the old waya -- except thats
	 * not good enough to solve this either!!!)
	 */
	block_cxs.push (NULL);
	unique_counts.push (0);
	saved_is_refs.push (false);
	saved_lhss.push (NULL);
	saved_plhss.push (NULL);
}

void
Whole_program::finish_stacks ()
{
	assert (block_cxs.size () == 1);
	assert (unique_counts.size () == 1); // added in ::initialize ();
	assert (saved_is_refs.size () == 1);
	assert (saved_lhss.size () == 1);
	assert (saved_plhss.size () == 1);

	block_cxs.pop ();
	unique_counts.pop ();
	saved_is_refs.pop ();
	saved_lhss.pop ();
	saved_plhss.pop ();
}


void
Whole_program::init_block (Context* cx)
{
	block_cxs.push (cx);
	unique_counts.push (0);

	// Blocks which arent assign_var need to see correct results here.
	saved_is_refs.push (false);
	saved_lhss.push (NULL);
	saved_plhss.push (NULL);

	// We need to remove these to make the results converge.
	if (aliasing->ins.has (cx))
		destroy_fake_indices (cx);
}



void
Whole_program::finish_block (Context* cx, bool pop)
{
	// We need to remove these to make the results converge.
	destroy_fake_indices (cx);

	FWPA->finish_block (cx);

	if (pop)
	{
		unique_counts.pop ();
		block_cxs.pop ();
		saved_is_refs.pop ();
		saved_lhss.pop ();
		saved_plhss.pop ();
	}
}

bool
Whole_program::analyse_block (Context* cx)
{
	DEBUG ("\nAnalysing BB: " << cx << ": " << *cx->get_bb()->get_graphviz_label ());

	init_block (cx);

	visit_block (cx->get_bb());

	finish_block (cx);

	dump (cx, R_OUT, "After analysis (" + *cx->get_bb()->get_graphviz_label () + ")");

	// Calculate fix-point
	bool changed = false;
	foreach_wpa (this)
	{
		bool new_changed = wpa->solution_changed (cx);
		if (new_changed)
		{
			DEBUG (cx << " has changed (" << wpa->name << ")");
		}

		changed |= new_changed;
	}

	phc_pause ();

	return changed;
}

/*
 * Given a list of points_to graphs, return the list of index_nodes which
 * might be NULL. An index node is in this set if the its storage node exists
 * in a graph in which it does not appear.
 * It may also be NULL if it references NULL in any of the graphs.
 */
Index_node_list*
Whole_program::get_possible_nulls (Context_list* cxs)
{
	Index_node_list* norefs = new Index_node_list;

	Set<Alias_name> existing;

	// Get the nodes which exist in some graph, but do not exist in other graphs.
	foreach (Context* cx, *cxs)
	{
		foreach (Storage_node* st, *aliasing->get_storage_nodes (cx, R_OUT))
		{
			foreach (Index_node* index, *aliasing->get_fields (cx, R_OUT, st))
			{
				// Check all the other graphs
				foreach (Context* other, *cxs)
				{
					if (cx == other)
						continue;

					if (aliasing->has_storage_node (cx, R_OUT, st)
						&& !aliasing->has_field (other, R_OUT, index))
					{
						// Add it
						if (!existing.has (index->name()))
						{
							existing.insert (index->name ());
							norefs->push_back (index);
						}
					}
				}
			}
		}
	}

	// So far we've got nodes which exist in only one graph. But what about
	// their references. Well, if the references only exist in one graph,
	// they'll get NULL too. Otherwise, they have their own value in the other
	// graph, which means NULL isnt possible for them on any path.
	return norefs;
}




void
Whole_program::pull_results (Context* cx, BB_list* bb_preds)
{
	Context_list* preds = new Context_list;

	foreach (Basic_block* bb, *bb_preds)
		preds->push_back (Context::as_peer (cx, bb));


	// Some index nodes may only have existed on one path. If their storage
	// node exists, then we assume that they are NULL on the other paths.
	Index_node_list* possible_nulls = this->get_possible_nulls (preds);

	// Separate the first from the remainder, to simplfiy the remainder.
	Context* first = preds->front ();
	preds->pop_front ();


	// Actually pull the results
	FWPA->pull_init (cx);
	FWPA->pull_first_pred (cx, first);

	foreach (Context* pred, *preds)
		FWPA->pull_pred (cx, pred);

	// Use possible NULLs
	foreach (Index_node* index, *possible_nulls)
		FWPA->pull_possible_null (cx, index);

	FWPA->pull_finish (cx);
}

void
Whole_program::dump (Context* cx, Result_state state, string comment)
{
	bool saved = debugging_enabled;
	foreach_wpa (this)
	{
		// This isnt the greatest means of debugging.
		pm->maybe_enable_debug (s(wpa->name));

		if (!debugging_enabled)
			continue;

		DEBUG (cx << " (" << comment << "): Dumping " << wpa->name);

		if (cx->empty ())
			wpa->dump_everything (comment);
		else
			wpa->dump (cx, state, comment);

		cdebug << endl;
	}
	debugging_enabled = saved;
}


/*
 * Analysis from here on in
 */

void
Whole_program::init_superglobals (Context* cx)
{
	// TODO: Strictly speaking, functions other than __MAIN__ should have their
	// globals set up before the parameters are copied. However, we'll ignore
	// this minor bug since its broken elsewhere in the compiler.

	// TODO: add HTTP_*
	
	// TODO: we incorrectly mark _SERVER as being an array of strings.
	// However, it actually has "argc", "argv" and "REQUEST_TIME" set, which
	// are not strings.
	

	// Start with globals, since it needs needs to point to MSN
	string MSN = cx->symtable_name ();
	FWPA->assign_value (cx, VN (MSN, new VARIABLE_NAME ("GLOBALS")), SN (MSN));


	// Do the other superglobals
	foreach (VARIABLE_NAME* sg, *PHP::get_superglobals ())
	{
		break; // simplify graph

		if (*sg->value == "GLOBALS")
			continue;

		// Create an array of strings
		assign_path_typed_array (cx, P (MSN, sg), new Types ("string"), *sg->value);
	}


	// We actually have no idea whats in _SESSION
	assign_path_unknown (cx, P ("_SESSION", UNKNOWN));

	// argc
	assign_path_typed (cx, P (MSN, "argc"), new Types ("int"));

	// argv
	assign_path_typed_array (cx, P (MSN, "argv"), new Types ("string"), "argv");
	assign_path_typed (cx,  P ("argv", "0"), new Types ("string"));


	dump (cx, R_WORKING, "After superglobals");
}

void
Whole_program::forward_bind (Method_info* info, Context* entry_cx, MIR::Actual_parameter_list* actuals)
{
	Context* caller_cx = entry_cx->caller ();

	init_block (entry_cx);

	// Initialize the analyses
	FWPA->forward_bind (caller_cx, entry_cx);


	// Create the symbol table.
	string scope = entry_cx->symtable_name ();
	create_empty_storage (entry_cx, "array", scope);


	// Special case for __MAIN__. We do it here so that the other analyses
	// have initialized.
	if (caller_cx->is_outer ())
	{
		main_scope = scope;
		init_superglobals (entry_cx);
	}


	/*
	 * Handle the parameters
	 */

	int i = 0;
	foreach (Actual_parameter* ap, *actuals)
	{
		// Actual parameters
		if (ap->is_ref || info->param_by_ref (i))
		{
			// $ap =& $fp;
			assign_path_by_ref (entry_cx,
					P (scope, info->param_name (i)),
					P (caller_cx->symtable_name (), dyc<VARIABLE_NAME> (ap->rvalue)));
		}
		else
		{
			// $ap = $fp;
			if (isa<VARIABLE_NAME> (ap->rvalue))
			{
				assign_path_by_copy (entry_cx,
						P (scope, info->param_name (i)),
						P (caller_cx->symtable_name (), dyc<VARIABLE_NAME> (ap->rvalue)));
			}
			else
			{
				assign_path_scalar (entry_cx,
						P (scope, info->param_name (i)),
						dyc<Literal> (ap->rvalue));
			}
		}

		i++;
	}

	// Assign other parameters.
	if (i < info->formal_param_count ())
	{
		Static_value* _default = info->default_param (i);
		if (_default)
		{
			if (not isa<Literal> (_default))
				phc_TODO ();

			assign_path_scalar (entry_cx, P (scope, info->param_name (i)), dyc<Literal> (_default));
		}
		else
		{
			// Add a default value of NULL for other variables
			assign_path_scalar (entry_cx, P (scope, info->param_name (i)), new NIL);
		}

		i++;
	}


	finish_block (entry_cx);

	dump (entry_cx, R_OUT, "After forward_bind");
}


void
Whole_program::backward_bind (Method_info* info, Context* exit_cx, MIR::VARIABLE_NAME* lhs)
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

	Context* caller_cx = exit_cx->caller ();
	if (lhs)
	{
		// TODO: take into account saved_by_ref ()
		if (info->return_by_ref ())
		{
			// $lhs =& $retval;
			assign_path_by_ref (exit_cx,
					P (caller_cx->symtable_name (), dyc<VARIABLE_NAME> (lhs)),
					P (exit_cx->symtable_name (), new VARIABLE_NAME (RETNAME)));
		}
		else
		{
			// $lhs = $retval;
			assign_path_by_copy (exit_cx,
					P (caller_cx->symtable_name (), dyc<VARIABLE_NAME> (lhs)),
					P (exit_cx->symtable_name (), new VARIABLE_NAME (RETNAME)));
		}

		// We need to allow 2 calls to finish_block because of this.
		finish_block (exit_cx, false);
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

	dump (exit_cx, R_OUT, "After assignment, before WPA backward bind");

	FWPA->backward_bind (caller_cx, exit_cx);

	dump (caller_cx, R_POST_BIND, "After backward bind");

	// Its useful to see the CFG we've fallen back into
	if (debugging_enabled && caller_cx->get_bb()->cfg)
		caller_cx->get_bb()->cfg->dump_graphviz (s("Back into function"));
}

/*
 * Index nodes are killable under the following conditions:
 * 1.) the name only refers to one node.
 *	2.) fields of abstract storage node are not killable
 *	4.) its name is not UNKNOWN.
 */
bool
Whole_program::is_killable (Context* cx, Index_node_list* indices)
{
	// Allow it to be turned off at the command-line.
	if (pm->args_info->flow_insensitive_flag)
		return false;

	if (indices->size () > 1)
		return false;

	Index_node* index = indices->front ();
	
	if (aliasing->is_abstract_field (cx, R_WORKING, index))
		return false;

	if (index->index == UNKNOWN)
		return false;

	return true;
}

void
Whole_program::refer_to_value (Context* cx, Index_node* lhs, Index_node* rhs, Certainty cert)
{
	// Create the references
	foreach (Storage_node* st, *aliasing->get_points_to (cx, R_WORKING, rhs))
	{
		if (isa<Value_node> (st))
			assign_absval (cx, lhs, get_abstract_value (cx, R_WORKING, st->name ()));
		else
			// Make L point to the value (not a deep copy, under any circumstances).
			FWPA->assign_value (cx, lhs, st);
	}


	// We've copied all the values (transitive-closure), but we also
	// want to keep the references in transitive-closure form.
	//
	// Note that we aren't required to do unification, even though the
	// edges are bidirectional. It may be that A may-ref B and A may-ref
	// C, but B does not may-ref C. An example is after CFG merges.
	foreach (Reference* ref, *aliasing->get_references (cx, R_WORKING, rhs, PTG_ALL))
		FWPA->create_reference (cx, lhs, ref->index, combine_certs (cert, ref->cert));


	// Create the reference
	FWPA->create_reference (cx, lhs, rhs, cert);

}

void
Whole_program::assign_path_by_ref (Context* cx, Path* plhs, Path* prhs, bool allow_kill)
{
	DEBUG ("assign_path_by_ref");

	/* For each index node L on the lhs, and R on the rhs:
	 * - A reference kills L
	 *   - but only if L refers to only 1 node (and other standard rules).
	 *
	 * - L and R should have reference edges added
	 *   - must-edges if only 1 L and 1 R
	 *   - otherwise may-edges
	 *
	 * - L gets R's values
	 *   - L's absval copies R's absval's value
	 *   - L points to all that R points to
	 */


	Index_node* fake = create_fake_index (cx);

	// Get the Rvalues
	Index_node_list* rhss = get_named_indices (cx, prhs);
	bool rhs_killable = is_killable (cx, rhss) && allow_kill;


	// Get the lvalues (best to get them early, in case they get changed by the
	// new references to the rvalues)
	Index_node_list* lhss = get_named_indices (cx, plhs);
	bool lhs_killable = is_killable (cx, lhss) && allow_kill;


	// Work out the certainty for the edges.
	Certainty cert = POSSIBLE;
 	if (rhs_killable && lhs_killable)
 		cert = DEFINITE;


	// Create the references in FAKE from RHS
	foreach (Index_node* rhs, *rhss)
	{
		rhs = check_owner_type (cx, rhs, rhs_killable ? DEFINITE : POSSIBLE);

		if (not aliasing->has_field (cx, R_WORKING, rhs))
		{
			// Check if there is an implicit definition (for which we need the value from UNKNOWN).
			copy_value (cx, rhs, new Index_node (rhs->storage, UNKNOWN));
		}

		refer_to_value (cx, fake, rhs, cert);
	}



	if (lhs_killable)
	{
		// We don't kill its references (but we do kill the reference edges)
		FWPA->kill_value (cx, lhss->front (), true);
	}

	foreach (Index_node* lhs, *lhss)
	{
		refer_to_value (cx, lhs, fake, cert);
	}
}

void
Whole_program::assign_path_scalar (Context* cx, Path* plhs, Abstract_value* absval, bool allow_kill)
{
	DEBUG ("assign_path_scalar");
	foreach (Reference* ref, *get_lhs_references (cx, plhs))
	{
		if (ref->cert == DEFINITE && allow_kill)
		{
			FWPA->kill_value (cx, ref->index);
		}

		assign_absval (cx, ref->index, absval);
	}
}

void
Whole_program::assign_path_scalar (Context* cx, Path* plhs, Literal* lit, bool allow_kill)
{
	assign_path_scalar (cx, plhs, new Abstract_value (lit), allow_kill);
}

void
Whole_program::assign_path_typed (Context* cx, Path* plhs, Types* types, bool allow_kill)
{
	DEBUG ("assign_path_typed");

	// Split scalars, objects and arrays here.
	Types* scalars = Type_info::get_scalar_types (types);
	Types* array = Type_info::get_array_types (types);
	Types* objects = Type_info::get_object_types (types);

	// TODO: what is going on here?

	// In these cases, we must copy to an intermediate value before the kill.
	if (array->size ())
		phc_TODO ();

	if (objects->size ())
		phc_TODO ();

	assign_path_scalar (cx, plhs, new Abstract_value (types), allow_kill);
}

void
Whole_program::assign_path_value (Context* cx, Path* plhs, Storage_node* st, bool allow_kill)
{
	DEBUG ("assign_path_value");

	// Assign the value to all referenced names.
	foreach (Reference* ref, *get_lhs_references (cx, plhs))
	{
		if (ref->cert == DEFINITE && allow_kill)
		{
			FWPA->kill_value (cx, ref->index);
		}

		FWPA->assign_value (cx, ref->index, st);
	}
}

string
Whole_program::assign_path_empty_array (Context* cx, Path* plhs, string name, bool allow_kill)
{
	// Assign the value to all referenced names.
	Storage_node* st = create_empty_storage (cx, "array", name);
	assign_path_value (cx, plhs, st, allow_kill);
	return st->storage; // which might not be NAME, if NAME uses the default value.
}

string
Whole_program::assign_path_typed_array (Context* cx, Path* plhs, Types* types, string name, bool allow_kill)
{
	name = assign_path_empty_array (cx, plhs, name);
	assign_path_typed (cx, P (name, UNKNOWN), types, allow_kill);
	return name;
}

string
Whole_program::assign_path_empty_object (Context* cx, Path* plhs, string type, string name, bool allow_kill)
{
	// Assign the value to all referenced names.
	Storage_node* st = create_empty_storage (cx, type, name);
	assign_path_value (cx, plhs, st, allow_kill);
	return st->storage; // which might not be NAME, if NAME uses the default value.
}

void
Whole_program::assign_path_unknown (Context* cx, Path* plhs, bool allow_kill)
{
	DEBUG ("assign_unknown");
	// This assigns a value which is unknown, but is not as bad as
	// ruin_everything (ie, it doesnt link to all the other objects, arrays,
	// etc. Is this being used right?

	// Unknown may be an array, a scalar or an object, all of which have
	// different properties. We must be careful to separate these.
	foreach (Reference* ref, *get_lhs_references (cx, plhs))
	{
		// When assigning to different references:
		//		- scalar values are copied (though they are conceptually shared,
		//		we deal with that through functions like this).
		//		- the array is shared, not copied. It will have a unique name.
		//		- the object is shared, and will have a unique name.
		foreach_wpa (this)
		{
			if (ref->cert == DEFINITE && allow_kill)
				wpa->kill_value (cx, ref->index);

			// TODO: this is really not good enough. The array looks empty, the
			// object may reference anything. I suspect this is only suitable
			// for _SESSION, when nothing else really exists. Even then, the
			// array and object shouldnt be empty. It might be sufficient to
			// have UNKNOWN fields pointing to themselves, and marking them as
			// abstract.

			wpa->set_scalar (cx, SCLVAL (ref->index), Abstract_value::unknown ());
			wpa->assign_value (cx, ref->index, SCLVAL (ref->index));

			Storage_node* array = create_empty_storage (cx, "array");
			wpa->assign_value (cx, ref->index, array);

			Storage_node* object = create_empty_storage (cx, "stdClass");
			wpa->assign_value (cx, ref->index, object);
		}
	}
}

void
Whole_program::assign_path_by_copy (Context* cx, Path* plhs, Path* prhs, bool allow_kill)
{
	DEBUG ("assign_path_by_copy");

	// foreach values V pointed to by PRHS:
	//	switch V.type:
	//		Scalar:
	//			- foreach alias A of PLHS, set the value of A::SCLVAL using V.
	//		Array:
	//			- foreach alias A of PLHS, create a copy of V, with a new name.
	//		Objects:
	//			- foreach alias A of PLHS, point from A to V.


	// Calculate the new result via an intermediate ("fake") index node.
	Index_node* fake = create_fake_index (cx);

	// We keep the graph in transitive-closure form, so each RHS will have
	// all the values of its references already. Therefore, there is no need
	// for a call to get_lhs_references ().
	foreach (Index_node* rhs, *get_named_indices (cx, prhs, true))
		copy_value (cx, fake, rhs);



	/* Now that we have the new value, and its separated from the RHS. */
	foreach (Reference* lhs_ref, *get_lhs_references (cx, plhs))
	{
		if (lhs_ref->cert == DEFINITE && allow_kill)
		{
			FWPA->kill_value (cx, lhs_ref->index);
		}

		copy_value (cx, lhs_ref->index, fake);
	}
}

void
Whole_program::assign_path_by_cast (Context* cx, Path* plhs, Path* prhs, string type, bool allow_kill)
{
	DEBUG ("assign_path_by_cast");

	// Calculate the new result via an intermediate ("fake") index node.
	Index_node* fake = create_fake_index (cx);

	// We keep the graph in transitive-closure form, so each RHS will have
	// all the values of its references already. Therefore, there is no need
	// for a call to get_lhs_references ().
	foreach (Index_node* rhs, *get_named_indices (cx, prhs, true))
		cast_value (cx, fake, rhs, type);



	/* Now that we have the new value, and its separated from the RHS,  */
	foreach (Reference* lhs_ref, *get_lhs_references (cx, plhs))
	{
		if (lhs_ref->cert == DEFINITE && allow_kill)
		{
			FWPA->kill_value (cx, lhs_ref->index);
		}

		copy_value (cx, lhs_ref->index, fake);
	}
}

void
Whole_program::assign_absval (Context* cx, Index_node* lhs, Abstract_value* absval)
{
	FWPA->set_scalar (cx, SCLVAL (lhs), absval);
	FWPA->assign_value (cx, lhs, SCLVAL (lhs));
}

void
Whole_program::copy_value (Context* cx, Index_node* lhs, Index_node* rhs, Name_map map)
{
	lhs = check_owner_type (cx, lhs, DEFINITE);

	// Check if RHS is an indexing a scalar.
	if (Abstract_value* absval = read_from_scalar_value (cx, rhs))
	{
		DEBUG ("copy_from_abstract_value");
		assign_absval (cx, lhs, absval);
		return;
	}


	// OK, its not a scalar. Carry on.
	DEBUG ("copy_value");

	// Check if it exists yet.
	if (!aliasing->has_field (cx, R_WORKING, rhs))
	{
		rhs = new Index_node (rhs->storage, UNKNOWN);
	}

	assert (aliasing->has_field (cx, R_WORKING, rhs));

	record_use (cx, rhs);

	// Get the value for each RHS. Copy it using the correct semantics.
	foreach (Storage_node* st, *aliasing->get_points_to (cx, R_WORKING, rhs))
	{
		// Get the type of the value
		Types* types = values->get_types (cx, R_WORKING, st->name());

		// It must be either all scalars, array, list of classes, or bottom.
		Types* scalars = Type_info::get_scalar_types (types);
		Types* array = Type_info::get_array_types (types);
		Types* objects = Type_info::get_object_types (types);

		assert (scalars->empty () + array->empty () + objects->empty () == 2);

		if (scalars->size())
		{
			assign_absval (cx, lhs, get_abstract_value (cx, R_WORKING, st->name ()));
		}

		// Deep copy
		if (array->size ())
		{
			copy_structure (cx, lhs, st, "array", map);
		}

		if (objects->size ())
		{
			// Just point to the object.
			FWPA->assign_value (cx, lhs, st);
		}
	}
}

void
Whole_program::cast_value (Context* cx, Index_node* lhs, Index_node* rhs, string type)
{
	DEBUG ("cast_value");

	// Handle missing fields
	if (!aliasing->has_field (cx, R_WORKING, rhs))
	{
		rhs = new Index_node (rhs->storage, UNKNOWN);
	}

	// Since we know the RHS must index a symbol-table (ignore something like
	// overwriting the GLOBALS array with an integer)
	record_use (cx, rhs);

	Abstract_value* absval = get_abstract_value (cx, R_WORKING, rhs->name ());
	if (Type_info::is_scalar (type))
	{
		Abstract_value* absval = get_abstract_value (cx, R_WORKING, rhs->name ());
		if (absval->lit == NULL)
		{
			if (type == "string")
			{
				phc_TODO ();
				//		coerce_to_string (...);
			}
			else
			{
				assign_absval (cx, lhs,
						new Abstract_value (new Types (type)));
			}
		}
		else
		{
			assign_absval (cx, lhs,
								new Abstract_value (
									PHP::cast_to (new CAST (s(type)), absval->lit)));
		}
	}
	else if (type == "array")
	{
		cast_to_storage (cx, lhs, rhs, "array");
	}
	else if (type == "object")
	{
		cast_to_storage (cx, lhs, rhs, "stdClass");
	}
}

/* Handle all the string coersions. If node is a string, return it. If it is an
 * object, call toString, and return the Index_node storing its value. If its
 * another type, perform the coersion. */
Index_node*
Whole_program::coerce_to_string (Context* cx, Index_node* node)
{
	Abstract_value* absval = get_abstract_value (cx, R_WORKING, node->name ());

	Types* objects = Type_info::get_object_types (absval->types);
	if (objects->size ())
	{
		node = create_fake_index (cx);
		foreach (string type, *absval->types)
		{
			phc_TODO ();
		}
	}

	return node;
}

void
Whole_program::cast_to_storage (Context* cx, Index_node* lhs, Index_node* rhs, string type)
{
	foreach (Storage_node* st, *aliasing->get_points_to (cx, R_WORKING, rhs))
	{
		// Get the type of the value
		Types* types = values->get_types (cx, R_WORKING, st->name());

		// It must be either all scalars, array, list of classes, or bottom.
		Types* scalars = Type_info::get_scalar_types (types);
		Types* array = Type_info::get_array_types (types);
		Types* objects = Type_info::get_object_types (types);

		assert (!scalars->empty() ^ !array->empty() ^ !objects->empty());

		if (scalars->size())
		{
			Storage_node* new_array = create_empty_storage (cx, type);

			// If its not null, it must be put in the "scalar" field
			Abstract_value* absval = get_abstract_value (cx, R_WORKING, st->name ());
			if (not isa<NIL> (absval->lit))
			{
				absval = absval->clone ();
				absval->types->erase ("unset"); // Cant be NULL

				// Copy to a new array to the "scalar" field.
				assign_absval (cx,
									new Index_node (new_array->storage, "scalar"),
									get_abstract_value (cx, R_WORKING, st->name ()));
			}


			FWPA->assign_value (cx, lhs, new_array);
		}

		// Array: normal copy
		if (array->size())
		{
			copy_structure (cx, lhs, st, type);
		}

		// Just copy to a new array
		if (objects->size ())
		{
			copy_structure (cx, lhs, st, type);
		}
	}
}

// This does a shallow copy, but if the shallow copy has arrays, it becomes a
// deep copy of the array (aka, it does the right thing).
void
Whole_program::copy_structure (Context* cx, Index_node* lhs, Storage_node* rhs, string type, Name_map map)
{
	Storage_node* new_array;

	// Check for cycles
	if (map.has (rhs->storage))
	{
		new_array = SN (map[rhs->storage]);
	}
	else
	{
		// Create the new array
		new_array = create_empty_storage (cx, type);
		map[rhs->storage] = new_array->storage;

		// Copy all the indices.
		foreach (Index_node* index, *aliasing->get_fields (cx, R_WORKING, rhs))
		{
			copy_value (cx,
					new Index_node (new_array->for_index_node (), index->index),
					index,
					map);
		}
	}

	// LHS points to NEW_ARRAY.
	FWPA->assign_value (cx, lhs, new_array);
}

Storage_node*
Whole_program::create_empty_storage (Context* cx, string type, string name)
{
	assert (name != "array");

	// Anonymous storage
	if (name == "")
	{
		// Use a - so that the convert_context_name hack doesnt get confused.
		name = cx->storage_name (type) + "-" + lexical_cast<string> (unique_count ());
	}

	Storage_node* st = SN (name);

	FWPA->set_storage (cx, st, new Types (type));

	// All the entries are NULL.
	assign_path_scalar (cx, P (name, UNKNOWN), new NIL);

	return st;
}


Index_node*
Whole_program::create_fake_index (Context* cx)
{
	return new Index_node ("FAKE", "fake" + lexical_cast<string> (unique_count ()));
}

void
Whole_program::destroy_fake_indices (Context* cx)
{
	foreach (Index_node* fake, *aliasing->get_fields (cx, R_WORKING, SN ("FAKE")))
	{
		FWPA->remove_fake_node (cx, fake);
	}
}





/*
 * Check if the storage node of INDEX is a scalar, and handle it (in a
 * non-readonly sense).
 */
Index_node*
Whole_program::check_owner_type (Context* cx, Index_node* index, Certainty cert)
{
	Storage_node* owner = aliasing->get_owner (cx, R_WORKING, index);
	Types* types = values->get_types (cx, R_WORKING, owner->name ());
	Types* scalar_types = Type_info::get_scalar_types (types);

	if (scalar_types->size ())
	{
		if (scalar_types->size () > 1)
			phc_TODO ();

		string type = scalar_types->front ();

		if (type == "string")
		{
			// Do we know the value of the string?
			// We may need to kill LHS.
			phc_TODO ();
		}
		else if (type == "unset")
		{
			assert (isa<Value_node> (owner));

			/*
			 * If this is NIL, then it must be a value_node, so we can get the
			 * index node that points to it, and there can only be one such node.
			 */
			Index_node* owner_index = aliasing->get_incoming (cx, R_WORKING, owner)->front ();

			// Convert to an array
			Storage_node* st = create_empty_storage (cx, "array");

			// We need to point not just this node, but all references, at the new array
			Reference_list* refs = aliasing->get_references (cx, 
					R_WORKING, owner_index, PTG_ALL);

			refs->push_back (new Reference (owner_index, DEFINITE));

			// references are immutable
			foreach (Reference* ref, *refs)
			{
				Certainty final_cert = combine_certs (ref->cert, cert);

				if (final_cert == DEFINITE)
				{
					FWPA->kill_value (cx, ref->index, false);
				}

				FWPA->assign_value (cx, ref->index, st);

			}

			// We dont want the caller to index an abstract value, so return
			// the new index_node.
			return new Index_node (st->storage, index->index);
		}
		else
		{
			// Nothing happens. But with multiple types, the old type has to be
			// copied.
			// With multiple RHSs, this will hit every time.
			// With multiple LHSs, this wont change value, which is fine.
			// (Note that the value we would have killed is LHS, not
			// LHS.storage, so this is unkilled, but it might need to be
			// killed)
			phc_TODO ();
		}

		dump (cx, R_WORKING, "just before the end");
		phc_TODO ();
	}


	// OK, carry on, nothing special here.
	return index;
}




Abstract_value*
Whole_program::read_from_scalar_value (Context* cx, Index_node* rhs)
{
	// Special case - the RHS's storage node might be a sclval (however, if it
	// has both an sclval and another storage node, then the other storage nodes
	// will be handled in a different call, and we need concern ourselves only
	// with the sclval here).
	Storage_node* st = aliasing->get_owner (cx, R_WORKING, rhs);

	// Get the type of the value
	Types* types = values->get_types (cx, R_WORKING, st->name());

	// It must be either all scalars, array, or list of classes.
	Types* scalars = Type_info::get_scalar_types (types);
	Types* array = Type_info::get_array_types (types);
	Types* objects = Type_info::get_object_types (types);

	if (scalars->size() == 0)
		return NULL;

	assert (array->empty ());
	assert (objects->empty ());

	DEBUG ("read_from_scalar_value");

	/*
	 * There are only two possible types:
	 *		If the type is known to be a string, this returns a string.
	 *		If it is known not to be a string, we return NULL.
	 *		If we can't tell, it can be either.
	 */
	if (scalars->size() == 1)
	{
		if (scalars->has ("string"))
		{
			Literal* array = values->get_lit (cx, R_WORKING, st->name ());
			string index = rhs->index;
			if (array && index != UNKNOWN)
			{
				Literal* value = PHP::fold_string_index (array, new STRING (s(index)));
				return new Abstract_value (value);
			}
			else
				// We still know the type
				return new Abstract_value (new Types ("string"));
		}
		else
			return new Abstract_value (new NIL);
	}


	return new Abstract_value (new Types ("string", "unset"));
}

/*
 * For RHS call-by-ref:
 *
 *		null: implicit conversion
 *		string: Run-time error
 *		array/obj: as below (TODO: include a parameter for
 *									whether an array or an object
 *									should be used).
 *		TODO: other scalar: nothing happens
 *
 *
 *	For assign-to-LHS:
 *
 *		string: writing to its "field"
 *		null: implicit conversion
 *		other scalar types: nothing happens!!
 *
 */


void
Whole_program::record_use (Context* cx, Index_node* node)
{
	// TODO: this marks it as a use, not a must use. Is there any difference
	// as far as analyses are concerned? If so, fix this. If not, remove the
	// may-uses.

	// TODO: once type-inferences is built, here would be a good place to
	// call/check for the handlers.
	
	FWPA->record_use (cx, node, POSSIBLE);
}



void
Whole_program::ruin_everything (Context* cx, Path* plhs)
{
	// For every storage node we can reach, mark its "*" index as completely
	// unknown.
	phc_TODO ();
}


/*
 * Return the value of INDEX, as a strung. This is used to
 * disambiguate for indexing other nodes.
 */
String*
Whole_program::get_string_value (Context* cx, Index_node* index)
{
	index = coerce_to_string (cx, index);
	Abstract_value* absval = get_abstract_value (cx, R_WORKING, index->name ());
	if (absval->lit == NULL)
		return s (UNKNOWN);

	return PHP::get_string_value (absval->lit);
}



Abstract_value*
Whole_program::get_abstract_value (Context* cx, Result_state state, Alias_name name)
{
	return dyc<Absval_cell> (values->get_value (cx, state, name))->value;
}


Abstract_value*
Whole_program::get_abstract_value (Context* cx, Result_state state, MIR::Rvalue* rval)
{
	string ns = cx->symtable_name ();

	if (isa<Literal> (rval))
		return new Abstract_value (dyc<Literal> (rval));

	// The variables are not expected to already have the same value. Perhaps
	// there was an assignment to $x[0], and we are accessing $x[$i].
	Index_node* index = VN (ns, dyc<VARIABLE_NAME> (rval));

	return get_abstract_value (cx, state, index->name ());
}





Index_node* path_to_index (Path* p)
{
	Indexing* i = dyc<Indexing> (p);
	return new Index_node (
			dyc<ST_path> (i->lhs)->name,
			dyc<Index_path> (i->rhs)->name);
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
 *	It handles implicit array conversion. If we're analysing the assignment
 *	$x[$i] = 5, we need to create $x. Likewise for $y =& $x[$i] or anything in
 *	the form $y =& $x->$f. If called in these contexts, it should set
 *	RHS_BY_REF.
 *
 *	Note that this does not follow references. This is because references are
 *	stored in transitive-closure form (ie if A ref B, B's outgoing nodes should
 *	exist in A).
 */
Index_node_list*
Whole_program::get_named_indices (Context* cx, Path* path, bool is_readonly)
{
	/*
	 * TODO: check type handlers.
	 */

	Indexing* p = dyc<Indexing> (path);
	// There aren't that many cases, so don't a general solution

	/*
	 * ST -> "a"
	 *
	 * ie: $a
	 */
	if (isa <ST_path> (p->lhs) && isa<Index_path> (p->rhs))
	{
		// I'm almost certain that any use of UNKNOWN here refers directly to the
		// single field, and not to the set of possible fields.
		return new Index_node_list (path_to_index (p));
	}

	/*
	 * ST -> (ST -> "a")
	 *
	 * ie: $$a
	 */
	if (isa<ST_path> (p->lhs) && isa<Indexing> (p->rhs))
	{
		Index_node* index = path_to_index (p->rhs);
		String* index_value = this->get_string_value (cx, index);
		record_use (cx, index);

		Index_node* single_result = new Index_node (
				dyc<ST_path> (p->lhs)->name,
				*index_value);

		// We need to convert ST::UNKNOWN to all possible variables.
		if (single_result->index != UNKNOWN)
			return new Index_node_list (single_result);


		Index_node_list* result = new Index_node_list (single_result);
		foreach (Index_node* var, *aliasing->get_fields (cx, R_WORKING, SN (single_result->storage)))
		{
			// Already added
			if (var->index == UNKNOWN)
				continue;

			// This should actually find the original (ie ST::UNKNOWN) as well,
			// which is correct. This will return the actual index_nodes we
			// want to update.
			result->push_back (var);
		}

		return result;
	}




	/*
	 * (ST -> "a") -> "f"
	 *
	 * ie:
	 *		$a->f
	 *		$a["f"]
	 *
	 *	TODO: irritatingly, the former calls the __toString handler, while the latter doesn't.
	 */
	if (isa<Indexing> (p->lhs) && isa<Index_path> (p->rhs))
	{
		// This is just a specialization of $a[$f], so work on it after that works perfectly.
		string index_value = dyc<Index_path> (p->rhs)->name;
		return get_array_named_indices (cx, p->lhs, s(index_value), is_readonly);
	}


	/*
	 * (ST -> "a") -> (ST -> "f")
	 *
	 * ie:
	 *		$a->$f
	 *		$a[$f]
	 *	TODO: see __toString comment, above.
	 */

	if (isa<Indexing> (p->lhs) && isa<Indexing> (p->rhs))
	{
		Index_node* index = path_to_index (p->rhs);
		String* index_value = this->get_string_value (cx, index);
		record_use (cx, index);

		return get_array_named_indices (cx, p->lhs, index_value, is_readonly);
	}


	phc_unreachable ();
}

Index_node_list*
Whole_program::get_array_named_indices (Context* cx, Path* plhs, String* index, bool is_readonly)
{
	Index_node_list* result = new Index_node_list;

	Index_node* array = path_to_index (dyc<Indexing> (plhs));

	assert (array->index != UNKNOWN);

	// Make a note of the uses
	record_use (cx, array);



	/* 
	 * Get the storage nodes
	 */


	// TODO: I believe we can remove this by moving it into the scalar
	// handling code in copy_value/assign_path_by_ref.

	// In a writing context, if the variable containing the array doesn't
	// already exist, it must be implicitly created.
	if (not is_readonly && not aliasing->has_field (cx, R_WORKING, array))
	{
		assign_path_empty_array (cx, plhs, ANON);
	}



	/*
	 * There are two cases that arent handled here:
	 *
	 *		-	implicit creation of a NULL node on the RHS in the case of
	 *			read-by-reference. This is handled in assign_path_by_ref.
	 *
	 *		-	read of an abstract value
	 *		-	write of an abstract value
	 *			These cant be done here, so we return the correct index_node,
	 *			and handle it in copy_value
	 */


	/* 
	 * Get the index nodes.
	 */

	Storage_node_list* storages = aliasing->get_points_to (cx, R_WORKING, array);


	// We only read the value of INDEX, so we don't need the implicit array
	// creation.
	if (is_readonly && not aliasing->has_field (cx, R_WORKING, array))
	{
		assert (storages->size () == 0);
		storages->push_back (SCLVAL (array));
	}

	foreach (Storage_node* storage, *storages)
	{
		if (*index == UNKNOWN)
		{
			// Reading an abstract value: set it up for whole_program.
			if (isa<Value_node> (storage))
				result->push_back (new Index_node (storage->for_index_node (), *index));
			else
			{
				// Include all possible nodes
				foreach (Index_node* field, *aliasing->get_fields (cx, R_WORKING, storage))
					result->push_back (field);
			}
		}
		else
			result->push_back (new Index_node (storage->for_index_node (), *index));
	}

	// Even in weird cases, we should always return something.
	assert (result->size ());

	return result;

}



Reference_list*
Whole_program::get_lhs_references (Context* cx, Path* path)
{
	// Returns a list of (Index_node, certainty) pairs. Although the certainty
	// originally comes from alias analysis, it is updated to reflect if the
	// index_node is killable, from is_killable().

	Index_node_list* lhss = get_named_indices (cx, path);
	Reference_list* refs = new Reference_list;

	bool killable = is_killable (cx, lhss);
	foreach (Index_node* lhs, *lhss)
	{
		Reference_list* initial_refs = aliasing->get_references (cx, R_WORKING, lhs, PTG_ALL);
		initial_refs->push_back (new Reference (lhs, DEFINITE));

		// references are immutable
		foreach (Reference* ref, *initial_refs)
			refs->push_back (new Reference (
				ref->index,
				killable ? ref->cert : POSSIBLE));
	}

	return refs;
}

/*
 * Analysis
 */


void
Whole_program::visit_branch_block (Branch_block* bb)
{
	string ns = block_cx ()->symtable_name ();

	record_use (block_cx (), VN (ns, bb->branch->variable_name));
}

void
Whole_program::standard_lhs (Basic_block* bb, MIR::Node* lhs, bool is_ref, MIR::Rvalue* rhs)
{
	string ns = block_cx ()->symtable_name ();
	Path* plhs = P (ns, lhs);

	if (isa<Literal> (rhs))
	{
		assert (not is_ref);
		assign_path_scalar (block_cx (), plhs, dyc<Literal> (rhs));
	}
	else
	{
		Path* prhs = P (ns, rhs);

		if (is_ref)
			assign_path_by_ref (block_cx (), plhs, prhs);
		else
			assign_path_by_copy (block_cx (), plhs, prhs);
	}
}



void
Whole_program::visit_assign_array (Statement_block* bb, MIR::Assign_array* in)
{
	standard_lhs (bb, in, in->is_ref, in->rhs);
}

void
Whole_program::visit_assign_field (Statement_block* bb, MIR::Assign_field* in)
{
	standard_lhs (bb, in, in->is_ref, in->rhs);
}

void
Whole_program::visit_assign_var_var (Statement_block* bb, MIR::Assign_var_var* in)
{
	standard_lhs (bb, in, in->is_ref, in->rhs);
}

void
Whole_program::visit_assign_next (Statement_block* bb, MIR::Assign_next* in)
{
	// TODO: _next_ is one larger than the largest positive integer element
	standard_lhs (bb, in, in->is_ref, in->rhs);
}

void
Whole_program::visit_catch (Statement_block* bb, MIR::Catch* in)
{
	phc_TODO ();
}

void
Whole_program::visit_class_alias (Statement_block* bb, MIR::Class_alias* in)
{
	phc_TODO ();
}


void
Whole_program::visit_eval_expr (Statement_block* bb, MIR::Eval_expr* in)
{
	visit_expr (bb, in->expr);
}

/*
 * Foreach_* are all the same: a use of the array, a def to the iterator (which
 * uses the iterator's reference value).
 */

void
Whole_program::visit_foreach_reset (Statement_block* bb, MIR::Foreach_reset* in)
{
	string ns = block_cx ()->symtable_name ();

	// mark the array as used
	record_use (block_cx (), VN (ns, in->array));

	// Mark iterator as defined. It can then be used later.
	assign_path_scalar (block_cx (), P (ns, in->iter), new Abstract_value (new Types ("iterator")));
}

void
Whole_program::visit_foreach_next (Statement_block*, MIR::Foreach_next* in)
{
	string ns = block_cx ()->symtable_name ();

	// mark the array as used
	record_use (block_cx (), VN (ns, in->array));

	// Mark iterator as defined.
	assign_path_scalar (block_cx (), P (ns, in->iter), new Abstract_value (new Types ("iterator")));
}


void
Whole_program::visit_foreach_end (Statement_block* bb, MIR::Foreach_end* in)
{
	string ns = block_cx ()->symtable_name ();

	// mark the array as used
	record_use (block_cx (), VN (ns, in->array));

	// Mark iterator as defined.
	assign_path_scalar (block_cx (), P (ns, in->iter), new Abstract_value (new Types ("iterator")));
}


void
Whole_program::visit_global (Statement_block* bb, MIR::Global* in)
{
	string ns = block_cx ()->symtable_name ();

	assign_path_by_ref (block_cx (),
			P (ns, in->variable_name),
			P (main_scope, in->variable_name));
}

void
Whole_program::visit_interface_alias (Statement_block* bb, MIR::Interface_alias* in)
{
	phc_TODO ();
}

void
Whole_program::visit_method_alias (Statement_block* bb, MIR::Method_alias* in)
{
	phc_TODO ();
}

void
Whole_program::visit_pre_op (Statement_block* bb, Pre_op* in)
{
	string ns = block_cx ()->symtable_name ();

	// ++ and -- won't affect objects.
	Path* path = P (ns, in->variable_name);

	// I'm not really sure how to get a good interface on all this.
	Index_node* n = VN (ns, in->variable_name);

	// Case where we know the value
	Literal* value = values->get_lit (block_cx (), R_WORKING, n->name ());
	if (value)
	{
		Literal* result = PHP::fold_pre_op (value, in->op);
		assign_path_scalar (block_cx (), path, result);
		return;
	}

	// Maybe we know the type?
	Types* types = values->get_types (block_cx (), R_WORKING, n->name());
	assign_path_typed (block_cx (), path, types);
}



void
Whole_program::visit_return (Statement_block* bb, MIR::Return* in)
{
	standard_lhs (bb, in, bb->cfg->get_entry_bb ()->method->signature->return_by_ref, in->rvalue);
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

void
Whole_program::visit_unset (Statement_block* bb, MIR::Unset* in)
{
	string ns = block_cx ()->symtable_name ();

	// FYI, unset ($x[$y]), where $x is not set, does nothing. Therefore,
	// RHS_BY_REF does not need to be set for the call the get_named_indices.
	Index_node_list* indices = get_named_indices (block_cx (), P (ns, in));

	// Send the results to the analyses for all variables which could be
	// overwritten.
	
	// TODO: This is wrong - we can't kill if we don't refer to just one block.
	// It's really a may-kill.
	foreach (Index_node* index, *indices)
	{
		FWPA->kill_value (block_cx (), index, true);
	}
}




/*
 * Assign_vars from here
 */ 
void
Whole_program::visit_assign_var (Statement_block* bb, MIR::Assign_var* in)
{
	string ns = block_cx ()->symtable_name ();

	saved_plhss.push (P (ns, in->lhs));
	saved_lhss.push (in->lhs);
	saved_is_refs.push (in->is_ref);

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
			assign_path_scalar (block_cx (), saved_plhs (), dyc<Literal> (in->rhs));
			break;

		default:
			phc_unreachable ();
			break;
	}

	saved_is_refs.pop ();
	saved_lhss.pop ();
	saved_plhss.pop ();
}


void
Whole_program::standard_rhs (Basic_block* bb, MIR::Node* in)
{
	string ns = block_cx ()->symtable_name ();
	Path* path = P (ns, in);

	if (saved_is_ref ())
		assign_path_by_ref (block_cx (), saved_plhs (), path);
	else
		assign_path_by_copy (block_cx (), saved_plhs (), path);
}



void
Whole_program::visit_array_access (Statement_block* bb, MIR::Array_access* in)
{
	standard_rhs (bb, in);
}

void
Whole_program::visit_array_next (Statement_block* bb, MIR::Array_next* in)
{
	standard_rhs (bb, in);
}

void
Whole_program::visit_bin_op (Statement_block* bb, MIR::Bin_op* in)
{
	string ns = block_cx ()->symtable_name ();

	Abstract_value* left = get_abstract_value (block_cx (), R_WORKING, in->left);
	Abstract_value* right = get_abstract_value (block_cx (), R_WORKING, in->right);

	if (left->lit && right->lit)
	{
		Literal* result = PHP::fold_bin_op (left->lit, in->op, right->lit);
		if (result) // can be NULL
		{
			assign_path_scalar (block_cx (), saved_plhs (), result);
			return;
		}
	}

	// Record uses
	if (left->lit == NULL)
		record_use (block_cx (), VN (ns, dyc<VARIABLE_NAME> (in->left)));

	if (right->lit == NULL)
		record_use (block_cx (), VN (ns, dyc<VARIABLE_NAME> (in->right)));


	Types* types = values->get_bin_op_types (block_cx (), left, right, *in->op->value);
	assign_path_typed (block_cx (), saved_plhs (), types);
}

void
Whole_program::visit_bool (Statement_block* bb, MIR::BOOL* in)
{
}

void
Whole_program::visit_cast (Statement_block* bb, MIR::Cast* in)
{
	string ns = block_cx ()->symtable_name ();
	Path* path = P (ns, in->variable_name);

	assign_path_by_cast (block_cx (), saved_plhs (), path, *in->cast->value);
}

void
Whole_program::visit_constant (Statement_block* bb, MIR::Constant* in)
{
	// Needs to go through the class definitions
	if (in->class_name)
		phc_TODO ();

	Abstract_value* absval = constants->get_constant (block_cx (), R_IN, *in->constant_name->value);
	assign_path_scalar (block_cx (), saved_plhs (), absval);
}

void
Whole_program::visit_field_access (Statement_block* bb, MIR::Field_access* in)
{
	standard_rhs (bb, in);
}

void
Whole_program::visit_foreach_get_key (Statement_block* bb, MIR::Foreach_get_key* in)
{
	string ns = block_cx ()->symtable_name ();

	// mark the iterator as used
	record_use (block_cx (), VN (ns, in->array));
	record_use (block_cx (), IN (ns, *in->iter->value));

	// TODO: better modelling of UNKNOWN would be great here.
	// A key must be a string or an int.
	assign_path_scalar (block_cx (), saved_plhs (), new Abstract_value (new Types ("string", "int")));
}

void
Whole_program::visit_foreach_get_val (Statement_block* bb, MIR::Foreach_get_val* in)
{
	string ns = block_cx ()->symtable_name ();

	// mark the iterator as used
	record_use (block_cx (), VN (ns, in->array));
	record_use (block_cx (), IN (ns, *in->iter->value));


	standard_rhs (bb, in);
}

void
Whole_program::visit_foreach_has_key (Statement_block* bb, MIR::Foreach_has_key* in)
{
	string ns = block_cx ()->symtable_name ();

	// mark the iterator as used
	record_use (block_cx (), VN (ns, in->array));
	record_use (block_cx (), IN (ns, *in->iter->value));


	// Always returns true or false.
	assign_path_scalar (block_cx (), saved_plhs (), new Abstract_value (new Types ("bool")));
}

void
Whole_program::visit_instanceof (Statement_block* bb, MIR::Instanceof* in)
{
	phc_TODO ();
}

void
Whole_program::visit_int (Statement_block* bb, MIR::INT* in)
{
}

void
Whole_program::visit_isset (Statement_block* bb, MIR::Isset* in)
{
	// TODO: there can be handlers here.
	string ns = block_cx ()->symtable_name ();

	/* Mark all the uses */
	if (isa<Variable_variable> (in->variable_name))
		phc_TODO ();

	if (isa<VARIABLE_NAME> (in->target))
		record_use (block_cx (), VN (ns, dyc<VARIABLE_NAME> (in->target)));
	else if (in->target)
		phc_TODO ();

	if (isa<VARIABLE_NAME> (in->variable_name)
		&& in->target == NULL)
		record_use (block_cx (), VN (ns, dyc<VARIABLE_NAME> (in->variable_name)));

	foreach (Rvalue* rval, *in->array_indices)
	{
		if (isa<VARIABLE_NAME> (rval))
			record_use (block_cx (), VN (ns, dyc<VARIABLE_NAME> (rval)));
	}


	// Always returns true or false.
	assign_path_scalar (block_cx (), saved_plhs (), new Abstract_value (new Types ("bool")));
}

void
Whole_program::visit_method_invocation (Statement_block* bb, MIR::Method_invocation* in)
{
	if (saved_is_ref ())
		phc_TODO ();

	invoke_method (block_cx (), saved_lhs (), in);
}

void
Whole_program::visit_nil (Statement_block* bb, MIR::NIL* in)
{
}

void
Whole_program::visit_new (Statement_block* bb, MIR::New* in)
{
	string ns = block_cx ()->symtable_name ();

	if (saved_plhs () == NULL)
		phc_TODO ();

	// This will be easy - just kill the LHS references.
	if (saved_is_ref ())
		phc_TODO ();

	instantiate_object (block_cx (), saved_lhs (), in);
}

void
Whole_program::visit_param_is_ref (Statement_block* bb, MIR::Param_is_ref* in)
{
	string ns = block_cx ()->symtable_name ();


	// Get the set of receivers (we need to check them all to see if this
	// parameter is by reference.
	Method_info_list* receivers = get_possible_receivers (block_cx (), R_WORKING, in);

	// Need to clone the information and merge it when it returns.
	if (receivers->size () != 1)
		phc_TODO ();

	bool direction_known = true;
	bool param_by_ref = false;
	foreach (Method_info* info, *receivers)
	{
		// TODO: when there are more receivers, this needs fixing.
		param_by_ref = info->param_by_ref (in->param_index->value);
	}


	// Apply the results
	if (direction_known)
	{
		assign_path_scalar (block_cx (), saved_plhs (), new BOOL (param_by_ref));
	}
	else
	{
		assign_path_typed (block_cx (), saved_plhs (), new Types ("bool"));
	}
}

void
Whole_program::visit_real (Statement_block* bb, MIR::REAL* in)
{
}

void
Whole_program::visit_string (Statement_block* bb, MIR::STRING* in)
{
}

void
Whole_program::visit_unary_op (Statement_block* bb, MIR::Unary_op* in)
{
	string ns = block_cx ()->symtable_name ();

	Abstract_value* val = get_abstract_value (block_cx (), R_WORKING, in->variable_name);

	if (val->lit)
	{
		Literal* result = PHP::fold_unary_op (in->op, val->lit);
		assign_path_scalar (block_cx (), saved_plhs (), result);
		return;
	}
	else
		record_use (block_cx (), VN (ns, in->variable_name));

	Types* types = values->get_unary_op_types (block_cx (), val, *in->op->value);
	assign_path_typed (block_cx (), saved_plhs (), types);
}

void
Whole_program::visit_variable_name (Statement_block* bb, MIR::VARIABLE_NAME* in)
{
	standard_rhs (bb, in);
}

void
Whole_program::visit_variable_variable (Statement_block* bb, MIR::Variable_variable* in)
{
	standard_rhs (bb, in);
}



