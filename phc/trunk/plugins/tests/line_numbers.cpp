/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 *
 * Compare the semantic value of tokens against their source representation
 */

#include "generated/Tree_visitor.h"
#include "process_ast/PHP_unparser.h"

class Print_line_numbers : public Tree_visitor
{
	String delimiter;
	bool read;
public:

	Print_line_numbers()
		:	delimiter("--!!--!!--"),
			read(false)
	{
		
	}

	void pre_if(AST_if* in)
	{
		cout << "if:" << in->get_line_number() << delimiter;
	}

	void pre_while(AST_while* in)
	{
		cout << "while:" << in->get_line_number() << delimiter;
	}

	void pre_do(AST_do* in)
	{
		cout << "do:" << in->get_line_number() << delimiter;
	}

	void pre_for(AST_for* in)
	{
		cout << "for:" << in->get_line_number() << delimiter;
	}

	void pre_foreach(AST_foreach* in)
	{
		cout << "foreach:" << in->get_line_number() << delimiter;
	}

	void pre_switch(AST_switch* in)
	{
		cout << "switch:" << in->get_line_number() << delimiter;
	}

	void pre_switch_case(AST_switch_case* in)
	{
		cout << "case:" << in->get_line_number() << delimiter;
	}

	void pre_break(AST_break* in)
	{
		cout << "break:" << in->get_line_number() << delimiter;
	}

	void pre_continue(AST_continue* in)
	{
		cout << "continue:" << in->get_line_number() << delimiter;
	}

	void pre_return(AST_return* in)
	{
		cout << "return:" << in->get_line_number() << delimiter;
	}

	void pre_try(AST_try* in)
	{
		cout << "try:" << in->get_line_number() << delimiter;
	}

	void pre_catch(AST_catch* in)
	{
		cout << "catch:" << in->get_line_number() << delimiter;
	}

	void pre_throw(AST_throw* in)
	{
		cout << "throw:" << in->get_line_number() << delimiter;
	}

	void pre_new(AST_new* in)
	{
		cout << "new:" << in->get_line_number() << delimiter;
	}

	void pre_interface_name(Token_interface_name* in)
	{
		cout << *in->value << ":" << in->get_line_number() << delimiter;
	}

	void pre_class_name(Token_class_name* in)
	{
		String* class_name = in->value;
		if (*class_name != "%MAIN%" and *class_name != "%STDLIB%")
		{
			cout << *class_name << ":" << in->get_line_number() << delimiter;
		}
	}

	void pre_method_name(Token_method_name* in)
	{
		/* this could also check that it's in the main class, but its a tad
		 * complicated for the incredibly limited benefit
		 */
		String* method_name = in->value;
		if (*method_name != "%run%") 
		{
			cout << *method_name << ":" << in->get_line_number() << delimiter;
		}
	}

	void pre_variable_name(Token_variable_name* in)
	{
		cout << *in->value << ":" << in->get_line_number() << delimiter;
	}

	void pre_directive_name(Token_directive_name* in)
	{
		cout << *in->value << ":" << in->get_line_number() << delimiter;
	}

	void pre_cast(Token_cast* in)
	{
		cout << *in->value << ":" << in->get_line_number() << delimiter;
	}

	void pre_op(Token_op* in)
	{
		cout << *in->value << ":" << in->get_line_number() << delimiter;
	}

	void pre_constant_name(Token_constant_name* in)
	{
		cout << *in->value << ":" << in->get_line_number() << delimiter;
	}

	// this here is a special case, since the PHP-unparser does funkyness, and
	// it's difficult to undo it using the test script. Solution, use the
	// PHP_unparser
	void pre_literal(AST_literal* in)
	{
		in->visit(new PHP_unparser());
		cout << ":" << in->get_line_number() << delimiter;
		read = false;
	}


};

extern "C" void process_ast(AST_php_script* script)
{
	Print_line_numbers gsasv;
	script->visit(&gsasv);
	cout << endl;
}
