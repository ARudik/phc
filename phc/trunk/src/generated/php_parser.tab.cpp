/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse PHP_parse
#define yylex   PHP_lex
#define yyerror PHP_error
#define yylval  PHP_lval
#define yychar  PHP_char
#define yydebug PHP_debug
#define yynerrs PHP_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     K_AND = 258,
     K_OR = 259,
     K_XOR = 260,
     K___FILE__ = 261,
     K_EXCEPTION = 262,
     K___LINE__ = 263,
     K_ARRAY = 264,
     K_AS = 265,
     K_BREAK = 266,
     K_CASE = 267,
     K_CLASS = 268,
     K_CONST = 269,
     K_CONTINUE = 270,
     K_DECLARE = 271,
     K_DEFAULT = 272,
     K_DIE = 273,
     K_DO = 274,
     K_ECHO = 275,
     K_ELSE = 276,
     K_ELSEIF = 277,
     K_EMPTY = 278,
     K_ENDDECLARE = 279,
     K_ENDFOR = 280,
     K_ENDFOREACH = 281,
     K_ENDIF = 282,
     K_ENDSWITCH = 283,
     K_ENDWHILE = 284,
     K_EVAL = 285,
     K_EXIT = 286,
     K_EXTENDS = 287,
     K_FOR = 288,
     K_FOREACH = 289,
     K_FUNCTION = 290,
     K_GLOBAL = 291,
     K_IF = 292,
     K_INCLUDE = 293,
     K_INCLUDE_ONCE = 294,
     K_INSTANCEOF = 295,
     K_ISSET = 296,
     K_LIST = 297,
     K_NEW = 298,
     K_PRINT = 299,
     K_REQUIRE = 300,
     K_REQUIRE_ONCE = 301,
     K_RETURN = 302,
     K_STATIC = 303,
     K_SWITCH = 304,
     K_UNSET = 305,
     K_USE = 306,
     K_VAR = 307,
     K_WHILE = 308,
     K___FUNCTION__ = 309,
     K___CLASS__ = 310,
     K___METHOD__ = 311,
     K_FINAL = 312,
     K_PHP_USER_FILTER = 313,
     K_INTERFACE = 314,
     K_IMPLEMENTS = 315,
     K_PUBLIC = 316,
     K_PRIVATE = 317,
     K_PROTECTED = 318,
     K_ABSTRACT = 319,
     K_CLONE = 320,
     K_TRY = 321,
     K_CATCH = 322,
     K_THROW = 323,
     K_CFUNCTION = 324,
     K_OLD_FUNCTION = 325,
     K_HALT_COMPILER = 326,
     C_TRUE = 327,
     C_FALSE = 328,
     C_NULL = 329,
     O_EQEQ = 330,
     O_EQEQEQ = 331,
     O_NOTEQ = 332,
     O_NOTEQEQ = 333,
     O_LE = 334,
     O_GE = 335,
     O_INC = 336,
     O_DEC = 337,
     O_DOUBLEARROW = 338,
     O_SINGLEARROW = 339,
     O_SL = 340,
     O_SR = 341,
     O_COLONCOLON = 342,
     O_LOGICOR = 343,
     O_LOGICAND = 344,
     O_PLUSEQ = 345,
     O_MINUSEQ = 346,
     O_MULEQ = 347,
     O_DIVEQ = 348,
     O_CONCATEQ = 349,
     O_MODEQ = 350,
     O_ANDEQ = 351,
     O_OREQ = 352,
     O_XOREQ = 353,
     O_SLEQ = 354,
     O_SREQ = 355,
     O_MAGIC_CONCAT = 356,
     CAST_INT = 357,
     CAST_REAL = 358,
     CAST_STRING = 359,
     CAST_ARRAY = 360,
     CAST_OBJECT = 361,
     CAST_BOOL = 362,
     CAST_UNSET = 363,
     STRING = 364,
     IDENT = 365,
     VARIABLE = 366,
     INT = 367,
     REAL = 368,
     INLINE_HTML = 369,
     INVALID_TOKEN = 370
   };
#endif
/* Tokens.  */
#define K_AND 258
#define K_OR 259
#define K_XOR 260
#define K___FILE__ 261
#define K_EXCEPTION 262
#define K___LINE__ 263
#define K_ARRAY 264
#define K_AS 265
#define K_BREAK 266
#define K_CASE 267
#define K_CLASS 268
#define K_CONST 269
#define K_CONTINUE 270
#define K_DECLARE 271
#define K_DEFAULT 272
#define K_DIE 273
#define K_DO 274
#define K_ECHO 275
#define K_ELSE 276
#define K_ELSEIF 277
#define K_EMPTY 278
#define K_ENDDECLARE 279
#define K_ENDFOR 280
#define K_ENDFOREACH 281
#define K_ENDIF 282
#define K_ENDSWITCH 283
#define K_ENDWHILE 284
#define K_EVAL 285
#define K_EXIT 286
#define K_EXTENDS 287
#define K_FOR 288
#define K_FOREACH 289
#define K_FUNCTION 290
#define K_GLOBAL 291
#define K_IF 292
#define K_INCLUDE 293
#define K_INCLUDE_ONCE 294
#define K_INSTANCEOF 295
#define K_ISSET 296
#define K_LIST 297
#define K_NEW 298
#define K_PRINT 299
#define K_REQUIRE 300
#define K_REQUIRE_ONCE 301
#define K_RETURN 302
#define K_STATIC 303
#define K_SWITCH 304
#define K_UNSET 305
#define K_USE 306
#define K_VAR 307
#define K_WHILE 308
#define K___FUNCTION__ 309
#define K___CLASS__ 310
#define K___METHOD__ 311
#define K_FINAL 312
#define K_PHP_USER_FILTER 313
#define K_INTERFACE 314
#define K_IMPLEMENTS 315
#define K_PUBLIC 316
#define K_PRIVATE 317
#define K_PROTECTED 318
#define K_ABSTRACT 319
#define K_CLONE 320
#define K_TRY 321
#define K_CATCH 322
#define K_THROW 323
#define K_CFUNCTION 324
#define K_OLD_FUNCTION 325
#define K_HALT_COMPILER 326
#define C_TRUE 327
#define C_FALSE 328
#define C_NULL 329
#define O_EQEQ 330
#define O_EQEQEQ 331
#define O_NOTEQ 332
#define O_NOTEQEQ 333
#define O_LE 334
#define O_GE 335
#define O_INC 336
#define O_DEC 337
#define O_DOUBLEARROW 338
#define O_SINGLEARROW 339
#define O_SL 340
#define O_SR 341
#define O_COLONCOLON 342
#define O_LOGICOR 343
#define O_LOGICAND 344
#define O_PLUSEQ 345
#define O_MINUSEQ 346
#define O_MULEQ 347
#define O_DIVEQ 348
#define O_CONCATEQ 349
#define O_MODEQ 350
#define O_ANDEQ 351
#define O_OREQ 352
#define O_XOREQ 353
#define O_SLEQ 354
#define O_SREQ 355
#define O_MAGIC_CONCAT 356
#define CAST_INT 357
#define CAST_REAL 358
#define CAST_STRING 359
#define CAST_ARRAY 360
#define CAST_OBJECT 361
#define CAST_BOOL 362
#define CAST_UNSET 363
#define STRING 364
#define IDENT 365
#define VARIABLE 366
#define INT 367
#define REAL 368
#define INLINE_HTML 369
#define INVALID_TOKEN 370




