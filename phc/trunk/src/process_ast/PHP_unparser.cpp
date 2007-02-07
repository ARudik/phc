/*
 * phc -- the open source PHP compiler
 * Unparse the AST back to PHP syntax
 */

#include <iostream>
#include <iomanip> 
#include "PHP_unparser.h" 
#include "generated/cmdline.h"

extern struct gengetopt_args_info args_info;

using namespace std;

void PHP_unparser::echo(const char* str)
{
	output_tabs();
	os << str;
}

void PHP_unparser::echo_nl(const char* s)
{
	echo(s);
	newline();
}

void PHP_unparser::echo(String* str)
{
	output_tabs();
	os << *str;
}

void PHP_unparser::echo_escaped(string *s)
{
	output_tabs();

	string::iterator i;
	for(i = s->begin(); i != s->end(); i++)
	{
		switch(*i)
		{
			case '\n':
				os << "\\n";
				break;
			case '\r':
				os << "\\r";
				break;
			case '\t':
				os << "\\t";
				break;
			case '\\':
			case '$':
			case '"':
				os << "\\" << *i;
				break;
			default:
				if(*i < 32 || *i == 127)
				{
					os << "\\x" << setw(2) <<
						setfill('0') << hex << uppercase << (unsigned long int)(unsigned char)*i;
					os << resetiosflags(cout.flags());
				}
				else
					os << *i;
				break;
		}
	}
}

void PHP_unparser::inc_indent()
{
	indent_level++;
	newline();
}

void PHP_unparser::dec_indent()
{
	indent_level--;
	newline();
}

void PHP_unparser::newline()
{
	if(!at_start_of_line)
	{
		at_start_of_line = true;
		os << endl;
	}
}

void PHP_unparser::output_tabs()
{
	if(at_start_of_line)
		for(long i = 0; i < indent_level; i++)
			os << args_info.tab_arg;

	at_start_of_line = false;
}

void PHP_unparser::empty_line()
{
	at_start_of_line = true;
	os << endl;
}

PHP_unparser::PHP_unparser(ostream& os) : os(os)
{
	indent_level = 0;
	at_start_of_line = true;
	inside_main = false;
}

void PHP_unparser::children_php_script(AST_php_script* in)
{
	echo("<?php");
	inc_indent();

	in->interface_defs->visit(this);
	in->class_defs->visit(this);

	dec_indent();
	echo_nl("?>");
}

void PHP_unparser::children_interface_def(AST_interface_def* in)
{
	echo("interface ");
	in->interface_name->visit(this);

	if(!in->extends->empty())
	{
		echo(" extends ");
		in->extends->visit(this);
	}
	
	newline();
	echo_nl("{");
	inc_indent();
	in->members->visit(this);
	dec_indent();
	echo_nl("}");
}

// %MAIN% is treated specially in AST_class_def_list
void PHP_unparser::children_class_def(AST_class_def* in)
{
	in->class_mod->visit(this);
	echo("class ");
	in->class_name->visit(this);

	if(in->extends != NULL)
	{
		echo(" extends ");
		in->extends->visit(this);
	}
	
	if(!in->implements->empty())
	{
		echo(" implements ");
		in->implements->visit(this);
	}
	
	newline();
	echo_nl("{");
	inc_indent();
	in->members->visit(this);
	dec_indent();
	echo_nl("}");
}

void PHP_unparser::children_class_mod(AST_class_mod* in)
{
	if(in->is_abstract) echo("abstract ");
	if(in->is_final) echo("final ");
}

// "%run%" is treated specially in AST_member_list
void PHP_unparser::children_method(AST_method* in)
{
	in->signature->visit(this);
	if(in->statements != NULL)
		in->statements->visit(this);
	else
		// Abstract method
		echo_nl(";");
}

void PHP_unparser::children_signature(AST_signature* in)
{
	if(!inside_main)
		in->method_mod->visit(this);

	echo("function ");
	if(in->is_ref) echo("&");
	in->method_name->visit(this);
	in->formal_parameters->visit(this);
}

