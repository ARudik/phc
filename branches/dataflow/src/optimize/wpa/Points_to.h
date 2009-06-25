/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Points-to graph.
 *
 *
 */

#ifndef PHC_POINTS_TO
#define PHC_POINTS_TO

#include <boost/type_traits/is_same.hpp> // TODO: probably unused soon
#include "MIR.h"

#include "lib/List.h"
#include "lib/String.h"
#include "lib/Set.h"
#include "lib/Map.h"


#include "WPA.h"

DECL (PT_node);
DECL (Index_node);
DECL (Storage_node);
DECL (Path);

SET_COMPARABLE (Points_to);

Storage_node* SN (string scope);
Index_node* IN (string scope, string name);
Index_node* VN (string scope, MIR::VARIABLE_NAME*);
Index_node* FN (string scope, MIR::FIELD_NAME*);

Value_node* SCLVAL (Index_node* node);
Storage_node* CX_array_node (Context* cx);
Storage_node* CX_object_node (Context* cx);
Storage_node* CX_symtable_node (Context* cx);



// A node in the graph (ie the abstract base of the components of an
// alias-pair).
class PT_node : virtual public GC_obj
{
public:
	// Each PT node gets a unique name for the alias pairs representation.
	virtual Alias_name name () = 0;
	virtual String* get_graphviz_label () = 0;

	virtual PT_node* convert_context_name () = 0;
};

/*
 * An index_node represents a variable, array-index or field of a storage node.
 *
 * It comprises a descriptor, the storage node's name, and the index name.
 * There is not a unique descriptor for this node. Any object with the same
 * descriptor represents the same node, in any graph. So we cannot store
 * attributes in here (they should be in the other analyses' lattices, indexed
 * by node->name ().str ()).
 */
class Index_node : public PT_node
{
public:
	// The name of the storage node which this indexes.
	const string storage;

	// The name of the node (can be UNKNOWN)
	const string index;

public:
	Index_node (string storage, string index);

	virtual Alias_name name ();
	virtual String* get_graphviz_label ();
	virtual Index_node* convert_context_name ();
	Path* to_path ();
};



// Represents class for arrays, objects and symtables.
class Storage_node : public PT_node
{
public:
	const string storage;

public:
	Storage_node (string storage);

	virtual Alias_name name ();
	virtual String* get_graphviz_label ();
	virtual Storage_node* convert_context_name ();

public:
	// Return a string suitable to be put as the prefix of an index_name.
	virtual string for_index_node ();
};

// This represents the value of the node that points to it. It is used as the
// name for scalars and such. It is tricky to track that information if only
// storage nodes are used, as the possible/definite thing is difficult.
class Value_node : public Storage_node
{
public:
	Value_node (Index_node* owner);
	Value_node (string owner);

	Alias_name name ();
	String* get_graphviz_label ();
	Value_node* convert_context_name ();

public:
	string for_index_node ();
};


// Just a pair really, but I didnt want to have to remember which was FIRST and which was SECOND.
class Reference : virtual public GC_obj
{
public:
	Reference (Index_node* index, Certainty cert)
	: index(index)
	, cert(cert)
	{
	}

public:
	Index_node* const index;
	const Certainty cert;
};

typedef List<Reference*> Reference_list;

template <class Source_type, class Target_type>
class Alias_pair : virtual public GC_obj
{
protected:
	typedef Alias_pair<Source_type, Target_type> parent;

public:

	Alias_pair (Source_type* source, Target_type* target)
	: source (source)
	, target (target)
	{
	}

	bool equals (parent* other)
	{
		Alias_name this_source = this->source->name();
		Alias_name this_target = this->target->name();
		Alias_name other_source = other->source->name();
		Alias_name other_target = other->target->name();

		return true
			&& this_source == other_source
			&& this_target == other_target
			;
	}

	void dump()
	{
		CHECK_DEBUG ();
		cdebug
			<< source->name ().str() << " -> "
			<< target->name ().str()
			;
	}

	Source_type* const source;
	Target_type* const target;
};

// Cert is kept outside the edge. It is returned from Points-to via Reference.
typedef Alias_pair<Index_node, Index_node> Reference_edge;
typedef Alias_pair<Index_node, Storage_node> Points_to_edge; 
typedef Alias_pair<Storage_node, Index_node> Field_edge; 

DECL_LIST (Points_to_edge);
DECL_LIST (Field_edge);
DECL_LIST (Reference_edge);

