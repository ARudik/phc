/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 *
 * Return the demangled classname of the specified object 
 */

#ifndef PHC_DEMANGLE
#define PHC_DEMANGLE

#include <phc/lib/Object.h>
const char* demangle(Object* obj);

#endif // PHC_DEMANGLE
