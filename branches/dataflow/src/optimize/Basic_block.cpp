#include "process_ir/General.h"
#include "process_mir/MIR_unparser.h"
#include "MIR.h"

#include "Basic_block.h"
#include "Def_use_web.h"

#include "ssa/Dominance.h"

#include "lib/escape.h"

using namespace std;
using namespace MIR;
using namespace boost;

/* Constructors */

// Zero is used for the outer scope, in BBID
long Basic_block::max_id = 0;

Basic_block::Basic_block(CFG* cfg)
: cfg(cfg)
, vertex (NULL)
{
	ID = max_id++;
}

Branch_block::Branch_block (CFG* cfg, Branch* b)
: Basic_block (cfg)
, branch (b) 
{
}

Statement_block::Statement_block (CFG* cfg, Statement* s) 
: Basic_block (cfg)
, statement(s)
{
}

Empty_block::Empty_block (CFG* cfg)
: Basic_block (cfg)
{
}

Entry_block::Entry_block (CFG* cfg, Method* method)
: Basic_block (cfg)
, method (method)
{
}

Exit_block::Exit_block (CFG* cfg, Method* method)
: Basic_block (cfg)
, method (method)
{
}

/*
 * Labels for graphviz
 */
String*
Entry_block::get_graphviz_label ()
{
	stringstream ss;
	ss << ID << " ENTRY: (";

	foreach (Formal_parameter* param, *method->signature->formal_parameters)
		ss << *param->var->variable_name->value << ", ";
	
	ss << ")";

	return s (ss.str ());
}

String* Exit_block::get_graphviz_label ()
{
	stringstream ss;
	ss << ID << " EXIT: (";

	foreach (Formal_parameter* param, *method->signature->formal_parameters)
		ss << *param->var->variable_name->value << ", ";
	
	ss << ")";

	return s (ss.str ());
}

String* Empty_block::get_graphviz_label ()
{
	return s("");
}

String* Branch_block::get_graphviz_label ()
{
	String* result = s("$");
	result->append (*branch->variable_name->value);
	result->append (" ID: ");
	result->append(""+ID);
	return result;
}

String*
Statement_block::get_graphviz_label ()
{
	stringstream ss;
	ss<<ID<<" ";
	MIR_unparser mup(ss, true);
	mup.unparse (statement);
	return escape_DOT (s(ss.str()));
}

/*
 * SSA
 */

/* Merge the phi nodes from OTHER into this BB. */
void
Basic_block::copy_phi_nodes (Basic_block* other)
{
	if (cfg->duw == NULL)
		return;

	cfg->duw->copy_phi_nodes (this, other);
}

bool
Basic_block::has_phi_node (Alias_name phi_lhs)
{
	return cfg->duw->has_phi_node (this, phi_lhs);
}

void
Basic_block::add_phi_node (Alias_name phi_lhs)
{
	cfg->duw->add_phi_node (this, phi_lhs);
}

void
Basic_block::add_phi_arg (Alias_name phi_lhs, int version, Edge* edge)
{
	
	//temporary
	if (has_phi_node(phi_lhs))
	{
		cfg->duw->add_phi_arg (this, phi_lhs, version, edge);
	}
}

void
Basic_block::remove_phi_nodes ()
{
	if (cfg->duw == NULL)
		return;

	cfg->duw->remove_phi_nodes (this);
}

void
Basic_block::remove_phi_node (Alias_name phi_lhs)
{
	cfg->duw->remove_phi_node (this, phi_lhs);
}


void
Basic_block::update_phi_node (Alias_name phi_lhs, Alias_name new_phi_lhs)
{
	cfg->duw->update_phi_node (this, phi_lhs, new_phi_lhs);
}


Alias_name_list*
Basic_block::get_phi_args (Alias_name phi_lhs)
{
	return cfg->duw->get_phi_args (this, phi_lhs);
}

Var_set*
Basic_block::get_phi_lhss ()
{
	if (cfg->duw == NULL)
		return new Var_set;

	return cfg->duw->get_phi_lhss (this);
}

Alias_name
Basic_block::get_phi_arg_for_edge (Edge* edge, Alias_name phi_lhs)
{
	return cfg->duw->get_phi_arg_for_edge (edge, phi_lhs);
}

void
Basic_block::set_phi_arg_for_edge (Edge* edge, Alias_name phi_lhs, Alias_name arg)
{
	cfg->duw->set_phi_arg_for_edge (edge, phi_lhs, arg);
}



/*
 * Block manipulation
 */

BB_list*
Basic_block::get_predecessors ()
{
	return cfg->get_bb_predecessors (this);
}

BB_list*
Basic_block::get_successors ()
{
	return cfg->get_bb_successors (this);
}

Basic_block*
Basic_block::get_successor ()
{
	BB_list* succs = get_successors ();
	assert (succs->size() == 1);
	return succs->front ();
}

Edge_list*
Basic_block::get_predecessor_edges ()
{
	return cfg->get_edge_predecessors (this);
}

Edge_list*
Basic_block::get_successor_edges ()
{
	return cfg->get_edge_successors (this);
}