SET_COMPARABLE (Points_to_edge);
SET_COMPARABLE (Field_edge);
SET_COMPARABLE (Reference_edge);


/*
 * NOTE:
 *
 *	All PT_nodes are simply descriptors for nodes. They do not provide a means
 *	to access the node itself.
 *
 *	Note too that the index_node is merely a unique point in the graph. There
 *	is no direct mapping to PHP constructs, as some are more compicated that
 *	that. For example: $x =& $x[$y], is an Index_node indexed by another
 *	Index_node, and can refer to multiple index_nodes.
 *
 *	The result is that Points_to just does the graphing. Paths and P provide the
 *	abstraction layer over the lower-level representation of PT_nodes, and there
 *	is a 1-to-1 correspondence between MIR nodes and paths.
 */

class Empty : virtual public GC_obj
{
public:
	bool operator!= (const Empty&) const { return false; }
	bool operator== (const Empty&) const { return true; }
};

class Empty_combiner
{
public:
	Empty operator()(const Empty, const Empty) { return Empty (); }
};


class Empty_default
{
public:
	static Empty default_value () { return Empty (); }
};

class Certainty_combiner
{
public:
	Certainty operator()(const Certainty c1, const Certainty c2)
	{
		return combine_certs (c1, c2);
	}
};

class Certainty_default
{
public:
	static Certainty default_value () { phc_unreachable (); }
};



template <class Source_type, class Target_type, class Edge_type, class Value_type = Empty, class Default = Empty_default, class Combiner = Empty_combiner>
class Pair_map : virtual public GC_obj
{
	typedef Source_type source_type;
	typedef Target_type target_type;
	typedef Edge_type edge_type;
	typedef Pair_map<Source_type, Target_type, Edge_type, Value_type, Default, Combiner> this_type;

public:

	// This can result in the edge being shared, which is fine.
	Pair_map<Source_type, Target_type, Edge_type, Value_type, Default, Combiner> (this_type& other)
	: values (other.values)
	, by_source (other.by_source)
	, by_target (other.by_target)
	{
	}

	Pair_map<Source_type, Target_type, Edge_type, Value_type, Default, Combiner> ()
	{
	}


	// Storing values
	Value_type get_value (Edge_type* edge)
	{
		return this->get_value (edge->source, edge->target);
	}

	Value_type get_value (Source_type* source, Target_type* target)
	{
		assert (this->has_edge (source, target));

		return values[source->name ()][target->name ()];
	}

	void set_value (Edge_type* pair, Value_type value = Default::default_value ())
	{
		this->set_value (pair->source, pair->target, value);
	}

	void set_value (Source_type* source, Target_type* target, Value_type value = Default::default_value ())
	{
		values[source->name()][target->name()] = value;
	}

	List<Target_type*>* get_targets (Source_type* source)
	{
		List<Target_type*>* result = new List<Target_type*>;

		foreach (Edge_type* edge, *by_source[source->name()].values ())
			result->push_back (edge->target);

		return result;
	}

	List<Source_type*>* get_sources (Target_type* target)
	{
		List<Source_type*>* result = new List<Source_type*>;

		foreach (Edge_type* edge, *by_target[target->name()].values ())
			result->push_back (edge->source);

		return result;
	}

	List<Target_type*>* get_all_targets ()
	{
		List<Target_type*>* result = new List<Target_type*>;

		foreach (Edge_type* edge, *this->get_edges ())
			result->push_back (edge->target);

		return result;
	}

	List<Source_type*>* get_all_sources ()
	{
		List<Source_type*>* result = new List<Source_type*>;

		foreach (Edge_type* edge, *this->get_edges ())
			result->push_back (edge->source);

		return result;
	}

	List<Edge_type*>* get_edges ()
	{
		List<Edge_type*>* result = new List<Edge_type*>;

		typedef Map<Alias_name, Edge_type*> Map_type;
		foreach (Map_type& map, *by_source.values ())
			result->push_back_all (map.values ());

		return result;
	}



	// Equality
	bool equals (this_type* other)
	{
		// Check the edges
		if (this->get_edges ()->size () != other->get_edges ()->size ())
			return false;

		foreach (Edge_type* e, *other->get_edges ())
			if (not this->has_edge (e))
				return false;

		// Check the values
		foreach (Edge_type* e, *other->get_edges ())
			if (this->get_value (e) != other->get_value (e))
				return false;

		return true;
	}


