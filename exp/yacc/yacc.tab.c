/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);


#line 82 "yacc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIN = 3,                       /* MAIN  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_BREAK = 6,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 7,                   /* CONTINUE  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_GETINT = 12,                    /* GETINT  */
  YYSYMBOL_PRINTF = 13,                    /* PRINTF  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_IDENT = 15,                     /* IDENT  */
  YYSYMBOL_INT_CONST = 16,                 /* INT_CONST  */
  YYSYMBOL_STR_CONST = 17,                 /* STR_CONST  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_TIMES = 20,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 21,                    /* DIVIDE  */
  YYSYMBOL_LSS = 22,                       /* LSS  */
  YYSYMBOL_LEQ = 23,                       /* LEQ  */
  YYSYMBOL_GRE = 24,                       /* GRE  */
  YYSYMBOL_GEQ = 25,                       /* GEQ  */
  YYSYMBOL_EQL = 26,                       /* EQL  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_30_ = 30,                       /* '%'  */
  YYSYMBOL_31_ = 31,                       /* '!'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_Decl = 43,                      /* Decl  */
  YYSYMBOL_ConstDecl = 44,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 45,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 46,                  /* ConstDef  */
  YYSYMBOL_ArrayDims = 47,                 /* ArrayDims  */
  YYSYMBOL_ConstInitVal = 48,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 49,          /* ConstInitValList  */
  YYSYMBOL_ConstExp = 50,                  /* ConstExp  */
  YYSYMBOL_BType = 51,                     /* BType  */
  YYSYMBOL_VarDecl = 52,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 53,                /* VarDefList  */
  YYSYMBOL_VarDef = 54,                    /* VarDef  */
  YYSYMBOL_InitVal = 55,                   /* InitVal  */
  YYSYMBOL_InitValList = 56,               /* InitValList  */
  YYSYMBOL_FuncDef = 57,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 58,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 59,                /* FuncFParam  */
  YYSYMBOL_MainFuncDef = 60,               /* MainFuncDef  */
  YYSYMBOL_Block = 61,                     /* Block  */
  YYSYMBOL_BlockItems = 62,                /* BlockItems  */
  YYSYMBOL_BlockItem = 63,                 /* BlockItem  */
  YYSYMBOL_Stmt = 64,                      /* Stmt  */
  YYSYMBOL_PrintfItems = 65,               /* PrintfItems  */
  YYSYMBOL_Exp = 66,                       /* Exp  */
  YYSYMBOL_Cond = 67,                      /* Cond  */
  YYSYMBOL_LVal = 68,                      /* LVal  */
  YYSYMBOL_LValArrayIndices = 69,          /* LValArrayIndices  */
  YYSYMBOL_PrimaryExp = 70,                /* PrimaryExp  */
  YYSYMBOL_Number = 71,                    /* Number  */
  YYSYMBOL_UnaryExp = 72,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 73,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 74,               /* FuncRParams  */
  YYSYMBOL_MulExp = 75,                    /* MulExp  */
  YYSYMBOL_AddExp = 76,                    /* AddExp  */
  YYSYMBOL_RelExp = 77,                    /* RelExp  */
  YYSYMBOL_EqExp = 78,                     /* EqExp  */
  YYSYMBOL_LAndExp = 79,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 80                     /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,    30,     2,     2,
      32,    33,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    33,    35,    37,    39,    45,    47,    54,
      56,    62,    64,    71,    73,    79,    81,    88,    90,    92,
      98,   100,   107,   114,   115,   120,   122,   128,   130,   137,
     139,   141,   143,   150,   152,   154,   160,   162,   169,   171,
     178,   180,   187,   189,   191,   198,   205,   207,   213,   215,
     222,   224,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   266,   268,   275,   282,   289,
     291,   297,   299,   306,   308,   310,   317,   324,   326,   328,
     330,   337,   339,   341,   348,   350,   357,   359,   361,   363,
     370,   372,   374,   381,   383,   385,   387,   389,   396,   398,
     400,   407,   409,   416,   418
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAIN", "CONST", "INT",
  "BREAK", "CONTINUE", "IF", "ELSE", "VOID", "WHILE", "GETINT", "PRINTF",
  "RETURN", "IDENT", "INT_CONST", "STR_CONST", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "LSS", "LEQ", "GRE", "GEQ", "EQL", "NEQ", "AND", "OR", "'%'",
  "'!'", "'('", "')'", "'['", "']'", "';'", "','", "'='", "'{'", "'}'",
  "$accept", "CompUnit", "Decl", "ConstDecl", "ConstDefList", "ConstDef",
  "ArrayDims", "ConstInitVal", "ConstInitValList", "ConstExp", "BType",
  "VarDecl", "VarDefList", "VarDef", "InitVal", "InitValList", "FuncDef",
  "FuncFParams", "FuncFParam", "MainFuncDef", "Block", "BlockItems",
  "BlockItem", "Stmt", "PrintfItems", "Exp", "Cond", "LVal",
  "LValArrayIndices", "PrimaryExp", "Number", "UnaryExp", "UnaryOp",
  "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,    21,     8,  -150,    32,    53,     7,    20,    23,    53,
    -150,  -150,    38,    47,  -150,  -150,  -150,  -150,   -19,    50,
    -150,  -150,  -150,    -4,    57,    72,    17,   234,    36,    65,
      92,   196,    73,    38,    74,    74,   102,    85,    82,    48,
    -150,  -150,  -150,  -150,   234,    86,  -150,  -150,  -150,  -150,
     234,     3,    -1,   165,  -150,  -150,    -1,    36,    26,  -150,
      87,   170,  -150,  -150,   196,  -150,    88,   122,  -150,  -150,
      89,    74,    21,   229,   234,  -150,    98,   100,  -150,   234,
     234,   234,   234,   234,  -150,   105,    99,  -150,    92,  -150,
     107,   115,  -150,    38,   120,   121,   127,   128,   136,   201,
    -150,  -150,  -150,    92,  -150,   131,   159,  -150,   140,   141,
     147,  -150,  -150,  -150,   150,   160,   157,  -150,  -150,  -150,
    -150,  -150,     3,     3,    36,  -150,  -150,   196,  -150,  -150,
    -150,  -150,   234,   234,   177,  -150,   163,  -150,  -150,  -150,
     224,   100,   234,  -150,   166,  -150,  -150,   173,    -1,    68,
      46,   175,   178,   180,   171,  -150,   186,   185,  -150,  -150,
    -150,    70,   234,   234,   234,   234,   234,   234,   234,   234,
      70,   234,   189,   190,  -150,   215,    -1,    -1,    -1,    -1,
      68,    68,    46,   175,  -150,   171,   193,   194,    70,  -150,
    -150,  -150,  -150
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    23,    24,     0,     0,     0,     0,     0,     0,
       4,    23,     0,     0,     1,     5,     2,     7,    29,    25,
       8,     6,     3,     0,     9,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    69,
      76,    81,    82,    83,     0,     0,    74,    77,    75,    86,
       0,    90,    22,     0,    31,    33,    67,     0,    29,    26,
      27,     0,    13,    17,     0,    10,    11,     0,    45,    38,
      42,     0,     0,     0,     0,    70,     0,    15,    80,     0,
       0,     0,     0,     0,    34,    36,     0,    32,     0,    18,
      20,     0,    14,     0,     0,     0,     0,     0,     0,     0,
      53,    46,    50,     0,    55,     0,    48,    51,     0,    74,
       0,    39,    41,    78,    84,     0,     0,    73,    16,    87,
      88,    89,    91,    92,     0,    35,    28,     0,    19,    12,
      59,    60,     0,     0,     0,    61,     0,    47,    49,    54,
       0,    43,     0,    79,    71,    37,    21,     0,    93,    98,
     101,   103,    68,     0,    65,    62,     0,     0,    44,    85,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    56,    94,    96,    95,    97,
      99,   100,   102,   104,    58,    65,     0,     0,     0,    66,
      64,    63,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,    56,   -58,  -150,   132,   214,   -21,   -23,   104,   207,
       2,  -150,   153,   -26,    -8,   114,  -150,   174,  -150,    61,
     -29,   145,  -150,  -149,    69,   -28,   124,   -66,   119,  -150,
    -150,   -43,  -150,   116,    15,   -17,   -67,    91,    95,  -150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    65,    66,    29,    90,    91,    63,
       7,     8,    59,    19,    85,    86,     9,    37,    38,    10,
     104,   105,   106,   107,   172,   108,   147,    46,    75,    47,
      48,    49,    50,   115,    51,    56,   149,   150,   151,   152
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,   109,    32,    12,    60,    68,    69,    78,    62,   102,
      52,    13,   175,    26,    52,    27,    76,    82,    83,    28,
      54,   184,    11,    79,    80,    55,    11,     3,    36,    55,
      27,     3,    14,    81,    31,    18,   119,   120,   121,   192,
     109,    92,   111,    17,    52,   114,   116,    52,   102,    87,
      35,    39,    40,    23,    41,    42,   118,     1,     2,    20,
      27,    15,    60,     3,    28,    21,    16,    43,    44,   103,
      22,   136,   166,   167,    36,    53,    94,    95,    96,    25,
      73,    97,    74,    98,    99,    39,    40,    30,    41,    42,
     162,   163,   164,   165,    33,   109,    55,   122,   123,   180,
     181,    43,    44,    57,   109,    34,   100,    58,   103,    67,
      52,    64,   157,    67,   114,   148,   148,    70,    71,    72,
     158,    77,   109,   110,    88,    93,     1,    11,    94,    95,
      96,   117,     3,    97,    27,    98,    99,    39,    40,   125,
      41,    42,   124,   185,   127,   176,   177,   178,   179,   148,
     148,   148,   148,    43,    44,   128,   130,   131,   100,   132,
     133,    67,   101,     1,    11,    94,    95,    96,   134,     3,
      97,   137,    98,    99,    39,    40,   139,    41,    42,   140,
      39,    40,   141,    41,    42,    39,    40,   142,    41,    42,
      43,    44,   144,   143,   154,   100,    43,    44,    67,   155,
      74,    43,    44,   168,    53,    84,   161,   169,   171,    61,
      89,    39,    40,   170,    41,    42,    39,    40,   173,    41,
      42,   174,   186,   187,   188,   129,    24,    43,    44,   190,
     191,   146,    43,    44,    45,    61,   156,   135,   145,    39,
      40,   126,    41,    42,    39,    40,   112,    41,    42,    39,
      40,   138,    41,    42,   189,    43,    44,   153,   159,   182,
      43,    44,   113,   160,   183,    43,    44
};

