/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

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
	#include <phc/ast.h>
	#include "generated/cmdline.h"
	#include <phc/lib/Integer.h>
	#include <phc/lib/String.h>
	#include <phc/lib/error.h>
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 466 "src/generated/php_parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
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
      while (YYID (0))
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
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  355
/* YYNRULES -- Number of states.  */
#define YYNSTATES  700

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   370

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    20,
      23,    24,    26,    28,    30,    35,    37,    39,    41,    45,
      53,    64,    65,    72,    73,    82,    83,    94,    95,   102,
     105,   109,   112,   116,   119,   123,   127,   131,   135,   139,
     141,   144,   148,   154,   163,   172,   173,   180,   182,   183,
     184,   200,   204,   206,   207,   209,   212,   213,   223,   225,
     229,   231,   233,   237,   239,   241,   242,   244,   245,   246,
     258,   259,   268,   275,   277,   280,   283,   284,   287,   289,
     290,   293,   294,   297,   299,   303,   304,   307,   309,   312,
     314,   319,   321,   326,   328,   333,   337,   343,   347,   352,
     357,   363,   364,   365,   372,   373,   379,   381,   383,   385,
     390,   391,   392,   400,   401,   402,   411,   412,   415,   416,
     420,   422,   423,   426,   430,   436,   441,   446,   452,   460,
     467,   468,   470,   472,   474,   475,   477,   479,   482,   486,
     490,   495,   499,   501,   503,   506,   511,   515,   521,   523,
     527,   530,   531,   535,   538,   539,   540,   551,   553,   557,
     559,   561,   562,   564,   566,   569,   571,   573,   575,   577,
     579,   581,   585,   591,   593,   597,   603,   608,   612,   614,
     615,   617,   621,   623,   630,   634,   639,   646,   650,   653,
     657,   661,   665,   669,   673,   677,   681,   685,   689,   693,
     697,   700,   703,   706,   709,   713,   717,   721,   725,   729,
     733,   737,   741,   745,   750,   754,   758,   762,   766,   770,
     774,   778,   781,   784,   787,   790,   794,   798,   802,   806,
     810,   814,   818,   822,   826,   830,   836,   838,   841,   844,
     847,   850,   853,   856,   859,   862,   865,   867,   872,   875,
     880,   887,   894,   899,   901,   903,   905,   910,   912,   915,
     916,   919,   920,   923,   927,   928,   932,   934,   936,   938,
     940,   942,   944,   946,   948,   950,   952,   954,   956,   958,
     961,   964,   969,   971,   975,   977,   979,   981,   982,   985,
     986,   988,   994,   998,  1002,  1004,  1006,  1008,  1010,  1012,
    1014,  1017,  1019,  1022,  1024,  1028,  1032,  1033,  1035,  1038,
    1042,  1044,  1046,  1048,  1051,  1053,  1058,  1063,  1065,  1067,
    1072,  1073,  1075,  1077,  1079,  1084,  1089,  1091,  1093,  1097,
    1099,  1102,  1106,  1108,  1110,  1115,  1116,  1117,  1120,  1126,
    1130,  1134,  1136,  1143,  1148,  1153,  1156,  1161,  1166,  1169,
    1172,  1177,  1180,  1183,  1185,  1189
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     143,     0,    -1,   144,    -1,   144,   145,    -1,    -1,   148,
      -1,   166,    -1,   167,    -1,    71,   135,   136,   137,    -1,
     146,   147,    -1,    -1,   148,    -1,   166,    -1,   167,    -1,
      71,   135,   136,   137,    -1,   151,    -1,    37,    -1,    34,
      -1,   138,   146,   139,    -1,   149,   135,   236,   136,   148,
     192,   196,    -1,   149,   135,   236,   136,   119,   146,   194,
     197,    27,   137,    -1,    -1,    53,   152,   135,   236,   136,
     191,    -1,    -1,    19,   153,   148,    53,   135,   236,   136,
     137,    -1,    -1,    33,   154,   135,   218,   137,   218,   137,
     218,   136,   182,    -1,    -1,    49,   155,   135,   236,   136,
     186,    -1,    11,   137,    -1,    11,   236,   137,    -1,    15,
     137,    -1,    15,   236,   137,    -1,    47,   137,    -1,    47,
     220,   137,    -1,    47,   240,   137,    -1,    36,   203,   137,
      -1,    48,   205,   137,    -1,    20,   217,   137,    -1,   114,
      -1,   236,   137,    -1,    51,   165,   137,    -1,    50,   135,
     163,   136,   137,    -1,   150,   135,   240,    10,   181,   180,
     136,   183,    -1,   150,   135,   220,    10,   238,   180,   136,
     183,    -1,    -1,    16,   156,   135,   185,   136,   184,    -1,
     137,    -1,    -1,    -1,    66,   157,   138,   146,   139,    67,
     158,   135,   222,   111,   136,   138,   146,   139,   159,    -1,
      68,   236,   137,    -1,   160,    -1,    -1,   161,    -1,   160,
     161,    -1,    -1,    67,   162,   135,   222,   111,   136,   138,
     146,   139,    -1,   164,    -1,   163,   116,   164,    -1,   240,
      -1,   109,    -1,   135,   109,   136,    -1,   169,    -1,   172,
      -1,    -1,   122,    -1,    -1,    -1,    35,   170,   168,   110,
     171,   135,   198,   136,   138,   146,   139,    -1,    -1,   174,
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
      -1,   137,    -1,   138,   146,   139,    -1,   213,    -1,    52,
      -1,    -1,   213,    -1,   214,    -1,   213,   214,    -1,    61,
      -1,    63,    -1,    62,    -1,    48,    -1,    64,    -1,    57,
      -1,   215,   116,   111,    -1,   215,   116,   111,   117,   230,
      -1,   111,    -1,   111,   117,   230,    -1,   216,   116,   110,
     117,   230,    -1,    14,   110,   117,   230,    -1,   217,   116,
     236,    -1,   236,    -1,    -1,   219,    -1,   219,   116,   236,
      -1,   236,    -1,    42,   135,   255,   136,   117,   236,    -1,
     240,   117,   236,    -1,   240,   117,   122,   240,    -1,   240,
     117,   122,    43,   223,   228,    -1,    43,   223,   228,    -1,
      65,   236,    -1,   240,    90,   236,    -1,   240,    91,   236,
      -1,   240,    92,   236,    -1,   240,    93,   236,    -1,   240,
      94,   236,    -1,   240,    95,   236,    -1,   240,    96,   236,
      -1,   240,    97,   236,    -1,   240,    98,   236,    -1,   240,
      99,   236,    -1,   240,   100,   236,    -1,   239,    81,    -1,
      81,   239,    -1,   239,    82,    -1,    82,   239,    -1,   236,
      88,   236,    -1,   236,    89,   236,    -1,   236,     4,   236,
      -1,   236,     3,   236,    -1,   236,     5,   236,    -1,   236,
     120,   236,    -1,   236,   122,   236,    -1,   236,   121,   236,
      -1,   236,   127,   236,    -1,   236,   101,   236,   139,    -1,
     236,   125,   236,    -1,   236,   126,   236,    -1,   236,   128,
     236,    -1,   236,   129,   236,    -1,   236,   130,   236,    -1,
     236,    85,   236,    -1,   236,    86,   236,    -1,   125,   236,
      -1,   126,   236,    -1,   131,   236,    -1,   132,   236,    -1,
     236,    76,   236,    -1,   236,    78,   236,    -1,   236,    75,
     236,    -1,   236,    77,   236,    -1,   236,   123,   236,    -1,
     236,    79,   236,    -1,   236,   124,   236,    -1,   236,    80,
     236,    -1,   236,    40,   223,    -1,   135,   236,   136,    -1,
     236,   118,   236,   119,   236,    -1,   259,    -1,   102,   236,
      -1,   103,   236,    -1,   104,   236,    -1,   105,   236,    -1,
     106,   236,    -1,   107,   236,    -1,   108,   236,    -1,    31,
     227,    -1,   133,   236,    -1,   232,    -1,     9,   135,   257,
     136,    -1,    44,   236,    -1,   110,   135,   201,   136,    -1,
     222,    87,   110,   135,   201,   136,    -1,   222,    87,   244,
     135,   201,   136,    -1,   244,   135,   201,   136,    -1,   110,
      -1,   110,    -1,   224,    -1,   247,    84,   251,   225,    -1,
     247,    -1,   225,   226,    -1,    -1,    84,   251,    -1,    -1,
     135,   136,    -1,   135,   236,   136,    -1,    -1,   135,   201,
     136,    -1,   112,    -1,   113,    -1,   109,    -1,    73,    -1,
      72,    -1,    74,    -1,     8,    -1,     6,    -1,    55,    -1,
      56,    -1,    54,    -1,   229,    -1,   110,    -1,   125,   230,
      -1,   126,   230,    -1,     9,   135,   233,   136,    -1,   231,
      -1,   110,    87,   110,    -1,   110,    -1,   261,    -1,   229,
      -1,    -1,   235,   234,    -1,    -1,   116,    -1,   235,   116,
     230,    83,   230,    -1,   235,   116,   230,    -1,   230,    83,
     230,    -1,   230,    -1,   237,    -1,   220,    -1,   240,    -1,
     240,    -1,   240,    -1,   246,   241,    -1,   246,    -1,   241,
     242,    -1,   242,    -1,    84,   251,   243,    -1,   135,   201,
     136,    -1,    -1,   248,    -1,   254,   248,    -1,   222,    87,
     244,    -1,   247,    -1,   221,    -1,   248,    -1,   254,   248,
      -1,   245,    -1,   248,   134,   250,   141,    -1,   248,   138,
     236,   139,    -1,   249,    -1,   111,    -1,   140,   138,   236,
     139,    -1,    -1,   236,    -1,   252,    -1,   244,    -1,   252,
     134,   250,   141,    -1,   252,   138,   236,   139,    -1,   253,
      -1,   110,    -1,   138,   236,   139,    -1,   140,    -1,   254,
     140,    -1,   255,   116,   256,    -1,   256,    -1,   240,    -1,
      42,   135,   255,   136,    -1,    -1,    -1,   258,   234,    -1,
     258,   116,   236,    83,   236,    -1,   258,   116,   236,    -1,
     236,    83,   236,    -1,   236,    -1,   258,   116,   236,    83,
     122,   238,    -1,   258,   116,   122,   238,    -1,   236,    83,
     122,   238,    -1,   122,   238,    -1,    41,   135,   260,   136,
      -1,    23,   135,   240,   136,    -1,    38,   236,    -1,    39,
     236,    -1,    30,   135,   236,   136,    -1,    45,   236,    -1,
      46,   236,    -1,   240,    -1,   260,   116,   240,    -1,   222,
      87,   110,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   312,   312,   332,   355,   364,   368,   370,   372,   385,
     408,   415,   419,   421,   423,   434,   443,   452,   460,   464,
     503,   533,   533,   544,   544,   555,   555,   570,   570,   581,
     583,   589,   591,   597,   599,   605,   611,   631,   633,   635,
     643,   649,   656,   667,   698,   730,   730,   741,   743,   743,
     743,   766,   778,   781,   791,   800,   815,   815,   834,   842,
     856,   868,   873,   886,   896,   905,   906,   918,   918,   918,
     943,   943,   960,   990,   995,  1000,  1012,  1013,  1021,  1030,
    1031,  1042,  1043,  1051,  1063,  1080,  1081,  1089,  1095,  1108,
    1110,  1118,  1120,  1128,  1130,  1138,  1149,  1165,  1167,  1169,
    1171,  1180,  1181,  1181,  1195,  1195,  1214,  1216,  1224,  1230,
    1239,  1240,  1240,  1284,  1285,  1285,  1323,  1324,  1335,  1336,
    1344,  1347,  1359,  1371,  1383,  1396,  1409,  1419,  1429,  1440,
    1458,  1459,  1464,  1474,  1477,  1484,  1492,  1500,  1508,  1516,
    1524,  1538,  1546,  1561,  1566,  1571,  1582,  1592,  1603,  1613,
    1630,  1640,  1649,  1663,  1665,  1665,  1665,  1689,  1694,  1704,
    1715,  1724,  1725,  1733,  1735,  1748,  1750,  1752,  1754,  1756,
    1758,  1766,  1776,  1787,  1797,  1814,  1825,  1844,  1854,  1871,
    1872,  1881,  1888,  1896,  1903,  1911,  1919,  1928,  1935,  1941,
    1953,  1965,  1977,  1989,  2001,  2013,  2025,  2037,  2049,  2061,
    2073,  2079,  2085,  2091,  2097,  2104,  2111,  2118,  2125,  2132,
    2139,  2146,  2153,  2160,  2173,  2180,  2187,  2194,  2201,  2208,
    2215,  2222,  2227,  2233,  2239,  2245,  2252,  2259,  2266,  2273,
    2280,  2287,  2294,  2301,  2308,  2316,  2324,  2326,  2331,  2336,
    2341,  2346,  2351,  2356,  2361,  2367,  2373,  2375,  2381,  2393,
    2400,  2408,  2416,  2429,  2440,  2446,  2460,  2477,  2485,  2494,
    2504,  2515,  2516,  2518,  2527,  2532,  2540,  2545,  2550,  2555,
    2560,  2565,  2570,  2574,  2578,  2582,  2586,  2596,  2598,  2603,
    2608,  2613,  2618,  2626,  2639,  2645,  2647,  2656,  2657,  2666,
    2667,  2675,  2686,  2696,  2707,  2723,  2725,  2733,  2741,  2749,
    2773,  2808,  2819,  2828,  2861,  2905,  2908,  2915,  2917,  2935,
    2949,  2951,  2959,  2961,  2973,  2981,  2992,  3003,  3015,  3020,
    3032,  3033,  3041,  3043,  3058,  3069,  3080,  3094,  3099,  3112,
    3114,  3127,  3136,  3153,  3155,  3158,  3166,  3167,  3177,  3188,
    3198,  3209,  3219,  3231,  3242,  3254,  3271,  3278,  3283,  3288,
    3293,  3298,  3303,  3314,  3322,  3336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
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
  "isset_variables", "class_constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
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
static const yytype_uint16 yyr1[] =
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
     259,   259,   259,   260,   260,   261
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     4,     2,
       0,     1,     1,     1,     4,     1,     1,     1,     3,     7,
      10,     0,     6,     0,     8,     0,    10,     0,     6,     2,
       3,     2,     3,     2,     3,     3,     3,     3,     3,     1,
       2,     3,     5,     8,     8,     0,     6,     1,     0,     0,
      15,     3,     1,     0,     1,     2,     0,     9,     1,     3,
       1,     1,     3,     1,     1,     0,     1,     0,     0,    11,
       0,     8,     6,     1,     2,     2,     0,     2,     1,     0,
       2,     0,     2,     1,     3,     0,     2,     1,     2,     1,
       4,     1,     4,     1,     4,     3,     5,     3,     4,     4,
       5,     0,     0,     6,     0,     5,     1,     1,     1,     4,
       0,     0,     7,     0,     0,     8,     0,     2,     0,     3,
       1,     0,     2,     3,     5,     4,     4,     5,     7,     6,
       0,     1,     1,     1,     0,     1,     1,     2,     3,     3,
       4,     3,     1,     1,     2,     4,     3,     5,     1,     3,
       2,     0,     3,     2,     0,     0,    10,     1,     3,     1,
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
       4,     2,     2,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
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
     285,   336,    29,     0,    31,     0,     0,     0,     0,   178,
       0,     0,     0,   244,     0,    65,   143,     0,     0,   142,
     348,   349,     0,   335,   254,     0,   264,   255,   257,   312,
       0,   248,   351,   352,    33,   296,     0,   297,   148,     0,
       0,     0,    61,     0,     0,     0,    75,    74,   188,     0,
       0,     0,   253,     0,   201,   299,   203,   237,   238,   239,
     240,   241,   242,   243,   134,   221,   222,   223,   224,   245,
       0,     0,     0,     0,     0,    70,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,   200,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,   300,   303,   320,     0,   330,   313,     0,   341,
       0,   289,    30,    32,     0,     0,     0,    38,     0,     0,
     262,     0,   179,    66,     0,     0,   144,   297,     0,    36,
     353,     0,     0,   333,     0,   332,     0,   134,   187,     0,
     313,    34,    35,     0,     0,    37,     0,     0,    58,    60,
       0,    41,     0,    10,    51,     0,     0,     0,     0,   133,
     296,   297,   234,     0,    18,     9,    11,    12,    13,     0,
       0,   296,   297,    76,     0,     0,   355,   309,   307,     0,
     207,   206,   208,   233,   227,   225,   228,   226,   230,   232,
     219,   220,   204,   205,     0,     0,   209,   211,   210,   229,
     231,   214,   215,   212,   216,   217,   218,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   184,
       0,   327,     0,   323,   306,   322,   326,   302,   321,     0,
       0,   345,   298,     0,   247,   290,   337,     0,     0,     0,
     177,   347,   350,   263,     0,   180,   182,    68,     0,   141,
       0,   346,   335,   335,     0,   309,     0,   259,     0,   278,
       0,     0,   277,   149,   282,   146,     0,     0,     0,    62,
       0,     0,     8,     0,   137,   249,     0,     0,   319,     0,
       0,     0,     0,    81,   253,    80,    83,   151,   134,   134,
     308,   213,     0,     0,   185,   252,     0,   134,   304,   320,
       0,   315,   316,     0,   340,     0,   339,     0,     0,     0,
       0,   179,     0,     0,   145,   354,     0,   331,     0,   265,
     256,   287,     0,   279,   280,     0,     0,    59,    42,     0,
       0,     0,   296,   297,     0,    10,   110,    85,     0,    85,
      87,    77,     0,     0,     0,   161,     0,     0,   235,   264,
     328,     0,     0,     0,   344,   343,     0,    95,     0,    10,
      93,    46,     0,     0,   181,   130,   334,   183,     0,   258,
     294,     0,   289,   283,   147,   101,   101,    28,    10,   108,
      22,    49,   140,    14,   113,   116,     0,     0,    88,     0,
      82,   151,    84,     0,   168,   160,   170,   165,   167,   166,
     169,    72,   150,     0,     0,   159,   163,     0,   250,   251,
     186,   305,   324,   325,     0,   338,     0,     0,     0,   179,
     132,   131,     0,   120,     0,   260,     0,   281,   290,   288,
     101,     0,   101,     0,     0,     0,   118,     0,   111,    19,
      86,     0,     0,   161,     0,   173,     0,   154,   164,     0,
     153,   342,    96,     0,    24,     0,     0,   130,   122,     0,
     293,   292,     0,     0,     0,     0,     0,    97,     0,     0,
       0,   114,     0,   117,     0,    10,    91,    44,    43,    71,
       0,     0,     0,   152,    65,     0,    94,     0,    10,     0,
       0,   123,     0,     0,     0,   106,   107,   104,    99,    98,
     109,     0,    10,     0,     0,     0,     0,   176,   174,   171,
       0,     0,    10,    89,    26,     0,   126,     0,   125,     0,
     291,   100,   102,    10,     0,   119,     0,    20,     0,     0,
       0,   155,   175,     0,    69,     0,   127,   124,    10,   105,
       0,     0,     0,    92,   172,     0,     0,   129,     0,   103,
      10,     0,   112,   130,    90,   128,     0,    10,     0,    53,
     115,     0,    56,    50,    52,    54,   157,    10,   156,     0,
      55,     0,     0,   158,     0,     0,     0,    10,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    72,   171,   285,   286,    74,    75,    76,
     145,   107,   114,   140,   106,   149,   555,   683,   684,   685,
     689,   267,   268,   144,   287,   288,   244,    79,   115,   433,
      80,   293,    81,   403,    82,   295,   463,   405,   507,   459,
     634,   597,   481,   358,   497,   551,   658,   643,   617,   500,
     505,   594,   556,   623,   559,   592,   542,   543,   544,   278,
     279,   118,   119,   139,   465,   522,   604,   665,   688,   523,
     524,   525,   526,   566,   527,   108,   364,   365,    83,    84,
      85,   126,   127,   440,   489,   113,   258,    86,   383,   384,
      87,   491,   356,   492,    88,    89,   460,    90,    91,   222,
     223,   418,    92,    93,    94,    95,    96,    97,   349,   344,
     345,   346,    98,   254,   255,   230,   231,    99,   251,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -487