/* Copy the first part of user declarations.  */
#line 8 "src/generated_src/php_parser.ypp"

	#include <assert.h>
	#include <typeinfo>
	#include "generated/ast.h"
	#include "generated/cmdline.h"
	#include "lib/Integer.h"
	#include "lib/String.h"
	#include "lib/error.h"
	#include "parsing/PHP_context.h"

	#ifdef YYSTYPE
	#undef YYSTYPE
	#endif
	#define YYSTYPE Object*

	extern struct gengetopt_args_info args_info;

	/*
	 * We provide some macros to do conversion of synthesized attributes to
	 * typed variables. Note that NULL arguments are left unchanged.
	 *
	 * CAST_AST(dest, src, type) converts "src" to "dest" of type "type".
	 *   It asserts that the conversion is successful.
	 *
	 * CAST_STR(dest, src, type) converts "src" to "dest" of type "type",
	 *   where type must be a Token type. It casts "src" to (String*) and then
	 *   uses the constructor of "dest" to do the conversion.
	 *
	 * CAST_UNSAFE is like ARG_CAST, but omits the assertion.
	 *
	 * CAST_STATEMENT_VECTOR(dest, src) is a specialised version of 
	 *   ARG_CAST that tries to convert "src" to "dest" of type 
	 *   AST_statement_list*. If this fails, it asserts that "src" is
	 *   of type AST_statement*, and creates a new vector and adds "src"
	 *   to this vector. If "src" is NULL, it returns an empty vector.
	 */
	
	static void assert_line_number(Object* obj)
	{
		AST_node* node = dynamic_cast<AST_node*>(obj);

		printf("Internal error: source type is %s ", typeid(*obj).name());
		
		if(node)
			printf("(source line %d)\n", node->get_line_number());
		else
			printf("(source line unknown)\n");
	}
	
	#define CAST_AST(dest, src, type) 									\
		type* dest = dynamic_cast<type*>(src);							\
		if(src && !dest) assert_line_number(src);						\
		assert(!src || dest);

	#define CAST_STR(dest, src, type) 									\
		type* dest; {															\
		String* temp = dynamic_cast<String*>(src);					\
		assert(temp != NULL);												\
		dest = new type(temp); }

	#define CAST_UNSAFE(dest, src, type) 								\
		type* dest = dynamic_cast<type*>(src);
		
	#define CAST_STATEMENT_VECTOR(dest, src) 							\
		AST_statement_list* dest; 									\
		if(!src)																	\
			dest = new AST_statement_list;							\
		else if(dynamic_cast<AST_statement*>(src)) 					\
		{ 																			\
			dest = new AST_statement_list; 							\
			dest->push_back(dynamic_cast<AST_statement*>(src));	\
		} 																			\
		else 																		\
		{ 																			\
			assert(dynamic_cast<AST_statement_list*>(src));	\
			dest = dynamic_cast<AST_statement_list*>(src); 	\
		}
	
	/*
	 * Some semantic checks
	 */

	#define EXPECT_VARIABLE(attr) \
		if(!var) \
		{ \
			AST_node* node = dynamic_cast<AST_node*>(attr); \
			phc_error(ERR_EXPECT_VAR, node->get_filename(), node->get_line_number()); \
		}

	/*
	 * Define macro to add line numbers and comments to nodes
	 */
	#define NEW(class, args)\
		dynamic_cast<class*>(copy_state(new class args, context))
	
	static AST_node* copy_state(AST_node* node, PHP_context* context)
	{
		node->attrs->set("phc.line_number", new Integer(context->source_line));
		node->attrs->set("phc.filename", context->filename->deep_clone());

		AST_commented_node* cnode;
		cnode = dynamic_cast<AST_commented_node*>(node);
		if(cnode)
		{
			List<String*>* cmnts = cnode->get_comments();
			cmnts->push_back_all(&context->last_comments);
			context->last_comments.clear();
			context->last_commented_node = cnode;
		}

		return node;
	}

	int PHP_lex(YYSTYPE* yylval, void* scanner);
	#define scanner context->scanner

	void PHP_error(PHP_context* context, const char* s)
	{
		phc_error(ERR_BISON, context->filename, context->source_line, s);
	}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 456 "src/generated/php_parser.tab.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5719

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  121
/* YYNRULES -- Number of rules. */
#define YYNRULES  356
/* YYNRULES -- Number of states. */
#define YYNSTATES  691

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   370

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   131,     2,     2,   140,   130,   122,     2,
     135,   136,   128,   125,   116,   126,   127,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   119,   137,
     123,   117,   124,   118,   133,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   141,   121,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   138,   120,   139,   132,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    20,
      23,    24,    26,    28,    30,    35,    37,    39,    41,    43,
      51,    62,    63,    70,    71,    80,    81,    92,    93,   100,
     103,   107,   110,   114,   117,   121,   125,   129,   133,   137,
     139,   142,   146,   152,   161,   170,   171,   178,   180,   181,
     182,   194,   198,   200,   201,   203,   206,   207,   215,   217,
     221,   223,   225,   229,   231,   233,   234,   236,   237,   238,
     248,   249,   258,   265,   267,   270,   273,   274,   277,   279,
     280,   283,   284,   287,   289,   293,   294,   297,   299,   302,
     304,   309,   311,   316,   318,   323,   327,   333,   337,   342,
     347,   353,   354,   355,   362,   363,   369,   371,   373,   375,
     380,   381,   382,   390,   391,   392,   401,   402,   405,   406,
     410,   412,   413,   416,   420,   426,   431,   436,   442,   450,
     457,   458,   460,   462,   464,   465,   467,   469,   472,   476,
     480,   485,   489,   491,   493,   496,   501,   505,   511,   513,
     517,   520,   521,   525,   528,   529,   530,   541,   543,   545,
     547,   549,   550,   552,   554,   557,   559,   561,   563,   565,
     567,   569,   573,   579,   581,   585,   591,   596,   600,   602,
     603,   605,   609,   611,   618,   622,   627,   634,   638,   641,
     645,   649,   653,   657,   661,   665,   669,   673,   677,   681,
     685,   688,   691,   694,   697,   701,   705,   709,   713,   717,
     721,   725,   729,   733,   738,   742,   746,   750,   754,   758,
     762,   766,   769,   772,   775,   778,   782,   786,   790,   794,
     798,   802,   806,   810,   814,   818,   824,   826,   829,   832,
     835,   838,   841,   844,   847,   850,   853,   855,   860,   863,
     868,   875,   882,   887,   889,   891,   893,   898,   900,   903,
     904,   907,   908,   911,   915,   916,   920,   922,   924,   926,
     928,   930,   932,   934,   936,   938,   940,   942,   944,   946,
     949,   952,   957,   959,   963,   965,   967,   969,   970,   973,
     974,   976,   982,   986,   990,   992,   994,   996,   998,  1000,
    1002,  1005,  1007,  1010,  1012,  1016,  1020,  1021,  1023,  1026,
    1030,  1032,  1034,  1036,  1039,  1041,  1046,  1051,  1053,  1055,
    1060,  1061,  1063,  1065,  1067,  1072,  1077,  1079,  1081,  1085,
    1087,  1090,  1094,  1096,  1098,  1103,  1104,  1105,  1108,  1114,
    1118,  1122,  1124,  1131,  1136,  1141,  1144,  1149,  1154,  1157,
    1160,  1165,  1168,  1171,  1173,  1177,  1181
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     143,     0,    -1,   144,    -1,   144,   145,    -1,    -1,   148,
      -1,   166,    -1,   167,    -1,    71,   135,   136,   137,    -1,
     146,   147,    -1,    -1,   148,    -1,   166,    -1,   167,    -1,
      71,   135,   136,   137,    -1,   151,    -1,    37,    -1,    34,
      -1,   262,    -1,   149,   135,   236,   136,   148,   192,   196,
      -1,   149,   135,   236,   136,   119,   146,   194,   197,    27,
     137,    -1,    -1,    53,   152,   135,   236,   136,   191,    -1,
      -1,    19,   153,   148,    53,   135,   236,   136,   137,    -1,
      -1,    33,   154,   135,   218,   137,   218,   137,   218,   136,
     182,    -1,    -1,    49,   155,   135,   236,   136,   186,    -1,
      11,   137,    -1,    11,   236,   137,    -1,    15,   137,    -1,
      15,   236,   137,    -1,    47,   137,    -1,    47,   220,   137,
      -1,    47,   240,   137,    -1,    36,   203,   137,    -1,    48,
     205,   137,    -1,    20,   217,   137,    -1,   114,    -1,   236,
     137,    -1,    51,   165,   137,    -1,    50,   135,   163,   136,
     137,    -1,   150,   135,   240,    10,   181,   180,   136,   183,
      -1,   150,   135,   220,    10,   238,   180,   136,   183,    -1,
      -1,    16,   156,   135,   185,   136,   184,    -1,   137,    -1,
      -1,    -1,    66,   157,   262,    67,   158,   135,   222,   111,
     136,   262,   159,    -1,    68,   236,   137,    -1,   160,    -1,
      -1,   161,    -1,   160,   161,    -1,    -1,    67,   162,   135,
     222,   111,   136,   262,    -1,   164,    -1,   163,   116,   164,
      -1,   240,    -1,   109,    -1,   135,   109,   136,    -1,   169,
      -1,   172,    -1,    -1,   122,    -1,    -1,    -1,    35,   170,
     168,   110,   171,   135,   198,   136,   262,    -1,    -1,   174,
     110,   173,   175,   178,   138,   206,   139,    -1,   176,   110,
     177,   138,   206,   139,    -1,    13,    -1,    64,    13,    -1,
      57,    13,    -1,    -1,    32,   222,    -1,    59,    -1,    -1,
      32,   179,    -1,    -1,    60,   179,    -1,   222,    -1,   179,
     116,   222,    -1,    -1,    83,   181,    -1,   238,    -1,   122,
     238,    -1,   148,    -1,   119,   146,    25,   137,    -1,   148,
      -1,   119,   146,    26,   137,    -1,   148,    -1,   119,   146,
      24,   137,    -1,   110,   117,   230,    -1,   185,   116,   110,
     117,   230,    -1,   138,   187,   139,    -1,   138,   137,   187,
     139,    -1,   119,   187,    28,   137,    -1,   119,   137,   187,
      28,   137,    -1,    -1,    -1,   187,    12,   236,   190,   188,
     146,    -1,    -1,   187,    17,   190,   189,   146,    -1,   119,
      -1,   137,    -1,   148,    -1,   119,   146,    29,   137,    -1,
      -1,    -1,   192,    22,   193,   135,   236,   136,   148,    -1,
      -1,    -1,   194,    22,   195,   135,   236,   136,   119,   146,
      -1,    -1,    21,   148,    -1,    -1,    21,   119,   146,    -1,
     199,    -1,    -1,   200,   111,    -1,   200,   122,   111,    -1,
     200,   122,   111,   117,   230,    -1,   200,   111,   117,   230,
      -1,   199,   116,   200,   111,    -1,   199,   116,   200,   122,
     111,    -1,   199,   116,   200,   122,   111,   117,   230,    -1,
     199,   116,   200,   111,   117,   230,    -1,    -1,   110,    -1,
       9,    -1,   202,    -1,    -1,   220,    -1,   240,    -1,   122,
     238,    -1,   202,   116,   220,    -1,   202,   116,   240,    -1,
     202,   116,   122,   238,    -1,   203,   116,   204,    -1,   204,
      -1,   111,    -1,   140,   237,    -1,   140,   138,   236,   139,
      -1,   205,   116,   111,    -1,   205,   116,   111,   117,   230,
      -1,   111,    -1,   111,   117,   230,    -1,   206,   207,    -1,
      -1,   211,   215,   137,    -1,   216,   137,    -1,    -1,    -1,
     212,    35,   208,   168,   110,   209,   135,   198,   136,   210,
      -1,   137,    -1,   262,    -1,   213,    -1,    52,    -1,    -1,
     213,    -1,   214,    -1,   213,   214,    -1,    61,    -1,    63,
      -1,    62,    -1,    48,    -1,    64,    -1,    57,    -1,   215,
     116,   111,    -1,   215,   116,   111,   117,   230,    -1,   111,
      -1,   111,   117,   230,    -1,   216,   116,   110,   117,   230,
      -1,    14,   110,   117,   230,    -1,   217,   116,   236,    -1,
     236,    -1,    -1,   219,    -1,   219,   116,   236,    -1,   236,
      -1,    42,   135,   255,   136,   117,   236,    -1,   240,   117,
     236,    -1,   240,   117,   122,   240,    -1,   240,   117,   122,
      43,   223,   228,    -1,    43,   223,   228,    -1,    65,   236,
      -1,   240,    90,   236,    -1,   240,    91,   236,    -1,   240,
      92,   236,    -1,   240,    93,   236,    -1,   240,    94,   236,
      -1,   240,    95,   236,    -1,   240,    96,   236,    -1,   240,
      97,   236,    -1,   240,    98,   236,    -1,   240,    99,   236,
      -1,   240,   100,   236,    -1,   239,    81,    -1,    81,   239,
      -1,   239,    82,    -1,    82,   239,    -1,   236,    88,   236,
      -1,   236,    89,   236,    -1,   236,     4,   236,    -1,   236,
       3,   236,    -1,   236,     5,   236,    -1,   236,   120,   236,
      -1,   236,   122,   236,    -1,   236,   121,   236,    -1,   236,
     127,   236,    -1,   236,   101,   236,   139,    -1,   236,   125,
     236,    -1,   236,   126,   236,    -1,   236,   128,   236,    -1,
     236,   129,   236,    -1,   236,   130,   236,    -1,   236,    85,
     236,    -1,   236,    86,   236,    -1,   125,   236,    -1,   126,
     236,    -1,   131,   236,    -1,   132,   236,    -1,   236,    76,
     236,    -1,   236,    78,   236,    -1,   236,    75,   236,    -1,
     236,    77,   236,    -1,   236,   123,   236,    -1,   236,    79,
     236,    -1,   236,   124,   236,    -1,   236,    80,   236,    -1,
     236,    40,   223,    -1,   135,   236,   136,    -1,   236,   118,
     236,   119,   236,    -1,   259,    -1,   102,   236,    -1,   103,
     236,    -1,   104,   236,    -1,   105,   236,    -1,   106,   236,
      -1,   107,   236,    -1,   108,   236,    -1,    31,   227,    -1,
     133,   236,    -1,   232,    -1,     9,   135,   257,   136,    -1,
      44,   236,    -1,   110,   135,   201,   136,    -1,   222,    87,
     110,   135,   201,   136,    -1,   222,    87,   244,   135,   201,
     136,    -1,   244,   135,   201,   136,    -1,   110,    -1,   110,
      -1,   224,    -1,   247,    84,   251,   225,    -1,   247,    -1,
     225,   226,    -1,    -1,    84,   251,    -1,    -1,   135,   136,
      -1,   135,   236,   136,    -1,    -1,   135,   201,   136,    -1,
     112,    -1,   113,    -1,   109,    -1,    73,    -1,    72,    -1,
      74,    -1,     8,    -1,     6,    -1,    55,    -1,    56,    -1,
      54,    -1,   229,    -1,   110,    -1,   125,   230,    -1,   126,
     230,    -1,     9,   135,   233,   136,    -1,   231,    -1,   110,
      87,   110,    -1,   110,    -1,   261,    -1,   229,    -1,    -1,
     235,   234,    -1,    -1,   116,    -1,   235,   116,   230,    83,
     230,    -1,   235,   116,   230,    -1,   230,    83,   230,    -1,
     230,    -1,   237,    -1,   220,    -1,   240,    -1,   240,    -1,
     240,    -1,   246,   241,    -1,   246,    -1,   241,   242,    -1,
     242,    -1,    84,   251,   243,    -1,   135,   201,   136,    -1,
      -1,   248,    -1,   254,   248,    -1,   222,    87,   244,    -1,
     247,    -1,   221,    -1,   248,    -1,   254,   248,    -1,   245,
      -1,   248,   134,   250,   141,    -1,   248,   138,   236,   139,
      -1,   249,    -1,   111,    -1,   140,   138,   236,   139,    -1,
      -1,   236,    -1,   252,    -1,   244,    -1,   252,   134,   250,
     141,    -1,   252,   138,   236,   139,    -1,   253,    -1,   110,
      -1,   138,   236,   139,    -1,   140,    -1,   254,   140,    -1,
     255,   116,   256,    -1,   256,    -1,   240,    -1,    42,   135,
     255,   136,    -1,    -1,    -1,   258,   234,    -1,   258,   116,
     236,    83,   236,    -1,   258,   116,   236,    -1,   236,    83,
     236,    -1,   236,    -1,   258,   116,   236,    83,   122,   238,
      -1,   258,   116,   122,   238,    -1,   236,    83,   122,   238,
      -1,   122,   238,    -1,    41,   135,   260,   136,    -1,    23,
     135,   240,   136,    -1,    38,   236,    -1,    39,   236,    -1,
      30,   135,   236,   136,    -1,    45,   236,    -1,    46,   236,
      -1,   240,    -1,   260,   116,   240,    -1,   222,    87,   110,
      -1,   138,   146,   139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   312,   312,   336,   359,   368,   372,   374,   376,   389,
     412,   419,   423,   425,   427,   438,   447,   456,   464,   468,
     507,   537,   537,   548,   548,   559,   559,   574,   574,   585,
     587,   593,   595,   601,   603,   609,   615,   635,   637,   639,
     647,   653,   660,   671,   702,   734,   734,   745,   747,   747,
     747,   770,   782,   785,   795,   804,   819,   819,   838,   846,
     860,   872,   877,   890,   900,   909,   910,   922,   922,   922,
     947,   947,   964,   994,   999,  1004,  1016,  1017,  1025,  1034,
    1035,  1046,  1047,  1055,  1067,  1084,  1085,  1093,  1099,  1112,
    1114,  1122,  1124,  1132,  1134,  1142,  1153,  1169,  1171,  1173,
    1175,  1184,  1185,  1185,  1199,  1199,  1218,  1220,  1228,  1234,
    1243,  1244,  1244,  1288,  1289,  1289,  1327,  1328,  1339,  1340,
    1348,  1351,  1363,  1375,  1387,  1400,  1413,  1423,  1433,  1444,
    1462,  1463,  1468,  1478,  1481,  1488,  1496,  1504,  1512,  1520,
    1528,  1542,  1550,  1565,  1570,  1575,  1587,  1597,  1608,  1618,
    1635,  1645,  1654,  1668,  1670,  1670,  1670,  1694,  1699,  1709,
    1720,  1729,  1730,  1738,  1740,  1753,  1755,  1757,  1759,  1761,
    1763,  1771,  1781,  1792,  1802,  1819,  1830,  1849,  1859,  1876,
    1877,  1886,  1893,  1901,  1908,  1916,  1924,  1933,  1940,  1946,
    1959,  1972,  1985,  1998,  2011,  2024,  2037,  2050,  2063,  2076,
    2089,  2095,  2101,  2107,  2113,  2120,  2127,  2134,  2141,  2148,
    2155,  2162,  2169,  2176,  2189,  2196,  2203,  2210,  2217,  2224,
    2231,  2238,  2243,  2249,  2255,  2261,  2268,  2275,  2282,  2289,
    2296,  2303,  2310,  2317,  2324,  2332,  2340,  2342,  2347,  2352,
    2357,  2362,  2367,  2372,  2377,  2383,  2389,  2391,  2397,  2409,
    2416,  2424,  2432,  2445,  2456,  2462,  2476,  2493,  2501,  2510,
    2520,  2531,  2532,  2534,  2543,  2548,  2556,  2561,  2566,  2571,
    2576,  2581,  2586,  2590,  2594,  2598,  2602,  2612,  2614,  2619,
    2624,  2629,  2634,  2642,  2655,  2661,  2663,  2672,  2673,  2682,
    2683,  2691,  2702,  2712,  2723,  2739,  2741,  2749,  2757,  2765,
    2789,  2824,  2835,  2844,  2877,  2921,  2924,  2931,  2933,  2951,
    2965,  2967,  2975,  2977,  2989,  2997,  3008,  3019,  3031,  3036,
    3049,  3050,  3058,  3060,  3075,  3086,  3097,  3111,  3116,  3130,
    3132,  3145,  3154,  3171,  3173,  3176,  3184,  3185,  3195,  3206,
    3216,  3227,  3237,  3249,  3260,  3272,  3289,  3296,  3301,  3306,
    3311,  3316,  3321,  3332,  3340,  3354,  3368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "K_AND", "K_OR", "K_XOR", "K___FILE__",
  "K_EXCEPTION", "K___LINE__", "K_ARRAY", "K_AS", "K_BREAK", "K_CASE",
  "K_CLASS", "K_CONST", "K_CONTINUE", "K_DECLARE", "K_DEFAULT", "K_DIE",
  "K_DO", "K_ECHO", "K_ELSE", "K_ELSEIF", "K_EMPTY", "K_ENDDECLARE",
  "K_ENDFOR", "K_ENDFOREACH", "K_ENDIF", "K_ENDSWITCH", "K_ENDWHILE",
  "K_EVAL", "K_EXIT", "K_EXTENDS", "K_FOR", "K_FOREACH", "K_FUNCTION",
  "K_GLOBAL", "K_IF", "K_INCLUDE", "K_INCLUDE_ONCE", "K_INSTANCEOF",
  "K_ISSET", "K_LIST", "K_NEW", "K_PRINT", "K_REQUIRE", "K_REQUIRE_ONCE",
  "K_RETURN", "K_STATIC", "K_SWITCH", "K_UNSET", "K_USE", "K_VAR",
  "K_WHILE", "K___FUNCTION__", "K___CLASS__", "K___METHOD__", "K_FINAL",
  "K_PHP_USER_FILTER", "K_INTERFACE", "K_IMPLEMENTS", "K_PUBLIC",
  "K_PRIVATE", "K_PROTECTED", "K_ABSTRACT", "K_CLONE", "K_TRY", "K_CATCH",
  "K_THROW", "K_CFUNCTION", "K_OLD_FUNCTION", "K_HALT_COMPILER", "C_TRUE",
  "C_FALSE", "C_NULL", "O_EQEQ", "O_EQEQEQ", "O_NOTEQ", "O_NOTEQEQ",
  "O_LE", "O_GE", "O_INC", "O_DEC", "O_DOUBLEARROW", "O_SINGLEARROW",
  "O_SL", "O_SR", "O_COLONCOLON", "O_LOGICOR", "O_LOGICAND", "O_PLUSEQ",
  "O_MINUSEQ", "O_MULEQ", "O_DIVEQ", "O_CONCATEQ", "O_MODEQ", "O_ANDEQ",
  "O_OREQ", "O_XOREQ", "O_SLEQ", "O_SREQ", "O_MAGIC_CONCAT", "CAST_INT",
  "CAST_REAL", "CAST_STRING", "CAST_ARRAY", "CAST_OBJECT", "CAST_BOOL",
  "CAST_UNSET", "STRING", "IDENT", "VARIABLE", "INT", "REAL",
  "INLINE_HTML", "INVALID_TOKEN", "','", "'='", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'.'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "'@'", "'['", "'('", "')'", "';'", "'{'", "'}'", "'$'", "']'",
  "$accept", "start", "top_statement_list", "top_statement",
  "inner_statement_list", "inner_statement", "statement", "keyword_if",
  "keyword_foreach", "unticked_statement", "@1", "@2", "@3", "@4", "@5",
  "@6", "@7", "additional_catches", "non_empty_additional_catches",
  "additional_catch", "@8", "unset_variables", "unset_variable",
  "use_filename", "function_declaration_statement",
  "class_declaration_statement", "is_reference",
  "unticked_function_declaration_statement", "@9", "@10",
  "unticked_class_declaration_statement", "@11", "class_entry_type",
  "extends_from", "interface_entry", "interface_extends_list",
  "implements_list", "interface_list", "foreach_optional_arg",
  "foreach_variable", "for_statement", "foreach_statement",
  "declare_statement", "declare_list", "switch_case_list", "case_list",
  "@12", "@13", "case_separator", "while_statement", "elseif_list", "@14",
  "new_elseif_list", "@15", "else_single", "new_else_single",
  "parameter_list", "non_empty_parameter_list", "optional_class_type",
  "function_call_parameter_list", "non_empty_function_call_parameter_list",
  "global_var_list", "global_var", "static_var_list",
  "class_statement_list", "class_statement", "@16", "@17", "method_body",
  "variable_modifiers", "method_modifiers", "non_empty_member_modifiers",
  "member_modifier", "class_variable_declaration",
  "class_constant_declaration", "echo_expr_list", "for_expr",
  "non_empty_for_expr", "expr_without_variable", "function_call",
  "fully_qualified_class_name", "class_name_reference",
  "dynamic_class_name_reference", "dynamic_class_name_variable_properties",
  "dynamic_class_name_variable_property", "exit_expr", "ctor_arguments",
  "common_scalar", "static_scalar", "static_class_constant", "scalar",
  "static_array_pair_list", "possible_comma",
  "non_empty_static_array_pair_list", "expr", "r_variable", "w_variable",
  "rw_variable", "variable", "variable_properties", "variable_property",
  "method_or_not", "variable_without_objects", "static_member",
  "base_variable_with_function_calls", "base_variable",
  "reference_variable", "compound_variable", "dim_offset",
  "object_property", "object_dim_list", "variable_name",
  "simple_indirect_reference", "assignment_list",
  "assignment_list_element", "array_pair_list",
  "non_empty_array_pair_list", "internal_functions_in_yacc",
  "isset_variables", "class_constant", "block", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,    44,    61,    63,    58,
     124,    94,    38,    60,    62,    43,    45,    46,    42,    47,
      37,    33,   126,    64,    91,    40,    41,    59,   123,   125,
      36,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   142,   143,   144,   144,   145,   145,   145,   145,   146,
     146,   147,   147,   147,   147,   148,   149,   150,   151,   151,
     151,   152,   151,   153,   151,   154,   151,   155,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   156,   151,   151,   157,   158,
     151,   151,   159,   159,   160,   160,   162,   161,   163,   163,
     164,   165,   165,   166,   167,   168,   168,   170,   171,   169,
     173,   172,   172,   174,   174,   174,   175,   175,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182,   183,   183,   184,   184,   185,   185,   186,   186,   186,
     186,   187,   188,   187,   189,   187,   190,   190,   191,   191,
     192,   193,   192,   194,   195,   194,   196,   196,   197,   197,
     198,   198,   199,   199,   199,   199,   199,   199,   199,   199,
     200,   200,   200,   201,   201,   202,   202,   202,   202,   202,
     202,   203,   203,   204,   204,   204,   205,   205,   205,   205,
     206,   206,   207,   207,   208,   209,   207,   210,   210,   211,
     211,   212,   212,   213,   213,   214,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   216,   216,   217,   217,   218,
     218,   219,   219,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   221,
     221,   221,   221,   222,   223,   223,   224,   224,   225,   225,
     226,   227,   227,   227,   228,   228,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   230,   230,   230,
     230,   230,   230,   231,   232,   232,   232,   233,   233,   234,
     234,   235,   235,   235,   235,   236,   236,   237,   238,   239,
     240,   240,   241,   241,   242,   243,   243,   244,   244,   245,
     246,   246,   247,   247,   247,   248,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   252,   253,   253,   254,
     254,   255,   255,   256,   256,   256,   257,   257,   258,   258,
     258,   258,   258,   258,   258,   258,   259,   259,   259,   259,
     259,   259,   259,   260,   260,   261,   262
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     4,     2,
       0,     1,     1,     1,     4,     1,     1,     1,     1,     7,
      10,     0,     6,     0,     8,     0,    10,     0,     6,     2,
       3,     2,     3,     2,     3,     3,     3,     3,     3,     1,
       2,     3,     5,     8,     8,     0,     6,     1,     0,     0,
      11,     3,     1,     0,     1,     2,     0,     7,     1,     3,
       1,     1,     3,     1,     1,     0,     1,     0,     0,     9,
       0,     8,     6,     1,     2,     2,     0,     2,     1,     0,
       2,     0,     2,     1,     3,     0,     2,     1,     2,     1,
       4,     1,     4,     1,     4,     3,     5,     3,     4,     4,
       5,     0,     0,     6,     0,     5,     1,     1,     1,     4,
       0,     0,     7,     0,     0,     8,     0,     2,     0,     3,
       1,     0,     2,     3,     5,     4,     4,     5,     7,     6,
       0,     1,     1,     1,     0,     1,     1,     2,     3,     3,
       4,     3,     1,     1,     2,     4,     3,     5,     1,     3,
       2,     0,     3,     2,     0,     0,    10,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     3,     5,     4,     3,     1,     0,
       1,     3,     1,     6,     3,     4,     6,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     4,     2,     4,
       6,     6,     4,     1,     1,     1,     4,     1,     2,     0,
       2,     0,     2,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     1,     3,     1,     1,     1,     0,     2,     0,
       1,     5,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     3,     3,     0,     1,     2,     3,
       1,     1,     1,     2,     1,     4,     4,     1,     1,     4,
       0,     1,     1,     1,     4,     4,     1,     1,     3,     1,
       2,     3,     1,     1,     4,     0,     0,     2,     5,     3,
       3,     1,     6,     4,     4,     2,     4,     4,     2,     2,
       4,     2,     2,     1,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       4,     0,     2,     1,   273,   272,     0,     0,    73,     0,
      45,    23,     0,     0,     0,   261,    25,    17,    67,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    21,   276,   274,   275,     0,    78,
       0,     0,    48,     0,     0,   270,   269,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   284,   318,
     266,   267,    39,     0,     0,     0,     0,     0,     0,    47,
      10,   329,     3,     5,     0,     0,    15,     6,     7,    63,
      64,     0,     0,   296,   311,     0,   286,   246,     0,   295,
       0,   297,     0,   314,   301,   310,   312,   317,     0,   236,
     285,    18,   336,    29,     0,    31,     0,     0,     0,     0,
     178,     0,     0,     0,   244,     0,    65,   143,     0,     0,
     142,   348,   349,     0,   335,   254,     0,   264,   255,   257,
     312,     0,   248,   351,   352,    33,   296,     0,   297,   148,
       0,     0,     0,    61,     0,     0,     0,    75,    74,   188,
       0,     0,     0,   253,     0,   201,   299,   203,   237,   238,
     239,   240,   241,   242,   243,   134,   221,   222,   223,   224,
     245,     0,     0,     0,     0,     0,    70,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,   200,   202,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,   300,   303,   320,     0,   330,   313,     0,
     341,     0,   289,    30,    32,     0,     0,     0,    38,     0,
       0,   262,     0,   179,    66,     0,     0,   144,   297,     0,
      36,   353,     0,     0,   333,     0,   332,     0,   134,   187,
       0,   313,    34,    35,     0,     0,    37,     0,     0,    58,
      60,     0,    41,     0,     0,    51,     0,     0,     0,     0,
     133,   296,   297,   234,     0,   356,     9,    11,    12,    13,
       0,     0,   296,   297,    76,     0,     0,   355,   309,   307,
       0,   207,   206,   208,   233,   227,   225,   228,   226,   230,
     232,   219,   220,   204,   205,     0,     0,   209,   211,   210,
     229,   231,   214,   215,   212,   216,   217,   218,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,     0,
     184,     0,   327,     0,   323,   306,   322,   326,   302,   321,
       0,     0,   345,   298,     0,   247,   290,   337,     0,     0,
       0,   177,   347,   350,   263,     0,   180,   182,    68,     0,
     141,     0,   346,   335,   335,     0,   309,     0,   259,     0,
     278,     0,     0,   277,   149,   282,   146,     0,     0,     0,
      62,     0,    49,     8,     0,   137,   249,     0,     0,   319,
       0,     0,     0,     0,    81,   253,    80,    83,   151,   134,
     134,   308,   213,     0,     0,   185,   252,     0,   134,   304,
     320,     0,   315,   316,     0,   340,     0,   339,     0,     0,
       0,     0,   179,     0,     0,   145,   354,     0,   331,     0,
     265,   256,   287,     0,   279,   280,     0,     0,    59,    42,
       0,     0,     0,   296,   297,     0,    10,   110,    85,     0,
      85,    87,    77,     0,     0,     0,   161,     0,     0,   235,
     264,   328,     0,     0,     0,   344,   343,     0,    95,     0,
      10,    93,    46,     0,     0,   181,   130,   334,   183,     0,
     258,   294,     0,   289,   283,   147,   101,   101,    28,    10,
     108,    22,     0,   140,    14,   113,   116,     0,     0,    88,
       0,    82,   151,    84,     0,   168,   160,   170,   165,   167,
     166,   169,    72,   150,     0,     0,   159,   163,     0,   250,
     251,   186,   305,   324,   325,     0,   338,     0,     0,     0,
     179,   132,   131,     0,   120,     0,   260,     0,   281,   290,
     288,   101,     0,   101,     0,     0,     0,   118,     0,   111,
      19,    86,     0,     0,   161,     0,   173,     0,   154,   164,
       0,   153,   342,    96,     0,    24,     0,     0,   130,   122,
       0,   293,   292,     0,     0,     0,     0,     0,    97,     0,
       0,     0,   114,     0,   117,     0,    10,    91,    44,    43,
      71,     0,     0,     0,   152,    65,     0,    94,     0,    69,
       0,     0,   123,     0,     0,     0,   106,   107,   104,    99,
      98,   109,     0,    10,     0,     0,     0,     0,   176,   174,
     171,     0,     0,    10,    89,    26,   126,     0,   125,     0,
     291,   100,   102,    10,    53,   119,     0,    20,     0,     0,
       0,   155,   175,     0,     0,   127,   124,    10,   105,    56,
      50,    52,    54,     0,     0,    92,   172,     0,     0,   129,
       0,   103,     0,    55,     0,   112,   130,    90,   128,     0,
      10,     0,     0,   115,     0,     0,   157,   156,   158,     0,
      57
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,    72,   172,   286,   287,    74,    75,    76,
     146,   108,   115,   141,   107,   150,   451,   660,   661,   662,
     672,   268,   269,   145,   288,   289,   245,    79,   116,   434,
      80,   294,    81,   404,    82,   296,   464,   406,   508,   460,
     635,   598,   482,   359,   498,   552,   657,   643,   618,   501,
     506,   595,   557,   624,   560,   593,   543,   544,   545,   279,
     280,   119,   120,   140,   466,   523,   605,   667,   687,   524,
     525,   526,   527,   567,   528,   109,   365,   366,    83,    84,
      85,   127,   128,   441,   490,   114,   259,    86,   384,   385,
      87,   492,   357,   493,    88,    89,   461,    90,    91,   223,
     224,   419,    92,    93,    94,    95,    96,    97,   350,   345,
     346,   347,    98,   255,   256,   231,   232,    99,   252,   100,
     101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -475
