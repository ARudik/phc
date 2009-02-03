/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Points-to graph.
 *
 * There should be multiple graphs, 1 per function. there need to be links
 * between them, so I'm not clear if its better to have multiple regions
 * within a graph, or multiple graphs.
 *
 */

#include "Points_to.h"
#include "MIR.h"
#include "lib/error.h"
#include "lib/escape.h"
#include "lib/demangle.h"
#include "process_ir/General.h"

using namespace MIR;
using namespace std;
using namespace boost;

#define ST_NAME "__PHC_ST__"

Points_to::Points_to ()
{
}

/*
 * Add a storage node for the scope (or it might exist already in the case of
 * recursion). Add an GLOBALS node to it.
 */
void
Points_to::open_scope (string scope_name)
{
	// TODO: add the superglobals (its wrong to add the parameters before the
	// superglobals, but we've only 1 example of this breaking).
	
	// Add the GLOBALS node

	if (scope_name == "__MAIN__")
	{
		// TODO: remove this hack and move it into Aliasing
		add_edge (SN (scope_name), IN (scope_name, "GLOBALS"), DEFINITE);
		add_edge (IN (scope_name, "GLOBALS"), SN (scope_name));
	}
	else
	{
		// We need to remove the "global $GLOBALS;" statements, since they're wrong, but we should remove it here first.
//		set_reference (IN (scope_name, "GLOBALS"), IN ("__MAIN__", "GLOBALS"));
	}
}

void
Points_to::close_scope (string scope_name)
{
	// Remove the symbol table. Then do a mark-and-sweep from all the other
	// symbol tables.
	remove_node (SN (scope_name));

	remove_unreachable_nodes ();
}


void
Points_to::kill_value (Index_node* index)
{
	Storage_node_list* values = get_points_to (index, PTG_ALL);
	if (values->size ())
		phc_TODO (); // kill, and the things it points to - watch of for may-aliases
}

// Remove all references edges into or out of INDEX. Also call kill_value.
void
Points_to::kill_reference (Index_node* index)
{
	foreach (Index_node* other, *get_references (index, PTG_ALL))
	{
		remove_pair (index, other);
		remove_pair (other, index);
	}
}


// Kill the value of INDEX (which indicates a scalar is being assigned
// here). This only updates the graph if an object or array is killed. If the
// node is not in the graph, add it.
void
Points_to::assign_scalar (Index_node* index)
{
	if (contains (index))
		kill_value (index);

	add_node (index);
}


// Make N1 alias N2. Kills N1. Initialized N2 if it is not already.
void
Points_to::assign_by_ref (Index_node* n1, Index_node* n2)
{
	if (!contains (n2))
	{
		add_node (n2);
		phc_TODO (); // initialize to NULL
	}

	if (!contains (n1))
		add_node (n1);
	else
		kill_reference (n1);

	// TODO: abstract

	// Copy all edges to reference nodes
	certainty certainties[] = {POSSIBLE, DEFINITE};
	foreach (certainty cert, certainties)
	{
		Index_node_list* refs = get_references (n2, cert);
		foreach (Index_node* ref, *refs)
			add_bidir_edge (n1, ref);
	}


	// Copy all edges to storage nodes
	foreach (certainty cert, certainties)
	{
		Storage_node_list* pts = get_points_to (n2, cert);
		foreach (Storage_node* st, *pts)
			add_edge (n1, st);
	}

	add_bidir_edge (n1, n2);
}

// Copy the current value from N2 to N1. This clones N2's array, points N1
// and N2 to the same object for object's, and kills existing values for N1.
void
Points_to::assign_by_copy (Index_node* n1, Index_node* n2)
{
	if (!contains (n1) || !contains (n2))
		phc_TODO ();

	// This kills the value of N1, and may lead to a clone on N2's value.
	if (has_value_edges (n1) || has_value_edges (n2))
		phc_TODO ();
}