void PHP_unparser::children_method_mod(AST_method_mod* in)
{
	if(in->is_public)		echo("public ");
	if(in->is_protected)	echo("protected ");
	if(in->is_private)	echo("private ");
	if(in->is_static)		echo("static ");
	if(in->is_abstract)	echo("abstract ");
	if(in->is_final)		echo("final ");
}

void PHP_unparser::children_formal_parameter(AST_formal_parameter* in)
{
	in->type->visit(this);
	if(in->is_ref) echo("&");
	echo("$");
	in->variable_name->visit(this);
	if(in->expr != NULL)
	{
		echo(" = ");
		in->expr->visit(this);
	}
}

void PHP_unparser::children_type(AST_type* in)
{
	if(in->is_array) echo("array ");
	if(in->class_name != NULL)
	{
		in->class_name->visit(this);
		echo(" ");
	}
}

void PHP_unparser::children_attribute(AST_attribute* in)
{
	in->attr_mod->visit(this);
	// Class attributes get a dollar sign, with the exception of const attributes
	if(!in->attr_mod->is_const) echo("$"); 
	in->variable_name->visit(this);
	if(in->expr != NULL)
	{
		echo(" = ");
		in->expr->visit(this);
	}
	echo_nl(";");
}

void PHP_unparser::children_attr_mod(AST_attr_mod* in)
{
	if(in->is_public)		echo("public ");
	if(in->is_protected)	echo("protected ");
	if(in->is_private)	echo("private ");
	if(in->is_static)		echo("static ");
	if(in->is_const)		echo("const ");

	if(!in->is_public && 
		!in->is_protected && 
		!in->is_private && 
		!in->is_static && 
		!in->is_const)
			echo("var ");
}

void PHP_unparser::children_if(AST_if* in)
{
	if(in->attrs->get_boolean("phc.unparser.is_elseif")->value())
		echo("elseif(");
	else
		echo("if(");

	in->expr->visit(this);
	echo_nl(")");
	
	in->iftrue->visit(this);
	
	if(!in->iffalse->empty())
	{
		AST_if* elseif = dynamic_cast<AST_if*>(in->iffalse->front());

		if(elseif && elseif->attrs->get_boolean("phc.unparser.is_elseif")->value())
		{
			elseif->visit(this);
		}
		else
		{
			echo_nl("else");
			in->iffalse->visit(this);
		}
	}
}

void PHP_unparser::children_while(AST_while* in)
{
	echo("while(");
	in->expr->visit(this);
	echo_nl(")");
	in->statements->visit(this);
}

void PHP_unparser::children_do(AST_do* in)
{
	echo_nl("do");
	in->statements->visit(this);
	echo("while(");
	in->expr->visit(this);
	echo_nl(");");
}

void PHP_unparser::children_for(AST_for* in)
{
	echo("for(");
	if(in->init != NULL) in->init->visit(this);
	echo("; ");
	if(in->cond != NULL) in->cond->visit(this);
	echo("; ");
	if(in->incr != NULL) in->incr->visit(this);
	echo_nl(")");
	in->statements->visit(this);
}

void PHP_unparser::children_foreach(AST_foreach* in)
{
	echo("foreach(");
	in->expr->visit(this);
	echo(" as ");
	if(in->key != NULL) 
	{
		in->key->visit(this);
		echo(" => ");
	}
	if(in->is_ref) echo("&");
	in->val->visit(this);
	echo_nl(")");
	in->statements->visit(this);
}

void PHP_unparser::children_switch(AST_switch* in)
{
	echo("switch(");
	in->expr->visit(this);
	echo_nl(")");
	in->switch_cases->visit(this);
}

void PHP_unparser::children_switch_case(AST_switch_case* in)
{
	if(in->expr != NULL)
	{
		echo("case ");
		in->expr->visit(this);
		echo_nl(":");
	}
	else
	{
		echo_nl("default:");
	}

	// We don't want curlies here
	inc_indent();

	List<AST_statement*>::const_iterator i;
	for(i = in->statements->begin(); i != in->statements->end(); i++)
		(*i)->visit(this);

	dec_indent();
}

