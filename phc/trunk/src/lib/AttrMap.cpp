/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 * 
 * Like the STL list, but inherit from Object and support == (deep equality)
 */

#include "AttrMap.h"
#include "String.h"

AttrMap::AttrMap() : map<string, Object*>() 
{
}

AttrMap::~AttrMap() 
{
}

Object* AttrMap::get(string key)
{
	return (*this)[key];
}

Boolean* AttrMap::get_boolean(string key)
{
	Boolean* ret = dynamic_cast<Boolean*>((*this)[key]);
	assert(ret != NULL);
	return ret;
}

Integer* AttrMap::get_integer(string key)
{
	Integer* ret = dynamic_cast<Integer*>((*this)[key]);
	assert(ret != NULL);
	return ret;
}

String* AttrMap::get_string(string key)
{
	String* ret = dynamic_cast<String*>((*this)[key]);
	assert(ret != NULL);
	return ret;
}

bool AttrMap::is_true(string key)
{
	Boolean* ret = dynamic_cast<Boolean*>((*this)[key]);
	if(ret == NULL)
		return false;
	else
		return ret->value();
}

bool AttrMap::has(string key)
{
	return find(key) != end();
}

void AttrMap::set(string key, Object* value)
{
	(*this)[key] = value;
}

bool AttrMap::deep_equals(Object* other)
{
	AttrMap* that = dynamic_cast<AttrMap*>(other);
	if(that == NULL)
		return false;

	if(size() != that->size())
		return false;
	
	AttrMap::const_iterator i;
	AttrMap::const_iterator j;
	for(i = begin(); i != end(); i++)
	{
		j = that->find((*i).first);
	
		if(j == that->end())
			return false;

		if(!((*i).second)->deep_equals((*j).second))
			return false;
	}

	return true;
}
	
AttrMap* AttrMap::deep_clone(Object* partial_result)
{
	AttrMap* clone;

	if(partial_result)
		clone = dynamic_cast<AttrMap*>(partial_result);
	else
		clone = new AttrMap();
	assert(clone);

	AttrMap::const_iterator i;
	for(i = begin(); i != end(); i++)
	{
		if((*i).second)
			clone->set((*i).first, (*i).second->deep_clone());
		else
			clone->set((*i).first, NULL);
	}

	return clone;
}
