
#include "boost/tuple/tuple.hpp"

#include "process_ir/debug.h"

#include "Def_use_web.h"
#include "optimize/wpa/Def_use.h"
#include "Var_set.h"

#include "wpa/Aliasing.h"


using namespace MIR;
using namespace std;
using namespace boost;


/*
 * SSA-web. 
 *
 * Use the SSA-web (which doesnt actually rely on SSA form, nor is
 * it built during it) both for getting into SSA form, and for creating the
 * SSA web.
 */


Def_use_web::Def_use_web (Def_use* du)
: du (du)
{
}

void
Def_use_web::build_web (CFG* cfg)
{
	// Get the information from the def_use
	foreach (Basic_block* bb, *cfg->get_all_bbs ())
	{
		defs[bb->ID].push_back_all (du->get_defs (bb));
		uses[bb->ID].push_back_all (du->get_uses (bb));
		may_defs [bb->ID].push_back_all (du->get_may_defs (bb));
	}

	// Build all the ops
	foreach (Basic_block* bb, *cfg->get_all_bbs ())
	{
		foreach (Alias_name* use, uses[bb->ID])
			named_uses[*use].push_back (new SSA_use (bb, use, SSA_BB));

		foreach (Alias_name* def, defs[bb->ID])
			named_defs[*def].push_back (new SSA_def (bb, def, SSA_BB));

		foreach (Alias_name* may_def, may_defs[bb->ID])
		{
			named_defs[*may_def].push_back (new SSA_def (bb, may_def, SSA_CHI));
			named_uses[*may_def].push_back (new SSA_use (
					bb,
					new Alias_name (*may_def),
					SSA_CHI));
		}
	}

	// Create the web
	Alias_name name;
	SSA_def_list& def_list = *(new SSA_def_list ());
	foreach (tie (name, def_list), named_defs)
	{
		foreach (SSA_def* def, def_list)
		{
			def_ops[def->bb->ID].push_back (def);

			// Add to all uses
			foreach (SSA_use* use, named_uses[*def->name])
				use->aux_ops.push_back (def);
		}
	}

	SSA_use_list& use_list = *(new SSA_use_list ());
	foreach (tie (name, use_list), named_uses)
	{
		foreach (SSA_use* use, use_list)
		{
			use_ops[use->bb->ID].push_back (use);

			// Add to all uses
			foreach (SSA_def* def, named_defs[*use->name])
				def->aux_ops.push_back (use);
		}
	}
}



// TODO: CHIs are not created for the parameters to a method call. They
// clearly should be.

// TODO:
// There is a special problem that occurs when you have two indirect
// assignments in the same statement. Suppose you have:
//
//		$x = my_func ($y);
//
//	Then you have to add CHIs for the aliases of $y AND for the aliases of
//	$x. However, the CHIs for the variables which alias $x do not occur at
//	the same time as the variables which alias $y. Instead, $y's aliases
//	should occur after the method invocation, and $x's aliases should occur
//	after the assignment to $x. $x is in the first set, but not in the
//	second. Anything which aliases both $y and $x gets 2 CHIs. $y will get
//	2 CHIs.
//
//	So:
//		$x0 = 5;
//		$x2 = my_func ($y0);
//		$x1 = CHI ($x0); // METHOD
//		$y1 = CHI ($y0); // METHOD
//		$y2 = CHI ($y1); // ASSIGNMENT
//
//	Some interesting notes:
//		- There is no use of $x1.
//		- This problem only occurs when there can be > 1 assignment, which
//		can only occur in assignments from method invocations.
//		- The same variable can get given a CHI from each of a method's
//		parameters, but that is only 1 CHI overall.
//		- There can only be 1 or 2 CHIs, not more (see above).
//		- If we were to use zero versions, the first chi would have a zero
//		version, since it has no real use.
//		- This is only really important for getting the numbering right.
//		Anywhere that uses phis would get them all.
//
//
//
// Some possible solutions:
//		Associate CHIs with other definitions, maybe each def has a list of
//		maydefs. But there is no def in the function call to associate it
//		with, though I think one could safely be added (the MU would ensure
//		that it is not overwritten).
//
//		Allow multiple CHIs in the CHI list. If there is more than 1 of the
//		same name, they are assumed to be in the same order in which they
//		occur. I believe that the only variable which will only occur once
//		in the variable on the RHS.
//		 - but what about when we have small alias sets? Then we dont really
//		 know which is which.
//		 - besides, keeping track of that seems very buggy
//
// XXX: I like this one best, I think.
//		Have two CHI lists, one for 'mid' statement, one for
//		'post-statement'. Aliases of assignments go in the latter. Aliases
//		due to the call go in the former.
//
//	I think this will also solve the problem of 'vanishing globals'. In the
//	case of:
//		global $x;
//		$x = 5;
//
//	The global statement is remove because $x_0 is not used. However, $x = 5
//	is a must_def of $x_0. We can model it as a may-def however, giving it a
//	CHI in the mid-part, and the CHI in the post-statement part gives it the
//	new value.
//
//	The global statement will not in fact be solved by this. If there were
//	an extra statement, $x = 8 after $x = 5, then $x = 5 would be kept live
//	by this 'Early CHI'.
//
//	How about each assignment to an alias gets a MU of the variables in the
//	statement which created the alias.



