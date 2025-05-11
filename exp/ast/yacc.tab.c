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

#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include "ast.h"

// 声明全局根变量
std::unique_ptr<BaseAST> root;

int yylex();
void yyerror(const char *s);
extern char* yytext;


#line 89 "yacc.tab.c"

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
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_TIMES = 17,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 18,                    /* DIVIDE  */
  YYSYMBOL_LSS = 19,                       /* LSS  */
  YYSYMBOL_LEQ = 20,                       /* LEQ  */
  YYSYMBOL_GRE = 21,                       /* GRE  */
  YYSYMBOL_GEQ = 22,                       /* GEQ  */
  YYSYMBOL_EQL = 23,                       /* EQL  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_IDENT = 27,                     /* IDENT  */
  YYSYMBOL_STR_CONST = 28,                 /* STR_CONST  */
  YYSYMBOL_INT_CONST = 29,                 /* INT_CONST  */
  YYSYMBOL_30_ = 30,                       /* '%'  */
  YYSYMBOL_31_ = 31,                       /* '!'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_Decl = 43,                      /* Decl  */
  YYSYMBOL_ConstDecl = 44,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 45,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 46,                  /* ConstDef  */
  YYSYMBOL_BType = 47,                     /* BType  */
  YYSYMBOL_VarDecl = 48,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 49,                /* VarDefList  */
  YYSYMBOL_VarDef = 50,                    /* VarDef  */
  YYSYMBOL_InitVal = 51,                   /* InitVal  */
  YYSYMBOL_InitValList = 52,               /* InitValList  */
  YYSYMBOL_MainFuncDef = 53,               /* MainFuncDef  */
  YYSYMBOL_Block = 54,                     /* Block  */
  YYSYMBOL_BlockItems = 55,                /* BlockItems  */
  YYSYMBOL_BlockItem = 56,                 /* BlockItem  */
  YYSYMBOL_Stmt = 57,                      /* Stmt  */
  YYSYMBOL_Assignment = 58,                /* Assignment  */
  YYSYMBOL_Number = 59,                    /* Number  */
  YYSYMBOL_ArrayDims = 60,                 /* ArrayDims  */
  YYSYMBOL_ConstInitVal = 61,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 62,          /* ConstInitValList  */
  YYSYMBOL_ConstExp = 63,                  /* ConstExp  */
  YYSYMBOL_FuncDef = 64,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 65,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 66,                /* FuncFParam  */
  YYSYMBOL_PrintfItems = 67,               /* PrintfItems  */
  YYSYMBOL_Exp = 68,                       /* Exp  */
  YYSYMBOL_Cond = 69,                      /* Cond  */
  YYSYMBOL_LVal = 70,                      /* LVal  */
  YYSYMBOL_LValArrayIndices = 71,          /* LValArrayIndices  */
  YYSYMBOL_PrimaryExp = 72,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 73,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 74,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 75,               /* FuncRParams  */
  YYSYMBOL_MulExp = 76,                    /* MulExp  */
  YYSYMBOL_AddExp = 77,                    /* AddExp  */
  YYSYMBOL_RelExp = 78,                    /* RelExp  */
  YYSYMBOL_EqExp = 79,                     /* EqExp  */
  YYSYMBOL_LAndExp = 80,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 81                     /* LOrExp  */
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
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

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
      32,    33,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,    66,    66,    78,    90,    96,   104,   117,   122,   132,
     149,   156,   178,   182,   194,   203,   218,   221,   228,   237,
     254,   259,   279,   283,   295,   304,   314,   324,   340,   345,
     350,   359,   363,   374,   382,   384,   391,   397,   407,   409,
     415,   421,   437,   443,   453,   464,   469,   475,   482,   490,
     497,   502,   507,   512,   518,   524,   546,   558,   566,   570,
     582,   587,   592,   601,   605,   617,   626,   636,   652,   656,
     668,   678,   688,   703,   706,   720,   729,   738,   746,   759,
     763,   775,   780,   785,   795,   800,   809,   819,   830,   834,
     838,   847,   851,   863,   868,   874,   880,   891,   896,   902,
     913,   918,   924,   930,   936,   947,   952,   958,   969,   974,
     985,   990
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
  "RETURN", "PLUS", "MINUS", "TIMES", "DIVIDE", "LSS", "LEQ", "GRE", "GEQ",
  "EQL", "NEQ", "AND", "OR", "IDENT", "STR_CONST", "INT_CONST", "'%'",
  "'!'", "'('", "')'", "'['", "']'", "';'", "'='", "','", "'{'", "'}'",
  "$accept", "CompUnit", "Decl", "ConstDecl", "ConstDefList", "ConstDef",
  "BType", "VarDecl", "VarDefList", "VarDef", "InitVal", "InitValList",
  "MainFuncDef", "Block", "BlockItems", "BlockItem", "Stmt", "Assignment",
  "Number", "ArrayDims", "ConstInitVal", "ConstInitValList", "ConstExp",
  "FuncDef", "FuncFParams", "FuncFParam", "PrintfItems", "Exp", "Cond",
  "LVal", "LValArrayIndices", "PrimaryExp", "UnaryExp", "UnaryOp",
  "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-156)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-27)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,    12,    58,  -156,    51,    19,    40,    68,    42,  -156,
      19,  -156,    72,    57,  -156,  -156,  -156,    48,    64,  -156,
    -156,    38,    73,    85,     9,   262,    88,    79,    99,   201,
      91,   110,   100,   100,   111,    97,   105,  -156,  -156,    28,
    -156,  -156,   262,  -156,   112,  -156,  -156,  -156,   262,    -2,
       5,    25,   107,  -156,     5,    88,    53,  -156,   120,    52,
     123,  -156,  -156,   201,    63,  -156,   122,   158,  -156,  -156,
     133,   100,    12,   255,   262,  -156,   137,   141,  -156,   262,
     262,   262,   262,   262,  -156,   139,   138,  -156,    88,    99,
    -156,   143,   142,  -156,   201,   110,   147,   148,   154,   156,
     160,   236,    21,  -156,  -156,  -156,   177,  -156,   195,  -156,
    -156,   171,   176,   178,   179,  -156,  -156,  -156,   175,   185,
     184,  -156,  -156,  -156,  -156,  -156,    -2,    -2,    88,  -156,
    -156,  -156,   201,  -156,  -156,  -156,  -156,   262,   262,   192,
      62,  -156,   187,   117,    -4,  -156,  -156,  -156,  -156,   164,
     141,   262,  -156,   191,  -156,  -156,   188,     5,   103,    13,
     204,   213,   209,   210,  -156,  -156,   215,   214,   217,   218,
    -156,  -156,  -156,   230,   262,   262,   262,   262,   262,   262,
     262,   262,   230,   262,   220,   222,  -156,   223,  -156,   249,
       5,     5,     5,     5,   103,   103,    13,   204,  -156,   210,
     224,  -156,   228,   230,  -156,  -156,  -156,  -156
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    16,    17,     0,     5,     0,     0,     0,     4,
       6,    16,     0,     0,     1,     2,     7,    18,    20,     8,
       3,     0,    10,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    88,    89,    77,
      57,    90,     0,    83,     0,    82,    84,    93,     0,    97,
      65,     0,    19,    28,    75,     0,    24,    21,    22,     0,
      83,    14,    60,     0,     0,    11,    12,     0,    33,    66,
      70,     0,     0,     0,     0,    78,     0,    58,    87,     0,
       0,     0,     0,     0,    29,    31,     0,    27,     0,     0,
      61,    63,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    45,    35,    38,     0,    42,     0,    37,
      39,     0,     0,    82,     0,    67,    69,    85,    91,     0,
       0,    81,    59,    94,    95,    96,    98,    99,     0,    30,
      26,    23,     0,    62,    13,    50,    51,     0,     0,     0,
      77,    52,     0,     0,    18,    34,    36,    40,    46,     0,
      71,     0,    86,    79,    32,    64,     0,   100,   105,   108,
     110,    76,     0,    73,    43,    53,     0,     0,     0,     0,
      72,    92,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    44,    47,
     101,   103,   102,   104,   106,   107,   109,   111,    49,    73,
       0,    56,     0,     0,    74,    55,    54,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,    83,   -65,  -156,   180,   261,     2,  -156,   190,   -16,
     -17,   146,  -156,   -22,  -156,   168,  -155,  -156,   251,   -14,
     -55,   149,   258,  -156,   225,  -156,    86,   -42,   152,   -61,
     145,  -156,   -35,  -156,   144,    23,   -24,   -44,   116,   118,
    -156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    65,    66,     7,     8,    57,    18,
      85,    86,     9,   107,   108,   109,   110,   111,    43,    27,
      61,    92,    62,    10,    35,    36,   184,    53,   156,    45,
      75,    46,    47,    48,   119,    49,    54,   158,   159,   160,
     161
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    50,   105,    12,    91,    50,   113,    30,    93,    52,
      68,    69,    58,    78,    11,    79,    80,    11,   189,     3,
      82,    83,     3,     1,     2,   112,    34,   198,    81,     3,
      25,   118,   120,    26,   -24,    50,   178,   179,    87,    50,
      37,    38,    33,   105,   123,   124,   125,   113,   207,   115,
      30,    14,    39,    73,    40,    74,    41,    42,   143,   142,
      73,    13,    74,   122,    51,    84,   112,    37,    38,   106,
      50,   130,    25,    58,    34,    29,    16,    91,    19,    39,
      24,    40,    25,    41,    42,    26,   -24,    25,    15,    23,
      88,    59,    90,    20,    73,    17,    74,    25,   164,    21,
      94,   167,    28,    37,    38,   126,   127,   169,    50,   118,
     106,    31,   113,   157,   157,    39,    55,    40,    32,    41,
      42,   113,   174,   175,   176,   177,    56,    51,    63,   166,
      71,   112,    37,    38,   194,   195,   170,    64,    70,    67,
     112,   199,   113,    72,    39,   -26,    40,    77,    41,    42,
     190,   191,   192,   193,   157,   157,   157,   157,    89,    -9,
      95,   112,     1,    11,    96,    97,    98,   114,     3,    99,
     121,   100,   101,    37,    38,    25,   168,   128,   129,    37,
      38,   132,   133,   135,   136,   102,   137,    40,   138,    41,
      42,    39,   139,    40,   103,    41,    42,    67,   104,     1,
      11,    96,    97,    98,   144,     3,    99,   147,   100,   101,
      37,    38,   148,   151,   150,   149,    37,    38,   152,   153,
     163,   173,   102,   165,    40,    74,    41,    42,    39,   180,
      40,   103,    41,    42,    67,   145,    96,    97,    98,   181,
      59,    99,   182,   100,   101,    37,    38,   185,   183,   187,
     186,    37,    38,   200,   188,   201,   202,   102,   203,    40,
     205,    41,    42,   140,   206,    40,   103,    41,    42,    67,
      37,    38,   141,    22,   154,   134,   146,    37,    38,   131,
      60,   155,    39,    44,    40,   204,    41,    42,   117,    39,
     162,    40,     0,    41,    42,   171,   196,   116,   172,   197
};

