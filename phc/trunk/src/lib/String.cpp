/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 *
 * Like STL string, but inherit from Object
 */

#include "String.h" 

String::String() 
{
	attrs = new AttrMap();
}

String::String(const string& s) : string(s)  
{
	attrs = new AttrMap();
}

String::String(char const* s) : string(s) 
{
	attrs = new AttrMap();
}

String::String(char const* s, size_t n) : string(s, n) 
{
	attrs = new AttrMap();
}

String::~String() 
{
}

String* String::deep_clone(Object* partial_result)
{
	String* clone;
	assert(!partial_result);
	clone = new String(*this);
	clone->attrs = attrs->deep_clone();
	return clone;
}	

bool String::try_match(Object* pattern)
{
	String* that = dynamic_cast<String*>(pattern);
	if(!that) return false;
	return (*this == *that);
}

void String::replace_wildcards(Object* pattern)
{
	String* that = dynamic_cast<String*>(pattern);
	assert(that);
}

bool String::deep_equals(Object* other)
{
	String* that = dynamic_cast<String*>(other);
	if(!that) return false;
	return (*this == *that);
}
