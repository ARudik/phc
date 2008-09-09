#ifndef PHC_EDGE
#define PHC_EDGE

#include <boost/graph/properties.hpp>

#include "MIR.h"
#include "CFG.h"
#include "Set.h"
#include "SSA.h"

// CFG edge
class Edge : public Object
{
public:
	Basic_block* source;
	Basic_block* target;
	edge_t edge;
	tribool direction;

public:
	Edge (Basic_block* source, Basic_block* target, edge_t edge);
	Edge (Basic_block* source, Basic_block* target, edge_t edge, bool direction);

public:
	/*
	 * Boost::Graph integration
	 */

	// Indicate to BGL that this represents a vertex internal property.
	typedef boost::edge_property_tag kind;
	edge_t vertex;

public:
	/*
	 * Graphviz properties
	 */

/*	virtual String* get_graphviz_label () = 0;

	// Override if there are extra properties for this block.
	// Returns a list of (name,value) pairs
	virtual list<std::pair<String*,String*> >* get_graphviz_properties ();

	// Returns a list of (name, list[values]) pairs
	virtual list<pair<String*,Set*> >* get_graphviz_bb_properties ();
	virtual list<pair<String*,Set*> >* get_graphviz_head_properties ();
	virtual list<pair<String*,Set*> >* get_graphviz_tail_properties ();
*/
public:
	/*
	 * Block properties
	 */

	bool is_executable;

	// TODO do we need to clone a block?
	Edge* clone();
};

// TODO move to SSA.h
class Phi;
class Statement_block;
class Branch_block;
class SSA_edge : public Object
{
public:
	// Target is either a PHI or a statement (aka an expr).
	
	// This means any BB (for a PHI) or a statement_block, or a branch_block.
	enum _which {PHI, STATEMENT, BRANCH} which;
	Phi* phi;

	Basic_block* bb;

	SSA_edge (Phi* phi);
	SSA_edge (Statement_block* bb);
	SSA_edge (Branch_block* bb);
	SSA_edge* clone ();
};

typedef List<SSA_edge*> SSA_edge_list;


#endif // PHC_EDGE
