#include <phc/Tree_visitor.h>

class Count_statements : public Tree_visitor
{
private:
   int num_statements;

public:
   // Set num_statements to zero before we begin
   void pre_php_script(AST_php_script* in)
   {
      num_statements = 0;
   }

   // Print the number of function calls when we are done
   void post_php_script(AST_php_script* in)
   {
      printf("%d statements found\n", num_statements);
   }
   
   // Count the number of function calls
   void post_statement(AST_statement* in)
   {
      num_statements++;
   }
};

extern "C" void process_ast(AST_php_script* php_script)
{
	Count_statements cfc;
	php_script->visit(&cfc);
}
