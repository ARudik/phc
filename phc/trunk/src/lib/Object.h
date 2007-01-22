/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 *
 * Superclass of all classes
 */

#ifndef PHC_OBJECT
#define PHC_OBJECT

#include "config.h"
#include <assert.h>

#ifndef NULL
#define NULL 0L
#endif

#ifdef ENABLE_GC
#ifdef HAVE_GC_LIB
#ifdef HAVE_GC_INC
// Logical AND for the preceding three
#define USE_GC
#endif
#endif
#endif

#define NOT_IMPLEMENTED false

#ifdef USE_GC
#include "gc/gc_cpp.h"
class Object : public gc
#else
class Object
#endif
{
public:
	// Deep cloning and deep equality
	virtual Object* deep_clone(Object* partial_result = NULL)
	{
		return partial_result;
	}
	virtual bool deep_equals(Object* other)
	{
		return true;
	}
	// Pattern matching
	virtual bool match(Object* pattern)
	{
		if(try_match(pattern))
		{
			replace_wildcards(pattern);
			return true;
		}
		else
			return false;
	}
	virtual bool try_match(Object* pattern)
	{
		assert(NOT_IMPLEMENTED);
		return false;
	}
	virtual void replace_wildcards(Object* pattern)
	{
		assert(NOT_IMPLEMENTED);
	}
	// Make Object a virtual base (required for RTTI and dynamic casts)
	virtual ~Object() {}
};

#endif /* OBJECT_H */
