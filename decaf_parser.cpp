/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "decaf.y" /* yacc.c:339  */

#include <cstdio>
#include <string>
#include "ast.h"

using namespace std;

extern int line;

int yylex();

void yyerror(const char *str)
{
    printf("Line %d: %s\n", line, str);
}

#define YYERROR_VERBOSE 1
Statement *input;

#line 86 "decaf_parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tokens.h".  */
#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_CONSTANT = 258,
    CHAR_CONSTANT = 259,
    ID = 260,
    STRING_CONSTANT = 261,
    KW_CLASS = 262,
    KW_BREAK = 263,
    KW_READ = 264,
    KW_PRINT = 265,
    KW_CONTINUE = 266,
    KW_EXTENDS = 267,
    KW_ELSE = 268,
    KW_WHILE = 269,
    KW_FOR = 270,
    KW_IF = 271,
    KW_INT = 272,
    KW_NEW = 273,
    KW_NULL = 274,
    KW_RETURN = 275,
    KW_TRUE = 276,
    KW_FALSE = 277,
    KW_VOID = 278,
    KW_BOOL = 279,
    OP_LT = 280,
    OP_GT = 281,
    OP_LTE = 282,
    OP_GTE = 283,
    OP_NE = 284,
    OP_EQ = 285,
    OP_ROT = 286,
    OP_NOT = 287,
    OP_OR = 288,
    OP_AND = 289,
    OP_SHIFT_LEFT = 290,
    OP_SHIFT_RIGHT = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "decaf.y" /* yacc.c:355  */

    char *id_t;
    int  num_t;
    char char_t;
    ExprList * exprList_t;
    ExprVector * exprvect_t;
    IdList * idList_t;
    GlobalIdList * gIdList_t;
    ParameterDefList * pdeflist_t;
    Expr * expr_t;
    Statement *statement_t;
    DataType type_t;