static const yytype_uint8 yycheck[] =
{
      28,    67,    23,     1,    30,    34,    35,    50,    31,    67,
      27,     3,   161,    32,    31,    34,    44,    18,    19,    38,
      28,   170,     5,    20,    21,    53,     5,    10,    26,    57,
      34,    10,     0,    30,    38,    15,    79,    80,    81,   188,
     106,    64,    71,    36,    61,    73,    74,    64,   106,    57,
      33,    15,    16,    15,    18,    19,    77,     4,     5,    36,
      34,     5,    88,    10,    38,     9,     5,    31,    32,    67,
       9,    99,    26,    27,    72,    39,     6,     7,     8,    32,
      32,    11,    34,    13,    14,    15,    16,    37,    18,    19,
      22,    23,    24,    25,    37,   161,   124,    82,    83,   166,
     167,    31,    32,    38,   170,    33,    36,    15,   106,    39,
     127,    38,   140,    39,   142,   132,   133,    15,    33,    37,
     141,    35,   188,    34,    37,    37,     4,     5,     6,     7,
       8,    33,    10,    11,    34,    13,    14,    15,    16,    40,
      18,    19,    37,   171,    37,   162,   163,   164,   165,   166,
     167,   168,   169,    31,    32,    40,    36,    36,    36,    32,
      32,    39,    40,     4,     5,     6,     7,     8,    32,    10,
      11,    40,    13,    14,    15,    16,    36,    18,    19,    38,
      15,    16,    35,    18,    19,    15,    16,    37,    18,    19,
      31,    32,    35,    33,    17,    36,    31,    32,    39,    36,
      34,    31,    32,    28,    39,    40,    33,    29,    37,    39,
      40,    15,    16,    33,    18,    19,    15,    16,    32,    18,
      19,    36,    33,    33,     9,    93,    12,    31,    32,    36,
      36,   127,    31,    32,    27,    39,    12,    36,   124,    15,
      16,    88,    18,    19,    15,    16,    72,    18,    19,    15,
      16,   106,    18,    19,   185,    31,    32,   133,   142,   168,
      31,    32,    33,   144,   169,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    10,    42,    43,    44,    51,    52,    57,
      60,     5,    51,     3,     0,    42,    60,    36,    15,    54,
      36,    42,    60,    15,    46,    32,    32,    34,    38,    47,
      37,    38,    47,    37,    33,    33,    51,    58,    59,    15,
      16,    18,    19,    31,    32,    50,    68,    70,    71,    72,
      73,    75,    76,    39,    55,    66,    76,    38,    15,    53,
      54,    39,    48,    50,    38,    45,    46,    39,    61,    61,
      15,    33,    37,    32,    34,    69,    66,    35,    72,    20,
      21,    30,    18,    19,    40,    55,    56,    55,    37,    40,
      48,    49,    48,    37,     6,     7,     8,    11,    13,    14,
      36,    40,    43,    51,    61,    62,    63,    64,    66,    68,
      34,    61,    58,    33,    66,    74,    66,    33,    47,    72,
      72,    72,    75,    75,    37,    40,    53,    37,    40,    45,
      36,    36,    32,    32,    32,    36,    66,    40,    62,    36,
      38,    35,    37,    33,    35,    56,    49,    67,    76,    77,
      78,    79,    80,    67,    17,    36,    12,    66,    47,    74,
      69,    33,    22,    23,    24,    25,    26,    27,    28,    29,
      33,    37,    65,    32,    36,    64,    76,    76,    76,    76,
      77,    77,    78,    79,    64,    66,    33,    33,     9,    65,
      36,    36,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    70,    70,    70,    71,    72,    72,    72,
      72,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       5,     1,     3,     3,     4,     3,     4,     1,     2,     3,
       1,     3,     1,     1,     1,     2,     4,     1,     3,     1,
       2,     3,     4,     1,     2,     3,     1,     3,     5,     6,
       1,     3,     2,     4,     5,     5,     2,     3,     1,     2,
       1,     1,     4,     1,     2,     1,     5,     7,     5,     2,
       2,     2,     3,     6,     6,     0,     3,     1,     1,     1,
       2,     3,     4,     3,     1,     1,     1,     1,     3,     4,
       2,     1,     1,     1,     1,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* CompUnit: Decl MainFuncDef  */
#line 31 "yacc.y"
                       {
        printf("<CompUnit>\n");
    }
#line 1296 "yacc.tab.c"
    break;

  case 3: /* CompUnit: FuncDef MainFuncDef  */
#line 33 "yacc.y"
                            {
        printf("<CompUnit>\n");
    }
#line 1304 "yacc.tab.c"
    break;

  case 4: /* CompUnit: MainFuncDef  */
#line 35 "yacc.y"
                    {
        printf("<CompUnit>\n");
    }
#line 1312 "yacc.tab.c"
    break;

  case 5: /* CompUnit: Decl CompUnit  */
#line 37 "yacc.y"
                      {

    }
#line 1320 "yacc.tab.c"
    break;

  case 6: /* CompUnit: FuncDef CompUnit  */
#line 39 "yacc.y"
                         {

    }
#line 1328 "yacc.tab.c"
    break;

  case 7: /* Decl: ConstDecl ';'  */
#line 45 "yacc.y"
                  {
        
    }
#line 1336 "yacc.tab.c"
    break;

  case 8: /* Decl: VarDecl ';'  */
#line 47 "yacc.y"
                    {
        
    }
#line 1344 "yacc.tab.c"
    break;

  case 9: /* ConstDecl: CONST BType ConstDef  */
#line 54 "yacc.y"
                         {
        printf("<ConstDecl>\n");
    }
#line 1352 "yacc.tab.c"
    break;

  case 10: /* ConstDecl: CONST BType ConstDef ',' ConstDefList  */
#line 56 "yacc.y"
                                              {
        printf("<ConstDecl>\n");
    }
#line 1360 "yacc.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 62 "yacc.y"
             {
        
    }
#line 1368 "yacc.tab.c"
    break;

  case 12: /* ConstDefList: ConstDef ',' ConstDefList  */
#line 64 "yacc.y"
                                  {
        
    }
#line 1376 "yacc.tab.c"
    break;

  case 13: /* ConstDef: IDENT '=' ConstInitVal  */
#line 71 "yacc.y"
                           {
        
    }
#line 1384 "yacc.tab.c"
    break;

  case 14: /* ConstDef: IDENT ArrayDims '=' ConstInitVal  */
#line 73 "yacc.y"
                                         {
        
    }
#line 1392 "yacc.tab.c"
    break;

  case 15: /* ArrayDims: '[' ConstExp ']'  */
#line 79 "yacc.y"
                     {
        
    }
#line 1400 "yacc.tab.c"
    break;

  case 16: /* ArrayDims: '[' ConstExp ']' ArrayDims  */
#line 81 "yacc.y"
                                   {
        
    }
#line 1408 "yacc.tab.c"
    break;

  case 17: /* ConstInitVal: ConstExp  */
#line 88 "yacc.y"
             {
        
    }
#line 1416 "yacc.tab.c"
    break;

  case 18: /* ConstInitVal: '{' '}'  */
#line 90 "yacc.y"
                {
        
    }
#line 1424 "yacc.tab.c"
    break;

  case 19: /* ConstInitVal: '{' ConstInitValList '}'  */
#line 92 "yacc.y"
                                 {
        
    }
#line 1432 "yacc.tab.c"
    break;

  case 20: /* ConstInitValList: ConstInitVal  */
#line 98 "yacc.y"
                 {
        
    }
#line 1440 "yacc.tab.c"
    break;

  case 21: /* ConstInitValList: ConstInitVal ',' ConstInitValList  */
#line 100 "yacc.y"
                                          {
        
    }
#line 1448 "yacc.tab.c"
    break;

  case 22: /* ConstExp: AddExp  */
#line 107 "yacc.y"
           {
        
    }
#line 1456 "yacc.tab.c"
    break;

  case 23: /* BType: INT  */
#line 114 "yacc.y"
        { }
#line 1462 "yacc.tab.c"
    break;

  case 24: /* BType: VOID  */
#line 115 "yacc.y"
         { }
#line 1468 "yacc.tab.c"
    break;

  case 25: /* VarDecl: BType VarDef  */
#line 120 "yacc.y"
                 {
        printf("<VarDecl>\n");
    }
#line 1476 "yacc.tab.c"
    break;

  case 26: /* VarDecl: BType VarDef ',' VarDefList  */
#line 122 "yacc.y"
                                    {
        printf("<VarDecl>\n");
    }
#line 1484 "yacc.tab.c"
    break;

  case 27: /* VarDefList: VarDef  */
#line 128 "yacc.y"
           {
        
    }
#line 1492 "yacc.tab.c"
    break;

  case 28: /* VarDefList: VarDef ',' VarDefList  */
#line 130 "yacc.y"
                              {
        
    }
#line 1500 "yacc.tab.c"
    break;

  case 29: /* VarDef: IDENT  */
#line 137 "yacc.y"
          {
        
    }
#line 1508 "yacc.tab.c"
    break;

  case 30: /* VarDef: IDENT ArrayDims  */
#line 139 "yacc.y"
                        {
        
    }
#line 1516 "yacc.tab.c"
    break;

  case 31: /* VarDef: IDENT '=' InitVal  */
#line 141 "yacc.y"
                          {
        
    }
#line 1524 "yacc.tab.c"
    break;

  case 32: /* VarDef: IDENT ArrayDims '=' InitVal  */
#line 143 "yacc.y"
                                    {
        
    }
#line 1532 "yacc.tab.c"
    break;

  case 33: /* InitVal: Exp  */
#line 150 "yacc.y"
        {
        
    }
#line 1540 "yacc.tab.c"
    break;

  case 34: /* InitVal: '{' '}'  */
#line 152 "yacc.y"
                {
        
    }
#line 1548 "yacc.tab.c"
    break;

  case 35: /* InitVal: '{' InitValList '}'  */
#line 154 "yacc.y"
                            {
        
    }
#line 1556 "yacc.tab.c"
    break;

  case 36: /* InitValList: InitVal  */
#line 160 "yacc.y"
            {
        
    }
#line 1564 "yacc.tab.c"
    break;

  case 37: /* InitValList: InitVal ',' InitValList  */
#line 162 "yacc.y"
                                {
        
    }
#line 1572 "yacc.tab.c"
    break;

  case 38: /* FuncDef: BType IDENT '(' ')' Block  */
#line 169 "yacc.y"
                              {
        printf("<FuncDef>\n");
    }
#line 1580 "yacc.tab.c"
    break;

  case 39: /* FuncDef: BType IDENT '(' FuncFParams ')' Block  */
#line 171 "yacc.y"
                                              {
        printf("<FuncDef>\n");
    }
#line 1588 "yacc.tab.c"
    break;

  case 40: /* FuncFParams: FuncFParam  */
#line 178 "yacc.y"
               {
        
    }
#line 1596 "yacc.tab.c"
    break;

  case 41: /* FuncFParams: FuncFParam ',' FuncFParams  */
#line 180 "yacc.y"
                                   {
        
    }
#line 1604 "yacc.tab.c"
    break;

  case 42: /* FuncFParam: BType IDENT  */
#line 187 "yacc.y"
                {
        
    }
#line 1612 "yacc.tab.c"
    break;

  case 43: /* FuncFParam: BType IDENT '[' ']'  */
#line 189 "yacc.y"
                            {
        
    }
#line 1620 "yacc.tab.c"
    break;

  case 44: /* FuncFParam: BType IDENT '[' ']' ArrayDims  */
#line 191 "yacc.y"
                                      {
        
    }
#line 1628 "yacc.tab.c"
    break;

  case 45: /* MainFuncDef: INT MAIN '(' ')' Block  */
#line 198 "yacc.y"
                           {
        printf("<MainFuncDef>\n");
    }
#line 1636 "yacc.tab.c"
    break;

  case 46: /* Block: '{' '}'  */
#line 205 "yacc.y"
            {
        printf("<Block>\n");
    }
#line 1644 "yacc.tab.c"
    break;

  case 47: /* Block: '{' BlockItems '}'  */
#line 207 "yacc.y"
                           {
        printf("<Block>\n");
    }
#line 1652 "yacc.tab.c"
    break;

  case 48: /* BlockItems: BlockItem  */
#line 213 "yacc.y"
              {
        
    }
#line 1660 "yacc.tab.c"
    break;

  case 49: /* BlockItems: BlockItem BlockItems  */
#line 215 "yacc.y"
                             {
        
    }
#line 1668 "yacc.tab.c"
    break;

  case 50: /* BlockItem: Decl  */
#line 222 "yacc.y"
         {
        
    }
#line 1676 "yacc.tab.c"
    break;

  case 51: /* BlockItem: Stmt  */
#line 224 "yacc.y"
             {
        
    }
#line 1684 "yacc.tab.c"
    break;

  case 52: /* Stmt: LVal '=' Exp ';'  */
#line 236 "yacc.y"
                     {
        printf("<Stmt>\n");
    }
#line 1692 "yacc.tab.c"
    break;

  case 53: /* Stmt: ';'  */
#line 238 "yacc.y"
            {
        printf("<Stmt>\n");
    }
#line 1700 "yacc.tab.c"
    break;

  case 54: /* Stmt: Exp ';'  */
#line 240 "yacc.y"
                {
        printf("<Stmt>\n");
    }
#line 1708 "yacc.tab.c"
    break;

  case 55: /* Stmt: Block  */
#line 242 "yacc.y"
              {
        printf("<Stmt>\n");
    }
#line 1716 "yacc.tab.c"
    break;

  case 56: /* Stmt: IF '(' Cond ')' Stmt  */
#line 244 "yacc.y"
                             {
        printf("<Stmt>\n");
    }
#line 1724 "yacc.tab.c"
    break;

  case 57: /* Stmt: IF '(' Cond ')' Stmt ELSE Stmt  */
#line 246 "yacc.y"
                                       {
        printf("<Stmt>\n");
    }
#line 1732 "yacc.tab.c"
    break;

  case 58: /* Stmt: WHILE '(' Cond ')' Stmt  */
#line 248 "yacc.y"
                                {
        printf("<Stmt>\n");
    }
#line 1740 "yacc.tab.c"
    break;

  case 59: /* Stmt: BREAK ';'  */
#line 250 "yacc.y"
                  {
        printf("<Stmt>\n");
    }
#line 1748 "yacc.tab.c"
    break;

  case 60: /* Stmt: CONTINUE ';'  */
#line 252 "yacc.y"
                     {
        printf("<Stmt>\n");
    }
#line 1756 "yacc.tab.c"
    break;

  case 61: /* Stmt: RETURN ';'  */
#line 254 "yacc.y"
                   {
        printf("<Stmt>\n");
    }
#line 1764 "yacc.tab.c"
    break;

  case 62: /* Stmt: RETURN Exp ';'  */
#line 256 "yacc.y"
                       {
        printf("<Stmt>\n");
    }
#line 1772 "yacc.tab.c"
    break;

  case 63: /* Stmt: LVal '=' GETINT '(' ')' ';'  */
#line 258 "yacc.y"
                                    {
        printf("<Stmt>\n");
    }
#line 1780 "yacc.tab.c"
    break;

  case 64: /* Stmt: PRINTF '(' STR_CONST PrintfItems ')' ';'  */
#line 260 "yacc.y"
                                                 {
        printf("<Stmt>\n");
    }
#line 1788 "yacc.tab.c"
    break;

  case 65: /* PrintfItems: %empty  */
#line 266 "yacc.y"
                {
        
    }
#line 1796 "yacc.tab.c"
    break;

  case 66: /* PrintfItems: ',' Exp PrintfItems  */
#line 268 "yacc.y"
                            {
        
    }
#line 1804 "yacc.tab.c"
    break;

  case 67: /* Exp: AddExp  */
#line 275 "yacc.y"
           {
        
    }
#line 1812 "yacc.tab.c"
    break;

  case 68: /* Cond: LOrExp  */
#line 282 "yacc.y"
           {
        
    }
#line 1820 "yacc.tab.c"
    break;

  case 69: /* LVal: IDENT  */
#line 289 "yacc.y"
          {
        
    }
#line 1828 "yacc.tab.c"
    break;

  case 70: /* LVal: IDENT LValArrayIndices  */
#line 291 "yacc.y"
                               {
        
    }
#line 1836 "yacc.tab.c"
    break;

  case 71: /* LValArrayIndices: '[' Exp ']'  */
#line 297 "yacc.y"
                {
        
    }
#line 1844 "yacc.tab.c"
    break;

  case 72: /* LValArrayIndices: '[' Exp ']' LValArrayIndices  */
#line 299 "yacc.y"
                                     {
        
    }
#line 1852 "yacc.tab.c"
    break;

  case 73: /* PrimaryExp: '(' Exp ')'  */
#line 306 "yacc.y"
                {
        
    }
#line 1860 "yacc.tab.c"
    break;

  case 74: /* PrimaryExp: LVal  */
#line 308 "yacc.y"
             {
        
    }
#line 1868 "yacc.tab.c"
    break;

  case 75: /* PrimaryExp: Number  */
#line 310 "yacc.y"
               {
        
    }
#line 1876 "yacc.tab.c"
    break;

  case 76: /* Number: INT_CONST  */
#line 317 "yacc.y"
              {
        
    }
#line 1884 "yacc.tab.c"
    break;

  case 77: /* UnaryExp: PrimaryExp  */
#line 324 "yacc.y"
               {
        
    }
#line 1892 "yacc.tab.c"
    break;

  case 78: /* UnaryExp: IDENT '(' ')'  */
#line 326 "yacc.y"
                      {
        
    }
#line 1900 "yacc.tab.c"
    break;

  case 79: /* UnaryExp: IDENT '(' FuncRParams ')'  */
#line 328 "yacc.y"
                                  {
        
    }
#line 1908 "yacc.tab.c"
    break;

  case 80: /* UnaryExp: UnaryOp UnaryExp  */
#line 330 "yacc.y"
                         {
        
    }
#line 1916 "yacc.tab.c"
    break;

  case 81: /* UnaryOp: PLUS  */
#line 337 "yacc.y"
         {
        
    }
#line 1924 "yacc.tab.c"
    break;

  case 82: /* UnaryOp: MINUS  */
#line 339 "yacc.y"
              {
        
    }
#line 1932 "yacc.tab.c"
    break;

  case 83: /* UnaryOp: '!'  */
#line 341 "yacc.y"
            {
        
    }
#line 1940 "yacc.tab.c"
    break;

  case 84: /* FuncRParams: Exp  */
#line 348 "yacc.y"
        {
        
    }
#line 1948 "yacc.tab.c"
    break;

  case 85: /* FuncRParams: Exp ',' FuncRParams  */
#line 350 "yacc.y"
                            {
        
    }
#line 1956 "yacc.tab.c"
    break;

  case 86: /* MulExp: UnaryExp  */
#line 357 "yacc.y"
             {
        
    }
#line 1964 "yacc.tab.c"
    break;

  case 87: /* MulExp: MulExp TIMES UnaryExp  */
#line 359 "yacc.y"
                              {
        
    }
#line 1972 "yacc.tab.c"
    break;

  case 88: /* MulExp: MulExp DIVIDE UnaryExp  */
#line 361 "yacc.y"
                               {
        
    }
#line 1980 "yacc.tab.c"
    break;

  case 89: /* MulExp: MulExp '%' UnaryExp  */
#line 363 "yacc.y"
                            {
        
    }
#line 1988 "yacc.tab.c"
    break;

  case 90: /* AddExp: MulExp  */
#line 370 "yacc.y"
           {
        
    }
#line 1996 "yacc.tab.c"
    break;

  case 91: /* AddExp: AddExp PLUS MulExp  */
#line 372 "yacc.y"
                           {
        
    }
#line 2004 "yacc.tab.c"
    break;

  case 92: /* AddExp: AddExp MINUS MulExp  */
#line 374 "yacc.y"
                            {
        
    }
#line 2012 "yacc.tab.c"
    break;

  case 93: /* RelExp: AddExp  */
#line 381 "yacc.y"
           {
        
    }
#line 2020 "yacc.tab.c"
    break;

  case 94: /* RelExp: RelExp LSS AddExp  */
#line 383 "yacc.y"
                          {
        
    }
#line 2028 "yacc.tab.c"
    break;

  case 95: /* RelExp: RelExp GRE AddExp  */
#line 385 "yacc.y"
                          {
        
    }
#line 2036 "yacc.tab.c"
    break;

  case 96: /* RelExp: RelExp LEQ AddExp  */
#line 387 "yacc.y"
                          {
        
    }
#line 2044 "yacc.tab.c"
    break;

  case 97: /* RelExp: RelExp GEQ AddExp  */
#line 389 "yacc.y"
                          {
        
    }
#line 2052 "yacc.tab.c"
    break;

  case 98: /* EqExp: RelExp  */
#line 396 "yacc.y"
           {
        
    }
#line 2060 "yacc.tab.c"
    break;

  case 99: /* EqExp: EqExp EQL RelExp  */
#line 398 "yacc.y"
                         {
        
    }
#line 2068 "yacc.tab.c"
    break;

  case 100: /* EqExp: EqExp NEQ RelExp  */
#line 400 "yacc.y"
                         {
        
    }
#line 2076 "yacc.tab.c"
    break;

  case 101: /* LAndExp: EqExp  */
#line 407 "yacc.y"
          {
        
    }
#line 2084 "yacc.tab.c"
    break;

  case 102: /* LAndExp: LAndExp AND EqExp  */
#line 409 "yacc.y"
                          {
        
    }
#line 2092 "yacc.tab.c"
    break;

  case 103: /* LOrExp: LAndExp  */
#line 416 "yacc.y"
            {
        
    }
#line 2100 "yacc.tab.c"
    break;

  case 104: /* LOrExp: LOrExp OR LAndExp  */
#line 418 "yacc.y"
                          {
        
    }
#line 2108 "yacc.tab.c"
    break;


#line 2112 "yacc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 423 "yacc.y"
 

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

extern FILE *yyin;

int main(int argc, char *argv[]) {
    // 如果没有提供命令行参数，使用标准输入
    if (argc <= 1) {
        yyin = stdin;
    } else {
        // 如果提供了文件名，尝试打开该文件
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "无法打开文件 '%s'\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    yydebug = 0;  // 调试模式：1为启用，0为关闭
    int result = yyparse();
    
    // 如果打开了文件，记得关闭
    if (argc > 1 && yyin != stdin) {
        fclose(yyin);
    }
    
    return result;
}
