/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 * 
 * Like the STL list, but inherit from Object and support == (deep equality)
 */

#ifndef PHC_MAP
#define PHC_MAP

using namespace std;

#include <map>
#include "lib/Object.h"
#include "lib/Boolean.h"
#include "lib/Integer.h"
#include "lib/String.h"

class AttrMap : public map<string, Object*>, virtual public Object
{
public:
	AttrMap();
	virtual ~AttrMap();

public:
	Object* get(string key);
	Boolean* get_boolean(string key);
	Integer* get_integer(string key);
	String* get_string(string key);
	bool is_true(string key);
	bool has(string key);

public:
	void set(string key, Object* value);
	
public:
	bool deep_equals(Object* other);
	AttrMap* deep_clone(Object* partial_result = NULL);
};

#endif // PHC_MAP
