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
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     ARRAY = 259,
     OF = 260,
     AP = 261,
     SOP = 262,
     SCP = 263,
     OP = 264,
     CP = 265,
     MINUS = 266,
     NOT = 267,
     BIN_EQUALS = 268,
     BIN_GREATER = 269,
     BIN_LESS = 270,
     BIN_MOD = 271,
     BIN_DIV = 272,
     BIN_MUL = 273,
     BIN_PLUS = 274,
     BIN_OR = 275,
     BIN_AND = 276,
     TRUE = 277,
     FALSE = 278,
     STR = 279,
     CHAR = 280,
     HEX = 281,
     BIN = 282,
     DEC = 283,
     METHOD = 284,
     WHILE = 285,
     REPEAT = 286,
     DO = 287,
     BREAK = 288,
     UNTIL = 289,
     IF = 290,
     THEN = 291,
     ELSE = 292,
     COLON = 293,
     SEMICOLON = 294,
     COMMA = 295,
     VAR = 296,
     BEGINING = 297,
     END = 298,
     TYPE = 299
   };
#endif
/* Tokens.  */
#define IDENT 258
#define ARRAY 259
#define OF 260
#define AP 261
#define SOP 262
#define SCP 263
#define OP 264
#define CP 265
#define MINUS 266
#define NOT 267
#define BIN_EQUALS 268
#define BIN_GREATER 269
#define BIN_LESS 270
#define BIN_MOD 271
#define BIN_DIV 272
#define BIN_MUL 273
#define BIN_PLUS 274
#define BIN_OR 275
#define BIN_AND 276
#define TRUE 277
#define FALSE 278
#define STR 279
#define CHAR 280
#define HEX 281
#define BIN 282
#define DEC 283
#define METHOD 284
#define WHILE 285
#define REPEAT 286
#define DO 287
#define BREAK 288
#define UNTIL 289
#define IF 290
#define THEN 291
#define ELSE 292
#define COLON 293
#define SEMICOLON 294
#define COMMA 295
#define VAR 296
#define BEGINING 297
#define END 298
#define TYPE 299




/* Copy the first part of user declarations.  */
#line 1 "grammer.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <getopt.h>
  #include "ast.h"
  #include "error.h"

  struct ast_node *root;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
