/* 
 * phc -- the open source PHP compiler 
 * See license/README.license for licensing information
 *
 * Replaces an include statement with the parsed contents of the included file.
 */

#ifndef PHC_PROCESS_INCLUDES
#define PHC_PROCESS_INCLUDES

#include "generated/Tree_transform.h"

class Process_includes : public Tree_transform
{
public:
	AST_php_script* current_script; // stores a record of the current script
	bool in_main_run; // indicates that the currently traversed method is %MAIN%::%RUN%

public:
	AST_php_script* pre_php_script(AST_php_script* in);
	void pre_method(AST_method* in, AST_member_list* out);
	void pre_eval_expr(AST_eval_expr* in, AST_statement_list* out);

};

#endif // PHC_PROCESS_INCLUDES