void PHP_unparser::children_break(AST_break* in)
{
	echo("break");
	if(in->expr != NULL)
	{
		echo(" ");
		in->expr->visit(this);
	}
	echo_nl(";");
}

void PHP_unparser::children_continue(AST_continue* in)
{
	echo("continue");
	if(in->expr != NULL)
	{
		echo(" ");
		in->expr->visit(this);
	}
	echo_nl(";");
}

void PHP_unparser::children_return(AST_return* in)
{
	echo("return");
	if(in->expr != NULL)
	{
		echo(" ");
		in->expr->visit(this);
	}
	echo_nl(";");
}

void PHP_unparser::children_static_declaration(AST_static_declaration* in)
{
	echo("static $");
	in->variable_name->visit(this);
	if(in->expr != NULL)
	{
		echo(" = ");
		in->expr->visit(this);
	}
	echo_nl(";");
}

void PHP_unparser::children_unset(AST_unset* in)
{
	echo("unset(");
	in->variable->visit(this);
	echo_nl(");");
}

void PHP_unparser::children_declare(AST_declare* in)
{
	echo("declare");
	in->directives->visit(this);

	if(!in->statements->empty())
		in->statements->visit(this);
	else
		echo_nl(";");
}

void PHP_unparser::children_directive(AST_directive* in)
{
	in->directive_name->visit(this);
	echo(" = ");
	in->expr->visit(this);
}

void PHP_unparser::children_try(AST_try* in)
{
	echo_nl("try");
	in->statements->visit(this);
	in->catches->visit(this);
}

void PHP_unparser::children_catch(AST_catch* in)
{
	echo("catch(");
	in->class_name->visit(this);
	echo(" $");
	in->variable_name->visit(this);
	echo_nl(")");
	in->statements->visit(this);
}

void PHP_unparser::children_throw(AST_throw* in)
{
	echo("throw ");
	in->expr->visit(this);
	echo_nl(";");
}

void PHP_unparser::children_eval_expr(AST_eval_expr* in)
{
	in->expr->visit(this);
	echo_nl(";");
}

void PHP_unparser::children_assignment(AST_assignment* in)
{
	if(in->attrs->get_boolean("phc.unparser.is_global_stmt")->value())
	{
		echo("global ");
		in->variable->visit(this);
	}
	else
	{
		in->variable->visit(this);

		if(in->is_ref)
			echo(" = &");
		else
			echo(" = ");

		in->expr->visit(this);
	}
}

void PHP_unparser::children_list_assignment(AST_list_assignment* in)
{
	in->list_elements->visit(this);
	echo(" = ");
	in->expr->visit(this);
}

void PHP_unparser::children_list_elements(AST_list_elements* in)
{
	echo("list");
	in->list_elements->visit(this);
}

void PHP_unparser::children_cast(AST_cast* in)
{
	echo("(");
	in->cast->visit(this);
	echo(") ");
	in->expr->visit(this);
}

void PHP_unparser::children_unary_op(AST_unary_op* in)
{
	in->op->visit(this);
	in->expr->visit(this);
}

void PHP_unparser::children_bin_op(AST_bin_op* in)
{
	in->left->visit(this);
	// We output "3 + 5", but "3, 5"
	if(*in->op->value != ",") echo(" ");
	in->op->visit(this);
	echo(" ");
	in->right->visit(this);
}

void PHP_unparser::children_conditional_expr(AST_conditional_expr* in)
{
	in->cond->visit(this);
	echo(" ? ");
	in->iftrue->visit(this);
	echo(" : ");
	in->iffalse->visit(this);
}

void PHP_unparser::children_ignore_errors(AST_ignore_errors* in)
{
	echo("@");
	in->expr->visit(this);
}