void
Points_to::dump_graphviz (String* label)
{
	if (label == NULL)
	{
		CHECK_DEBUG ();
		label = s("TEST");
	}

	cout
	<< "digraph G {\n"
	<< "graph [labelloc=t];\n"
	<< "graph [label=\"" << *label << "\"];\n"
	;

	// Add definite edges
	Alias_name source;
	Map<Alias_name, Alias_pair*> alias_map;
	foreach (tie (source, alias_map), by_source)
	{
		Alias_name target;
		Alias_pair* alias_pair;
		foreach (tie (target, alias_pair), alias_map)
		{
			assert (alias_pair);

			// Source
			cout
			<< "\""
			<< *escape_DOT (s (source.str()))
			<< "\" [" << *alias_pair->source->get_graphviz ()
			<< "];\n"
			;
			
			// Target
			cout
			<< "\""
			<< *escape_DOT (s (target.str()))
			<< "\" [" << *alias_pair->target->get_graphviz ()
			<< "];\n"
			;

			// Edge
			cout 
			<< "\""
			<< *escape_DOT (s(source.str())) 
			<< "\" -> \"" 
			<< *escape_DOT (s(target.str())) 
			<< "\" [label=\""
			<< (alias_pair->cert == POSSIBLE ? "P" : "D")
			<< "\"];\n"
			;
		}

	}

	cout
	<< "}\n"
	;
}




void
Points_to::add_node (Index_node* index)
{
	if (!contains (index))
		add_edge (SN (index->storage), index);
}

// Does the graph already contains this node.
bool
Points_to::contains (Index_node* index)
{
	// TODO: check its connected to a storage node
	return has_node (index);
}
// Does the node have edges pointing to a storage node
bool
Points_to::has_value_edges (Index_node* source)
{
	return get_points_to (source, PTG_ALL)->size () != 0;
}

// Return a list of aliases which are references
Index_node_list*
Points_to::get_references (Index_node* index, certainty cert)
{
	return get_aliases <Index_node> (index, cert);
}

// Only get the aliasias which are indices or Storage node NS
Index_node_list*
Points_to::get_local_references (Storage_node* sn, Index_node* node, certainty cert)
{
	Index_node_list* tmp = get_aliases <Index_node> (node, cert);

	// Its very awkward to do this in-place.
	Index_node_list* result = new Index_node_list;
	foreach (Index_node* node, *tmp)
	{
		if (sn->storage == node->storage)
			result->push_back (node);
	}

	return result;
}

// Get a list of aliases which are points-to.
Storage_node_list*
Points_to::get_points_to (Index_node* node, certainty cert)
{
	return get_aliases <Storage_node> (node, cert);
}


// Mark all symtable nodes, then sweep anything they can reach. Remove the
// rest.
void
Points_to::remove_unreachable_nodes ()
{
	// XXX: The problem is that this leaves reference nodes behind. But we
	// only really want to remove the reference nodes that are out of scope.
	// So a node representing a variable should be removed when its symtable
	// does. What about other reference nodes? If there is an array with no
	// references to it, do we want to keep its index_nodes? Well, only if
	// they're references elsewhere. But if they're referenced elsewhere, the
	// useful info is already copied.

	// Summary: when removing a storage, remove all its index nodes.
	
	// Which means that until arrays and objects are modelled, this function
	// does nothing.
	return;
	dump_graphviz (NULL);

	// Put all symtables into the worklist
	PT_node_list* worklist = new PT_node_list;
	PT_node_list* all_nodes = get_nodes <PT_node> ();
	foreach (PT_node* node, *all_nodes)
	{
		// TODO: split between symtable and other storage nodes
		if (Storage_node* sn = dynamic_cast<Storage_node*> (node))
			worklist->push_back (sn);
	}

	// Mark all reachable nodes (use names, not pointers, as there may be
	// mulitple descirptor with the same name, but obviously different
	// pointers).
	Set<Alias_name> reachable;

	while (worklist->size () > 0)
	{
		PT_node* node = worklist->front ();
		worklist->pop_front ();

		if (reachable.has (node->name ()))
			continue;

		// mark reachable
		reachable.insert (node->name ());
	
		// Add successors to the worklist
		foreach (PT_node* succ, *get_targets<PT_node> (node))
		{
			worklist->push_back (succ);
		}
	}

	// remove all nodes not marked as reachable
	foreach (PT_node* node, *all_nodes)
	{
		// We use get_all_nodes because the vertex descriptors are invalidated
		// by remove_vertex
		if (!reachable.has (node->name ()))
		{
			phc_TODO ();
		}
	}
	dump_graphviz (NULL);
}


