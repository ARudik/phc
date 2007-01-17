/*
 * phc -- the open source PHP compiler
 * Parser for the AST in XML format
 */

#ifndef PHC_XML_PARSER_H
#define PHC_XML_PARSER_H

#include <phc/config.h>

#ifdef HAVE_XERCES
#include <phc/ast.h>
AST_php_script* parse_ast_xml_file(String* filename);
AST_php_script* parse_ast_xml_buffer(String* buffer);
AST_php_script* parse_ast_xml_stdin();
#endif // HAVE_XERCES

#endif // PHC_XML_PARSER_H
