/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Control-flow Graph
 */

#include "boost/foreach.hpp"
#include "boost/graph/graphviz.hpp"

#include "CFG.h"
#include "process_ast/DOT_unparser.h"
#include "process_ir/General.h"

using namespace boost;
using namespace std;
using namespace MIR;

CFG::CFG ()
: bs()
{
	vb = get(vertex_bb_t(), bs);

	// Initialize the entry and exit blocks
	entry = add_bb (new Entry_block);
	exit = add_bb (new Exit_block);
}

vertex_t
CFG::add_bb (Basic_block* bb)
{
	vertex_t v = add_vertex (bs);
	vb[v] = bb;
	bb->vertex = v;
	return v;
}

void
CFG::add_statements (List<Statement*>* statements)
{
	// Keep track of labels, for edges between gotos and branches.
	map <string, vertex_t> labels;

	// In the second pass, we'll need the vertices to add edges.
	map <Statement*, vertex_t> nodes;


	// In the first pass, just create nodes for the statements.
	for_lci (statements, Statement, i)
	{
		vertex_t v;
		switch ((*i)->classid())
		{
			case Label::ID:
				v = add_bb (new Empty_block);
				labels [*dyc<Label>(*i)->label_name->get_value_as_string ()] = v;
				break;

			case Goto::ID:
				v = add_bb (new Empty_block);
				break;

			case Branch::ID:
				v = add_bb (new Branch_block (dyc<Branch>(*i)));
					break;

			default:
				v = add_bb (new Statement_block (*i));
				break;
		}
		nodes[*i] = v;
	}


	// Create the edges
	vertex_t parent = entry;
	bool use_parent = true; // parent is just an int, so not nullable

	foreach (Statement* s, *statements)
	{
		// Be careful with pointers. Its very easy to overwrite vertices
		vertex_t v = nodes[s];
		if (use_parent)
			add_edge (parent, v, bs);


		switch (s->classid())
		{
			case Goto::ID:
			{
				vertex_t target = 
					labels[*dyc<Goto>(s)->label_name->get_value_as_string ()];
				add_edge (v, target, bs);

				use_parent = false;
				break;
			}

			case Branch::ID:
			{
				Branch* b = dyc<Branch>(s);
				vertex_t iftrue = labels[*b->iftrue->get_value_as_string ()];
				vertex_t iffalse = labels[*b->iffalse->get_value_as_string ()];
				add_edge (v, iftrue, bs);
				add_edge (v, iffalse, bs);

				use_parent = false;
				break;
			}

			default:
				parent = v;
				use_parent = true;
				break;
		}
	}
	
	assert (use_parent);
	add_edge (parent, exit, bs);

	// Check that no blocks have NULL vertices
	foreach (vertex_t v, vertices (bs))
	{
		assert (vb[v] != NULL);
	}

}

Basic_block*
CFG::get_entry_bb ()
{
	return vb[entry];
}

Basic_block*
CFG::get_exit_bb ()
{
	return vb[exit];
}

list<Basic_block*>*
CFG::get_predecessors (Basic_block* bb)
{
	list<Basic_block*>* result = new list<Basic_block*>;

	foreach (edge_t e, in_edges (bb->vertex, bs))
	{
		result->push_back (vb[source (e, bs)]);
	}

	return result;
}

list<Basic_block*>*
CFG::get_successors (Basic_block* bb)
{
	list<Basic_block*>* result = new list<Basic_block*>;

	foreach (edge_t e, out_edges (bb->vertex, bs))
	{
		result->push_back (vb[target (e, bs)]);
	}

	return result;
}

list<Basic_block*>*
CFG::get_all_bbs ()
{
	this->consistency_check();

	list<Basic_block*>* result = new list<Basic_block*>;

	foreach (vertex_t v, vertices(bs))
	{
		result->push_back (vb[v]);
	}

	return result;
}

// Dump to graphviz
struct BB_property_functor
{
	property_map<Graph, vertex_bb_t>::type vb;
	BB_property_functor (CFG* cfg)
	{
		vb = cfg->vb;
	}
	void operator()(std::ostream& out, const edge_t& v) const 
	{
		// No edges properties
		// TODO add true and false for Branches
	}

	void operator()(std::ostream& out, const vertex_t& v) const 
	{
		out << " [label=\"" << *DOT_unparser::escape (vb[v]->get_graphviz_label ()) << "\"";
		String* prop = vb[v]->get_graphviz_properties ();
		if (prop)
			out << ", " << *prop << " ";
		
		out << "]";
	}
};

struct Graph_property_functor
{
	void operator()(std::ostream& out) const 
	{
		out << "graph [outputorder=edgesfirst]" << std::endl;
	}
};

void
CFG::dump_graphviz ()
{
	write_graphviz (
		cout, 
		bs, 
		BB_property_functor(this),
		BB_property_functor(this),
		Graph_property_functor());
}

/* Error checking */
void
CFG::consistency_check ()
{
	// I believe the Graph can renumber the BBs. Each BB should have the correct vertex.
	foreach (vertex_t v, vertices (bs))
	{
		assert (vb[v]->vertex == v);
	}
}