#line 177 "decaf_parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 192 "decaf_parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    46,     2,     2,
      44,    45,    49,    47,    41,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    60,    61,    65,    81,    85,    86,    89,
      93,    99,   100,   103,   104,   106,   122,   125,   126,   129,
     130,   133,   137,   143,   146,   156,   157,   159,   175,   177,
     179,   183,   188,   189,   192,   193,   196,   212,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   225,   241,   243,
     244,   246,   247,   249,   251,   252,   253,   255,   256,   258,
     262,   267,   271,   276,   280,   285,   286,   288,   290,   291,
     294,   295,   297,   298,   300,   301,   302,   304,   305,   306,
     307,   308,   310,   311,   312,   313,   315,   316,   318,   319,
     320,   322,   323,   324,   326,   327,   328,   329,   330,   331,
     333,   334,   335,   337,   338
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_CONSTANT", "CHAR_CONSTANT", "ID",
  "STRING_CONSTANT", "KW_CLASS", "KW_BREAK", "KW_READ", "KW_PRINT",
  "KW_CONTINUE", "KW_EXTENDS", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_IF",
  "KW_INT", "KW_NEW", "KW_NULL", "KW_RETURN", "KW_TRUE", "KW_FALSE",
  "KW_VOID", "KW_BOOL", "OP_LT", "OP_GT", "OP_LTE", "OP_GTE", "OP_NE",
  "OP_EQ", "OP_ROT", "OP_NOT", "OP_OR", "OP_AND", "OP_SHIFT_LEFT",
  "OP_SHIFT_RIGHT", "'{'", "'}'", "';'", "'='", "','", "'['", "']'", "'('",
  "')'", "'%'", "'+'", "'-'", "'*'", "'/'", "'!'", "$accept", "input",
  "opt_field_decl", "field_decls", "field", "id_list_global",
  "id_decl_global", "opt_method_decl", "method_decl", "method",
  "opt_arg_list", "arg_list", "arg", "block", "opt_var_decl", "var_decls",
  "var_decl", "id_list_local", "type", "opt_statements", "statements",
  "statement", "assign_list", "opt_else", "opt_expr", "assign",
  "method_call", "opt_call_arg_list", "call_arg_list", "print_list",
  "read_list", "argument", "lvalue", "opt_array", "expr", "expra",
  "equality", "relational", "shift", "module", "expras", "term", "factor",
  "constant", "bool_constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   123,   125,    59,
      61,    44,    91,    93,    40,    41,    37,    43,    45,    42,
      47,    33
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,     4,    34,    41,  -102,   -10,  -102,  -102,    25,   -10,
    -102,    60,    69,    48,    25,  -102,    77,  -102,    37,    57,
    -102,    18,  -102,  -102,    53,    22,   102,  -102,   103,   -10,
     -10,  -102,  -102,  -102,  -102,    85,  -102,    71,    90,  -102,
      88,    93,  -102,   130,    92,  -102,  -102,   101,   -10,  -102,
     101,   -10,  -102,  -102,  -102,    79,   -10,  -102,   134,    62,
     104,   136,    24,   105,    98,   106,   107,    32,  -102,   108,
      79,  -102,   109,   110,   112,  -102,  -102,    74,    32,    32,
    -102,  -102,   111,   113,  -102,    76,  -102,    32,    32,    32,
     114,  -102,  -102,   123,   124,    21,    75,    28,    99,    44,
      73,  -102,  -102,  -102,    32,   136,    32,   118,   123,  -102,
    -102,  -102,  -102,    32,  -102,   142,    -2,   115,   120,   123,
     136,    32,   -23,  -102,  -102,    24,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,   -22,    78,  -102,   -13,  -102,   123,  -102,  -102,
    -102,    32,  -102,   117,  -102,  -102,   124,    21,    75,    75,
      28,    28,    28,    28,    99,    99,    99,    44,    73,    73,
    -102,  -102,   101,    32,   136,   101,   123,  -102,  -102,     0,
    -102,   146,   136,   101,  -102,    15,  -102,   101,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,    32,    33,    14,     3,
       6,     0,     0,     0,    13,    16,     0,     5,    11,     0,
      10,     0,     2,    15,     0,     0,     0,     7,     0,    20,
      20,   100,   101,   103,   104,     0,   102,     0,    11,     9,
       0,    19,    22,     0,     0,     8,    12,     0,     0,    23,
       0,    26,    18,    21,    17,    35,    25,    28,     0,    69,
       0,     0,     0,     0,     0,     0,     0,    52,    46,     0,
      34,    37,     0,     0,     0,    27,    31,     0,     0,    58,
      67,    44,    69,    56,    64,    69,    65,     0,     0,     0,
      55,    62,    96,    66,    71,    73,    76,    81,    85,    87,
      90,    93,    98,    45,     0,     0,     0,     0,    51,    24,
      36,    38,    39,     0,    29,     0,     0,     0,    57,    60,
       0,    58,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    43,    53,    30,    68,
      54,     0,    63,     0,    99,    61,    70,    72,    75,    74,
      78,    77,    79,    80,    84,    83,    82,    86,    88,    89,
      91,    92,     0,     0,     0,     0,    59,    97,    41,     0,
      47,    50,     0,     0,    40,     0,    49,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,  -102,   154,  -102,   137,  -102,  -102,   150,
     138,  -102,   119,   -47,  -102,  -102,   116,  -102,    10,  -102,
    -102,    96,   -11,  -102,  -102,  -101,  -102,    49,  -102,  -102,
    -102,    50,   -53,  -102,   -66,    43,    46,     2,   -21,   -65,
      39,   -12,   -83,   149,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    19,    20,    13,    14,    15,
      40,    41,    42,    68,    55,    56,    57,    77,    43,    69,
      70,    71,   143,   184,   107,    72,    73,   117,   118,    90,
      83,    91,    92,    80,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,   108,    74,    54,   144,   123,   124,     6,    84,     3,
     126,   126,   116,   119,     7,    11,     1,    74,    16,    11,
     126,   122,   154,   172,    16,    31,    32,    31,    32,    85,
      86,   126,   175,   126,     4,    31,    32,    85,   142,   182,
     145,   149,     6,    33,    34,    33,    34,   147,    12,     7,
     128,   129,    74,    33,    34,   119,   174,   170,   171,   134,
     187,    58,    29,   135,   136,    18,    58,   152,    87,   164,
     165,   166,    88,   180,    21,    89,    87,    25,     5,    26,
      88,   144,    24,    89,    59,   176,    22,    60,    61,    62,
      63,   138,   139,    64,    65,    66,    27,    30,    28,    67,
     130,   131,   132,   133,    78,    37,    79,   179,    38,   160,
     161,   162,   163,   114,    46,   115,    51,   173,    78,   174,
     121,    74,   140,   141,    45,   178,   168,   169,   181,    74,
     158,   159,    26,    47,    48,    49,   186,    50,    51,    76,
     188,    82,   104,    81,   103,   137,   109,   148,   111,   112,
     105,   106,   113,    78,   120,   125,   126,   146,   127,   183,
     150,   151,   177,    17,    23,    39,   110,    53,    44,   156,
     153,   185,    75,   157,    35,   155,   167
};