typedef union YYSTYPE
#line 14 "grammer.y"
{
  struct ast_node* node;
}
/* Line 193 of yacc.c.  */
#line 199 "grammer.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 212 "grammer.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    17,    20,    24,
      25,    28,    31,    36,    40,    42,    47,    54,    58,    60,
      62,    66,    68,    70,    72,    74,    76,    81,    83,    85,
      87,    89,    91,    93,    98,   105,   109,   114,   115,   118,
     123,   129,   135,   138,   141,   143,   145,   147,   149,   151,
     153,   155,   158,   161,   166,   170,   174,   178,   182,   186,
     191,   196,   200,   204,   208,   212,   216,   221,   222,   224,
     228,   230,   235,   237,   239,   241,   243,   245,   247,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    -1,    46,    47,    -1,    29,    52,    48,
      -1,    29,    52,    39,    -1,    61,    -1,    41,    61,    -1,
      41,    49,    61,    -1,    -1,    49,    50,    -1,    51,    39,
      -1,    51,    38,    55,    39,    -1,     3,    40,    51,    -1,
       3,    -1,     3,     9,    53,    10,    -1,     3,     9,    53,
      10,    38,    55,    -1,    54,    40,    53,    -1,    54,    -1,
       3,    -1,     3,    38,    55,    -1,    56,    -1,    57,    -1,
      58,    -1,    44,    -1,     3,    -1,     4,     6,     5,    55,
      -1,    60,    -1,    61,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    35,    67,    36,    59,    -1,    35,    67,
      36,    59,    37,    59,    -1,    42,    43,    39,    -1,    42,
      62,    43,    39,    -1,    -1,    62,    59,    -1,    30,    67,
      32,    59,    -1,    31,    59,    30,    67,    39,    -1,    31,
      59,    34,    67,    39,    -1,    33,    39,    -1,    67,    39,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,    74,
      -1,    75,    -1,    76,    -1,    11,    67,    -1,    12,    67,
      -1,    67,    38,    13,    67,    -1,    67,    19,    67,    -1,
      67,    11,    67,    -1,    67,    18,    67,    -1,    67,    17,
      67,    -1,    67,    16,    67,    -1,    67,    13,    13,    67,
      -1,    67,    12,    13,    67,    -1,    67,    15,    67,    -1,
      67,    14,    67,    -1,    67,    21,    67,    -1,    67,    20,
      67,    -1,     9,    67,    10,    -1,     3,     9,    72,    10,
      -1,    -1,    73,    -1,    67,    40,    73,    -1,    67,    -1,
      67,     7,    73,     8,    -1,     3,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    74,    75,    78,    79,    80,    83,
      84,    87,    88,    91,    92,    95,    96,    99,   100,   103,
     104,   107,   108,   109,   113,   117,   121,   124,   125,   126,
     127,   128,   129,   132,   133,   136,   137,   140,   141,   145,
     148,   149,   152,   155,   158,   159,   160,   161,   162,   163,
     164,   167,   168,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   185,   188,   191,   192,   195,
     196,   199,   202,   205,   206,   207,   208,   209,   210,   211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "ARRAY", "OF", "AP", "SOP",
  "SCP", "OP", "CP", "MINUS", "NOT", "BIN_EQUALS", "BIN_GREATER",
  "BIN_LESS", "BIN_MOD", "BIN_DIV", "BIN_MUL", "BIN_PLUS", "BIN_OR",
  "BIN_AND", "TRUE", "FALSE", "STR", "CHAR", "HEX", "BIN", "DEC", "METHOD",
  "WHILE", "REPEAT", "DO", "BREAK", "UNTIL", "IF", "THEN", "ELSE", "COLON",
  "SEMICOLON", "COMMA", "VAR", "BEGINING", "END", "TYPE", "$accept",
  "source", "source_item", "body", "body_var", "body_item", "list_var",
  "function_signature", "list_arg", "list_arg_item", "type_ref", "builtin",
  "custom", "array", "statement", "if", "block", "block_item", "while",
  "do", "break", "expression", "expr", "unary", "binary", "braces", "call",
  "call_list", "list_expr", "indexer", "place", "literal", 0
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    55,    56,    57,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      64,    64,    65,    66,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    71,    72,    72,    73,
      73,    74,    75,    76,    76,    76,    76,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     1,     2,     3,     0,
       2,     2,     4,     3,     1,     4,     6,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     4,     6,     3,     4,     0,     2,     4,
       5,     5,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     4,     3,     3,     3,     3,     3,     4,
       4,     3,     3,     3,     3,     3,     4,     0,     1,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     3,     0,     0,     0,     5,     9,
      37,     4,     6,    19,     0,    18,     0,     7,     0,     0,
       0,    15,     0,    14,    10,     0,     8,    35,    72,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,    38,    27,    28,    29,    30,    31,
      32,     0,    44,    45,    46,    47,    48,    49,    50,    25,
       0,    24,    20,    21,    22,    23,     0,    17,     0,     0,
      11,    67,     0,    51,    52,     0,     0,    42,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,    16,    13,     0,    70,     0,
      68,    65,     0,     0,     0,     0,     0,    55,     0,     0,
      62,    61,    58,    57,    56,    54,    64,    63,     0,     0,
      12,     0,    66,    39,     0,     0,    33,    71,    60,    59,
      53,    26,    69,    40,    41,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     4,    11,    16,    24,    25,     6,    14,    15,
      62,    63,    64,    65,    44,    45,    46,    19,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    99,   100,    56,
      57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     -80,    11,   -80,     7,   -80,    12,   -15,    17,   -80,    -7,
      -5,   -80,   -80,     5,    40,    13,     3,   -80,    18,     6,
       0,    14,    17,    16,   -80,   -31,   -80,   -80,    42,   265,
     265,   265,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   265,
      85,    19,   265,    22,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   132,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
      60,   -80,   -80,   -80,   -80,   -80,     0,   -80,    73,     0,
     -80,   265,   177,   246,   246,   192,   -11,   -80,   220,   -80,
     265,   265,    66,    67,   265,   265,   265,   265,   265,   265,
     265,   265,    68,   -80,    77,   -80,   -80,    44,   117,    74,
     -80,   -80,    85,   265,   265,    85,    81,   246,   265,   265,
      39,    39,    39,    39,    39,    39,     9,     9,   265,     0,
     -80,   265,   -80,   -80,   147,   162,    53,   -80,    39,    39,
      39,   -80,   -80,   -80,   -80,    85,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   -80,    25,   -80,    76,   -80,
     -64,   -80,   -80,   -80,   -40,   -80,    69,   -80,   -80,   -80,
     -80,   -80,   -17,   -80,   -80,   -80,   -80,   -80,   -79,   -80,
     -80,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      76,   106,    95,    59,    60,    97,    23,    69,    70,    28,
       5,     2,    72,    73,    74,    29,    80,    30,    31,   103,
      13,     7,    75,   104,     8,    78,     9,    10,    32,    33,
      34,    35,    36,    37,    38,    10,    39,    40,    18,    41,
       3,    42,   132,    20,    61,    10,    80,    92,    10,    43,
      21,    71,    66,    22,    98,   131,    68,    27,    77,    90,
      91,    79,   123,    98,   107,   126,    94,   110,   111,   112,
     113,   114,   115,   116,   117,    12,    23,    92,    17,   108,
     109,   118,   119,   120,   122,    26,   124,   125,    28,   127,
     135,   128,   129,    96,    29,   136,    30,    31,    67,     0,
       0,   130,     0,     0,    98,     0,     0,    32,    33,    34,
      35,    36,    37,    38,     0,    39,    40,     0,    41,     0,
      42,     0,     0,     0,    80,     0,     0,    10,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    80,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    80,    92,     0,   121,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    80,
      92,    93,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    80,    92,   133,   101,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    80,
      92,   134,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,    80,     0,     0,
      92,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,   105,     0,    92,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    28,     0,
       0,     0,     0,     0,    29,     0,    30,    31,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    32,    33,    34,
      35,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
      40,    80,    66,     3,     4,    69,     3,    38,    39,     3,
       3,     0,    29,    30,    31,     9,     7,    11,    12,    30,
       3,     9,    39,    34,    39,    42,    41,    42,    22,    23,
      24,    25,    26,    27,    28,    42,    30,    31,    43,    33,
      29,    35,   121,    38,    44,    42,     7,    38,    42,    43,
      10,     9,    38,    40,    71,   119,    40,    39,    39,    20,
      21,    39,   102,    80,    81,   105,     6,    84,    85,    86,
      87,    88,    89,    90,    91,     6,     3,    38,     9,    13,
      13,    13,     5,    39,    10,    16,   103,   104,     3,     8,
      37,   108,   109,    68,     9,   135,    11,    12,    22,    -1,
      -1,   118,    -1,    -1,   121,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    -1,    -1,    -1,     7,    -1,    -1,    42,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     7,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     7,    38,    -1,    40,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     7,
      38,    39,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     7,    38,    39,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     7,
      38,    39,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,     7,    -1,    -1,
      38,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    36,    -1,    38,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     3,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,     0,    29,    47,     3,    52,     9,    39,    41,
      42,    48,    61,     3,    53,    54,    49,    61,    43,    62,
      38,    10,    40,     3,    50,    51,    61,    39,     3,     9,
      11,    12,    22,    23,    24,    25,    26,    27,    28,    30,
      31,    33,    35,    43,    59,    60,    61,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    74,    75,    76,     3,
       4,    44,    55,    56,    57,    58,    38,    53,    40,    38,
      39,     9,    67,    67,    67,    67,    59,    39,    67,    39,
       7,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    38,    39,     6,    55,    51,    55,    67,    72,
      73,    10,    32,    30,    34,    36,    73,    67,    13,    13,
      67,    67,    67,    67,    67,    67,    67,    67,    13,     5,
      39,    40,    10,    59,    67,    67,    59,     8,    67,    67,
      67,    55,    73,    39,    39,    37,    59
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
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
#line 70 "grammer.y"
    {(yyval.node) = root = NULL;}
    break;

  case 3:
