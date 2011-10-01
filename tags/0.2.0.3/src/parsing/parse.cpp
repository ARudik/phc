/*
 * phc -- the open source PHP compiler
 * See doc/license/README.license for licensing information
 *
 * Parser wrapper. 
 */

#include <fstream>
#include <istream>
#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "parse.h"
#include "cmdline.h"
#include "php_parser.tab.hpp"
#include "parsing/PHP_context.h"
#include "process_ast/Remove_parser_temporaries.h"
#include "process_ast/Token_conversion.h"

extern struct gengetopt_args_info args_info;

using namespace AST;
using namespace std;

String* search_file(String* filename, String_list* dirs);
void run_standard_transforms(PHP_script* php_script);

PHP_script* parse_code (String* code, String* filename, int line_number)
{
	// TODO: It is important to have this, but this also substancially slows
	// down my work. Since it already doesn't work in the general case, and line
	// numbers aren't available properly a lot of the time, it is best to
	// disable this assertion for now, and fix it later.
	if (filename == NULL)
		filename = new String ("");
	assert (filename);

	assert (code);

	stringstream ss;
	ss << *code;

	PHP_script* php_script = NULL;

	// Compile
	PHP_context* context = new PHP_context(ss, filename);
	context->source_line = line_number;

	// TODO remove duplication
	if(!PHP_parse(context))
	{
		php_script = context->php_script;
		php_script->attrs->set ("phc.filename", filename);
		run_standard_transforms(php_script);
	}

	php_script->assert_valid();
	return php_script;
}


PHP_script* parse(String* filename, String_list* dirs)
{
	assert(filename);
	
	PHP_script* php_script = NULL;

	String* full_path = search_file(filename, dirs);

	if(full_path == NULL)
		return NULL;

	ifstream file_input;
	istream& input = (*full_path == "-") ? cin : file_input;

	if(*full_path != "-")
	{
		file_input.open (full_path->c_str(), ifstream::in);
		if (not file_input.is_open ()) return NULL;
	}

	// Compile
	PHP_context* context = new PHP_context(input, full_path);

	//		if(is_dump_option ("tokens"))
	{
		// run the lexer only
		// TODO: reenable
		// while(parser.php_lexer->yylex());
	}
	//		else
	{
		if(!PHP_parse(context))
		{
			php_script = context->php_script;
			php_script->attrs->set ("phc.filename", filename);
			run_standard_transforms(php_script);
		}
	}

	if(file_input.is_open ()) file_input.close ();

	php_script->assert_valid();
	return php_script;
}

String* search_file(String* filename, String_list* dirs)
{
	struct stat buf;

	if(*filename == "-")
		return filename;
	
	if(dirs == NULL)
		return filename;

	// Check whether filename can be opened without searching dirs
	if(!stat(filename->c_str(), &buf))
	{
		return filename;
	}

	// Otherwise, search dirs
	foreach (String* s, *dirs)
	{
		String* full_path = s->clone ();
		full_path->append("/");
		full_path->append(*filename);
	
		if(!stat(full_path->c_str(), &buf))
		{
			return full_path;
		}
	}

	// Otherwise, search dirs (with backslashes instead of forward slashes)
	foreach (String* s, *dirs)
	{
		String* full_path = s->clone ();
		full_path->append("/");
		full_path->append(*filename);

		String::iterator j;
		foreach (char & c, *full_path)
			if(c == '/') c = '\\';

		if(!stat(full_path->c_str(), &buf))
		{
			return full_path;
		}
	}
	
	// If file could not be found, return NULL
	return NULL;
}

void run_standard_transforms(PHP_script* php_script)
{
	// Remove temporaries generated by the parser for the purpose
	// of building the AST. It doesn't really matter when this 
	// transform runs, as long as it runs before XML serialisation
	Remove_parser_temporaries rpt;
	php_script->visit(&rpt);


	// There are a number of strange rules based on the value of an
	// integer/real, which must be applied. The parser cannot do this,
	// since we have to determine whether there are 1 or more - signs
	// before the number, and this is unknown at compile time. This
	// should be run early.
	Token_conversion tc;
	php_script->transform_children(&tc);
}