/*
 * This code is autogenerated by MakeTea. Do not edit.
 */

#include "Tree_visitor.h"

Tree_visitor::~Tree_visitor()
{
}

void Tree_visitor::pre_php_script(AST_php_script* in)
{
}

void Tree_visitor::children_php_script(AST_php_script* in)
{
	in->interface_defs->visit(this);
	in->class_defs->visit(this);
}

void Tree_visitor::post_php_script(AST_php_script* in)
{
}

void Tree_visitor::pre_interface_def(AST_interface_def* in)
{
}

void Tree_visitor::children_interface_def(AST_interface_def* in)
{
	in->interface_name->visit(this);
	in->extends->visit(this);
	in->members->visit(this);
}

void Tree_visitor::post_interface_def(AST_interface_def* in)
{
}

void Tree_visitor::pre_class_def(AST_class_def* in)
{
}

void Tree_visitor::children_class_def(AST_class_def* in)
{
	in->class_mod->visit(this);
	in->class_name->visit(this);
	if(in->extends != NULL)
	in->extends->visit(this);
	in->implements->visit(this);
	in->members->visit(this);
}

void Tree_visitor::post_class_def(AST_class_def* in)
{
}

void Tree_visitor::pre_class_mod(AST_class_mod* in)
{
}

void Tree_visitor::children_class_mod(AST_class_mod* in)
{
}

void Tree_visitor::post_class_mod(AST_class_mod* in)
{
}

void Tree_visitor::pre_member(AST_member* in)
{
}

void Tree_visitor::post_member(AST_member* in)
{
}

void Tree_visitor::pre_method(AST_method* in)
{
}

void Tree_visitor::children_method(AST_method* in)
{
	in->signature->visit(this);
	if(in->statements != NULL)
	in->statements->visit(this);
}

void Tree_visitor::post_method(AST_method* in)
{
}

void Tree_visitor::pre_signature(AST_signature* in)
{
}

void Tree_visitor::children_signature(AST_signature* in)
{
	in->method_mod->visit(this);
	in->method_name->visit(this);
	in->formal_parameters->visit(this);
}

void Tree_visitor::post_signature(AST_signature* in)
{
}

void Tree_visitor::pre_method_mod(AST_method_mod* in)
{
}

void Tree_visitor::children_method_mod(AST_method_mod* in)
{
}

void Tree_visitor::post_method_mod(AST_method_mod* in)
{
}

void Tree_visitor::pre_formal_parameter(AST_formal_parameter* in)
{
}

void Tree_visitor::children_formal_parameter(AST_formal_parameter* in)
{
	in->type->visit(this);
	in->variable_name->visit(this);
	if(in->expr != NULL)
	in->expr->visit(this);
}

void Tree_visitor::post_formal_parameter(AST_formal_parameter* in)
{
}

void Tree_visitor::pre_type(AST_type* in)
{
}

void Tree_visitor::children_type(AST_type* in)
{
	if(in->class_name != NULL)
	in->class_name->visit(this);
}

void Tree_visitor::post_type(AST_type* in)
{
}

void Tree_visitor::pre_attribute(AST_attribute* in)
{
}

void Tree_visitor::children_attribute(AST_attribute* in)
{
	in->attr_mod->visit(this);
	in->variable_name->visit(this);
	if(in->expr != NULL)
	in->expr->visit(this);
}

void Tree_visitor::post_attribute(AST_attribute* in)
{
}

void Tree_visitor::pre_attr_mod(AST_attr_mod* in)
{
}

void Tree_visitor::children_attr_mod(AST_attr_mod* in)
{
}

void Tree_visitor::post_attr_mod(AST_attr_mod* in)
{
}

void Tree_visitor::pre_statement(AST_statement* in)
{
}

void Tree_visitor::post_statement(AST_statement* in)
{
}

void Tree_visitor::pre_if(AST_if* in)
{
}

void Tree_visitor::children_if(AST_if* in)
{
	in->expr->visit(this);
	in->iftrue->visit(this);
	in->iffalse->visit(this);
}

void Tree_visitor::post_if(AST_if* in)
{
}

void Tree_visitor::pre_while(AST_while* in)
{
}

void Tree_visitor::children_while(AST_while* in)
{
	in->expr->visit(this);
	in->statements->visit(this);
}

void Tree_visitor::post_while(AST_while* in)
{
}

void Tree_visitor::pre_do(AST_do* in)
{
}

void Tree_visitor::children_do(AST_do* in)
{
	in->statements->visit(this);
	in->expr->visit(this);
}