static const yytype_uint8 yycheck[] =
{
      47,    67,    55,    50,   105,    88,    89,    17,    61,     5,
      33,    33,    78,    79,    24,     5,     7,    70,     8,     9,
      33,    87,    45,    45,    14,     3,     4,     3,     4,     5,
       6,    33,    45,    33,     0,     3,     4,     5,   104,    39,
     106,    43,    17,    21,    22,    21,    22,   113,    23,    24,
      29,    30,   105,    21,    22,   121,    41,   140,   141,    31,
      45,    51,    44,    35,    36,     5,    56,   120,    44,   134,
     135,   136,    48,   174,     5,    51,    44,    40,    37,    42,
      48,   182,     5,    51,     5,   151,    38,     8,     9,    10,
      11,    47,    48,    14,    15,    16,    39,    44,    41,    20,
      25,    26,    27,    28,    42,     3,    44,   173,     5,   130,
     131,   132,   133,    39,    43,    41,    37,    39,    42,    41,
      44,   174,    49,    50,    39,   172,   138,   139,   175,   182,
     128,   129,    42,    45,    41,     5,   183,    45,    37,     5,
     187,     5,    44,    39,    39,    46,    38,     5,    39,    39,
      44,    44,    40,    42,    41,    41,    33,    39,    34,    13,
      45,    41,    45,     9,    14,    28,    70,    48,    30,   126,
     121,   182,    56,   127,    25,   125,   137
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    53,     5,     0,    37,    17,    24,    54,    55,
      56,    70,    23,    59,    60,    61,    70,    56,     5,    57,
      58,     5,    38,    61,     5,    40,    42,    39,    41,    44,
      44,     3,     4,    21,    22,    95,    96,     3,     5,    58,
      62,    63,    64,    70,    62,    39,    43,    45,    41,     5,
      45,    37,    65,    64,    65,    66,    67,    68,    70,     5,
       8,     9,    10,    11,    14,    15,    16,    20,    65,    71,
      72,    73,    77,    78,    84,    68,     5,    69,    42,    44,
      85,    39,     5,    82,    84,     5,     6,    44,    48,    51,
      81,    83,    84,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    39,    44,    44,    44,    76,    86,    38,
      73,    39,    39,    40,    39,    41,    86,    79,    80,    86,
      41,    44,    86,    94,    94,    41,    33,    34,    29,    30,
      25,    26,    27,    28,    31,    35,    36,    46,    47,    48,
      49,    50,    86,    74,    77,    86,    39,    86,     5,    43,
      45,    41,    84,    79,    45,    83,    87,    88,    89,    89,
      90,    90,    90,    90,    91,    91,    91,    92,    93,    93,
      94,    94,    45,    39,    41,    45,    86,    45,    65,    86,
      77,    65,    39,    13,    75,    74,    65,    45,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    65,    66,    66,    67,    67,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    91,    91,    92,    92,
      92,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     0,     2,     1,     3,     5,     3,
       1,     1,     4,     1,     0,     2,     1,     6,     6,     1,
       0,     3,     1,     2,     4,     1,     0,     2,     1,     3,
       3,     1,     1,     1,     1,     0,     2,     1,     2,     2,
       6,     5,     9,     3,     2,     2,     1,     3,     1,     2,
       0,     1,     0,     3,     4,     2,     2,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     3,     0,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     2,     1,     4,     1,     3,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 56 "decaf.y" /* yacc.c:1646  */
    {input = new ClassStatement((yyvsp[-4].id_t),(yyvsp[-2].statement_t),(yyvsp[-1].statement_t));}
#line 1407 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1413 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = 0; }
#line 1419 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 65 "decaf.y" /* yacc.c:1646  */
    { 
				        if ((yyvsp[-1].statement_t)->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)(yyvsp[-1].statement_t);
				            
				            block->stList.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back((yyvsp[-1].statement_t));
				            l.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = new BlockStatement(l);
				        }
		               }