static const yytype_int16 yypact[] =
{
    -487,    46,  2564,  -487,  -487,  -487,   -84,  3606,  -487,  3717,
    -487,  -487,  4827,   -66,   -57,   -41,  -487,  -487,  -487,   -83,
    -487,  4827,  4827,    42,    54,   -75,  4827,  4827,  4827,  3828,
     -10,  -487,    75,   -68,  -487,  -487,  -487,  -487,    91,  -487,
      97,  4827,  -487,  4827,    81,  -487,  -487,  -487,   -34,   -34,
    4827,  4827,  4827,  4827,  4827,  4827,  4827,  -487,   -73,  -487,
    -487,  -487,  -487,  4827,  4827,  4827,  4827,  4827,  4827,  -487,
    -487,    80,  -487,  -487,    86,    99,  -487,  -487,  -487,  -487,
    -487,   116,   126,  -487,  -487,    40,  -487,  -487,  4965,  -487,
     -44,   524,   102,  -487,   154,  -487,    73,  -487,   -27,  -487,
    -487,  3939,  -487,  5029,  -487,  5093,   112,  3495,   -87,  5989,
     -34,  4827,  4050,  -487,   113,   129,  -487,   -93,   -23,  -487,
    5989,  5989,   -34,   -15,   169,   171,   118,  -487,   170,     7,
     -27,  6109,  5989,  5989,  -487,   122,  5989,   895,   144,   -11,
     128,   -34,  -487,   155,   130,   131,  -487,  -487,  -487,   127,
    5157,   132,   136,   188,  -487,  -487,  -487,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  4161,    -6,    -6,   233,  -487,  -487,
    5221,  1222,  4827,  4827,  4827,  -487,   244,   -21,  4827,  4827,
    4827,   -75,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,
    4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,
    4827,  4827,  4827,  4827,  4827,  -487,  -487,  -487,  4827,  4827,
    4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4272,
    4161,   -80,   154,  -487,  4827,  4827,    80,   111,   -34,  5797,
     142,   163,  -487,  -487,   173,   231,  4827,  -487,   149,  5285,
    -487,  5349,  4827,  -487,   179,  4827,  -487,  -487,   -83,  -487,
    -487,   -97,   194,  -487,    17,  -487,   -12,  4161,  -487,   -80,
       7,  -487,  -487,   477,   220,  -487,  4827,    30,  -487,  -487,
     198,  -487,  4827,  -487,  -487,   199,    29,   -34,   201,   219,
      64,   975,  -487,   204,  -487,  -487,  -487,  -487,  -487,   744,
    5413,   330,   837,   309,   232,   208,   216,   221,     7,   -27,
    6109,   560,  6053,  -487,  5956,  5956,  5956,  5956,   571,   571,
     114,   114,  6183,  1083,   823,  5861,  4870,  6200,  6256,   571,
     571,    -6,    -6,    -6,   233,   233,   233,  6109,  6109,  6109,
    6109,  6109,  6109,  6109,  6109,  6109,  6109,  6109,   -31,  6109,
     218,  -487,  4827,  -487,   223,    14,  -487,  -487,  5989,   214,
     881,  -487,  -487,  4383,  -487,  4494,  -487,   242,    65,   225,
    5989,  -487,  -487,  -487,   224,   247,  5989,  -487,   960,  -487,
     -34,  -487,   -15,   -15,   249,  -487,   228,  -487,   236,   281,
     477,   477,  -487,  -487,  -487,   255,  5477,   -34,   245,  -487,
    5541,  1357,  -487,   216,  -487,  -487,  4605,   237,  -487,  2830,
     -34,   -40,   232,   319,  -487,   265,  -487,  -487,  4161,  4161,
       7,  -487,  4827,   -75,  -487,  -487,  1018,  4161,  -487,  4827,
    4827,  -487,  -487,   -34,  5989,   -34,  5925,   477,   273,  2963,
    4827,  4827,  4827,   250,  -487,  -487,    69,  -487,  4827,  -487,
     302,   477,   277,  -487,  -487,   477,   -86,  -487,  -487,  3096,
     323,   -34,    70,  1034,   254,  -487,  -487,   311,   -34,   311,
    -487,  -487,   232,   257,   232,    -8,   260,   270,  6127,   118,
    -487,   271,   267,  1097,  -487,  -487,  4716,  -487,   292,  -487,
    -487,  -487,  5605,   274,  5989,     2,  -487,  6109,   -80,  -487,
     332,   280,   297,  -487,  -487,   282,   283,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  2697,    66,   -40,   285,  -487,   287,
     265,  -487,  -487,   307,  -487,  -487,  -487,  -487,  -487,  -487,
    -487,  -487,  -487,   313,   383,   135,  -487,    -5,  -487,  -487,
    -487,  -487,  -487,  -487,   -34,  5989,   477,  1492,   288,  4827,
    -487,  -487,   291,   312,   -20,  -487,   477,  -487,   477,  -487,
    -487,   167,  -487,     3,  1625,   295,   166,  3495,  -487,  -487,
    -487,  3229,  3229,    11,   314,   317,    31,  -487,  -487,   325,
    -487,  -487,  -487,   299,  -487,   304,   300,    -2,   324,   331,
    -487,   360,   200,  4827,   -76,   308,     4,  -487,   310,   232,
     327,  -487,   417,  -487,   316,  -487,  -487,  -487,  -487,  -487,
     477,   477,   337,  -487,   129,   335,  -487,  3362,  -487,    33,
     477,   336,   477,   318,  4901,  -487,  -487,  -487,  -487,  -487,
    -487,   343,  -487,   321,   320,  4827,  1758,  -487,  -487,   341,
     349,   477,  -487,  -487,  -487,  1891,   345,   353,  -487,   477,
    -487,  -487,  -487,  -487,   333,  2697,  4827,  -487,  5669,   329,
     477,  -487,  -487,  2026,  -487,   477,   350,  -487,  -487,  2697,
     322,  5733,  3495,  -487,  -487,   338,   334,  -487,   477,  2697,
    -487,   351,  -487,     2,  -487,  -487,  2159,  -487,   339,   401,
    2697,    87,  -487,  -487,   401,  -487,  -487,  -487,  -487,   344,
    -487,  2294,   232,  -487,   363,   340,   342,  -487,  2429,  -487
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -487,  -487,  -487,  -487,  -265,  -487,     0,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -487,  -202,
    -487,  -487,   103,  -487,   482,   489,  -112,  -487,  -487,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -487,    32,    34,    -9,
    -487,   -67,  -487,  -487,  -487,  -486,  -487,  -487,  -116,  -487,
    -487,  -487,  -487,  -487,  -487,  -487,  -174,  -487,   -77,  -215,
    -487,  -487,   253,  -487,    -4,  -487,  -487,  -487,  -487,  -487,
    -487,  -487,   -22,  -487,  -487,  -487,  -418,  -487,    -7,  -487,
     -25,  -178,  -487,  -487,  -487,  -487,    36,   107,   186,  -487,
    -487,  -487,    10,  -487,   108,   391,  -196,   183,   355,  -487,
     289,  -487,  -173,  -487,  -487,   -16,    93,  -487,    94,  -258,
    -487,  -487,     1,   138,   139,  -487,  -487,  -487,  -487,  -487
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -309
static const yytype_int16 yytable[] =
{
     125,   377,    73,   303,   297,   340,   513,   540,   391,   128,
     553,   540,   413,   483,  -253,   583,   583,   152,    59,   370,
     584,   584,   135,   153,   153,   513,   130,   252,   116,   236,
     341,    59,   351,   495,   181,   124,    59,   206,   207,   371,
     514,   142,   376,   615,   515,   245,     3,    71,   343,   516,
     237,   101,   496,   517,   518,   519,   520,   117,   342,   514,
      71,   616,   164,   515,   582,    71,   586,   143,   516,   110,
     152,    59,   517,   518,   519,   520,   152,    59,   111,   152,
      59,   394,   458,   375,    59,   153,   343,   557,   558,   296,
      59,   578,   153,   248,   112,   152,    59,   153,   153,    59,
      71,   138,   579,   297,   146,   264,    71,   235,   541,    71,
     147,   569,   541,   226,   249,   103,   153,   105,   129,    71,
     109,   575,   202,   203,   204,    71,   265,   177,    71,   120,
     121,   521,   570,   373,   131,   132,   133,   136,  -121,   393,
      59,   224,   587,   619,   636,   225,   387,   602,   419,   148,
     599,   150,   420,   374,   181,   637,   125,   280,   157,   158,
     159,   160,   161,   162,   163,   128,   388,   291,   603,    71,
    -162,   165,   166,   167,   168,   169,   170,   122,   299,   583,
    -135,   428,   130,   514,   584,   373,  -138,   590,   591,   123,
     504,   227,   516,   466,   467,   585,   517,   518,   519,   520,
    -135,   429,   471,   153,   457,   486,  -138,   224,  -307,   229,
     141,   225,   583,   280,   537,   192,   151,   584,   172,   239,
     241,   173,   299,   260,   686,   687,   175,   474,   613,   475,
     545,   154,   156,   554,   174,   469,   176,   220,   221,   199,
     200,   201,   202,   203,   204,   224,  -308,   234,   242,   225,
     280,   243,   153,   257,   259,   502,  -253,   299,   256,   261,
     299,   263,   508,   266,   270,   273,   272,   271,   275,   406,
     298,   164,   136,   181,   129,   276,   294,   299,   354,   355,
     289,   290,   136,   357,   359,   361,   300,   301,   302,   367,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   153,   298,   343,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   339,   136,   372,
     626,   385,   348,   350,   389,   396,   392,   395,   571,   397,
     400,   402,   404,   635,   360,   153,   407,   153,   153,   298,
     366,   408,   298,   368,   415,   421,   409,   645,   417,   427,
     430,   431,   153,   432,   439,   136,   438,   653,   442,   298,
     382,   441,   445,   454,   386,   153,   153,   461,   659,   462,
     390,   464,   448,   478,   137,   485,   488,   493,   125,   452,
     501,   503,   410,   669,   506,   511,   528,   128,   153,   456,
     153,   280,   280,   155,   155,   676,   529,   531,   532,   536,
     280,   539,   680,   548,   130,   546,   547,   564,   567,   550,
     552,   561,   691,   562,   565,   574,   153,   576,   577,   480,
     589,   600,   698,   153,   601,   605,   606,   406,   608,   512,
     607,   610,   611,   612,   624,   618,   622,   620,   629,   499,
     416,   625,   631,   639,   644,   641,   646,   647,   650,   651,
     670,   424,   655,   426,   656,   238,   663,   668,   682,   660,
     677,   674,   247,   673,   695,   681,   696,   250,   253,   692,
     697,   153,   690,     4,    77,     5,   378,   382,   382,   299,
     447,    78,   630,   509,   510,   598,   269,   560,   642,   678,
     609,   369,   549,   568,   136,   530,   129,   563,   246,   153,
     436,   347,   437,   472,     0,     0,   136,   136,     0,   281,
     468,     0,     0,     0,     0,   136,     0,   348,   473,   292,
       0,    35,    36,    37,   382,     0,     0,     0,   482,   366,
     484,     0,     0,     0,     0,     0,   487,     0,   382,    45,
      46,    47,   382,     0,     0,     0,     0,   593,     0,     0,
       0,   596,   596,   178,   621,   180,   443,   444,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,     0,     0,
       0,   298,     0,   352,   535,     0,    57,   379,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,     0,   380,   381,     0,  -299,  -299,   633,     0,     0,
       0,   181,   281,   477,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,     0,   490,     0,     0,
       0,   494,   352,     0,     0,   182,   183,   184,   185,   186,
     187,   219,     0,   382,     0,   188,   189,   366,   190,   191,
    -309,  -309,     0,   382,     0,   382,   188,   189,     0,     0,
       0,   192,   672,     0,     0,     0,     0,   694,     0,     0,
       0,     0,   192,     0,     0,     0,     0,     0,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   614,     0,   414,  -309,  -309,   199,   200,   201,   202,
     203,   204,     0,     0,     0,     0,     0,   382,   382,     0,
       0,     0,     0,     0,     0,     0,     0,   382,     0,   382,
       0,     0,   572,     0,     0,   435,     0,   253,   253,     0,
       0,     0,   580,   648,   581,     0,     0,     0,   382,     0,
       0,     0,   269,     0,     0,     0,   382,   178,   179,   180,
       0,   453,     0,     0,   661,   352,   352,   382,     0,     0,
       0,     0,   382,   281,   281,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,   382,     0,     0,   352,     0,
     352,     0,     0,     0,   181,     0,   627,   628,     0,     0,
       0,     0,     0,     0,     0,     0,   638,     0,   640,     0,
       0,     0,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,   352,     0,     0,     0,   652,     0,   182,
     183,   184,   185,   186,   187,   657,   178,   179,   180,   188,
     189,     0,   190,   191,     0,     0,   664,     0,     0,     0,
       0,   667,     0,     0,     0,   192,     0,   401,     0,     0,
       0,     0,     0,     0,   675,     0,     0,     0,     0,     0,
       0,   352,   193,   181,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,     0,     0,     0,     0,     0,
       0,     0,     0,   398,   178,   179,   180,     0,     0,   352,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,   188,   189,
       0,   190,   191,     0,     0,     0,     0,     0,  -299,  -299,
       0,   181,     0,     0,   192,     0,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,     0,
       0,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   219,     0,   182,   183,   184,   185,
     186,   187,   411,   178,   179,   180,   188,   189,     0,   190,
     191,     0,     0,     0,     0,     0,  -299,  -299,     0,     0,
       0,     0,   192,     0,     0,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,     0,     0,   193,
     181,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   219,     0,     0,     0,     0,     0,     0,     0,
     422,   178,   179,   180,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,   182,   183,   184,   185,   186,
     187,     0,     0,     0,     0,   188,   189,     0,   190,   191,
       0,     0,     0,     0,     0,     0,  -299,  -299,   181,     0,
       0,   192,     0,     0,     0,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,     0,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,  -136,   219,   182,   183,   184,   185,   186,   187,   434,
     178,   179,   180,   188,   189,     0,   190,   191,     0,     0,
       0,  -136,     0,     0,     0,  -299,  -299,     0,     0,   192,
       0,     0,     0,   181,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   193,   181,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,     0,
    -139,   219,     0,     0,     0,     0,     0,   470,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,   188,   189,
    -139,     0,   182,   183,   184,   185,   186,   187,     0,     0,
       0,     0,   188,   189,   192,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,     0,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,     4,     0,
       5,     6,     0,     7,     0,     8,   533,     9,    10,     0,
       0,    11,    12,     0,     0,    13,     0,     0,     0,     0,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
       0,    39,     0,     0,     0,     0,    40,    41,    42,     0,
      43,     0,     0,   283,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,     0,
       0,     0,     0,    65,    66,    67,     0,    68,     0,    69,
      70,   284,    71,     4,     0,     5,     6,     0,     7,     0,
       8,     0,     9,    10,     0,     0,    11,    12,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,     0,    39,     0,     0,     0,
       0,    40,    41,    42,     0,    43,     0,     0,   283,    45,
      46,    47,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,    65,    66,
      67,     0,    68,     0,    69,    70,   450,    71,     4,     0,
       5,     6,     0,     7,     0,     8,     0,     9,    10,     0,
       0,    11,    12,     0,     0,    13,   573,     0,     0,     0,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
       0,    39,     0,     0,     0,     0,    40,    41,    42,     0,
      43,     0,     0,   283,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,     0,
       0,     0,     0,    65,    66,    67,     0,    68,     0,    69,
      70,     4,    71,     5,     6,     0,     7,     0,     8,     0,
       9,    10,     0,     0,    11,    12,     0,     0,    13,     0,
       0,     0,     0,     0,   588,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,     0,    39,     0,     0,     0,     0,    40,
      41,    42,     0,    43,     0,     0,   283,    45,    46,    47,
       0,     0,     0,     0,     0,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,    65,    66,    67,     0,
      68,     0,    69,    70,     4,    71,     5,     6,     0,     7,
       0,     8,     0,     9,    10,     0,     0,    11,    12,     0,
       0,    13,     0,     0,   649,     0,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,     0,    39,     0,     0,
       0,     0,    40,    41,    42,     0,    43,     0,     0,   283,
      45,    46,    47,     0,     0,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,     0,     0,     0,     0,    65,
      66,    67,     0,    68,     0,    69,    70,     4,    71,     5,
       6,     0,     7,     0,     8,     0,     9,    10,     0,     0,
      11,    12,     0,     0,    13,     0,     0,     0,     0,     0,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,     0,
      39,     0,     0,     0,     0,    40,    41,    42,     0,    43,
       0,     0,   283,    45,    46,    47,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,     0,    65,    66,    67,     0,    68,     0,    69,    70,
     654,    71,     4,     0,     5,     6,     0,     7,     0,     8,
       0,     9,    10,     0,     0,    11,    12,     0,     0,    13,
       0,   666,     0,     0,     0,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
      35,    36,    37,    38,     0,    39,     0,     0,     0,     0,
      40,    41,    42,     0,    43,     0,     0,   283,    45,    46,
      47,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,    65,    66,    67,
       0,    68,     0,    69,    70,     4,    71,     5,     6,     0,
       7,     0,     8,     0,     9,    10,     0,     0,    11,    12,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,     0,    39,     0,
       0,     0,     0,    40,    41,    42,     0,    43,     0,     0,
     283,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
      65,    66,    67,     0,    68,     0,    69,    70,   679,    71,
       4,     0,     5,     6,     0,     7,     0,     8,     0,     9,
      10,     0,     0,    11,    12,     0,     0,    13,     0,     0,
       0,     0,     0,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,     0,    39,     0,     0,     0,     0,    40,    41,
      42,     0,    43,     0,     0,   283,    45,    46,    47,     0,
       0,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,     0,    65,    66,    67,     0,    68,
       0,    69,    70,   693,    71,     4,     0,     5,     6,     0,
       7,     0,     8,     0,     9,    10,     0,     0,    11,    12,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,     0,    39,     0,
       0,     0,     0,    40,    41,    42,     0,    43,     0,     0,
     283,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
      65,    66,    67,     0,    68,     0,    69,    70,   699,    71,
       4,     0,     5,     6,     0,     7,     0,     8,     0,     9,
      10,     0,     0,    11,    12,     0,     0,    13,     0,     0,
       0,     0,     0,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,     0,    39,     0,     0,     0,     0,    40,    41,
      42,     0,    43,     0,     0,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,     0,    65,    66,    67,     0,    68,
       0,    69,    70,     4,    71,     5,     6,     0,     7,     0,
       8,     0,     9,    10,     0,     0,    11,    12,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,     0,    39,     0,     0,     0,
       0,    40,    41,    42,     0,    43,     0,     0,   283,    45,
      46,    47,     0,     0,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
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
      58,    59,    60,    61,    62,     0,     0,     0,     0,   455,
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
       0,     0,   479,     0,     0,     0,     0,     0,    63,    64,
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
      62,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,    65,    66,    67,
       0,    68,     0,    69,    70,     4,    71,     5,     6,     0,
       7,     0,     0,     0,     9,    10,     0,     0,    11,    12,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    14,
      15,     0,    16,    17,     0,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
      65,    66,    67,     0,    68,     0,    69,    70,     4,    71,
       5,     6,     0,     7,     0,     0,     0,     9,    10,     0,
       0,    11,    12,     0,     0,    13,     0,     0,     0,     0,
       0,     0,    14,    15,     0,    16,    17,     0,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     0,     0,     0,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,   632,     0,     0,     0,     0,     0,    63,    64,     0,
       0,     0,     0,    65,    66,    67,     0,    68,     0,    69,
      70,     4,    71,     5,     6,     0,     7,     0,     0,     0,
       9,    10,     0,     0,    11,    12,     0,     0,    13,     0,
       0,     0,     0,     0,     0,    14,    15,     0,    16,    17,
       0,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    42,     0,    43,     0,     0,     0,    45,    46,    47,
       0,     0,     0,     0,     0,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     4,     0,     5,     6,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,    65,    66,    67,    13,
      68,     0,    69,    70,     0,    71,    14,    15,     0,     0,
       0,     0,     0,     0,    21,    22,     0,    23,    24,    25,
      26,    27,    28,     0,     0,     0,     0,     0,     0,     0,
      35,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,    45,    46,
      47,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,     4,     0,     5,     6,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,    65,    66,    67,
      13,    68,     0,   102,     0,     0,    71,    14,    15,     0,
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
      67,    13,    68,     0,   104,     0,     0,    71,    14,    15,
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
      66,    67,    13,    68,     0,   134,     0,     0,    71,    14,
      15,     0,     0,     0,     0,     0,     0,    21,    22,     0,
      23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,    35,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     4,     0,     5,     6,
       0,   228,     0,     0,    63,    64,     0,     0,     0,     0,
      65,    66,    67,    13,    68,     0,     0,     0,     0,    71,
      14,    15,     0,     0,     0,     0,     0,     0,    21,    22,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,     0,     0,    35,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,     0,     0,     0,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,     4,     0,     5,
       6,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,    65,    66,    67,    13,    68,   240,     0,     0,     0,
      71,    14,    15,     0,     0,     0,     0,     0,     0,    21,
      22,     0,    23,    24,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     4,     0,
       5,     6,     0,   277,     0,     0,    63,    64,     0,     0,
       0,     0,    65,    66,    67,    13,    68,     0,     0,     0,
       0,    71,    14,    15,     0,     0,     0,     0,     0,     0,
      21,    22,     0,    23,    24,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,    35,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,     4,
       0,     5,     6,     0,   338,     0,     0,    63,    64,     0,
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
       4,     0,     5,     6,     0,   423,     0,     0,    63,    64,
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
       0,     4,     0,     5,     6,     0,   425,     0,     0,    63,
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
       0,     0,     4,     0,     5,     6,     0,   451,     0,     0,
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
       0,     0,     0,     4,     0,     5,     6,     0,   534,     0,
       0,    63,    64,     0,     0,     0,     0,    65,    66,    67,
      13,    68,     0,     0,     0,     0,    71,    14,    15,     0,
       0,     0,     0,     0,     0,    21,    22,     0,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    37,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,   178,   179,   180,     0,    48,    49,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   181,     0,     0,     0,   182,   183,   184,   185,   186,
     187,     0,    63,    64,     0,   188,   189,     0,    65,    66,
      67,     0,    68,     0,     0,     0,     0,    71,   178,   179,
     180,   192,     0,     0,     0,     0,   182,   183,   184,   185,
     186,   187,     0,     0,     0,     0,   188,   189,     0,   190,
     191,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,     0,   192,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
     615,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   178,   179,   180,     0,     0,     0,   616,     0,
     182,   183,   184,   185,   186,   187,     0,     0,     0,     0,
     188,   189,     0,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   178,   179,   180,     0,
       0,     0,   205,     0,   182,   183,   184,   185,   186,   187,
       0,     0,     0,     0,   188,   189,     0,   190,   191,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     178,   179,   180,     0,     0,     0,   232,     0,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,   188,   189,
       0,   190,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   178,   179,   180,     0,     0,     0,
     233,     0,   182,   183,   184,   185,   186,   187,     0,     0,
       0,     0,   188,   189,     0,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   178,   179,
     180,     0,     0,     0,   274,     0,   182,   183,   184,   185,
     186,   187,     0,     0,     0,     0,   188,   189,     0,   190,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   178,   179,   180,     0,     0,   282,     0,     0,
     182,   183,   184,   185,   186,   187,     0,     0,     0,     0,
     188,   189,     0,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   178,   179,   180,     0,
       0,   362,     0,     0,   182,   183,   184,   185,   186,   187,
       0,     0,     0,     0,   188,   189,     0,   190,   191,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     178,   179,   180,     0,     0,   363,     0,     0,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,   188,   189,
       0,   190,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   178,   179,   180,     0,     0,   399,
       0,     0,   182,   183,   184,   185,   186,   187,     0,     0,
       0,     0,   188,   189,     0,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   178,   179,
     180,     0,     0,   446,     0,     0,   182,   183,   184,   185,
     186,   187,     0,     0,     0,     0,   188,   189,     0,   190,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   178,   179,   180,     0,     0,   449,     0,     0,
     182,   183,   184,   185,   186,   187,     0,     0,     0,     0,
     188,   189,     0,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   178,   179,   180,     0,
       0,   538,     0,     0,   182,   183,   184,   185,   186,   187,
       0,     0,     0,     0,   188,   189,     0,   190,   191,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     178,   179,   180,     0,     0,   662,     0,     0,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,   188,   189,
       0,   190,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   178,   179,   180,     0,     0,   671,
       0,     0,   182,   183,   184,   185,   186,   187,     0,     0,
     353,     0,   188,   189,     0,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   178,   179,
     180,     0,     0,     0,     0,     0,   182,   183,   184,   185,
     186,   187,     0,     0,     0,     0,   188,   189,     0,   190,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
     412,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   178,   179,   180,     0,   181,     0,     0,     0,
     182,   183,   184,   185,   186,   187,     0,     0,   476,     0,
     188,   189,     0,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,   181,
       0,  -309,  -309,  -309,  -309,   186,   187,     0,     0,     0,
       0,   188,   189,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   178,   192,     0,     0,
       0,     0,     0,     0,   182,   183,   184,   185,   186,   187,
       0,     0,     0,     0,   188,   189,     0,   190,   191,   197,
     198,   199,   200,   201,   202,   203,   204,     0,     0,     0,
     192,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,   188,   189,
       0,   190,   191,     0,     0,     0,     0,     0,     0,   181,
       0,     0,     0,     0,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   182,   183,   184,   185,   186,   187,
       0,     0,     0,     0,   188,   189,     0,   190,   191,     0,
       0,     0,   182,   183,   184,   185,   186,   187,     0,     0,
     192,     0,   188,   189,     0,   190,   191,     0,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   193,   192,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     181,     0,     0,     0,     0,     0,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,   188,   189,
       0,     0,   191,     0,     0,   182,   183,   184,   185,   186,
     187,     0,     0,     0,   192,   188,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,     0,     0,     0,
       0,   192,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,     0,     0,     0,     0,     0,
       0,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   182,   183,   184,   185,   186,   187,     0,     0,     0,
       0,   188,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     198,   199,   200,   201,   202,   203,   204
};

static const yytype_int16 yycheck[] =
{
      25,   259,     2,   181,   177,   220,    14,     9,   273,    25,
     496,     9,    43,   431,    87,    12,    12,   110,   111,   116,
      17,    17,    29,    48,    49,    14,    25,    42,   111,   116,
     110,   111,   228,   119,    40,   110,   111,    81,    82,   136,
      48,   109,   257,   119,    52,   138,     0,   140,   221,    57,
     137,   135,   138,    61,    62,    63,    64,   140,   138,    48,
     140,   137,   135,    52,   550,   140,   552,   135,    57,   135,
     110,   111,    61,    62,    63,    64,   110,   111,   135,   110,
     111,   277,   122,   256,   111,   110,   259,    21,    22,   110,
     111,   111,   117,   116,   135,   110,   111,   122,   123,   111,
     140,   111,   122,   276,    13,   116,   140,   107,   110,   140,
      13,   116,   110,   140,   137,     7,   141,     9,    25,   140,
      12,   539,   128,   129,   130,   140,   137,    87,   140,    21,
      22,   139,   137,   116,    26,    27,    28,    29,   136,   110,
     111,   134,   139,   139,   111,   138,   116,   116,   134,    41,
     139,    43,   138,   136,    40,   122,   181,   164,    50,    51,
      52,    53,    54,    55,    56,   181,   136,   174,   137,   140,
      35,    63,    64,    65,    66,    67,    68,   135,   177,    12,
     116,   116,   181,    48,    17,   116,   116,    21,    22,   135,
     455,    98,    57,   408,   409,    28,    61,    62,    63,    64,
     136,   136,   417,   228,   400,   136,   136,   134,   135,   101,
     135,   138,    12,   220,   479,   101,   135,    17,   138,   111,
     112,   135,   221,   130,   137,   138,   110,   423,    28,   425,
     488,    48,    49,   498,   135,   413,   110,   135,    84,   125,
     126,   127,   128,   129,   130,   134,   135,   135,   135,   138,
     257,   122,   277,   135,    84,   451,    87,   256,    87,   137,
     259,   117,   458,   135,   109,   138,   135,   137,   136,   294,
     177,   135,   164,    40,   181,    87,    32,   276,   136,   116,
     172,   173,   174,   110,    53,   136,   178,   179,   180,   110,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   338,   221,   488,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   135,
     595,   111,   224,   225,   136,   116,   137,   136,   534,   135,
      10,    32,   110,   608,   236,   370,   138,   372,   373,   256,
     242,   135,   259,   245,   136,   141,   135,   622,   135,   117,
     135,   137,   387,   116,   136,   257,   117,   632,    87,   276,
     263,   135,   117,   136,   266,   400,   401,   402,   643,    60,
     272,   116,   137,   110,    29,   135,    84,   110,   413,   396,
      67,   137,   299,   658,    83,   138,   136,   413,   423,   399,
     425,   408,   409,    48,    49,   670,   136,   136,   141,   117,
     417,   137,   677,   116,   413,    83,   136,   110,    35,   137,
     137,   136,   687,   136,   111,   137,   451,   136,   116,   429,
     135,   117,   697,   458,   117,   110,   137,   462,   138,   464,
     136,   117,   111,    83,    27,   137,   119,   137,   111,   449,
     342,   135,   117,   117,   111,   137,   135,   137,   117,   110,
     138,   353,   117,   355,   111,   110,   137,   117,    67,   136,
     119,   137,   117,   135,   111,   136,   136,   122,   123,   135,
     138,   506,   684,     6,     2,     8,     9,   380,   381,   488,
     387,     2,   604,   459,   462,   562,   141,   506,   614,   673,
     577,   248,   492,   525,   396,   469,   413,   511,   117,   534,
     372,   222,   373,   419,    -1,    -1,   408,   409,    -1,   164,
     412,    -1,    -1,    -1,    -1,   417,    -1,   419,   420,   174,
      -1,    54,    55,    56,   427,    -1,    -1,    -1,   430,   431,
     432,    -1,    -1,    -1,    -1,    -1,   438,    -1,   441,    72,
      73,    74,   445,    -1,    -1,    -1,    -1,   557,    -1,    -1,
      -1,   561,   562,     3,   589,     5,   380,   381,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,   488,    -1,   228,   476,    -1,   109,   110,    -1,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,   125,   126,    -1,    81,    82,   607,    -1,    -1,
      -1,    40,   257,   427,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,   441,    -1,    -1,
      -1,   445,   277,    -1,    -1,    75,    76,    77,    78,    79,
      80,   117,    -1,   536,    -1,    85,    86,   539,    88,    89,
      79,    80,    -1,   546,    -1,   548,    85,    86,    -1,    -1,
      -1,   101,   662,    -1,    -1,    -1,    -1,   692,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   583,    -1,   338,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,   600,   601,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,   612,
      -1,    -1,   536,    -1,    -1,   370,    -1,   372,   373,    -1,
      -1,    -1,   546,   625,   548,    -1,    -1,    -1,   631,    -1,
      -1,    -1,   387,    -1,    -1,    -1,   639,     3,     4,     5,
      -1,   396,    -1,    -1,   646,   400,   401,   650,    -1,    -1,
      -1,    -1,   655,   408,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   417,    -1,    -1,   668,    -1,    -1,   423,    -1,
     425,    -1,    -1,    -1,    40,    -1,   600,   601,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,   612,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,   631,    -1,    75,
      76,    77,    78,    79,    80,   639,     3,     4,     5,    85,
      86,    -1,    88,    89,    -1,    -1,   650,    -1,    -1,    -1,
      -1,   655,    -1,    -1,    -1,   101,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,
      -1,   506,   118,    40,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,     3,     4,     5,    -1,    -1,   534,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    40,    -1,    -1,   101,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   117,    -1,    75,    76,    77,    78,
      79,    80,   139,     3,     4,     5,    85,    86,    -1,    88,
      89,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,   118,
      40,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    40,    -1,
      -1,   101,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   118,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   116,   117,    75,    76,    77,    78,    79,    80,   139,
       3,     4,     5,    85,    86,    -1,    88,    89,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    81,    82,    -1,    -1,   101,
      -1,    -1,    -1,    40,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   118,    40,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     116,   117,    -1,    -1,    -1,    -1,    -1,   139,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
     136,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,   101,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     6,    -1,
       8,     9,    -1,    11,    -1,    13,   139,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
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
     138,   139,   140,     6,    -1,     8,     9,    -1,    11,    -1,
      13,    -1,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,   135,    -1,   137,   138,   139,   140,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    -1,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    34,
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
      -1,    23,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,
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
       9,    -1,    11,    -1,    13,    -1,    15,    16,    -1,    -1,
      19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    -1,
      59,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,   135,    -1,   137,   138,
     139,   140,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      -1,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    23,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
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
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
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
     131,   132,   133,    -1,   135,    -1,   137,   138,   139,   140,
       6,    -1,     8,     9,    -1,    11,    -1,    13,    -1,    15,
      16,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    -1,    59,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,   135,
      -1,   137,   138,   139,   140,     6,    -1,     8,     9,    -1,
      11,    -1,    13,    -1,    15,    16,    -1,    -1,    19,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
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
     131,   132,   133,    -1,   135,    -1,   137,   138,   139,   140,
       6,    -1,     8,     9,    -1,    11,    -1,    13,    -1,    15,
      16,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    -1,    59,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,   135,
      -1,   137,   138,     6,   140,     8,     9,    -1,    11,    -1,
      13,    -1,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     114,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,   135,    -1,   137,   138,     6,   140,     8,     9,    -1,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    19,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    -1,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    68,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,   135,    -1,   137,   138,     6,   140,
       8,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,   125,   126,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,   135,    -1,   137,
     138,     6,   140,     8,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,    23,
     135,    -1,   137,   138,    -1,   140,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,
      23,   135,    -1,   137,    -1,    -1,   140,    30,    31,    -1,
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
      -1,   122,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,
     131,   132,   133,    23,   135,    -1,    -1,    -1,    -1,   140,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    -1,
      -1,   131,   132,   133,    23,   135,   136,    -1,    -1,    -1,
     140,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,     6,    -1,
       8,     9,    -1,   122,    -1,    -1,   125,   126,    -1,    -1,
      -1,    -1,   131,   132,   133,    23,   135,    -1,    -1,    -1,
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
      73,    74,    -1,    -1,     3,     4,     5,    -1,    81,    82,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    40,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,   125,   126,    -1,    85,    86,    -1,   131,   132,
     133,    -1,   135,    -1,    -1,    -1,    -1,   140,     3,     4,
       5,   101,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      89,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   101,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     3,     4,     5,    -1,    -1,    -1,   137,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     3,     4,     5,    -1,
      -1,    -1,   137,    -1,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       3,     4,     5,    -1,    -1,    -1,   137,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     3,     4,     5,    -1,    -1,    -1,
     137,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     3,     4,
       5,    -1,    -1,    -1,   137,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     3,     4,     5,    -1,    -1,   136,    -1,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     3,     4,     5,    -1,
      -1,   136,    -1,    -1,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       3,     4,     5,    -1,    -1,   136,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     3,     4,     5,    -1,    -1,   136,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     3,     4,
       5,    -1,    -1,   136,    -1,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     3,     4,     5,    -1,    -1,   136,    -1,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     3,     4,     5,    -1,
      -1,   136,    -1,    -1,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       3,     4,     5,    -1,    -1,   136,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     3,     4,     5,    -1,    -1,   136,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     3,     4,     5,    -1,    40,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    83,    -1,
      85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    40,
      -1,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,   118,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     3,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
     101,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
     101,    -1,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,   118,   101,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      40,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    89,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,   101,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,   101,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,   130
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
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
     261,   135,   137,   236,   137,   236,   156,   153,   217,   236,
     135,   135,   135,   227,   154,   170,   111,   140,   203,   204,
     236,   236,   135,   135,   110,   222,   223,   224,   247,   248,
     254,   236,   236,   236,   137,   220,   236,   240,   111,   205,
     155,   135,   109,   135,   165,   152,    13,    13,   236,   157,
     236,   135,   110,   222,   239,   240,   239,   236,   236,   236,
     236,   236,   236,   236,   135,   236,   236,   236,   236,   236,
     236,   146,   138,   135,   135,   110,   110,    87,     3,     4,
       5,    40,    75,    76,    77,    78,    79,    80,    85,    86,
      88,    89,   101,   118,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   137,    81,    82,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   117,
     135,    84,   241,   242,   134,   138,   140,   248,   122,   236,
     257,   258,   137,   137,   135,   148,   116,   137,   240,   236,
     136,   236,   135,   122,   168,   138,   237,   240,   116,   137,
     240,   260,    42,   240,   255,   256,    87,   135,   228,    84,
     248,   137,   137,   117,   116,   137,   135,   163,   164,   240,
     109,   137,   135,   138,   137,   136,    87,   122,   201,   202,
     220,   240,   136,    71,   139,   147,   148,   166,   167,   236,
     236,   220,   240,   173,    32,   177,   110,   244,   248,   254,
     236,   236,   236,   223,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   122,   236,
     201,   110,   138,   244,   251,   252,   253,   242,   236,   250,
     236,   238,   240,    83,   136,   116,   234,   110,   185,    53,
     236,   136,   136,   136,   218,   219,   236,   110,   236,   204,
     116,   136,   135,   116,   136,   244,   201,   251,     9,   110,
     125,   126,   229,   230,   231,   111,   236,   116,   136,   136,
     236,   146,   137,   110,   238,   136,   116,   135,   139,   136,
      10,    10,    32,   175,   110,   179,   222,   138,   135,   135,
     248,   139,   119,    43,   240,   136,   236,   135,   243,   134,
     138,   141,   139,   122,   236,   122,   236,   117,   116,   136,
     135,   137,   116,   171,   139,   240,   255,   256,   117,   136,
     225,   135,    87,   230,   230,   117,   136,   164,   137,   136,
     139,   122,   220,   240,   136,   119,   148,   238,   122,   181,
     238,   222,    60,   178,   116,   206,   201,   201,   236,   223,
     139,   201,   250,   236,   238,   238,    83,   230,   110,   119,
     148,   184,   236,   218,   236,   135,   136,   236,    84,   226,
     230,   233,   235,   110,   230,   119,   138,   186,   119,   148,
     191,    67,   238,   137,   146,   192,    83,   180,   238,   180,
     179,   138,   222,    14,    48,    52,    57,    61,    62,    63,
      64,   139,   207,   211,   212,   213,   214,   216,   136,   136,
     228,   136,   141,   139,   122,   236,   117,   146,   136,   137,
       9,   110,   198,   199,   200,   251,    83,   136,   116,   234,
     137,   187,   137,   187,   146,   158,   194,    21,    22,   196,
     181,   136,   136,   206,   110,   111,   215,    35,   214,   116,
     137,   238,   230,    24,   137,   218,   136,   116,   111,   122,
     230,   230,   187,    12,    17,    28,   187,   139,    29,   135,
      21,    22,   197,   148,   193,   119,   148,   183,   183,   139,
     117,   117,   116,   137,   208,   110,   137,   136,   138,   200,
     117,   111,    83,    28,   236,   119,   137,   190,   137,   139,
     137,   222,   119,   195,    27,   135,   146,   230,   230,   111,
     168,   117,   119,   148,   182,   146,   111,   122,   230,   117,
     230,   137,   190,   189,   111,   146,   135,   137,   236,    26,
     117,   110,   230,   146,   139,   117,   111,   230,   188,   146,
     136,   236,   136,   137,   230,   209,    25,   230,   117,   146,
     138,   136,   148,   135,   137,   230,   146,   119,   198,   139,
     146,   136,    67,   159,   160,   161,   137,   138,   210,   162,
     161,   146,   135,   139,   222,   111,   136,   138,   146,   139
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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (context, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
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
    while (YYID (0))
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, context); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, PHP_context* context)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    PHP_context* context;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (context);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, PHP_context* context)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    PHP_context* context;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, context);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, PHP_context* context)
#else
static void
yy_reduce_print (yyvsp, yyrule, context)
    YYSTYPE *yyvsp;
    int yyrule;
    PHP_context* context;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , context);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, context); \
} while (YYID (0))

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
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
      YYSIZE_T yyn = 0;
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
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
      int yychecklim = YYLAST - yyn + 1;
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
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
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
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, PHP_context* context)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, context)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    PHP_context* context;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (context);

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
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (PHP_context* context);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


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
	yytype_int16 *yyss1 = yyss;
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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
			CAST_AST(body, (yyvsp[(1) - (1)]), AST_statement_list);
		
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
#line 333 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(statement_list, (yyvsp[(1) - (2)]), AST_statement_list);

			// Ignore null statements
			if((yyvsp[(2) - (2)]))
			{
				CAST_UNSAFE(statement, (yyvsp[(2) - (2)]), AST_statement);
			
				if(statement == NULL)
				{
					CAST_AST(statements, (yyvsp[(2) - (2)]), AST_statement_list);
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
#line 355 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_statement_list; ;}
    break;

  case 5:
#line 365 "src/generated_src/php_parser.ypp"
    {
			(yyval) = (yyvsp[(1) - (1)]); 
		;}
    break;

  case 6:
#line 369 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 7:
#line 371 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 8:
#line 373 "src/generated_src/php_parser.ypp"
    {
			// Note: we never generate K_HALT_COMPILER
			(yyval) = NULL;
		;}
    break;

  case 9:
#line 386 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(statement_list, (yyvsp[(1) - (2)]), AST_statement_list);

			// Ignore null statements
			if((yyvsp[(2) - (2)]))
			{
				CAST_UNSAFE(statement, (yyvsp[(2) - (2)]), AST_statement);

				if(statement == NULL)
				{
					CAST_AST(statements, (yyvsp[(2) - (2)]), AST_statement_list);
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
#line 408 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_statement_list; ;}
    break;

  case 11:
#line 416 "src/generated_src/php_parser.ypp"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		;}
    break;

  case 12:
#line 420 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 13:
#line 422 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 14:
#line 424 "src/generated_src/php_parser.ypp"
    {
			// Note: we never generate K_HALT_COMPILER
			(yyval) = NULL;
		;}
    break;

  case 15:
#line 435 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 16:
#line 444 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_if, ()); ;}
    break;

  case 17:
#line 453 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_foreach, ()); ;}
    break;

  case 18:
#line 461 "src/generated_src/php_parser.ypp"
    { 
			(yyval) = (yyvsp[(2) - (3)]);
		;}
    break;

  case 19:
#line 465 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_if, (yyvsp[(1) - (7)]), AST_if);
			CAST_AST(expr, (yyvsp[(3) - (7)]), AST_expr);
			CAST_STATEMENT_VECTOR(iftrue, (yyvsp[(5) - (7)]));
			CAST_AST(elseif, (yyvsp[(6) - (7)]), AST_if);
			CAST_STATEMENT_VECTOR(iffalse, (yyvsp[(7) - (7)]));
			
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
#line 504 "src/generated_src/php_parser.ypp"
    {
			// Duplication of logic above for K_IF.
			CAST_AST(new_if, (yyvsp[(1) - (10)]), AST_if);
			CAST_AST(expr, (yyvsp[(3) - (10)]), AST_expr);
			CAST_STATEMENT_VECTOR(iftrue, (yyvsp[(6) - (10)]));
			CAST_AST(elseif, (yyvsp[(7) - (10)]), AST_if);
			CAST_STATEMENT_VECTOR(iffalse, (yyvsp[(8) - (10)]));
			
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
#line 533 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_while, ());;}
    break;

  case 22:
#line 534 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_while, (yyvsp[(1) - (6)]), AST_while);
			CAST_AST(expr, (yyvsp[(4) - (6)]), AST_expr);
			CAST_AST(body, (yyvsp[(6) - (6)]), AST_statement_list);

			new_while->expr = expr;
			new_while->statements = body;

			(yyval) = new_while;
		;}
    break;

  case 23:
#line 544 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_do, ());;}
    break;

  case 24:
#line 545 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_do, (yyvsp[(1) - (8)]), AST_do);
			CAST_STATEMENT_VECTOR(body, (yyvsp[(3) - (8)]));
			CAST_AST(expr, (yyvsp[(6) - (8)]), AST_expr);
			
			new_do->statements = body;
			new_do->expr = expr;
			
			(yyval) = new_do;
		;}
    break;

  case 25:
#line 555 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_for, ());;}
    break;

  case 26:
#line 556 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_for, (yyvsp[(1) - (10)]), AST_for);
			CAST_AST(init, (yyvsp[(4) - (10)]), AST_expr);
			CAST_AST(cond, (yyvsp[(6) - (10)]), AST_expr);
			CAST_AST(incr, (yyvsp[(8) - (10)]), AST_expr);
			CAST_STATEMENT_VECTOR(stmts, (yyvsp[(10) - (10)]));
			
			new_for->init = init;
			new_for->cond = cond;
			new_for->incr = incr;
			new_for->statements = stmts;
			
			(yyval) = new_for;
		;}
    break;

  case 27:
#line 570 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_switch, ());;}
    break;

  case 28:
#line 571 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_switch, (yyvsp[(1) - (6)]), AST_switch);
			CAST_AST(expr, (yyvsp[(4) - (6)]), AST_expr);
			CAST_AST(cases, (yyvsp[(6) - (6)]), AST_switch_case_list);
			
			new_switch->expr = expr;
			new_switch->switch_cases = cases;
			
			(yyval) = new_switch;
		;}
    break;

  case 29:
#line 582 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_break, (NULL)); ;}
    break;

  case 30:
#line 584 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(2) - (3)]), AST_expr);
			
			(yyval) = NEW(AST_break, (expr));
		;}
    break;

  case 31:
#line 590 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_continue, (NULL)); ;}
    break;

  case 32:
#line 592 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (3)]), AST_expr);

			(yyval) = NEW(AST_continue, (expr));
		;}
    break;

  case 33:
#line 598 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_return, (NULL)); ;}
    break;

  case 34:
#line 600 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (3)]), AST_expr);

			(yyval) = NEW(AST_return, (expr));
		;}
    break;

  case 35:
#line 606 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (3)]), AST_expr);

			(yyval) = NEW(AST_return, (expr));
		;}
    break;

  case 36:
#line 612 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(2) - (3)]), List<AST_variable_name*>);
		
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
#line 632 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 38:
#line 634 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 39:
#line 636 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			Token_string* scalar = NEW(Token_string, (str, str));
			AST_expr* fn = NEW(AST_method_invocation, ("echo", scalar));
	
			(yyval) = NEW(AST_eval_expr, (fn));
		;}
    break;

  case 40:
#line 644 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(1) - (2)]), AST_expr);
			
			(yyval) = NEW(AST_eval_expr, (expr));
		;}
    break;

  case 41:
#line 650 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (3)]), Token_string); 
			AST_method_invocation* fn = NEW(AST_method_invocation, ("use", expr));
			
			(yyval) = NEW(AST_eval_expr, (fn));
		;}
    break;

  case 42:
#line 657 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(vars, (yyvsp[(3) - (5)]), List<AST_variable*>);
			AST_statement_list* statements = new AST_statement_list;
			List<AST_variable*>::const_iterator i;
			
			for(i = vars->begin(); i != vars->end(); i++)
				statements->push_back(NEW(AST_unset, (*i)));

			(yyval) = statements;
		;}
    break;

  case 43:
#line 668 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_foreach, (yyvsp[(1) - (8)]), AST_foreach);
			CAST_AST(expr, (yyvsp[(3) - (8)]), AST_expr);
			CAST_AST(var1, (yyvsp[(5) - (8)]), AST_variable);
			CAST_AST(var2, (yyvsp[(6) - (8)]), AST_variable);
			CAST_STATEMENT_VECTOR(body, (yyvsp[(8) - (8)]));
	
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
#line 699 "src/generated_src/php_parser.ypp"
    { 
			// Duplication of the logic in the previous rule
			CAST_AST(new_foreach, (yyvsp[(1) - (8)]), AST_foreach);
			CAST_AST(expr, (yyvsp[(3) - (8)]), AST_expr);
			CAST_AST(var1, (yyvsp[(5) - (8)]), AST_variable);
			CAST_AST(var2, (yyvsp[(6) - (8)]), AST_variable);
			CAST_STATEMENT_VECTOR(body, (yyvsp[(8) - (8)]));
	
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
#line 730 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_declare, ());;}
    break;

  case 46:
#line 731 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_declare, (yyvsp[(1) - (6)]), AST_declare);
			CAST_AST(directives, (yyvsp[(4) - (6)]), AST_directive_list);
			CAST_STATEMENT_VECTOR(statements, (yyvsp[(6) - (6)]));

			new_declare->directives = directives;
			new_declare->statements = statements;

			(yyval) = new_declare;
		;}
    break;

  case 47:
#line 742 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 48:
#line 743 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_try, ());;}
    break;

  case 49:
#line 743 "src/generated_src/php_parser.ypp"
    {(yyvsp[(6) - (6)]) = NEW(AST_catch, ());;}
    break;

  case 50:
#line 744 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(new_try, (yyvsp[(1) - (15)]), AST_try);
			CAST_STATEMENT_VECTOR(try_stat, (yyvsp[(4) - (15)]));
			CAST_AST(new_catch, (yyvsp[(6) - (15)]), AST_catch);
			CAST_AST(class_name, (yyvsp[(9) - (15)]), Token_class_name);
			CAST_STR(var, (yyvsp[(10) - (15)]), Token_variable_name);
			CAST_STATEMENT_VECTOR(catch_stat, (yyvsp[(13) - (15)]));
			CAST_AST(additional_catches, (yyvsp[(15) - (15)]), AST_catch_list);
			
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
#line 767 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (3)]), AST_expr);
			
			(yyval) = NEW(AST_throw, (expr)); 
		;}
    break;

  case 52:
#line 779 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 53:
#line 781 "src/generated_src/php_parser.ypp"
    {
			AST_catch_list* catches = new AST_catch_list;
			(yyval) = catches; 
		;}
    break;

  case 54:
#line 792 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(c, (yyvsp[(1) - (1)]), AST_catch);
			
			AST_catch_list* catches = new AST_catch_list;
			catches->push_back(c);
			
			(yyval) = catches;
		;}
    break;

  case 55:
#line 801 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(catches, (yyvsp[(1) - (2)]), AST_catch_list);
			CAST_AST(c, (yyvsp[(2) - (2)]), AST_catch);
			
			catches->push_back(c);
			
			(yyval) = catches; 
		;}
    break;

  case 56:
#line 815 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_catch, ());;}
    break;

  case 57:
#line 816 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(new_catch, (yyvsp[(1) - (9)]), AST_catch);
			CAST_AST(class_name, (yyvsp[(4) - (9)]), Token_class_name);
			CAST_STR(var, (yyvsp[(5) - (9)]), Token_variable_name);
			CAST_STATEMENT_VECTOR(stat, (yyvsp[(8) - (9)]));
			
			new_catch->class_name = class_name;
			new_catch->variable_name = var;
			new_catch->statements = stat;
			
			(yyval) = new_catch; 
		;}
    break;

  case 58:
#line 835 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(var, (yyvsp[(1) - (1)]), AST_variable);

			List<AST_variable*>* vars = new List<AST_variable*>;
			vars->push_back(var);
			(yyval) = vars;
		;}
    break;

  case 59:
#line 843 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(vars, (yyvsp[(1) - (3)]), List<AST_variable*>);
			CAST_AST(var, (yyvsp[(3) - (3)]), AST_variable);
		
			vars->push_back(var);
			(yyval) = vars; 
		;}
    break;

  case 60:
#line 857 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (1)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (1)]));
			(yyval) = var;
		;}
    break;

  case 61:
#line 869 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			(yyval) = NEW(Token_string, (str, str));
		;}
    break;

  case 62:
#line 874 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[(2) - (3)]), String);
			(yyval) = NEW(Token_string, (str, str))
		;}
    break;

  case 63:
#line 887 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 64:
#line 897 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 65:
#line 905 "src/generated_src/php_parser.ypp"
    { (yyval) = new Integer(0); ;}
    break;

  case 66:
#line 907 "src/generated_src/php_parser.ypp"
    { (yyval) = new Integer(1); ;}
    break;

  case 67:
#line 918 "src/generated_src/php_parser.ypp"
    {(yyvsp[(1) - (1)]) = NEW(AST_method, ());;}
    break;

  case 68:
#line 918 "src/generated_src/php_parser.ypp"
    {context->current_method = dynamic_cast<String*>((yyvsp[(4) - (4)]));;}
    break;

  case 69:
#line 919 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(fn, (yyvsp[(1) - (11)]), AST_method);
			CAST_AST(is_ref, (yyvsp[(3) - (11)]), Integer);
			CAST_STR(name, (yyvsp[(4) - (11)]), Token_method_name);
			CAST_AST(params, (yyvsp[(7) - (11)]), AST_formal_parameter_list); 
			CAST_AST(body, (yyvsp[(10) - (11)]), AST_statement_list);
		
			AST_signature* signature = NEW(AST_signature, (AST_method_mod::new_STATIC(), is_ref->value(), name, params));
			fn->signature = signature;
			fn->statements = body;

			context->php_script->get_class_def("%MAIN%")->add_member(fn);	

			(yyval) = NULL;
		;}
    break;

  case 70:
#line 943 "src/generated_src/php_parser.ypp"
    {context->current_class = dynamic_cast<String*>((yyvsp[(2) - (2)]));;}
    break;

  case 71:
