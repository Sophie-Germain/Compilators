/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 14 "parser.y"

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(char *msg); // standard error-handling routine


/* Line 371 of yacc.c  */
#line 83 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Double = 261,
     T_String = 262,
     T_Class = 263,
     T_LessEqual = 264,
     T_GreaterEqual = 265,
     T_Equal = 266,
     T_NotEqual = 267,
     T_Dims = 268,
     T_And = 269,
     T_Or = 270,
     T_Null = 271,
     T_Extends = 272,
     T_This = 273,
     T_Interface = 274,
     T_Implements = 275,
     T_While = 276,
     T_For = 277,
     T_If = 278,
     T_Else = 279,
     T_Return = 280,
     T_Break = 281,
     T_New = 282,
     T_NewArray = 283,
     T_Print = 284,
     T_ReadInteger = 285,
     T_ReadLine = 286,
     T_Identifier = 287,
     T_StringConstant = 288,
     T_IntConstant = 289,
     T_DoubleConstant = 290,
     T_BoolConstant = 291,
     T_UnaryMinus = 292,
     T_NElse = 293
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Double 261
#define T_String 262
#define T_Class 263
#define T_LessEqual 264
#define T_GreaterEqual 265
#define T_Equal 266
#define T_NotEqual 267
#define T_Dims 268
#define T_And 269
#define T_Or 270
#define T_Null 271
#define T_Extends 272
#define T_This 273
#define T_Interface 274
#define T_Implements 275
#define T_While 276
#define T_For 277
#define T_If 278
#define T_Else 279
#define T_Return 280
#define T_Break 281
#define T_New 282
#define T_NewArray 283
#define T_Print 284
#define T_ReadInteger 285
#define T_ReadLine 286
#define T_Identifier 287
#define T_StringConstant 288
#define T_IntConstant 289
#define T_DoubleConstant 290
#define T_BoolConstant 291
#define T_UnaryMinus 292
#define T_NElse 293



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 50 "parser.y"

    int   integerConstant;
    bool  boolConstant;
    char  *stringConstant;
    double doubleConstant;
    char  identifier[MaxIdentLen+1];
    Decl  *decl;
    List<Decl*> *declList;
    List<NamedType*> *namedTypeList;
    List<Stmt*> *stmtList;
    List<Expr*> *exprList;
    Program *program;
    VarDecl *varDecl;
    Type *type;
    FnDecl *fnDecl;
    List<VarDecl*> *varList;
    ClassDecl *classDecl;
    InterfaceDecl *interfDecl;
    StmtBlock *stmtBlock;
    Stmt *stmt;
    IfStmt *ifStmt;
    WhileStmt *whileStmt;
    ForStmt *forStmt;
    ReturnStmt *returnStmt;
    BreakStmt *breakStmt;
    PrintStmt *printStmt;
    Expr *expr;
    LValue *lValue;
    Call *call;
    NamedType *namedType;