	void add_edge (Source_type* source, Target_type* target, Value_type v = Default::default_value ())
	{
		this->add_edge (new Edge_type (source, target), v);
	}

	void add_edge (Edge_type* edge, Value_type v = Default::default_value ())
	{
		Alias_name source_name = edge->source->name ();
		Alias_name target_name = edge->target->name ();

		if (this->has_edge (edge))
		{
			if (values[source_name][target_name] != v)
				phc_TODO ();
		}
		else
		{
			by_source [source_name][target_name] = edge;
			by_target [target_name][source_name] = edge;
		}

		values[source_name][target_name] = v;
	}

	bool has_edge (Edge_type* edge)
	{
		return this->has_edge (edge->source, edge->target);
	}

	bool has_edge (Source_type* source, Target_type* target)
	{
		bool result = (by_source[source->name()].has (target->name()));

		assert (result == (by_target[target->name()].has (source->name())));

		return result;
	}

	bool has_target (Target_type* target)
	{
		return by_target.has (target->name());
	}

	bool has_source (Source_type* source)
	{
		return by_source.has (source->name());
	}

	void remove_edge (Source_type* source, Target_type* target)
	{
		by_source[source->name()].erase (target->name ());
		by_target[target->name()].erase (source->name ());
		values[source->name()].erase (target->name());
	}

	void remove_all_incoming_edges (Target_type* target)
	{
		foreach (Source_type* source, *this->get_sources (target))
			this->remove_edge (source, target);
	}

	void remove_all_outgoing_edges (Source_type* source)
	{
		foreach (Target_type* target, *this->get_targets (source))
			this->remove_edge (source, target);
	}

	this_type* merge (this_type* other)
	{
		this_type* result = new this_type (*this);

		foreach (Edge_type* e, *other->get_edges ())
		{
			if (result->has_edge (e))
			{
				Value_type combined = Combiner() (other->get_value (e), result->get_value (e));
				result->set_value (e, combined);
			}
			else
			{
				result->add_edge (e, other->get_value (e));
			}

		}

		return result;
	}

	// Returns a clone in which all the names are converted to context names.
	this_type* convert_context_names ()
	{
		this_type* result = new this_type;

		foreach (Edge_type* e, *this->get_edges ())
		{
			Edge_type* new_edge = new Edge_type (
				e->source->convert_context_name (),
				e->target->convert_context_name ());

			Value_type pre_merge_value = this->get_value (e);

			if (result->has_edge (new_edge))
			{
				Value_type combined = Combiner() (pre_merge_value, result->get_value (new_edge));
				result->set_value (new_edge, combined);
			}
			else
			{
				result->add_edge (new_edge, pre_merge_value);
			}
		}
		return result;
	}



private:
	Map<Alias_name, Map<Alias_name, Value_type> > values;
	Map<Alias_name, Map<Alias_name, Edge_type*> > by_source;
	Map<Alias_name, Map<Alias_name, Edge_type*> > by_target;
};

/*
 * Abstract is a state machine with 3 states:
 *		MISSING -> PRESENT -> ABSTRACT
 *
 *	ABSTRACT means its saturated, and so we can never get back from there.
 *	An ABSTRACT node can be removed however, if nothing points to it.
 */
namespace Abstract_state
{
	enum _as { MISSING = 0 /*default*/, PRESENT = 1, ABSTRACT = 2};
	typedef enum _as AS;

	AS inc (AS as);
	AS dec (AS as);
	AS merge (AS as1, AS as2);
}


class Points_to_impl : virtual public GC_obj
{
private:
	int reference_count;
	friend class Points_to;

private:
	// This keeps count of whether something is abstract or not (subsuming
	// whether it is in scope).
	Map<Alias_name, Abstract_state::AS> abstract_states;

	// The set of storage nodes which are a function's symbol table.
	Set<Alias_name> symtables;

	typedef Pair_map<Index_node, Index_node, Reference_edge, Certainty, Certainty_default, Certainty_combiner> reference_pair_type;

	// (Index_node, Index_node) -> certainty.
	// SOURCE and TARGET alias each other, with some CERTAINTY in { POSSIBLE,
	// DEFINITE }.
	reference_pair_type references;

	// (Index_node, Storage_node) set.
	// SOURCE is an index points-to TARGET. Its certainty is determined
	// implicitly by the number of points-to edges from SOURCE.
	Pair_map<Index_node, Storage_node, Points_to_edge> points_to;

