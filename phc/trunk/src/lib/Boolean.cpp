#include "lib/Boolean.h"

Boolean* Boolean::deep_clone(Object* partial_result)
{
	assert(!partial_result);
	return new Boolean(_b);
}

bool 
Boolean::deep_equals(Object* other)
{
	Boolean* that = dynamic_cast<Boolean*>(other);
	if(!that)
		return false;

	return _b == that->_b;
}