/*
 * Low-level API
 */

// Add the edge to the graph.
void
Points_to::add_edge (PT_node* n1, PT_node* n2, certainty cert)
{
	insert (new Alias_pair (n1, n2, cert));
}

// Add 2 edges, to and from N1 and N2.
void
Points_to::add_bidir_edge (PT_node* n1, PT_node* n2, certainty cert)
{
	insert (new Alias_pair (n1, n2, cert));
	insert (new Alias_pair (n2, n1, cert));
}

Points_to*
Points_to::clone ()
{
	Points_to* result = new Points_to;

	foreach (Alias_pair* p, this->all_pairs)
	{
		// No need to deep copy, as pairs are never updated in-place.
		result->insert (p);
	}

	return result;
}


void
Points_to::insert (Alias_pair* pair)
{
	Alias_name source = pair->source->name ();
	Alias_name target = pair->target->name ();

	// TODO: dont duplicate
	if (by_source[source].has (target))
		phc_TODO ();

	if (by_target[target].has (source))
		phc_TODO ();

	by_source[source][target] = pair;
	by_target[target][source] = pair;

	// Record all pairs.
	all_pairs.insert (pair);
}

bool
Points_to::has_node (PT_node* node)
{
	Alias_name name = node->name ();

	if (by_source[name].size ())
		return true;
	
	if (by_target[name].size ())
		return true;

	return false;
}

// And fail if its not present (unless !EXPECTED).
void
Points_to::remove_pair (PT_node* source, PT_node* target, bool expected)
{
	Alias_name s = source->name ();
	Alias_name t = target->name ();

	if (!by_source[s].has (t))
	{
		if (!expected)
			return;

		phc_unreachable ();
	}

	Alias_pair* edge = by_source[s][t];
	assert (edge);

	// Find the edge and remove it from all_pairs;
	all_pairs.erase (edge);

	// Remove it from by_source
	by_source[s].erase (t);

	// Remove it from by_target
	by_target[t].erase (s);
}

void
Points_to::remove_node (PT_node* node)
{
	if (isa<Storage_node> (node))
	{
		// This cant recurse, as storage nodes can only have index_nodes, which
		// won't be removed like this.
		foreach (Index_node* member, *get_targets<Index_node> (node))
		{
			remove_node (member);
		}
	}

	// dont use foreach, as remove_pair kills the iterators.
	while (by_source [node->name ()].size ())
	{
		Alias_name name;
		Alias_pair* pair;

		tie (name, pair) = *by_source [node->name ()].begin();
		remove_pair (pair->source, pair->target, true);
		remove_pair (pair->target, pair->source, false);
	}
}


/*
 * Alias-pairs
 */

Alias_pair::Alias_pair (PT_node* source, PT_node* target, certainty cert)
: source (source)
, target (target)
, cert (cert)
{
}

void
Alias_pair::dump()
{
	CHECK_DEBUG ();
	cdebug
	<< source->name ().str() << " -> "
	<< target->name ().str()
	<< " - " << cert;
}


/*
 * Nodes
 */
Storage_node* SN (string scope)
{
	return new Storage_node (scope);
}

Index_node* IN (string scope, string name)
{
	return new Index_node (scope, name);
}

Index_node* VN (string scope, MIR::VARIABLE_NAME* var)
{
	return IN (scope, *var->value);
}

Index_node* FN (string scope, MIR::FIELD_NAME* field)
{
	return IN (scope, *field->value);
}




Storage_node::Storage_node (string storage)
: storage (storage)
, is_abstract (false)
{
}

Alias_name
Storage_node::name ()
{
	return Alias_name ("ST", storage);
}

String*
Storage_node::get_graphviz ()
{
	stringstream ss;
	ss << "shape=box";
	return s (ss.str ());
}

Index_node::Index_node (string storage, string index)
: storage (storage)
, index (index)
{
}

Alias_name
Index_node::name ()
{
	return Alias_name (storage, index);
}

String*
Index_node::get_graphviz ()
{
	return s("");
}