static const short int yypact[] =
{
    -475,    85,  1805,  -475,  -475,  -475,   -41,  2847,  -475,  2958,
    -475,  -475,  4068,   -36,   -17,   -10,  -475,  -475,  -475,   -93,
    -475,  4068,  4068,    43,    48,   -59,  4068,  4068,  4068,  3069,
     -20,  -475,    58,   -70,  -475,  -475,  -475,  -475,    90,  -475,
     128,  4068,  -475,  4068,    61,  -475,  -475,  -475,   -38,   -38,
    4068,  4068,  4068,  4068,  4068,  4068,  4068,  -475,   -79,  -475,
    -475,  -475,  -475,  4068,  4068,  4068,  4068,  4068,  4068,  -475,
    -475,    52,  -475,  -475,    65,    76,  -475,  -475,  -475,  -475,
    -475,   105,   111,  -475,  -475,   140,  -475,  -475,  4206,  -475,
     -32,  1136,   104,  -475,   157,  -475,   116,  -475,   -87,  -475,
    -475,  -475,  3180,  -475,  4270,  -475,  4334,   108,  2736,   -89,
    5230,   -38,  4068,  3291,  -475,   121,   146,  -475,   -80,   -29,
    -475,  5230,  5230,   -38,   -14,   159,   184,   138,  -475,   186,
     -97,   -87,  5414,  5230,  5230,  -475,   137,  5230,   770,   160,
       0,   143,   -38,  -475,   170,   145,   150,  -475,  -475,  -475,
     142,  4398,   152,   156,   205,  -475,  -475,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,  -475,  3402,     5,     5,   253,  -475,
    -475,  4462,  1138,  4068,  4068,  4068,  -475,   262,   -28,  4068,
    4068,  4068,   -59,  4068,  4068,  4068,  4068,  4068,  4068,  4068,
    4068,  4068,  4068,  4068,  4068,  4068,  4068,  4068,  4068,  4068,
    4068,  4068,  4068,  4068,  4068,  4068,  -475,  -475,  -475,  4068,
    4068,  4068,  4068,  4068,  4068,  4068,  4068,  4068,  4068,  4068,
    3513,  3402,    11,   157,  -475,  4068,  4068,    52,   126,   -38,
    5038,   161,   179,  -475,  -475,   189,   247,  4068,  -475,   165,
    4526,  -475,  4590,  4068,  -475,   192,  4068,  -475,  -475,   -93,
    -475,  -475,   -94,   168,  -475,    14,  -475,   -77,  3402,  -475,
      11,   -97,  -475,  -475,   441,   195,  -475,  4068,    39,  -475,
    -475,   171,  -475,  4068,   241,  -475,   172,    37,   -38,   174,
     196,    44,  5555,  -475,   176,  -475,  -475,  -475,  -475,  -475,
     500,  4654,   303,   517,   282,   209,   177,   185,   187,   -97,
     -87,  5414,  5294,  5358,  -475,  5197,  5197,  5197,  5197,   204,
     204,    38,    38,  5432,  4112,   717,  5102,  5488,  5505,  5261,
     204,   204,     5,     5,     5,   253,   253,   253,  5414,  5414,
    5414,  5414,  5414,  5414,  5414,  5414,  5414,  5414,  5414,    33,
    5414,   202,  -475,  4068,  -475,   188,   -48,  -475,  -475,  5230,
     199,   845,  -475,  -475,  3624,  -475,  3735,  -475,   208,    53,
     206,  5230,  -475,  -475,  -475,   207,   220,  5230,  -475,   901,
    -475,   -38,  -475,   -14,   -14,   225,  -475,   211,  -475,   214,
     250,   441,   441,  -475,  -475,  -475,   226,  4718,   -38,   215,
    -475,  4782,  -475,  -475,   185,  -475,  -475,  3846,   217,  -475,
    2071,   -38,   -78,   209,   285,  -475,   230,  -475,  -475,  3402,
    3402,   -97,  -475,  4068,   -59,  -475,  -475,   957,  3402,  -475,
    4068,  4068,  -475,  -475,   -38,  5230,   -38,  5166,   441,   244,
    2204,  4068,  4068,  4068,   221,  -475,  -475,    55,  -475,  4068,
    -475,   275,   441,   252,  -475,  -475,   441,   -81,  -475,  -475,
    2337,   228,   -38,    63,  5583,   227,  -475,  -475,   283,   -38,
     283,  -475,  -475,   209,   232,   209,     7,   235,   236,   687,
     138,  -475,   237,   233,  1013,  -475,  -475,  3957,  -475,   251,
    -475,  -475,  -475,  4846,   239,  5230,     4,  -475,  5414,    11,
    -475,   294,   245,   266,  -475,  -475,   246,   248,  -475,  -475,
    -475,  -475,   209,  -475,  -475,  1938,   135,   -78,   256,  -475,
     258,   230,  -475,  -475,   276,  -475,  -475,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,   284,   352,   162,  -475,     8,  -475,
    -475,  -475,  -475,  -475,  -475,   -38,  5230,   441,  1273,   263,
    4068,  -475,  -475,   268,   286,   -82,  -475,   441,  -475,   441,
    -475,  -475,   200,  -475,    -3,  1406,   288,   183,  2736,  -475,
    -475,  -475,  2470,  2470,   124,   290,   291,    16,  -475,  -475,
     299,  -475,  -475,  -475,   273,  -475,   279,   142,    10,   295,
     305,  -475,   334,   201,  4068,   -44,   281,     3,  -475,   287,
     289,   300,  -475,   393,  -475,   297,  -475,  -475,  -475,  -475,
    -475,   441,   441,   312,  -475,   146,   317,  -475,  2603,  -475,
       6,   441,   320,   441,   301,  4142,  -475,  -475,  -475,  -475,
    -475,  -475,   142,  -475,   306,   307,  4068,  1539,  -475,  -475,
     326,   335,   441,  -475,  -475,  -475,   336,   340,  -475,   441,
    -475,  -475,  -475,  -475,   387,  1938,  4068,  -475,  4910,   318,
     441,  -475,  -475,  1672,   441,   339,  -475,  -475,  1938,  -475,
    -475,   387,  -475,  4974,  2736,  -475,  -475,   322,   321,  -475,
     441,  1938,   325,  -475,   342,  -475,     4,  -475,  -475,   209,
    -475,   327,   351,  1938,    93,   328,  -475,  -475,  -475,   142,
    -475
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -475,  -475,  -475,  -475,  -376,  -475,    -2,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,  -475,  -475,  -475,  -475,  -475,  -195,
    -475,  -475,    79,  -475,   466,   467,  -134,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,  -475,  -475,  -475,     9,    13,   -31,
    -475,   -86,  -475,  -475,  -475,  -474,  -475,  -475,  -137,  -475,
    -475,  -475,  -475,  -475,  -475,  -475,  -196,  -475,   -96,  -215,
    -475,  -475,   234,  -475,   -27,  -475,  -475,  -475,  -475,  -475,
    -475,  -475,   -40,  -475,  -475,  -475,  -425,  -475,    17,  -475,
     -23,  -177,  -475,  -475,  -475,  -475,    18,  -180,  -315,  -475,
    -475,  -475,    23,  -475,   480,   373,  -217,   210,   -13,  -475,
     270,  -475,  -168,  -475,  -475,   -21,   -24,  -475,    78,  -249,
    -475,  -475,    -8,   127,   125,  -475,  -475,  -475,  -475,  -475,
    -147
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -309
static const short int yytable[] =
{
      73,   130,   126,   274,   129,   304,   341,   484,  -253,   584,
     298,   378,   352,   541,   585,   584,   138,   131,   117,   541,
     585,   514,   371,   554,    59,   154,   154,   237,   253,   579,
     153,    59,   153,    59,    59,   156,   156,   225,   496,   143,
     580,   226,   372,   377,   459,   182,   136,   118,   238,   207,
     208,   125,    59,   227,   344,   515,   165,   497,   246,   516,
      71,   395,    71,    71,   517,   144,   444,   445,   518,   519,
     520,   521,   153,    59,   228,   616,   414,   583,   182,   587,
     505,    71,   297,    59,   383,     3,   420,   249,   154,   376,
     421,   139,   344,   617,   102,   154,   153,    59,   239,   111,
     154,   154,    71,   147,   538,   248,   236,   261,   250,   298,
     251,   254,    71,   478,   542,   576,   265,   636,   112,   154,
     542,   342,    59,   555,   570,   113,    71,   491,   637,   270,
     374,   495,   603,   203,   204,   205,   588,   266,   514,   193,
    -121,   148,   620,   153,    59,   571,   522,   394,    59,   343,
     375,    71,   282,   604,   299,   388,   558,   559,   130,   126,
    -135,   129,   293,   200,   201,   202,   203,   204,   205,   429,
     300,   374,   515,    71,   131,   389,   516,    71,   123,  -138,
    -135,   517,   281,   124,   458,   518,   519,   520,   521,   430,
     173,   487,   292,   142,   467,   468,   152,  -162,   299,  -138,
     174,   383,   383,   472,   591,   592,   154,   475,   282,   476,
     515,   175,   584,   584,   300,   176,   353,   585,   585,   517,
     627,   177,   573,   518,   519,   520,   521,   178,   586,   614,
     686,    70,   581,   299,   582,   503,   299,   470,   281,   221,
     546,   222,   509,   235,   182,   282,  -253,   645,   383,   300,
     225,  -307,   300,   299,   226,   154,   243,   653,   155,   157,
     225,  -308,   383,   600,   226,   353,   383,   658,   244,   300,
     260,   257,   407,   258,   262,   281,   411,   264,   267,   271,
      70,   671,   272,  -309,  -309,   273,   628,   629,   276,   189,
     190,   165,   277,   182,   295,   356,   638,   355,   640,   358,
     360,   362,   368,   373,   683,   193,   386,   390,   392,   393,
     396,   398,   397,   401,   403,   408,   154,   652,   572,   405,
     409,   344,   410,   418,   656,   428,   415,  -309,  -309,   200,
     201,   202,   203,   204,   205,   666,   433,   443,   416,   669,
     422,   431,   439,   446,   432,   463,   465,   440,   154,   442,
     154,   154,   449,   455,   479,   678,   486,   383,   436,   489,
     254,   254,   494,   502,   504,   154,   507,   383,   537,   383,
     512,   529,   530,   532,   533,   270,   540,   547,   154,   154,
     462,   548,   549,   551,   454,   553,   565,   568,   353,   353,
     130,   126,   562,   129,   563,   566,   282,   282,   457,   590,
     575,   154,   578,   154,   577,   282,   131,   601,   602,   606,
     607,   353,   611,   353,   453,   608,   612,   613,   619,   623,
     625,   383,   383,   630,   621,   622,   281,   281,   481,   154,
     609,   383,   626,   383,   632,   281,   154,   639,   641,   353,
     407,   646,   513,   650,   647,   651,   353,     4,   500,     5,
     379,   655,   383,   654,   659,   665,   670,   676,   677,   383,
     679,   680,   685,   684,   689,   299,   673,   448,    77,    78,
     383,   631,   511,   510,   383,   644,   561,   599,   642,   556,
     681,   300,   610,   370,   154,   564,   569,   104,   531,   106,
     383,   247,   110,   348,   353,    35,    36,    37,   473,   438,
     437,   121,   122,   179,   180,   181,   132,   133,   134,   137,
       0,     0,   154,    45,    46,    47,   550,     0,     0,     0,
       0,   149,   353,   151,     0,     0,     0,   402,     0,     0,
     158,   159,   160,   161,   162,   163,   164,   688,     0,     0,
     182,     0,   690,   166,   167,   168,   169,   170,   171,     0,
      57,   380,     0,    60,    61,     0,   594,     0,     0,     0,
     597,   597,     0,     0,     0,     0,   381,   382,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,     0,   230,     0,     0,   189,   190,     0,   191,   192,
       0,     0,   240,   242,     0,     0,     0,     0,  -299,  -299,
       0,   193,     0,     0,     0,     0,   634,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,     0,     0,     0,   220,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   290,   291,   137,   682,     0,     0,   301,
     302,   303,   675,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,     0,     0,     0,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     340,   137,     0,     0,     0,   349,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,     0,     0,
     179,   180,   181,   367,     0,     0,   369,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,     0,     0,     0,   387,     0,     0,
       0,     0,     0,   391,     0,     0,     0,   182,     0,     0,
       0,     0,   183,   184,   185,   186,   187,   188,     0,     0,
       0,     0,   189,   190,     0,   191,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,     0,   183,   184,   185,   186,   187,   188,     0,     0,
       0,     0,   189,   190,     0,   191,   192,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   193,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   425,   194,   427,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   179,   180,
     181,  -299,  -299,     0,     0,     0,   412,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   182,     0,   220,     0,   137,
     137,     0,     0,   469,     0,     0,     0,     0,   137,     0,
     349,   474,     0,     0,   179,   180,   181,   263,     0,     0,
       0,   483,   367,   485,     0,     0,     0,     0,     0,   488,
     183,   184,   185,   186,   187,   188,     0,     0,     0,     0,
     189,   190,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   182,     0,     0,     0,     0,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   536,     0,     0,
     179,   180,   181,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   183,   184,   185,   186,
     187,   188,     0,     0,   423,     0,   189,   190,     0,   191,
     192,     0,     0,     0,     0,     0,     0,   182,     0,     0,
       0,     0,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   180,   181,   194,
     367,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   183,   184,   185,   186,   187,   188,     0,     0,
     435,     0,   189,   190,     0,   191,   192,     0,     0,     0,
       0,     0,     0,   182,     0,     0,     0,     0,   193,     0,
       0,     0,     0,     0,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   183,   184,
     185,   186,   187,   188,     0,     0,   471,     0,   189,   190,
       0,   191,   192,     0,     0,     0,   648,     0,     0,     0,
       0,     0,     0,     0,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   663,     0,     0,     0,
       0,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,     4,     0,     5,     6,     0,     7,
       0,     8,   534,     9,    10,     0,     0,    11,    12,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,     0,    39,     0,     0,
       0,     0,    40,    41,    42,     0,    43,     0,     0,   284,
      45,    46,    47,     0,     0,     0,     0,  -299,  -299,    48,
      49,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,     0,     0,     0,     0,    65,
      66,    67,     0,    68,     0,    69,    70,   285,    71,     4,
       0,     5,     6,     0,     7,     0,     8,     0,     9,    10,
       0,     0,    11,    12,     0,     0,    13,   574,     0,     0,
       0,     0,     0,    14,    15,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    37,
      38,     0,    39,     0,     0,     0,     0,    40,    41,    42,
       0,    43,     0,     0,   284,    45,    46,    47,     0,     0,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,    65,    66,    67,     0,    68,     0,
      69,    70,     4,    71,     5,     6,     0,     7,     0,     8,
       0,     9,    10,     0,     0,    11,    12,     0,     0,    13,
       0,     0,     0,     0,     0,   589,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
      35,    36,    37,    38,     0,    39,     0,     0,     0,     0,
      40,    41,    42,     0,    43,     0,     0,   284,    45,    46,
      47,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,    65,    66,    67,
       0,    68,     0,    69,    70,     4,    71,     5,     6,     0,
       7,     0,     8,     0,     9,    10,     0,     0,    11,    12,
       0,     0,    13,     0,     0,   649,     0,     0,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,     0,    39,     0,
       0,     0,     0,    40,    41,    42,     0,    43,     0,     0,
     284,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
      65,    66,    67,     0,    68,     0,    69,    70,     4,    71,
       5,     6,     0,     7,     0,     8,     0,     9,    10,     0,
       0,    11,    12,     0,     0,    13,     0,   668,     0,     0,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
       0,    39,     0,     0,     0,     0,    40,    41,    42,     0,
      43,     0,     0,   284,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,     0,
       0,     0,     0,    65,    66,    67,     0,    68,     0,    69,
      70,     4,    71,     5,     6,     0,     7,     0,     8,     0,
       9,    10,     0,     0,    11,    12,     0,     0,    13,     0,
       0,     0,     0,     0,     0,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,     0,    39,     0,     0,     0,     0,    40,
      41,    42,     0,    43,     0,     0,    44,    45,    46,    47,
       0,     0,     0,     0,     0,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,    65,    66,    67,     0,
      68,     0,    69,    70,     4,    71,     5,     6,     0,     7,
       0,     8,     0,     9,    10,     0,     0,    11,    12,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,     0,    39,     0,     0,
       0,     0,    40,    41,    42,     0,    43,     0,     0,   284,
      45,    46,    47,     0,     0,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,     0,     0,     0,     0,    65,
      66,    67,     0,    68,     0,    69,    70,     4,    71,     5,
       6,     0,     7,     0,     0,     0,     9,    10,     0,     0,
      11,    12,     0,     0,    13,     0,     0,     0,     0,     0,
       0,    14,    15,     0,    16,    17,     0,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,    45,    46,    47,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
     456,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,     0,    65,    66,    67,     0,    68,     0,    69,    70,
       4,    71,     5,     6,     0,     7,     0,     0,     0,     9,
      10,     0,     0,    11,    12,     0,     0,    13,     0,     0,
       0,     0,     0,     0,    14,    15,     0,    16,    17,     0,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      42,     0,    43,     0,     0,     0,    45,    46,    47,     0,
       0,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,   480,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,     0,    65,    66,    67,     0,    68,
       0,    69,    70,     4,    71,     5,     6,     0,     7,     0,
       0,     0,     9,    10,     0,     0,    11,    12,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    14,    15,     0,
      16,    17,     0,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,    43,     0,     0,     0,    45,
      46,    47,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,   499,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,    65,    66,
      67,     0,    68,     0,    69,    70,     4,    71,     5,     6,
       0,     7,     0,     0,     0,     9,    10,     0,     0,    11,
      12,     0,     0,    13,     0,     0,     0,     0,     0,     0,
      14,    15,     0,    16,    17,     0,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    42,     0,    43,     0,
       0,     0,    45,    46,    47,     0,     0,     0,     0,     0,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,   596,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,    65,    66,    67,     0,    68,     0,    69,    70,     4,
      71,     5,     6,     0,     7,     0,     0,     0,     9,    10,
       0,     0,    11,    12,     0,     0,    13,     0,     0,     0,
       0,     0,     0,    14,    15,     0,    16,    17,     0,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,    45,    46,    47,     0,     0,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,    65,    66,    67,     0,    68,     0,
      69,    70,     4,    71,     5,     6,     0,     7,     0,     0,
       0,     9,    10,     0,     0,    11,    12,     0,     0,    13,
       0,     0,     0,     0,     0,     0,    14,    15,     0,    16,
      17,     0,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
      35,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,     0,    45,    46,
      47,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     4,     0,     5,     6,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,    65,    66,    67,
      13,    68,     0,    69,    70,     0,    71,    14,    15,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    37,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     4,     0,     5,     6,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,    65,    66,
      67,    13,    68,     0,   103,     0,     0,    71,    14,    15,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
      45,    46,    47,     0,     0,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,     0,     4,     0,     5,     6,     0,
       0,     0,     0,    63,    64,     0,     0,     0,     0,    65,
      66,    67,    13,    68,     0,   105,     0,     0,    71,    14,
      15,     0,     0,     0,     0,     0,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,    35,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     4,     0,     5,     6,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
      65,    66,    67,    13,    68,     0,   135,     0,     0,    71,
      14,    15,     0,     0,     0,     0,     0,     0,    21,    22,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,     0,     0,    35,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,     0,     0,     0,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,     4,     0,     5,
       6,     0,   229,     0,     0,    63,    64,     0,     0,     0,
       0,    65,    66,    67,    13,    68,     0,     0,     0,     0,
      71,    14,    15,     0,     0,     0,     0,     0,     0,    21,
      22,     0,    23,    24,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     4,     0,
       5,     6,     0,     0,     0,     0,    63,    64,     0,     0,
       0,     0,    65,    66,    67,    13,    68,   241,     0,     0,
       0,    71,    14,    15,     0,     0,     0,     0,     0,     0,
      21,    22,     0,    23,    24,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,    35,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,     4,
       0,     5,     6,     0,   278,     0,     0,    63,    64,     0,
       0,     0,     0,    65,    66,    67,    13,    68,     0,     0,
       0,     0,    71,    14,    15,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    23,    24,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,    45,    46,    47,     0,     0,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
       4,     0,     5,     6,     0,   339,     0,     0,    63,    64,
       0,     0,     0,     0,    65,    66,    67,    13,    68,     0,
       0,     0,     0,    71,    14,    15,     0,     0,     0,     0,
       0,     0,    21,    22,     0,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,    35,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,    45,    46,    47,     0,
       0,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     4,     0,     5,     6,     0,   424,     0,     0,    63,
      64,     0,     0,     0,     0,    65,    66,    67,    13,    68,
       0,     0,     0,     0,    71,    14,    15,     0,     0,     0,
       0,     0,     0,    21,    22,     0,    23,    24,    25,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,    45,    46,    47,
       0,     0,     0,     0,     0,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     4,     0,     5,     6,     0,   426,     0,     0,
      63,    64,     0,     0,     0,     0,    65,    66,    67,    13,
      68,     0,     0,     0,     0,    71,    14,    15,     0,     0,
       0,     0,     0,     0,    21,    22,     0,    23,    24,    25,
      26,    27,    28,     0,     0,     0,     0,     0,     0,     0,
      35,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,    45,    46,
      47,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,     4,     0,     5,     6,     0,   452,     0,
       0,    63,    64,     0,     0,     0,     0,    65,    66,    67,
      13,    68,     0,     0,     0,     0,    71,    14,    15,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    37,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     4,     0,     5,     6,     0,   535,
       0,     0,    63,    64,     0,     0,     0,     0,    65,    66,
      67,    13,    68,     0,     0,     0,     0,    71,    14,    15,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
      45,    46,    47,     0,     0,   179,   180,   181,     0,    48,
      49,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   182,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,    63,    64,     0,     0,   189,   190,    65,
      66,    67,     0,    68,     0,     0,     0,     0,    71,   179,
     180,   181,     0,   193,     0,     0,     0,   183,   184,   185,
     186,   187,   188,     0,     0,     0,     0,   189,   190,     0,
     191,   192,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   193,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   616,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   179,   180,   181,     0,     0,     0,   617,
       0,   183,   184,   185,   186,   187,   188,     0,     0,     0,
       0,   189,   190,     0,   191,   192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   179,   180,   181,
       0,     0,     0,   206,     0,   183,   184,   185,   186,   187,
     188,     0,     0,     0,     0,   189,   190,     0,   191,   192,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   179,   180,   181,     0,     0,     0,   233,     0,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,   189,
     190,     0,   191,   192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   179,   180,   181,     0,     0,
       0,   234,     0,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,   189,   190,     0,   191,   192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   179,
     180,   181,     0,     0,     0,   275,     0,   183,   184,   185,
     186,   187,   188,     0,     0,     0,     0,   189,   190,     0,
     191,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   179,   180,   181,     0,     0,   283,     0,
       0,   183,   184,   185,   186,   187,   188,     0,     0,     0,
       0,   189,   190,     0,   191,   192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   179,   180,   181,
       0,     0,   363,     0,     0,   183,   184,   185,   186,   187,
     188,     0,     0,     0,     0,   189,   190,     0,   191,   192,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   179,   180,   181,     0,     0,   364,     0,     0,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,   189,
     190,     0,   191,   192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   179,   180,   181,     0,     0,
     400,     0,     0,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,   189,   190,     0,   191,   192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   179,
     180,   181,     0,     0,   447,     0,     0,   183,   184,   185,
     186,   187,   188,     0,     0,     0,     0,   189,   190,     0,
     191,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   179,   180,   181,     0,     0,   450,     0,
       0,   183,   184,   185,   186,   187,   188,     0,     0,     0,
       0,   189,   190,     0,   191,   192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   179,   180,   181,
       0,     0,   539,     0,     0,   183,   184,   185,   186,   187,
     188,     0,     0,     0,     0,   189,   190,     0,   191,   192,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   179,   180,   181,     0,     0,   664,     0,     0,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,   189,
     190,     0,   191,   192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   179,   180,   181,     0,     0,
     674,     0,     0,   183,   184,   185,   186,   187,   188,     0,
       0,   354,     0,   189,   190,     0,   191,   192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   179,
     180,   181,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,     0,     0,     0,     0,   189,   190,     0,
     191,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   413,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   179,   180,   181,     0,   182,     0,     0,
       0,   183,   184,   185,   186,   187,   188,     0,     0,   477,
       0,   189,   190,     0,   191,   192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
     182,     0,  -309,  -309,  -309,  -309,   187,   188,     0,     0,
       0,     0,   189,   190,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   179,   193,   181,
       0,   182,     0,     0,     0,   183,   184,   185,   186,   187,
     188,     0,     0,     0,     0,   189,   190,     0,   191,   192,
     198,   199,   200,   201,   202,   203,   204,   205,     0,     0,
       0,   193,     0,     0,   182,     0,   183,   184,   185,   186,
     187,   188,     0,     0,     0,     0,   189,   190,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   179,   193,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,   189,
     190,     0,   191,   192,   198,   199,   200,   201,   202,   203,
     204,   205,     0,     0,     0,   193,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,   189,   190,     0,   191,   192,     0,     0,
       0,     0,     0,     0,   182,     0,     0,     0,     0,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,     0,     0,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,   189,
     190,     0,   191,   192,     0,     0,     0,   183,   184,   185,
     186,   187,   188,     0,     0,   193,     0,   189,   190,     0,
       0,   192,     0,     0,     0,     0,     0,     0,   182,     0,
       0,     0,   194,   193,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   182,     0,     0,     0,     0,
       0,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,   189,   190,     0,     0,     0,     0,     0,
     183,   184,   185,   186,   187,   188,     0,     0,     0,   193,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,     0,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,     0,
       0,     0,     0,     0,     0,     0,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,  -299,  -299,     0,     0,
       0,     0,     0,     0,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,  -299,  -299,     0,     0,     0,     0,
       0,  -136,   220,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,  -136,     0,     0,     0,     0,     0,     0,     0,  -139,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -139
};

static const short int yycheck[] =
{
       2,    25,    25,   150,    25,   182,   221,   432,    87,    12,
     178,   260,   229,     9,    17,    12,    29,    25,   111,     9,
      17,    14,   116,   497,   111,    48,    49,   116,    42,   111,
     110,   111,   110,   111,   111,    48,    49,   134,   119,   109,
     122,   138,   136,   258,   122,    40,    29,   140,   137,    81,
      82,   110,   111,   140,   222,    48,   135,   138,   138,    52,
     140,   278,   140,   140,    57,   135,   381,   382,    61,    62,
      63,    64,   110,   111,    98,   119,    43,   551,    40,   553,
     456,   140,   110,   111,   264,     0,   134,   116,   111,   257,
     138,   111,   260,   137,   135,   118,   110,   111,   111,   135,
     123,   124,   140,    13,   480,   118,   108,   131,   137,   277,
     123,   124,   140,   428,   110,   540,   116,   111,   135,   142,
     110,   110,   111,   499,   116,   135,   140,   442,   122,   142,
     116,   446,   116,   128,   129,   130,   139,   137,    14,   101,
     136,    13,   139,   110,   111,   137,   139,   110,   111,   138,
     136,   140,   165,   137,   178,   116,    21,    22,   182,   182,
     116,   182,   175,   125,   126,   127,   128,   129,   130,   116,
     178,   116,    48,   140,   182,   136,    52,   140,   135,   116,
     136,    57,   165,   135,   401,    61,    62,    63,    64,   136,
     138,   136,   175,   135,   409,   410,   135,    35,   222,   136,
     135,   381,   382,   418,    21,    22,   229,   424,   221,   426,
      48,   135,    12,    12,   222,   110,   229,    17,    17,    57,
     596,   110,   537,    61,    62,    63,    64,    87,    28,    28,
     137,   138,   547,   257,   549,   452,   260,   414,   221,   135,
     489,    84,   459,   135,    40,   258,    87,   623,   428,   257,
     134,   135,   260,   277,   138,   278,   135,   633,    48,    49,
     134,   135,   442,   139,   138,   278,   446,   643,   122,   277,
      84,    87,   295,   135,   137,   258,   300,   117,   135,   109,
     138,   657,   137,    79,    80,   135,   601,   602,   136,    85,
      86,   135,    87,    40,    32,   116,   611,   136,   613,   110,
      53,   136,   110,   135,   680,   101,   111,   136,    67,   137,
     136,   135,   116,    10,    32,   138,   339,   632,   535,   110,
     135,   489,   135,   135,   639,   117,   339,   123,   124,   125,
     126,   127,   128,   129,   130,   650,   116,    87,   136,   654,
     141,   135,   117,   117,   137,    60,   116,   136,   371,   135,
     373,   374,   137,   136,   110,   670,   135,   537,   371,    84,
     373,   374,   110,   135,   137,   388,    83,   547,   117,   549,
     138,   136,   136,   136,   141,   388,   137,    83,   401,   402,
     403,   136,   116,   137,   397,   137,   110,    35,   401,   402,
     414,   414,   136,   414,   136,   111,   409,   410,   400,   111,
     137,   424,   116,   426,   136,   418,   414,   117,   117,   110,
     137,   424,   117,   426,   397,   136,   111,    83,   137,   119,
      27,   601,   602,   111,   137,   136,   409,   410,   430,   452,
     577,   611,   135,   613,   117,   418,   459,   117,   137,   452,
     463,   135,   465,   117,   137,   110,   459,     6,   450,     8,
       9,   111,   632,   117,    67,   137,   117,   135,   137,   639,
     135,   119,   111,   136,   136,   489,   661,   388,     2,     2,
     650,   605,   463,   460,   654,   622,   507,   563,   615,   502,
     676,   489,   578,   249,   507,   512,   526,     7,   470,     9,
     670,   118,    12,   223,   507,    54,    55,    56,   420,   374,
     373,    21,    22,     3,     4,     5,    26,    27,    28,    29,
      -1,    -1,   535,    72,    73,    74,   493,    -1,    -1,    -1,
      -1,    41,   535,    43,    -1,    -1,    -1,    10,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,   684,    -1,    -1,
      40,    -1,   689,    63,    64,    65,    66,    67,    68,    -1,
     109,   110,    -1,   112,   113,    -1,   558,    -1,    -1,    -1,
     562,   563,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,   102,    -1,    -1,    85,    86,    -1,    88,    89,
      -1,    -1,   112,   113,    -1,    -1,    -1,    -1,    81,    82,
      -1,   101,    -1,    -1,    -1,    -1,   608,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,   679,    -1,    -1,   179,
     180,   181,   664,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,    -1,
       3,     4,     5,   243,    -1,    -1,   246,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,    -1,    -1,
      -1,    -1,    -1,   273,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    89,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   101,    -1,
      -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   354,   118,   356,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     3,     4,
       5,    81,    82,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,   117,    -1,   409,
     410,    -1,    -1,   413,    -1,    -1,    -1,    -1,   418,    -1,
     420,   421,    -1,    -1,     3,     4,     5,   137,    -1,    -1,
      -1,   431,   432,   433,    -1,    -1,    -1,    -1,    -1,   439,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,
       3,     4,     5,   118,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    75,    76,    77,    78,
      79,    80,    -1,    -1,   139,    -1,    85,    86,    -1,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,   118,
     540,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    75,    76,    77,    78,    79,    80,    -1,    -1,
     139,    -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    75,    76,
      77,    78,    79,    80,    -1,    -1,   139,    -1,    85,    86,
      -1,    88,    89,    -1,    -1,    -1,   626,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   646,    -1,    -1,    -1,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     6,    -1,     8,     9,    -1,    11,
      -1,    13,   139,    15,    16,    -1,    -1,    19,    20,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    -1,    59,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    81,    82,    81,
      82,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,   135,    -1,   137,   138,   139,   140,     6,
      -1,     8,     9,    -1,    11,    -1,    13,    -1,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    -1,    59,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,   135,    -1,
     137,   138,     6,   140,     8,     9,    -1,    11,    -1,    13,
      -1,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,   135,    -1,   137,   138,     6,   140,     8,     9,    -1,
      11,    -1,    13,    -1,    15,    16,    -1,    -1,    19,    20,
      -1,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,   135,    -1,   137,   138,     6,   140,
       8,     9,    -1,    11,    -1,    13,    -1,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    25,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      -1,    59,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,   135,    -1,   137,
     138,     6,   140,     8,     9,    -1,    11,    -1,    13,    -1,
      15,    16,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
     135,    -1,   137,   138,     6,   140,     8,     9,    -1,    11,
      -1,    13,    -1,    15,    16,    -1,    -1,    19,    20,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    -1,    59,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,   135,    -1,   137,   138,     6,   140,     8,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,
      19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,   135,    -1,   137,   138,
       6,   140,     8,     9,    -1,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    68,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,   125,
     126,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,   135,
      -1,   137,   138,     6,   140,     8,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    -1,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,   135,    -1,   137,   138,     6,   140,     8,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,   135,    -1,   137,   138,     6,
     140,     8,     9,    -1,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    68,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,   125,   126,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,   135,    -1,
     137,   138,     6,   140,     8,     9,    -1,    11,    -1,    -1,
      -1,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,
      23,   135,    -1,   137,   138,    -1,   140,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,
     133,    23,   135,    -1,   137,    -1,    -1,   140,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    23,   135,    -1,   137,    -1,    -1,   140,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
     131,   132,   133,    23,   135,    -1,   137,    -1,    -1,   140,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,     6,    -1,     8,
       9,    -1,   122,    -1,    -1,   125,   126,    -1,    -1,    -1,
      -1,   131,   132,   133,    23,   135,    -1,    -1,    -1,    -1,
     140,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,   131,   132,   133,    23,   135,   136,    -1,    -1,
      -1,   140,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,     6,
      -1,     8,     9,    -1,   122,    -1,    -1,   125,   126,    -1,
      -1,    -1,    -1,   131,   132,   133,    23,   135,    -1,    -1,
      -1,    -1,   140,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
       6,    -1,     8,     9,    -1,   122,    -1,    -1,   125,   126,
      -1,    -1,    -1,    -1,   131,   132,   133,    23,   135,    -1,
      -1,    -1,    -1,   140,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,     6,    -1,     8,     9,    -1,   122,    -1,    -1,   125,
     126,    -1,    -1,    -1,    -1,   131,   132,   133,    23,   135,
      -1,    -1,    -1,    -1,   140,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,     6,    -1,     8,     9,    -1,   122,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,    23,
     135,    -1,    -1,    -1,    -1,   140,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,     6,    -1,     8,     9,    -1,   122,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,
      23,   135,    -1,    -1,    -1,    -1,   140,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,     6,    -1,     8,     9,    -1,   122,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,
     133,    23,   135,    -1,    -1,    -1,    -1,   140,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,     3,     4,     5,    -1,    81,
      82,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    40,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,   125,   126,    -1,    -1,    85,    86,   131,
     132,   133,    -1,   135,    -1,    -1,    -1,    -1,   140,     3,
       4,     5,    -1,   101,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    89,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   101,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     3,     4,     5,    -1,    -1,    -1,   137,
      -1,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     3,     4,     5,
      -1,    -1,    -1,   137,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     3,     4,     5,    -1,    -1,    -1,   137,    -1,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     3,     4,     5,    -1,    -1,
      -1,   137,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     3,
       4,     5,    -1,    -1,    -1,   137,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     3,     4,     5,    -1,    -1,   136,    -1,
      -1,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     3,     4,     5,
      -1,    -1,   136,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     3,     4,     5,    -1,    -1,   136,    -1,    -1,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     3,     4,     5,    -1,    -1,
     136,    -1,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     3,
       4,     5,    -1,    -1,   136,    -1,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     3,     4,     5,    -1,    -1,   136,    -1,
      -1,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     3,     4,     5,
      -1,    -1,   136,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     3,     4,     5,    -1,    -1,   136,    -1,    -1,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     3,     4,     5,    -1,    -1,
     136,    -1,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    83,    -1,    85,    86,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     3,     4,     5,    -1,    40,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    -1,    -1,    83,
      -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      40,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     3,   101,     5,
      -1,    40,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,   101,    -1,    -1,    40,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     3,   101,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    89,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,   101,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    89,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,   101,    -1,    85,    86,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,   118,   101,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    40,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,   101,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,   116,   117,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   143,   144,     0,     6,     8,     9,    11,    13,    15,
      16,    19,    20,    23,    30,    31,    33,    34,    35,    36,
      37,    38,    39,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    53,    54,    55,    56,    57,    59,
      64,    65,    66,    68,    71,    72,    73,    74,    81,    82,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   125,   126,   131,   132,   133,   135,   137,
     138,   140,   145,   148,   149,   150,   151,   166,   167,   169,
     172,   174,   176,   220,   221,   222,   229,   232,   236,   237,
     239,   240,   244,   245,   246,   247,   248,   249,   254,   259,
     261,   262,   135,   137,   236,   137,   236,   156,   153,   217,
     236,   135,   135,   135,   227,   154,   170,   111,   140,   203,
     204,   236,   236,   135,   135,   110,   222,   223,   224,   247,
     248,   254,   236,   236,   236,   137,   220,   236,   240,   111,
     205,   155,   135,   109,   135,   165,   152,    13,    13,   236,
     157,   236,   135,   110,   222,   239,   240,   239,   236,   236,
     236,   236,   236,   236,   236,   135,   236,   236,   236,   236,
     236,   236,   146,   138,   135,   135,   110,   110,    87,     3,
       4,     5,    40,    75,    76,    77,    78,    79,    80,    85,
      86,    88,    89,   101,   118,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   137,    81,    82,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     117,   135,    84,   241,   242,   134,   138,   140,   248,   122,
     236,   257,   258,   137,   137,   135,   148,   116,   137,   240,
     236,   136,   236,   135,   122,   168,   138,   237,   240,   116,
     137,   240,   260,    42,   240,   255,   256,    87,   135,   228,
      84,   248,   137,   137,   117,   116,   137,   135,   163,   164,
     240,   109,   137,   135,   262,   137,   136,    87,   122,   201,
     202,   220,   240,   136,    71,   139,   147,   148,   166,   167,
     236,   236,   220,   240,   173,    32,   177,   110,   244,   248,
     254,   236,   236,   236,   223,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   122,
     236,   201,   110,   138,   244,   251,   252,   253,   242,   236,
     250,   236,   238,   240,    83,   136,   116,   234,   110,   185,
      53,   236,   136,   136,   136,   218,   219,   236,   110,   236,
     204,   116,   136,   135,   116,   136,   244,   201,   251,     9,
     110,   125,   126,   229,   230,   231,   111,   236,   116,   136,
     136,   236,    67,   137,   110,   238,   136,   116,   135,   139,
     136,    10,    10,    32,   175,   110,   179,   222,   138,   135,
     135,   248,   139,   119,    43,   240,   136,   236,   135,   243,
     134,   138,   141,   139,   122,   236,   122,   236,   117,   116,
     136,   135,   137,   116,   171,   139,   240,   255,   256,   117,
     136,   225,   135,    87,   230,   230,   117,   136,   164,   137,
     136,   158,   122,   220,   240,   136,   119,   148,   238,   122,
     181,   238,   222,    60,   178,   116,   206,   201,   201,   236,
     223,   139,   201,   250,   236,   238,   238,    83,   230,   110,
     119,   148,   184,   236,   218,   236,   135,   136,   236,    84,
     226,   230,   233,   235,   110,   230,   119,   138,   186,   119,
     148,   191,   135,   238,   137,   146,   192,    83,   180,   238,
     180,   179,   138,   222,    14,    48,    52,    57,    61,    62,
      63,    64,   139,   207,   211,   212,   213,   214,   216,   136,
     136,   228,   136,   141,   139,   122,   236,   117,   146,   136,
     137,     9,   110,   198,   199,   200,   251,    83,   136,   116,
     234,   137,   187,   137,   187,   146,   222,   194,    21,    22,
     196,   181,   136,   136,   206,   110,   111,   215,    35,   214,
     116,   137,   238,   230,    24,   137,   218,   136,   116,   111,
     122,   230,   230,   187,    12,    17,    28,   187,   139,    29,
     111,    21,    22,   197,   148,   193,   119,   148,   183,   183,
     139,   117,   117,   116,   137,   208,   110,   137,   136,   262,
     200,   117,   111,    83,    28,   236,   119,   137,   190,   137,
     139,   137,   136,   119,   195,    27,   135,   146,   230,   230,
     111,   168,   117,   119,   148,   182,   111,   122,   230,   117,
     230,   137,   190,   189,   262,   146,   135,   137,   236,    26,
     117,   110,   230,   146,   117,   111,   230,   188,   146,    67,
     159,   160,   161,   236,   136,   137,   230,   209,    25,   230,
     117,   146,   162,   161,   136,   148,   135,   137,   230,   135,
     119,   198,   222,   146,   136,   111,   137,   210,   262,   136,
     262
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (context, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (PHP_context* context);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (PHP_context* context)
#else
int
yyparse (context)
    PHP_context* context;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 313 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(body, (yyvsp[0]), AST_statement_list);

			// If there are any remaining comments, add them as a NOP
			if(!context->last_comments.empty())
				body->push_back(NEW(AST_nop, ()));
		
			AST_signature* signature = NEW(AST_signature, ("%run%"));
			signature->method_mod = AST_method_mod::new_STATIC();

			context->php_script->get_class_def("%MAIN%")->add_member(NEW(AST_method, (signature, body)));
			
			// Make %MAIN% the last class definition
			AST_class_def* main = context->php_script->class_defs->front();
			context->php_script->class_defs->pop_front();
			context->php_script->class_defs->push_back(main);
		;}
    break;

  case 3:
#line 337 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(statement_list, (yyvsp[-1]), AST_statement_list);

			// Ignore null statements
			if((yyvsp[0]))
			{
				CAST_UNSAFE(statement, (yyvsp[0]), AST_statement);
			
				if(statement == NULL)
				{
					CAST_AST(statements, (yyvsp[0]), AST_statement_list);
					statement_list->push_back_all(statements);
				}
				else
				{
					statement_list->push_back(statement);
				}
			}
				
			(yyval) = statement_list;
		;}
    break;

  case 4:
#line 359 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_statement_list; ;}
    break;

  case 5:
#line 369 "src/generated_src/php_parser.ypp"
    {
			(yyval) = (yyvsp[0]); 
		;}
    break;

  case 6:
#line 373 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 7:
#line 375 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 8:
#line 377 "src/generated_src/php_parser.ypp"
    {
			// Note: we never generate K_HALT_COMPILER
			(yyval) = NULL;
		;}
    break;

  case 9:
#line 390 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(statement_list, (yyvsp[-1]), AST_statement_list);

			// Ignore null statements
			if((yyvsp[0]))
			{
				CAST_UNSAFE(statement, (yyvsp[0]), AST_statement);

				if(statement == NULL)
				{
					CAST_AST(statements, (yyvsp[0]), AST_statement_list);
					statement_list->push_back_all(statements);
				}
				else
				{
					statement_list->push_back(statement);
				}
			}

			(yyval) = statement_list;
		;}
    break;

  case 10:
