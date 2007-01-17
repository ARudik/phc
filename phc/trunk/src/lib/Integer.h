/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 *
 * Class to represent ints (for passing around as synthesized attributes) 
 */
 
#ifndef PHC_INTEGER
#define PHC_INTEGER

// Hack in the C++ language to distinguish between pre and post ops
#define POST_INCREMENT int 

#include <phc/lib/Object.h>

class Integer : virtual public Object
{
private:
	long _n;
	
public:
	Integer() : _n(0) {}
	Integer(long n) : _n(n) {}
	long value() { return _n; }

public:
	void operator++(POST_INCREMENT) { _n++; }

public:
	Integer* deep_clone(Object* partial_result = NULL)
	{
		assert(!partial_result);
		return new Integer(_n);
	}
	
	bool deep_equals(Object* other)
	{
		Integer* that = dynamic_cast<Integer*>(other);
		if(!that)
			return false;

		return _n == that->_n;
	}
};

#endif