void
Def_use_web::dump ()
{
	phc_TODO ();
	CHECK_DEBUG ();
/*
	cdebug << "Use-def web (" << use_def_chains.size() << "):\n";
	pair<Alias_name, SSA_edge_list> p;
	foreach (p, use_def_chains)
	{
		cdebug << "SSA edges for " << p.first.str ();

		foreach (SSA_edge* edge, p.second)
			edge->dump ();

		cdebug << endl;
	}

	cdebug << "Def-use web (" << def_use_chains.size() << "):\n";
	foreach (p, def_use_chains)
	{
		cdebug << "SSA edges for " << p.first.str ();

		foreach (SSA_edge* edge, p.second)
			edge->dump ();

		cdebug << endl;
	}*/
}

void
Def_use_web::consistency_check ()
{
	return;

	// There isnt much that will help here. I'll implement it if its buggy.
	// Check that named defs are correctly named
	// Check that blocked defs are in the right block.
	// Check that all the defs for a use contains the use
	// and vice-versa
	phc_TODO ();

/*
	// Is the first variable we find in SSA.
	bool in_ssa = (*use_def_chains.begin ()).first.ssa_version == 0;
	if (!in_ssa)
		return;


	// Check that each use has 0 or 1 def.
	Alias_name key;
	SSA_edge_list edge_list;
	foreach (tie (key, edge_list), use_def_chains)
	{
		assert (edge_list.size () < 2);
	}


	// Check that each key is in SSA form
	foreach (tie (key, edge_list), use_def_chains)
		assert (key.ssa_version);
	
	foreach (tie (key, edge_list), def_use_chains)
		assert (key.ssa_version);
		*/
}


Alias_name_list*
Def_use_web::get_defs (Basic_block* bb)
{
	return &defs[bb->ID];
}

Alias_name_list*
Def_use_web::get_uses (Basic_block* bb)
{
	return &uses[bb->ID];
}

Alias_name_list*
Def_use_web::get_may_defs (Basic_block* bb)
{
	return &may_defs[bb->ID];
}


SSA_use_list*
Def_use_web::get_block_uses (Basic_block* bb)
{
	return &use_ops[bb->ID];
}

SSA_def_list*
Def_use_web::get_block_defs (Basic_block* bb)
{
	return &def_ops[bb->ID];
}

SSA_use_list*
Def_use_web::get_named_uses (Alias_name* name)
{
	return &named_uses[*name];
}

SSA_def_list*
Def_use_web::get_named_defs (Alias_name* name)
{
	return &named_defs[*name];
}