#line 944 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(new_class, (yyvsp[(1) - (8)]), AST_class_def);
			CAST_STR(name, (yyvsp[(2) - (8)]), Token_class_name);
			CAST_AST(extends, (yyvsp[(4) - (8)]), Token_class_name);
			CAST_AST(implements, (yyvsp[(5) - (8)]), Token_interface_name_list);
			CAST_AST(members, (yyvsp[(7) - (8)]), AST_member_list);

			new_class->class_name = name;
			new_class->extends = extends;
			new_class->implements = implements;
			new_class->members = members;

			context->php_script->class_defs->push_back(new_class);

			(yyval) = NULL;
		;}
    break;

  case 72:
#line 961 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(idef, (yyvsp[(1) - (6)]), AST_interface_def);
			CAST_STR(name, (yyvsp[(2) - (6)]), Token_interface_name);
			CAST_AST(extends, (yyvsp[(3) - (6)]), Token_interface_name_list);
			CAST_AST(members, (yyvsp[(5) - (6)]), AST_member_list);

			idef->interface_name = name;
			idef->extends = extends;
			idef->members = members;
			
			context->php_script->interface_defs->push_back(idef);

			(yyval) = NULL;
		;}
    break;

  case 73:
#line 991 "src/generated_src/php_parser.ypp"
    { 
			AST_class_mod* mod = NEW(AST_class_mod, (false, false));
			(yyval) = NEW(AST_class_def, (mod));
		;}
    break;

  case 74:
#line 996 "src/generated_src/php_parser.ypp"
    { 
			AST_class_mod* mod = NEW(AST_class_mod, (true, false)); 
			(yyval) = NEW(AST_class_def, (mod));
		;}
    break;

  case 75:
#line 1001 "src/generated_src/php_parser.ypp"
    { 
			AST_class_mod* mod = NEW(AST_class_mod, (false, true)); 
			(yyval) = NEW(AST_class_def, (mod));
		;}
    break;

  case 76:
#line 1012 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 77:
#line 1014 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 78:
#line 1022 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_interface_def, ()); ;}
    break;

  case 79:
#line 1030 "src/generated_src/php_parser.ypp"
    { (yyval) = new Token_interface_name_list; ;}
    break;

  case 80:
#line 1032 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 81:
#line 1042 "src/generated_src/php_parser.ypp"
    { (yyval) = new Token_interface_name_list; ;}
    break;

  case 82:
#line 1044 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 83:
#line 1052 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[(1) - (1)]), Token_class_name);

			Token_interface_name* ifn = NEW(Token_interface_name, (class_name->value));
		
			Token_interface_name_list* names;
			names = new Token_interface_name_list;
			names->push_back(ifn);
			
			(yyval) = names;
		;}
    break;

  case 84:
#line 1064 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(names, (yyvsp[(1) - (3)]), Token_interface_name_list);
			CAST_AST(class_name, (yyvsp[(3) - (3)]), Token_class_name);
			
			Token_interface_name* ifn = NEW(Token_interface_name, (class_name->value));
			names->push_back(ifn);
			
			(yyval) = names;
		;}
    break;

  case 85:
#line 1080 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 86:
#line 1082 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 87:
#line 1090 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[(1) - (1)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (1)]));
			(yyval) = var;
		;}
    break;

  case 88:
#line 1096 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[(2) - (2)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(2) - (2)]));
			var->attrs->set("phc.parser.is_ref", new Boolean(true));
			(yyval) = var; 
		;}
    break;

  case 89:
#line 1109 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 90:
#line 1111 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (4)]); ;}
    break;

  case 91:
#line 1119 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 92:
#line 1121 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (4)]); ;}
    break;

  case 93:
#line 1129 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 94:
#line 1131 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (4)]); ;}
    break;

  case 95:
#line 1139 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (3)]), Token_directive_name);
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);

			AST_directive_list* dirs = new AST_directive_list;
			AST_directive* dir = NEW(AST_directive, (name, value));
			
			dirs->push_back(dir);
			(yyval) = dirs;
		;}
    break;

  case 96:
#line 1150 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(dirs, (yyvsp[(1) - (5)]), AST_directive_list);
			CAST_STR(name, (yyvsp[(3) - (5)]), Token_directive_name);	
			CAST_AST(value, (yyvsp[(5) - (5)]), AST_expr);
			
			AST_directive* dir = NEW(AST_directive, (name, value));
			dirs->push_back(dir);
			(yyval) = dirs;
		;}
    break;

  case 97:
#line 1166 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 98:
#line 1168 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(3) - (4)]); ;}
    break;

  case 99:
#line 1170 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (4)]); ;}
    break;

  case 100:
#line 1172 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(3) - (5)]); ;}
    break;

  case 101:
#line 1180 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_switch_case_list; ;}
    break;

  case 102:
#line 1181 "src/generated_src/php_parser.ypp"
    {(yyvsp[(2) - (4)]) = NEW(AST_switch_case, ());;}
    break;

  case 103:
#line 1182 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(switch_case, (yyvsp[(2) - (6)]), AST_switch_case);	
			CAST_AST(cases, (yyvsp[(1) - (6)]), AST_switch_case_list);
			CAST_AST(expr, (yyvsp[(3) - (6)]), AST_expr);
			CAST_AST(body, (yyvsp[(6) - (6)]), AST_statement_list);
			
			switch_case->statements = body;
			switch_case->expr = expr;
			
			cases->push_back(switch_case);
			
			(yyval) = cases;
		;}
    break;

  case 104:
#line 1195 "src/generated_src/php_parser.ypp"
    {(yyvsp[(2) - (3)]) = NEW(AST_switch_case, ());;}
    break;

  case 105:
#line 1196 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(switch_case, (yyvsp[(2) - (5)]), AST_switch_case);
			CAST_AST(cases, (yyvsp[(1) - (5)]), AST_switch_case_list);
			CAST_AST(body, (yyvsp[(5) - (5)]), AST_statement_list);

			switch_case->statements = body;
			switch_case->expr = NULL;
			
			cases->push_back(switch_case);
			
			(yyval) = cases;
		;}
    break;

  case 106:
#line 1215 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 107:
#line 1217 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 108:
#line 1225 "src/generated_src/php_parser.ypp"
    {
			CAST_STATEMENT_VECTOR(body, (yyvsp[(1) - (1)]));
			
			(yyval) = body;
		;}
    break;

  case 109:
#line 1231 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (4)]); ;}
    break;

  case 110:
#line 1239 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 111:
#line 1240 "src/generated_src/php_parser.ypp"
    {(yyvsp[(2) - (2)]) = NEW(AST_if, ());;}
    break;

  case 112:
#line 1241 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(elseif, (yyvsp[(1) - (7)]), AST_if);
			CAST_AST(nested_if, (yyvsp[(2) - (7)]), AST_if);
			CAST_AST(expr, (yyvsp[(5) - (7)]), AST_expr);
			CAST_STATEMENT_VECTOR(stat, (yyvsp[(7) - (7)]));
			
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
#line 1284 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 114:
#line 1285 "src/generated_src/php_parser.ypp"
    {(yyvsp[(2) - (2)]) = NEW(AST_if, ());;}
    break;

  case 115:
#line 1286 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(elseif, (yyvsp[(1) - (8)]), AST_if);
			CAST_AST(nested_if, (yyvsp[(2) - (8)]), AST_if);
			CAST_AST(expr, (yyvsp[(5) - (8)]), AST_expr);
			CAST_STATEMENT_VECTOR(stat, (yyvsp[(8) - (8)]));
			
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
#line 1323 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 117:
#line 1325 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 118:
#line 1335 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 119:
#line 1337 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 120:
#line 1345 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 121:
#line 1347 "src/generated_src/php_parser.ypp"
    { 
			AST_formal_parameter_list* params = new AST_formal_parameter_list;
			(yyval) = params;
		;}
    break;

  case 122:
#line 1360 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[(1) - (2)]), AST_type);
			CAST_STR(name, (yyvsp[(2) - (2)]), Token_variable_name);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, name)));
			
			(yyval) = params; 
		;}
    break;

  case 123:
#line 1372 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[(1) - (3)]), AST_type);
			CAST_STR(name, (yyvsp[(3) - (3)]), Token_variable_name);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name)));
			
			(yyval) = params; 
		;}
    break;

  case 124:
#line 1384 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[(1) - (5)]), AST_type);
			CAST_STR(name, (yyvsp[(3) - (5)]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[(5) - (5)]), AST_expr);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 125:
#line 1397 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_type, (yyvsp[(1) - (4)]), AST_type);
			CAST_STR(name, (yyvsp[(2) - (4)]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[(4) - (4)]), AST_expr);
			
			AST_formal_parameter_list* params;
			
			params = new AST_formal_parameter_list;
			params->push_back(NEW(AST_formal_parameter, (class_type, false, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 126:
#line 1410 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[(1) - (4)]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[(3) - (4)]), AST_type);
			CAST_STR(name, (yyvsp[(4) - (4)]), Token_variable_name);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, name)));
			
			(yyval) = params; 
		;}
    break;

  case 127:
#line 1420 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[(1) - (5)]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[(3) - (5)]), AST_type);
			CAST_STR(name, (yyvsp[(5) - (5)]), Token_variable_name);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name)));
			
			(yyval) = params; 
		;}
    break;

  case 128:
#line 1430 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[(1) - (7)]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[(3) - (7)]), AST_type);
			CAST_STR(name, (yyvsp[(5) - (7)]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[(7) - (7)]), AST_expr);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, true, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 129:
#line 1441 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(params, (yyvsp[(1) - (6)]), AST_formal_parameter_list);
			CAST_AST(class_type, (yyvsp[(3) - (6)]), AST_type);
			CAST_STR(name, (yyvsp[(4) - (6)]), Token_variable_name);
			CAST_AST(default_val, (yyvsp[(6) - (6)]), AST_expr);
			
			params->push_back(NEW(AST_formal_parameter, (class_type, false, name, default_val)));
			
			(yyval) = params; 
		;}
    break;

  case 130:
#line 1458 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_type, (false, NULL)); ;}
    break;

  case 131:
#line 1460 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(class_name, (yyvsp[(1) - (1)]), Token_class_name);
			(yyval) = NEW(AST_type, (false, class_name)); 
		;}
    break;

  case 132:
#line 1465 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(AST_type, (true, NULL));
		;}
    break;

  case 133:
#line 1475 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 134:
#line 1477 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_actual_parameter_list; ;}
    break;

  case 135:
#line 1485 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(arg, (yyvsp[(1) - (1)]), AST_expr);
			
			AST_actual_parameter_list* list = new AST_actual_parameter_list;
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 136:
#line 1493 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(arg, (yyvsp[(1) - (1)]), AST_expr);
			
			AST_actual_parameter_list* list = new AST_actual_parameter_list;
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 137:
#line 1501 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			
			AST_actual_parameter_list* list = new AST_actual_parameter_list;
			list->push_back(NEW(AST_actual_parameter, (true, expr)));
			(yyval) = list; 
		;}
    break;

  case 138:
#line 1509 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (3)]), AST_actual_parameter_list);
			CAST_AST(arg, (yyvsp[(3) - (3)]), AST_expr);
			
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 139:
#line 1517 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (3)]), AST_actual_parameter_list);
			CAST_AST(arg, (yyvsp[(3) - (3)]), AST_expr);
			
			list->push_back(NEW(AST_actual_parameter, (false, arg)));
			(yyval) = list;
		;}
    break;

  case 140:
#line 1525 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(list, (yyvsp[(1) - (4)]), AST_actual_parameter_list);
			CAST_AST(arg, (yyvsp[(4) - (4)]), AST_expr);
			
			list->push_back(NEW(AST_actual_parameter, (true, arg)));
			(yyval) = list; 
		;}
    break;

  case 141:
#line 1539 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (3)]), List<AST_variable_name*>);
			CAST_AST(var_name, (yyvsp[(3) - (3)]), AST_variable_name);

			list->push_back(var_name);
			(yyval) = list;
		;}
    break;

  case 142:
#line 1547 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var_name, (yyvsp[(1) - (1)]), AST_variable_name);
			
			List<AST_variable_name*>* list = new List<AST_variable_name*>;
			list->push_back(var_name);
			
			(yyval) = list;
		;}
    break;

  case 143:
#line 1562 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(var, (yyvsp[(1) - (1)]), Token_variable_name);
			(yyval) = var; 
		;}
    break;

  case 144:
#line 1567 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_reflection, (expr));
		;}
    break;

  case 145:
#line 1572 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(3) - (4)]), AST_expr);
			(yyval) = NEW(AST_reflection, (expr));
		;}
    break;

  case 146:
#line 1583 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (3)]), AST_statement_list);
			CAST_STR(name, (yyvsp[(3) - (3)]), Token_variable_name);
			
			AST_static_declaration* v = NEW(AST_static_declaration, (name, NULL));
			list->push_back(v);
			
			(yyval) = list;
		;}
    break;

  case 147:
#line 1593 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (5)]), AST_statement_list);
			CAST_STR(name, (yyvsp[(3) - (5)]), Token_variable_name);
			CAST_AST(value, (yyvsp[(5) - (5)]), AST_expr);

			AST_static_declaration* v = NEW(AST_static_declaration, (name, value));
			list->push_back(v);
			
			(yyval) = list;
		;}
    break;

  case 148:
#line 1604 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (1)]), Token_variable_name);
			
			AST_statement_list* list = new AST_statement_list;
			AST_static_declaration* v = NEW(AST_static_declaration, (name, NULL));
			list->push_back(v);
			
			(yyval) = list;
		;}
    break;

  case 149:
#line 1614 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (3)]), Token_variable_name);
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_statement_list* list = new AST_statement_list;
			AST_static_declaration* v = NEW(AST_static_declaration, (name, value));
			list->push_back(v);

			(yyval) = list;
		;}
    break;

  case 150:
#line 1631 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(member_list, (yyvsp[(1) - (2)]), AST_member_list);		
			CAST_AST(members, (yyvsp[(2) - (2)]), AST_member_list);
			
			member_list->push_back_all(members);
			
			(yyval) = member_list;			
		;}
    break;

  case 151:
#line 1640 "src/generated_src/php_parser.ypp"
    {
			(yyval) = new AST_member_list;
		;}
    break;

  case 152:
#line 1650 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(modifiers, (yyvsp[(1) - (3)]), AST_attr_mod);
			CAST_AST(members, (yyvsp[(2) - (3)]), AST_member_list);	

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
#line 1664 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 154:
#line 1665 "src/generated_src/php_parser.ypp"
    {(yyvsp[(2) - (2)]) = NEW(AST_method, ());;}
    break;

  case 155:
#line 1665 "src/generated_src/php_parser.ypp"
    {context->current_method = dynamic_cast<String*>((yyvsp[(5) - (5)]));;}
    break;

  case 156:
#line 1666 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(mod, (yyvsp[(1) - (10)]), AST_method_mod);
			CAST_AST(fn, (yyvsp[(2) - (10)]), AST_method);
			CAST_AST(is_ref, (yyvsp[(4) - (10)]), Integer);
			CAST_STR(name, (yyvsp[(5) - (10)]), Token_method_name);
			CAST_AST(params, (yyvsp[(8) - (10)]), AST_formal_parameter_list);
			CAST_AST(body, (yyvsp[(10) - (10)]), AST_statement_list);
		
			AST_signature* signature = NEW(AST_signature, (mod, is_ref->value(), name, params));
			
			AST_member_list* members = new AST_member_list;
			fn->signature = signature;
			fn->statements = body;
			members->push_back(fn);
			
			(yyval) = members;
		;}
    break;

  case 157:
#line 1690 "src/generated_src/php_parser.ypp"
    {
			// Abstract method
			(yyval) = NULL; 
		;}
    break;

  case 158:
#line 1695 "src/generated_src/php_parser.ypp"
    {
			(yyval) = (yyvsp[(2) - (3)]);
		;}
    break;

  case 159:
#line 1705 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(method_mod, (yyvsp[(1) - (1)]), AST_method_mod);
			
			if(method_mod->is_abstract)
			{
				phc_error(ERR_ABSTRACT_VARS, method_mod->get_filename(), method_mod->get_line_number());
			}

			(yyval) = NEW(AST_attr_mod, (method_mod)); 
		;}
    break;

  case 160:
#line 1716 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(AST_attr_mod, (true, false, false, false, false)); ;}
    break;

  case 161:
#line 1724 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PUBLIC(); ;}
    break;

  case 162:
#line 1726 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 163:
#line 1734 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 164:
#line 1736 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(i, (yyvsp[(1) - (2)]), AST_method_mod);
			CAST_AST(j, (yyvsp[(2) - (2)]), AST_method_mod);
		
			(yyval) = NEW(AST_method_mod, (i, j)); 
		;}
    break;

  case 165:
#line 1749 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PUBLIC(); ;}
    break;

  case 166:
#line 1751 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PROTECTED(); ;}
    break;

  case 167:
#line 1753 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_PRIVATE(); ;}
    break;

  case 168:
#line 1755 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_STATIC(); ;}
    break;

  case 169:
#line 1757 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_ABSTRACT(); ;}
    break;

  case 170:
#line 1759 "src/generated_src/php_parser.ypp"
    { (yyval) = AST_method_mod::new_FINAL(); ;}
    break;

  case 171:
#line 1767 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(members, (yyvsp[(1) - (3)]), AST_member_list);
			CAST_STR(name, (yyvsp[(3) - (3)]), Token_variable_name);
			
			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, NULL));
			members->push_back(attr);
			
			(yyval) = members;
		;}
    break;

  case 172:
#line 1777 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(members, (yyvsp[(1) - (5)]), AST_member_list);
			CAST_STR(name, (yyvsp[(3) - (5)]), Token_variable_name);
			CAST_AST(value, (yyvsp[(5) - (5)]), AST_expr);
			
			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, value));
			members->push_back(attr);

			(yyval) = members;			
		;}
    break;

  case 173:
#line 1788 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (1)]), Token_variable_name);
			AST_member_list* members = new AST_member_list;

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, NULL));	
			members->push_back(attr);

			(yyval) = members;
		;}
    break;

  case 174:
#line 1798 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(name, (yyvsp[(1) - (3)]), Token_variable_name);
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);
			AST_member_list* members = new AST_member_list;

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_PUBLIC(), name, value));
			members->push_back(attr);

			(yyval) = members;
		;}
    break;

  case 175:
#line 1815 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(members, (yyvsp[(1) - (5)]), AST_member_list);
			CAST_STR(name, (yyvsp[(3) - (5)]), Token_variable_name);
			CAST_AST(value, (yyvsp[(5) - (5)]), AST_expr);

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_CONST(), name, value));
			members->push_back(attr);
			
			(yyval) = members;
		;}
    break;

  case 176:
#line 1826 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(2) - (4)]), Token_variable_name);
			CAST_AST(value, (yyvsp[(4) - (4)]), AST_expr);
			AST_member_list* members = new AST_member_list;

			AST_attribute* attr = NEW(AST_attribute, (AST_attr_mod::new_CONST(), name, value));
			members->push_back(attr);

			(yyval) = members;
		;}
    break;

  case 177:
#line 1845 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(echo_list, (yyvsp[(1) - (3)]), AST_statement_list);
			CAST_AST(param, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_method_invocation* fn = NEW(AST_method_invocation, ("echo", param));
			echo_list->push_back(NEW(AST_eval_expr, (fn)));
			
			(yyval) = echo_list;
		;}
    break;

  case 178:
#line 1855 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(param, (yyvsp[(1) - (1)]), AST_expr);
			AST_statement_list* echo_list = new AST_statement_list;
			
			AST_method_invocation* fn = NEW(AST_method_invocation, ("echo", param));
			echo_list->push_back(NEW(AST_eval_expr, (fn)));
			
			(yyval) = echo_list;
		;}
    break;

  case 179:
#line 1871 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 180:
#line 1873 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 181:
#line 1882 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(a, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(b, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = new AST_bin_op(a, b, ",");
		;}
    break;

  case 182:
#line 1889 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 183:
#line 1897 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(elements, (yyvsp[(3) - (6)]), AST_list_elements);
			CAST_AST(expr, (yyvsp[(6) - (6)]), AST_expr);
			
			(yyval) = NEW(AST_list_assignment, (elements, expr));
		;}
    break;

  case 184:
#line 1904 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);
			
			(yyval) = NEW(AST_assignment, (var, false, value));
		;}
    break;

  case 185:
#line 1912 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (4)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (4)]));
			CAST_AST(value, (yyvsp[(4) - (4)]), AST_expr);
			
			(yyval) = NEW(AST_assignment, (var, true, value)); 
		;}
    break;

  case 186:
#line 1920 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (6)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (6)]));
			CAST_AST(name, (yyvsp[(5) - (6)]), AST_class_name);
			CAST_AST(args, (yyvsp[(6) - (6)]), AST_actual_parameter_list);

			(yyval) = NEW(AST_assignment, (var, true, NEW(AST_new, (name, args))));
		;}
    break;

  case 187:
#line 1929 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(name, (yyvsp[(2) - (3)]), AST_class_name);	
			CAST_AST(args, (yyvsp[(3) - (3)]), AST_actual_parameter_list);

			(yyval) = NEW(AST_new, (name, args));
		;}
    break;

  case 188:
#line 1936 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			
			(yyval) = NEW(AST_clone, (expr)); 
		;}
    break;

  case 189:
#line 1942 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "+")))); 
		;}
    break;

  case 190:
#line 1954 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "-")))); 
		;}
    break;

  case 191:
#line 1966 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "*")))); 
		;}
    break;

  case 192:
#line 1978 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "/")))); 
		;}
    break;

  case 193:
#line 1990 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
	
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, ".")))); 
		;}
    break;

  case 194:
#line 2002 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "%")))); 
		;}
    break;

  case 195:
#line 2014 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "&")))); 
		;}
    break;

  case 196:
#line 2026 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "|")))); 
		;}
    break;

  case 197:
#line 2038 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "^")))); 
		;}
    break;

  case 198:
#line 2050 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, "<<")))); 
		;}
    break;

  case 199:
#line 2062 "src/generated_src/php_parser.ypp"
    {
			CAST_UNSAFE(var, (yyvsp[(1) - (3)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (3)]));
			CAST_AST(expr, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_expr* var_c;
			var_c = var->deep_clone();
			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
		
			(yyval) = NEW(AST_assignment, (var, false, NEW(AST_bin_op, (var_c, expr, ">>")))); 
		;}
    break;

  case 200:
#line 2074 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[(1) - (2)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (2)]));
			(yyval) = NEW(AST_post_op, (var, "++"));
		;}
    break;

  case 201:
#line 2080 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[(2) - (2)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(2) - (2)]));
			(yyval) = NEW(AST_pre_op, (var, "++"));
		;}
    break;

  case 202:
#line 2086 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[(1) - (2)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(1) - (2)]));
			(yyval) = NEW(AST_post_op, (var, "--"));
		;}
    break;

  case 203:
#line 2092 "src/generated_src/php_parser.ypp"
    { 
			CAST_UNSAFE(var, (yyvsp[(2) - (2)]), AST_variable);
			EXPECT_VARIABLE((yyvsp[(2) - (2)]));
			(yyval) = NEW(AST_pre_op, (var, "--"));
		;}
    break;

  case 204:
#line 2098 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "||"));
		;}
    break;

  case 205:
#line 2105 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "&&"));
		;}
    break;

  case 206:
#line 2112 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "or"));
		;}
    break;

  case 207:
#line 2119 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "and"));
		;}
    break;

  case 208:
#line 2126 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "xor"));
		;}
    break;

  case 209:
#line 2133 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "|"));
		;}
    break;

  case 210:
#line 2140 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "&"));
		;}
    break;

  case 211:
#line 2147 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "^"));
		;}
    break;

  case 212:
#line 2154 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "."));
		;}
    break;

  case 213:
#line 2161 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (4)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (4)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "."));

			/*
			 * Interface with the lexer: return to in-string state 
			 */
			 
			context->return_to_complex_syntax();
		;}
    break;

  case 214:
#line 2174 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "+"));
		;}
    break;

  case 215:
#line 2181 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "-"));
		;}
    break;

  case 216:
#line 2188 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "*"));
		;}
    break;

  case 217:
#line 2195 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "/"));
		;}
    break;

  case 218:
#line 2202 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "%"));
		;}
    break;

  case 219:
#line 2209 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "<<"));
		;}
    break;

  case 220:
#line 2216 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, ">>"));
		;}
    break;

  case 221:
#line 2223 "src/generated_src/php_parser.ypp"
    {
			// We ignore unary plus
			(yyval) = (yyvsp[(2) - (2)]); 
		;}
    break;

  case 222:
#line 2228 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			
			(yyval) = NEW(AST_unary_op, (expr, "-")); 
		;}
    break;

  case 223:
#line 2234 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			
			(yyval) = NEW(AST_unary_op, (expr, "!")); 
		;}
    break;

  case 224:
#line 2240 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			
			(yyval) = NEW(AST_unary_op, (expr, "~")); 
		;}
    break;

  case 225:
#line 2246 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "==="));
		;}
    break;

  case 226:
#line 2253 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "!=="));
		;}
    break;

  case 227:
#line 2260 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "=="));
		;}
    break;

  case 228:
#line 2267 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "!="));
		;}
    break;

  case 229:
#line 2274 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "<"));
		;}
    break;

  case 230:
#line 2281 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, "<="));
		;}
    break;

  case 231:
#line 2288 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, ">"));
		;}
    break;

  case 232:
#line 2295 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(left, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(right, (yyvsp[(3) - (3)]), AST_expr);

			(yyval) = NEW(AST_bin_op, (left, right, ">="));
		;}
    break;

  case 233:
#line 2302 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(class_name, (yyvsp[(3) - (3)]), AST_class_name);
			
			(yyval) = NEW(AST_instanceof, (expr, class_name));
		;}
    break;

  case 234:
#line 2309 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (3)]), AST_expr);

			expr->attrs->set("phc.unparser.needs_brackets", new Boolean(true));
			
			(yyval) = expr;
		;}
    break;

  case 235:
#line 2317 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(cond, (yyvsp[(1) - (5)]), AST_expr);
			CAST_AST(iftrue, (yyvsp[(3) - (5)]), AST_expr);
			CAST_AST(iffalse, (yyvsp[(5) - (5)]), AST_expr);
			
			(yyval) = NEW(AST_conditional_expr, (cond, iftrue, iffalse)); 
		;}
    break;

  case 236:
#line 2325 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 237:
#line 2327 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_cast, ("int", expr));
		;}
    break;

  case 238:
#line 2332 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_cast, ("real", expr));
		;}
    break;

  case 239:
#line 2337 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_cast, ("string", expr));
		;}
    break;

  case 240:
#line 2342 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_cast, ("array", expr));
		;}
    break;

  case 241:
#line 2347 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_cast, ("object", expr));
		;}
    break;

  case 242:
#line 2352 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_cast, ("bool", expr));
		;}
    break;

  case 243:
#line 2357 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_cast, ("unset", expr));
		;}
    break;

  case 244:
#line 2362 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(param, (yyvsp[(2) - (2)]), AST_expr);
			
			(yyval) = NEW(AST_method_invocation, ("exit", param));
		;}
    break;

  case 245:
#line 2368 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
 
			(yyval) = NEW(AST_ignore_errors, (expr)); 
		;}
    break;

  case 246:
#line 2374 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 247:
#line 2376 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(list, (yyvsp[(3) - (4)]), AST_array_elem_list);
			
			(yyval) = NEW(AST_array, (list)); 
		;}
    break;

  case 248:
#line 2382 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(param, (yyvsp[(2) - (2)]), AST_expr);

			(yyval) = NEW(AST_method_invocation, ("print", param));	
		;}
    break;

  case 249:
#line 2394 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(params, (yyvsp[(3) - (4)]), AST_actual_parameter_list);
			CAST_STR(fn, (yyvsp[(1) - (4)]), Token_method_name);
		
			(yyval) = NEW(AST_method_invocation, (NULL, fn, params));
		;}
    break;

  case 250:
#line 2401 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[(1) - (6)]), Token_class_name);
			CAST_STR(fn, (yyvsp[(3) - (6)]), Token_method_name);
			CAST_AST(params, (yyvsp[(5) - (6)]), AST_actual_parameter_list);

			(yyval) = NEW(AST_method_invocation, (class_name, fn, params));
		;}
    break;

  case 251:
#line 2409 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[(1) - (6)]), Token_class_name);
			CAST_AST(expr, (yyvsp[(3) - (6)]), AST_expr);
			CAST_AST(params, (yyvsp[(5) - (6)]), AST_actual_parameter_list);
			
			(yyval) = NEW(AST_method_invocation, (class_name, NEW(AST_reflection, (expr)), params));
		;}
    break;

  case 252:
#line 2417 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(1) - (4)]), AST_expr);
			CAST_AST(params, (yyvsp[(3) - (4)]), AST_actual_parameter_list);			
			
			(yyval) = NEW(AST_method_invocation, (NULL, NEW(AST_reflection, (expr)), params));
		;}
    break;

  case 253:
#line 2430 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (1)]), Token_class_name);
			(yyval) = name; 
		;}
    break;

  case 254:
#line 2441 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (1)]), Token_class_name);

			(yyval) = name; 
		;}
    break;

  case 255:
#line 2447 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(1) - (1)]), AST_expr);
			(yyval) = NEW(AST_reflection, (expr)); 
		;}
    break;

  case 256:
#line 2461 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(object, (yyvsp[(1) - (4)]), AST_expr);
			CAST_AST(result, (yyvsp[(3) - (4)]), AST_variable);
			CAST_AST(vars, (yyvsp[(4) - (4)]), List<AST_variable*>);
			
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
#line 2478 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 258:
#line 2486 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(vars, (yyvsp[(1) - (2)]), List<AST_variable*>);
			CAST_AST(var, (yyvsp[(2) - (2)]), AST_variable);

			vars->push_back(var);
			(yyval) = vars;
		;}
    break;

  case 259:
#line 2494 "src/generated_src/php_parser.ypp"
    { 
			List<AST_variable*>* vars = new List<AST_variable*>;
			(yyval) = vars;
		;}
    break;

  case 260:
#line 2505 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 261:
#line 2515 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(Token_int, (0L, new String("0"))); ;}
    break;

  case 262:
#line 2517 "src/generated_src/php_parser.ypp"
    { (yyval) = NEW(Token_int, (0L, new String("0"))); ;}
    break;

  case 263:
#line 2519 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 264:
#line 2527 "src/generated_src/php_parser.ypp"
    { 
			AST_actual_parameter_list* args = new AST_actual_parameter_list;
			
			(yyval) = args; 
		;}
    break;

  case 265:
#line 2533 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 266:
#line 2541 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			(yyval) = NEW(Token_int, (strtol(str->c_str(), 0, 0), str));
		;}
    break;

  case 267:
#line 2546 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			(yyval) = NEW(Token_real, (atof(str->c_str()), str));
		;}
    break;

  case 268:
#line 2551 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			(yyval) = NEW(Token_string, (str, str));
		;}
    break;

  case 269:
#line 2556 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			(yyval) = NEW(Token_bool, (false, str));
		;}
    break;

  case 270:
#line 2561 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			(yyval) = NEW(Token_bool, (true, str));
		;}
    break;

  case 271:
#line 2566 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(str, (yyvsp[(1) - (1)]), String);
			(yyval) = NEW(Token_null, (str));
		;}
    break;

  case 272:
#line 2571 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_int, (context->source_line, new String("__LINE__")));
		;}
    break;

  case 273:
#line 2575 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->filename, new String("__FILE__")));
		;}
    break;

  case 274:
#line 2579 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->current_class, new String("__CLASS__")));
		;}
    break;

  case 275:
#line 2583 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->current_method, new String("__METHOD__")));
		;}
    break;

  case 276:
#line 2587 "src/generated_src/php_parser.ypp"
    {
			(yyval) = NEW(Token_string, (context->current_method, new String("__FUNCTION__")));
		;}
    break;

  case 277:
#line 2597 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 278:
#line 2599 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (1)]), Token_constant_name);
			(yyval) = NEW(AST_constant, ("%MAIN%", name)); 
		;}
    break;

  case 279:
#line 2604 "src/generated_src/php_parser.ypp"
    {
			// We simply ignore the +
			(yyval) = (yyvsp[(2) - (2)]);
		;}
    break;

  case 280:
#line 2609 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(val, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_unary_op, (val, "-"));
		;}
    break;

  case 281:
#line 2614 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(3) - (4)]), AST_array_elem_list);
			(yyval) = NEW(AST_array, (list));
		;}
    break;

  case 282:
#line 2619 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 283:
#line 2627 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(class_name, (yyvsp[(1) - (3)]), Token_class_name);
			CAST_STR(constant, (yyvsp[(3) - (3)]), Token_constant_name);
			
			(yyval) = NEW(AST_constant, (class_name, constant));
		;}
    break;

  case 284:
#line 2640 "src/generated_src/php_parser.ypp"
    {
			CAST_STR(name, (yyvsp[(1) - (1)]), Token_constant_name);

			(yyval) = NEW(AST_constant, ("%MAIN%", name));
		;}
    break;

  case 285:
#line 2646 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 286:
#line 2648 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 287:
#line 2656 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_array_elem_list; ;}
    break;

  case 288:
#line 2658 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 289:
#line 2666 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 290:
#line 2668 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 291:
#line 2676 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (5)]), AST_array_elem_list);
			CAST_AST(key, (yyvsp[(3) - (5)]), AST_expr);
			CAST_AST(value, (yyvsp[(5) - (5)]), AST_expr);

			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 292:
#line 2687 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (3)]), AST_array_elem_list);
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);
			
			(yyval) = list;
		;}
    break;

  case 293:
#line 2697 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(key, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 294:
#line 2708 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(value, (yyvsp[(1) - (1)]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 295:
#line 2724 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 296:
#line 2726 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 297:
#line 2734 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 298:
#line 2742 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 299:
#line 2750 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 300:
#line 2774 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(object, (yyvsp[(1) - (2)]), AST_expr);
			CAST_AST(props, (yyvsp[(2) - (2)]), AST_expr_list);

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
#line 2809 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 302:
#line 2820 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(props, (yyvsp[(1) - (2)]), AST_expr_list);
			CAST_AST(prop, (yyvsp[(2) - (2)]), AST_expr);

			props->push_back(prop);
			
			(yyval) = props;
		;}
    break;

  case 303:
#line 2829 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(prop, (yyvsp[(1) - (1)]), AST_expr);
			
			AST_expr_list* props = new AST_expr_list;
			props->push_back(prop);
			
			(yyval) = props;
		;}
    break;

  case 304:
#line 2862 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var, (yyvsp[(2) - (3)]), AST_variable);
			CAST_AST(params, (yyvsp[(3) - (3)]), AST_actual_parameter_list);
			
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
#line 2906 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 306:
#line 2908 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 307:
#line 2916 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 308:
#line 2918 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(num_indirections, (yyvsp[(1) - (2)]), Integer);
			CAST_AST(var, (yyvsp[(2) - (2)]), AST_variable);
				
			for(long i = 0; i < num_indirections->value(); i++)
			{
				var = NEW(AST_variable, (NEW(AST_reflection, (var))));
			}
			
			(yyval) = var;
		;}
    break;

  case 309:
#line 2936 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(class_name, (yyvsp[(1) - (3)]), Token_class_name);
			CAST_AST(var, (yyvsp[(3) - (3)]), AST_variable);
		
			var->target = class_name;
			(yyval) = var; 
		;}
    break;

  case 310:
#line 2950 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 311:
#line 2952 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 312:
#line 2960 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 313:
#line 2962 "src/generated_src/php_parser.ypp"
    {	
			CAST_AST(num_indirections, (yyvsp[(1) - (2)]), Integer);
			CAST_AST(var, (yyvsp[(2) - (2)]), AST_variable);
				
			for(long i = 0; i < num_indirections->value(); i++)
			{
				var = NEW(AST_variable, (NEW(AST_reflection, (var))));
			}

			(yyval) = var;
		;}
    break;

  case 314:
#line 2974 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 315:
#line 2982 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var, (yyvsp[(1) - (4)]), AST_variable);
			CAST_AST(index, (yyvsp[(3) - (4)]), AST_expr);
		
			// string index is only valid after *all* array indices.
			assert(var->string_index == NULL);
		
			var->array_indices->push_back(index);
			(yyval) = var;
		;}
    break;

  case 316:
#line 2993 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(var, (yyvsp[(1) - (4)]), AST_variable);
			CAST_AST(index, (yyvsp[(3) - (4)]), AST_expr);
			
			// we only accept *one* string index.
			assert(var->string_index == NULL);
			
			var->string_index = index;
			(yyval) = var;
		;}
    break;

  case 317:
#line 3004 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(name, (yyvsp[(1) - (1)]), AST_variable_name);

			(yyval) = NEW(AST_variable, (name));
		;}
    break;

  case 318:
#line 3016 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(var, (yyvsp[(1) - (1)]), Token_variable_name);
			(yyval) = var; 
		;}
    break;

  case 319:
#line 3021 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(3) - (4)]), AST_expr);
			(yyval) = NEW(AST_reflection, (expr)); 
		;}
    break;

  case 320:
#line 3032 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 321:
#line 3034 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 322:
#line 3042 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 323:
#line 3044 "src/generated_src/php_parser.ypp"
    {
			// This is a "normal" variable (which includes a $), i.e. $x->$y
			// So, we need to add a level of indirection
			CAST_AST(var, (yyvsp[(1) - (1)]), AST_variable);
			(yyval) = NEW(AST_variable, (NEW(AST_reflection, (var)))); 
		;}
    break;

  case 324:
#line 3059 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(op, (yyvsp[(1) - (4)]), AST_variable);
			CAST_AST(index, (yyvsp[(3) - (4)]), AST_expr);
		
			// string index is only valid after *all* array indices
			assert(op->string_index == NULL);
			
			op->array_indices->push_back(index);
			(yyval) = op;
		;}
    break;

  case 325:
#line 3070 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(op, (yyvsp[(1) - (4)]), AST_variable);
			CAST_AST(index, (yyvsp[(3) - (4)]), AST_expr);

			// we only accept *one* string index.
			assert(op->string_index == NULL);

			op->string_index = index;
			(yyval) = op;
		;}
    break;

  case 326:
#line 3081 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(name, (yyvsp[(1) - (1)]), AST_variable_name);	

			(yyval) = NEW(AST_variable, (name)); 
		;}
    break;

  case 327:
#line 3095 "src/generated_src/php_parser.ypp"
    { 
			CAST_STR(var, (yyvsp[(1) - (1)]), Token_variable_name);
			(yyval) = var; 
		;}
    break;

  case 328:
#line 3100 "src/generated_src/php_parser.ypp"
    { 
			CAST_AST(expr, (yyvsp[(2) - (3)]), AST_expr);
			(yyval) = NEW(AST_reflection, (expr)); 
		;}
    break;

  case 329:
#line 3113 "src/generated_src/php_parser.ypp"
    { (yyval) = new Integer(1); ;}
    break;

  case 330:
#line 3115 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(i, (yyvsp[(1) - (2)]), Integer);
			
			(*i)++;
			(yyval) = i; 
		;}
    break;

  case 331:
#line 3128 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(elements, (yyvsp[(1) - (3)]), AST_list_elements);
			CAST_AST(element, (yyvsp[(3) - (3)]), AST_list_element);

			elements->list_elements->push_back(element);
			
			(yyval) = elements; 
		;}
    break;

  case 332:
#line 3137 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(element, (yyvsp[(1) - (1)]), AST_list_element);

			AST_list_element_list* elements = new AST_list_element_list;
			elements->push_back(element);
			
			(yyval) = NEW(AST_list_elements, (elements)); 
		;}
    break;

  case 333:
#line 3154 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 334:
#line 3156 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(3) - (4)]); ;}
    break;

  case 335:
#line 3158 "src/generated_src/php_parser.ypp"
    { (yyval) = NULL; ;}
    break;

  case 336:
#line 3166 "src/generated_src/php_parser.ypp"
    { (yyval) = new AST_array_elem_list; ;}
    break;

  case 337:
#line 3168 "src/generated_src/php_parser.ypp"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 338:
#line 3178 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (5)]), AST_array_elem_list);
			CAST_AST(key, (yyvsp[(3) - (5)]), AST_expr);
			CAST_AST(value, (yyvsp[(5) - (5)]), AST_expr);

			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 339:
#line 3189 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (3)]), AST_array_elem_list);
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);
			
			(yyval) = list;
		;}
    break;

  case 340:
#line 3199 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(key, (yyvsp[(1) - (3)]), AST_expr);
			CAST_AST(value, (yyvsp[(3) - (3)]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (key, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 341:
#line 3210 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(value, (yyvsp[(1) - (1)]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = NEW(AST_array_elem, (NULL, false, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 342:
#line 3220 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (6)]), AST_array_elem_list);
			CAST_AST(key, (yyvsp[(3) - (6)]), AST_expr);
			CAST_AST(value, (yyvsp[(6) - (6)]), AST_expr);

			AST_array_elem* elem = 
				NEW(AST_array_elem, (key, true, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 343:
#line 3232 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(list, (yyvsp[(1) - (4)]), AST_array_elem_list);
			CAST_AST(value, (yyvsp[(4) - (4)]), AST_expr);
			
			AST_array_elem* elem = 
				NEW(AST_array_elem, (NULL, true, value));
			list->push_back(elem);
			
			(yyval) = list;
		;}
    break;

  case 344:
#line 3243 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(key, (yyvsp[(1) - (4)]), AST_expr);
			CAST_AST(value, (yyvsp[(4) - (4)]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = 
				NEW(AST_array_elem, (key, true, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 345:
#line 3255 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(value, (yyvsp[(2) - (2)]), AST_expr);
			
			AST_array_elem_list* list = new AST_array_elem_list;
			AST_array_elem* elem = 
				NEW(AST_array_elem, (NULL, true, value));
			list->push_back(elem);

			(yyval) = list;
		;}
    break;

  case 346:
#line 3272 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(params, (yyvsp[(3) - (4)]), AST_actual_parameter_list);
		  
			Token_method_name* fn = NEW(Token_method_name, (new String("isset")));
			(yyval) = NEW(AST_method_invocation, (NULL, fn, params));
		;}
    break;

  case 347:
#line 3279 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(variable, (yyvsp[(3) - (4)]), AST_expr); 
			(yyval) = NEW(AST_method_invocation, ("empty", variable));
		;}
    break;

  case 348:
#line 3284 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("include", expr));
		;}
    break;

  case 349:
#line 3289 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("include_once", expr));
		;}
    break;

  case 350:
#line 3294 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(3) - (4)]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("eval", expr));
		;}
    break;

  case 351:
#line 3299 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("require", expr));
		;}
    break;

  case 352:
#line 3304 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(expr, (yyvsp[(2) - (2)]), AST_expr);
			(yyval) = NEW(AST_method_invocation, ("require_once", expr));
		;}
    break;

  case 353:
#line 3315 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(variable, (yyvsp[(1) - (1)]), AST_expr);
			AST_actual_parameter_list* params = new AST_actual_parameter_list;
			
			params->push_back(NEW(AST_actual_parameter, (false, variable)));
			(yyval) = params;
		;}
    break;

  case 354:
#line 3323 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(params, (yyvsp[(1) - (3)]), AST_actual_parameter_list);
			CAST_AST(variable, (yyvsp[(3) - (3)]), AST_expr);
			
			params->push_back(NEW(AST_actual_parameter, (false, variable)));
			(yyval) = params;
		;}
    break;

  case 355:
#line 3337 "src/generated_src/php_parser.ypp"
    {
			CAST_AST(class_name, (yyvsp[(1) - (3)]), Token_class_name);
			CAST_STR(constant, (yyvsp[(3) - (3)]), Token_constant_name);

			(yyval) = NEW(AST_constant, (class_name, constant));
		;}
    break;


/* Line 1267 of yacc.c.  */
#line 6932 "src/generated/php_parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (context, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (context, yymsg);
	  }
	else
	  {
	    yyerror (context, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, context);
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
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, context);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
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
		 yytoken, &yylval, context);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, context);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



