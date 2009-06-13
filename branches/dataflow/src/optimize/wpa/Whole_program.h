/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Perform a number of whole-program analyses simulteneously.
 */

/*
 * This is the basis for simulatenous optimizations. It seems that we need
 * alias analysis to do type-inference, and type-inference for alias
 * analysis.  On top of this, we would get more precise results if we did the
 * analysis conditionally (or symbolically - aka evaluating constants and
 * branches).  Additionally, we can use this to model global state, including
 * include_path, the error_reporting level, defined functions, classes and
 * constants, etc.
 *
 * The analysis starts in main, and each statement is symbolically executed
 * (referred heretofore as evaluated) by each analyser before the next
 * statement is evaluated. When another function is called, it propagates the
 * current results (or global results for global state) into the callee, and
 * the callee is the evaluated, before returning to the caller. Once the
 * entire program is evaluated in this manner, we will have complete results,
 * including a callgraph and types. Then other analyses who merely consume
 * this information can run, and annotated things for the code generator.
 *
 * The analysis will proceed conditionally, in the sense of CCP, which means
 * that it will evaluate a conditional, and only proceed down 1 path if we
 * are able to evaluate it. Passes will be passed a clone of the statement,
 * and so can update it if they wish. The statement will be passed to each
 * analysis until it fix-points.
 *
 * The analyses will have to each other, so that we can get a type if
 * required for callgraph resolution, etc.
 *
 */

#ifndef PHC_WHOLE_PROGRAM
#define PHC_WHOLE_PROGRAM

#include "lib/Map.h"
#include "WPA.h"

DECL(Method_info);
DECL(Index_node);
DECL(Reference);

class CFG;
class Basic_block;

class Aliasing;
class Callgraph;
class Constant_state;
class Def_use;
class Include_analysis;
class Value_analysis;
class VRP;

class Optimization_transformer;
class Optimization_annotator;
class Pass_manager;
class Path;
class WPA;
class Absval_cell;

/*
 * Intended to be used as FWPA->whatever ();
 */

// This gets used everywhere.
#define foreach_wpa(WP)		foreach (WPA* wpa, WP->analyses)

#define FWPA	 foreach (WPA* wpa, this->analyses) wpa

class Whole_program : public CFG_visitor
{
	// Previous iteration - stored for analyses_have_reached_fix_point
	List<WPA*> old_analyses;

public:

	List<WPA*> analyses;

	Pass_manager* pm;

	Optimization_transformer* transformer;
	Optimization_annotator* annotator;

	// Analyses should be able to reach in here to get other analyses'
	// results.
	Aliasing* aliasing;
	Callgraph* callgraph;
	Constant_state* constants;
	Def_use* def_use;
	Value_analysis* values;

	// For assignments
	Path* saved_plhs;
	MIR::VARIABLE_NAME* saved_lhs;
	bool saved_is_ref;

	// name of __MAIN__ scope
	string main_scope;


public:
	Whole_program(Pass_manager* pm);

	void run (MIR::PHP_script* in);
	void run (CFG* cfg){phc_unreachable ();}

	void initialize ();
	bool analyses_have_converged ();

	/* 
	 * Creating and using analyses.
	 */
	void register_analysis (string name, WPA* analysis);

	void invoke_method (MIR::Method_invocation* in,
							  Context* caller_cx,
							  MIR::VARIABLE_NAME* lhs);

	Method_info_list* get_possible_receivers (MIR::Target*, MIR::Method_name*);
	Method_info_list* get_possible_receivers (MIR::Param_is_ref*);
	Method_info_list* get_possible_receivers (MIR::Method_invocation*);

	void generate_summary (User_method_info* info);

	void merge_contexts ();

	/* Optimizations on user-code */
	void apply_results (User_method_info* info);
	void annotate_results (User_method_info* info);
	void perform_local_optimizations (User_method_info* info);
	void perform_interprocedural_optimizations (User_method_info* info);

	void strip (MIR::PHP_script* in);

	// Apply the interprocedural optimization results to this BB.

	void analyse_method_info (Method_info* info,
									  Context* caller_cx,
									  MIR::Actual_parameter_list* actuals,
									  MIR::VARIABLE_NAME* lhs);

	void analyse_function (User_method_info* info,
								  Context* caller_cx,
								  MIR::Actual_parameter_list*,
								  MIR::VARIABLE_NAME* lhs);

	void analyse_summary (Summary_method_info* info,
								 Context* caller_cx,
							    MIR::Actual_parameter_list*,
								 MIR::VARIABLE_NAME* lhs);

	void apply_modelled_function (Summary_method_info* info, Context* cx, Context* caller_cx);

	void init_superglobals (Context* cx);

	/* Local analysis - calling other analyses */
	void dump (Context* cx, string comment);


	/*
	 * Calls to the WPA modules.
	 */
	void forward_bind (Method_info* info,
							 Context* entry_cx,
							 MIR::Actual_parameter_list* actuals);

	void backward_bind (Method_info* info,
							  Context* entry_cx,
							  MIR::VARIABLE_NAME* lhs);

	// Performs points-to analysis, and call the other analyses with the
	// results. Returns true if a solution has changed, requiring this block
	// to be reanalysed.
	bool analyse_block (Context* cx);
	void init_block (Context* cx);