void Tree_visitor::post_do(AST_do* in)
{
}

void Tree_visitor::pre_for(AST_for* in)
{
}

void Tree_visitor::children_for(AST_for* in)
{
	if(in->init != NULL)
	in->init->visit(this);
	if(in->cond != NULL)
	in->cond->visit(this);
	if(in->incr != NULL)
	in->incr->visit(this);
	in->statements->visit(this);
}

void Tree_visitor::post_for(AST_for* in)
{
}

void Tree_visitor::pre_foreach(AST_foreach* in)
{
}

void Tree_visitor::children_foreach(AST_foreach* in)
{
	in->expr->visit(this);
	if(in->key != NULL)
	in->key->visit(this);
	in->val->visit(this);
	in->statements->visit(this);
}

void Tree_visitor::post_foreach(AST_foreach* in)
{
}

void Tree_visitor::pre_switch(AST_switch* in)
{
}

void Tree_visitor::children_switch(AST_switch* in)
{
	in->expr->visit(this);
	in->switch_cases->visit(this);
}

void Tree_visitor::post_switch(AST_switch* in)
{
}

void Tree_visitor::pre_switch_case(AST_switch_case* in)
{
}

void Tree_visitor::children_switch_case(AST_switch_case* in)
{
	if(in->expr != NULL)
	in->expr->visit(this);
	in->statements->visit(this);
}

void Tree_visitor::post_switch_case(AST_switch_case* in)
{
}

void Tree_visitor::pre_break(AST_break* in)
{
}

void Tree_visitor::children_break(AST_break* in)
{
	if(in->expr != NULL)
	in->expr->visit(this);
}

void Tree_visitor::post_break(AST_break* in)
{
}

void Tree_visitor::pre_continue(AST_continue* in)
{
}

void Tree_visitor::children_continue(AST_continue* in)
{
	if(in->expr != NULL)
	in->expr->visit(this);
}

void Tree_visitor::post_continue(AST_continue* in)
{
}

void Tree_visitor::pre_return(AST_return* in)
{
}

void Tree_visitor::children_return(AST_return* in)
{
	if(in->expr != NULL)
	in->expr->visit(this);
}

void Tree_visitor::post_return(AST_return* in)
{
}

void Tree_visitor::pre_static_declaration(AST_static_declaration* in)
{
}

void Tree_visitor::children_static_declaration(AST_static_declaration* in)
{
	in->variable_name->visit(this);
	if(in->expr != NULL)
	in->expr->visit(this);
}

void Tree_visitor::post_static_declaration(AST_static_declaration* in)
{
}

void Tree_visitor::pre_unset(AST_unset* in)
{
}

void Tree_visitor::children_unset(AST_unset* in)
{
	in->variable->visit(this);
}

void Tree_visitor::post_unset(AST_unset* in)
{
}

void Tree_visitor::pre_declare(AST_declare* in)
{
}

void Tree_visitor::children_declare(AST_declare* in)
{
	in->directives->visit(this);
	in->statements->visit(this);
}

void Tree_visitor::post_declare(AST_declare* in)
{
}

void Tree_visitor::pre_directive(AST_directive* in)
{
}

void Tree_visitor::children_directive(AST_directive* in)
{
	in->directive_name->visit(this);
	in->expr->visit(this);
}

void Tree_visitor::post_directive(AST_directive* in)
{
}

void Tree_visitor::pre_try(AST_try* in)
{
}

void Tree_visitor::children_try(AST_try* in)
{
	in->statements->visit(this);
	in->catches->visit(this);
}

void Tree_visitor::post_try(AST_try* in)
{
}

void Tree_visitor::pre_catch(AST_catch* in)
{
}

void Tree_visitor::children_catch(AST_catch* in)
{
	in->class_name->visit(this);
	in->variable_name->visit(this);
	in->statements->visit(this);
}

void Tree_visitor::post_catch(AST_catch* in)
{
}

void Tree_visitor::pre_throw(AST_throw* in)
{
}

void Tree_visitor::children_throw(AST_throw* in)
{
	in->expr->visit(this);
}

void Tree_visitor::post_throw(AST_throw* in)
{
}

void Tree_visitor::pre_eval_expr(AST_eval_expr* in)
{
}

void Tree_visitor::children_eval_expr(AST_eval_expr* in)
{
	in->expr->visit(this);
}

void Tree_visitor::post_eval_expr(AST_eval_expr* in)
{
}