void PHP_unparser::children_constant(AST_constant* in)
{
	if((*in->class_name->value)[0] == '%')
	{
		in->constant_name->visit(this);
	}
	else
	{
		in->class_name->visit(this);
		echo("::");
		in->constant_name->visit(this);
	}
}

void PHP_unparser::children_instanceof(AST_instanceof* in)
{
	in->expr->visit(this);
	echo(" instanceof ");
	in->class_name->visit(this);
}

void PHP_unparser::children_variable(AST_variable* in)
{
	AST_reflection* reflection;
	AST_variable* name = NULL;

	if(in->target != NULL)
	{
		Token_class_name* class_name = dynamic_cast<Token_class_name*>(in->target);

		if(class_name)
		{
			if((*class_name->value)[0] == '%')
			{
				echo("$");
			}
			else
			{
				class_name->visit(this);
				echo("::$");
			}
		}
		else
		{
			in->target->visit(this);
			echo("->");
		}
	}
	else
	{
		echo("$");
	}

	reflection = dynamic_cast<AST_reflection*>(in->variable_name);
	
	if(reflection)
	{
		name = dynamic_cast<AST_variable*>(reflection->expr);
		in->variable_name->visit(this);
	}
	else
	{
		in->variable_name->visit(this);
	}

	List<AST_expr*>::const_iterator i;
	for(i = in->array_indices->begin(); i != in->array_indices->end(); i++)
	{
		echo("[");
		if(*i) (*i)->visit(this);
		echo("]");
	}
	
	if(in->string_index != NULL)
	{
		echo("{");
		in->string_index->visit(this);
		echo("}");
	}
}

void PHP_unparser::children_reflection(AST_reflection* in)
{
	in->expr->visit(this);
}

void PHP_unparser::children_pre_op(AST_pre_op* in)
{
	in->op->visit(this);
	in->variable->visit(this);
}

void PHP_unparser::children_post_op(AST_post_op* in)
{
	in->variable->visit(this);
	in->op->visit(this);
}

void PHP_unparser::children_array(AST_array* in)
{
	echo("array");
	in->array_elems->visit(this);
}

void PHP_unparser::children_array_elem(AST_array_elem* in)
{
	if(in->key != NULL)
	{
		in->key->visit(this);
		echo(" => ");
	}
	if(in->is_ref) echo("&");
	in->val->visit(this);
}

void PHP_unparser::children_method_invocation(AST_method_invocation* in)
{
	bool after_arrow = false;
	bool use_brackets = true;
	Token_class_name* static_method;
	Token_method_name* method_name;

	static_method = dynamic_cast<Token_class_name*>(in->target);
	if(static_method)
	{
		if((*static_method->value)[0] == '%')
		{
			// Don't print names of phc pseudo-classes
		}
		else
		{
			static_method->visit(this);
			echo("::");
		}
	}
	else
	{
		in->target->visit(this);
		echo("->");
		after_arrow = true;
	}

	// Leave out brackets in calls in builtins
	method_name = dynamic_cast<Token_method_name*>(in->method_name);
	if(static_method && method_name && *static_method->value == "%STDLIB%")
	{
		use_brackets &= *method_name->value != "echo";
		use_brackets &= *method_name->value != "print";
		use_brackets &= *method_name->value != "include";
		use_brackets &= *method_name->value != "include_once";
		use_brackets &= *method_name->value != "require";
		use_brackets &= *method_name->value != "require_once";
		use_brackets &= *method_name->value != "use";
	}

	if(!use_brackets)
	{
		in->method_name->visit(this);
		echo(" ");	
		in->actual_parameters->visit(this);
	}
	else
	{
		in->method_name->visit(this);

		echo("(");
		in->actual_parameters->visit(this);
		echo(")");
	}
}

void PHP_unparser::children_actual_parameter(AST_actual_parameter* in)
{
	if(in->is_ref) echo("&");
	in->expr->visit(this);
}

void PHP_unparser::children_new(AST_new* in)
{
	echo("new ");
	in->class_name->visit(this);
	echo("(");
	in->actual_parameters->visit(this);
	echo(")");
}

