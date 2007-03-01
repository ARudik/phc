/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Prepare the AST for code generation (desugaring) 
 */

#ifndef PHC_PREP_H
#define PHC_PREP_H

#include "generated/Tree_transform.h"

class Prep : public Tree_transform
{
public:
	Token_method_name* post_method_name(Token_method_name* in);
	AST_expr* post_assignment(AST_assignment* in);
	void post_unset(AST_unset* in, AST_statement_list* out);
};

#endif // PHC_PREP_H
