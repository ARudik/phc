/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Translate the shredded and lowered AST to HIR 
 */

#ifndef PHC_AST_TO_HIR_H
#define PHC_AST_TO_HIR_H

#include "AST_fold.h"
#include "HIR.h"
#include "process_ir/General.h"

/*
 * Those AST nodes that should no longer appear in the HIR do not have an
 * implementation in this translation, so that we inherit the default assert(0)
 * implementation from AST_fold. However, to satisfy the typechecker, we must
 * still provide a reasonble type for these nodes. For example, the type we
 * specify for For (which does not have a corresponding HIR construct) is
 * simplify HIR::Statement*. For some constructs, specifying HIR::Node*
 * suffices.
 */
class AST_to_HIR : public AST::Fold
<HIR::Node*,				// Node*
 HIR::PHP_script*,			// PHP_script*
 HIR::Statement*,			// Statement*
 HIR::Class_def*,			// Class_def*
 HIR::Class_mod*,			// Class_mod*
 HIR::Interface_def*,		// Interface_def*
 HIR::Member*,				// Member*
 HIR::Method*,				// Method*
 HIR::Signature*,			// Signature*
 HIR::Method_mod*,			// Method_mod*
 HIR::Formal_parameter*,	// Formal_parameter*
 HIR::Type*,				// Type*
 HIR::Attribute*,			// Attribute*
 HIR::Attr_mod*,			// Attr_mod*
 HIR::Name_with_default*,	// Name_with_default*
 HIR::If*,			// If*
 HIR::Loop*,			// While*
 HIR::Statement*,		// Do*
 HIR::Statement*,			// For*
 HIR::Foreach*,			// Foreach*
 HIR::Switch*,			// Switch*
 HIR::Switch_case*,				// Switch_case*
 HIR::Break*,			// Break*
 HIR::Continue*,			// Continue*
 HIR::Return*,				// Return*
 HIR::Static_declaration*,	// Static_declaration*
 HIR::Global*,				// Global*
 HIR::Statement*,			// Declare*
 HIR::Statement*,				// Directive*
 HIR::Try*,					// Try*
 HIR::Catch*,				// Catch*
 HIR::Throw*,				// Throw*
 HIR::Eval_expr*,			// Eval_expr*
 HIR::Statement*,			// Nop*
 HIR::Branch*,				// Branch*
 HIR::Goto*,				// Goto*
 HIR::Label*,				// Label*
 HIR::Foreach_reset*,	// Foreach_reset*
 HIR::Foreach_next*,	// Foreach_next*
 HIR::Foreach_end*,	// Foreach_end*
 HIR::Foreach_has_key*,	// Foreach_has_key*
 HIR::Foreach_get_key*,	// Foreach_get_key*
 HIR::Foreach_get_val*,	// Foreach_get_val*
 HIR::Expr*,				// Expr*
 HIR::Literal*,				// Literal*
 HIR::Assignment*,			// Assignment*
 HIR::Op_assignment*,				// Op_assignment*
 HIR::List_assignment*,				// List_assignment*
 HIR::List_element*,				// List_element*
 HIR::Nested_list_elements*,				// Nested_list_elements*
 HIR::Cast*,				// Cast*
 HIR::Unary_op*,			// Unary_op*
 HIR::Bin_op*,				// Bin_op*
 HIR::Expr*,				// Conditional_expr*
 HIR::Ignore_errors*,				// Ignore_errors*
 HIR::Constant*,			// Constant*
 HIR::Instanceof*,			// Instanceof*
 HIR::Variable*,			// Variable*
 HIR::Variable_name*,		// Variable_name*
 HIR::Reflection*,			// Reflection*
 HIR::Target*,				// Target*
 HIR::Pre_op*,				// Pre_op*
 HIR::Expr*,				// Post_op*
 HIR::Array*,				// Array*
 HIR::Array_elem*,			// Array_elem*
 HIR::Method_invocation*,	// Method_invocation*
 HIR::Method_name*,			// Method_name*
 HIR::Actual_parameter*,	// Actual_parameter*
 HIR::New*,					// New*
 HIR::Class_name*,			// Class_name*
 HIR::Commented_node*,				// Commented_node*
 HIR::Identifier*,			// Identifier*
 HIR::Node*,			// Source_rep*
 HIR::HT_ITERATOR*,		// HT_ITERATOR*
 HIR::CLASS_NAME*,		// CLASS_NAME*
 HIR::INTERFACE_NAME*,	// INTERFACE_NAME*
 HIR::METHOD_NAME*,		// METHOD_NAME*
 HIR::VARIABLE_NAME*,		// VARIABLE_NAME*
 HIR::Identifier*,			// DIRECTIVE_NAME*
 HIR::LABEL_NAME*,		// LABEL_NAME*
 HIR::INT*,				// INT*
 HIR::REAL*,				// REAL*
 HIR::STRING*,			// STRING*
 HIR::BOOL*,				// BOOL*
 HIR::NIL*,				// NIL*
 HIR::OP*,				// OP*
 HIR::CAST*,				// CAST*
 HIR::CONSTANT_NAME*>		// CONSTANT_NAME*
{
	HIR::PHP_script* fold_impl_php_script(AST::PHP_script* orig, List<HIR::Statement*>* statements) 
	{
		HIR::PHP_script* result;
		result = new HIR::PHP_script(statements);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Class_def* fold_impl_class_def(AST::Class_def* orig, HIR::Class_mod* class_mod, HIR::CLASS_NAME* class_name, HIR::CLASS_NAME* extends, List<HIR::INTERFACE_NAME*>* implements, List<HIR::Member*>* members) 
	{
		HIR::Class_def* result;
		result = new HIR::Class_def(class_mod, class_name, extends, implements, members);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Class_mod* fold_impl_class_mod(AST::Class_mod* orig, bool is_abstract, bool is_final) 
	{
		HIR::Class_mod* result;
		result = new HIR::Class_mod(is_abstract, is_final);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Interface_def* fold_impl_interface_def(AST::Interface_def* orig, HIR::INTERFACE_NAME* interface_name, List<HIR::INTERFACE_NAME*>* extends, List<HIR::Member*>* members) 
	{
		HIR::Interface_def* result;
		result = new HIR::Interface_def(interface_name, extends, members);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Method* fold_impl_method(AST::Method* orig, HIR::Signature* signature, List<HIR::Statement*>* statements) 
	{
		HIR::Method* result;
		result = new HIR::Method(signature, statements);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Signature* fold_impl_signature(AST::Signature* orig, HIR::Method_mod* method_mod, bool is_ref, HIR::METHOD_NAME* method_name, List<HIR::Formal_parameter*>* formal_parameters) 
	{
		HIR::Signature* result;
		result = new HIR::Signature(method_mod, is_ref, method_name, formal_parameters);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Method_mod* fold_impl_method_mod(AST::Method_mod* orig, bool is_public, bool is_protected, bool is_private, bool is_static, bool is_abstract, bool is_final) 
	{
		HIR::Method_mod* result;
		result = new HIR::Method_mod(is_public, is_protected, is_private, is_static, is_abstract, is_final);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Formal_parameter* fold_impl_formal_parameter(AST::Formal_parameter* orig, HIR::Type* type, bool is_ref, HIR::Name_with_default* var) 
	{
		HIR::Formal_parameter* result;
		result = new HIR::Formal_parameter(type, is_ref, var);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Type* fold_impl_type(AST::Type* orig, HIR::CLASS_NAME* class_name) 
	{
		HIR::Type* result;
		result = new HIR::Type(class_name);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Attribute* fold_impl_attribute(AST::Attribute* orig, HIR::Attr_mod* attr_mod, List<HIR::Name_with_default*>* vars) 
	{
//		assert(vars->size() == 1); // TODO reinstate this

		HIR::Attribute* result;
		result = new HIR::Attribute(attr_mod, vars);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Attr_mod* fold_impl_attr_mod(AST::Attr_mod* orig, bool is_public, bool is_protected, bool is_private, bool is_static, bool is_const) 
	{
		HIR::Attr_mod* result;
		result = new HIR::Attr_mod(is_public, is_protected, is_private, is_static, is_const);
		result->attrs = orig->attrs;
		return result;
	}
	
	HIR::Name_with_default* fold_impl_name_with_default(AST::Name_with_default* orig, HIR::VARIABLE_NAME* variable_name, HIR::Expr* expr) 
	{ 
		HIR::Name_with_default* result;
		result = new HIR::Name_with_default(variable_name, expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Return* fold_impl_return(AST::Return* orig, HIR::Expr* expr) 
	{
		HIR::Return* result;
		result = new HIR::Return(expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Static_declaration* fold_impl_static_declaration(AST::Static_declaration* orig, List<HIR::Name_with_default*>* vars) 
	{
		assert(vars->size() == 1);

		HIR::Static_declaration* result;
		result = new HIR::Static_declaration(vars);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Global* fold_impl_global(AST::Global* orig, List<HIR::Variable_name*>* variable_names) 
	{
		// HIR only takes a single variable per global; should be been taken care of in the shredder
		// TODO reinstate
//		assert(variable_names->size() == 1);
		
		HIR::Global* result;
		result = new HIR::Global(variable_names);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Try* fold_impl_try(AST::Try* orig, List<HIR::Statement*>* statements, List<HIR::Catch*>* catches) 
	{
		HIR::Try* result;
		result = new HIR::Try(statements, catches);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Catch* fold_impl_catch(AST::Catch* orig, HIR::CLASS_NAME* class_name, HIR::VARIABLE_NAME* variable_name, List<HIR::Statement*>* statements) 
	{
		HIR::Catch* result;
		result = new HIR::Catch(class_name, variable_name, statements);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Throw* fold_impl_throw(AST::Throw* orig, HIR::Expr* expr) 
	{
		HIR::Throw* result;
		result = new HIR::Throw(expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Eval_expr* fold_impl_eval_expr(AST::Eval_expr* orig, HIR::Expr* expr) 
	{
		HIR::Eval_expr* result;
		result = new HIR::Eval_expr(expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Branch* fold_impl_branch(AST::Branch* orig, HIR::Expr* expr, HIR::LABEL_NAME* iftrue, HIR::LABEL_NAME* iffalse) 
	{
		HIR::Branch* result;
		result = new HIR::Branch(expr, iftrue, iffalse);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Goto* fold_impl_goto(AST::Goto* orig, HIR::LABEL_NAME* label_name) 
	{
		HIR::Goto* result;
		result = new HIR::Goto(label_name);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Label* fold_impl_label(AST::Label* orig, HIR::LABEL_NAME* label_name) 
	{
		HIR::Label* result;
		result = new HIR::Label(label_name);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Break* fold_impl_break (AST::Break* orig, HIR::Expr* expr)
	{
		HIR::Break* result;
		result = new HIR::Break (expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::If* fold_impl_if(AST::If* orig, HIR::Expr* expr, List<HIR::Statement*>* iftrue, List<HIR::Statement*>* iffalse)
	{
		HIR::If* result;
		result = new HIR::If (expr, iftrue, iffalse);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Op_assignment* fold_impl_op_assignment(AST::Op_assignment* orig, HIR::Variable* variable, HIR::OP* op, HIR::Expr* expr)
	{
		HIR::Op_assignment* result;
		result = new HIR::Op_assignment (variable, op, expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Loop* fold_impl_while (AST::While* orig, HIR::Expr* expr, List<HIR::Statement*>* statements)
	{
		// All while's must be true
		HIR::BOOL* b = dynamic_cast<HIR::BOOL*> (expr);
		assert (b && b->value);

		HIR::Loop* result;
		result = new HIR::Loop(statements);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Foreach* fold_impl_foreach (AST::Foreach* orig, HIR::Expr* expr, HIR::Variable* key, bool is_ref, HIR::Variable* val, List<HIR::Statement*>* statements)
	{
		HIR::Foreach* result;
		result = new HIR::Foreach(expr, key, is_ref, val, statements);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Ignore_errors* fold_impl_ignore_errors(AST::Ignore_errors* orig, HIR::Expr* expr)
	{
		HIR::Ignore_errors* result;
		result = new HIR::Ignore_errors (expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Switch* fold_impl_switch(AST::Switch* orig, HIR::Expr* expr, List<HIR::Switch_case*>* switch_cases)
	{
		HIR::Switch* result;
		result = new HIR::Switch (expr, switch_cases);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Continue* fold_impl_continue(AST::Continue* orig, HIR::Expr* expr)
	{
		HIR::Continue* result;
		result = new HIR::Continue(expr);
		result->attrs = orig->attrs;
		return result;
	}


	HIR::List_assignment* fold_impl_list_assignment(AST::List_assignment* orig, List<HIR::List_element*>* list_elements, HIR::Expr* expr)
	{
		HIR::List_assignment* result;
		result = new HIR::List_assignment(list_elements, expr);
		result->attrs = orig->attrs;
		return result;
	}


	HIR::Nested_list_elements* fold_impl_nested_list_elements(AST::Nested_list_elements* orig, List<HIR::List_element*>* list_elements)
	{
		HIR::Nested_list_elements* result;
		result = new HIR::Nested_list_elements(list_elements);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Switch_case* fold_impl_switch_case(AST::Switch_case* orig, HIR::Expr* expr, List<HIR::Statement*>* statements)
	{
		HIR::Switch_case* result;
		result = new HIR::Switch_case (expr, statements);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Foreach_reset* fold_impl_foreach_reset (AST::Foreach_reset* orig, HIR::Variable* variable, HIR::HT_ITERATOR* ht_iterator) 
	{
		HIR::Foreach_reset* result;
		result = new HIR::Foreach_reset (variable, ht_iterator);
		result->attrs = orig->attrs;
		return result;
	}


	HIR::Foreach_next* fold_impl_foreach_next (AST::Foreach_next* orig, HIR::Variable* variable, HIR::HT_ITERATOR* ht_iterator) 
	{
		HIR::Foreach_next* result;
		result = new HIR::Foreach_next (variable, ht_iterator);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Foreach_end* fold_impl_foreach_end (AST::Foreach_end* orig, HIR::Variable* variable, HIR::HT_ITERATOR* ht_iterator) 
	{
		HIR::Foreach_end* result;
		result = new HIR::Foreach_end (variable, ht_iterator);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Foreach_has_key* fold_impl_foreach_has_key (AST::Foreach_has_key* orig, HIR::Variable* variable, HIR::HT_ITERATOR* ht_iterator) 
	{
		HIR::Foreach_has_key* result;
		result = new HIR::Foreach_has_key (variable, ht_iterator);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Foreach_get_key* fold_impl_foreach_get_key (AST::Foreach_get_key* orig, HIR::Variable* variable, HIR::HT_ITERATOR* ht_iterator) 
	{
		HIR::Foreach_get_key* result;
		result = new HIR::Foreach_get_key (variable, ht_iterator);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Foreach_get_val* fold_impl_foreach_get_val (AST::Foreach_get_val* orig, HIR::Variable* variable, HIR::HT_ITERATOR* ht_iterator) 
	{
		HIR::Foreach_get_val* result;
		result = new HIR::Foreach_get_val (variable, ht_iterator);
		result->attrs = orig->attrs;
		return result;
	}
	
	HIR::Assignment* fold_impl_assignment(AST::Assignment* orig, HIR::Variable* variable, bool is_ref, HIR::Expr* expr) 
	{
		HIR::Assignment* result;
		result = new HIR::Assignment(variable, is_ref, expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Cast* fold_impl_cast(AST::Cast* orig, HIR::CAST* cast, HIR::Expr* expr) 
	{
		HIR::Cast* result;
		result = new HIR::Cast(cast, expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Unary_op* fold_impl_unary_op(AST::Unary_op* orig, HIR::OP* op, HIR::Expr* expr) 
	{
		HIR::Unary_op* result;
		result = new HIR::Unary_op(op, expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Bin_op* fold_impl_bin_op(AST::Bin_op* orig, HIR::Expr* left, HIR::OP* op, HIR::Expr* right) 
	{
		HIR::Bin_op* result;
		result = new HIR::Bin_op(left, op, right);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Constant* fold_impl_constant(AST::Constant* orig, HIR::CLASS_NAME* class_name, HIR::CONSTANT_NAME* constant_name) 
	{
		HIR::Constant* result;
		result = new HIR::Constant(class_name, constant_name);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Instanceof* fold_impl_instanceof(AST::Instanceof* orig, HIR::Expr* expr, HIR::Class_name* class_name) 
	{
		HIR::Instanceof* result;
		result = new HIR::Instanceof(expr, class_name);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Variable* fold_impl_variable(AST::Variable* orig, HIR::Target* target, HIR::Variable_name* variable_name, List<HIR::Expr*>* array_indices) 
	{
		HIR::Variable* result;
		result = new HIR::Variable(target, variable_name, array_indices);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Reflection* fold_impl_reflection(AST::Reflection* orig, HIR::Expr* expr) 
	{
		HIR::Reflection* result;
		result = new HIR::Reflection (expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Pre_op* fold_impl_pre_op(AST::Pre_op* orig, HIR::OP* op, HIR::Variable* variable) 
	{
		HIR::Pre_op* result;
		result = new HIR::Pre_op(op, variable);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Array* fold_impl_array(AST::Array* orig, List<HIR::Array_elem*>* array_elems) 
	{
		HIR::Array* result;
		result = new HIR::Array(array_elems);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Array_elem* fold_impl_array_elem(AST::Array_elem* orig, HIR::Expr* key, bool is_ref, HIR::Expr* val) 
	{
		HIR::Array_elem* result;
		result = new HIR::Array_elem(key, is_ref, val);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Method_invocation* fold_impl_method_invocation(AST::Method_invocation* orig, HIR::Target* target, HIR::Method_name* method_name, List<HIR::Actual_parameter*>* actual_parameters) 
	{
		HIR::Method_invocation* result;
		result = new HIR::Method_invocation(target, method_name, actual_parameters);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::Actual_parameter* fold_impl_actual_parameter(AST::Actual_parameter* orig, bool is_ref, HIR::Expr* expr) 
	{
		HIR::Actual_parameter* result;
		result = new HIR::Actual_parameter(is_ref, expr);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::New* fold_impl_new(AST::New* orig, HIR::Class_name* class_name, List<HIR::Actual_parameter*>* actual_parameters) 
	{
		HIR::New* result;
		result = new HIR::New(class_name, actual_parameters);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::HT_ITERATOR* fold_ht_iterator (AST::HT_ITERATOR* orig)
	{
		HIR::HT_ITERATOR* result;
		result = new HIR::HT_ITERATOR (orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::CLASS_NAME* fold_class_name(AST::CLASS_NAME* orig) 
	{
		HIR::CLASS_NAME* result;
		result = new HIR::CLASS_NAME(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::INTERFACE_NAME* fold_interface_name(AST::INTERFACE_NAME* orig) 
	{
		HIR::INTERFACE_NAME* result;
		result = new HIR::INTERFACE_NAME(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::METHOD_NAME* fold_method_name(AST::METHOD_NAME* orig) 
	{
		HIR::METHOD_NAME* result;
		result = new HIR::METHOD_NAME(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::VARIABLE_NAME* fold_variable_name(AST::VARIABLE_NAME* orig) 
	{
		HIR::VARIABLE_NAME* result;
		result = new HIR::VARIABLE_NAME(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::LABEL_NAME* fold_label_name(AST::LABEL_NAME* orig) 
	{
		HIR::LABEL_NAME* result;
		result = new HIR::LABEL_NAME(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::INT* fold_int(AST::INT* orig) 
	{
		HIR::INT* result;
		result = new HIR::INT(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::REAL* fold_real(AST::REAL* orig) 
	{
		HIR::REAL* result;
		result = new HIR::REAL(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::STRING* fold_string(AST::STRING* orig) 
	{
		HIR::STRING* result;
		result = new HIR::STRING(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::BOOL* fold_bool(AST::BOOL* orig) 
	{
		HIR::BOOL* result;
		result = new HIR::BOOL(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::NIL* fold_nil(AST::NIL* orig) 
	{
		HIR::NIL* result;
		result = new HIR::NIL();
		result->attrs = orig->attrs;
		return result;
	}

	HIR::OP* fold_op(AST::OP* orig) 
	{
		HIR::OP* result;
		result = new HIR::OP(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::CAST* fold_cast(AST::CAST* orig) 
	{
		HIR::CAST* result;
		result = new HIR::CAST(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	HIR::CONSTANT_NAME* fold_constant_name(AST::CONSTANT_NAME* orig) 
	{
		HIR::CONSTANT_NAME* result;
		result = new HIR::CONSTANT_NAME(orig->value);
		result->attrs = orig->attrs;
		return result;
	}

	~AST_to_HIR () {}
};

#endif // PHC_AST_TO_HIR_H 