void PHP_unparser::children_clone(AST_clone* in)
{
	echo("clone ");
	in->expr->visit(this);
}

void PHP_unparser::children_interface_def_list(AST_interface_def_list* in)
{
	List<AST_interface_def*>::const_iterator i;

	for(i = in->begin(); i != in->end(); i++)
	{
		(*i)->visit(this);
		empty_line();
	}
}

void PHP_unparser::children_class_def_list(AST_class_def_list* in)
{
	AST_class_def* main = NULL;
	List<AST_class_def*>::const_iterator i;
	bool is_first = true;

	for(i = in->begin(); i != in->end(); i++)
	{
		if(*(*i)->class_name->value == "%MAIN%")
		{
			main = *i;
		}
		else
		{
			if(!is_first) empty_line();
			(*i)->visit(this);
			is_first = false;
		}
	}

	// Treat %MAIN% specially
	if(!is_first) empty_line();
	assert(main);
	inside_main = true;
	main->members->visit(this);
	inside_main = false;
}

void PHP_unparser::children_interface_name_list(Token_interface_name_list* in)
{
	List<Token_interface_name*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
	{
		if(i != in->begin()) echo(", ");
		(*i)->visit(this);
	}
}

void PHP_unparser::children_member_list(AST_member_list* in)
{
	AST_method* run = NULL;
	bool is_first = true;

	List<AST_member*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
	{
		AST_method* method = dynamic_cast<AST_method*>(*i);
		
		// Don't output attributes of %MAIN%
		if(!method && inside_main)
		{
			continue;
		}
		// We output run at the end of %MAIN%
		if(method && *method->signature->method_name->value == "%run%")
		{
			run = method;	
		}
		// Otherwise, unparse the class member as normal
		else
		{		
			if(!is_first && method) empty_line();
			(*i)->visit(this);
			is_first = false;
		}
	}

	// Treat %run% specially
	// Rather than calling visit, we iterate over the vector manually
	// to avoid PHP_unparser::the opening and closing curlies
	if(inside_main)
	{
		assert(run);
		if(!is_first) empty_line();
		List<AST_statement*>::const_iterator j;
		for(j = run->statements->begin(); j != run->statements->end(); j++)
			(*j)->visit(this);
	}
}

void PHP_unparser::children_statement_list(AST_statement_list* in)
{
	newline();
	echo("{");
	inc_indent();

	List<AST_statement*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		(*i)->visit(this);

	dec_indent();
	echo_nl("}");
}

void PHP_unparser::children_formal_parameter_list(AST_formal_parameter_list* in)
{
	echo("(");
	List<AST_formal_parameter*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
	{
		if(i != in->begin()) echo(", ");
		(*i)->visit(this);
	}
	echo(")");
}

void PHP_unparser::children_switch_case_list(AST_switch_case_list* in)
{
	echo_nl("{");
	inc_indent();

	List<AST_switch_case*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		(*i)->visit(this);

	dec_indent();
	echo_nl("}");
}

void PHP_unparser::children_directive_list(AST_directive_list* in)
{
	echo("(");

	List<AST_directive*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
	{
		if(i != in->begin()) echo(", ");
		(*i)->visit(this);
	}
	
	echo(")");
}

void PHP_unparser::children_catch_list(AST_catch_list* in)
{
	List<AST_catch*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		(*i)->visit(this);
}

void PHP_unparser::children_list_element_list(AST_list_element_list* in)
{
	echo("(");

	List<AST_list_element*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
	{
		if(i != in->begin()) echo(", ");
		if(*i) (*i)->visit(this);
	}

	echo(")");
}

void PHP_unparser::children_expr_list(AST_expr_list* in)
{
	List<AST_expr*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
		if(*i) (*i)->visit(this);
}

void PHP_unparser::children_array_elem_list(AST_array_elem_list* in)
{
	echo("(");

	List<AST_array_elem*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
	{
		if(i != in->begin()) echo(", ");
		(*i)->visit(this);
	}

	echo(")");
}

