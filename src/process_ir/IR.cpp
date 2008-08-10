/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Common ancestor for the IRs 
 */

#include "IR.h"
#include "AST.h"
#include "MIR.h"
#include "hir_to_mir/HIR_to_MIR.h"
#include "ast_to_hir/AST_to_HIR.h"

using namespace IR;

int
Node::get_line_number ()
{
	Integer* i = dynamic_cast<Integer*>(attrs->get("phc.line_number"));
	if(i != NULL)
		return i->value();
	else
		return 0;
}

String*
Node::get_filename()
{
	String* result = dynamic_cast<String*>(attrs->get("phc.filename"));
	if (result == NULL)
		result = new String ("<unknown>");

	return result;
}

Node::Node()
{
	attrs = new AttrMap;
}

void
Node::copy_location (Node* source)
{
	String* filename = dynamic_cast<String*>(attrs->get("phc.filename"));
	if (filename == NULL)
		attrs->set ("phc.filename", source->get_filename ()->clone ());

	Integer* i = dynamic_cast<Integer*>(attrs->get("phc.line_number"));
	if (i == NULL)
		attrs->set ("phc.line_number", new Integer (source->get_line_number()));
}

bool
Node::equals (IR::Node* that)
{
	if (isa<AST::Node> (this))
		return dyc<AST::Node> (this)->equals (dyc<AST::Node> (that));
	else if (isa<HIR::Node> (this))
		return dyc<HIR::Node> (this)->equals (dyc<HIR::Node> (that));
	else if (isa<MIR::Node> (this))
		return dyc<MIR::Node> (this)->equals (dyc<MIR::Node> (that));

	assert (0);
}


void PHP_script::assert_valid()
{
	if(is_AST())
		as_AST()->assert_valid();
	else if (is_HIR ())
		as_HIR()->assert_valid();
	else
		as_MIR()->assert_valid();
}


// VISIT

void PHP_script::visit(AST::Visitor* ast_visitor)
{
	as_AST()->visit(ast_visitor);
}

void PHP_script::visit(HIR::Visitor* hir_visitor)
{
	as_HIR()->visit(hir_visitor);
}

void PHP_script::visit(MIR::Visitor* mir_visitor)
{
	as_MIR()->visit(mir_visitor);
}

void PHP_script::visit(AST::Visitor* ast_visitor, HIR::Visitor* hir_visitor, MIR::Visitor* mir_visitor)
{
	if(is_AST())
		visit(ast_visitor);
	else if (is_HIR ())
		visit(hir_visitor);
	else
		visit(mir_visitor);
}


// TRANSFORM

void PHP_script::transform_children(AST::Transform* ast_transform)
{
	as_AST()->transform_children(ast_transform);
}

void PHP_script::transform_children(HIR::Transform* hir_transform)
{
	as_HIR()->transform_children(hir_transform);
}

void PHP_script::transform_children(MIR::Transform* mir_transform)
{
	as_MIR()->transform_children(mir_transform);
}

void PHP_script::transform_children(AST::Transform* ast_transform, HIR::Transform* hir_transform, MIR::Transform* mir_transform)
{
	if(is_AST())
		transform_children(ast_transform);
	else if (is_HIR ())
		transform_children(hir_transform);
	else
		transform_children(mir_transform);
}



bool PHP_script::is_AST()
{
	return dynamic_cast<AST::PHP_script*>(this) != NULL;
}

bool PHP_script::is_HIR()
{
	return dynamic_cast<HIR::PHP_script*>(this) != NULL;
}

bool PHP_script::is_MIR()
{
	return dynamic_cast<MIR::PHP_script*>(this) != NULL;
}


AST::PHP_script* PHP_script::as_AST()
{
	AST::PHP_script* ast = dynamic_cast<AST::PHP_script*>(this);
	assert(ast != NULL);
	return ast;
}

HIR::PHP_script* PHP_script::as_HIR()
{
	HIR::PHP_script* hir = dynamic_cast<HIR::PHP_script*>(this);
	assert(hir != NULL);
	return hir;
}


MIR::PHP_script* PHP_script::as_MIR()
{
	MIR::PHP_script* mir = dynamic_cast<MIR::PHP_script*>(this);
	assert(mir != NULL);
	return mir;
}


PHP_script* PHP_script::fold_lower ()
{
	if (is_AST ())
		return (new AST_to_HIR ())->fold_php_script (as_AST ());
	else if (is_HIR ())
		return (new HIR_to_MIR ())->fold_php_script (as_HIR ());
	else 
		return NULL;
}