/* Line 387 of yacc.c  */
#line 235 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 276 "y.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   927

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  223

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    45,     2,     2,
      51,    52,    43,    41,    53,    42,    49,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      39,    38,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      35,    36,    47,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      21,    24,    26,    29,    36,    43,    45,    47,    49,    51,
      53,    56,    58,    59,    63,    65,    71,    79,    87,    97,
     100,   101,   103,   105,   109,   111,   117,   122,   125,   127,
     134,   141,   146,   150,   154,   157,   160,   162,   164,   166,
     168,   170,   172,   174,   176,   178,   181,   187,   195,   203,
     212,   221,   231,   237,   240,   244,   247,   253,   255,   259,
     264,   269,   276,   278,   279,   281,   283,   285,   287,   289,
     293,   295,   299,   301,   303,   305,   307,   311,   315,   319,
     323,   327,   331,   334,   338,   342,   346,   350,   354,   358,
     362,   366,   369,   373,   377,   382
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    59,    60,    -1,    60,    -1,
      61,    -1,    68,    -1,    72,    -1,    64,    -1,    63,    37,
      -1,    62,    61,    -1,    61,    -1,    65,    32,    -1,    65,
      32,    51,    66,    52,    75,    -1,     3,    32,    51,    66,
      52,    75,    -1,     5,    -1,     6,    -1,     7,    -1,     4,
      -1,    32,    -1,    65,    13,    -1,    67,    -1,    -1,    67,
      53,    63,    -1,    63,    -1,     8,    32,    54,    69,    55,
      -1,     8,    32,    17,    32,    54,    69,    55,    -1,     8,
      32,    20,    71,    54,    69,    55,    -1,     8,    32,    17,
      32,    20,    71,    54,    69,    55,    -1,    69,    70,    -1,
      -1,    61,    -1,    64,    -1,    71,    53,    32,    -1,    32,
      -1,    19,    32,    54,    73,    55,    -1,    19,    32,    54,
      55,    -1,    73,    74,    -1,    74,    -1,    65,    32,    51,
      66,    52,    37,    -1,     3,    32,    51,    66,    52,    37,
      -1,    54,    62,    76,    55,    -1,    54,    62,    55,    -1,
      54,    76,    55,    -1,    54,    55,    -1,    76,    77,    -1,
      77,    -1,    78,    -1,    80,    -1,    79,    -1,    82,    -1,
      81,    -1,    83,    -1,    75,    -1,    37,    -1,    89,    37,
      -1,    23,    51,    89,    52,    77,    -1,    23,    51,    89,
      52,    77,    24,    77,    -1,    22,    51,    37,    89,    37,
      52,    77,    -1,    22,    51,    89,    37,    89,    37,    52,
      77,    -1,    22,    51,    37,    89,    37,    89,    52,    77,
      -1,    22,    51,    89,    37,    89,    37,    89,    52,    77,
      -1,    21,    51,    89,    52,    77,    -1,    25,    37,    -1,
      25,    89,    37,    -1,    26,    37,    -1,    29,    51,    88,
      52,    37,    -1,    32,    -1,    89,    49,    32,    -1,    89,
      48,    89,    56,    -1,    32,    51,    86,    52,    -1,    89,
      49,    32,    51,    86,    52,    -1,    88,    -1,    -1,    34,
      -1,    35,    -1,    36,    -1,    33,    -1,    16,    -1,    88,
      53,    89,    -1,    89,    -1,    84,    38,    89,    -1,    87,
      -1,    84,    -1,    18,    -1,    85,    -1,    51,    89,    52,
      -1,    89,    41,    89,    -1,    89,    42,    89,    -1,    89,
      43,    89,    -1,    89,    44,    89,    -1,    89,    45,    89,
      -1,    42,    89,    -1,    89,    39,    89,    -1,    89,     9,
      89,    -1,    89,    40,    89,    -1,    89,    10,    89,    -1,
      89,    11,    89,    -1,    89,    12,    89,    -1,    89,    14,
      89,    -1,    89,    15,    89,    -1,    46,    89,    -1,    30,
      51,    52,    -1,    31,    51,    52,    -1,    27,    51,    32,
      52,    -1,    28,    51,    89,    53,    65,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   164,   165,   168,   169,   170,   171,   175,
     178,   179,   182,   185,   186,   189,   190,   191,   192,   193,
     194,   197,   198,   201,   202,   205,   206,   207,   208,   211,
     212,   215,   216,   219,   220,   223,   224,   227,   228,   231,
     232,   235,   236,   237,   238,   241,   242,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   258,   259,   262,   263,
     264,   265,   268,   271,   272,   275,   278,   281,   282,   283,
     286,   287,   290,   291,   294,   295,   296,   297,   298,   301,
     302,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_LessEqual", "T_GreaterEqual", "T_Equal",
  "T_NotEqual", "T_Dims", "T_And", "T_Or", "T_Null", "T_Extends", "T_This",
  "T_Interface", "T_Implements", "T_While", "T_For", "T_If", "T_Else",
  "T_Return", "T_Break", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Identifier", "T_StringConstant", "T_IntConstant",
  "T_DoubleConstant", "T_BoolConstant", "';'", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "T_UnaryMinus", "'['", "'.'",
  "T_NElse", "'('", "')'", "','", "'{'", "'}'", "']'", "$accept",
  "Program", "DeclList", "Decl", "VariableDecl", "VariableDeclList",
  "Variable", "FunctionDecl", "Type", "Formals", "VarList", "ClassDecl",
  "FieldList", "Field", "IdentList", "InterfaceDecl", "PrototypeList",
  "Prototype", "StmtBlock", "StmtList", "Stmt", "IfStmt", "ForStmt",
  "WhileStmt", "ReturnStmt", "BreakStmt", "PrintStmt", "LValue", "Call",
  "Actuals", "Constant", "ExprList", "Expr", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,    59,    61,    60,
      62,    43,    45,    42,    47,    37,    33,   292,    91,    46,
     293,    40,    41,    44,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    61,
      62,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    79,    80,    81,    81,    82,    83,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    87,    87,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     6,     6,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     5,     7,     7,     9,     2,
       0,     1,     1,     3,     1,     5,     4,     2,     1,     6,
       6,     4,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     7,     7,     8,
       8,     9,     5,     2,     3,     2,     5,     1,     3,     4,
       4,     6,     1,     0,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    18,    15,    16,    17,     0,     0,    19,     0,
       2,     4,     5,     0,     8,     0,     6,     7,     0,     0,
       0,     1,     3,     9,    20,    12,    22,     0,     0,    30,
       0,    22,    24,     0,     0,    21,     0,    34,     0,     0,
       0,    36,     0,     0,    38,     0,    12,     0,     0,     0,
      30,     0,    30,    25,    31,    32,    29,     0,     0,    35,
      37,     0,     0,    14,    23,     0,     0,    33,     0,    22,
      22,    13,    78,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    77,    74,    75,    76,    54,
       0,     0,     0,    44,    11,     0,    53,     0,    46,    47,
      49,    48,    51,    50,    52,    83,    85,    82,     0,    30,
      26,    27,     0,     0,     0,     0,     0,    67,    63,     0,
      65,     0,     0,     0,     0,     0,    73,    92,   101,     0,
      42,    10,     0,    43,    45,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
       0,     0,     0,    80,   102,   103,     0,    72,    86,    41,
      81,    94,    96,    97,    98,    99,   100,    93,    95,    87,
      88,    89,    90,    91,     0,    68,    28,    40,    39,     0,
       0,     0,     0,   104,     0,     0,     0,    70,    69,    73,
      62,     0,     0,    56,     0,    66,    79,     0,     0,     0,
       0,     0,   105,    71,    58,     0,     0,     0,    57,    60,
      59,     0,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    54,    95,    13,    55,    33,    34,
      35,    16,    39,    56,    38,    17,    43,    44,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   166,
     107,   167,   108
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int16 yypact[] =
{
     156,   -20,   -96,   -96,   -96,   -96,   -11,    -3,   -96,     5,
     156,   -96,   -96,    -4,   -96,    -5,   -96,   -96,   -13,    38,
      -7,   -96,   -96,   -96,   -96,    25,   164,    27,    59,   -96,
      12,   164,   -96,     9,    41,    51,     8,   -96,   -18,    82,
      80,   -96,    19,    96,   -96,    63,   -96,    70,   164,    59,
     -96,    95,   -96,   -96,   -96,   -96,   -96,    78,    85,   -96,
     -96,    70,   177,   -96,   -96,    42,   102,   -96,   135,   164,
     164,   -96,   -96,   -96,    92,    99,   103,   832,   116,   104,
     105,   107,   114,   115,    10,   -96,   -96,   -96,   -96,   -96,
     876,   876,   876,   -96,   -96,   220,   -96,   673,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   134,   -96,   -96,   442,   -96,
     -96,   -96,   121,   124,   876,   854,   876,   126,   -96,   483,
     -96,   146,   876,   876,   127,   128,   876,    62,    62,   312,
     -96,   -96,   713,   -96,   -96,   876,   876,   876,   876,   876,
     876,   876,   -96,   876,   876,   876,   876,   876,   876,   876,
     876,   153,   142,   149,   150,   326,   876,   496,   370,   -96,
     137,   267,    79,   591,   -96,   -96,   139,   148,   -96,   -96,
     591,   628,   628,   639,   639,   613,   602,   628,   628,    74,
      74,    62,    62,    62,   249,   141,   -96,   -96,   -96,   753,
     537,   876,   753,   -96,   164,   178,   876,   -96,   -96,   876,
     -96,   778,   550,   192,   -12,   -96,   591,   165,   753,   384,
     805,   753,   -96,   -96,   -96,   753,   753,   428,   -96,   -96,
     -96,   753,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -96,   -96,   208,     3,   -96,   -17,    54,     0,   -24,
     -96,   -96,   -46,   -96,   171,   -96,   -96,   179,   -27,   138,
     -95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,    22,
     -96,   106,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int16 yytable[] =
{
      15,    24,   134,    12,    66,    21,    68,    45,    24,    32,
      15,   119,    18,    12,    32,    40,     2,     3,     4,     5,
      63,    19,    24,   -19,   127,   128,   129,    25,    49,    20,
      42,    64,    24,    23,    71,    51,    52,   134,    26,    15,
     212,    46,   -19,    42,     8,   112,   113,    30,   155,   157,
     158,    58,    32,    32,    14,    27,   161,   163,    28,    36,
     163,   126,    50,   152,    14,    94,    15,    41,    15,   170,
     171,   172,   173,   174,   175,   176,    31,   177,   178,   179,
     180,   181,   182,   183,   184,     1,     2,     3,     4,     5,
     190,    37,    29,    47,   200,    51,   109,   203,   131,    40,
       2,     3,     4,     5,    48,     1,     2,     3,     4,     5,
     150,   151,    57,   214,     8,    61,   218,   147,   148,   149,
     219,   220,   150,   151,    62,   202,   222,    67,     8,    69,
     206,   195,   196,   163,     8,   209,    70,    53,     1,     2,
       3,     4,     5,   114,   217,     1,     2,     3,     4,     5,
     115,    59,    15,   120,   116,   121,   122,   110,   123,     1,
       2,     3,     4,     5,     6,   124,   125,     8,     2,     3,
       4,     5,   135,   153,     8,     7,   154,   126,   160,   164,
     165,     2,     3,     4,     5,   185,   187,   188,     8,   193,
     111,   197,   199,    72,   204,    73,     8,   186,    74,    75,
      76,   196,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   205,   211,   213,    22,    90,
      65,   207,    60,    91,     2,     3,     4,     5,    92,   162,
       0,    62,    93,   132,     0,     0,    72,     0,    73,     0,
       0,    74,    75,    76,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   136,   137,
     138,   139,    90,   140,   141,     0,    91,     0,     0,     0,
       0,    92,     0,     0,    62,   130,   136,   137,   138,   139,
       0,   140,   141,     0,     0,     0,     0,     0,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,   198,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,     0,     0,     0,
     194,   136,   137,   138,   139,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,   136,   137,   138,   139,     0,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,     0,     0,   168,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,     0,     0,   189,   136,
     137,   138,   139,     0,   140,   141,     0,     0,     0,     0,
       0,     0,     0,   136,   137,   138,   139,     0,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
       0,     0,   192,   143,   144,   145,   146,   147,   148,   149,
       0,     0,   150,   151,     0,     0,   215,   136,   137,   138,
     139,     0,   140,   141,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
     146,   147,   148,   149,     0,     0,   150,   151,     0,   142,
     221,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,   136,   137,   138,   139,     0,   140,   141,     0,
       0,     0,     0,     0,     0,   136,   137,   138,   139,     0,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
     159,     0,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   191,     0,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,   136,   137,   138,   139,
       0,   140,   141,     0,     0,     0,     0,     0,     0,   136,
     137,   138,   139,     0,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,   201,     0,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   210,     0,   143,
     144,   145,   146,   147,   148,   149,     0,     0,   150,   151,
     136,   137,   138,   139,     0,   140,   141,     0,     0,     0,
       0,   136,   137,   138,   139,     0,   140,     0,     0,     0,
       0,     0,   136,   137,   138,   139,     0,     0,     0,     0,
     143,   144,   145,   146,   147,   148,   149,   -20,   -20,   150,
     151,   143,   144,   145,   146,   147,   148,   149,   136,   137,
     150,   151,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,     0,     0,     0,     0,   -20,   -20,   145,
     146,   147,   148,   149,     0,     0,   150,   151,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,    72,
       0,    73,     0,     0,    74,    75,    76,     0,    77,    78,
      79,    80,    81,    82,    83,   117,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     0,    91,
       0,     0,     0,     0,    92,     0,     0,    62,   133,    72,
       0,    73,     0,     0,    74,    75,    76,     0,    77,    78,
      79,    80,    81,    82,    83,   117,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     0,    91,
       0,     0,     0,     0,    92,     0,     0,    62,   169,    72,
       0,    73,     0,     0,    74,    75,    76,     0,    77,    78,
      79,    80,    81,    82,    83,   117,    85,    86,    87,    88,
      89,     0,     0,     0,    72,    90,    73,     0,     0,    91,
       0,     0,     0,     0,    92,    79,    80,    62,    82,    83,
     117,    85,    86,    87,    88,     0,     0,     0,     0,     0,
      90,    72,     0,    73,    91,     0,     0,     0,     0,    92,
     208,     0,    79,    80,     0,    82,    83,   117,    85,    86,
      87,    88,     0,     0,     0,     0,     0,    90,    72,     0,
      73,    91,     0,     0,     0,     0,    92,   216,     0,    79,
      80,     0,    82,    83,   117,    85,    86,    87,    88,   118,
      72,     0,    73,     0,    90,     0,     0,     0,    91,     0,
       0,    79,    80,    92,    82,    83,   117,    85,    86,    87,
      88,   156,    72,     0,    73,     0,    90,     0,     0,     0,
      91,     0,     0,    79,    80,    92,    82,    83,   117,    85,
      86,    87,    88,     0,     0,     0,     0,     0,    90,     0,
       0,     0,    91,     0,     0,     0,     0,    92
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-20)))

