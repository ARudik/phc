/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Class to represent bools 
 */

#ifndef PHC_BOOLEAN
#define PHC_BOOLEAN

// Hack in the C++ language to distinguish between pre and post ops
#define POST_INCREMENT int 

#include "lib/Object.h"

class Boolean : virtual public Object
{
private:
	bool _b;

public:
	Boolean() : _b(false) {}
	Boolean(bool b) : _b(b) {}
	bool value() { return _b; }

public:
	Boolean* deep_clone(Object* partial_result = NULL);
	bool deep_equals(Object* other);
};

#endif 