void Tree_visitor::pre_expr(AST_expr* in)
{
}

void Tree_visitor::post_expr(AST_expr* in)
{
}

void Tree_visitor::pre_literal(AST_literal* in)
{
}

void Tree_visitor::post_literal(AST_literal* in)
{
}

void Tree_visitor::pre_assignment(AST_assignment* in)
{
}

void Tree_visitor::children_assignment(AST_assignment* in)
{
	in->variable->visit(this);
	in->expr->visit(this);
}

void Tree_visitor::post_assignment(AST_assignment* in)
{
}

void Tree_visitor::pre_list_assignment(AST_list_assignment* in)
{
}

void Tree_visitor::children_list_assignment(AST_list_assignment* in)
{
	in->list_elements->visit(this);
	in->expr->visit(this);
}

void Tree_visitor::post_list_assignment(AST_list_assignment* in)
{
}

void Tree_visitor::pre_list_elements(AST_list_elements* in)
{
}

void Tree_visitor::children_list_elements(AST_list_elements* in)
{
	in->list_elements->visit(this);
}

void Tree_visitor::post_list_elements(AST_list_elements* in)
{
}

void Tree_visitor::pre_list_element(AST_list_element* in)
{
}

void Tree_visitor::post_list_element(AST_list_element* in)
{
}

void Tree_visitor::pre_cast(AST_cast* in)
{
}

void Tree_visitor::children_cast(AST_cast* in)
{
	in->cast->visit(this);
	in->expr->visit(this);
}

void Tree_visitor::post_cast(AST_cast* in)
{
}

void Tree_visitor::pre_unary_op(AST_unary_op* in)
{
}

void Tree_visitor::children_unary_op(AST_unary_op* in)
{
	in->op->visit(this);
	in->expr->visit(this);
}

void Tree_visitor::post_unary_op(AST_unary_op* in)
{
}

void Tree_visitor::pre_bin_op(AST_bin_op* in)
{
}

void Tree_visitor::children_bin_op(AST_bin_op* in)
{
	in->left->visit(this);
	in->op->visit(this);
	in->right->visit(this);
}

void Tree_visitor::post_bin_op(AST_bin_op* in)
{
}

void Tree_visitor::pre_conditional_expr(AST_conditional_expr* in)
{
}

void Tree_visitor::children_conditional_expr(AST_conditional_expr* in)
{
	in->cond->visit(this);
	in->iftrue->visit(this);
	in->iffalse->visit(this);
}

void Tree_visitor::post_conditional_expr(AST_conditional_expr* in)
{
}

void Tree_visitor::pre_ignore_errors(AST_ignore_errors* in)
{
}

void Tree_visitor::children_ignore_errors(AST_ignore_errors* in)
{
	in->expr->visit(this);
}

void Tree_visitor::post_ignore_errors(AST_ignore_errors* in)
{
}

void Tree_visitor::pre_constant(AST_constant* in)
{
}

void Tree_visitor::children_constant(AST_constant* in)
{
	in->class_name->visit(this);
	in->constant_name->visit(this);
}

void Tree_visitor::post_constant(AST_constant* in)
{
}

void Tree_visitor::pre_instanceof(AST_instanceof* in)
{
}

void Tree_visitor::children_instanceof(AST_instanceof* in)
{
	in->expr->visit(this);
	in->class_name->visit(this);
}

void Tree_visitor::post_instanceof(AST_instanceof* in)
{
}

void Tree_visitor::pre_variable(AST_variable* in)
{
}

void Tree_visitor::children_variable(AST_variable* in)
{
	if(in->target != NULL)
	in->target->visit(this);
	in->variable_name->visit(this);
	in->array_indices->visit(this);
	if(in->string_index != NULL)
	in->string_index->visit(this);
}

void Tree_visitor::post_variable(AST_variable* in)
{
}

void Tree_visitor::pre_variable_name(AST_variable_name* in)
{
}

void Tree_visitor::post_variable_name(AST_variable_name* in)
{
}

void Tree_visitor::pre_reflection(AST_reflection* in)
{
}

void Tree_visitor::children_reflection(AST_reflection* in)
{
	in->expr->visit(this);
}

void Tree_visitor::post_reflection(AST_reflection* in)
{
}

void Tree_visitor::pre_target(AST_target* in)
{
}

void Tree_visitor::post_target(AST_target* in)
{
}

void Tree_visitor::pre_pre_op(AST_pre_op* in)
{
}