#line 1440 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 81 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1446 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new GlobalDeclarationStatement((yyvsp[-2].type_t),*(yyvsp[-1].gIdList_t));delete (yyvsp[-1].gIdList_t);}
#line 1452 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new GlobalDeclarationAssignStatement((yyvsp[-4].type_t), (yyvsp[-3].id_t), (yyvsp[-1].expr_t)); }
#line 1458 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 89 "decaf.y" /* yacc.c:1646  */
    {
							(yyval.gIdList_t) = (yyvsp[-2].gIdList_t);
					    		(yyval.gIdList_t)->push_back((GlobalIdDeclarationStatement*)(yyvsp[0].statement_t));
						  }
#line 1467 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 93 "decaf.y" /* yacc.c:1646  */
    {
							(yyval.gIdList_t) = new GlobalIdList;
					    		(yyval.gIdList_t)->push_back((GlobalIdDeclarationStatement*)(yyvsp[0].statement_t));
						  }
#line 1476 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new GlobalIdDeclarationStatement((yyvsp[0].id_t), 0); }
#line 1482 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 100 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new GlobalIdDeclarationStatement((yyvsp[-3].id_t), (yyvsp[-1].num_t)); }
#line 1488 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1494 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = 0;}
#line 1500 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 106 "decaf.y" /* yacc.c:1646  */
    { 
				        if ((yyvsp[-1].statement_t)->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)(yyvsp[-1].statement_t);
				            
				            block->stList.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back((yyvsp[-1].statement_t));
				            l.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = new BlockStatement(l);
				        }
		            }
#line 1521 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1527 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 125 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new MethodStatement((yyvsp[-5].type_t), (yyvsp[-4].id_t), *(yyvsp[-2].pdeflist_t), (yyvsp[0].statement_t));delete (yyvsp[-2].pdeflist_t); }
#line 1533 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 126 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new MethodStatement(VOID, (yyvsp[-4].id_t), *(yyvsp[-2].pdeflist_t), (yyvsp[0].statement_t));delete (yyvsp[-2].pdeflist_t); }
#line 1539 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "decaf.y" /* yacc.c:1646  */
    { (yyval.pdeflist_t) = (yyvsp[0].pdeflist_t); }
#line 1545 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 130 "decaf.y" /* yacc.c:1646  */
    { (yyval.pdeflist_t) = new ParameterDefList; }
#line 1551 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 133 "decaf.y" /* yacc.c:1646  */
    { 
				       (yyval.pdeflist_t) = (yyvsp[-2].pdeflist_t);
				       (yyval.pdeflist_t)->push_back((ParameterDefinitionStatement*)(yyvsp[0].statement_t));
		            }
#line 1560 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 137 "decaf.y" /* yacc.c:1646  */
    {
				(yyval.pdeflist_t) = new ParameterDefList;
			        (yyval.pdeflist_t)->push_back((ParameterDefinitionStatement*)(yyvsp[0].statement_t));
			    }
