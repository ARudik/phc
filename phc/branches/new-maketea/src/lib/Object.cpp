/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Superclass of all classes
 */

#include "lib/Object.h"

Object* 
Object::deep_clone(Object* partial_result)
{
	return partial_result;
}

bool 
Object::deep_equals(Object* other)
{
	return true;
}

bool 
Object::match(Object* pattern)
{
	if(try_match(pattern))
	{
		replace_wildcards(pattern);
		return true;
	}
	else
		return false;
}

bool 
Object::try_match(Object* pattern)
{
	assert(NOT_IMPLEMENTED);
	return false;
}

void 
Object::replace_wildcards(Object* pattern)
{
	assert(NOT_IMPLEMENTED);
}
