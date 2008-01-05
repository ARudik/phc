/* cmdline.h */

/* File autogenerated by gengetopt version 2.19.1  */

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
  int verbose_flag;	/* Verbose output (default=off).  */
  const char *verbose_help; /* Verbose output help description.  */
  int compile_flag;	/* Compile (default=off).  */
  const char *compile_help; /* Compile help description.  */
  int pretty_print_flag;	/* Pretty print input according to the Zend style guidelines (default=off).  */
  const char *pretty_print_help; /* Pretty print input according to the Zend style guidelines help description.  */
  int obfuscate_flag;	/* Obfuscate input (default=off).  */
  const char *obfuscate_help; /* Obfuscate input help description.  */
  char ** run_arg;	/* Run the specified plugin (may be specified multiple times).  */
  char ** run_orig;	/* Run the specified plugin (may be specified multiple times) original value given at command line.  */
  int run_min; /* Run the specified plugin (may be specified multiple times)'s minimum occurreces */
  int run_max; /* Run the specified plugin (may be specified multiple times)'s maximum occurreces */
  const char *run_help; /* Run the specified plugin (may be specified multiple times) help description.  */
  char ** r_option_arg;	/* Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin).  */
  char ** r_option_orig;	/* Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin) original value given at command line.  */
  int r_option_min; /* Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin)'s minimum occurreces */
  int r_option_max; /* Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin)'s maximum occurreces */
  const char *r_option_help; /* Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin) help description.  */
  char * read_xml_arg;	/* Assume the input is in XML format. Start processing after the named pass.  */
  char * read_xml_orig;	/* Assume the input is in XML format. Start processing after the named pass original value given at command line.  */
  const char *read_xml_help; /* Assume the input is in XML format. Start processing after the named pass help description.  */
  int no_validation_flag;	/* Toggle XML validation (default=on).  */
  const char *no_validation_help; /* Toggle XML validation help description.  */
  int include_flag;	/* Parse included or required files at compile-time (default=off).  */
  const char *include_help; /* Parse included or required files at compile-time help description.  */
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
  char * optimize_arg;	/* Optimize (default='0').  */
  char * optimize_orig;	/* Optimize original value given at command line.  */
  const char *optimize_help; /* Optimize help description.  */
  char * output_arg;	/* Place executable into file FILE.  */
  char * output_orig;	/* Place executable into file FILE original value given at command line.  */
  const char *output_help; /* Place executable into file FILE help description.  */
  int next_line_curlies_flag;	/* Output the opening curly on the next line instead of on the same line (default=off).  */
  const char *next_line_curlies_help; /* Output the opening curly on the next line instead of on the same line help description.  */
  int no_leading_tab_flag;	/* Don't start every line in between <?php .. ?> with a tab (default=off).  */
  const char *no_leading_tab_help; /* Don't start every line in between <?php .. ?> with a tab help description.  */
  int no_line_numbers_flag;	/* Don't show line numbers when dumping DOT/XML (default=off).  */
  const char *no_line_numbers_help; /* Don't show line numbers when dumping DOT/XML help description.  */
  int no_nulls_flag;	/* Don't show NULLs when dumping DOT (default=off).  */
  const char *no_nulls_help; /* Don't show NULLs when dumping DOT help description.  */
  int no_empty_lists_flag;	/* Don't show empty lists when dumping DOT (default=off).  */
  const char *no_empty_lists_help; /* Don't show empty lists when dumping DOT help description.  */
  char * tab_arg;	/* String to use for tabs while unparsing (default='\t').  */
  char * tab_orig;	/* String to use for tabs while unparsing original value given at command line.  */
  const char *tab_help; /* String to use for tabs while unparsing help description.  */
  int no_hash_bang_flag;	/* Do not output any #! lines (default=off).  */
  const char *no_hash_bang_help; /* Do not output any #! lines help description.  */
  char ** dump_arg;	/* Dump input as PHP (although potentially with gotos and labels) after the pass named 'passname'.  */
  char ** dump_orig;	/* Dump input as PHP (although potentially with gotos and labels) after the pass named 'passname' original value given at command line.  */
  int dump_min; /* Dump input as PHP (although potentially with gotos and labels) after the pass named 'passname''s minimum occurreces */
  int dump_max; /* Dump input as PHP (although potentially with gotos and labels) after the pass named 'passname''s maximum occurreces */
  const char *dump_help; /* Dump input as PHP (although potentially with gotos and labels) after the pass named 'passname' help description.  */
  char ** udump_arg;	/* Dump input as runnable PHP after the pass named 'passname'.  */
  char ** udump_orig;	/* Dump input as runnable PHP after the pass named 'passname' original value given at command line.  */
  int udump_min; /* Dump input as runnable PHP after the pass named 'passname''s minimum occurreces */
  int udump_max; /* Dump input as runnable PHP after the pass named 'passname''s maximum occurreces */
  const char *udump_help; /* Dump input as runnable PHP after the pass named 'passname' help description.  */
  char ** ddump_arg;	/* Dump input as DOT after the pass named 'passname'.  */
  char ** ddump_orig;	/* Dump input as DOT after the pass named 'passname' original value given at command line.  */
  int ddump_min; /* Dump input as DOT after the pass named 'passname''s minimum occurreces */
  int ddump_max; /* Dump input as DOT after the pass named 'passname''s maximum occurreces */
  const char *ddump_help; /* Dump input as DOT after the pass named 'passname' help description.  */
  char ** xdump_arg;	/* Dump input as XML after the pass named 'passname'.  */
  char ** xdump_orig;	/* Dump input as XML after the pass named 'passname' original value given at command line.  */
  int xdump_min; /* Dump input as XML after the pass named 'passname''s minimum occurreces */
  int xdump_max; /* Dump input as XML after the pass named 'passname''s maximum occurreces */
  const char *xdump_help; /* Dump input as XML after the pass named 'passname' help description.  */
  int list_passes_flag;	/* List the passes to be run (default=off).  */
  const char *list_passes_help; /* List the passes to be run help description.  */
  int dont_fail_flag;	/* Dont fail on error (after parsing) (default=off).  */
  const char *dont_fail_help; /* Dont fail on error (after parsing) help description.  */
  
  int help_given ;	/* Whether help was given.  */
  int full_help_given ;	/* Whether full-help was given.  */
  int version_given ;	/* Whether version was given.  */
  int verbose_given ;	/* Whether verbose was given.  */
  int compile_given ;	/* Whether compile was given.  */
  int pretty_print_given ;	/* Whether pretty-print was given.  */
  int obfuscate_given ;	/* Whether obfuscate was given.  */
  unsigned int run_given ;	/* Whether run was given.  */
  unsigned int r_option_given ;	/* Whether r-option was given.  */
  int read_xml_given ;	/* Whether read-xml was given.  */
  int no_validation_given ;	/* Whether no-validation was given.  */
  int include_given ;	/* Whether include was given.  */
  unsigned int c_option_given ;	/* Whether c-option was given.  */
  int generate_c_given ;	/* Whether generate-c was given.  */
  int extension_given ;	/* Whether extension was given.  */
  int with_php_given ;	/* Whether with-php was given.  */
  int optimize_given ;	/* Whether optimize was given.  */
  int output_given ;	/* Whether output was given.  */
  int next_line_curlies_given ;	/* Whether next-line-curlies was given.  */
  int no_leading_tab_given ;	/* Whether no-leading-tab was given.  */
  int no_line_numbers_given ;	/* Whether no-line-numbers was given.  */
  int no_nulls_given ;	/* Whether no-nulls was given.  */
  int no_empty_lists_given ;	/* Whether no-empty-lists was given.  */
  int tab_given ;	/* Whether tab was given.  */
  int no_hash_bang_given ;	/* Whether no-hash-bang was given.  */
  unsigned int dump_given ;	/* Whether dump was given.  */
  unsigned int udump_given ;	/* Whether udump was given.  */
  unsigned int ddump_given ;	/* Whether ddump was given.  */
  unsigned int xdump_given ;	/* Whether xdump was given.  */
  int list_passes_given ;	/* Whether list-passes was given.  */
  int dont_fail_given ;	/* Whether dont-fail was given.  */

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
