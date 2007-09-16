#ifndef _HIR_FACTORY_H_
#define _HIR_FACTORY_H_

#include "lib/List.h"
#include "lib/String.h"
#include <list>
#include <string>
#include <assert.h>
using namespace std;


#include "HIR.h"

namespace HIR{
class HIR_factory
{
public:
    // If type_id corresponds to HIR node, the elements in args must
    // correspond to the children of the node.
    // 
    // If type_id corresponds to a list (of the form "..._list"),
    // the elements of arg must be of the same type as the elements
    // in the list, and all elements in args are added to the list.
    // 
    // If type_id corresponds to a token (terminal symbol), args must
    // contain a single node of type String. Terminal symbols
    // with non-default values are not supported.
    static Object* create(char const* type_id, List<Object*>* args);
};
}


#endif