	// TARGETs are indices of SOURCE. A certainty would indicate whether it is
	// initialized, but is probably a bit hard to do (and not worth it compared
	// to an 'is_initialized' analysis.
	// TODO: might be much easier with the new design.
	// (Storage_node, Index_node) set.
	Pair_map<Storage_node, Index_node, Field_edge> fields;

public:
	Points_to_impl ();

	void open_scope (Storage_node* st);
	void close_scope (Storage_node* st);
	bool is_abstract (Storage_node* st);
	void inc_abstract (Storage_node* st);
	void dec_abstract (Storage_node* st);
	bool is_abstract_field (Index_node* index);
	bool is_symtable (Storage_node* st);

	/*
	 * Reference
	 */

	// References are (target, certainty) pairs. Don't confuse them with
	// Reference_edges.
	Reference_list* get_references (Index_node* source, Certainty cert = PTG_ALL);
	Certainty get_reference_cert (Reference_edge* edge);
	Certainty get_reference_cert (Index_node* source, Index_node* target);

	void add_reference (Index_node* source, Index_node* target, Certainty cert);

	bool has_reference (Reference_edge* edge);
	bool has_reference (Index_node* source, Index_node* target);

	// Just removes the reference
	void remove_reference (Index_node* source, Index_node* target);

	/*
	 * Points-to edges
	 */

	// Storage nodes that index_node points-to.
	Storage_node_list* get_points_to (Index_node* index);
	Index_node_list* get_points_to_incoming (Storage_node* st);

	void add_points_to (Index_node* source, Storage_node* target);
	bool has_points_to (Index_node* source, Storage_node* target);

	// Removes the points-to edge, and nothing else. The caller must ensure that
	// the index is not left pointing to nothing.
	void remove_points_to (Index_node* source, Storage_node* target);


	/*
	 * Field edges
	 */

	Index_node_list* get_fields (Storage_node* storage);

	// The storage node of an index node is implicit (in the STORAGE field).
	void add_field (Index_node* field);
	bool has_field (Index_node* field);

	Storage_node* get_storage (Index_node* field);

	// Remove the edge from the storage-node to the index-node. Also removes
	// outgoing points-to edges, and reference edges.
	void remove_field (Index_node* target);

	// Try really really hard to find the "correct" owner of the index_node,
	// even if it is not in the graph, or the index_node is impossible
	// (SCLVAL->index for example).
	Storage_node* get_owner (Index_node* index);


	/*
	 * Nodes
	 */

	PT_node_list* get_nodes ();
	Index_node_list* get_index_nodes ();
	Storage_node_list* get_storage_nodes ();


	bool has_storage_node (Storage_node* st);

	void remove_index_node (Index_node* index);
	void remove_storage_node (Storage_node* st);

	/*
	 * Whole graph.
	 */

	bool equals (Points_to_impl* other);
	void dump_graphviz (String* label, Context* cx, Result_state state, Whole_program* wp);

	Points_to_impl* clone();
	Points_to_impl* merge (Points_to_impl* other);

	void consistency_check (Context* cx, Result_state state, Whole_program* wp);


	static Index_node_list* get_possible_nulls (List<Points_to_impl*>* graphs);

	// A lot of points in the graph use names derived from some context. Change
	// them to use a non-contextual version.
	void convert_context_names ();

	void remove_unreachable_nodes ();

	/*
	 * Lower-level API
	 */

private:

	void remove_node (PT_node* node);

	reference_pair_type* merge_references (Points_to_impl* other);

};


/*
 * A thin wrapper around Points-to, to provide copy-on-write. There are
 * probably better ways to do this (ie reuse someone else's code), but they
 * rely on C++ idioms, which we haven't really been using.
 *
 * A Points_to_impl belongs to a Points_to, and is never passed directly to
 * another Points_to.
 */
class Points_to : virtual public GC_obj
{
private:
	Points_to_impl* impl;
	int reference_count;

	void separate ()
	{
		if (this->impl->reference_count == 1)
			return;

		impl = impl->clone ();
	}

	Points_to (Points_to_impl* impl)
	: impl (impl)
	{
	}


public:

	Points_to ()
	{
		impl = new Points_to_impl;
	}

	/*
	 * Simple pass-through
	 */

