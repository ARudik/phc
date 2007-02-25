#include "lib/Integer.h"

Integer* 
Integer::deep_clone(Object* partial_result)
{
	assert(!partial_result);
	return new Integer(_n);
}

	bool 
Integer::deep_equals(Object* other)
{
	Integer* that = dynamic_cast<Integer*>(other);
	if(!that)
		return false;

	return _n == that->_n;
}