void Tree_visitor::children_pre_op(AST_pre_op* in)
{
	in->op->visit(this);
	in->variable->visit(this);
}

void Tree_visitor::post_pre_op(AST_pre_op* in)
{
}

void Tree_visitor::pre_post_op(AST_post_op* in)
{
}

void Tree_visitor::children_post_op(AST_post_op* in)
{
	in->variable->visit(this);
	in->op->visit(this);
}

void Tree_visitor::post_post_op(AST_post_op* in)
{
}

void Tree_visitor::pre_array(AST_array* in)
{
}

void Tree_visitor::children_array(AST_array* in)
{
	in->array_elems->visit(this);
}

void Tree_visitor::post_array(AST_array* in)
{
}

void Tree_visitor::pre_array_elem(AST_array_elem* in)
{
}

void Tree_visitor::children_array_elem(AST_array_elem* in)
{
	if(in->key != NULL)
	in->key->visit(this);
	in->val->visit(this);
}

void Tree_visitor::post_array_elem(AST_array_elem* in)
{
}

void Tree_visitor::pre_method_invocation(AST_method_invocation* in)
{
}

void Tree_visitor::children_method_invocation(AST_method_invocation* in)
{
	in->target->visit(this);
	in->method_name->visit(this);
	in->actual_parameters->visit(this);
}

void Tree_visitor::post_method_invocation(AST_method_invocation* in)
{
}

void Tree_visitor::pre_method_name(AST_method_name* in)
{
}

void Tree_visitor::post_method_name(AST_method_name* in)
{
}

void Tree_visitor::pre_actual_parameter(AST_actual_parameter* in)
{
}

void Tree_visitor::children_actual_parameter(AST_actual_parameter* in)
{
	in->expr->visit(this);
}

void Tree_visitor::post_actual_parameter(AST_actual_parameter* in)
{
}

void Tree_visitor::pre_new(AST_new* in)
{
}

void Tree_visitor::children_new(AST_new* in)
{
	in->class_name->visit(this);
	in->actual_parameters->visit(this);
}

void Tree_visitor::post_new(AST_new* in)
{
}

void Tree_visitor::pre_class_name(AST_class_name* in)
{
}

void Tree_visitor::post_class_name(AST_class_name* in)
{
}

void Tree_visitor::pre_clone(AST_clone* in)
{
}

void Tree_visitor::children_clone(AST_clone* in)
{
	in->expr->visit(this);
}

void Tree_visitor::post_clone(AST_clone* in)
{
}

void Tree_visitor::pre_node(AST_node* in)
{
}

void Tree_visitor::post_node(AST_node* in)
{
}

void Tree_visitor::pre_commented_node(AST_commented_node* in)
{
}

void Tree_visitor::post_commented_node(AST_commented_node* in)
{
}

void Tree_visitor::pre_identifier(AST_identifier* in)
{
}

void Tree_visitor::post_identifier(AST_identifier* in)
{
}

void Tree_visitor::pre_interface_name(Token_interface_name* in)
{
}

void Tree_visitor::children_interface_name(Token_interface_name* in)
{
}

void Tree_visitor::post_interface_name(Token_interface_name* in)
{
}

void Tree_visitor::pre_class_name(Token_class_name* in)
{
}

void Tree_visitor::children_class_name(Token_class_name* in)
{
}

void Tree_visitor::post_class_name(Token_class_name* in)
{
}

void Tree_visitor::pre_method_name(Token_method_name* in)
{
}

void Tree_visitor::children_method_name(Token_method_name* in)
{
}

void Tree_visitor::post_method_name(Token_method_name* in)
{
}

void Tree_visitor::pre_variable_name(Token_variable_name* in)
{
}

void Tree_visitor::children_variable_name(Token_variable_name* in)
{
}

void Tree_visitor::post_variable_name(Token_variable_name* in)
{
}

void Tree_visitor::pre_directive_name(Token_directive_name* in)
{
}

void Tree_visitor::children_directive_name(Token_directive_name* in)
{
}

void Tree_visitor::post_directive_name(Token_directive_name* in)
{
}

void Tree_visitor::pre_int(Token_int* in)
{
}

void Tree_visitor::children_int(Token_int* in)
{
}

void Tree_visitor::post_int(Token_int* in)
{
}

void Tree_visitor::pre_real(Token_real* in)
{
}

void Tree_visitor::children_real(Token_real* in)
{
}

void Tree_visitor::post_real(Token_real* in)
{
}

void Tree_visitor::pre_string(Token_string* in)
{
}

