/* 
 * phc -- the open source PHP compiler 
 * See doc/license/README.license for licensing information
 *
 * Remove concatenations to empty strings (which are generated by the parser)
 */

#ifndef PHC_REMOVE_CONCAT_NULL
#define PHC_REMOVE_CONCAT_NULL

#include "AST_transform.h"

using namespace AST;

class Remove_concat_null : public AST_transform
{
public:
	AST_expr* post_bin_op(AST_bin_op* in);
};

#endif // PHC_REMOVE_CONCAT_NULL
