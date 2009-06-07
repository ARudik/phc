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

#include "process_ir/debug.h"
#include "MIR.h"

#include "Abstract_value.h"
#include "embed/embed.h"

using MIR::Literal;
using namespace std;

Abstract_value::Abstract_value (Literal* lit)
: lit (lit)
, types (Type_info::get_type (lit))
{
}

Abstract_value::Abstract_value (Types* types)
: lit (NULL)
, types (types)
{
}

Abstract_value::Abstract_value (Literal* lit, Types* types)
: lit (lit)
, types (types)
{
}

Abstract_value*
Abstract_value::unknown ()
{
	return new Abstract_value (NULL, NULL);
}


void
Abstract_value::dump (ostream& os)
{
	CHECK_DEBUG ();
	os << "(";
	if (lit)
		os << *lit->get_value_as_string ();
	else
		os << "(B)";

	os << ", {";

	if (types)
		Type_info::dump_types (os, types);
	else
		os << "(B)";

	os << "})";
}

bool
Abstract_value::known_false ()
{
	if (lit == NULL)
		return false;

	return not this->known_true ();
}

bool
Abstract_value::known_true ()
{
	if (lit == NULL)
		return false;

	return PHP::is_true (lit);
}


bool
Abstract_value::equals (Abstract_value* other)
{
	if (this->lit == NULL || other->lit == NULL)
		return this->lit == other->lit;
	else
		return this->lit->equals (other->lit);

	if (this->types == NULL || other->types == NULL)
		return this->types == other->types;
	else
		return this->types->equals (other->types);
}



namespace Type_info
{

void
dump_types (ostream& os, Types* types)
{
	foreach (string type, *types)
	{
		os << type << ", ";
	}
}

class MIR_types : public Map<int,string>
{
public:
   MIR_types () : Map<int,string>()
	{
		(*this)[MIR::BOOL::ID]		= "bool";
		(*this)[MIR::INT::ID]		= "int";
		(*this)[MIR::NIL::ID]		= "unset";
		(*this)[MIR::REAL::ID]		= "real";
		(*this)[MIR::STRING::ID]	= "string";
	}
};

// Avoid the "static inialization order fiasco"
MIR_types& mir_types ()
{
	static MIR_types types;
	return types;
}

class Scalar_types : public Types
{
public:
   Scalar_types () : Types ()
	{
		insert ("bool");
		insert ("int");
		insert ("unset");
		insert ("real");
		insert ("string");
	}
};

// Avoid the "static inialization order fiasco"
Scalar_types& scalar_types ()
{
	static Scalar_types types;
	return types;
}

Types*
get_all_scalar_types ()
{
	return &scalar_types ();
}

Types*
get_type (MIR::Literal* lit)
{
	return new Types (mir_types() [lit->classid()]);
}


Types*
get_scalar_types (Types* in)
{
	Types* out = new Types;

	// Faster and simpler to check for each scalar type than the other way
	// round.
	foreach (string scalar, scalar_types())
		if (in->has (scalar))
			out->insert (scalar);

	return out;
}

Types*
get_array_types (Types* in)
{
	if (in->has ("array"))
		return new Types ("array");
	else
		return new Types ();
}

Types*
get_object_types (Types* in)
{
	Types* out = new Types;
	foreach (string type, *in)
		if (!scalar_types().has (type) && type != "array")
			out->insert (type);

	return out;
}

} // end namespace