	bool has_field (Index_node* field) { return impl->has_field (field); };
	bool has_points_to (Index_node* source, Storage_node* target) { return impl->has_points_to (source, target); }
	bool has_reference (Index_node* source, Index_node* target) { return impl->has_reference (source, target); }
	bool has_reference (Reference_edge* edge) { return impl->has_reference (edge); }
	bool has_storage_node (Storage_node* st) { return impl->has_storage_node (st); }
	bool is_abstract_field (Index_node* index) { return impl->is_abstract_field (index); }
	bool is_abstract (Storage_node* st) { return impl->is_abstract (st); }
	bool is_symtable (Storage_node* st) { return impl->is_symtable (st); }
	Certainty get_reference_cert (Index_node* source, Index_node* target) { return impl->get_reference_cert (source, target); }
	Certainty get_reference_cert (Reference_edge* edge) { return impl->get_reference_cert (edge); }
	Index_node_list* get_fields (Storage_node* storage) { return impl->get_fields (storage); }
	Index_node_list* get_index_nodes () { return impl->get_index_nodes (); }
	Index_node_list* get_points_to_incoming (Storage_node* st) { return impl->get_points_to_incoming (st); }
	PT_node_list* get_nodes () { return impl->get_nodes (); }
	Reference_list* get_references (Index_node* source, Certainty cert = PTG_ALL) { return impl->get_references (source, cert); }
	Storage_node* get_owner (Index_node* index) { return impl->get_owner (index); }
	Storage_node* get_storage (Index_node* field) { return impl->get_storage (field); }
	Storage_node_list* get_points_to (Index_node* index) { return impl->get_points_to (index); }
	Storage_node_list* get_storage_nodes () { return impl->get_storage_nodes (); }
	void consistency_check (Context* cx, Result_state state, Whole_program* wp) { return impl->consistency_check (cx, state, wp); }
	void dump_graphviz (String* label, Context* cx, Result_state state, Whole_program* wp) { return impl->dump_graphviz (label, cx, state, wp); }

	/*
	 * Minor interfacing work involved
	 */
	static Index_node_list* get_possible_nulls (List<Points_to*>* graphs)
	{
		List<Points_to_impl*>* impls = new List<Points_to_impl*>;
		foreach (Points_to* ptg, *graphs)
		{
			impls->push_back (ptg->impl);
		}
		return Points_to_impl::get_possible_nulls (impls);
	}

	bool equals (Points_to* other)
	{
		if (this->impl == other->impl)
			return true;

		return this->impl->equals (other->impl);
	}

	Points_to* clone ()
	{
		this->impl->reference_count++;
		return new Points_to (this->impl);
	}

	Points_to* merge (Points_to* other)
	{
		if (this->impl == other->impl)
		{
			this->impl->reference_count++;
			return new Points_to (this->impl);
		}

		return new Points_to (this->impl->merge (other->impl));
	}



	/*
	 * Needs to clone for copy-on-write
	 */

	void open_scope (Storage_node* st)
	{
		separate ();
		impl->open_scope (st);
	}

	void close_scope (Storage_node* st)
	{
		separate ();
		impl->close_scope (st);
	}

	void inc_abstract (Storage_node* st)
	{
		separate ();
		impl->inc_abstract (st);
	}

	void add_reference (Index_node* source, Index_node* target, Certainty cert)
	{
		separate ();
		impl->add_reference (source, target, cert);
	}

	void remove_reference (Index_node* source, Index_node* target)
	{
		separate ();
		impl->remove_reference (source, target);
	}

	void add_points_to (Index_node* source, Storage_node* target)
	{
		separate ();
		impl->add_points_to (source, target);
	}

	void remove_points_to (Index_node* source, Storage_node* target)
	{
		separate ();
		impl->remove_points_to (source, target);
	}

	void add_field (Index_node* field)
	{
		separate ();
		impl->add_field (field);
	}

	void remove_field (Index_node* target)
	{
		separate ();
		impl->remove_field (target);
	}

	void remove_index_node (Index_node* index)
	{
		separate ();
		impl->remove_index_node (index);
	}

	void remove_storage_node (Storage_node* st)
	{
		separate ();
		impl->remove_storage_node (st);
	}

	void convert_context_names ()
	{
		separate ();
		impl->convert_context_names ();
	}

	void remove_unreachable_nodes ()
	{
		separate ();
		impl->remove_unreachable_nodes ();
	}
};

#endif // PHC_POINTS_TO