static const yytype_int16 yycheck[] =
{
      42,    25,    67,     1,    59,    29,    67,    21,    63,    26,
      32,    33,    28,    48,     5,    17,    18,     5,   173,    10,
      15,    16,    10,     4,     5,    67,    24,   182,    30,    10,
      34,    73,    74,    37,    38,    59,    23,    24,    55,    63,
      15,    16,    33,   108,    79,    80,    81,   108,   203,    71,
      64,     0,    27,    32,    29,    34,    31,    32,    37,   101,
      32,     3,    34,    77,    39,    40,   108,    15,    16,    67,
      94,    88,    34,    89,    72,    37,    36,   132,    36,    27,
      32,    29,    34,    31,    32,    37,    38,    34,     5,    32,
      37,    39,    40,    10,    32,    27,    34,    34,    36,    27,
      37,   143,    38,    15,    16,    82,    83,   149,   132,   151,
     108,    38,   173,   137,   138,    27,    37,    29,    33,    31,
      32,   182,    19,    20,    21,    22,    27,    39,    37,    12,
      33,   173,    15,    16,   178,   179,   150,    27,    27,    39,
     182,   183,   203,    38,    27,    38,    29,    35,    31,    32,
     174,   175,   176,   177,   178,   179,   180,   181,    38,    36,
      38,   203,     4,     5,     6,     7,     8,    34,    10,    11,
      33,    13,    14,    15,    16,    34,    12,    38,    40,    15,
      16,    38,    40,    36,    36,    27,    32,    29,    32,    31,
      32,    27,    32,    29,    36,    31,    32,    39,    40,     4,
       5,     6,     7,     8,    27,    10,    11,    36,    13,    14,
      15,    16,    36,    38,    35,    37,    15,    16,    33,    35,
      28,    33,    27,    36,    29,    34,    31,    32,    27,    25,
      29,    36,    31,    32,    39,    40,     6,     7,     8,    26,
      39,    11,    33,    13,    14,    15,    16,    32,    38,    32,
      36,    15,    16,    33,    36,    33,    33,    27,     9,    29,
      36,    31,    32,    27,    36,    29,    36,    31,    32,    39,
      15,    16,    36,    12,   128,    95,   108,    15,    16,    89,
      29,   132,    27,    25,    29,   199,    31,    32,    33,    27,
     138,    29,    -1,    31,    32,   151,   180,    72,   153,   181
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    10,    42,    43,    44,    47,    48,    53,
      64,     5,    47,     3,     0,    42,    36,    27,    50,    36,
      42,    27,    46,    32,    32,    34,    37,    60,    38,    37,
      60,    38,    33,    33,    47,    65,    66,    15,    16,    27,
      29,    31,    32,    59,    63,    70,    72,    73,    74,    76,
      77,    39,    51,    68,    77,    37,    27,    49,    50,    39,
      59,    61,    63,    37,    27,    45,    46,    39,    54,    54,
      27,    33,    38,    32,    34,    71,    68,    35,    73,    17,
      18,    30,    15,    16,    40,    51,    52,    51,    37,    38,
      40,    61,    62,    61,    37,    38,     6,     7,     8,    11,
      13,    14,    27,    36,    40,    43,    47,    54,    55,    56,
      57,    58,    68,    70,    34,    54,    65,    33,    68,    75,
      68,    33,    60,    73,    73,    73,    76,    76,    38,    40,
      51,    49,    38,    40,    45,    36,    36,    32,    32,    32,
      27,    36,    68,    37,    27,    40,    56,    36,    36,    37,
      35,    38,    33,    35,    52,    62,    69,    77,    78,    79,
      80,    81,    69,    28,    36,    36,    12,    68,    12,    68,
      60,    75,    71,    33,    19,    20,    21,    22,    23,    24,
      25,    26,    33,    38,    67,    32,    36,    32,    36,    57,
      77,    77,    77,    77,    78,    78,    79,    80,    57,    68,
      33,    33,    33,     9,    67,    36,    36,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    43,    43,    44,
      44,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    51,    51,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    60,    60,
      61,    61,    61,    62,    62,    63,    64,    64,    65,    65,
      66,    66,    66,    67,    67,    68,    69,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     2,     2,     5,
       3,     5,     1,     3,     3,     4,     1,     1,     2,     4,
       2,     4,     1,     3,     1,     2,     3,     4,     1,     2,
       3,     1,     3,     5,     3,     2,     2,     1,     1,     1,
       2,     4,     1,     3,     4,     1,     2,     5,     7,     5,
       2,     2,     2,     3,     6,     6,     5,     1,     3,     4,
       1,     2,     3,     1,     3,     1,     5,     6,     1,     3,
       2,     4,     5,     0,     3,     1,     1,     1,     2,     3,
       4,     3,     1,     1,     1,     3,     4,     2,     1,     1,
       1,     1,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3
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
  case 2: /* CompUnit: Decl CompUnit  */
#line 66 "yacc.y"
                    {
        auto ast = dynamic_cast<CompUnitAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new CompUnitAST(); // Should not happen if root is handled correctly
            root.reset(ast);
        }
        if ((yyvsp[-1].ast_ptr)) {
            // Prepend declaration to maintain order similar to original linked list approach
            ast->declarations.insert(ast->declarations.begin(), std::unique_ptr<BaseAST>(static_cast<BaseAST*>((yyvsp[-1].ast_ptr))));
        }
        (yyval.ast_ptr) = ast;
    }
