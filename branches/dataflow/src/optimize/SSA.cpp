
#include <boost/foreach.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/dominator_tree.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/topological_sort.hpp>

#include "SSA.h"

using namespace MIR;
using namespace boost;

void
Phi::add_arg (int version)
{
	VARIABLE_NAME* param = lhs->clone ();
	param->set_version (version);
	args->push_back (param);
}

Phi::Phi (VARIABLE_NAME* var_name)
: lhs(var_name)
{
	args = new VARIABLE_NAME_list;
}

// We use Muchnick, Section 8.11 (which is essentially the same as the
// Minimal SSA form from the original Cytron, Ferrante, Rosen, Wegman and
// Zadeck paper), and Cooper/Torczon Chapter 9.

/*
 * Terms (from Muchnick 7.3)
 * 
 * Dominator:
 *		A basic block X dominates another, Y, if X must be executed before Y.
 *		X dominates X.  Technically, if all paths from ENTRY to Y must go
 *		through X.  
 *
 *	Immediate dominator:
 *		The unique dominator U of a BB X, for which there is no BB dominated by
 *		U which dominates X.
 *
 *	Strict dominator (we dont use this term yet):
 *		X sdom Y if X dom Y and X != Y.
 *
 *	Dominance Frontier:
 *		DF (X) is the set of nodes dominated by X, whose successors are not
 *		dominated by X (well, one or more are not dominated by X).
 *	
 *	We need to calculate the dominace frontier. There is a linear-time
 *	algorithm for this:
 *
 * 1) Find DF_local (X):
 *		DF_local (x) = { y in succ (x) | idom (y) != x } The set of successors
 *		of X, which are not immediately dominated by X.
 *
 *	2) Find DF_up (X, Z):
 *		DF_up (x,z)  = { y in DF (z) | idom (z) = x && idom (y) != x } We want
 *		to propagate each the dominance frontiers of Z to X, its immediate
 *		dominator, if X doesnt dominate frontier (Y).
 *
 * 3) Propagate frontier
 *		Iteratively propagate DF_local (Z) from dominated block Z to immediate
 *		dominator X via DF_up (X, Z).
 */

Dominance::Dominance (CFG* cfg)
: cfg(cfg)
{
}

void
Dominance::calculate_immediate_dominators ()
{
	// Step 1: Calculate immediate dominators.

	// This automatically builds reverse dominators, ie, given y, find x such
	// that x idom y.
	lengauer_tarjan_dominator_tree(cfg->bs, cfg->entry, idoms);

	// Build forward dominators
	// We also want to find the block that are immedately dominated by
	// another block (ie [a,b,c] such that x idom a, x idom b and x idom c.
	foreach (Basic_block* y, *cfg->get_all_bbs ())
	{
		vertex_t dominator = get (idoms, y->vertex);
		forward_doms [cfg->vb[dominator]]->push_back (y);
	}
}

void
Dominance::calculate_local_dominance_frontier ()
{
	foreach (Basic_block* x, *cfg->get_all_bbs ())
	{
		// Step 2: Calculate local dominance frontier:
		//	DF_local (x) = { y in succ (x) | idom (y) != x }
		foreach (Basic_block* y, *x->get_successors ())
		{
			if (y->get_immediate_dominator () != x)
				x->add_to_dominance_frontier (y);
		}
	}
}

void
Dominance::propagate_dominance_frontier_upwards ()
{
	foreach (Basic_block* x, *cfg->get_all_bbs ())
	{
		// Step 3: Propagate local dominance frontier upwards.
		// DF_up (x,z)  = { y in DF (z) | idom (z) = x && idom (y) != x }
		foreach (Basic_block* z, *cfg->get_all_bbs_bottom_up ())
		{
			foreach (Basic_block* y, *z->get_dominance_frontier ())
			{
				if (y->get_immediate_dominator () != x)
					x->add_to_dominance_frontier (y);
			}
		}
	}
}

void
Dominance::add_to_bb_dominance_frontier (Basic_block* bb, Basic_block* frontier)
{
	df [bb]->push_back (frontier);
}

BB_list*
Dominance::get_bb_dominance_frontier (Basic_block* bb)
{
	return df[bb];
}

Basic_block*
Dominance::get_bb_immediate_dominator (Basic_block* bb)
{
	return cfg->vb [get (idoms, bb->vertex)];
}


BB_list*
Dominance::get_blocks_dominated_by_bb (Basic_block* bb)
{
	return forward_doms[bb];
}

SSA_renaming::SSA_renaming (CFG* cfg)
: cfg(cfg)
, counter (0)
{
}

void
SSA_renaming::push_to_var_stack (VARIABLE_NAME* var_name, int version)
{
	var_stacks[*var_name->value].push (version);
}

int 
SSA_renaming::read_var_stack (VARIABLE_NAME* var_name)
{
	int result = var_stacks[*var_name->value].top();
	var_stacks[*var_name->value].pop();
	return result;
}

void 
SSA_renaming::initialize_var_stack (VARIABLE_NAME* var_name)
{
	assert (var_stacks.find (*var_name->value) != var_stacks.end());
	push_to_var_stack (var_name, counter++);
}

void 
SSA_renaming::create_new_ssa_name (VARIABLE_NAME* var_name)
{
	var_name->convert_to_ssa_name (counter);
	var_stacks[*var_name->value].push (counter++);
}

void 
SSA_renaming::rename_vars (Basic_block* bb)
{
	// Create new names for PHI targets
	foreach (Phi* phi, *bb->get_phi_nodes ())
		create_new_ssa_name (phi->lhs);

	// Rename local variable uses
	foreach (VARIABLE_NAME* use, *bb->get_local_uses ())
		use->convert_to_ssa_name (read_var_stack (use));

	// Create new names for defs
	foreach (VARIABLE_NAME* def, *bb->get_local_defs ())
		create_new_ssa_name (def);

	// Copy names to CFG successors (including names defined in
	// predecessor, which are not redefined here).
	foreach (Basic_block* succ, *bb->get_successors ())
		foreach (Phi* phi, *succ->get_phi_nodes ())
		phi->add_arg (read_var_stack (phi->lhs));

	// Recurse down the dominator tree
	foreach (Basic_block* dominated, *bb->get_dominated_blocks ())
		rename_vars (dominated);

	// Before going back up the tree, get rid of new variable names from
	// the stack, so the next node up sees its own names.
	foreach (VARIABLE_NAME* def, *bb->get_local_defs ())
		var_stacks[*def->value].pop ();
}