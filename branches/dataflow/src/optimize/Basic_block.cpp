#include "Basic_block.h"
#include "process_ir/General.h"
#include "process_mir/MIR_unparser.h"
#include "MIR.h"

using namespace std;
using namespace MIR;

/* Constructors */

Basic_block::Basic_block(CFG* cfg)
: cfg(cfg)
, vertex (NULL)
, defs (NULL)
, uses (NULL)
, live_in (NULL)
, live_out (NULL)
, changed (false)
, aliases (NULL)
{
}

Branch_block::Branch_block (CFG* cfg, MIR::Branch* b)
: Basic_block (cfg)
, branch (b) 
{
}

Statement_block::Statement_block (CFG* cfg, MIR::Statement* s) 
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

list<pair<String*,String*> >*
Basic_block::get_graphviz_properties ()
{
	list<pair<String*,String*> >* result = new list<pair<String*,String*> >;
	assert (0);
	return result;
}


/*
 * Labels for graphviz
 */
String*
Entry_block::get_graphviz_label ()
{
	return s("ENTRY");
}

String* Exit_block::get_graphviz_label ()
{
	return s("EXIT");
}

String* Empty_block::get_graphviz_label ()
{
	return s("");
}

String* Branch_block::get_graphviz_label ()
{
	return branch->variable_name->value;
}

String*
Statement_block::get_graphviz_label ()
{
	stringstream ss;
	MIR_unparser mup(ss, true);
	mup.unparse(statement);
	return s(ss.str());
}

list<pair<String*,String*> >*
Branch_block::get_graphviz_properties ()
{
	list<pair<String*,String*> >* result =
		Basic_block::get_graphviz_properties ();

	result->push_back (pair<String*,String*> (s("shape"), s("rectangle")));

	return result;
}


list<std::pair<String*,Set*> >*
Basic_block::get_graphviz_bb_properties ()
{
	list<pair<String*,Set*> >* result = new list<std::pair<String*,Set*> >;
	if (defs)
		result->push_back (pair<String*, Set*> (s("defs"), defs));
	if (uses)
		result->push_back (pair<String*, Set*> (s("uses"), uses));
	if (aliases && dynamic_cast<Entry_block*> (this))
		result->push_back (pair<String*, Set*> (s("aliases"), aliases));
	return result;
}

list<std::pair<String*,Set*> >*
Basic_block::get_graphviz_head_properties ()
{
	list<std::pair<String*,Set*> >* result = new list<std::pair<String*,Set*> >;
	if (live_in)
		result->push_back (pair<String*, Set*> (s("IN"), live_in));
	return result;
}

list<std::pair<String*,Set*> >*
Basic_block::get_graphviz_tail_properties ()
{
	list<std::pair<String*,Set*> >* result = new list<std::pair<String*,Set*> >;
	if (live_out)
		result->push_back (pair<String*, Set*> (s("OUT"), live_out));
	return result;
}

/*
 * SSA
 */

void
Basic_block::add_phi_function (VARIABLE_NAME* var_name)
{
	phi_nodes[*var_name->value] = new Phi (var_name);
}

bool
Basic_block::has_phi_function (VARIABLE_NAME* var_name)
{
	return phi_nodes.find (*var_name->value) != phi_nodes.end ();
}

Set*
Statement_block::get_local_defs ()
{
	assert (0);
}

Set*
Statement_block::get_local_uses ()
{
	assert (0);
}

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

Basic_block*
Branch_block::get_true_successor ()
{
	BB_list* succs = get_successors ();
	assert (succs->size() == 2);

	foreach (Basic_block* succ, *succs)
		if (cfg->is_true_edge (cfg->get_edge (this, succ)))
			return succ;

	assert (0);
}

Basic_block*
Branch_block::get_false_successor ()
{
	BB_list* succs = get_successors ();
	assert (succs->size() == 2);

	foreach (Basic_block* succ, *succs)
		if (not cfg->is_true_edge (cfg->get_edge (this, succ)))
			return succ;

	assert (0);
}

void
Basic_block::remove ()
{
	clear_vertex (vertex, cfg->bs);
	remove_vertex (vertex, cfg->bs);
}

void
Basic_block::replace (BB_list* replacements)
{
	if (replacements->size() == 1
		&& replacements->front() == this)
	{
		// Same BB: do nothing
	}
	else if (replacements->size() == 0)
	{
		// Remove the BB
		foreach (Basic_block* pred, *this->get_predecessors ())
			foreach (Basic_block* succ, *this->get_successors ())
				boost::add_edge (pred->vertex, succ->vertex, cfg->bs);

		this->remove ();
	}
	else
	{
		foreach (Basic_block* new_bb, *replacements)
		{
			// Create vertices for the new statements
			vertex_t v = cfg->add_bb (new_bb);

			// Add edges from predecessors
			foreach (Basic_block* pred, *this->get_predecessors ())
				boost::add_edge (pred->vertex, v, cfg->bs);

			// Add edges from successors 
			foreach (Basic_block* succ, *this->get_successors ())
				boost::add_edge (v, succ->vertex, cfg->bs);
		}
		this->remove ();
	}
}

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

void
Basic_block::add_to_dominance_frontier (Basic_block* bb)
{
	cfg->dominance->add_to_bb_dominance_frontier (this, bb);
}

BB_list*
Basic_block::get_dominated_blocks ()
{
	return cfg->dominance->get_blocks_dominated_by_bb (this);
}

Set*
Basic_block::get_local_defs ()
{
	assert (0);
}

Set*
Basic_block::get_local_uses ()
{
	assert (0);
}

Set*
Branch_block::get_local_uses ()
{
	assert (0);
}

List<Phi*>*
Basic_block::get_phi_nodes ()
{
	List<Phi*>* result = new List<Phi*>;

	pair<string, Phi*> pair;
	foreach (pair, phi_nodes)
		result->push_back (pair.second);

	return result;
}
