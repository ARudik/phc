/* 
 * phc -- the open source PHP compiler 
 * See license/README.license for licensing information
 *
 * Replace a token containing just a string representation, with one containing
 * its value aswell
 */

#ifndef PHC_TOKEN_CONVERSION
#define PHC_TOKEN_CONVERSION

#include <phc/Tree_transform.h>

class Token_conversion : public Tree_transform
{
public:
	AST_expr* pre_int(Token_int* in);
	AST_expr* pre_unary_op(AST_unary_op* in);
};

#endif // PHC_TOKEN_CONVERSION
