/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Abstract values fetch their results from optimizations, and are then read
 * by (possibly other) optimizations to perform their analyses.
 *
 * For example, we might be able to say that an int times 1 is an int, but
 * not than an int times and int is an int.
 *
 */

#ifndef PHC_ABSTRACT_VALUE_H
#define PHC_ABSTRACT_VALUE_H

#include "process_ir/debug.h"

#include "lib/Object.h"
#include "lib/Set.h"
#include "lib/String.h"

namespace MIR { class Literal; }

typedef Set<string> Types;

class Abstract_value : virtual public GC_obj
{
public:
	MIR::Literal* const lit;
	Types* const types;

public:
	Abstract_value (MIR::Literal* lit);
	Abstract_value (Types* types);

	// An unknown type is awful.
	static Abstract_value* unknown ();

	// These could have a truth value incorporated - for now just use the
	// constant.
	bool known_true ();
	bool known_false ();

	bool equals (Abstract_value* absval);
	Abstract_value* clone ();

	void dump (std::ostream& os = cdebug);

private:
	Abstract_value (MIR::Literal*, Types* types);
};

namespace Type_info
{
	void dump_types (std::ostream& os, Types* types);
	Types* get_type (MIR::Literal* lit);
	Types* get_all_scalar_types ();
	bool is_scalar (string type);

	// Given a set of types, we want to know which types are scalars, which is
	// an array, and which are objects. These return new sets with only the
	// appropriate types in them.
	// TODO: all this time I've been ignoring resources!!
	Types* get_scalar_types (Types*);
	Types* get_array_types (Types*); // can only be "array" or empty
	Types* get_object_types (Types*); // anything thats not covered above.
}




#endif // PHC_ABSTRACT_VALUE_H
