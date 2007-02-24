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
	String(); 
	String(const string& s); 
	String(char const* s); 
	String(char const* s, size_t n);
	virtual ~String();

public: // Required by Object
	virtual String* deep_clone(Object* partial_result = NULL);
	virtual bool try_match(Object* pattern);
	virtual void replace_wildcards(Object* pattern);
	virtual bool deep_equals(Object* other);
};

#endif
