/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * An unparser using the guidelines Zend coding guidelines; see:
 * http://framework.zend.com/manual/en/coding-standard.coding-style.html
 */

#include <ast.h>
#include <iostream>
#include <Tree_visitor.h>
#include <lib/demangle.h>
#include <process_ast/PHP_unparser.h>

using namespace std;


class Zend_Style_Unparser: public PHP_unparser
{

	public:
		static int array_elem_counter;
		static int concat_counter;
		static int logic_counter;
		static bool is_method_invocation;
		static bool in_if_expression;

	public:

		void pre_commented_node (AST_commented_node* in);
		void children_attribute (AST_attribute* in);
		void children_class_def (AST_class_def* in);
		void children_php_script (AST_php_script* in);
		void children_if (AST_if* in);
		void children_while (AST_while* in);
		void children_method (AST_method* in);
		void children_do (AST_do* in);
		void children_for (AST_for* in);
		void children_foreach (AST_foreach* in);
		void children_switch (AST_switch* in);
		void children_declare (AST_declare* in);
		void children_try (AST_try* in);
		void children_catch (AST_catch* in);
		void children_statement_list (AST_statement_list* in);
		void pre_array_elem (AST_array_elem* in);
		void post_array_elem (AST_array_elem* in);
		void children_actual_parameter (AST_actual_parameter* in);
		void children_member_list (AST_member_list* in);
		void children_bin_op (AST_bin_op* in);
};