	/*
	 * Assignments by paths (aka high-level)
	 */
	void assign_path_scalar (Context* cx, Path* lhs, MIR::Literal* lit);
	void assign_path_scalar (Context* cx, Path* plhs, Abstract_value* absval);
	void assign_path_unknown (Context* cx, Path* lhs);
	void assign_path_typed (Context* cx, Path* lhs, Types* types);
	void assign_path_by_ref (Context* cx, Path* lhs, Path* rhs);
	void assign_path_by_copy (Context* cx, Path* lhs, Path* rhs);
	void assign_path_value (Context* cx, Path* lhs, Storage_node* st);
	string assign_path_empty_array (Context* cx, Path* lhs, string name = "");
	string assign_path_empty_object (Context* cx, Path* lhs, string type, string name = "");

	// Most pesimistic case
	void ruin_everything (Context* cx, Path* path);


	/*
	 * Assignments by by node (aka lower-level)
	 */

	void assign_absval (Context* cx, Index_node* lhs, Abstract_value* absval);
	Index_node* create_fake_index (Context* cx);
	void destroy_fake_index (Context* cx);

	// If no name is provided, an anonymous name is chosen.
	Storage_node* create_empty_storage (Context* cx, string type, string name = "");

	// When copying data, we dont want to collapse stuff into a single array/object!
	int storage_count;

	// Copy the value from RHS to LHS.
	void copy_value (Context* cx, Index_node* lhs, Index_node* rhs);

	Index_node* check_owner_type (Context* cx, Index_node* index);
	Abstract_value* read_from_scalar_value (Context* cx, Index_node* rhs);

	bool is_killable (Context* cx, Index_node_list* indices);


	/*
	 * These might be considered to belong elsewhere, but each of them needs to
	 * some information which is not necessarily available to the analysis in
	 * question.
	 */


	// Get the value of node (can be UNKNOWN).
	String* get_string_value (Context* cx, Index_node* node);

	Abstract_value* get_abstract_value (Context* cx, Alias_name name);

	// Get all the possible names, and merge them.
	Abstract_value* get_abstract_value (Context* cx, MIR::Rvalue* rval);

	// Special case, get the input value.
	Abstract_value* get_bb_in_abstract_value (Context* cx, Alias_name name);

	// PATH can refer to many nodes. Get the list of Index_nodes it points to.
	// Set the RHS_BY_REF flag if PATH represents the RHS of an
	// assignment-by-reference.
	Index_node_list* get_named_indices (Context* cx, Path* path, bool is_readonly = false);
	Index_node_list* get_array_named_indices (Context* cx, Path* lhs, String* index, bool is_readonly);

	// Get anything the path can point to, and all nodes that they may reference.
	Reference_list* get_lhs_references (Context* cx, Path* path);


	/*
	 * End of Assignments
	 */

	Edge_list* get_successors (Context* cx);
	void pull_results (Context* cx, BB_list* bbs);
	Index_node_list* get_possible_nulls (List<Context*>*);

	void record_use (Context* cx, Index_node* node);




	/*
	 * Actually perform analysis
	 */

	Context* block_cx;

	void visit_branch_block (Branch_block*);

	void visit_assign_array (Statement_block*, MIR::Assign_array*);
	void visit_assign_field (Statement_block*, MIR::Assign_field *);
	void visit_assign_var (Statement_block*, MIR::Assign_var*);
	void visit_assign_var_var (Statement_block*, MIR::Assign_var_var*);
	void visit_eval_expr (Statement_block*, MIR::Eval_expr*);
	void visit_foreach_end (Statement_block*, MIR::Foreach_end*);
	void visit_foreach_next (Statement_block*, MIR::Foreach_next*);
	void visit_foreach_reset (Statement_block*, MIR::Foreach_reset*);
	void visit_global (Statement_block*, MIR::Global*);
	void visit_pre_op (Statement_block*, MIR::Pre_op*);
	void visit_assign_next (Statement_block*, MIR::Assign_next*);
	void visit_return (Statement_block*, MIR::Return*);
	void visit_static_declaration (Statement_block*, MIR::Static_declaration*);
	void visit_throw (Statement_block*, MIR::Throw*);
	void visit_try (Statement_block*, MIR::Try*);
	void visit_unset (Statement_block*, MIR::Unset*);

	void visit_array_access (Statement_block* bb, MIR::Array_access* in);
	void visit_bin_op (Statement_block* bb, MIR::Bin_op* in);
	void visit_cast (Statement_block* bb, MIR::Cast* in);
	void visit_constant (Statement_block* bb, MIR::Constant* in);
	void visit_field_access (Statement_block* bb, MIR::Field_access* in);
	void visit_foreach_get_key (Statement_block* bb, MIR::Foreach_get_key* in);
	void visit_foreach_get_val (Statement_block* bb, MIR::Foreach_get_val* in);
	void visit_foreach_has_key (Statement_block* bb, MIR::Foreach_has_key* in);
	void visit_instanceof (Statement_block* bb, MIR::Instanceof* in);
	void visit_isset (Statement_block* bb, MIR::Isset* in);
	void visit_method_invocation (Statement_block* bb, MIR::Method_invocation* in);
	void visit_new (Statement_block* bb, MIR::New* in);
	void visit_param_is_ref (Statement_block* bb, MIR::Param_is_ref* in);
	void visit_unary_op (Statement_block* bb, MIR::Unary_op* in);
	void visit_variable_name (Statement_block* bb, MIR::VARIABLE_NAME* in);
	void visit_variable_variable (Statement_block* bb, MIR::Variable_variable* in);
};


#endif // PHC_WHOLE_PROGRAM
