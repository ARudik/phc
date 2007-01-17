/*
 * phc -- the open source PHP compiler
 * Convert the phc AST to XML format
 */

#include <iostream>
#include "XML_unparser.h"
#include <phc/lib/base64.h>
#include <phc/lib/demangle.h>
#include "generated/cmdline.h"

using namespace std;

extern struct gengetopt_args_info args_info;

void XML_unparser::print_indent()
{
	for(int i = 0; i < indent; i++)
		os << args_info.tab_arg;
}

bool XML_unparser::needs_encoding(String* str)
{
	String::const_iterator i;
	
	for(i = str->begin(); i != str->end(); i++)
	{
		if(*i < 32)
			return true;

		if(*i > 126)
			return true;

		if(*i == '<' || *i == '>' || *i == '&')
			return true;
	}

	return false;
}

XML_unparser::XML_unparser(ostream& os) : os(os) 
{
	indent = 0;
}

XML_unparser::~XML_unparser() 
{
}

void XML_unparser::pre_node(AST_node* in)
{
	bool is_root = dynamic_cast<AST_php_script*>(in);
	
	if(is_root)
		os << "<?xml version=\"1.0\"?>" << endl;

	print_indent();
	os << "<" << demangle(in);
	
	if(is_root)
	{
		os << " xmlns=\"http://www.phpcompiler.org/phc-1.0\"";
		os << " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
	}

	os << ">" << endl;
	indent++;

	if(in->attrs->size() == 0)
	{
		print_indent();
		os << "<attrs />" << endl;
	}
	else
	{
		print_indent();
		os << "<attrs>" << endl;
		indent++;

		AttrMap::const_iterator i;
		for(i = in->attrs->begin(); i != in->attrs->end(); i++)
		{
			if((*i).first == "phc.line_number")
			{
				print_indent();
				os << "<attr key=\"phc.line_number\">" << in->get_line_number() << "</attr>" << endl;
			}
			else if((*i).first == "phc.filename")
			{
				print_indent();
				os << "<attr key=\"phc.filename\">" << *in->get_filename() << "</attr>" << endl;
			}
			else if((*i).first == "phc.comments")
			{
				print_indent();
				os << "<attr key=\"phc.comments\">" << endl;
				indent++;
				
				List<String*>::const_iterator j;
				List<String*>* comments = dynamic_cast<List<String*>*>((*i).second);
				for(j = comments->begin(); j != comments->end(); j++)
				{
					print_indent();
					os << "<comment";
					
					if(needs_encoding(*j))
					{
						os << " encoding=\"base64\">";
						os << *base64_encode(*j);
					}
					else	
					{
						os << ">";
						os << **j;
					}

					os << "</comment>" << endl;
				}
				
				indent--;
				print_indent();
				os << "</attr>" << endl;
			}
			else if((*i).first == "phc.unparser.is_elseif")
			{
				print_indent();
				bool is_elseif = dynamic_cast<Boolean*>((*i).second)->value();
				os << "<attr key=\"phc.unparser.is_elseif\">" << (is_elseif ? "true" : "false") << "</attr>" << endl;
			}
			else if((*i).first == "phc.unparser.needs_brackets")
			{
				print_indent();
				bool needs_brackets = dynamic_cast<Boolean*>((*i).second)->value();
				os << "<attr key=\"phc.unparser.needs_brackets\">" << (needs_brackets ? "true" : "false") << "</attr>" << endl;
			}
			else if((*i).first == "phc.unparser.is_global_stmt")
			{
				print_indent();
				bool is_global_stmt = dynamic_cast<Boolean*>((*i).second)->value();
				os << "<attr key=\"phc.unparser.is_global_stmt\">" << (is_global_stmt ? "true" : "false") << "</attr>" << endl;
			}
			else
			{
				phc_warning(WARNING_UNKNOWN_ATTRIBUTE, NULL, 0, (*i).first.c_str());	
			}
		}

		indent--;
		print_indent();
		os << "</attrs>" << endl;
	}
}

void XML_unparser::post_node(AST_node* in)
{
	indent--;
	print_indent();
	os << "</" << demangle(in) << ">" << endl;
}

void XML_unparser::pre_identifier(AST_identifier* in)
{
	String* value = in->get_value_as_string();

	print_indent();
	if(needs_encoding(value))
		os << "<value encoding=\"base64\">" << *base64_encode(value) << "</value>" << endl;
	else
		os << "<value>" << *value << "</value>" << endl;;

}

void XML_unparser::pre_literal(AST_literal* in)
{
	String* value = in->get_value_as_string();
	String* source_rep = in->get_source_rep();

	// Token_null does not have a value
	if(!dynamic_cast<Token_null*>(in))
	{
		print_indent();
		if(needs_encoding(value))
			os << "<value encoding=\"base64\">" << *base64_encode(value) << "</value>" << endl;
		else	
			os << "<value>" << *value << "</value>" << endl;
	}

	print_indent();
	if(needs_encoding(source_rep))
		os << "<source_rep encoding=\"base64\">" << *base64_encode(source_rep) << "</source_rep>" << endl;
	else	
		os << "<source_rep>" << *source_rep << "</source_rep>" << endl;
}

void XML_unparser::visit_null(char* type_id)
{
	print_indent();
	os << "<" << type_id << " xsi:nil=\"true\" />" << endl;
}

void XML_unparser::visit_marker(char* name, bool value)
{
	print_indent();
	os << "<bool>" << (value ? "true" : "false") << "</bool>" << endl;
}
