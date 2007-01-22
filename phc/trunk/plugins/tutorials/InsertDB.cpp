#include "generated/Tree_visitor.h"

class InsertDB : public Tree_visitor
{
private:
   int uses_dbx;
   
public:
   void pre_method(AST_method* in)
   {
      uses_dbx = false;   
   }

   void post_method(AST_method* in)
   {
      if(uses_dbx)
         in->signature->method_name->value->append("_DB");
   }

   void post_method_invocation(AST_method_invocation* in)
   {
      Token_method_name* pattern = new Token_method_name(WILDCARD);
      
      // Check for dbx_
      if(in->method_name->match(pattern) && 
         pattern->value->find("dbx_") == 0)
      {
         uses_dbx = true;
      }
   }
};

extern "C" void process_ast(AST_php_script* php_script)
{
	InsertDB idb;
	php_script->visit(&idb);
}
