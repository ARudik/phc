/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Def-use information.
 *
 * Gather the def-use information while the alias analysis is running.
 *
 */

#ifndef PHC_DEF_USE
#define PHC_DEF_USE

#include "WPA.h"

class Def_use : public WPA
{
public:
	Def_use (Whole_program* wp);


	void set_value (Basic_block* bb, string lhs, MIR::Literal* lit, certainty cert);
	void set_value_from (Basic_block* bb, string lhs, string rhs, certainty cert);


	void pull_results (Basic_block* bb);
	void aggregate_results (Basic_block* bb);
	void dump (Basic_block* bb);

	// TODO: do we need function local ones for call-clobbering
	Map<long, Set<string> > defs;
	Map<long, Set<string> > uses;
	Map<long, Set<string> > may_defs;
	Map<long, Set<string> > may_uses;
};

#endif // PHC_DEF_USE
