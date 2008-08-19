#ifndef PHC_SET
#define PHC_SET

#include <set>
#include <lib/String.h>

class Set
{
public:
	// Backing store
	set<string> bs;

	// If true, the SET holds every possbible variable.
	bool full;

public:
	Set();

public:
	// Out-of-place operations return new sets. We only consider out-of-place
	// versions since the STL includes only out-of-place versions. In-place
	// versions could be created in some cases, however, possibly with lower
	// complexity.
	Set* set_union (Set* other);
	Set* set_intersection (Set* other);
	Set* set_difference (Set* other);
	bool operator!=(Set& other);
	bool operator==(Set& other);
	
public:
	void insert (String* string);

	// The set is the set of all possible strings.
	void insert_all ();

	bool contains (String* string);
	void dump(ostream&);
};


#endif // PHC_SET