static const yytype_int16 yycheck[] =
{
       0,    13,    97,     0,    50,     0,    52,    31,    13,    26,
      10,    77,    32,    10,    31,     3,     4,     5,     6,     7,
      47,    32,    13,    13,    90,    91,    92,    32,    20,    32,
      30,    48,    13,    37,    61,    53,    54,   132,    51,    39,
      52,    32,    32,    43,    32,    69,    70,    54,   114,   115,
     116,    32,    69,    70,     0,    17,   122,   123,    20,    32,
     126,    51,    54,   109,    10,    62,    66,    55,    68,   135,
     136,   137,   138,   139,   140,   141,    51,   143,   144,   145,
     146,   147,   148,   149,   150,     3,     4,     5,     6,     7,
     156,    32,    54,    52,   189,    53,    54,   192,    95,     3,
       4,     5,     6,     7,    53,     3,     4,     5,     6,     7,
      48,    49,    32,   208,    32,    52,   211,    43,    44,    45,
     215,   216,    48,    49,    54,   191,   221,    32,    32,    51,
     196,    52,    53,   199,    32,   201,    51,    55,     3,     4,
       5,     6,     7,    51,   210,     3,     4,     5,     6,     7,
      51,    55,   152,    37,    51,    51,    51,    55,    51,     3,
       4,     5,     6,     7,     8,    51,    51,    32,     4,     5,
       6,     7,    38,    52,    32,    19,    52,    51,    32,    52,
      52,     4,     5,     6,     7,    32,    37,    37,    32,    52,
      55,    52,    51,    16,   194,    18,    32,    55,    21,    22,
      23,    53,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    37,    24,    52,    10,    42,
      49,   199,    43,    46,     4,     5,     6,     7,    51,   123,
      -1,    54,    55,    95,    -1,    -1,    16,    -1,    18,    -1,
      -1,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     9,    10,
      11,    12,    42,    14,    15,    -1,    46,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    55,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,    49,    -1,    -1,    -1,
      53,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    49,    -1,    -1,    52,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    49,    -1,    -1,    52,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    49,
      -1,    -1,    52,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    48,    49,    -1,    -1,    52,     9,    10,    11,
      12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    49,    -1,    37,
      52,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    49,     9,    10,    11,    12,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    49,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    49,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,    49,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    49,
       9,    10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,     9,    10,    48,
      49,    39,    40,    41,    42,    43,    44,    45,     9,    10,
      48,    49,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    49,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    49,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    48,    49,    16,
      -1,    18,    -1,    -1,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    55,    16,
      -1,    18,    -1,    -1,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    55,    16,
      -1,    18,    -1,    -1,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    16,    42,    18,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    27,    28,    54,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    16,    -1,    18,    46,    -1,    -1,    -1,    -1,    51,
      52,    -1,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    16,    -1,
      18,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      16,    -1,    18,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    27,    28,    51,    30,    31,    32,    33,    34,    35,
      36,    37,    16,    -1,    18,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    27,    28,    51,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    19,    32,    58,
      59,    60,    61,    63,    64,    65,    68,    72,    32,    32,
      32,     0,    60,    37,    13,    32,    51,    17,    20,    54,
      54,    51,    63,    65,    66,    67,    32,    32,    71,    69,
       3,    55,    65,    73,    74,    66,    32,    52,    53,    20,
      54,    53,    54,    55,    61,    64,    70,    32,    32,    55,
      74,    52,    54,    75,    63,    71,    69,    32,    69,    51,
      51,    75,    16,    18,    21,    22,    23,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      42,    46,    51,    55,    61,    62,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    87,    89,    54,
      55,    55,    66,    66,    51,    51,    51,    32,    37,    89,
      37,    51,    51,    51,    51,    51,    51,    89,    89,    89,
      55,    61,    76,    55,    77,    38,     9,    10,    11,    12,
      14,    15,    37,    39,    40,    41,    42,    43,    44,    45,
      48,    49,    69,    52,    52,    89,    37,    89,    89,    37,
      32,    89,    88,    89,    52,    52,    86,    88,    52,    55,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    32,    55,    37,    37,    52,
      89,    37,    52,    52,    53,    52,    53,    52,    56,    51,
      77,    37,    89,    77,    65,    37,    89,    86,    52,    89,
      37,    24,    52,    52,    77,    52,    52,    89,    77,    77,
      77,    52,    77
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 152 "parser.y"
    {
                        (yylsp[(1) - (1)]);
                        /* pp2: The @1 is needed to convince
                         * yacc to set up yylloc. You can remove
                         * it once you have other uses of @n*/
                        Program *program = new Program((yyvsp[(1) - (1)].declList));
                        // if no errors, advance to next phase
                        if (ReportError::NumErrors() == 0)
                            program->Print(0);
                                     }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 164 "parser.y"
    {((yyval.declList) = (yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl));}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 165 "parser.y"
    {((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl));}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 168 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].varDecl);}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 169 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].decl);}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 170 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].decl);}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 171 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].fnDecl);}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 175 "parser.y"
    {(yyval.varDecl) = (yyvsp[(1) - (2)].varDecl);}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 178 "parser.y"
    {(yyval.varList)->Append((yyvsp[(2) - (2)].varDecl));}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 179 "parser.y"
    {((yyval.varList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].varDecl));}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 182 "parser.y"
    {(yyval.varDecl) = new VarDecl(new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)), (yyvsp[(1) - (2)].type));}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 185 "parser.y"
    {((yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList)))->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 186 "parser.y"
    {((yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), Type::voidType, (yyvsp[(4) - (6)].varList)))->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 189 "parser.y"
    {(yyval.type) = Type::intType;}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 190 "parser.y"
    {(yyval.type) = Type::doubleType;}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 191 "parser.y"
    {(yyval.type) = Type::stringType;}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 192 "parser.y"
    {(yyval.type) = Type::boolType;}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 193 "parser.y"
    {(yyval.type) = new NamedType(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)));}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 194 "parser.y"
    {(yyval.type) = new ArrayType((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].type));}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 197 "parser.y"
    {(yyval.varList) = (yyvsp[(1) - (1)].varList);}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 198 "parser.y"
    {(yyval.varList) = new List<VarDecl*>;}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 201 "parser.y"
    {((yyval.varList) = (yyvsp[(1) - (3)].varList))->Append((yyvsp[(3) - (3)].varDecl));}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 202 "parser.y"
    {((yyval.varList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].varDecl));}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 205 "parser.y"
    {(yyval.decl) = new ClassDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), NULL, new List<NamedType*>, (yyvsp[(4) - (5)].declList));}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 206 "parser.y"
    {(yyval.decl) = new ClassDecl(new Identifier((yylsp[(2) - (7)]), (yyvsp[(2) - (7)].identifier)), new NamedType(new Identifier((yylsp[(4) - (7)]), (yyvsp[(4) - (7)].identifier))), new List<NamedType*>, (yyvsp[(6) - (7)].declList));}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 207 "parser.y"
    {(yyval.decl) = new ClassDecl(new Identifier((yylsp[(2) - (7)]), (yyvsp[(2) - (7)].identifier)), NULL, (yyvsp[(4) - (7)].namedTypeList), (yyvsp[(6) - (7)].declList));}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 208 "parser.y"
    {(yyval.decl) = new ClassDecl(new Identifier((yylsp[(2) - (9)]), (yyvsp[(2) - (9)].identifier)), new NamedType(new Identifier((yylsp[(4) - (9)]), (yyvsp[(4) - (9)].identifier))), (yyvsp[(6) - (9)].namedTypeList), (yyvsp[(8) - (9)].declList));}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 211 "parser.y"
    {((yyval.declList) = (yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl));}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    {(yyval.declList) = new List<Decl*>;}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 215 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].varDecl);}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 216 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].fnDecl);}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 219 "parser.y"
    {((yyval.namedTypeList) = (yyvsp[(1) - (3)].namedTypeList))->Append(new NamedType(new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier))));}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 220 "parser.y"
    {((yyval.namedTypeList) = new List <NamedType*>)->Append(new NamedType(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier))));}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 223 "parser.y"
    {(yyval.decl) = new InterfaceDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), (yyvsp[(4) - (5)].declList));}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 224 "parser.y"
    {(yyval.decl) = new InterfaceDecl(new Identifier((yylsp[(2) - (4)]), (yyvsp[(2) - (4)].identifier)), new List<Decl*>);}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 227 "parser.y"
    {(yyval.declList)->Append((yyvsp[(2) - (2)].fnDecl));}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 228 "parser.y"
    {((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].fnDecl));}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    {(yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList));}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 232 "parser.y"
    {(yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), Type::voidType, (yyvsp[(4) - (6)].varList));}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 235 "parser.y"
    {(yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (4)].varList), (yyvsp[(3) - (4)].stmtList));}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    {(yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (3)].varList), new List<Stmt*>);}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 237 "parser.y"
    {(yyval.stmtBlock) = new StmtBlock(new List<VarDecl*>, (yyvsp[(2) - (3)].stmtList));}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    {(yyval.stmtBlock) = new StmtBlock(new List<VarDecl*>, new List<Stmt*>);}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 241 "parser.y"
    {((yyval.stmtList) = (yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].stmt));}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 242 "parser.y"
    {((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].stmt));}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 245 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 246 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 247 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 248 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 249 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 250 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 251 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmtBlock);}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 252 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 253 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (2)].expr);}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 258 "parser.y"
    {(yyval.stmt) = new IfStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), NULL);}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 259 "parser.y"
    {(yyval.stmt) = new IfStmt((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 262 "parser.y"
    {(yyval.stmt) = new ForStmt(new EmptyExpr(), (yyvsp[(4) - (7)].expr), new EmptyExpr(), (yyvsp[(7) - (7)].stmt));}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 263 "parser.y"
    {(yyval.stmt) = new ForStmt((yyvsp[(3) - (8)].expr), (yyvsp[(5) - (8)].expr), new EmptyExpr(), (yyvsp[(8) - (8)].stmt));}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 264 "parser.y"
    {(yyval.stmt) = new ForStmt(new EmptyExpr(), (yyvsp[(4) - (8)].expr), (yyvsp[(6) - (8)].expr), (yyvsp[(8) - (8)].stmt));}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 265 "parser.y"
    {(yyval.stmt) = new ForStmt((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt));}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 268 "parser.y"
    {(yyval.stmt) = new WhileStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt));}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 271 "parser.y"
    {(yyval.stmt) = new ReturnStmt((yylsp[(1) - (2)]), new EmptyExpr());}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 272 "parser.y"
    {(yyval.stmt) = new ReturnStmt((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].expr));}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 275 "parser.y"
    {(yyval.stmt) = new BreakStmt((yylsp[(1) - (2)]));}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 278 "parser.y"
    {(yyval.stmt) = new PrintStmt((yyvsp[(3) - (5)].exprList));}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 281 "parser.y"
    {(yyval.expr) = new FieldAccess(NULL, new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)));}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 282 "parser.y"
    {(yyval.expr) = new FieldAccess((yyvsp[(1) - (3)].expr), new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier)));}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 283 "parser.y"
    {(yyval.expr) = new ArrayAccess((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 286 "parser.y"
    {(yyval.expr) = new Call((yylsp[(1) - (4)]), NULL, new Identifier((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].identifier)), (yyvsp[(3) - (4)].exprList));}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 287 "parser.y"
    {(yyval.expr) = new Call((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].expr), new Identifier((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].identifier)), (yyvsp[(5) - (6)].exprList));}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 290 "parser.y"
    {(yyval.exprList) = (yyvsp[(1) - (1)].exprList);}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 291 "parser.y"
    {(yyval.exprList) = new List<Expr*>;}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 294 "parser.y"
    {(yyval.expr) = new IntConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].integerConstant));}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 295 "parser.y"
    {(yyval.expr) = new DoubleConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].doubleConstant));}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 296 "parser.y"
    {(yyval.expr) = new BoolConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].boolConstant));}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 297 "parser.y"
    {(yyval.expr) = new StringConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].stringConstant));}
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 298 "parser.y"
    {(yyval.expr) = new NullConstant((yylsp[(1) - (1)]));}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 301 "parser.y"
    {((yyval.exprList) = (yyvsp[(1) - (3)].exprList))->Append((yyvsp[(3) - (3)].expr));}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 302 "parser.y"
    {((yyval.exprList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr));}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 305 "parser.y"
    {(yyval.expr) = new AssignExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "="), (yyvsp[(3) - (3)].expr));}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 306 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 307 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 308 "parser.y"
    {(yyval.expr) = new This((yylsp[(1) - (1)]));}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 309 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 310 "parser.y"
    {(yyval.expr) = (yyvsp[(2) - (3)].expr);}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 311 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "+"), (yyvsp[(3) - (3)].expr));}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 312 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "-"), (yyvsp[(3) - (3)].expr));}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 313 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "*"), (yyvsp[(3) - (3)].expr));}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 314 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "/"), (yyvsp[(3) - (3)].expr));}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 315 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "%"), (yyvsp[(3) - (3)].expr));}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 316 "parser.y"
    {(yyval.expr) = new ArithmeticExpr(new Operator((yylsp[(1) - (2)]), "-"), (yyvsp[(2) - (2)].expr));}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 317 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "<"), (yyvsp[(3) - (3)].expr));}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 318 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "<="), (yyvsp[(3) - (3)].expr));}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 319 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), ">"), (yyvsp[(3) - (3)].expr));}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 320 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), ">="), (yyvsp[(3) - (3)].expr));}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 321 "parser.y"
    {(yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "=="), (yyvsp[(3) - (3)].expr));}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 322 "parser.y"
    {(yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "!="), (yyvsp[(3) - (3)].expr));}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 323 "parser.y"
    {(yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "&&"), (yyvsp[(3) - (3)].expr));}
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 324 "parser.y"
    {(yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "||"), (yyvsp[(3) - (3)].expr));}
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 325 "parser.y"
    {(yyval.expr) = new LogicalExpr(new Operator((yylsp[(1) - (2)]), "!"), (yyvsp[(2) - (2)].expr));}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 326 "parser.y"
    {(yyval.expr) = new ReadIntegerExpr((yylsp[(1) - (3)]));}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 327 "parser.y"
    {(yyval.expr) = new ReadLineExpr((yylsp[(1) - (3)]));}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 328 "parser.y"
    {(yyval.expr) = new NewExpr((yylsp[(1) - (4)]), new NamedType(new Identifier((yylsp[(3) - (4)]), (yyvsp[(3) - (4)].identifier))));}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 329 "parser.y"
    {(yyval.expr) = new NewArrayExpr((yylsp[(1) - (6)]), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].type));}
    break;


/* Line 1787 of yacc.c  */
#line 2549 "y.tab.c"
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


/* Line 2050 of yacc.c  */
#line 333 "parser.y"


/*---------------------------------------*/
/*-----------ADDITIONAL C CODE-----------*/
/*---------------------------------------*/

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}
