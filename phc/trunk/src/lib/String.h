/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 *
 * Like STL string, but inherit from Object
 */

#ifndef PHC_STRING
#define PHC_STRING

#include <string>
#include "lib/Object.h"
#include "lib/AttrMap.h"

using namespace std;

class Wildcard;
extern Wildcard* WILDCARD;

class String : public string, virtual public Object
{
public:
	AttrMap* attrs;

public:
	String() : attrs(NULL) {}
	String(const string& s) : string(s), attrs(NULL) {}
	String(const char* s) : string(s), attrs(NULL) {}
	String(const char* s, size_t n) : string(s, n), attrs(NULL) {}
	String* deep_clone(Object* partial_result = NULL)
	{
		String* clone;
		assert(!partial_result);
		clone = new String(*this);
		if(attrs)
			clone->attrs = attrs->deep_clone();
	}	
	virtual bool try_match(Object* pattern)
	{
		String* that = dynamic_cast<String*>(pattern);
		if(!that) return false;
		return (*this == *that);
	}
	virtual void replace_wildcards(Object* pattern)
	{
		String* that = dynamic_cast<String*>(pattern);
		assert(that);
	}
	virtual bool deep_equals(Object* other)
	{
		String* that = dynamic_cast<String*>(other);
		if(!that) return false;
		return (*this == *that);
	}
	virtual ~String() {}
};

#endif