#line 71 "grammer.y"
    {(yyval.node) = root = make_source((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 4:
#line 74 "grammer.y"
    {(yyval.node) = make_common_node("source_item", (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 5:
#line 75 "grammer.y"
    {(yyval.node) = make_common_node("source_item", (yyvsp[(2) - (3)].node), NULL);}
    break;

  case 6:
#line 78 "grammer.y"
    {(yyval.node) = make_common_node("body", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 7:
#line 79 "grammer.y"
    {(yyval.node) = make_common_node("body", (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 8:
#line 80 "grammer.y"
    {(yyval.node) = make_common_node("body", (yyvsp[(3) - (3)].node), (yyvsp[(2) - (3)].node));}
    break;

  case 9:
#line 83 "grammer.y"
    {(yyval.node) = NULL;}
    break;

  case 10:
#line 84 "grammer.y"
    {(yyval.node) = make_common_node("body_var", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 11:
#line 87 "grammer.y"
    {(yyval.node) = make_common_node("body_item", (yyvsp[(1) - (2)].node), NULL);}
    break;

  case 12:
#line 88 "grammer.y"
    {(yyval.node) = make_common_node("body_item", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));}
    break;

  case 13:
#line 91 "grammer.y"
    {(yyval.node) = make_common_node("list", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 14:
#line 92 "grammer.y"
    {(yyval.node) = make_common_node("list", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 15:
#line 95 "grammer.y"
    {(yyval.node) = make_function_signature((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), NULL);}
    break;

  case 16:
#line 96 "grammer.y"
    {(yyval.node) = make_function_signature((yyvsp[(1) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node));}
    break;

  case 17:
#line 99 "grammer.y"
    {(yyval.node) = make_common_node("list", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 18:
#line 100 "grammer.y"
    {(yyval.node) = make_common_node("list", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 19:
#line 103 "grammer.y"
    {(yyval.node) = make_common_node("list_item", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 20:
#line 104 "grammer.y"
    {(yyval.node) = make_common_node("list_item", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 21:
#line 107 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 22:
#line 108 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 23:
#line 109 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 24:
#line 113 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 25:
#line 117 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 26:
#line 121 "grammer.y"
    {(yyval.node) = make_common_node("array", (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 27:
#line 124 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 28:
#line 125 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 29:
#line 126 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 30:
#line 127 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 31:
#line 128 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 32:
#line 129 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 33:
#line 132 "grammer.y"
    {(yyval.node) = make_branch_node((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), NULL);}
    break;

  case 34:
#line 133 "grammer.y"
    {(yyval.node) = make_branch_node((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));}
    break;

  case 35:
#line 136 "grammer.y"
    {(yyval.node) = make_block(NULL);}
    break;

  case 36:
#line 137 "grammer.y"
    {(yyval.node) = make_block((yyvsp[(2) - (4)].node));}
    break;

  case 37:
#line 140 "grammer.y"
    {(yyval.node) = NULL;}
    break;

  case 38:
#line 141 "grammer.y"
    {(yyval.node) = make_common_node("block_item", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 39:
#line 145 "grammer.y"
    {(yyval.node) = make_loop_node("while", (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 40:
#line 148 "grammer.y"
    {(yyval.node) = make_loop_node("do-while", (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));}
    break;

  case 41:
#line 149 "grammer.y"
    {(yyval.node) = make_loop_node("do-until", (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node));}
    break;

  case 42:
#line 152 "grammer.y"
    {(yyval.node) = make_common_node("break", NULL, NULL);}
    break;

  case 43:
#line 155 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 44:
#line 158 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 45:
#line 159 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 46:
#line 160 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 47:
#line 161 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 48:
#line 162 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 49:
#line 163 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 50:
#line 164 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 51:
#line 167 "grammer.y"
    {(yyval.node) = make_expr_node("MINUS", (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 52:
#line 168 "grammer.y"
    {(yyval.node) = make_expr_node("NOT", (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 53:
#line 171 "grammer.y"
    {(yyval.node) = make_expr_node("ASSIGMENT", (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 54:
#line 172 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_PLUS", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 55:
#line 173 "grammer.y"
    {(yyval.node) = make_expr_node("MINUS", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 56:
#line 174 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_MUL", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 57:
#line 175 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_DIV", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 58:
#line 176 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_MOD", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 59:
#line 177 "grammer.y"
    {(yyval.node) = make_expr_node("EQUALITY", (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 60:
#line 178 "grammer.y"
    {(yyval.node) = make_expr_node("NOTEQUAL", (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 61:
#line 179 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_LESS", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 62:
#line 180 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_GREATER", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 63:
#line 181 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_AND", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 64:
#line 182 "grammer.y"
    {(yyval.node) = make_expr_node("BIN_OR", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 65:
#line 185 "grammer.y"
    {(yyval.node) = make_expr_node("BRACES", (yyvsp[(2) - (3)].node), NULL);}
    break;

  case 66:
#line 188 "grammer.y"
    {(yyval.node) = make_common_node("call", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));}
    break;

  case 67:
#line 191 "grammer.y"
    {(yyval.node) = NULL;}
    break;

  case 68:
#line 192 "grammer.y"
    {(yyval.node) = make_common_node("list", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 69:
#line 195 "grammer.y"
    {(yyval.node) = make_common_node("expr", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 196 "grammer.y"
    {(yyval.node) = make_common_node("expr", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 71:
#line 199 "grammer.y"
    {(yyval.node) = make_common_node("indexer", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));}
    break;

  case 72:
#line 202 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 73:
#line 205 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 74:
#line 206 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 75:
#line 207 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 76:
#line 208 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 77:
#line 209 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 78:
#line 210 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 79:
#line 211 "grammer.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;


/* Line 1267 of yacc.c.  */
#line 1954 "grammer.tab.c"
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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
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
		      yytoken, &yylval);
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
		  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 213 "grammer.y"