Edge*
Basic_block::get_successor_edge ()
{
	Edge_list* succs = get_successor_edges ();
	assert (succs->size() == 1);
	return succs->front ();
}


Basic_block*
Branch_block::get_true_successor ()
{
	Edge_list* succs = get_successor_edges ();
	assert (succs->size() == 2);

	foreach (Edge* succ, *succs)
		if (cfg->is_true_edge (succ))
			return succ->get_target ();

	phc_unreachable ();
}


Basic_block*
Branch_block::get_false_successor ()
{
	Edge_list* succs = get_successor_edges ();
	assert (succs->size() == 2);

	foreach (Edge* succ, *succs)
		if (not cfg->is_true_edge (succ))
			return succ->get_target ();

	phc_unreachable ();
}

Edge*
Branch_block::get_true_successor_edge ()
{
	Edge_list* succs = get_successor_edges ();
	assert (succs->size() == 2);

	foreach (Edge* succ, *succs)
		if (cfg->is_true_edge (succ))
			return succ;

	phc_unreachable ();
}

Edge*
Branch_block::get_false_successor_edge ()
{
	Edge_list* succs = get_successor_edges ();
	assert (succs->size() == 2);

	foreach (Edge* succ, *succs)
		if (not cfg->is_true_edge (succ))
			return succ;

	phc_unreachable ();
}

void
Branch_block::switch_successors ()
{
	foreach (Edge* succ, *get_successor_edges ())
	{
		assert (!indeterminate (succ->direction));
		succ->direction = !succ->direction;
	}
}

/*
 * Dominance
 */

BB_list*
Basic_block::get_dominance_frontier ()
{
	return cfg->dominance->get_bb_dominance_frontier (this);
}

Basic_block*
Basic_block::get_immediate_dominator ()
{
	return cfg->dominance->get_bb_immediate_dominator (this);
}

bool
Basic_block::is_dominated_by (Basic_block* bb)
{
	return cfg->dominance->is_bb_dominated_by (this, bb);
}

BB_list*
Basic_block::get_dominated_blocks ()
{
	return cfg->dominance->get_blocks_dominated_by_bb (this);
}


/*
 * Reverse Dominance
 */
Basic_block*
Basic_block::get_immediate_reverse_dominator ()
{
	if (cfg->dominance->reverse_dominance == NULL)
		PUNT;

	return cfg->dominance->reverse_dominance->get_bb_immediate_dominator (this);
}

BB_list*
Basic_block::get_reverse_dominated_blocks ()
{
	if (cfg->dominance->reverse_dominance == NULL)
		PUNT;

	return cfg->dominance->reverse_dominance->get_blocks_dominated_by_bb (this);
}

bool
Basic_block::is_reverse_dominated_by (Basic_block* bb)
{
	if (cfg->dominance->reverse_dominance == NULL)
		PUNT;
	return cfg->dominance->reverse_dominance->is_bb_dominated_by (this, bb);
}

BB_list*
Basic_block::get_reverse_dominance_frontier ()
{
	if (cfg->dominance->reverse_dominance == NULL)
		PUNT;

	return cfg->dominance->reverse_dominance->get_bb_dominance_frontier (this);
}


int
Basic_block::get_index ()
{
	return cfg->index[vertex];
}


/*
 * Debugging
 */

void
Entry_block::dump()
{
	DEBUG ("Entry block");
}

void
Exit_block::dump()
{
	DEBUG ("Exit block");
}

void
Branch_block::dump()
{
	DEBUG ("Branch block (" << ID << ")");
}

void
Statement_block::dump()
{
	DEBUG ("Statement block (" << ID << ")");
}
void
Empty_block::dump()
{
	DEBUG ("Empty block (" << ID << ")");
}


/*
 * Cloning doesnt clone its place in the CFG, it just (deep) clones the data.
 */

Basic_block*
Branch_block::clone ()
{
	return new Branch_block (cfg, branch->clone ());
}

Basic_block*
Exit_block::clone ()
{
	// TODO: we dont need METHOD, and cloning might actually be expensive.
	return new Exit_block (cfg, method->clone ());
}

Basic_block*
Entry_block::clone ()
{
	return new Entry_block (cfg, method->clone ());
}

Basic_block*
Empty_block::clone ()
{
	return new Empty_block (cfg);
}

Basic_block*
Statement_block::clone ()
{
	return new Statement_block (cfg, statement->clone ());
}

bool
Empty_block::equals (Basic_block* other)
{
	return isa<Empty_block> (other);
}

bool
Entry_block::equals (Basic_block* other)
{
	return isa<Entry_block> (other);
}

bool
Exit_block::equals (Basic_block* other)
{
	return isa<Exit_block> (other);
}

bool
Branch_block::equals (Basic_block* other)
{
	if (Branch_block* bb = dynamic_cast<Branch_block*> (other))
		return bb->branch->equals (branch);

	return false;
}

bool
Statement_block::equals (Basic_block* other)
{
	if (Statement_block* bb = dynamic_cast<Statement_block*> (other))
		return bb->statement->equals (statement);

	return false;
}
