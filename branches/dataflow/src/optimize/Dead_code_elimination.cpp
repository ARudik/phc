#include "Dead_code_elimination.h" // TODO: rename file
#include "process_ir/General.h"
#include "Def_use.h"
#include "assert.h"
#include "embed/embed.h"

using namespace MIR;

DCE::DCE ()
: marks (&ssa_op_ptr_comparison)
{
}

bool is_pure (Expr* in)
{
	Wildcard<METHOD_NAME>* name = new Wildcard<METHOD_NAME>;
	if (in->match (new Method_invocation (NULL, name, NULL))
		&& PHP::is_pure_function (name->value))
		return true;

	return (not (isa<New> (in) || isa<Method_invocation> (in)));
}

/*
 * Does the statement have any externally visible effects (like IO)?
 *		Has visible effects:
 *			Any function we dont know anything about
 *			TODO: impure functions dont necessarily have them (ie array_merge)
 *			Any class instatiation we know nothing about
 *
 *		 Doesn't have visible effects
 *			Anything else
*/
bool is_critical (Statement* in)
{
	if (not (isa<Eval_expr> (in) || isa<Assign_var> (in)))
		return false;

	Wildcard<Expr>* expr = new Wildcard<Expr>;
	if (in->match (new Eval_expr (expr))
		|| in->match (
			new Assign_var (
				new Wildcard<VARIABLE_NAME>,
				false, // dont-care
				expr)))
	{
		// TODO: pure and critical are different
		// TODO: indirect operations arent taken into account
		return !is_pure (expr->value);
	}
	else
		return false;
}

// TODO add phi nodes

/*
 * Cooper/Torczon, Sec. 10.3.1 and Figure 10.3
 *		http://www.cs.rice.edu/~keith/512/Lectures/10DeadCprop.pdf
 *
 *	Has a mark-sweep-style DCE algorithm: (based on Cytron et al SSA paper,
 *	section 7.1)
 *
 *	Dead ():
 *		MarkPass ()
 *		SweepPass ()
 */

/*	MarkPass ():
 *
 *		Worklist = []
 *
 *		// works on statements only: Phis cant be critical
 *		foreach statement S
 *			clear s.mark
 *			if s is critical
 *				set s.mark
 *				worklist []= s
 *
 *		// Works on phis and statements, but _separately_.
 *		while !worklist.empty ()
 *			i = worklist.pop_front ()
 *			foreach u in i.uses ()
 *				d = u.def ()
 *				if (!d.mark)
 *					set d.mark
 *					worklist []= d
 *
 *			foreach bb in s.rdf ()
 *				j = bb.branch ()
 *				if j.mark:
 *					set j.mark
 *					worklist =[] j
 */
void
DCE::mark_pass ()
{
	// Initialize the critical blocks - a critical block is a side-effecting
	// statement
	foreach (Basic_block* bb, *cfg->get_all_bbs ())
	{
		if (Statement_block* sb = dynamic_cast<Statement_block*> (bb))
		{
			if (is_critical (sb->statement))
			{
				DEBUG ("marking " << bb->get_index() << " as critical");
				mark(SSA_op::for_bb (sb));
			}
		}
		else
		{
			// Branches and phis are handled below.
		}
	}

	dump ();

	// Go through the worklist, propagating the mark from uses to defs
	while (worklist->size () > 0)
	{
		SSA_op* op = worklist->front ();
		worklist->pop_front ();

		SSA_stmt* stmt = dyc<SSA_stmt> (op); // TODO
		Basic_block* bb = stmt->get_bb ();

		foreach (MIR::VARIABLE_NAME* use, *cfg->duw->get_nonphi_uses (bb))
		{
			// ignore uninit
			if (!cfg->duw->has_def (use))
				continue;


			DEBUG ("marking " << bb->get_index() << " due to def of "
					<< *use->get_ssa_var_name ());
			mark (cfg->duw->get_var_def (use));
		}

		// Mark the critical branches (ie, the reverse dominance frontier of
		// the critical blocks)
		//
		// The dominance frontier occurs at joins. The reverse-dominance
		// frontier is at splits, which must be branches.
		foreach (Basic_block* rdf, *bb->get_reverse_dominance_frontier ())
		{
			DEBUG ("marking " << rdf->get_index()
					<< " as part of " << bb->get_index() << "'s RDF");
			mark(SSA_op::for_bb (rdf));
		}
	}
}

void
DCE::mark (SSA_op* op)
{
	marks[op] = true;
	worklist->push_back (op);
}

// Check if the block is marked (ignoring the phi nodes)
bool
DCE::is_marked (Basic_block* bb)
{
	return marks[SSA_op::for_bb (bb)];
}

/*	SweepPass ():
 *		foreach operation i: // i can be a phi or a statement
 *			if !i.mark
 *				if isa<Branch> (i)
 *					i = jump to nearest marked post-dominator
 *				else
 *					delete i
 */
void
DCE::sweep_pass ()
{
	SSA_op* op;
	bool marked;
	foreach (tie (op, marked), marks)
	{
		if (!marked)
			continue;

		if (isa<SSA_stmt> (op))
			cfg->remove_bb (op->get_bb ());
		else if (isa<SSA_branch> (op))
		{
			// find the nearest marked post-dominator
			Basic_block* postdominator = op->get_bb ();
			while (is_marked (postdominator))
				postdominator = postdominator->get_immediate_reverse_dominator ();

			cfg->remove_branch (dyc<Branch_block> (op->get_bb ()), postdominator);
		}
		else
			// TODO: phi blocks
			assert (0);
	}
}

void
DCE::run (CFG* cfg)
{
	marks.clear ();
	worklist = new SSA_op_list;
	this->cfg = cfg;

	mark_pass ();
	dump ();
	sweep_pass ();
}

void
DCE::dump()
{
	CHECK_DEBUG ();
	cdebug << "DCE:" << endl;
	foreach (Basic_block* bb, *cfg->get_all_bbs ())
		cdebug << bb->get_index() << ": " << is_marked (bb) << endl;
}

/*
void
DCE::transform_assign_var (Statement_block* bb, Assign_var* in, BB_list* out)
{
	if (bb->cfg->duw->get_var_uses(in->lhs)->size () == 0)
	{
		if (not is_pure (in->rhs))
		{
			out->push_back (new Statement_block (bb->cfg, new Eval_expr (in->rhs)));
		}
		else
		{
			DEBUG ("Removing BB (no uses)")
			debug (in);
		}
	}
	else
		out->push_back (bb);
}

// TODO: replace with ADCE
// TODO: add remove SSA_pre_ops

void
DCE::transform_phi_node (Basic_block* bb, VARIABLE_NAME* phi_lhs)
{
	// remove phis with unused LHSs
	if (bb->cfg->duw->get_var_uses (phi_lhs)->size () == 0)
		bb->remove_phi_node (phi_lhs);
}

void
DCE::transform_eval_expr (Statement_block* bb, MIR::Eval_expr* in, BB_list* out)
{
	if (not is_pure (in->expr))
	{
		out->push_back (bb);
	}
}
*/