void PHP_unparser::children_actual_parameter_list(AST_actual_parameter_list* in)
{
	List<AST_actual_parameter*>::const_iterator i;
	for(i = in->begin(); i != in->end(); i++)
	{
		if(i != in->begin()) echo(", ");
		(*i)->visit(this);
	}
}

// Token classes
void PHP_unparser::children_interface_name(Token_interface_name* in)
{
	echo(in->value);
}

void PHP_unparser::children_class_name(Token_class_name* in)
{
	echo(in->value);
}

void PHP_unparser::children_method_name(Token_method_name* in)
{
	echo(in->value);
}

void PHP_unparser::children_variable_name(Token_variable_name* in)
{
	echo(in->value);
}

void PHP_unparser::children_directive_name(Token_directive_name* in)
{
	echo(in->value);
}

void PHP_unparser::children_cast(Token_cast* in)
{
	echo(in->value);
}

void PHP_unparser::children_op(Token_op* in)
{
	echo(in->value);
}

void PHP_unparser::children_constant_name(Token_constant_name* in)
{
	echo(in->value);
}

void PHP_unparser::children_int(Token_int* in)
{
	echo(in->source_rep);
}

void PHP_unparser::children_real(Token_real* in)
{
	echo(in->source_rep);
}

void PHP_unparser::children_string(Token_string* in)
{
	if(
			*in->source_rep == "__FILE__" ||
			*in->source_rep == "__CLASS__" ||
			*in->source_rep == "__METHOD__" ||
			*in->source_rep == "__FUNCTION__"
	  )
	{
		echo(in->source_rep);
	}
	else
	{
		/* we have to jump through some hoops here to allow \x00 be in the
		 * string. Obviously it can't be in the c string, so we use a char array
		 * instead, so that we can use sizeof. */
		char escape_chars[] = 
			/* i < 32 - we dont check for zero here, it screws up the search */
			"\x00\x01\x02\x03"
			"\x04\x05\x06\x07"
			"\x08\x09\x0A\x0B"
			"\x0C\x0D\x0E\x0F"
			"\x10\x11\x12\x13"
			"\x14\x15\x16\x17"
			"\x18\x19\x1A\x1B"
			"\x1C\x1D\x1E\x1F"

			/* i == 127 */
			"\x7f"

			/* normal escape chars (this is to check if we can put these in ', so
			 * we check for ', and not ". Otherwise, these are the same characters
			 * that we check for in echo_escaped) */
			"\n\r\t\\$'";

		int length = sizeof(escape_chars) - 1; /* for the null char at the end */
		String* str_escape_chars = new String(escape_chars, length);

		if( in->source_rep->find_first_of(*str_escape_chars) == String::npos) 
		{
			echo("'");
			echo(in->source_rep);
			echo("'");
		}
		else 
		{
			echo("\"");
			echo_escaped(in->source_rep);
			echo("\"");
		}
	}
}

void PHP_unparser::children_bool(Token_bool* in)
{
	echo(in->source_rep);
}

void PHP_unparser::children_null(Token_null* in)
{
	echo(in->source_rep);
}

// Generic classes
void PHP_unparser::pre_expr(AST_expr* in)
{
	if(in->attrs->is_true("phc.unparser.needs_brackets"))
		echo("(");
	if(in->attrs->is_true("phc.unparser.needs_curlies"))
		echo("{");
}

void PHP_unparser::post_expr(AST_expr* in)
{
	if(in->attrs->is_true("phc.unparser.needs_curlies"))
		echo("}");
	if(in->attrs->is_true("phc.unparser.needs_brackets"))
		echo(")");
}

void PHP_unparser::pre_commented_node(AST_commented_node* in)
{
	List<String*>::const_iterator i;
	List<String*>* comments = in->get_comments();
	for(i = comments->begin(); i != comments->end(); i++)
	{
		echo(*i);
		newline();
	}
}