void Tree_visitor::children_string(Token_string* in)
{
}

void Tree_visitor::post_string(Token_string* in)
{
}

void Tree_visitor::pre_bool(Token_bool* in)
{
}

void Tree_visitor::children_bool(Token_bool* in)
{
}

void Tree_visitor::post_bool(Token_bool* in)
{
}

void Tree_visitor::pre_null(Token_null* in)
{
}

void Tree_visitor::children_null(Token_null* in)
{
}

void Tree_visitor::post_null(Token_null* in)
{
}

void Tree_visitor::pre_cast(Token_cast* in)
{
}

void Tree_visitor::children_cast(Token_cast* in)
{
}

void Tree_visitor::post_cast(Token_cast* in)
{
}

void Tree_visitor::pre_op(Token_op* in)
{
}

void Tree_visitor::children_op(Token_op* in)
{
}

void Tree_visitor::post_op(Token_op* in)
{
}

void Tree_visitor::pre_constant_name(Token_constant_name* in)
{
}

void Tree_visitor::children_constant_name(Token_constant_name* in)
{
}

void Tree_visitor::post_constant_name(Token_constant_name* in)
{
}

void Tree_visitor::pre_interface_def_list(AST_interface_def_list* in)
{
}

void Tree_visitor::children_interface_def_list(AST_interface_def_list* in)
{
	List<AST_interface_def*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_interface_def_list(AST_interface_def_list* in)
{
}

void Tree_visitor::pre_class_def_list(AST_class_def_list* in)
{
}

void Tree_visitor::children_class_def_list(AST_class_def_list* in)
{
	List<AST_class_def*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_class_def_list(AST_class_def_list* in)
{
}

void Tree_visitor::pre_interface_name_list(Token_interface_name_list* in)
{
}

void Tree_visitor::children_interface_name_list(Token_interface_name_list* in)
{
	List<Token_interface_name*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_interface_name_list(Token_interface_name_list* in)
{
}

void Tree_visitor::pre_member_list(AST_member_list* in)
{
}

void Tree_visitor::children_member_list(AST_member_list* in)
{
	List<AST_member*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_member_list(AST_member_list* in)
{
}

void Tree_visitor::pre_statement_list(AST_statement_list* in)
{
}

void Tree_visitor::children_statement_list(AST_statement_list* in)
{
	List<AST_statement*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_statement_list(AST_statement_list* in)
{
}

void Tree_visitor::pre_formal_parameter_list(AST_formal_parameter_list* in)
{
}

void Tree_visitor::children_formal_parameter_list(AST_formal_parameter_list* in)
{
	List<AST_formal_parameter*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_formal_parameter_list(AST_formal_parameter_list* in)
{
}

void Tree_visitor::pre_switch_case_list(AST_switch_case_list* in)
{
}

void Tree_visitor::children_switch_case_list(AST_switch_case_list* in)
{
	List<AST_switch_case*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_switch_case_list(AST_switch_case_list* in)
{
}

void Tree_visitor::pre_directive_list(AST_directive_list* in)
{
}

void Tree_visitor::children_directive_list(AST_directive_list* in)
{
	List<AST_directive*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_directive_list(AST_directive_list* in)
{
}

void Tree_visitor::pre_catch_list(AST_catch_list* in)
{
}

void Tree_visitor::children_catch_list(AST_catch_list* in)
{
	List<AST_catch*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_catch_list(AST_catch_list* in)
{
}

void Tree_visitor::pre_list_element_list(AST_list_element_list* in)
{
}

void Tree_visitor::children_list_element_list(AST_list_element_list* in)
{
	List<AST_list_element*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_list_element_list(AST_list_element_list* in)
{
}

void Tree_visitor::pre_expr_list(AST_expr_list* in)
{
}

void Tree_visitor::children_expr_list(AST_expr_list* in)
{
	List<AST_expr*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_expr_list(AST_expr_list* in)
{
}

void Tree_visitor::pre_array_elem_list(AST_array_elem_list* in)
{
}

void Tree_visitor::children_array_elem_list(AST_array_elem_list* in)
{
	List<AST_array_elem*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_array_elem_list(AST_array_elem_list* in)
{
}

void Tree_visitor::pre_actual_parameter_list(AST_actual_parameter_list* in)
{
}

void Tree_visitor::children_actual_parameter_list(AST_actual_parameter_list* in)
{
	List<AST_actual_parameter*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void Tree_visitor::post_actual_parameter_list(AST_actual_parameter_list* in)
{
}