#line 1327 "yacc.tab.c"
    break;

  case 3: /* CompUnit: FuncDef CompUnit  */
#line 78 "yacc.y"
                       {
        auto ast = dynamic_cast<CompUnitAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new CompUnitAST(); // Should not happen if root is handled correctly
            root.reset(ast);
        }
        if ((yyvsp[-1].ast_ptr)) {
            // Prepend function definition
            ast->function_definitions.insert(ast->function_definitions.begin(), std::unique_ptr<BaseAST>(static_cast<BaseAST*>((yyvsp[-1].ast_ptr))));
        }
        (yyval.ast_ptr) = ast;
    }
#line 1344 "yacc.tab.c"
    break;

  case 4: /* CompUnit: MainFuncDef  */
#line 90 "yacc.y"
                  {
        auto ast = std::make_unique<CompUnitAST>();
        ast->main_func_def.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        root = std::move(ast); // Set global root
        (yyval.ast_ptr) = root.get(); // Return raw pointer for bison stack
    }
#line 1355 "yacc.tab.c"
    break;

  case 5: /* CompUnit: Decl  */
#line 96 "yacc.y"
           {
        auto ast = std::make_unique<CompUnitAST>();
        if ((yyvsp[0].ast_ptr)) {
            ast->declarations.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        }
        root = std::move(ast);
        (yyval.ast_ptr) = root.get();
    }
#line 1368 "yacc.tab.c"
    break;

  case 6: /* CompUnit: FuncDef  */
#line 104 "yacc.y"
              {
        auto ast = std::make_unique<CompUnitAST>();
        if ((yyvsp[0].ast_ptr)) {
            ast->function_definitions.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        }
        root = std::move(ast);
        (yyval.ast_ptr) = root.get();
    }
#line 1381 "yacc.tab.c"
    break;

  case 7: /* Decl: ConstDecl ';'  */
#line 117 "yacc.y"
                  {
        auto ast = std::make_unique<DeclAST>();
        ast->decl.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        ast->kind = DeclAST::DeclKind::CONST_DECL;
        (yyval.ast_ptr) = ast.release();
    }
#line 1392 "yacc.tab.c"
    break;

  case 8: /* Decl: VarDecl ';'  */
#line 122 "yacc.y"
                    {
        auto ast = std::make_unique<DeclAST>();
        ast->decl.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        ast->kind = DeclAST::DeclKind::VAR_DECL;
        (yyval.ast_ptr) = ast.release();
    }
