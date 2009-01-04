/*
 * The propagation algorithm from SCCP.
 */


#include "CFG.h"
#include "CFG_visitor.h"
#include "Edge.h"
#include "Def_use.h"
#include "Lattice.h"
#include "process_ir/debug.h"
#include "Sparse_conditional_visitor.h"

void
Sparse_conditional_visitor::run (CFG* cfg)
{
	this->cfg = cfg;
	cfg->consistency_check ();

	lattice.clear ();

	// 1. Initialize:
	cfg_wl = new Edge_list(cfg->get_entry_edge ());
	ssa_wl = new SSA_op_list;

	foreach (Edge* e, *cfg->get_all_edges ())
		e->is_executable = false;

	// TOP is NULL, so the lattice map is already initialized.


	// Start in the entry block
	visit_block (cfg->get_entry_bb ());


	// 2. Stop when CFG-worklist and SSA-worklist are both empty.
	while (cfg_wl->size () > 0 || ssa_wl->size () > 0)
	{
		// Take workitem from either list.

		/* 3.
		 * For CFGWL, pop e. If ExecFlag(e) == true, do nothing. Else:
		 *	- ExecFlag(e) = true;
		 *	- visitPhi (p) for all phis in e.target.
		 *	- if this is the first time the stmt is evaluated 
		 *		(ie. if count (execflags(e1), where e1.target = e.target) == 1)
		 *	  then visitExpr (e.target)
		 *		- If e.target has 1 outgoing edge, add it to CFGW BB
		 */

		while (cfg_wl->size() > 0)
		{
			Edge* e = cfg_wl->front();
			cfg_wl->pop_front ();

			if (e->is_executable)
				continue;

			e->is_executable = true;

			foreach (MIR::VARIABLE_NAME* phi_lhs, *e->get_target ()->get_phi_lhss ())
				visit_phi_node (e->get_target (), phi_lhs);

			if (get_predecessor_executable_count (e->get_target()) == 1)
				visit_block (e->get_target ());

			Edge_list* succs = e->get_target ()->get_successor_edges ();
			if (succs->size() == 1)
				cfg_wl->push_back (succs->front ());
		}

		while (ssa_wl->size() > 0)
		{
			/*
			 * 4/5.
			 * For SSAWL, pop e.
			 * - If e.target is a Phi, perform visitPhi (e.target).
			 *	- If e.target is an expression, and any of e.targets incoming
			 *	  edges is executable, run visit_expression. Else do nothing.
			 */
			SSA_op* e = ssa_wl->front ();
			ssa_wl->pop_front ();

			if (SSA_phi* phi = dynamic_cast<SSA_phi*> (e))
				visit_phi_node (phi->bb, phi->phi_lhs);
			else if (SSA_chi* chi = dynamic_cast<SSA_chi*> (e))
				visit_chi_node (chi->bb, chi->lhs, chi->rhs);
			else
			{
				assert (!isa<SSA_formal> (e));

				// Branches and statements
				Basic_block* bb = e->get_bb ();
				if (get_predecessor_executable_count (bb))
					visit_block (bb);
			}
		}
	}

	if (debugging_enabled)
	{
		lattice.dump();
	}

	// The algorithm so far has found the answers. We now need to update the
	// results.
	post_pass (cfg);
}


int
Sparse_conditional_visitor::get_predecessor_executable_count (Basic_block* bb)
{
	int exec_count = 0;
	foreach (Edge* pred, *bb->get_predecessor_edges ())
	{
		if (pred->is_executable)
			exec_count++;
	}
	return exec_count;
}


/*
 * The rest of the statements make up VisitExpr:
 *
 *	VisitExpr:
 *	Evaluate the expression.
 *	- If its a branch, add:
 *		- all outgoing edges to CFGWL for BOTTOM
 *		- only the appropriate outgoing edge for a constant
 */
void
Sparse_conditional_visitor::visit_branch_block (Branch_block* bb)
{
	cfg_wl->push_back_all (get_branch_successors (bb));
}

void
Sparse_conditional_visitor::set_lattice (MIR::VARIABLE_NAME* def, Lattice_cell* value)
{
	Lattice_cell* old = lattice[def];
	if (old != value)
	{
		// shouldnt have two different Literals here
		assert (old == TOP || value == BOTTOM);

		foreach (SSA_op* edge, *cfg->duw->get_uses (def, SSA_ALL))
		{
			//	1. add uses of the LHS to the SSA worklist.
			ssa_wl->push_back (edge);

			// 2. If the expression controls a conditional branch, .... However,
			// conditions never control branches - that's always a VARIABLE_NAME.
			// The new value for that variable will propagate through 1.
		}
	}
	lattice[def] = value;
}

void
Sparse_conditional_visitor::meet_lattice (MIR::VARIABLE_NAME* var, Lattice_cell* value)
{
	set_lattice (var, meet (lattice[var], value));
}