#line 412 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_statement_list; ;}
    break;

  case 11:
#line 420 "src/generated_src/php_parser.ypp"
    {
			(yyval) = (yyvsp[0]);
		;}
    break;

  case 12:
#line 424 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 13:
#line 426 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 14:
#line 428 "src/generated_src/php_parser.ypp"
    {
			// Note: we never generate K_HALT_COMPILER
			(yyval) = NULL;
		;}
    break;

  case 15:
#line 439 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 16:
#line 448 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_if, ()); ;}
    break;

  case 17:
#line 457 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_foreach, ()); ;}
    break;

  case 18:
#line 465 "src/generated_src/php_parser.ypp"
    { 
			(yyval) = (yyvsp[0]);
		;}
    break;

  case 19:
#line 469 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_if, (yyvsp[-6]), AST_if);
			CAST_AST(expr, (yyvsp[-4]), AST_expr);
			CAST_STATEMENT_VECTOR(iftrue, (yyvsp[-2]));
			CAST_AST(elseif, (yyvsp[-1]), AST_if);
			CAST_STATEMENT_VECTOR(iffalse, (yyvsp[0]));
			
			new_if->expr = expr;
			new_if->iftrue = iftrue;
			
			if(elseif)
			{
				AST_statement_list* new_false = new AST_statement_list;
				new_false->push_back(elseif);
				
				/* 
				 * Nest the elseif part
				 *
				 * We must add it to the most deeply nested if we can find
				 * Note that _if_ any of the nested ifs (elseifs) has a false
				 * branch, then this consists of a single instruction, an AST_if*.
				 * So, the dynamic_cast is guaranteed to succeed.
				 *
				 * This is similar to the code in elseif_list. 
				 */ 
				while(!elseif->iffalse->empty())
					elseif = dynamic_cast<AST_if*>(elseif->iffalse->front());
				elseif->iffalse = iffalse;
				
				new_if->iffalse = new_false;
			}
			else
			{
				new_if->iffalse = iffalse;
			}

			(yyval) = new_if;
		;}
    break;

  case 20:
#line 508 "src/generated_src/php_parser.ypp"
    {
			// Duplication of logic above for K_IF.
			CAST_AST(new_if, (yyvsp[-9]), AST_if);
			CAST_AST(expr, (yyvsp[-7]), AST_expr);
			CAST_STATEMENT_VECTOR(iftrue, (yyvsp[-4]));
			CAST_AST(elseif, (yyvsp[-3]), AST_if);
			CAST_STATEMENT_VECTOR(iffalse, (yyvsp[-2]));
			
			new_if->expr = expr;
			new_if->iftrue = iftrue;
		
			if(elseif)
			{
				AST_statement_list* new_false = new AST_statement_list;
				new_false->push_back(elseif);

				while(!elseif->iffalse->empty())
					elseif = dynamic_cast<AST_if*>(elseif->iffalse->front());
				elseif->iffalse = iffalse;
				
				new_if->iffalse = new_false;	
			}
			else
			{
				new_if->iffalse = iffalse;
			}
	
			(yyval) = new_if;
		;}
    break;

  case 21:
#line 537 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_while, ());;}
    break;

  case 22:
#line 538 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_while, (yyvsp[-5]), AST_while);
			CAST_AST(expr, (yyvsp[-2]), AST_expr);
			CAST_AST(body, (yyvsp[0]), AST_statement_list);

			new_while->expr = expr;
			new_while->statements = body;

			(yyval) = new_while;
		;}
    break;

  case 23:
#line 548 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_do, ());;}
    break;

  case 24:
#line 549 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_do, (yyvsp[-7]), AST_do);
			CAST_STATEMENT_VECTOR(body, (yyvsp[-5]));
			CAST_AST(expr, (yyvsp[-2]), AST_expr);
			
			new_do->statements = body;
			new_do->expr = expr;
			
			(yyval) = new_do;
		;}
    break;

  case 25:
#line 559 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_for, ());;}
    break;

  case 26:
#line 560 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_for, (yyvsp[-9]), AST_for);
			CAST_AST(init, (yyvsp[-6]), AST_expr);
			CAST_AST(cond, (yyvsp[-4]), AST_expr);
			CAST_AST(incr, (yyvsp[-2]), AST_expr);
			CAST_STATEMENT_VECTOR(stmts, (yyvsp[0]));
			
			new_for->init = init;
			new_for->cond = cond;
			new_for->incr = incr;
			new_for->statements = stmts;
			
			(yyval) = new_for;
		;}
    break;

  case 27:
#line 574 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_switch, ());;}
    break;

  case 28:
#line 575 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_switch, (yyvsp[-5]), AST_switch);
			CAST_AST(expr, (yyvsp[-2]), AST_expr);
			CAST_AST(cases, (yyvsp[0]), AST_switch_case_list);
			
			new_switch->expr = expr;
			new_switch->switch_cases = cases;
			
			(yyval) = new_switch;
		;}
    break;

  case 29:
#line 586 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_break, (NULL)); ;}
    break;

  case 30:
#line 588 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[-1]), AST_expr);
			
			(yyval) = NEW(AST_break, (expr));
		;}
    break;

  case 31:
#line 594 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_continue, (NULL)); ;}
    break;

  case 32:
#line 596 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-1]), AST_expr);

			(yyval) = NEW(AST_continue, (expr));
		;}
    break;

  case 33:
#line 602 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_return, (NULL)); ;}
    break;

  case 34:
#line 604 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-1]), AST_expr);

			(yyval) = NEW(AST_return, (expr));
		;}
    break;

  case 35:
#line 610 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-1]), AST_expr);

			(yyval) = NEW(AST_return, (expr));
		;}
    break;

  case 36:
#line 616 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-1]), List<AST_variable_name*>);
		
			AST_statement_list* globals = new AST_statement_list;
			List<AST_variable_name*>::const_iterator i;
			
			for(i = list->begin(); i != list->end(); i++)
			{
				AST_variable* gv = NEW(AST_variable, (*i)); // global var
				gv->target = NEW(Token_class_name, (new String("%MAIN%")));
				AST_variable_name* iclone = (*i)->deep_clone();
				AST_variable* lv = NEW(AST_variable, (iclone)); // local var
				AST_assignment* gd = NEW(AST_assignment, (lv, true, gv)); // global declaration
				gd->attrs->set("phc.unparser.is_global_stmt", new Boolean(true));
				globals->push_back(NEW(AST_eval_expr, (gd)));
			}
		
			(yyval) = globals;
		;}
    break;

  case 37:
#line 636 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 38:
#line 638 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 39:
#line 640 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[0]), String);
			Token_string* scalar = NEW(Token_string, (str, str));
			AST_expr* fn = NEW(AST_method_invocation, ("echo", scalar));
	
			(yyval) = NEW(AST_eval_expr, (fn));
		;}
    break;

  case 40:
#line 648 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[-1]), AST_expr);
			
			(yyval) = NEW(AST_eval_expr, (expr));
		;}
    break;

  case 41:
#line 654 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-1]), Token_string); 
			AST_method_invocation* fn = NEW(AST_method_invocation, ("use", expr));
			
			(yyval) = NEW(AST_eval_expr, (fn));
		;}
    break;

  case 42:
#line 661 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(vars, (yyvsp[-2]), List<AST_variable*>);
			AST_statement_list* statements = new AST_statement_list;
			List<AST_variable*>::const_iterator i;
			
			for(i = vars->begin(); i != vars->end(); i++)
				statements->push_back(NEW(AST_unset, (*i)));

			(yyval) = statements;
		;}
    break;

  case 43:
#line 672 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_foreach, (yyvsp[-7]), AST_foreach);
			CAST_AST(expr, (yyvsp[-5]), AST_expr);
			CAST_AST(var1, (yyvsp[-3]), AST_variable);
			CAST_AST(var2, (yyvsp[-2]), AST_variable);
			CAST_STATEMENT_VECTOR(body, (yyvsp[0]));
	
			new_foreach->expr = expr;
			new_foreach->statements = body;
	
			if(var2)
			{
				if(var1->attrs->get_boolean("phc.parser.is_ref")->value())
				{
					phc_error(ERR_FOREACH_KEY_REF, var1->get_filename(), var1->get_line_number());
				}
			
				new_foreach->key = var1;
				new_foreach->is_ref = var2->attrs->get_boolean("phc.parser.is_ref")->value();
				new_foreach->val = var2;
			}
			else
			{
				new_foreach->key = NULL;
				new_foreach->is_ref = var1->attrs->get_boolean("phc.parser.is_ref")->value();
				new_foreach->val = var1;
			}

			(yyval) = new_foreach;
		;}
    break;

  case 44:
#line 703 "src/generated_src/php_parser.ypp"
    { 
			// Duplication of the logic in the previous rule
			CAST_AST(new_foreach, (yyvsp[-7]), AST_foreach);
			CAST_AST(expr, (yyvsp[-5]), AST_expr);
			CAST_AST(var1, (yyvsp[-3]), AST_variable);
			CAST_AST(var2, (yyvsp[-2]), AST_variable);
			CAST_STATEMENT_VECTOR(body, (yyvsp[0]));
	
			new_foreach->expr = expr;
			new_foreach->statements = body;
	
			if(var2)
			{
				if(var1->attrs->get_boolean("phc.parser.is_ref")->value())
				{
					phc_error(ERR_FOREACH_KEY_REF, var1->get_filename(), var1->get_line_number());
				}
			
				new_foreach->key = var1;
				new_foreach->is_ref = var2->attrs->get_boolean("phc.parser.is_ref")->value();
				new_foreach->val = var2;
			}
			else
			{
				new_foreach->key = NULL;
				new_foreach->is_ref = var1->attrs->get_boolean("phc.parser.is_ref")->value();
				new_foreach->val = var1;
			}

			(yyval) = new_foreach;
		;}
    break;

  case 45:
#line 734 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_declare, ());;}
    break;

  case 46:
#line 735 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_declare, (yyvsp[-5]), AST_declare);
			CAST_AST(directives, (yyvsp[-2]), AST_directive_list);
			CAST_STATEMENT_VECTOR(statements, (yyvsp[0]));

			new_declare->directives = directives;
			new_declare->statements = statements;

			(yyval) = new_declare;
		;}
    break;

  case 47:
#line 746 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 48:
#line 747 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_try, ());;}
    break;

  case 49:
#line 747 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_catch, ());;}
    break;

  case 50:
#line 748 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(new_try, (yyvsp[-10]), AST_try);
			CAST_STATEMENT_VECTOR(try_stat, (yyvsp[-8]));
			CAST_AST(new_catch, (yyvsp[-7]), AST_catch);
			CAST_AST(class_name, (yyvsp[-4]), Token_class_name);
			CAST_STR(var, (yyvsp[-3]), Token_variable_name);
			CAST_STATEMENT_VECTOR(catch_stat, (yyvsp[-1]));
			CAST_AST(additional_catches, (yyvsp[0]), AST_catch_list);
			
			new_catch->class_name = class_name;
			new_catch->variable_name = var;
			new_catch->statements = catch_stat;

			AST_catch_list* all_catches = new AST_catch_list;
			all_catches->push_back(new_catch);
			all_catches->push_back_all(additional_catches);
		
			new_try->statements = try_stat;
			new_try->catches = all_catches;
		
			(yyval) = new_try;
		;}
    break;

  case 51:
#line 771 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-1]), AST_expr);
			
			(yyval) = NEW(AST_throw, (expr)); 
		;}
    break;

  case 52:
#line 783 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 53:
#line 785 "src/generated_src/php_parser.ypp"
    {
			AST_catch_list* catches = new AST_catch_list;
			(yyval) = catches; 
		;}
    break;

  case 54:
#line 796 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(c, (yyvsp[0]), AST_catch);
			
			AST_catch_list* catches = new AST_catch_list;
			catches->push_back(c);
			
			(yyval) = catches;
		;}
    break;

  case 55:
#line 805 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(catches, (yyvsp[-1]), AST_catch_list);
			CAST_AST(c, (yyvsp[0]), AST_catch);
			
			catches->push_back(c);
			
			(yyval) = catches; 
		;}
    break;

  case 56:
#line 819 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_catch, ());;}
    break;

  case 57:
#line 820 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_catch, (yyvsp[-6]), AST_catch);
			CAST_AST(class_name, (yyvsp[-3]), Token_class_name);
			CAST_STR(var, (yyvsp[-2]), Token_variable_name);
			CAST_STATEMENT_VECTOR(stat, (yyvsp[0]));
			
			new_catch->class_name = class_name;
			new_catch->variable_name = var;
			new_catch->statements = stat;
			
			(yyval) = new_catch; 
		;}
    break;

  case 58:
#line 839 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(var, (yyvsp[0]), AST_variable);

			List<AST_variable*>* vars = new List<AST_variable*>;
			vars->push_back(var);
			(yyval) = vars;
		;}
    break;

  case 59:
#line 847 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(vars, (yyvsp[-2]), List<AST_variable*>);
			CAST_AST(var, (yyvsp[0]), AST_variable);
		
			vars->push_back(var);
			(yyval) = vars; 
		;}
    break;

  case 60:
#line 861 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[0]), AST_variable);
			EXPECT_VARIABLE((yyvsp[0]));
			(yyval) = var;
		;}
    break;

  case 61:
#line 873 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[0]), String);
			(yyval) = NEW(Token_string, (str, str));
		;}
    break;

  case 62:
#line 878 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[-1]), String);
			(yyval) = NEW(Token_string, (str, str))
		;}
    break;

  case 63:
#line 891 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 64:
#line 901 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 65:
#line 909 "src/generated_src/php_parser.ypp"
    { (yyval) = new Integer(0); ;}
    break;

  case 66:
#line 911 "src/generated_src/php_parser.ypp"
    { (yyval) = new Integer(1); ;}
    break;

  case 67:
#line 922 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_method, ());;}
    break;

  case 68:
#line 922 "src/generated_src/php_parser.ypp"
    {context->current_method = dynamic_cast<String*>((yyvsp[0]));;}
    break;

  case 69:
#line 923 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(fn, (yyvsp[-8]), AST_method);
			CAST_AST(is_ref, (yyvsp[-6]), Integer);
			CAST_STR(name, (yyvsp[-5]), Token_method_name);
			CAST_AST(params, (yyvsp[-2]), AST_formal_parameter_list); 
			CAST_AST(body, (yyvsp[0]), AST_statement_list);
		
			AST_signature* signature = NEW(AST_signature, (AST_method_mod::new_STATIC(), is_ref->value(), name, params));
			fn->signature = signature;
			fn->statements = body;

			context->php_script->get_class_def("%MAIN%")->add_member(fn);	

			(yyval) = NULL;
		;}
    break;

  case 70:
#line 947 "src/generated_src/php_parser.ypp"
    {context->current_class = dynamic_cast<String*>((yyvsp[0]));;}
    break;

  case 71:
#line 948 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(new_class, (yyvsp[-7]), AST_class_def);
			CAST_STR(name, (yyvsp[-6]), Token_class_name);
			CAST_AST(extends, (yyvsp[-4]), Token_class_name);
			CAST_AST(implements, (yyvsp[-3]), Token_interface_name_list);
			CAST_AST(members, (yyvsp[-1]), AST_member_list);

			new_class->class_name = name;
			new_class->extends = extends;
			new_class->implements = implements;
			new_class->members = members;

			context->php_script->class_defs->push_back(new_class);

			(yyval) = NULL;
		;}
    break;

  case 72:
#line 965 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(idef, (yyvsp[-5]), AST_interface_def);
			CAST_STR(name, (yyvsp[-4]), Token_interface_name);
			CAST_AST(extends, (yyvsp[-3]), Token_interface_name_list);
			CAST_AST(members, (yyvsp[-1]), AST_member_list);

			idef->interface_name = name;
			idef->extends = extends;
			idef->members = members;
			
			context->php_script->interface_defs->push_back(idef);

			(yyval) = NULL;
		;}
    break;

  case 73:
#line 995 "src/generated_src/php_parser.ypp"
    { 
			AST_class_mod* mod = NEW(AST_class_mod, (false, false));
			(yyval) = NEW(AST_class_def, (mod));
		;}
    break;

  case 74:
#line 1000 "src/generated_src/php_parser.ypp"
    { 
			AST_class_mod* mod = NEW(AST_class_mod, (true, false)); 
			(yyval) = NEW(AST_class_def, (mod));
		;}
    break;

  case 75:
#line 1005 "src/generated_src/php_parser.ypp"
    { 
			AST_class_mod* mod = NEW(AST_class_mod, (false, true)); 
			(yyval) = NEW(AST_class_def, (mod));
		;}
    break;

  case 76:
#line 1016 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 77:
#line 1018 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 78:
#line 1026 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_interface_def, ()); ;}
    break;

  case 79:
#line 1034 "src/generated_src/php_parser.ypp"
    { (yyval) = new Token_interface_name_list; ;}
    break;

  case 80:
#line 1036 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 81:
#line 1046 "src/generated_src/php_parser.ypp"
    { (yyval) = new Token_interface_name_list; ;}
    break;

  case 82:
#line 1048 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 83:
#line 1056 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[0]), Token_class_name);

			Token_interface_name* ifn = NEW(Token_interface_name, (class_name->value));
		
			Token_interface_name_list* names;
			names = new Token_interface_name_list;
			names->push_back(ifn);
			
			(yyval) = names;
		;}
    break;

  case 84:
#line 1068 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(names, (yyvsp[-2]), Token_interface_name_list);
			CAST_AST(class_name, (yyvsp[0]), Token_class_name);
			
			Token_interface_name* ifn = NEW(Token_interface_name, (class_name->value));
			names->push_back(ifn);
			
			(yyval) = names;
		;}
    break;

  case 85:
#line 1084 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 86:
#line 1086 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 87:
#line 1094 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[0]), AST_variable);
			EXPECT_VARIABLE((yyvsp[0]));
			(yyval) = var;
		;}
    break;

  case 88:
#line 1100 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[0]), AST_variable);
			EXPECT_VARIABLE((yyvsp[0]));
			var->attrs->set("phc.parser.is_ref", new Boolean(true));
			(yyval) = var; 
		;}
    break;

  case 89:
#line 1113 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 90:
#line 1115 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 91:
#line 1123 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 92:
#line 1125 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 93:
#line 1133 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 94:
#line 1135 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 95:
#line 1143 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[-2]), Token_directive_name);
			CAST_AST(value, (yyvsp[0]), AST_expr);

			AST_directive_list* dirs = new AST_directive_list;
			AST_directive* dir = NEW(AST_directive, (name, value));
			
			dirs->push_back(dir);
			(yyval) = dirs;
		;}
    break;

  case 96:
#line 1154 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(dirs, (yyvsp[-4]), AST_directive_list);
			CAST_STR(name, (yyvsp[-2]), Token_directive_name);	
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_directive* dir = NEW(AST_directive, (name, value));
			dirs->push_back(dir);
			(yyval) = dirs;
		;}
    break;

  case 97:
#line 1170 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 98:
#line 1172 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 99:
#line 1174 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 100:
#line 1176 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 101:
#line 1184 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_switch_case_list; ;}
    break;

  case 102:
#line 1185 "src/generated_src/php_parser.ypp"
    {(yyvsp[-2]) = NEW(AST_switch_case, ());;}
    break;

  case 103:
#line 1186 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(switch_case, (yyvsp[-4]), AST_switch_case);	
			CAST_AST(cases, (yyvsp[-5]), AST_switch_case_list);
			CAST_AST(expr, (yyvsp[-3]), AST_expr);
			CAST_AST(body, (yyvsp[0]), AST_statement_list);
			
			switch_case->statements = body;
			switch_case->expr = expr;
			
			cases->push_back(switch_case);
			
			(yyval) = cases;
		;}
    break;

  case 104:
#line 1199 "src/generated_src/php_parser.ypp"
    {(yyvsp[-1]) = NEW(AST_switch_case, ());;}
    break;

  case 105:
#line 1200 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(switch_case, (yyvsp[-3]), AST_switch_case);
			CAST_AST(cases, (yyvsp[-4]), AST_switch_case_list);
			CAST_AST(body, (yyvsp[0]), AST_statement_list);

			switch_case->statements = body;
			switch_case->expr = NULL;
			
			cases->push_back(switch_case);
			
			(yyval) = cases;
		;}
    break;

  case 106:
#line 1219 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 107:
#line 1221 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 108:
#line 1229 "src/generated_src/php_parser.ypp"
    {
			CAST_STATEMENT_VECTOR(body, (yyvsp[0]));
			
			(yyval) = body;
		;}
    break;

  case 109:
#line 1235 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 110:
#line 1243 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 111:
#line 1244 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_if, ());;}
    break;

  case 112:
#line 1245 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(elseif, (yyvsp[-6]), AST_if);
			CAST_AST(nested_if, (yyvsp[-5]), AST_if);
			CAST_AST(expr, (yyvsp[-2]), AST_expr);
			CAST_STATEMENT_VECTOR(stat, (yyvsp[0]));
			
			AST_statement_list* empty = new AST_statement_list;
			
			nested_if->expr = expr;
			nested_if->iftrue = stat;
			nested_if->iffalse = empty;
			nested_if->attrs->set("phc.unparser.is_elseif", new Boolean(true));

			if(elseif)
			{
				AST_statement_list* iffalse = new AST_statement_list;
				iffalse->push_back(nested_if);
				
				/*
				 * Nest the elseif.
				 * This is similar to the code in unticked_statement for K_IF.
				 */
				AST_if* p = elseif;
				while(!p->iffalse->empty())
					p = dynamic_cast<AST_if*>(p->iffalse->front());
				p->iffalse = iffalse;		
						
				(yyval) = elseif;
			}
			else
			{
				(yyval) = nested_if;
			}
		;}
    break;

  case 113:
#line 1288 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 114:
#line 1289 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_if, ());;}
    break;

  case 115:
#line 1290 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(elseif, (yyvsp[-7]), AST_if);
			CAST_AST(nested_if, (yyvsp[-6]), AST_if);
			CAST_AST(expr, (yyvsp[-3]), AST_expr);
			CAST_STATEMENT_VECTOR(stat, (yyvsp[0]));
			
			AST_statement_list* empty = new AST_statement_list;
			
			nested_if->expr = expr;
			nested_if->iftrue = stat;
			nested_if->iffalse = empty;
			nested_if->attrs->set("phc.unparser.is_elseif", new Boolean(true));

			if(elseif)
			{
				AST_statement_list* iffalse = new AST_statement_list;
				iffalse->push_back(nested_if);
				
				AST_if* p = elseif;
				while(!p->iffalse->empty())
					p = dynamic_cast<AST_if*>(p->iffalse->front());
				p->iffalse = iffalse;		
						
				(yyval) = elseif;
			}
			else
			{
				(yyval) = nested_if;
			}
		;}
    break;

  case 116:
#line 1327 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 117:
#line 1329 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 118:
#line 1339 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 119:
#line 1341 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 120:
#line 1349 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 121:
#line 1351 "src/generated_src/php_parser.ypp"
    { 
			AST_formal_parameter_list* params = new AST_formal_parameter_list;
			(yyval) = params;
		;}
    break;

  case 122:
#line 1364 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[-1]), AST_type);
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, name)));
			
			(yyval) = params; 
		;}
    break;

  case 123:
#line 1376 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[-2]), AST_type);
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name)));
			
			(yyval) = params; 
		;}
    break;

  case 124:
#line 1388 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[-4]), AST_type);
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[0]), AST_expr);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 125:
#line 1401 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[-3]), AST_type);
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[0]), AST_expr);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, false, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 126:
#line 1414 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[-3]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[-1]), AST_type);
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, name)));
			
			(yyval) = params; 
		;}
    break;

  case 127:
#line 1424 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[-4]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[-2]), AST_type);
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name)));
			
			(yyval) = params; 
		;}
    break;

  case 128:
#line 1434 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[-6]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[-4]), AST_type);
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[0]), AST_expr);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 129:
#line 1445 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[-5]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[-3]), AST_type);
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[0]), AST_expr);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, false, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 130:
#line 1462 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_type, (false, NULL)); ;}
    break;

  case 131:
#line 1464 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(class_name, (yyvsp[0]), Token_class_name);
			(yyval) = NEW(AST_type, (false, class_name)); 
		;}
    break;

  case 132:
#line 1469 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(AST_type, (true, NULL));
		;}
    break;

  case 133:
#line 1479 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 134:
#line 1481 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_actual_parameter_list; ;}
    break;

  case 135:
#line 1489 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(arg, (yyvsp[0]), AST_expr);
			
			AST_actual_parameter_list* list = new AST_actual_parameter_list;
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 136:
#line 1497 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(arg, (yyvsp[0]), AST_expr);
			
			AST_actual_parameter_list* list = new AST_actual_parameter_list;
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 137:
#line 1505 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_actual_parameter_list* list = new AST_actual_parameter_list;
			list->push_back(NEW(AST_actual_parameter, (true, expr)));
			(yyval) = list; 
		;}
    break;

  case 138:
#line 1513 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-2]), AST_actual_parameter_list);
			CAST_AST(arg, (yyvsp[0]), AST_expr);
			
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 139:
#line 1521 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-2]), AST_actual_parameter_list);
			CAST_AST(arg, (yyvsp[0]), AST_expr);
			
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 140:
#line 1529 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(list, (yyvsp[-3]), AST_actual_parameter_list);
			CAST_AST(arg, (yyvsp[0]), AST_expr);
			
			list->push_back(NEW(AST_actual_parameter, (true, arg)));
			(yyval) = list; 
		;}
    break;

  case 141:
#line 1543 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-2]), List<AST_variable_name*>);
			CAST_AST(var_name, (yyvsp[0]), AST_variable_name);

			list->push_back(var_name);
			(yyval) = list;
		;}
    break;

  case 142:
#line 1551 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var_name, (yyvsp[0]), AST_variable_name);
			
			List<AST_variable_name*>* list = new List<AST_variable_name*>;
			list->push_back(var_name);
			
			(yyval) = list;
		;}
    break;

  case 143:
#line 1566 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(var, (yyvsp[0]), Token_variable_name);
			(yyval) = var; 
		;}
    break;

  case 144:
#line 1571 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_reflection, (expr));
		;}
    break;

  case 145:
#line 1576 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[-1]), AST_expr);
			expr->attrs->set("phc.unparser.needs_curlies", new Boolean(true));
			(yyval) = NEW(AST_reflection, (expr));
		;}
    break;

  case 146:
#line 1588 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-2]), AST_statement_list);
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			
			AST_static_declaration* v = NEW(AST_static_declaration, (name, NULL));
			list->push_back(v);
			
			(yyval) = list;
		;}
    break;

  case 147:
#line 1598 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-4]), AST_statement_list);
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(value, (yyvsp[0]), AST_expr);

			AST_static_declaration* v = NEW(AST_static_declaration, (name, value));
			list->push_back(v);
			
			(yyval) = list;
		;}
    break;

  case 148:
#line 1609 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			
			AST_statement_list* list = new AST_statement_list;
			AST_static_declaration* v = NEW(AST_static_declaration, (name, NULL));
			list->push_back(v);
			
			(yyval) = list;
		;}
    break;

  case 149:
#line 1619 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_statement_list* list = new AST_statement_list;
			AST_static_declaration* v = NEW(AST_static_declaration, (name, value));
			list->push_back(v);

			(yyval) = list;
		;}
    break;

  case 150:
#line 1636 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(member_list, (yyvsp[-1]), AST_member_list);		
			CAST_AST(members, (yyvsp[0]), AST_member_list);
			
			member_list->push_back_all(members);
			
			(yyval) = member_list;			
		;}
    break;

  case 151:
#line 1645 "src/generated_src/php_parser.ypp"
    {
			(yyval) = new AST_member_list;
		;}
    break;

  case 152:
#line 1655 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(modifiers, (yyvsp[-2]), AST_attr_mod);
			CAST_AST(members, (yyvsp[-1]), AST_member_list);	

			AST_member_list::iterator i;
			for(i = members->begin(); i != members->end(); i++)
			{
				CAST_AST(attribute, *i, AST_attribute);
				attribute->attr_mod = modifiers->deep_clone();
			}

			(yyval) = members;
		;}
    break;

  case 153:
#line 1669 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 154:
#line 1670 "src/generated_src/php_parser.ypp"
    {(yyvsp[0]) = NEW(AST_method, ());;}
    break;

  case 155:
#line 1670 "src/generated_src/php_parser.ypp"
    {context->current_method = dynamic_cast<String*>((yyvsp[0]));;}
    break;

  case 156:
#line 1671 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(mod, (yyvsp[-9]), AST_method_mod);
			CAST_AST(fn, (yyvsp[-8]), AST_method);
			CAST_AST(is_ref, (yyvsp[-6]), Integer);
			CAST_STR(name, (yyvsp[-5]), Token_method_name);
			CAST_AST(params, (yyvsp[-2]), AST_formal_parameter_list);
			CAST_AST(body, (yyvsp[0]), AST_statement_list);
		
			AST_signature* signature = NEW(AST_signature, (mod, is_ref->value(), name, params));
			
			AST_member_list* members = new AST_member_list;
			fn->signature = signature;
			fn->statements = body;
			members->push_back(fn);
			
			(yyval) = members;
		;}
    break;

  case 157:
#line 1695 "src/generated_src/php_parser.ypp"
    {
			// Abstract method
			(yyval) = NULL; 
		;}
    break;

  case 158:
#line 1700 "src/generated_src/php_parser.ypp"
    {
			(yyval) = (yyvsp[0]);
		;}
    break;

  case 159:
#line 1710 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(method_mod, (yyvsp[0]), AST_method_mod);
			
			if(method_mod->is_abstract)
			{
				phc_error(ERR_ABSTRACT_VARS, method_mod->get_filename(), method_mod->get_line_number());
			}

			(yyval) = NEW(AST_attr_mod, (method_mod)); 
		;}
    break;

  case 160:
#line 1721 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_attr_mod, (true, false, false, false, false)); ;}
    break;

  case 161:
#line 1729 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PUBLIC(); ;}
    break;

  case 162:
#line 1731 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 163:
#line 1739 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 164:
#line 1741 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(i, (yyvsp[-1]), AST_method_mod);
			CAST_AST(j, (yyvsp[0]), AST_method_mod);
		
			(yyval) = NEW(AST_method_mod, (i, j)); 
		;}
    break;

  case 165:
#line 1754 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PUBLIC(); ;}
    break;

  case 166:
#line 1756 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PROTECTED(); ;}
    break;

  case 167:
#line 1758 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PRIVATE(); ;}
    break;

  case 168:
#line 1760 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_STATIC(); ;}
    break;

  case 169:
#line 1762 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_ABSTRACT(); ;}
    break;

  case 170:
#line 1764 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_FINAL(); ;}
    break;

  case 171:
#line 1772 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(members, (yyvsp[-2]), AST_member_list);
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			
			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, NULL));
			members->push_back(attr);
			
			(yyval) = members;
		;}
    break;

  case 172:
#line 1782 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(members, (yyvsp[-4]), AST_member_list);
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, value));
			members->push_back(attr);

			(yyval) = members;			
		;}
    break;

  case 173:
#line 1793 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[0]), Token_variable_name);
			AST_member_list* members = new AST_member_list;

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, NULL));	
			members->push_back(attr);

			(yyval) = members;
		;}
    break;

  case 174:
#line 1803 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			AST_member_list* members = new AST_member_list;

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, value));
			members->push_back(attr);

			(yyval) = members;
		;}
    break;

  case 175:
#line 1820 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(members, (yyvsp[-4]), AST_member_list);
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(value, (yyvsp[0]), AST_expr);

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_CONST(), name, value));
			members->push_back(attr);
			
			(yyval) = members;
		;}
    break;

  case 176:
#line 1831 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[-2]), Token_variable_name);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			AST_member_list* members = new AST_member_list;

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_CONST(), name, value));
			members->push_back(attr);

			(yyval) = members;
		;}
    break;

  case 177:
#line 1850 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(echo_list, (yyvsp[-2]), AST_statement_list);
			CAST_AST(param, (yyvsp[0]), AST_expr);
			
			AST_method_invocation* fn = NEW(AST_method_invocation, ("echo", param));
			echo_list->push_back(NEW(AST_eval_expr, (fn)));
			
			(yyval) = echo_list;
		;}
    break;

  case 178:
#line 1860 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(param, (yyvsp[0]), AST_expr);
			AST_statement_list* echo_list = new AST_statement_list;
			
			AST_method_invocation* fn = NEW(AST_method_invocation, ("echo", param));
			echo_list->push_back(NEW(AST_eval_expr, (fn)));
			
			(yyval) = echo_list;
		;}
    break;

  case 179:
#line 1876 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 180:
#line 1878 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]) ;}
    break;

  case 181:
#line 1887 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(a, (yyvsp[-2]), AST_expr);
			CAST_AST(b, (yyvsp[0]), AST_expr);

			(yyval) = new AST_bin_op(a, b, ",");
		;}
    break;

  case 182:
#line 1894 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 183:
#line 1902 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(elements, (yyvsp[-3]), AST_list_elements);
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_list_assignment, (elements, expr));
		;}
    break;

  case 184:
#line 1909 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_assignment, (var, false, value));
		;}
    break;

  case 185:
#line 1917 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-3]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-3]));
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_assignment, (var, true, value)); 
		;}
    break;

  case 186:
#line 1925 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-5]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-5]));
			CAST_AST(name, (yyvsp[-1]), AST_class_name);
			CAST_AST(args, (yyvsp[0]), AST_actual_parameter_list);

			(yyval) = NEW(AST_assignment, (var, true, NEW(AST_new, (name, args))));
		;}
    break;

  case 187:
#line 1934 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(name, (yyvsp[-1]), AST_class_name);	
			CAST_AST(args, (yyvsp[0]), AST_actual_parameter_list);

			(yyval) = NEW(AST_new, (name, args));
		;}
    break;

  case 188:
#line 1941 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_clone, (expr)); 
		;}
    break;

  case 189:
#line 1947 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "+"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 190:
#line 1960 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "-"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 191:
#line 1973 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "*"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 192:
#line 1986 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "/"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 193:
#line 1999 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "."))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 194:
#line 2012 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "%"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 195:
#line 2025 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "&"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 196:
#line 2038 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "|"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 197:
#line 2051 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "^"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 198:
#line 2064 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "<<"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 199:
#line 2077 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[-2]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-2]));
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			
			AST_assignment* agn = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, ">>"))));
			agn->attrs->set("phc.unparser.is_opeq", new Boolean(true));
			(yyval) = agn;
		;}
    break;

  case 200:
#line 2090 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[-1]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-1]));
			(yyval) = NEW(AST_post_op, (var, "++"));
		;}
    break;

  case 201:
#line 2096 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[0]), AST_variable);
			EXPECT_VARIABLE((yyvsp[0]));
			(yyval) = NEW(AST_pre_op, (var, "++"));
		;}
    break;

  case 202:
#line 2102 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[-1]), AST_variable);
			EXPECT_VARIABLE((yyvsp[-1]));
			(yyval) = NEW(AST_post_op, (var, "--"));
		;}
    break;

  case 203:
#line 2108 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[0]), AST_variable);
			EXPECT_VARIABLE((yyvsp[0]));
			(yyval) = NEW(AST_pre_op, (var, "--"));
		;}
    break;

  case 204:
#line 2114 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "||"));
		;}
    break;

  case 205:
#line 2121 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "&&"));
		;}
    break;

  case 206:
#line 2128 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "or"));
		;}
    break;

  case 207:
#line 2135 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "and"));
		;}
    break;

  case 208:
#line 2142 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "xor"));
		;}
    break;

  case 209:
#line 2149 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "|"));
		;}
    break;

  case 210:
#line 2156 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "&"));
		;}
    break;

  case 211:
#line 2163 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "^"));
		;}
    break;

  case 212:
#line 2170 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "."));
		;}
    break;

  case 213:
#line 2177 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-3]), AST_expr);
			CAST_AST(right, (yyvsp[-1]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "."));

			/*
			 * Interface with the lexer: return to in-string state 
			 */
			 
			context->return_to_complex_syntax();
		;}
    break;

  case 214:
#line 2190 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "+"));
		;}
    break;

  case 215:
#line 2197 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "-"));
		;}
    break;

  case 216:
#line 2204 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "*"));
		;}
    break;

  case 217:
#line 2211 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "/"));
		;}
    break;

  case 218:
#line 2218 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "%"));
		;}
    break;

  case 219:
#line 2225 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "<<"));
		;}
    break;

  case 220:
#line 2232 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, ">>"));
		;}
    break;

  case 221:
#line 2239 "src/generated_src/php_parser.ypp"
    {
			// We ignore unary plus
			(yyval) = (yyvsp[0]); 
		;}
    break;

  case 222:
#line 2244 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_unary_op, (expr, "-")); 
		;}
    break;

  case 223:
#line 2250 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_unary_op, (expr, "!")); 
		;}
    break;

  case 224:
#line 2256 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_unary_op, (expr, "~")); 
		;}
    break;

  case 225:
#line 2262 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "==="));
		;}
    break;

  case 226:
#line 2269 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "!=="));
		;}
    break;

  case 227:
#line 2276 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "=="));
		;}
    break;

  case 228:
#line 2283 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "!="));
		;}
    break;

  case 229:
#line 2290 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "<"));
		;}
    break;

  case 230:
#line 2297 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "<="));
		;}
    break;

  case 231:
#line 2304 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, ">"));
		;}
    break;

  case 232:
#line 2311 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[-2]), AST_expr);
			CAST_AST(right, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, ">="));
		;}
    break;

  case 233:
#line 2318 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-2]), AST_expr);
			CAST_AST(class_name, (yyvsp[0]), AST_class_name);
			
			(yyval) = NEW(AST_instanceof, (expr, class_name));
		;}
    break;

  case 234:
#line 2325 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-1]), AST_expr);

			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
			
			(yyval) = expr;
		;}
    break;

  case 235:
#line 2333 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(cond, (yyvsp[-4]), AST_expr);
			CAST_AST(iftrue, (yyvsp[-2]), AST_expr);
			CAST_AST(iffalse, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_conditional_expr, (cond, iftrue, iffalse)); 
		;}
    break;

  case 236:
#line 2341 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 237:
#line 2343 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_cast, ("int", expr));
		;}
    break;

  case 238:
#line 2348 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_cast, ("real", expr));
		;}
    break;

  case 239:
#line 2353 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_cast, ("string", expr));
		;}
    break;

  case 240:
#line 2358 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_cast, ("array", expr));
		;}
    break;

  case 241:
#line 2363 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_cast, ("object", expr));
		;}
    break;

  case 242:
#line 2368 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_cast, ("bool", expr));
		;}
    break;

  case 243:
#line 2373 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_cast, ("unset", expr));
		;}
    break;

  case 244:
#line 2378 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(param, (yyvsp[0]), AST_expr);
			
			(yyval) = NEW(AST_method_invocation, ("exit", param));
		;}
    break;

  case 245:
#line 2384 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
 
			(yyval) = NEW(AST_ignore_errors, (expr)); 
		;}
    break;

  case 246:
#line 2390 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 247:
#line 2392 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(list, (yyvsp[-1]), AST_array_elem_list);
			
			(yyval) = NEW(AST_array, (list)); 
		;}
    break;

  case 248:
#line 2398 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(param, (yyvsp[0]), AST_expr);

			(yyval) = NEW(AST_method_invocation, ("print", param));	
		;}
    break;

  case 249:
#line 2410 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(params, (yyvsp[-1]), AST_actual_parameter_list);
			CAST_STR(fn, (yyvsp[-3]), Token_method_name);
		
			(yyval) = NEW(AST_method_invocation, (NULL, fn, params));
		;}
    break;

  case 250:
#line 2417 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[-5]), Token_class_name);
			CAST_STR(fn, (yyvsp[-3]), Token_method_name);
			CAST_AST(params, (yyvsp[-1]), AST_actual_parameter_list);

			(yyval) = NEW(AST_method_invocation, (class_name, fn, params));
		;}
    break;

  case 251:
#line 2425 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[-5]), Token_class_name);
			CAST_AST(expr, (yyvsp[-3]), AST_expr);
			CAST_AST(params, (yyvsp[-1]), AST_actual_parameter_list);
			
			(yyval) = NEW(AST_method_invocation, (class_name, NEW(AST_reflection, (expr)), params));
		;}
    break;

  case 252:
#line 2433 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-3]), AST_expr);
			CAST_AST(params, (yyvsp[-1]), AST_actual_parameter_list);			
			
			(yyval) = NEW(AST_method_invocation, (NULL, NEW(AST_reflection, (expr)), params));
		;}
    break;

  case 253:
#line 2446 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[0]), Token_class_name);
			(yyval) = name; 
		;}
    break;

  case 254:
#line 2457 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[0]), Token_class_name);

			(yyval) = name; 
		;}
    break;

  case 255:
#line 2463 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_reflection, (expr)); 
		;}
    break;

  case 256:
#line 2477 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(object, (yyvsp[-3]), AST_expr);
			CAST_AST(result, (yyvsp[-1]), AST_variable);
			CAST_AST(vars, (yyvsp[0]), List<AST_variable*>);
			
			result->target = object;

			List<AST_variable*>::const_iterator i;
			for(i = vars->begin(); i != vars->end(); i++)
			{
				(*i)->target = result;
				result = *i;
			}
			
			(yyval) = result; 
		;}
    break;

  case 257:
#line 2494 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 258:
#line 2502 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(vars, (yyvsp[-1]), List<AST_variable*>);
			CAST_AST(var, (yyvsp[0]), AST_variable);

			vars->push_back(var);
			(yyval) = vars;
		;}
    break;

  case 259:
#line 2510 "src/generated_src/php_parser.ypp"
    { 
			List<AST_variable*>* vars = new List<AST_variable*>;
			(yyval) = vars;
		;}
    break;

  case 260:
#line 2521 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 261:
#line 2531 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(Token_int, (0L, new String("0"))); ;}
    break;

  case 262:
#line 2533 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(Token_int, (0L, new String("0"))); ;}
    break;

  case 263:
#line 2535 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 264:
#line 2543 "src/generated_src/php_parser.ypp"
    { 
			AST_actual_parameter_list* args = new AST_actual_parameter_list;
			
			(yyval) = args; 
		;}
    break;

  case 265:
#line 2549 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 266:
#line 2557 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[0]), String);
			(yyval) = NEW(Token_int, (strtol(str->c_str(), 0, 0), str));
		;}
    break;

  case 267:
#line 2562 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[0]), String);
			(yyval) = NEW(Token_real, (atof(str->c_str()), str));
		;}
    break;

  case 268:
#line 2567 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[0]), String);
			(yyval) = NEW(Token_string, (str, str));
		;}
    break;

  case 269:
#line 2572 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(str, (yyvsp[0]), String);
			(yyval) = NEW(Token_bool, (false, str));
		;}
    break;

  case 270:
#line 2577 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(str, (yyvsp[0]), String);
			(yyval) = NEW(Token_bool, (true, str));
		;}
    break;

  case 271:
#line 2582 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(str, (yyvsp[0]), String);
			(yyval) = NEW(Token_null, (str));
		;}
    break;

  case 272:
#line 2587 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_int, (context->source_line, new String("__LINE__")));
		;}
    break;

  case 273:
#line 2591 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->filename, new String("__FILE__")));
		;}
    break;

  case 274:
#line 2595 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->current_class, new String("__CLASS__")));
		;}
    break;

  case 275:
#line 2599 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->current_method, new String("__METHOD__")));
		;}
    break;

  case 276:
#line 2603 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->current_method, new String("__FUNCTION__")));
		;}
    break;

  case 277:
#line 2613 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 278:
#line 2615 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[0]), Token_constant_name);
			(yyval) = NEW(AST_constant, ("%MAIN%", name)); 
		;}
    break;

  case 279:
#line 2620 "src/generated_src/php_parser.ypp"
    {
			// We simply ignore the +
			(yyval) = (yyvsp[0]);
		;}
    break;

  case 280:
#line 2625 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(val, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_unary_op, (val, "-"));
		;}
    break;

  case 281:
#line 2630 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-1]), AST_array_elem_list);
			(yyval) = NEW(AST_array, (list));
		;}
    break;

  case 282:
#line 2635 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 283:
#line 2643 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(class_name, (yyvsp[-2]), Token_class_name);
			CAST_STR(constant, (yyvsp[0]), Token_constant_name);
			
			(yyval) = NEW(AST_constant, (class_name, constant));
		;}
    break;

  case 284:
#line 2656 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[0]), Token_constant_name);

			(yyval) = NEW(AST_constant, ("%MAIN%", name));
		;}
    break;

  case 285:
#line 2662 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 286:
#line 2664 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 287:
#line 2672 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_array_elem_list; ;}
    break;

  case 288:
#line 2674 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 289:
#line 2682 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 290:
#line 2684 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 291:
#line 2692 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-4]), AST_array_elem_list);
			CAST_AST(key, (yyvsp[-2]), AST_expr);
			CAST_AST(value, (yyvsp[0]), AST_expr);

			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 292:
#line 2703 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-2]), AST_array_elem_list);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);
			
			(yyval) = list;
		;}
    break;

  case 293:
#line 2713 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(key, (yyvsp[-2]), AST_expr);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 294:
#line 2724 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 295:
#line 2740 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 296:
#line 2742 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 297:
#line 2750 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 298:
#line 2758 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 299:
#line 2766 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 300:
#line 2790 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(object, (yyvsp[-1]), AST_expr);
			CAST_AST(props, (yyvsp[0]), AST_expr_list);

			AST_expr_list::iterator i;
			for(i = props->begin(); i != props->end(); i++)
			{
				CAST_UNSAFE(var, *i, AST_variable);
				CAST_UNSAFE(fn, *i, AST_method_invocation);

				if(var)
				{
					var->target = object;
					
					AST_actual_parameter_list* function_params = dynamic_cast<AST_actual_parameter_list*>(var->attrs->get("phc.parser.function_params"));
	
					if(function_params)
					{
						object = NEW(AST_method_invocation, (NULL, NEW(AST_reflection,(var)), function_params));
					}
					else
					{
						object = var;
					}
				}
				else
				{
					fn->target = object;
					object = fn;
				}
			}

			(yyval) = object;
		;}
    break;

  case 301:
#line 2825 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 302:
#line 2836 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(props, (yyvsp[-1]), AST_expr_list);
			CAST_AST(prop, (yyvsp[0]), AST_expr);

			props->push_back(prop);
			
			(yyval) = props;
		;}
    break;

  case 303:
#line 2845 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(prop, (yyvsp[0]), AST_expr);
			
			AST_expr_list* props = new AST_expr_list;
			props->push_back(prop);
			
			(yyval) = props;
		;}
    break;

  case 304:
#line 2878 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var, (yyvsp[-1]), AST_variable);
			CAST_AST(params, (yyvsp[0]), AST_actual_parameter_list);
			
			if(params)
			{
				if(var->array_indices->empty())
				{
					CAST_UNSAFE(vn, var->variable_name, Token_variable_name);
				
					if(vn)
					{
						Token_method_name* fn;
						
						fn = NEW(Token_method_name, (vn->value));
						(yyval) = NEW(AST_method_invocation, (NULL, fn, params));
					}
					else
					{
						AST_reflection* fn;

						fn = dynamic_cast<AST_reflection*>(var->variable_name);
						assert(fn);
						(yyval) = NEW(AST_method_invocation, (NULL, fn, params));
					}
				}
				else
				{
					var->attrs->set("phc.parser.function_params", params);
					(yyval) = var;
				}
			}
			else
			{
				(yyval) = var;
			}
		;}
    break;

  case 305:
#line 2922 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 306:
#line 2924 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 307:
#line 2932 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 308:
#line 2934 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(num_indirections, (yyvsp[-1]), Integer);
			CAST_AST(var, (yyvsp[0]), AST_variable);
				
			for(long i = 0; i < num_indirections->value(); i++)
			{
				var = NEW(AST_variable, (NEW(AST_reflection, (var))));
			}
			
			(yyval) = var;
		;}
    break;

  case 309:
#line 2952 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_name, (yyvsp[-2]), Token_class_name);
			CAST_AST(var, (yyvsp[0]), AST_variable);
		
			var->target = class_name;
			(yyval) = var; 
		;}
    break;

  case 310:
#line 2966 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 311:
#line 2968 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 312:
#line 2976 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 313:
#line 2978 "src/generated_src/php_parser.ypp"
    {	
			CAST_AST(num_indirections, (yyvsp[-1]), Integer);
			CAST_AST(var, (yyvsp[0]), AST_variable);
				
			for(long i = 0; i < num_indirections->value(); i++)
			{
				var = NEW(AST_variable, (NEW(AST_reflection, (var))));
			}

			(yyval) = var;
		;}
    break;

  case 314:
#line 2990 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 315:
#line 2998 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var, (yyvsp[-3]), AST_variable);
			CAST_AST(index, (yyvsp[-1]), AST_expr);
		
			// string index is only valid after *all* array indices.
			assert(var->string_index == NULL);
		
			var->array_indices->push_back(index);
			(yyval) = var;
		;}
    break;

  case 316:
#line 3009 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var, (yyvsp[-3]), AST_variable);
			CAST_AST(index, (yyvsp[-1]), AST_expr);
			
			// we only accept *one* string index.
			assert(var->string_index == NULL);
			
			var->string_index = index;
			(yyval) = var;
		;}
    break;

  case 317:
#line 3020 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(name, (yyvsp[0]), AST_variable_name);

			(yyval) = NEW(AST_variable, (name));
		;}
    break;

  case 318:
#line 3032 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(var, (yyvsp[0]), Token_variable_name);
			(yyval) = var; 
		;}
    break;

  case 319:
#line 3037 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[-1]), AST_expr);
			expr->attrs->set("phc.unparser.needs_curlies", new Boolean(true));
			(yyval) = NEW(AST_reflection, (expr)); 
		;}
    break;

  case 320:
#line 3049 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 321:
#line 3051 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 322:
#line 3059 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 323:
#line 3061 "src/generated_src/php_parser.ypp"
    {
			// This is a "normal" variable (which includes a $), i.e. $x->$y
			// So, we need to add a level of indirection
			CAST_AST(var, (yyvsp[0]), AST_variable);
			(yyval) = NEW(AST_variable, (NEW(AST_reflection, (var)))); 
		;}
    break;

  case 324:
#line 3076 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(op, (yyvsp[-3]), AST_variable);
			CAST_AST(index, (yyvsp[-1]), AST_expr);
		
			// string index is only valid after *all* array indices
			assert(op->string_index == NULL);
			
			op->array_indices->push_back(index);
			(yyval) = op;
		;}
    break;

  case 325:
#line 3087 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(op, (yyvsp[-3]), AST_variable);
			CAST_AST(index, (yyvsp[-1]), AST_expr);

			// we only accept *one* string index.
			assert(op->string_index == NULL);

			op->string_index = index;
			(yyval) = op;
		;}
    break;

  case 326:
#line 3098 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(name, (yyvsp[0]), AST_variable_name);	

			(yyval) = NEW(AST_variable, (name)); 
		;}
    break;

  case 327:
#line 3112 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(var, (yyvsp[0]), Token_variable_name);
			(yyval) = var; 
		;}
    break;

  case 328:
#line 3117 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[-1]), AST_expr);
			expr->attrs->set("phc.unparser.needs_curlies", new Boolean(true));
			(yyval) = NEW(AST_reflection, (expr)); 
		;}
    break;

  case 329:
#line 3131 "src/generated_src/php_parser.ypp"
    { (yyval) = new Integer(1); ;}
    break;

  case 330:
#line 3133 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(i, (yyvsp[-1]), Integer);
			
			(*i)++;
			(yyval) = i; 
		;}
    break;

  case 331:
#line 3146 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(elements, (yyvsp[-2]), AST_list_elements);
			CAST_AST(element, (yyvsp[0]), AST_list_element);

			elements->list_elements->push_back(element);
			
			(yyval) = elements; 
		;}
    break;

  case 332:
#line 3155 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(element, (yyvsp[0]), AST_list_element);

			AST_list_element_list* elements = new AST_list_element_list;
			elements->push_back(element);
			
			(yyval) = NEW(AST_list_elements, (elements)); 
		;}
    break;

  case 333:
#line 3172 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 334:
#line 3174 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 335:
#line 3176 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 336:
#line 3184 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_array_elem_list; ;}
    break;

  case 337:
#line 3186 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 338:
#line 3196 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-4]), AST_array_elem_list);
			CAST_AST(key, (yyvsp[-2]), AST_expr);
			CAST_AST(value, (yyvsp[0]), AST_expr);

			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 339:
#line 3207 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-2]), AST_array_elem_list);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);
			
			(yyval) = list;
		;}
    break;

  case 340:
#line 3217 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(key, (yyvsp[-2]), AST_expr);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 341:
#line 3228 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 342:
#line 3238 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-5]), AST_array_elem_list);
			CAST_AST(key, (yyvsp[-3]), AST_expr);
			CAST_AST(value, (yyvsp[0]), AST_expr);

			AST_array_elem* elem = 
				NEW(AST_array_elem, (key, true, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 343:
#line 3250 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[-3]), AST_array_elem_list);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem* elem = 
				NEW(AST_array_elem, (NULL, true, value));
			list->push_back(elem);
			
			(yyval) = list;
		;}
    break;

  case 344:
#line 3261 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(key, (yyvsp[-3]), AST_expr);
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = 
				NEW(AST_array_elem, (key, true, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 345:
#line 3273 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(value, (yyvsp[0]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = 
				NEW(AST_array_elem, (NULL, true, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 346:
#line 3290 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(params, (yyvsp[-1]), AST_actual_parameter_list);
		  
			Token_method_name* fn = NEW(Token_method_name, (new String("isset")));
			(yyval) = NEW(AST_method_invocation, (NULL, fn, params));
		;}
    break;

  case 347:
#line 3297 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(variable, (yyvsp[-1]), AST_expr); 
			(yyval) = NEW(AST_method_invocation, ("empty", variable));
		;}
    break;

  case 348:
#line 3302 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("include", expr));
		;}
    break;

  case 349:
#line 3307 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("include_once", expr));
		;}
    break;

  case 350:
#line 3312 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[-1]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("eval", expr));
		;}
    break;

  case 351:
#line 3317 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("require", expr));
		;}
    break;

  case 352:
#line 3322 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[0]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("require_once", expr));
		;}
    break;

  case 353:
#line 3333 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(variable, (yyvsp[0]), AST_expr);
			AST_actual_parameter_list* params = new AST_actual_parameter_list;
			
			params->push_back(NEW(AST_actual_parameter, (false, variable)));
			(yyval) = params;
		;}
    break;

  case 354:
#line 3341 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(params, (yyvsp[-2]), AST_actual_parameter_list);
			CAST_AST(variable, (yyvsp[0]), AST_expr);
			
			params->push_back(NEW(AST_actual_parameter, (false, variable)));
			(yyval) = params;
		;}
    break;

  case 355:
#line 3355 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[-2]), Token_class_name);
			CAST_STR(constant, (yyvsp[0]), Token_constant_name);

			(yyval) = NEW(AST_constant, (class_name, constant));
		;}
    break;

  case 356:
#line 3369 "src/generated_src/php_parser.ypp"
    {
			CAST_STATEMENT_VECTOR(list, (yyvsp[-1]));
			
			// If there are any remaining comments, add them as a NOP
			if(!context->last_comments.empty())
				list->push_back(NEW(AST_nop, ()));

			(yyval) = list;
		;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 6608 "src/generated/php_parser.tab.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (context, yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (context, YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (context, YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (context, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



