/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * A pass which does nothing when run () is called. This serves to add named
 * points in the Pass queue, so that, for example, you can use "--dump=ast", or
 * add_after_named_pass ("ast").
 */



#ifndef PHC_FAKE_PASS_H
#define PHC_FAKE_PASS_H

#include "process_ast/PHP_unparser.h"
#include "process_ast/Pass_manager.h"

class Fake_pass : public Pass
{
	public:
	Fake_pass (const char* name)
	{
		this->name = new String (name);
	}

	void run (AST_php_script*, Pass_manager*) {}
};


#endif // PHC_FAKE_PASS_H
