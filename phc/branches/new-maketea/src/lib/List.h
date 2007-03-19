/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 * 
 * Like the STL list, but inherit from Object
 */
 
#ifndef PHC_LIST
#define PHC_LIST

#include <assert.h>
#include <list>
#include "lib/Object.h"

using namespace std;

class Wildcard;
extern Wildcard* WILDCARD;

template<typename _Tp, typename _Alloc = allocator<_Tp> >
class List : public list<_Tp, _Alloc>, virtual public Object 
{
public:
	using list<_Tp, _Alloc>::push_back;

public:
	List() : list<_Tp, _Alloc>() {}
	virtual ~List() {}

public:
	using list<_Tp, _Alloc>::begin;
	using list<_Tp, _Alloc>::end;

	List<_Tp, _Alloc>* deep_clone(Object* partial_result = NULL)
	{
		List<_Tp, _Alloc>* clone;

		if(partial_result)
			clone = dynamic_cast<List<_Tp, _Alloc>*>(partial_result);
		else
			clone = new List<_Tp, _Alloc>;
		assert(clone);

		typename List<_Tp, _Alloc>::const_iterator i;
		for(i = begin(); i != end(); i++)
		{
			if(*i)
				clone->push_back(dynamic_cast<_Tp>((*i)->deep_clone()));
			else
				clone->push_back(NULL);
		}
		
		return clone;
	}

	virtual bool try_match(Object* pattern)
	{
		List<_Tp, _Alloc>* that = dynamic_cast<List<_Tp, _Alloc>*>(pattern);
		if(!that) return false;

		typename List<_Tp, _Alloc>::const_iterator i;
		typename List<_Tp, _Alloc>::iterator j;
		for(i = begin(), j = that->begin(); i != end() && j != that->end(); i++, j++)
		{
			if(dynamic_cast<void*>(*j) == dynamic_cast<void*>(WILDCARD))
				{ /* ignore */ }
			else if(*i == NULL)
				{ if(*j != NULL) return false; }
			else 
				{ if(!(*i)->match(*j)) return false; }
		}
		
		if(i != end() || j != that->end()) 
			return false;

		return true;
	}

	virtual void replace_wildcards(Object* pattern)
	{
		List<_Tp, _Alloc>* that = dynamic_cast<List<_Tp, _Alloc>*>(pattern);
		assert(that);
		
		typename List<_Tp, _Alloc>::const_iterator i;
		typename List<_Tp, _Alloc>::iterator j;
		for(i = begin(), j = that->begin(); i != end() && j != that->end(); i++, j++)
		{
			if(dynamic_cast<void*>(*j) == dynamic_cast<void*>(WILDCARD))
				{ *j = *i; }
			else if(*i != NULL)
				{ (*i)->replace_wildcards(*j); }
		}
	}

	virtual bool deep_equals(Object* other)
	{
		List<_Tp, _Alloc>* that = dynamic_cast<List<_Tp, _Alloc>*>(other);
		if(!that) return false;
		
		typename List<_Tp, _Alloc>::const_iterator i, j;
		for(i = begin(), j = that->begin(); i != end() && j != that->end(); i++, j++)
		{
			if(*i == NULL)
			{
				if(*j != NULL)
					return false;
			}
			else
			{
				if(!(*i)->match(*j)) 
					return false;	
			}
		}
		
		if(i != end() || j != that->end()) 
			return false;
		
		return true;
	}
	
	void push_back_all(List* other) 
	{
		insert(end(), other->begin(), other->end());
	}
};

#endif /* LIST_H */