#line 1569 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new ParameterDefinitionStatement((yyvsp[-1].type_t), (yyvsp[0].id_t)); }
#line 1575 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "decaf.y" /* yacc.c:1646  */
    { 
				            list<Statement *> l;
				            if((yyvsp[-2].statement_t) != 0)
				            	l.push_back((yyvsp[-2].statement_t));
					    if((yyvsp[-1].statement_t) != 0)
				            	l.push_back((yyvsp[-1].statement_t));
				            (yyval.statement_t) = new BlockStatement(l);
					  }
#line 1588 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1594 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = 0; }
#line 1600 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 159 "decaf.y" /* yacc.c:1646  */
    { 
				        if ((yyvsp[-1].statement_t)->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)(yyvsp[-1].statement_t);
				            
				            block->stList.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back((yyvsp[-1].statement_t));
				            l.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = new BlockStatement(l);
				        }
		              }
#line 1621 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 175 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1627 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 177 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new LocalDeclarationStatement((yyvsp[-2].type_t), *(yyvsp[-1].idList_t));delete (yyvsp[-1].idList_t); }
#line 1633 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "decaf.y" /* yacc.c:1646  */
    {
					    (yyval.idList_t) = (yyvsp[-2].idList_t);
					    (yyval.idList_t)->push_back((yyvsp[0].id_t));
				    }
#line 1642 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 183 "decaf.y" /* yacc.c:1646  */
    {
		    (yyval.idList_t) = new IdList;
		    (yyval.idList_t)->push_back((yyvsp[0].id_t));
	     }
#line 1651 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 188 "decaf.y" /* yacc.c:1646  */
    { (yyval.type_t) = INT;}
#line 1657 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 189 "decaf.y" /* yacc.c:1646  */
    { (yyval.type_t) = BOOLEAN;}
#line 1663 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 192 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1669 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 193 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = 0; }
#line 1675 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 196 "decaf.y" /* yacc.c:1646  */
    { 
				        if ((yyvsp[-1].statement_t)->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)(yyvsp[-1].statement_t);
				            
				            block->stList.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back((yyvsp[-1].statement_t));
				            l.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = new BlockStatement(l);
				        }
				 }
#line 1696 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 212 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1702 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[-1].statement_t); }
#line 1708 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 216 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[-1].statement_t); }
#line 1714 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 217 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new IfStatement((yyvsp[-3].expr_t),(yyvsp[-1].statement_t),(yyvsp[0].statement_t)); }
#line 1720 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 218 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new WhileStatement((yyvsp[-2].expr_t),(yyvsp[0].statement_t)); }
#line 1726 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 219 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new ForStatement((yyvsp[-6].statement_t),(yyvsp[-4].expr_t),(yyvsp[-2].statement_t),(yyvsp[0].statement_t));}
#line 1732 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 220 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new ReturnStatement((yyvsp[-1].expr_t)); }
#line 1738 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new BreakStatement(); }
#line 1744 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 222 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new ContinueStatement(); }
#line 1750 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 223 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1756 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 225 "decaf.y" /* yacc.c:1646  */
    { 
				        if ((yyvsp[-2].statement_t)->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)(yyvsp[-2].statement_t);
				            
				            block->stList.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back((yyvsp[-2].statement_t));
				            l.push_back((yyvsp[0].statement_t));
				            
				            (yyval.statement_t) = new BlockStatement(l);
				        }
				    }
#line 1777 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 241 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1783 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 243 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1789 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 244 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = 0; }
#line 1795 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 246 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1801 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 247 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = 0; }
#line 1807 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 249 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new AssignStatement((yyvsp[-2].expr_t),(yyvsp[0].expr_t)); }
#line 1813 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 251 "decaf.y" /* yacc.c:1646  */
    {  (yyval.statement_t) = new MethodCallStatement((yyvsp[-3].id_t), *(yyvsp[-1].exprvect_t));delete (yyvsp[-1].exprvect_t); }
#line 1819 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new PrintStatement(*(yyvsp[0].exprList_t));delete (yyvsp[0].exprList_t); }
#line 1825 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 253 "decaf.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new ReadStatement(*(yyvsp[0].exprList_t));delete (yyvsp[0].exprList_t); }
#line 1831 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 255 "decaf.y" /* yacc.c:1646  */
    { (yyval.exprvect_t) = (yyvsp[0].exprvect_t); }
