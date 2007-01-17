/*
 * phc -- the open source PHP compiler
 *
 * Base64 encoder/decoder. See RFC2045.
 */

#ifndef PHC_BASE64_H
#define PHC_BASE64_H

#include <phc/lib/String.h>

String* base64_encode(String* str);
String* base64_decode(String* str);

#endif // PHC_BASE64_H
