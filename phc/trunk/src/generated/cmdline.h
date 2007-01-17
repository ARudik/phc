/* cmdline.h */

/* File autogenerated by gengetopt version 2.19  */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
#define CMDLINE_PARSER_PACKAGE PACKAGE
#endif

#ifndef CMDLINE_PARSER_VERSION
#define CMDLINE_PARSER_VERSION VERSION
#endif

struct gengetopt_args_info
{
  const char *help_help; /* Print help and exit help description.  */
  const char *full_help_help; /* Print help, including hidden options, and exit help description.  */
  const char *version_help; /* Print version and exit help description.  */
  int compile_flag;	/* Compile (default=off).  */
  const char *compile_help; /* Compile help description.  */
  char ** c_option_arg;	/* Pass option to the C compile (e.g., -C-g; can be specified multiple times).  */
  char ** c_option_orig;	/* Pass option to the C compile (e.g., -C-g; can be specified multiple times) original value given at command line.  */
  int c_option_min; /* Pass option to the C compile (e.g., -C-g; can be specified multiple times)'s minimum occurreces */
  int c_option_max; /* Pass option to the C compile (e.g., -C-g; can be specified multiple times)'s maximum occurreces */
  const char *c_option_help; /* Pass option to the C compile (e.g., -C-g; can be specified multiple times) help description.  */
  int generate_c_flag;	/* Generate C code (default=off).  */
  const char *generate_c_help; /* Generate C code help description.  */
  char * extension_arg;	/* Generate a PHP extension called NAME instead of a standalone application.  */
  char * extension_orig;	/* Generate a PHP extension called NAME instead of a standalone application original value given at command line.  */
  const char *extension_help; /* Generate a PHP extension called NAME instead of a standalone application help description.  */
  char * with_php_arg;	/* PHP installation path.  */
  char * with_php_orig;	/* PHP installation path original value given at command line.  */
  const char *with_php_help; /* PHP installation path help description.  */
  char ** run_arg;	/* Run the specified plugin (may be specified multiple times).  */
  char ** run_orig;	/* Run the specified plugin (may be specified multiple times) original value given at command line.  */
  int run_min; /* Run the specified plugin (may be specified multiple times)'s minimum occurreces */
  int run_max; /* Run the specified plugin (may be specified multiple times)'s maximum occurreces */
  const char *run_help; /* Run the specified plugin (may be specified multiple times) help description.  */
  int dump_tokens_flag;	/* Perform lexical analysis only (spits out a token list). Probably only useful for debugging phc itself (default=off).  */
  const char *dump_tokens_help; /* Perform lexical analysis only (spits out a token list). Probably only useful for debugging phc itself help description.  */
  int dump_php_flag;	/* Dump PHP code back immediately after parsing to standard output (pretty printing) (default=off).  */
  const char *dump_php_help; /* Dump PHP code back immediately after parsing to standard output (pretty printing) help description.  */
  int dump_ast_dot_flag;	/* Dump the AST from the source in dot format (default=off).  */
  const char *dump_ast_dot_help; /* Dump the AST from the source in dot format help description.  */
  int dump_ast_xml_flag;	/* Dump the AST from the source in XML format (default=off).  */
  const char *dump_ast_xml_help; /* Dump the AST from the source in XML format help description.  */
  int read_ast_xml_flag;	/* Assume the input is a phc AST in XML format (default=off).  */
  const char *read_ast_xml_help; /* Assume the input is a phc AST in XML format help description.  */
  int no_line_numbers_flag;	/* Don't include line numbers when dumping AST/XML (default=off).  */
  const char *no_line_numbers_help; /* Don't include line numbers when dumping AST/XML help description.  */
  int compile_time_includes_flag;	/* When possible, replace include() statements with the parsed contents of the specified file (default=off).  */
  const char *compile_time_includes_help; /* When possible, replace include() statements with the parsed contents of the specified file help description.  */
  char * tab_arg;	/* String to use for tabs while unparsing (default='\t').  */
  char * tab_orig;	/* String to use for tabs while unparsing original value given at command line.  */
  const char *tab_help; /* String to use for tabs while unparsing help description.  */
  int verbose_flag;	/* Verbose output (default=off).  */
  const char *verbose_help; /* Verbose output help description.  */
  int no_validation_flag;	/* Toggle XML validation (default=on).  */
  const char *no_validation_help; /* Toggle XML validation help description.  */
  
  int help_given ;	/* Whether help was given.  */
  int full_help_given ;	/* Whether full-help was given.  */
  int version_given ;	/* Whether version was given.  */
  int compile_given ;	/* Whether compile was given.  */
  unsigned int c_option_given ;	/* Whether c-option was given.  */
  int generate_c_given ;	/* Whether generate-c was given.  */
  int extension_given ;	/* Whether extension was given.  */
  int with_php_given ;	/* Whether with-php was given.  */
  unsigned int run_given ;	/* Whether run was given.  */
  int dump_tokens_given ;	/* Whether dump-tokens was given.  */
  int dump_php_given ;	/* Whether dump-php was given.  */
  int dump_ast_dot_given ;	/* Whether dump-ast-dot was given.  */
  int dump_ast_xml_given ;	/* Whether dump-ast-xml was given.  */
  int read_ast_xml_given ;	/* Whether read-ast-xml was given.  */
  int no_line_numbers_given ;	/* Whether no-line-numbers was given.  */
  int compile_time_includes_given ;	/* Whether compile-time-includes was given.  */
  int tab_given ;	/* Whether tab was given.  */
  int verbose_given ;	/* Whether verbose was given.  */
  int no_validation_given ;	/* Whether no-validation was given.  */

  char **inputs ; /* unamed options */
  unsigned inputs_num ; /* unamed options number */
} ;

extern const char *gengetopt_args_info_purpose;
extern const char *gengetopt_args_info_usage;
extern const char *gengetopt_args_info_help[];
extern const char *gengetopt_args_info_full_help[];

int cmdline_parser (int argc, char * const *argv,
  struct gengetopt_args_info *args_info);
int cmdline_parser2 (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

void cmdline_parser_print_help(void);
void cmdline_parser_print_full_help(void);
void cmdline_parser_print_version(void);

void cmdline_parser_init (struct gengetopt_args_info *args_info);
void cmdline_parser_free (struct gengetopt_args_info *args_info);

int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