#line 1837 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 256 "decaf.y" /* yacc.c:1646  */
    { (yyval.exprvect_t) = new ExprVector; }
#line 1843 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 258 "decaf.y" /* yacc.c:1646  */
    {
					    (yyval.exprvect_t) = (yyvsp[-2].exprvect_t);
					    (yyval.exprvect_t)->push_back((yyvsp[0].expr_t));
				       }
#line 1852 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 262 "decaf.y" /* yacc.c:1646  */
    { 
			    (yyval.exprvect_t) = new ExprVector;
			    (yyval.exprvect_t)->push_back((yyvsp[0].expr_t));
		     }
#line 1861 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 267 "decaf.y" /* yacc.c:1646  */
    {
					    (yyval.exprList_t) = (yyvsp[-2].exprList_t);
					    (yyval.exprList_t)->push_back((yyvsp[0].expr_t));
				    }
#line 1870 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 271 "decaf.y" /* yacc.c:1646  */
    { 
			    (yyval.exprList_t) = new ExprList;
			    (yyval.exprList_t)->push_back((yyvsp[0].expr_t));
		      }
#line 1879 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 276 "decaf.y" /* yacc.c:1646  */
    {
					    (yyval.exprList_t) = (yyvsp[-2].exprList_t);
					    (yyval.exprList_t)->push_back((yyvsp[0].expr_t));
				}
#line 1888 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 280 "decaf.y" /* yacc.c:1646  */
    { 
			    (yyval.exprList_t) = new ExprList;
			    (yyval.exprList_t)->push_back((yyvsp[0].expr_t));
		   }
#line 1897 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 285 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new StringExpr((yyvsp[0].id_t)); }
#line 1903 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 286 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1909 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 288 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new IdExpr((yyvsp[-1].id_t), (yyvsp[0].expr_t)); }
#line 1915 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 290 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[-1].expr_t); }
#line 1921 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 291 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = 0; }
#line 1927 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 294 "decaf.y" /* yacc.c:1646  */
    {  (yyval.expr_t) = new OrExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t));  }
#line 1933 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 295 "decaf.y" /* yacc.c:1646  */
    {  (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1939 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 297 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new AndExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 1945 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 298 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1951 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 300 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new EQExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 1957 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 301 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new NEExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 1963 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 302 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyval.expr_t); }
#line 1969 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 304 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new GTExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 1975 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 305 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new LTExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 1981 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 306 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new LTEExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 1987 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 307 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new GTEExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 1993 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 308 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1999 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 310 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new RShiftExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 2005 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 311 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new LShiftExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 2011 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 312 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new RotExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t)); }
#line 2017 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 313 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2023 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 315 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new ModExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 2029 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 316 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2035 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 318 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new AddExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 2041 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 319 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new SubExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 2047 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 320 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2053 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 322 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new MultExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 2059 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 323 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new DivExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t)); }
#line 2065 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 324 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2071 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 326 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new MultExpr(new NumExpr(-1), (yyvsp[0].expr_t)); }
#line 2077 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 327 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new NotExpr((yyvsp[0].expr_t)); }
#line 2083 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 328 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2089 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 329 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new MethodCallExpr((yyvsp[-3].id_t),*(yyvsp[-1].exprvect_t));delete (yyvsp[-1].exprvect_t); }
#line 2095 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 330 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2101 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 331 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[-1].expr_t); }
#line 2107 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 333 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new NumExpr((yyvsp[0].num_t)); }
#line 2113 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 334 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new CharExpr((yyvsp[0].char_t)); }
#line 2119 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 335 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2125 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 337 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new BoolExpr(true); }
#line 2131 "decaf_parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 338 "decaf.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new BoolExpr(false); }
#line 2137 "decaf_parser.cpp" /* yacc.c:1646  */
    break;


#line 2141 "decaf_parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 341 "decaf.y" /* yacc.c:1906  */

