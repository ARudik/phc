/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.1
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name */
#define CMDLINE_PARSER_PACKAGE PACKAGE
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION VERSION
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *full_help_help; /**< @brief Print help, including hidden options, and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  int verbose_flag;	/**< @brief Verbose output (default=off).  */
  const char *verbose_help; /**< @brief Verbose output help description.  */
  int compile_flag;	/**< @brief Compile (default=off).  */
  const char *compile_help; /**< @brief Compile help description.  */
  int pretty_print_flag;	/**< @brief Pretty print input according to the Zend style guidelines (default=off).  */
  const char *pretty_print_help; /**< @brief Pretty print input according to the Zend style guidelines help description.  */
  int obfuscate_flag;	/**< @brief Obfuscate input (default=off).  */
  const char *obfuscate_help; /**< @brief Obfuscate input help description.  */
  char ** run_arg;	/**< @brief Run the specified plugin (may be specified multiple times).  */
  char ** run_orig;	/**< @brief Run the specified plugin (may be specified multiple times) original value given at command line.  */
  unsigned int run_min; /**< @brief Run the specified plugin (may be specified multiple times)'s minimum occurreces */
  unsigned int run_max; /**< @brief Run the specified plugin (may be specified multiple times)'s maximum occurreces */
  const char *run_help; /**< @brief Run the specified plugin (may be specified multiple times) help description.  */
  char ** r_option_arg;	/**< @brief Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin).  */
  char ** r_option_orig;	/**< @brief Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin) original value given at command line.  */
  unsigned int r_option_min; /**< @brief Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin)'s minimum occurreces */
  unsigned int r_option_max; /**< @brief Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin)'s maximum occurreces */
  const char *r_option_help; /**< @brief Pass option to a plugin (specify multiple flags in the same order as multiple plugins - 1 option only per plugin) help description.  */
  char ** define_arg;	/**< @brief Define ini entry (only affects -c and --include).  */
  char ** define_orig;	/**< @brief Define ini entry (only affects -c and --include) original value given at command line.  */
  unsigned int define_min; /**< @brief Define ini entry (only affects -c and --include)'s minimum occurreces */
  unsigned int define_max; /**< @brief Define ini entry (only affects -c and --include)'s maximum occurreces */
  const char *define_help; /**< @brief Define ini entry (only affects -c and --include) help description.  */
  int no_warnings_flag;	/**< @brief Allow warnings to be printed (default=off).  */
  const char *no_warnings_help; /**< @brief Allow warnings to be printed help description.  */
  char * read_xml_arg;	/**< @brief Assume the input is in XML format. Start processing after the named pass (passes are ast|hir|mir).  */
  char * read_xml_orig;	/**< @brief Assume the input is in XML format. Start processing after the named pass (passes are ast|hir|mir) original value given at command line.  */
  const char *read_xml_help; /**< @brief Assume the input is in XML format. Start processing after the named pass (passes are ast|hir|mir) help description.  */
  int no_xml_validation_flag;	/**< @brief Toggle XML validation (default=on).  */
  const char *no_xml_validation_help; /**< @brief Toggle XML validation help description.  */
  int include_flag;	/**< @brief Parse included or required files at compile-time (default=off).  */
  const char *include_help; /**< @brief Parse included or required files at compile-time help description.  */
  char ** c_option_arg;	/**< @brief Pass option to the C compile (e.g., -C-g; can be specified multiple times).  */
  char ** c_option_orig;	/**< @brief Pass option to the C compile (e.g., -C-g; can be specified multiple times) original value given at command line.  */
  unsigned int c_option_min; /**< @brief Pass option to the C compile (e.g., -C-g; can be specified multiple times)'s minimum occurreces */
  unsigned int c_option_max; /**< @brief Pass option to the C compile (e.g., -C-g; can be specified multiple times)'s maximum occurreces */
  const char *c_option_help; /**< @brief Pass option to the C compile (e.g., -C-g; can be specified multiple times) help description.  */
  int generate_c_flag;	/**< @brief Generate C code (default=off).  */
  const char *generate_c_help; /**< @brief Generate C code help description.  */
  char * extension_arg;	/**< @brief Generate a PHP extension called EXTENSION instead of a standalone application.  */
  char * extension_orig;	/**< @brief Generate a PHP extension called EXTENSION instead of a standalone application original value given at command line.  */
  const char *extension_help; /**< @brief Generate a PHP extension called EXTENSION instead of a standalone application help description.  */
  char * web_app_arg;	/**< @brief Generate a web-application (experimental).  */
  char * web_app_orig;	/**< @brief Generate a web-application (experimental) original value given at command line.  */
  const char *web_app_help; /**< @brief Generate a web-application (experimental) help description.  */
  char * with_php_arg;	/**< @brief PHP installation path.  */
  char * with_php_orig;	/**< @brief PHP installation path original value given at command line.  */
  const char *with_php_help; /**< @brief PHP installation path help description.  */
  char * optimize_arg;	/**< @brief Optimize (default='0').  */
  char * optimize_orig;	/**< @brief Optimize original value given at command line.  */
  const char *optimize_help; /**< @brief Optimize help description.  */
  char * output_arg;	/**< @brief Place executable into file FILE.  */
  char * output_orig;	/**< @brief Place executable into file FILE original value given at command line.  */
  const char *output_help; /**< @brief Place executable into file FILE help description.  */
  int execute_flag;	/**< @brief Run executable after compiling (implies -c) (default=off).  */
  const char *execute_help; /**< @brief Run executable after compiling (implies -c) help description.  */
  int next_line_curlies_flag;	/**< @brief Output the opening curly on the next line instead of on the same line (default=off).  */
  const char *next_line_curlies_help; /**< @brief Output the opening curly on the next line instead of on the same line help description.  */
  int no_leading_tab_flag;	/**< @brief Don't start every line in between <?php .. ?> with a tab (default=off).  */
  const char *no_leading_tab_help; /**< @brief Don't start every line in between <?php .. ?> with a tab help description.  */
  char * tab_arg;	/**< @brief String to use for tabs while unparsing (default='\t').  */
  char * tab_orig;	/**< @brief String to use for tabs while unparsing original value given at command line.  */
  const char *tab_help; /**< @brief String to use for tabs while unparsing help description.  */
  int no_hash_bang_flag;	/**< @brief Do not output any #! lines (default=off).  */
  const char *no_hash_bang_help; /**< @brief Do not output any #! lines help description.  */
  char ** dump_arg;	/**< @brief Dump input as PHP (although potentially with gotos and labels) after PASSNAME.  */
  char ** dump_orig;	/**< @brief Dump input as PHP (although potentially with gotos and labels) after PASSNAME original value given at command line.  */
  unsigned int dump_min; /**< @brief Dump input as PHP (although potentially with gotos and labels) after PASSNAME's minimum occurreces */
  unsigned int dump_max; /**< @brief Dump input as PHP (although potentially with gotos and labels) after PASSNAME's maximum occurreces */
  const char *dump_help; /**< @brief Dump input as PHP (although potentially with gotos and labels) after PASSNAME help description.  */
  char ** dump_xml_arg;	/**< @brief Dump input as XML after PASSNAME.  */
  char ** dump_xml_orig;	/**< @brief Dump input as XML after PASSNAME original value given at command line.  */
  unsigned int dump_xml_min; /**< @brief Dump input as XML after PASSNAME's minimum occurreces */
  unsigned int dump_xml_max; /**< @brief Dump input as XML after PASSNAME's maximum occurreces */
  const char *dump_xml_help; /**< @brief Dump input as XML after PASSNAME help description.  */
  char ** dump_dot_arg;	/**< @brief Dump input as DOT after PASSNAME.  */
  char ** dump_dot_orig;	/**< @brief Dump input as DOT after PASSNAME original value given at command line.  */
  unsigned int dump_dot_min; /**< @brief Dump input as DOT after PASSNAME's minimum occurreces */
  unsigned int dump_dot_max; /**< @brief Dump input as DOT after PASSNAME's maximum occurreces */
  const char *dump_dot_help; /**< @brief Dump input as DOT after PASSNAME help description.  */
  int dump_parse_tree_flag;	/**< @brief Dump parse tree as DOT (default=off).  */
  const char *dump_parse_tree_help; /**< @brief Dump parse tree as DOT help description.  */
  int dump_tokens_flag;	/**< @brief Dump list of tokens from the lexer (default=off).  */
  const char *dump_tokens_help; /**< @brief Dump list of tokens from the lexer help description.  */
  int list_passes_flag;	/**< @brief List of available passes (for PASSNAME) (default=off).  */
  const char *list_passes_help; /**< @brief List of available passes (for PASSNAME) help description.  */
  int convert_uppered_flag;	/**< @brief Use legal PHP when dumping MIR as PHP (default=off).  */
  const char *convert_uppered_help; /**< @brief Use legal PHP when dumping MIR as PHP help description.  */
  int no_dot_line_numbers_flag;	/**< @brief Don't show line numbers when dumping DOT/XML (default=off).  */
  const char *no_dot_line_numbers_help; /**< @brief Don't show line numbers when dumping DOT/XML help description.  */
  int no_dot_nulls_flag;	/**< @brief Don't show NULLs when dumping DOT (default=off).  */
  const char *no_dot_nulls_help; /**< @brief Don't show NULLs when dumping DOT help description.  */
  int no_dot_empty_lists_flag;	/**< @brief Don't show empty lists when dumping DOT (default=off).  */
  const char *no_dot_empty_lists_help; /**< @brief Don't show empty lists when dumping DOT help description.  */
  int no_xml_line_numbers_flag;	/**< @brief Don't show line numbers when dumping DOT (default=off).  */
  const char *no_xml_line_numbers_help; /**< @brief Don't show line numbers when dumping DOT help description.  */
  int no_xml_base_64_flag;	/**< @brief Don't encode any strings into base64 when dumping XML (default=off).  */
  const char *no_xml_base_64_help; /**< @brief Don't encode any strings into base64 when dumping XML help description.  */
  int no_xml_attrs_flag;	/**< @brief When dumping XML, omit node attributes (default=off).  */
  const char *no_xml_attrs_help; /**< @brief When dumping XML, omit node attributes help description.  */
  char ** stats_arg;	/**< @brief Print statistics for the pass named 'PASSNAME.  */
  char ** stats_orig;	/**< @brief Print statistics for the pass named 'PASSNAME original value given at command line.  */
  unsigned int stats_min; /**< @brief Print statistics for the pass named 'PASSNAME's minimum occurreces */
  unsigned int stats_max; /**< @brief Print statistics for the pass named 'PASSNAME's maximum occurreces */
  const char *stats_help; /**< @brief Print statistics for the pass named 'PASSNAME help description.  */
  int rt_stats_flag;	/**< @brief Print statistics about a program at run-time (default=off).  */
  const char *rt_stats_help; /**< @brief Print statistics about a program at run-time help description.  */
  char ** cfg_dump_arg;	/**< @brief Dump CFG after the pass named 'PASSNAME'.  */
  char ** cfg_dump_orig;	/**< @brief Dump CFG after the pass named 'PASSNAME' original value given at command line.  */
  unsigned int cfg_dump_min; /**< @brief Dump CFG after the pass named 'PASSNAME''s minimum occurreces */
  unsigned int cfg_dump_max; /**< @brief Dump CFG after the pass named 'PASSNAME''s maximum occurreces */
  const char *cfg_dump_help; /**< @brief Dump CFG after the pass named 'PASSNAME' help description.  */
  char ** debug_arg;	/**< @brief Print debugging information for the pass named 'PASSNAME.  */
  char ** debug_orig;	/**< @brief Print debugging information for the pass named 'PASSNAME original value given at command line.  */
  unsigned int debug_min; /**< @brief Print debugging information for the pass named 'PASSNAME's minimum occurreces */
  unsigned int debug_max; /**< @brief Print debugging information for the pass named 'PASSNAME's maximum occurreces */
  const char *debug_help; /**< @brief Print debugging information for the pass named 'PASSNAME help description.  */
  int dont_fail_flag;	/**< @brief Dont fail on error (after parsing) (default=off).  */
  const char *dont_fail_help; /**< @brief Dont fail on error (after parsing) help description.  */
  int missed_opt_flag;	/**< @brief Give a warning when an optimization was missed (default=on).  */
  const char *missed_opt_help; /**< @brief Give a warning when an optimization was missed help description.  */
  char ** disable_arg;	/**< @brief Disable the pass named 'PASSNAME'.  */
  char ** disable_orig;	/**< @brief Disable the pass named 'PASSNAME' original value given at command line.  */
  unsigned int disable_min; /**< @brief Disable the pass named 'PASSNAME''s minimum occurreces */
  unsigned int disable_max; /**< @brief Disable the pass named 'PASSNAME''s maximum occurreces */
  const char *disable_help; /**< @brief Disable the pass named 'PASSNAME' help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int full_help_given ;	/**< @brief Whether full-help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int verbose_given ;	/**< @brief Whether verbose was given.  */
  unsigned int compile_given ;	/**< @brief Whether compile was given.  */
  unsigned int pretty_print_given ;	/**< @brief Whether pretty-print was given.  */
  unsigned int obfuscate_given ;	/**< @brief Whether obfuscate was given.  */
  unsigned int run_given ;	/**< @brief Whether run was given.  */
  unsigned int r_option_given ;	/**< @brief Whether r-option was given.  */
  unsigned int define_given ;	/**< @brief Whether define was given.  */
  unsigned int no_warnings_given ;	/**< @brief Whether no-warnings was given.  */
  unsigned int read_xml_given ;	/**< @brief Whether read-xml was given.  */
  unsigned int no_xml_validation_given ;	/**< @brief Whether no-xml-validation was given.  */
  unsigned int include_given ;	/**< @brief Whether include was given.  */
  unsigned int c_option_given ;	/**< @brief Whether c-option was given.  */
  unsigned int generate_c_given ;	/**< @brief Whether generate-c was given.  */
  unsigned int extension_given ;	/**< @brief Whether extension was given.  */
  unsigned int web_app_given ;	/**< @brief Whether web-app was given.  */
  unsigned int with_php_given ;	/**< @brief Whether with-php was given.  */
  unsigned int optimize_given ;	/**< @brief Whether optimize was given.  */
  unsigned int output_given ;	/**< @brief Whether output was given.  */
  unsigned int execute_given ;	/**< @brief Whether execute was given.  */
  unsigned int next_line_curlies_given ;	/**< @brief Whether next-line-curlies was given.  */
  unsigned int no_leading_tab_given ;	/**< @brief Whether no-leading-tab was given.  */
  unsigned int tab_given ;	/**< @brief Whether tab was given.  */
  unsigned int no_hash_bang_given ;	/**< @brief Whether no-hash-bang was given.  */
  unsigned int dump_given ;	/**< @brief Whether dump was given.  */
  unsigned int dump_xml_given ;	/**< @brief Whether dump-xml was given.  */
  unsigned int dump_dot_given ;	/**< @brief Whether dump-dot was given.  */
  unsigned int dump_parse_tree_given ;	/**< @brief Whether dump-parse-tree was given.  */
  unsigned int dump_tokens_given ;	/**< @brief Whether dump-tokens was given.  */
  unsigned int list_passes_given ;	/**< @brief Whether list-passes was given.  */
  unsigned int convert_uppered_given ;	/**< @brief Whether convert-uppered was given.  */
  unsigned int no_dot_line_numbers_given ;	/**< @brief Whether no-dot-line-numbers was given.  */
  unsigned int no_dot_nulls_given ;	/**< @brief Whether no-dot-nulls was given.  */
  unsigned int no_dot_empty_lists_given ;	/**< @brief Whether no-dot-empty-lists was given.  */
  unsigned int no_xml_line_numbers_given ;	/**< @brief Whether no-xml-line-numbers was given.  */
  unsigned int no_xml_base_64_given ;	/**< @brief Whether no-xml-base-64 was given.  */
  unsigned int no_xml_attrs_given ;	/**< @brief Whether no-xml-attrs was given.  */
  unsigned int stats_given ;	/**< @brief Whether stats was given.  */
  unsigned int rt_stats_given ;	/**< @brief Whether rt-stats was given.  */
  unsigned int cfg_dump_given ;	/**< @brief Whether cfg-dump was given.  */
  unsigned int debug_given ;	/**< @brief Whether debug was given.  */
  unsigned int dont_fail_given ;	/**< @brief Whether dont-fail was given.  */
  unsigned int missed_opt_given ;	/**< @brief Whether missed-opt was given.  */
  unsigned int disable_given ;	/**< @brief Whether disable was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];
/** @brief all the lines making the full help output (including hidden options) */
extern const char *gengetopt_args_info_full_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char * const *argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the full help (including hidden options)
 */
void cmdline_parser_print_full_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