#line 1403 "yacc.tab.c"
    break;

  case 9: /* ConstDecl: CONST BType IDENT '=' Number  */
#line 132 "yacc.y"
                                 {
        auto ast = std::make_unique<ConstDeclAST>();
        ast->type = TYPE_INT;  // 假设默认为INT类型
        
        // 使用$3而不是yytext
        ast->ident = std::string((yyvsp[-2].str_val));  
        
        // 获取Number节点的值
        auto number = dynamic_cast<NumberAST*>((yyvsp[0].ast_ptr));
        if (number) {
            ast->value = number->value;
        }
        
        // 释放字符串
        free((yyvsp[-2].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1426 "yacc.tab.c"
    break;

  case 10: /* ConstDecl: CONST BType ConstDef  */
#line 149 "yacc.y"
                             {
        auto ast = std::make_unique<ConstDeclAST>();
        if ((yyvsp[-1].ast_ptr)) {
            ast->type = TYPE_INT; // 假设默认为INT类型
        }
        ast->const_def.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1439 "yacc.tab.c"
    break;

  case 11: /* ConstDecl: CONST BType ConstDef ',' ConstDefList  */
#line 156 "yacc.y"
                                              {
        auto ast = std::make_unique<ConstDeclAST>();
        if ((yyvsp[-3].ast_ptr)) {
            ast->type = TYPE_INT; // 假设默认为INT类型
        }
        
        auto const_def_list = std::make_unique<ConstDefListAST>();
        const_def_list->const_defs.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        
        auto def_list = dynamic_cast<ConstDefListAST*>((yyvsp[0].ast_ptr));
        if (def_list) {
            for (auto& def : def_list->const_defs) {
                const_def_list->const_defs.emplace_back(std::move(def));
            }
        }
        
        ast->const_def_list.reset(const_def_list.release());
        (yyval.ast_ptr) = ast.release();
    }
#line 1463 "yacc.tab.c"
    break;

  case 12: /* ConstDefList: ConstDef  */
#line 178 "yacc.y"
             {
        auto ast = std::make_unique<ConstDefListAST>();
        ast->const_defs.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1473 "yacc.tab.c"
    break;

  case 13: /* ConstDefList: ConstDef ',' ConstDefList  */
#line 182 "yacc.y"
                                  {
        auto ast = dynamic_cast<ConstDefListAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new ConstDefListAST();
        }
        ast->const_defs.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1486 "yacc.tab.c"
    break;

  case 14: /* ConstDef: IDENT '=' ConstInitVal  */
#line 194 "yacc.y"
                           {
        auto ast = std::make_unique<ConstDefAST>();
        ast->ident = std::string((yyvsp[-2].str_val));
        ast->const_init_val.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-2].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1501 "yacc.tab.c"
    break;

  case 15: /* ConstDef: IDENT ArrayDims '=' ConstInitVal  */
#line 203 "yacc.y"
                                         {
        auto ast = std::make_unique<ConstDefAST>();
        ast->ident = std::string((yyvsp[-3].str_val));
        ast->array_dims.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->const_init_val.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1517 "yacc.tab.c"
    break;

  case 16: /* BType: INT  */
#line 218 "yacc.y"
        {
        (yyval.ast_ptr) = nullptr;  // BType不需要生成AST节点
    }
#line 1525 "yacc.tab.c"
    break;

  case 17: /* BType: VOID  */
#line 221 "yacc.y"
         {
        (yyval.ast_ptr) = nullptr;  // BType不需要生成AST节点
    }
#line 1533 "yacc.tab.c"
    break;

  case 18: /* VarDecl: BType IDENT  */
#line 228 "yacc.y"
                {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT;
        ast->ident = std::string((yyvsp[0].str_val));
        
        // 释放字符串
        free((yyvsp[0].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1548 "yacc.tab.c"
    break;

  case 19: /* VarDecl: BType IDENT '=' InitVal  */
#line 237 "yacc.y"
                                {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT;
        ast->ident = std::string((yyvsp[-2].str_val));
        
        // 创建一个VarDefAST并设置初始化值
        auto var_def = std::make_unique<VarDefAST>();
        var_def->ident = std::string((yyvsp[-2].str_val));
        var_def->init_val.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        var_def->has_init = true;
        
        ast->var_def.reset(var_def.release());
        
        // 释放字符串
        free((yyvsp[-2].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1571 "yacc.tab.c"
    break;

  case 20: /* VarDecl: BType VarDef  */
#line 254 "yacc.y"
                     {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT; // 假设类型为INT
        ast->var_def.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1582 "yacc.tab.c"
    break;

  case 21: /* VarDecl: BType VarDef ',' VarDefList  */
#line 259 "yacc.y"
                                    {
        auto ast = std::make_unique<VarDeclAST>();
        ast->type = TYPE_INT; // 假设类型为INT
        
        auto var_def_list = std::make_unique<VarDefListAST>();
        var_def_list->var_defs.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        
        auto def_list = dynamic_cast<VarDefListAST*>((yyvsp[0].ast_ptr));
        if (def_list) {
            for (auto& def : def_list->var_defs) {
                var_def_list->var_defs.emplace_back(std::move(def));
            }
        }
        
        ast->var_def_list.reset(var_def_list.release());
        (yyval.ast_ptr) = ast.release();
    }
#line 1604 "yacc.tab.c"
    break;

  case 22: /* VarDefList: VarDef  */
#line 279 "yacc.y"
           {
        auto ast = std::make_unique<VarDefListAST>();
        ast->var_defs.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1614 "yacc.tab.c"
    break;

  case 23: /* VarDefList: VarDef ',' VarDefList  */
#line 283 "yacc.y"
                              {
        auto ast = dynamic_cast<VarDefListAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new VarDefListAST();
        }
        ast->var_defs.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1627 "yacc.tab.c"
    break;

  case 24: /* VarDef: IDENT  */
#line 295 "yacc.y"
          {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string((yyvsp[0].str_val));
        ast->has_init = false;
        
        // 释放字符串
        free((yyvsp[0].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1642 "yacc.tab.c"
    break;

  case 25: /* VarDef: IDENT ArrayDims  */
#line 304 "yacc.y"
                        {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string((yyvsp[-1].str_val));
        ast->array_dims.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->has_init = false;
        
        // 释放字符串
        free((yyvsp[-1].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1658 "yacc.tab.c"
    break;

  case 26: /* VarDef: IDENT '=' InitVal  */
#line 314 "yacc.y"
                          {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string((yyvsp[-2].str_val));
        ast->init_val.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->has_init = true;
        
        // 释放字符串
        free((yyvsp[-2].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1674 "yacc.tab.c"
    break;

  case 27: /* VarDef: IDENT ArrayDims '=' InitVal  */
#line 324 "yacc.y"
                                    {
        auto ast = std::make_unique<VarDefAST>();
        ast->ident = std::string((yyvsp[-3].str_val));
        ast->array_dims.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->init_val.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->has_init = true;
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1691 "yacc.tab.c"
    break;

  case 28: /* InitVal: Exp  */
#line 340 "yacc.y"
        {
        auto ast = std::make_unique<InitValAST>();
        ast->init_type = InitValAST::InitType::EXPR;
        ast->expr.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1702 "yacc.tab.c"
    break;

  case 29: /* InitVal: '{' '}'  */
#line 345 "yacc.y"
                {
        auto ast = std::make_unique<InitValAST>();
        ast->init_type = InitValAST::InitType::LIST;
        ast->list.reset(new InitValListAST()); // 空列表
        (yyval.ast_ptr) = ast.release();
    }
#line 1713 "yacc.tab.c"
    break;

  case 30: /* InitVal: '{' InitValList '}'  */
#line 350 "yacc.y"
                            {
        auto ast = std::make_unique<InitValAST>();
        ast->init_type = InitValAST::InitType::LIST;
        ast->list.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1724 "yacc.tab.c"
    break;

  case 31: /* InitValList: InitVal  */
#line 359 "yacc.y"
            {
        auto ast = std::make_unique<InitValListAST>();
        ast->init_vals.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1734 "yacc.tab.c"
    break;

  case 32: /* InitValList: InitVal ',' InitValList  */
#line 363 "yacc.y"
                                {
        auto ast = dynamic_cast<InitValListAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new InitValListAST();
        }
        ast->init_vals.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1747 "yacc.tab.c"
    break;

  case 33: /* MainFuncDef: INT MAIN '(' ')' Block  */
#line 374 "yacc.y"
                           {
        auto ast = std::make_unique<MainFuncDefAST>();
        ast->block.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1757 "yacc.tab.c"
    break;

  case 34: /* Block: '{' BlockItems '}'  */
#line 382 "yacc.y"
                       {
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr);  // 直接使用BlockItems生成的BlockAST
    }
#line 1765 "yacc.tab.c"
    break;

  case 35: /* Block: '{' '}'  */
#line 384 "yacc.y"
                {
        auto ast = std::make_unique<BlockAST>();  // 创建空块
        (yyval.ast_ptr) = ast.release();
    }
#line 1774 "yacc.tab.c"
    break;

  case 36: /* BlockItems: BlockItems BlockItem  */
#line 391 "yacc.y"
                         {
        auto block = dynamic_cast<BlockAST*>((yyvsp[-1].ast_ptr));
        if (block && (yyvsp[0].ast_ptr)) {
            block->items.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        }
        (yyval.ast_ptr) = block;
    }
#line 1786 "yacc.tab.c"
    break;

  case 37: /* BlockItems: BlockItem  */
#line 397 "yacc.y"
                  {
        auto ast = std::make_unique<BlockAST>();
        if ((yyvsp[0].ast_ptr)) {
            ast->items.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        }
        (yyval.ast_ptr) = ast.release();
    }
#line 1798 "yacc.tab.c"
    break;

  case 38: /* BlockItem: Decl  */
#line 407 "yacc.y"
         {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1806 "yacc.tab.c"
    break;

  case 39: /* BlockItem: Stmt  */
#line 409 "yacc.y"
             {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1814 "yacc.tab.c"
    break;

  case 40: /* Stmt: Assignment ';'  */
#line 415 "yacc.y"
                   {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::ASSIGNMENT;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1825 "yacc.tab.c"
    break;

  case 41: /* Stmt: IDENT '=' Exp ';'  */
#line 421 "yacc.y"
                        {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::ASSIGN;
        
        auto assign = std::make_unique<AssignmentAST>();
        auto lval = std::make_unique<LValAST>();
        lval->ident = std::string((yyvsp[-3].str_val));
        assign->lval.reset(lval.release());
        assign->exp.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        ast->content = std::move(assign);
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1846 "yacc.tab.c"
    break;

  case 42: /* Stmt: Block  */
#line 437 "yacc.y"
            {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::BLOCK;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1857 "yacc.tab.c"
    break;

  case 43: /* Stmt: RETURN IDENT ';'  */
#line 443 "yacc.y"
                       {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::RETURN;
        ast->return_ident = std::string((yyvsp[-1].str_val));
        
        // 释放字符串
        free((yyvsp[-1].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1872 "yacc.tab.c"
    break;

  case 44: /* Stmt: LVal '=' Exp ';'  */
#line 453 "yacc.y"
                       {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::ASSIGN;
        
        auto assign = std::make_unique<AssignmentAST>();
        assign->lval.reset(static_cast<BaseAST*>((yyvsp[-3].ast_ptr)));
        assign->exp.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        ast->content = std::move(assign);
        
        (yyval.ast_ptr) = ast.release();
    }
#line 1888 "yacc.tab.c"
    break;

  case 45: /* Stmt: ';'  */
#line 464 "yacc.y"
          {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::EMPTY;
        (yyval.ast_ptr) = ast.release();
    }
#line 1898 "yacc.tab.c"
    break;

  case 46: /* Stmt: Exp ';'  */
#line 469 "yacc.y"
              {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::EXPRESSION;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1909 "yacc.tab.c"
    break;

  case 47: /* Stmt: IF '(' Cond ')' Stmt  */
#line 475 "yacc.y"
                           {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::IF;
        ast->cond.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->if_stmt.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1921 "yacc.tab.c"
    break;

  case 48: /* Stmt: IF '(' Cond ')' Stmt ELSE Stmt  */
#line 482 "yacc.y"
                                     {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::IF_ELSE;
        ast->cond.reset(static_cast<BaseAST*>((yyvsp[-4].ast_ptr)));
        ast->if_stmt.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->else_stmt.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1934 "yacc.tab.c"
    break;

  case 49: /* Stmt: WHILE '(' Cond ')' Stmt  */
#line 490 "yacc.y"
                              {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::WHILE;
        ast->cond.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->while_stmt.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1946 "yacc.tab.c"
    break;

  case 50: /* Stmt: BREAK ';'  */
#line 497 "yacc.y"
                {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::BREAK;
        (yyval.ast_ptr) = ast.release();
    }
#line 1956 "yacc.tab.c"
    break;

  case 51: /* Stmt: CONTINUE ';'  */
#line 502 "yacc.y"
                   {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::CONTINUE;
        (yyval.ast_ptr) = ast.release();
    }
#line 1966 "yacc.tab.c"
    break;

  case 52: /* Stmt: RETURN ';'  */
#line 507 "yacc.y"
                 {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::RETURN_VOID;
        (yyval.ast_ptr) = ast.release();
    }
#line 1976 "yacc.tab.c"
    break;

  case 53: /* Stmt: RETURN Exp ';'  */
#line 512 "yacc.y"
                     {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::RETURN_EXP;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1987 "yacc.tab.c"
    break;

  case 54: /* Stmt: LVal '=' GETINT '(' ')' ';'  */
#line 518 "yacc.y"
                                  {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::GETINT;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-5].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 1998 "yacc.tab.c"
    break;

  case 55: /* Stmt: PRINTF '(' STR_CONST PrintfItems ')' ';'  */
#line 524 "yacc.y"
                                               {
        auto ast = std::make_unique<StmtAST>();
        ast->kind = StmtAST::PRINTF;
        
        auto printf_items = std::make_unique<PrintfItemsAST>();
        printf_items->format_string = std::string((yyvsp[-3].str_val));
        
        // 如果有其他参数
        auto items = dynamic_cast<PrintfItemsAST*>((yyvsp[-2].ast_ptr));
        if (items) {
            printf_items->expressions = std::move(items->expressions);
        }
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        ast->content.reset(printf_items.release());
        (yyval.ast_ptr) = ast.release();
    }
#line 2022 "yacc.tab.c"
    break;

  case 56: /* Assignment: IDENT '=' GETINT '(' ')'  */
#line 546 "yacc.y"
                             {
        auto ast = std::make_unique<AssignmentAST>();
        ast->ident = std::string((yyvsp[-4].str_val));
        
        // 释放字符串
        free((yyvsp[-4].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2036 "yacc.tab.c"
    break;

  case 57: /* Number: INT_CONST  */
#line 558 "yacc.y"
              {
        auto ast = std::make_unique<NumberAST>();
        ast->value = (yyvsp[0].int_val);
        (yyval.ast_ptr) = ast.release();
    }
#line 2046 "yacc.tab.c"
    break;

  case 58: /* ArrayDims: '[' ConstExp ']'  */
#line 566 "yacc.y"
                     {
        auto ast = std::make_unique<ArrayDimsAST>();
        ast->dims.emplace_back(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2056 "yacc.tab.c"
    break;

  case 59: /* ArrayDims: '[' ConstExp ']' ArrayDims  */
#line 570 "yacc.y"
                                   {
        auto ast = dynamic_cast<ArrayDimsAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new ArrayDimsAST();
        }
        ast->dims.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2069 "yacc.tab.c"
    break;

  case 60: /* ConstInitVal: ConstExp  */
#line 582 "yacc.y"
             {
        auto ast = std::make_unique<ConstInitValAST>();
        ast->init_type = ConstInitValAST::InitType::EXPR;
        ast->expr.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2080 "yacc.tab.c"
    break;

  case 61: /* ConstInitVal: '{' '}'  */
#line 587 "yacc.y"
                {
        auto ast = std::make_unique<ConstInitValAST>();
        ast->init_type = ConstInitValAST::InitType::LIST;
        ast->list.reset(new ConstInitValListAST()); // 空列表
        (yyval.ast_ptr) = ast.release();
    }
#line 2091 "yacc.tab.c"
    break;

  case 62: /* ConstInitVal: '{' ConstInitValList '}'  */
#line 592 "yacc.y"
                                 {
        auto ast = std::make_unique<ConstInitValAST>();
        ast->init_type = ConstInitValAST::InitType::LIST;
        ast->list.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2102 "yacc.tab.c"
    break;

  case 63: /* ConstInitValList: ConstInitVal  */
#line 601 "yacc.y"
                 {
        auto ast = std::make_unique<ConstInitValListAST>();
        ast->init_vals.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2112 "yacc.tab.c"
    break;

  case 64: /* ConstInitValList: ConstInitVal ',' ConstInitValList  */
#line 605 "yacc.y"
                                          {
        auto ast = dynamic_cast<ConstInitValListAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new ConstInitValListAST();
        }
        ast->init_vals.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2125 "yacc.tab.c"
    break;

  case 65: /* ConstExp: AddExp  */
#line 617 "yacc.y"
           {
        auto ast = std::make_unique<ConstExpAST>();
        ast->exp.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2135 "yacc.tab.c"
    break;

  case 66: /* FuncDef: BType IDENT '(' ')' Block  */
#line 626 "yacc.y"
                              {
        auto ast = std::make_unique<FuncDefAST>();
        ast->return_type = TYPE_INT; // 假设返回类型为INT
        ast->ident = std::string((yyvsp[-3].str_val));
        ast->block.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2151 "yacc.tab.c"
    break;

  case 67: /* FuncDef: BType IDENT '(' FuncFParams ')' Block  */
#line 636 "yacc.y"
                                              {
        auto ast = std::make_unique<FuncDefAST>();
        ast->return_type = TYPE_INT; // 假设返回类型为INT
        ast->ident = std::string((yyvsp[-4].str_val));
        ast->func_f_params.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->block.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-4].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2168 "yacc.tab.c"
    break;

  case 68: /* FuncFParams: FuncFParam  */
#line 652 "yacc.y"
               {
        auto ast = std::make_unique<FuncFParamsAST>();
        ast->params.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2178 "yacc.tab.c"
    break;

  case 69: /* FuncFParams: FuncFParam ',' FuncFParams  */
#line 656 "yacc.y"
                                   {
        auto ast = dynamic_cast<FuncFParamsAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new FuncFParamsAST();
        }
        ast->params.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2191 "yacc.tab.c"
    break;

  case 70: /* FuncFParam: BType IDENT  */
#line 668 "yacc.y"
                {
        auto ast = std::make_unique<FuncFParamAST>();
        ast->param_type = TYPE_INT; // 假设类型为INT
        ast->ident = std::string((yyvsp[0].str_val));
        ast->is_array = false;
        
        // 释放字符串
        free((yyvsp[0].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2207 "yacc.tab.c"
    break;

  case 71: /* FuncFParam: BType IDENT '[' ']'  */
#line 678 "yacc.y"
                            {
        auto ast = std::make_unique<FuncFParamAST>();
        ast->param_type = TYPE_INT; // 假设类型为INT
        ast->ident = std::string((yyvsp[-2].str_val));
        ast->is_array = true;
        
        // 释放字符串
        free((yyvsp[-2].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2223 "yacc.tab.c"
    break;

  case 72: /* FuncFParam: BType IDENT '[' ']' ArrayDims  */
#line 688 "yacc.y"
                                      {
        auto ast = std::make_unique<FuncFParamAST>();
        ast->param_type = TYPE_INT; // 假设类型为INT
        ast->ident = std::string((yyvsp[-3].str_val));
        ast->is_array = true;
        ast->array_dims.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2240 "yacc.tab.c"
    break;

  case 73: /* PrintfItems: %empty  */
#line 703 "yacc.y"
                {
        auto ast = std::make_unique<PrintfItemsAST>();
        (yyval.ast_ptr) = ast.release();
    }
#line 2249 "yacc.tab.c"
    break;

  case 74: /* PrintfItems: ',' Exp PrintfItems  */
#line 706 "yacc.y"
                            {
        auto ast = dynamic_cast<PrintfItemsAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new PrintfItemsAST();
        }
        
        // 使用emplace_back添加表达式
        ast->expressions.emplace_back(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2264 "yacc.tab.c"
    break;

  case 75: /* Exp: AddExp  */
#line 720 "yacc.y"
           {
        auto ast = std::make_unique<ExpAST>();
        ast->expr.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2274 "yacc.tab.c"
    break;

  case 76: /* Cond: LOrExp  */
#line 729 "yacc.y"
           {
        auto ast = std::make_unique<CondAST>();
        ast->expr.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2284 "yacc.tab.c"
    break;

  case 77: /* LVal: IDENT  */
#line 738 "yacc.y"
          {
        auto ast = std::make_unique<LValAST>();
        ast->ident = std::string((yyvsp[0].str_val));
        
        // 释放字符串
        free((yyvsp[0].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2298 "yacc.tab.c"
    break;

  case 78: /* LVal: IDENT LValArrayIndices  */
#line 746 "yacc.y"
                               {
        auto ast = std::make_unique<LValAST>();
        ast->ident = std::string((yyvsp[-1].str_val));
        ast->array_indices.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-1].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2313 "yacc.tab.c"
    break;

  case 79: /* LValArrayIndices: '[' Exp ']'  */
#line 759 "yacc.y"
                {
        auto ast = std::make_unique<LValArrayIndicesAST>();
        ast->indices.emplace_back(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2323 "yacc.tab.c"
    break;

  case 80: /* LValArrayIndices: '[' Exp ']' LValArrayIndices  */
#line 763 "yacc.y"
                                     {
        auto ast = dynamic_cast<LValArrayIndicesAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new LValArrayIndicesAST();
        }
        ast->indices.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2336 "yacc.tab.c"
    break;

  case 81: /* PrimaryExp: '(' Exp ')'  */
#line 775 "yacc.y"
                {
        auto ast = std::make_unique<PrimaryExpAST>();
        ast->type = PrimaryExpAST::PrimaryType::EXP;
        ast->exp.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2347 "yacc.tab.c"
    break;

  case 82: /* PrimaryExp: LVal  */
#line 780 "yacc.y"
             {
        auto ast = std::make_unique<PrimaryExpAST>();
        ast->type = PrimaryExpAST::PrimaryType::LVAL;
        ast->lval.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2358 "yacc.tab.c"
    break;

  case 83: /* PrimaryExp: Number  */
#line 785 "yacc.y"
               {
        auto ast = std::make_unique<PrimaryExpAST>();
        ast->type = PrimaryExpAST::PrimaryType::NUMBER;
        ast->number.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2369 "yacc.tab.c"
    break;

  case 84: /* UnaryExp: PrimaryExp  */
#line 795 "yacc.y"
               {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::PRIMARY;
        ast->primary_exp.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2380 "yacc.tab.c"
    break;

  case 85: /* UnaryExp: IDENT '(' ')'  */
#line 800 "yacc.y"
                      {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::FUNC_CALL;
        ast->func_name = std::string((yyvsp[-2].str_val));
        
        // 释放字符串
        free((yyvsp[-2].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2395 "yacc.tab.c"
    break;

  case 86: /* UnaryExp: IDENT '(' FuncRParams ')'  */
#line 809 "yacc.y"
                                  {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::FUNC_CALL;
        ast->func_name = std::string((yyvsp[-3].str_val));
        ast->func_r_params.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast.release();
    }
#line 2411 "yacc.tab.c"
    break;

  case 87: /* UnaryExp: UnaryOp UnaryExp  */
#line 819 "yacc.y"
                         {
        auto ast = std::make_unique<UnaryExpAST>();
        ast->type = UnaryExpAST::UnaryType::UNARY;
        ast->unary_op.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        ast->unary_exp.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2423 "yacc.tab.c"
    break;

  case 88: /* UnaryOp: PLUS  */
#line 830 "yacc.y"
         {
        auto ast = std::make_unique<UnaryOpAST>();
        ast->op = UnaryOpAST::OpType::PLUS;
        (yyval.ast_ptr) = ast.release();
    }
#line 2433 "yacc.tab.c"
    break;

  case 89: /* UnaryOp: MINUS  */
#line 834 "yacc.y"
              {
        auto ast = std::make_unique<UnaryOpAST>();
        ast->op = UnaryOpAST::OpType::MINUS;
        (yyval.ast_ptr) = ast.release();
    }
#line 2443 "yacc.tab.c"
    break;

  case 90: /* UnaryOp: '!'  */
#line 838 "yacc.y"
            {
        auto ast = std::make_unique<UnaryOpAST>();
        ast->op = UnaryOpAST::OpType::NOT;
        (yyval.ast_ptr) = ast.release();
    }
#line 2453 "yacc.tab.c"
    break;

  case 91: /* FuncRParams: Exp  */
#line 847 "yacc.y"
        {
        auto ast = std::make_unique<FuncRParamsAST>();
        ast->params.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast.release();
    }
#line 2463 "yacc.tab.c"
    break;

  case 92: /* FuncRParams: Exp ',' FuncRParams  */
#line 851 "yacc.y"
                            {
        auto ast = dynamic_cast<FuncRParamsAST*>((yyvsp[0].ast_ptr));
        if (!ast) {
            ast = new FuncRParamsAST();
        }
        ast->params.emplace_back(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2476 "yacc.tab.c"
    break;

  case 93: /* MulExp: UnaryExp  */
#line 863 "yacc.y"
             {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = MulExpAST::OpType::NONE;
        (yyval.ast_ptr) = ast.release();
    }
#line 2487 "yacc.tab.c"
    break;

  case 94: /* MulExp: MulExp TIMES UnaryExp  */
#line 868 "yacc.y"
                              {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = MulExpAST::OpType::MUL;
        (yyval.ast_ptr) = ast.release();
    }
#line 2499 "yacc.tab.c"
    break;

  case 95: /* MulExp: MulExp DIVIDE UnaryExp  */
#line 874 "yacc.y"
                               {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = MulExpAST::OpType::DIV;
        (yyval.ast_ptr) = ast.release();
    }
#line 2511 "yacc.tab.c"
    break;

  case 96: /* MulExp: MulExp '%' UnaryExp  */
#line 880 "yacc.y"
                            {
        auto ast = std::make_unique<MulExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = MulExpAST::OpType::MOD;
        (yyval.ast_ptr) = ast.release();
    }
#line 2523 "yacc.tab.c"
    break;

  case 97: /* AddExp: MulExp  */
#line 891 "yacc.y"
           {
        auto ast = std::make_unique<AddExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = AddExpAST::OpType::NONE;
        (yyval.ast_ptr) = ast.release();
    }
#line 2534 "yacc.tab.c"
    break;

  case 98: /* AddExp: AddExp PLUS MulExp  */
#line 896 "yacc.y"
                           {
        auto ast = std::make_unique<AddExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = AddExpAST::OpType::ADD;
        (yyval.ast_ptr) = ast.release();
    }
#line 2546 "yacc.tab.c"
    break;

  case 99: /* AddExp: AddExp MINUS MulExp  */
#line 902 "yacc.y"
                            {
        auto ast = std::make_unique<AddExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = AddExpAST::OpType::SUB;
        (yyval.ast_ptr) = ast.release();
    }
#line 2558 "yacc.tab.c"
    break;

  case 100: /* RelExp: AddExp  */
#line 913 "yacc.y"
           {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = RelExpAST::OpType::NONE;
        (yyval.ast_ptr) = ast.release();
    }
#line 2569 "yacc.tab.c"
    break;

  case 101: /* RelExp: RelExp LSS AddExp  */
#line 918 "yacc.y"
                          {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = RelExpAST::OpType::LESS;
        (yyval.ast_ptr) = ast.release();
    }
#line 2581 "yacc.tab.c"
    break;

  case 102: /* RelExp: RelExp GRE AddExp  */
#line 924 "yacc.y"
                          {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = RelExpAST::OpType::GREATER;
        (yyval.ast_ptr) = ast.release();
    }
#line 2593 "yacc.tab.c"
    break;

  case 103: /* RelExp: RelExp LEQ AddExp  */
#line 930 "yacc.y"
                          {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = RelExpAST::OpType::LESS_EQ;
        (yyval.ast_ptr) = ast.release();
    }
#line 2605 "yacc.tab.c"
    break;

  case 104: /* RelExp: RelExp GEQ AddExp  */
#line 936 "yacc.y"
                          {
        auto ast = std::make_unique<RelExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = RelExpAST::OpType::GREATER_EQ;
        (yyval.ast_ptr) = ast.release();
    }
#line 2617 "yacc.tab.c"
    break;

  case 105: /* EqExp: RelExp  */
#line 947 "yacc.y"
           {
        auto ast = std::make_unique<EqExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = EqExpAST::OpType::NONE;
        (yyval.ast_ptr) = ast.release();
    }
#line 2628 "yacc.tab.c"
    break;

  case 106: /* EqExp: EqExp EQL RelExp  */
#line 952 "yacc.y"
                         {
        auto ast = std::make_unique<EqExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = EqExpAST::OpType::EQ;
        (yyval.ast_ptr) = ast.release();
    }
#line 2640 "yacc.tab.c"
    break;

  case 107: /* EqExp: EqExp NEQ RelExp  */
#line 958 "yacc.y"
                         {
        auto ast = std::make_unique<EqExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = EqExpAST::OpType::NEQ;
        (yyval.ast_ptr) = ast.release();
    }
#line 2652 "yacc.tab.c"
    break;

  case 108: /* LAndExp: EqExp  */
#line 969 "yacc.y"
          {
        auto ast = std::make_unique<LAndExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = LAndExpAST::OpType::NONE;
        (yyval.ast_ptr) = ast.release();
    }
#line 2663 "yacc.tab.c"
    break;

  case 109: /* LAndExp: LAndExp AND EqExp  */
#line 974 "yacc.y"
                          {
        auto ast = std::make_unique<LAndExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = LAndExpAST::OpType::AND;
        (yyval.ast_ptr) = ast.release();
    }
#line 2675 "yacc.tab.c"
    break;

  case 110: /* LOrExp: LAndExp  */
#line 985 "yacc.y"
            {
        auto ast = std::make_unique<LOrExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = LOrExpAST::OpType::NONE;
        (yyval.ast_ptr) = ast.release();
    }
#line 2686 "yacc.tab.c"
    break;

  case 111: /* LOrExp: LOrExp OR LAndExp  */
#line 990 "yacc.y"
                          {
        auto ast = std::make_unique<LOrExpAST>();
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        ast->op = LOrExpAST::OpType::OR;
        (yyval.ast_ptr) = ast.release();
    }
#line 2698 "yacc.tab.c"
    break;


#line 2702 "yacc.tab.c"

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

#line 999 "yacc.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
