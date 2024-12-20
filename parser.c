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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         _xkbcommon_parse
#define yylex           _xkbcommon_lex
#define yyerror         _xkbcommon_error
#define yydebug         _xkbcommon_debug
#define yynerrs         _xkbcommon_nerrs

/* First part of user prologue.  */

#include "config.h"

#include "xkbcomp/xkbcomp-priv.h"
#include "xkbcomp/ast-build.h"
#include "xkbcomp/parser-priv.h"
#include "scanner-utils.h"
#include "keysym.h"

struct parser_param {
    struct xkb_context *ctx;
    struct scanner *scanner;
    XkbFile *rtrn;
    bool more_maps;
};

#define parser_err(param, error_id, fmt, ...) \
    scanner_err_with_code((param)->scanner, error_id, fmt, ##__VA_ARGS__)

#define parser_warn(param, warning_id, fmt, ...) \
    scanner_warn_with_code((param)->scanner, warning_id, fmt, ##__VA_ARGS__)

static void
_xkbcommon_error(struct parser_param *param, const char *msg)
{
    parser_err(param, XKB_ERROR_INVALID_SYNTAX, "%s", msg);
}

static bool
resolve_keysym(const char *name, xkb_keysym_t *sym_rtrn)
{
    xkb_keysym_t sym;

    if (!name || istreq(name, "any") || istreq(name, "nosymbol")) {
        *sym_rtrn = XKB_KEY_NoSymbol;
        return true;
    }

    if (istreq(name, "none") || istreq(name, "voidsymbol")) {
        *sym_rtrn = XKB_KEY_VoidSymbol;
        return true;
    }

    sym = xkb_keysym_from_name(name, XKB_KEYSYM_NO_FLAGS);
    if (sym != XKB_KEY_NoSymbol) {
        *sym_rtrn = sym;
        return true;
    }

    return false;
}

#define param_scanner param->scanner


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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* END_OF_FILE  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ERROR_TOK = 3,                  /* ERROR_TOK  */
  YYSYMBOL_XKB_KEYMAP = 4,                 /* XKB_KEYMAP  */
  YYSYMBOL_XKB_KEYCODES = 5,               /* XKB_KEYCODES  */
  YYSYMBOL_XKB_TYPES = 6,                  /* XKB_TYPES  */
  YYSYMBOL_XKB_SYMBOLS = 7,                /* XKB_SYMBOLS  */
  YYSYMBOL_XKB_COMPATMAP = 8,              /* XKB_COMPATMAP  */
  YYSYMBOL_XKB_GEOMETRY = 9,               /* XKB_GEOMETRY  */
  YYSYMBOL_XKB_SEMANTICS = 10,             /* XKB_SEMANTICS  */
  YYSYMBOL_XKB_LAYOUT = 11,                /* XKB_LAYOUT  */
  YYSYMBOL_INCLUDE = 12,                   /* INCLUDE  */
  YYSYMBOL_OVERRIDE = 13,                  /* OVERRIDE  */
  YYSYMBOL_AUGMENT = 14,                   /* AUGMENT  */
  YYSYMBOL_REPLACE = 15,                   /* REPLACE  */
  YYSYMBOL_ALTERNATE = 16,                 /* ALTERNATE  */
  YYSYMBOL_VIRTUAL_MODS = 17,              /* VIRTUAL_MODS  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_INTERPRET = 19,                 /* INTERPRET  */
  YYSYMBOL_ACTION_TOK = 20,                /* ACTION_TOK  */
  YYSYMBOL_KEY = 21,                       /* KEY  */
  YYSYMBOL_ALIAS = 22,                     /* ALIAS  */
  YYSYMBOL_GROUP = 23,                     /* GROUP  */
  YYSYMBOL_MODIFIER_MAP = 24,              /* MODIFIER_MAP  */
  YYSYMBOL_INDICATOR = 25,                 /* INDICATOR  */
  YYSYMBOL_SHAPE = 26,                     /* SHAPE  */
  YYSYMBOL_KEYS = 27,                      /* KEYS  */
  YYSYMBOL_ROW = 28,                       /* ROW  */
  YYSYMBOL_SECTION = 29,                   /* SECTION  */
  YYSYMBOL_OVERLAY = 30,                   /* OVERLAY  */
  YYSYMBOL_TEXT = 31,                      /* TEXT  */
  YYSYMBOL_OUTLINE = 32,                   /* OUTLINE  */
  YYSYMBOL_SOLID = 33,                     /* SOLID  */
  YYSYMBOL_LOGO = 34,                      /* LOGO  */
  YYSYMBOL_VIRTUAL = 35,                   /* VIRTUAL  */
  YYSYMBOL_EQUALS = 36,                    /* EQUALS  */
  YYSYMBOL_PLUS = 37,                      /* PLUS  */
  YYSYMBOL_MINUS = 38,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 39,                    /* DIVIDE  */
  YYSYMBOL_TIMES = 40,                     /* TIMES  */
  YYSYMBOL_OBRACE = 41,                    /* OBRACE  */
  YYSYMBOL_CBRACE = 42,                    /* CBRACE  */
  YYSYMBOL_OPAREN = 43,                    /* OPAREN  */
  YYSYMBOL_CPAREN = 44,                    /* CPAREN  */
  YYSYMBOL_OBRACKET = 45,                  /* OBRACKET  */
  YYSYMBOL_CBRACKET = 46,                  /* CBRACKET  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_SEMI = 49,                      /* SEMI  */
  YYSYMBOL_EXCLAM = 50,                    /* EXCLAM  */
  YYSYMBOL_INVERT = 51,                    /* INVERT  */
  YYSYMBOL_STRING = 52,                    /* STRING  */
  YYSYMBOL_INTEGER = 53,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 54,                     /* FLOAT  */
  YYSYMBOL_IDENT = 55,                     /* IDENT  */
  YYSYMBOL_KEYNAME = 56,                   /* KEYNAME  */
  YYSYMBOL_PARTIAL = 57,                   /* PARTIAL  */
  YYSYMBOL_DEFAULT = 58,                   /* DEFAULT  */
  YYSYMBOL_HIDDEN = 59,                    /* HIDDEN  */
  YYSYMBOL_ALPHANUMERIC_KEYS = 60,         /* ALPHANUMERIC_KEYS  */
  YYSYMBOL_MODIFIER_KEYS = 61,             /* MODIFIER_KEYS  */
  YYSYMBOL_KEYPAD_KEYS = 62,               /* KEYPAD_KEYS  */
  YYSYMBOL_FUNCTION_KEYS = 63,             /* FUNCTION_KEYS  */
  YYSYMBOL_ALTERNATE_GROUP = 64,           /* ALTERNATE_GROUP  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_XkbFile = 66,                   /* XkbFile  */
  YYSYMBOL_XkbCompositeMap = 67,           /* XkbCompositeMap  */
  YYSYMBOL_XkbCompositeType = 68,          /* XkbCompositeType  */
  YYSYMBOL_XkbMapConfigList = 69,          /* XkbMapConfigList  */
  YYSYMBOL_XkbMapConfig = 70,              /* XkbMapConfig  */
  YYSYMBOL_FileType = 71,                  /* FileType  */
  YYSYMBOL_OptFlags = 72,                  /* OptFlags  */
  YYSYMBOL_Flags = 73,                     /* Flags  */
  YYSYMBOL_Flag = 74,                      /* Flag  */
  YYSYMBOL_DeclList = 75,                  /* DeclList  */
  YYSYMBOL_Decl = 76,                      /* Decl  */
  YYSYMBOL_VarDecl = 77,                   /* VarDecl  */
  YYSYMBOL_KeyNameDecl = 78,               /* KeyNameDecl  */
  YYSYMBOL_KeyAliasDecl = 79,              /* KeyAliasDecl  */
  YYSYMBOL_VModDecl = 80,                  /* VModDecl  */
  YYSYMBOL_VModDefList = 81,               /* VModDefList  */
  YYSYMBOL_VModDef = 82,                   /* VModDef  */
  YYSYMBOL_InterpretDecl = 83,             /* InterpretDecl  */
  YYSYMBOL_InterpretMatch = 84,            /* InterpretMatch  */
  YYSYMBOL_VarDeclList = 85,               /* VarDeclList  */
  YYSYMBOL_KeyTypeDecl = 86,               /* KeyTypeDecl  */
  YYSYMBOL_SymbolsDecl = 87,               /* SymbolsDecl  */
  YYSYMBOL_SymbolsBody = 88,               /* SymbolsBody  */
  YYSYMBOL_SymbolsVarDecl = 89,            /* SymbolsVarDecl  */
  YYSYMBOL_ArrayInit = 90,                 /* ArrayInit  */
  YYSYMBOL_GroupCompatDecl = 91,           /* GroupCompatDecl  */
  YYSYMBOL_ModMapDecl = 92,                /* ModMapDecl  */
  YYSYMBOL_LedMapDecl = 93,                /* LedMapDecl  */
  YYSYMBOL_LedNameDecl = 94,               /* LedNameDecl  */
  YYSYMBOL_ShapeDecl = 95,                 /* ShapeDecl  */
  YYSYMBOL_SectionDecl = 96,               /* SectionDecl  */
  YYSYMBOL_SectionBody = 97,               /* SectionBody  */
  YYSYMBOL_SectionBodyItem = 98,           /* SectionBodyItem  */
  YYSYMBOL_RowBody = 99,                   /* RowBody  */
  YYSYMBOL_RowBodyItem = 100,              /* RowBodyItem  */
  YYSYMBOL_Keys = 101,                     /* Keys  */
  YYSYMBOL_Key = 102,                      /* Key  */
  YYSYMBOL_OverlayDecl = 103,              /* OverlayDecl  */
  YYSYMBOL_OverlayKeyList = 104,           /* OverlayKeyList  */
  YYSYMBOL_OverlayKey = 105,               /* OverlayKey  */
  YYSYMBOL_OutlineList = 106,              /* OutlineList  */
  YYSYMBOL_OutlineInList = 107,            /* OutlineInList  */
  YYSYMBOL_CoordList = 108,                /* CoordList  */
  YYSYMBOL_Coord = 109,                    /* Coord  */
  YYSYMBOL_DoodadDecl = 110,               /* DoodadDecl  */
  YYSYMBOL_DoodadType = 111,               /* DoodadType  */
  YYSYMBOL_FieldSpec = 112,                /* FieldSpec  */
  YYSYMBOL_Element = 113,                  /* Element  */
  YYSYMBOL_OptMergeMode = 114,             /* OptMergeMode  */
  YYSYMBOL_MergeMode = 115,                /* MergeMode  */
  YYSYMBOL_OptExprList = 116,              /* OptExprList  */
  YYSYMBOL_ExprList = 117,                 /* ExprList  */
  YYSYMBOL_Expr = 118,                     /* Expr  */
  YYSYMBOL_Term = 119,                     /* Term  */
  YYSYMBOL_ActionList = 120,               /* ActionList  */
  YYSYMBOL_Action = 121,                   /* Action  */
  YYSYMBOL_Lhs = 122,                      /* Lhs  */
  YYSYMBOL_Terminal = 123,                 /* Terminal  */
  YYSYMBOL_OptKeySymList = 124,            /* OptKeySymList  */
  YYSYMBOL_KeySymList = 125,               /* KeySymList  */
  YYSYMBOL_KeySyms = 126,                  /* KeySyms  */
  YYSYMBOL_KeySym = 127,                   /* KeySym  */
  YYSYMBOL_SignedNumber = 128,             /* SignedNumber  */
  YYSYMBOL_Number = 129,                   /* Number  */
  YYSYMBOL_Float = 130,                    /* Float  */
  YYSYMBOL_Integer = 131,                  /* Integer  */
  YYSYMBOL_KeyCode = 132,                  /* KeyCode  */
  YYSYMBOL_Ident = 133,                    /* Ident  */
  YYSYMBOL_String = 134,                   /* String  */
  YYSYMBOL_OptMapName = 135,               /* OptMapName  */
  YYSYMBOL_MapName = 136                   /* MapName  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   735

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  334

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   257


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
       0,     4,     5,     6,     7,     8,     9,    10,    11,     2,
      12,    13,    14,    15,    16,     2,     2,     2,     2,     2,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     2,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     2,     2,     2,     2,
      52,    53,    54,    55,    56,     2,     2,     2,     2,     2,
      57,    58,    59,    60,    61,    62,    63,    64,     2,     2,
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
       2,     2,     2,     2,     2,     3,     1,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   255,   255,   257,   259,   263,   269,   270,   271,   274,
     276,   280,   288,   289,   290,   291,   292,   295,   296,   299,
     300,   303,   304,   305,   306,   307,   308,   309,   310,   313,
     328,   338,   341,   347,   352,   357,   362,   367,   372,   377,
     382,   387,   392,   393,   394,   395,   402,   404,   406,   410,
     414,   418,   422,   424,   428,   430,   434,   440,   442,   446,
     448,   452,   458,   464,   466,   470,   471,   472,   473,   474,
     477,   479,   483,   487,   491,   495,   497,   501,   503,   507,
     511,   512,   515,   517,   519,   521,   523,   527,   528,   531,
     532,   536,   537,   540,   542,   546,   550,   551,   554,   557,
     559,   563,   565,   567,   571,   573,   577,   581,   585,   586,
     587,   588,   591,   592,   595,   597,   599,   601,   603,   605,
     607,   609,   611,   613,   615,   619,   620,   623,   624,   625,
     626,   627,   637,   638,   641,   643,   647,   649,   651,   653,
     655,   657,   661,   663,   665,   667,   669,   671,   673,   675,
     679,   681,   685,   689,   691,   693,   695,   699,   701,   703,
     705,   709,   710,   713,   715,   717,   719,   723,   727,   740,
     741,   776,   777,   780,   781,   784,   787,   790,   793,   794,
     797,   800,   801,   804
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
  "END_OF_FILE", "error", "\"invalid token\"", "ERROR_TOK", "XKB_KEYMAP",
  "XKB_KEYCODES", "XKB_TYPES", "XKB_SYMBOLS", "XKB_COMPATMAP",
  "XKB_GEOMETRY", "XKB_SEMANTICS", "XKB_LAYOUT", "INCLUDE", "OVERRIDE",
  "AUGMENT", "REPLACE", "ALTERNATE", "VIRTUAL_MODS", "TYPE", "INTERPRET",
  "ACTION_TOK", "KEY", "ALIAS", "GROUP", "MODIFIER_MAP", "INDICATOR",
  "SHAPE", "KEYS", "ROW", "SECTION", "OVERLAY", "TEXT", "OUTLINE", "SOLID",
  "LOGO", "VIRTUAL", "EQUALS", "PLUS", "MINUS", "DIVIDE", "TIMES",
  "OBRACE", "CBRACE", "OPAREN", "CPAREN", "OBRACKET", "CBRACKET", "DOT",
  "COMMA", "SEMI", "EXCLAM", "INVERT", "STRING", "INTEGER", "FLOAT",
  "IDENT", "KEYNAME", "PARTIAL", "DEFAULT", "HIDDEN", "ALPHANUMERIC_KEYS",
  "MODIFIER_KEYS", "KEYPAD_KEYS", "FUNCTION_KEYS", "ALTERNATE_GROUP",
  "$accept", "XkbFile", "XkbCompositeMap", "XkbCompositeType",
  "XkbMapConfigList", "XkbMapConfig", "FileType", "OptFlags", "Flags",
  "Flag", "DeclList", "Decl", "VarDecl", "KeyNameDecl", "KeyAliasDecl",
  "VModDecl", "VModDefList", "VModDef", "InterpretDecl", "InterpretMatch",
  "VarDeclList", "KeyTypeDecl", "SymbolsDecl", "SymbolsBody",
  "SymbolsVarDecl", "ArrayInit", "GroupCompatDecl", "ModMapDecl",
  "LedMapDecl", "LedNameDecl", "ShapeDecl", "SectionDecl", "SectionBody",
  "SectionBodyItem", "RowBody", "RowBodyItem", "Keys", "Key",
  "OverlayDecl", "OverlayKeyList", "OverlayKey", "OutlineList",
  "OutlineInList", "CoordList", "Coord", "DoodadDecl", "DoodadType",
  "FieldSpec", "Element", "OptMergeMode", "MergeMode", "OptExprList",
  "ExprList", "Expr", "Term", "ActionList", "Action", "Lhs", "Terminal",
  "OptKeySymList", "KeySymList", "KeySyms", "KeySym", "SignedNumber",
  "Number", "Float", "Integer", "KeyCode", "Ident", "String", "OptMapName",
  "MapName", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-179)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     176,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
       6,  -182,  -182,   271,   227,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,   -38,   -38,  -182,  -182,   -24,
    -182,    33,   227,  -182,   210,  -182,   353,    44,     5,  -182,
    -182,  -182,  -182,  -182,  -182,    32,  -182,    13,    41,  -182,
    -182,   -48,    55,    11,  -182,    79,    87,    58,   -48,    -2,
      55,  -182,    55,    72,  -182,  -182,  -182,   107,   -48,  -182,
     110,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,    55,   -18,  -182,   127,
     121,  -182,    66,  -182,   138,  -182,   136,  -182,  -182,  -182,
     144,   147,  -182,   152,   180,   182,   178,   184,   187,   188,
     190,    58,   198,   201,   214,   367,   677,   367,  -182,   -48,
    -182,   367,   663,   663,   367,   494,   200,   367,   367,   367,
     663,    68,   449,   223,  -182,  -182,   212,   663,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,   367,   367,   367,
     367,   367,  -182,  -182,    57,   157,  -182,   224,  -182,  -182,
    -182,  -182,  -182,   218,    91,  -182,   333,  -182,   509,   537,
     333,   552,   -48,     1,  -182,  -182,   228,    40,   216,   143,
      70,   333,   150,   593,   247,   -30,    97,  -182,   105,  -182,
     261,    55,   259,    55,  -182,  -182,   408,  -182,  -182,  -182,
     367,  -182,   608,  -182,  -182,  -182,   287,  -182,  -182,   367,
     367,   367,   367,   367,  -182,   367,   367,  -182,   252,  -182,
     253,   264,    24,   269,   272,   163,  -182,   273,   270,  -182,
    -182,  -182,   280,   494,   285,  -182,  -182,   283,   367,  -182,
     284,   112,     8,  -182,  -182,   294,  -182,   299,   -36,   304,
     247,   326,   649,   279,   307,  -182,   204,   316,  -182,   322,
     320,   111,   111,  -182,  -182,   333,   211,  -182,  -182,   116,
     367,  -182,   677,  -182,    24,  -182,  -182,  -182,   333,  -182,
     333,  -182,  -182,  -182,   -30,  -182,  -182,  -182,  -182,   247,
     333,   334,  -182,   466,  -182,   318,  -182,  -182,  -182,  -182,
    -182,  -182,   339,  -182,  -182,  -182,   343,   120,    14,   345,
    -182,   361,   124,  -182,  -182,  -182,  -182,   367,  -182,   131,
    -182,  -182,   344,   350,   318,   166,   352,    14,  -182,  -182,
    -182,  -182,  -182,  -182
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      18,     4,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     2,     3,     0,    17,    20,     1,     6,    12,    13,
      15,    14,    16,     7,     8,   182,   182,    19,   183,     0,
     181,     0,    18,    31,    18,    10,     0,   126,     0,     9,
     127,   129,   128,   130,   131,     0,    29,     0,   125,     5,
      11,     0,   116,   115,   114,   117,     0,   118,   119,   120,
     121,   122,   123,   124,   109,   110,   111,     0,     0,   178,
       0,   179,    32,    34,    35,    30,    33,    36,    37,    39,
      38,    40,    41,    42,    43,    44,     0,   153,   113,     0,
     112,    45,     0,    53,    54,   180,     0,   169,   176,   168,
       0,    58,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,   177,     0,     0,   116,   115,
     117,   118,   119,   120,   121,   123,   124,     0,     0,     0,
       0,     0,   175,   160,   153,     0,   141,   146,   148,   159,
     158,   112,   157,   154,     0,    52,    55,    60,     0,     0,
      57,   162,     0,     0,    64,    69,     0,   112,     0,     0,
       0,   135,     0,     0,     0,     0,     0,   100,     0,   105,
       0,   120,   122,     0,    83,    85,     0,    81,    86,    84,
       0,    49,     0,   143,   146,   142,     0,   144,   145,   133,
       0,     0,     0,     0,   155,     0,     0,    46,     0,    59,
       0,   169,     0,   168,     0,     0,   151,     0,   161,   166,
     165,    68,     0,     0,     0,    50,    72,     0,     0,    75,
       0,     0,     0,   174,   173,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,   149,     0,
     132,   137,   138,   136,   139,   140,     0,    61,    56,     0,
     133,    71,     0,    70,     0,    62,    63,    66,    65,    73,
     134,    74,   101,   171,     0,    77,    99,    78,   104,     0,
     103,     0,    90,     0,    88,     0,    79,    76,   107,   147,
     156,   167,     0,   150,   164,   163,     0,     0,     0,     0,
      87,     0,     0,    97,   152,   106,   102,     0,    93,     0,
      92,    82,     0,     0,     0,     0,     0,     0,    98,    95,
      96,    94,    89,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,  -182,  -182,  -182,   181,  -182,   402,  -182,   389,
    -182,  -182,   -35,  -182,  -182,  -182,  -182,   288,  -182,  -182,
     -50,  -182,  -182,  -182,   173,   174,  -182,  -182,   362,  -182,
    -182,  -182,  -182,   215,  -182,   119,  -182,    86,  -182,  -182,
      90,  -182,   167,  -181,   185,   369,  -182,   -27,  -182,  -182,
    -182,   154,  -126,    83,    76,  -182,   158,   -31,  -182,  -182,
     221,   170,   -52,   161,   205,  -182,   -44,  -182,   -47,   -34,
     420,  -182
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    11,    25,    34,    12,    26,    36,    14,    15,
      37,    46,   167,    73,    74,    75,    92,    93,    76,   100,
     168,    77,    78,   173,   174,   175,    79,    80,   195,    82,
      83,    84,   196,   197,   293,   294,   319,   320,   198,   312,
     313,   186,   187,   188,   189,   199,    86,   154,    88,    47,
      48,   259,   260,   181,   156,   225,   226,   157,   158,   227,
     228,   229,   230,   245,   246,   159,   160,   136,   161,   162,
      29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,   101,   180,   241,    94,   184,    16,    69,   242,   102,
      71,   106,    72,   105,    28,   107,    89,    32,    96,    69,
      87,   112,    71,   243,   244,   108,   109,   115,   110,   116,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      97,    61,    62,   232,    63,    64,    65,    66,    67,   233,
      95,    98,   114,    97,    49,   317,    40,    41,    42,    43,
      44,   243,   244,    68,    98,   222,    99,   133,    69,    70,
     318,    71,    94,   169,    33,    90,    90,    98,   177,    99,
     183,    50,   -67,    90,   190,    90,    45,   202,   -67,   163,
      90,    89,    89,    91,   176,    87,    87,   194,    87,    89,
     209,    89,   115,    87,   116,    87,    89,    95,   307,   184,
      87,    98,   237,   185,   119,   120,   204,   204,   238,   204,
     204,    90,    90,    69,  -108,   231,    71,   102,   210,   211,
     212,   213,   111,   219,   219,   103,    90,    89,    89,   247,
     217,    87,    87,   104,   224,   248,   113,   249,   219,    90,
     212,   213,    89,   250,   282,    90,    87,   108,   301,   253,
     250,   194,   316,   117,   274,    89,   323,   219,   250,    87,
     118,    89,   324,   326,   121,    87,     1,   122,   102,   327,
     210,   211,   212,   213,   124,   123,   177,   210,   211,   212,
     213,   325,   236,   125,   210,   211,   212,   213,   155,   239,
     164,   190,   176,   214,   166,    90,    87,   170,   331,   271,
     179,   272,   182,    35,   238,    39,   126,   292,   127,   128,
     129,    89,   305,   203,   205,    87,   207,   208,   130,   131,
     102,   132,   206,     2,     3,     4,     5,     6,     7,     8,
       9,   210,   211,   212,   213,   224,    90,   134,   210,   211,
     212,   213,    38,   297,   135,   137,   178,   300,   292,   200,
     215,   201,    89,   216,   234,   235,    87,     2,     3,     4,
       5,     6,     7,     8,     9,    17,    18,    19,    20,    21,
      22,    23,    24,   256,     2,     3,     4,     5,     6,     7,
       8,     9,   185,   261,   262,   263,   264,   251,   265,   266,
     252,   267,   268,   138,   139,    54,   140,  -123,   141,   142,
     143,   144,  -178,    61,   145,   270,   146,   278,   274,   273,
     295,   280,   147,   148,   210,   211,   212,   213,   149,   275,
     171,   258,   279,   281,   290,   150,   151,    95,    98,   152,
      69,   153,   284,    71,   138,   139,    54,   140,   285,   141,
     142,   143,   144,   287,    61,   145,   296,   146,    18,    19,
      20,    21,    22,   147,   148,   298,   299,   289,   238,   149,
     210,   211,   212,   213,   311,   308,   150,   151,    95,    98,
     152,    69,   153,   314,    71,   138,   139,    54,   140,   315,
     141,   142,   143,   144,   321,    61,   145,   322,   146,   329,
     328,   332,    13,    27,   147,   148,   276,   165,   277,    81,
     149,   255,   310,   333,   330,   286,    85,   150,   151,    95,
      98,   152,    69,   153,   302,    71,   138,   139,    54,   140,
     303,   141,   142,   191,   144,   288,   192,   145,   193,    63,
      64,    65,    66,   269,   304,   306,    31,   283,     0,     0,
     254,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,    69,     0,     0,    71,   138,   139,    54,
     140,     0,   141,   142,   191,   144,     0,   192,   145,   193,
      63,    64,    65,    66,   138,   139,    54,   140,     0,   141,
     142,   143,   144,   291,    61,   145,     0,   146,     0,    68,
       0,     0,     0,     0,    69,     0,     0,    71,   309,     0,
       0,     0,   138,   139,    54,   140,    68,   141,   142,   143,
     144,    69,    61,   145,    71,   146,     0,   138,   139,    54,
     140,     0,   141,   142,   143,   144,     0,    61,   145,   171,
     146,     0,     0,     0,   172,     0,     0,     0,     0,    69,
       0,   218,    71,     0,     0,   138,   139,    54,   140,    68,
     141,   142,   143,   144,    69,    61,   145,    71,   146,     0,
     138,   139,    54,   140,     0,   141,   142,   143,   144,   220,
      61,   221,     0,   146,     0,     0,     0,    68,     0,     0,
       0,     0,    69,   222,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,   223,     0,     0,
      71,   138,   139,    54,   140,     0,   141,   142,   143,   144,
       0,    61,   145,     0,   146,     0,   138,   139,    54,   140,
       0,   141,   142,   143,   144,   240,    61,   145,     0,   146,
       0,     0,     0,    68,     0,     0,     0,     0,    69,     0,
     257,    71,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,    69,     0,     0,    71,   138,   139,    54,
     140,     0,   141,   142,   143,   144,   291,    61,   145,     0,
     146,   138,   139,    54,   140,     0,   141,   142,   143,   144,
       0,    61,   145,     0,   146,   138,   139,    54,   140,    68,
     141,   142,   143,   144,    69,    61,   145,    71,   146,     0,
       0,     0,     0,    68,     0,     0,     0,     0,    69,     0,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,    71
};

static const yytype_int16 yycheck[] =
{
      47,    53,   128,   184,    51,    41,     0,    55,    38,    53,
      58,    58,    47,    57,    52,    59,    47,    41,    52,    55,
      47,    68,    58,    53,    54,    59,    60,    45,    62,    47,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      29,    28,    29,    42,    31,    32,    33,    34,    35,    48,
      52,    53,    86,    29,    49,    41,    12,    13,    14,    15,
      16,    53,    54,    50,    53,    41,    55,   111,    55,    56,
      56,    58,   119,   123,    41,   122,   123,    53,   125,    55,
     130,    49,    42,   130,   131,   132,    42,   137,    48,   116,
     137,   122,   123,    52,   125,   122,   123,   132,   125,   130,
      43,   132,    45,   130,    47,   132,   137,    52,   289,    41,
     137,    53,    42,    45,    48,    49,   147,   148,    48,   150,
     151,   168,   169,    55,    52,   172,    58,   171,    37,    38,
      39,    40,    25,   168,   169,    56,   183,   168,   169,    42,
      49,   168,   169,    56,   171,    48,    36,    42,   183,   196,
      39,    40,   183,    48,    42,   202,   183,   191,    42,   193,
      48,   196,    42,    36,    48,   196,    42,   202,    48,   196,
      49,   202,    48,    42,    36,   202,     0,    41,   222,    48,
      37,    38,    39,    40,    37,    41,   233,    37,    38,    39,
      40,   317,    49,    41,    37,    38,    39,    40,   115,    49,
     117,   248,   233,    46,   121,   252,   233,   124,    42,    46,
     127,    48,   129,    32,    48,    34,    36,   252,    36,    41,
      36,   252,   274,   147,   148,   252,   150,   151,    41,    41,
     274,    41,   149,    57,    58,    59,    60,    61,    62,    63,
      64,    37,    38,    39,    40,   272,   293,    49,    37,    38,
      39,    40,    42,    49,    53,    41,    56,    46,   293,    36,
      36,    49,   293,    45,    36,    49,   293,    57,    58,    59,
      60,    61,    62,    63,    64,     4,     5,     6,     7,     8,
       9,    10,    11,   200,    57,    58,    59,    60,    61,    62,
      63,    64,    45,   210,   211,   212,   213,    36,   215,   216,
      41,    49,    49,    18,    19,    20,    21,    43,    23,    24,
      25,    26,    43,    28,    29,    43,    31,   234,    48,    46,
      41,   238,    37,    38,    37,    38,    39,    40,    43,    49,
      45,    44,    49,    49,   251,    50,    51,    52,    53,    54,
      55,    56,    48,    58,    18,    19,    20,    21,    49,    23,
      24,    25,    26,    49,    28,    29,    49,    31,     5,     6,
       7,     8,     9,    37,    38,    49,    44,    41,    48,    43,
      37,    38,    39,    40,    56,    41,    50,    51,    52,    53,
      54,    55,    56,    44,    58,    18,    19,    20,    21,    46,
      23,    24,    25,    26,    49,    28,    29,    36,    31,    49,
      56,    49,     0,    14,    37,    38,   233,   119,   234,    47,
      43,   196,   293,   327,   324,   248,    47,    50,    51,    52,
      53,    54,    55,    56,   270,    58,    18,    19,    20,    21,
     272,    23,    24,    25,    26,   250,    28,    29,    30,    31,
      32,    33,    34,   222,   274,   284,    26,   242,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    42,    -1,
      -1,    -1,    18,    19,    20,    21,    50,    23,    24,    25,
      26,    55,    28,    29,    58,    31,    -1,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    -1,    28,    29,    45,
      31,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,
      -1,    42,    58,    -1,    -1,    18,    19,    20,    21,    50,
      23,    24,    25,    26,    55,    28,    29,    58,    31,    -1,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    42,
      28,    29,    -1,    31,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    55,    41,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,
      58,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      -1,    28,    29,    -1,    31,    -1,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    42,    28,    29,    -1,    31,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      42,    58,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      -1,    28,    29,    -1,    31,    18,    19,    20,    21,    50,
      23,    24,    25,    26,    55,    28,    29,    58,    31,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      66,    67,    70,    72,    73,    74,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    68,    71,    74,    52,   135,
     136,   135,    41,    41,    69,    70,    72,    75,    42,    70,
      12,    13,    14,    15,    16,    42,    76,   114,   115,    49,
      49,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    28,    29,    31,    32,    33,    34,    35,    50,    55,
      56,    58,    77,    78,    79,    80,    83,    86,    87,    91,
      92,    93,    94,    95,    96,   110,   111,   112,   113,   122,
     133,    52,    81,    82,   133,    52,   134,    29,    53,    55,
      84,   127,   131,    56,    56,   131,   133,   131,   134,   134,
     134,    25,   133,    36,   134,    45,    47,    36,    49,    48,
      49,    36,    41,    41,    37,    41,    36,    36,    41,    36,
      41,    41,    41,   131,    49,    53,   132,    41,    18,    19,
      21,    23,    24,    25,    26,    29,    31,    37,    38,    43,
      50,    51,    54,    56,   112,   118,   119,   122,   123,   130,
     131,   133,   134,   112,   118,    82,   118,    77,    85,    85,
     118,    45,    50,    88,    89,    90,   122,   133,    56,   118,
     117,   118,   118,    85,    41,    45,   106,   107,   108,   109,
     133,    25,    28,    30,    77,    93,    97,    98,   103,   110,
      36,    49,    85,   119,   122,   119,   118,   119,   119,    43,
      37,    38,    39,    40,    46,    36,    45,    49,    42,    77,
      42,    29,    41,    55,   112,   120,   121,   124,   125,   126,
     127,   133,    42,    48,    36,    49,    49,    42,    48,    49,
      42,   108,    38,    53,    54,   128,   129,    42,    48,    42,
      48,    36,    41,   134,    42,    98,   118,    42,    44,   116,
     117,   118,   118,   118,   118,   118,   118,    49,    49,   125,
      43,    46,    48,    46,    48,    49,    89,    90,   118,    49,
     118,    49,    42,   129,    48,    49,   107,    49,   109,    41,
     118,    27,    77,    99,   100,    41,    49,    49,    49,    44,
      46,    42,   116,   121,   126,   127,   128,   108,    41,    42,
     100,    56,   104,   105,    44,    46,    42,    41,    56,   101,
     102,    49,    36,    42,    48,   117,    42,    48,    56,    49,
     105,    42,    49,   102
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    67,    68,    68,    68,    69,
      69,    70,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    78,
      79,    80,    81,    81,    82,    82,    83,    84,    84,    85,
      85,    86,    87,    88,    88,    89,    89,    89,    89,    89,
      90,    90,    91,    92,    93,    94,    94,    95,    95,    96,
      97,    97,    98,    98,    98,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   104,   104,   105,   106,
     106,   107,   107,   107,   108,   108,   109,   110,   111,   111,
     111,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   115,   115,   115,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   121,   122,   122,   122,   122,   123,   123,   123,
     123,   124,   124,   125,   125,   125,   125,   126,   127,   127,
     127,   128,   128,   129,   129,   130,   131,   132,   133,   133,
     134,   135,   135,   136
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     7,     1,     1,     1,     2,
       1,     7,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     2,     3,     4,
       5,     3,     3,     1,     1,     3,     6,     3,     1,     2,
       1,     6,     6,     3,     1,     3,     3,     1,     2,     1,
       3,     3,     5,     6,     6,     5,     6,     6,     6,     6,
       2,     1,     5,     1,     1,     1,     1,     2,     1,     5,
       1,     3,     1,     1,     3,     6,     3,     1,     3,     3,
       1,     3,     5,     3,     3,     1,     5,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     3,     3,     3,     3,
       3,     1,     2,     2,     2,     2,     1,     4,     1,     3,
       3,     1,     4,     1,     3,     4,     6,     1,     1,     1,
       1,     1,     0,     3,     3,     1,     1,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1
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
        yyerror (param, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, param); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct parser_param *param)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (param);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct parser_param *param)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, param);
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
                 int yyrule, struct parser_param *param)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], param);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, param); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, struct parser_param *param)
{
  YY_USE (yyvaluep);
  YY_USE (param);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_STRING: /* STRING  */
            { free(((*yyvaluep).str)); }
        break;

    case YYSYMBOL_IDENT: /* IDENT  */
            { free(((*yyvaluep).str)); }
        break;

    case YYSYMBOL_XkbFile: /* XkbFile  */
            { if (!param->rtrn) FreeXkbFile(((*yyvaluep).file)); }
        break;

    case YYSYMBOL_XkbCompositeMap: /* XkbCompositeMap  */
            { if (!param->rtrn) FreeXkbFile(((*yyvaluep).file)); }
        break;

    case YYSYMBOL_XkbMapConfigList: /* XkbMapConfigList  */
            { FreeXkbFile(((*yyvaluep).fileList).head); }
        break;

    case YYSYMBOL_XkbMapConfig: /* XkbMapConfig  */
            { if (!param->rtrn) FreeXkbFile(((*yyvaluep).file)); }
        break;

    case YYSYMBOL_DeclList: /* DeclList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).anyList).head); }
        break;

    case YYSYMBOL_Decl: /* Decl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).any)); }
        break;

    case YYSYMBOL_VarDecl: /* VarDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).var)); }
        break;

    case YYSYMBOL_KeyNameDecl: /* KeyNameDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).keyCode)); }
        break;

    case YYSYMBOL_KeyAliasDecl: /* KeyAliasDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).keyAlias)); }
        break;

    case YYSYMBOL_VModDecl: /* VModDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).vmodList).head); }
        break;

    case YYSYMBOL_VModDefList: /* VModDefList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).vmodList).head); }
        break;

    case YYSYMBOL_VModDef: /* VModDef  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).vmod)); }
        break;

    case YYSYMBOL_InterpretDecl: /* InterpretDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).interp)); }
        break;

    case YYSYMBOL_InterpretMatch: /* InterpretMatch  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).interp)); }
        break;

    case YYSYMBOL_VarDeclList: /* VarDeclList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).varList).head); }
        break;

    case YYSYMBOL_KeyTypeDecl: /* KeyTypeDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).keyType)); }
        break;

    case YYSYMBOL_SymbolsDecl: /* SymbolsDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).syms)); }
        break;

    case YYSYMBOL_SymbolsBody: /* SymbolsBody  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).varList).head); }
        break;

    case YYSYMBOL_SymbolsVarDecl: /* SymbolsVarDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).var)); }
        break;

    case YYSYMBOL_ArrayInit: /* ArrayInit  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_GroupCompatDecl: /* GroupCompatDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).groupCompat)); }
        break;

    case YYSYMBOL_ModMapDecl: /* ModMapDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).modMask)); }
        break;

    case YYSYMBOL_LedMapDecl: /* LedMapDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).ledMap)); }
        break;

    case YYSYMBOL_LedNameDecl: /* LedNameDecl  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).ledName)); }
        break;

    case YYSYMBOL_CoordList: /* CoordList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_Coord: /* Coord  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_OptExprList: /* OptExprList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
        break;

    case YYSYMBOL_ExprList: /* ExprList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
        break;

    case YYSYMBOL_Expr: /* Expr  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_Term: /* Term  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_ActionList: /* ActionList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).exprList).head); }
        break;

    case YYSYMBOL_Action: /* Action  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_Lhs: /* Lhs  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_Terminal: /* Terminal  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_OptKeySymList: /* OptKeySymList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_KeySymList: /* KeySymList  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_KeySyms: /* KeySyms  */
            { FreeStmt((ParseCommon *) ((*yyvaluep).expr)); }
        break;

    case YYSYMBOL_OptMapName: /* OptMapName  */
            { free(((*yyvaluep).str)); }
        break;

    case YYSYMBOL_MapName: /* MapName  */
            { free(((*yyvaluep).str)); }
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct parser_param *param)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, param_scanner);
    }

  if (yychar <= END_OF_FILE)
    {
      yychar = END_OF_FILE;
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
  case 2: /* XkbFile: XkbCompositeMap  */
                        { (yyval.file) = param->rtrn = (yyvsp[0].file); param->more_maps = !!param->rtrn; }
    break;

  case 3: /* XkbFile: XkbMapConfig  */
                        { (yyval.file) = param->rtrn = (yyvsp[0].file); param->more_maps = !!param->rtrn; YYACCEPT; }
    break;

  case 4: /* XkbFile: END_OF_FILE  */
                        { (yyval.file) = param->rtrn = NULL; param->more_maps = false; }
    break;

  case 5: /* XkbCompositeMap: OptFlags XkbCompositeType OptMapName OBRACE XkbMapConfigList CBRACE SEMI  */
                        { (yyval.file) = XkbFileCreate((yyvsp[-5].file_type), (yyvsp[-4].str), (ParseCommon *) (yyvsp[-2].fileList).head, (yyvsp[-6].mapFlags)); }
    break;

  case 6: /* XkbCompositeType: XKB_KEYMAP  */
                                        { (yyval.file_type) = FILE_TYPE_KEYMAP; }
    break;

  case 7: /* XkbCompositeType: XKB_SEMANTICS  */
                                        { (yyval.file_type) = FILE_TYPE_KEYMAP; }
    break;

  case 8: /* XkbCompositeType: XKB_LAYOUT  */
                                        { (yyval.file_type) = FILE_TYPE_KEYMAP; }
    break;

  case 9: /* XkbMapConfigList: XkbMapConfigList XkbMapConfig  */
                        { (yyval.fileList).head = (yyvsp[-1].fileList).head; (yyval.fileList).last->common.next = &(yyvsp[0].file)->common; (yyval.fileList).last = (yyvsp[0].file); }
    break;

  case 10: /* XkbMapConfigList: XkbMapConfig  */
                        { (yyval.fileList).head = (yyval.fileList).last = (yyvsp[0].file); }
    break;

  case 11: /* XkbMapConfig: OptFlags FileType OptMapName OBRACE DeclList CBRACE SEMI  */
                        {
                            (yyval.file) = XkbFileCreate((yyvsp[-5].file_type), (yyvsp[-4].str), (yyvsp[-2].anyList).head, (yyvsp[-6].mapFlags));
                        }
    break;

  case 12: /* FileType: XKB_KEYCODES  */
                                                { (yyval.file_type) = FILE_TYPE_KEYCODES; }
    break;

  case 13: /* FileType: XKB_TYPES  */
                                                { (yyval.file_type) = FILE_TYPE_TYPES; }
    break;

  case 14: /* FileType: XKB_COMPATMAP  */
                                                { (yyval.file_type) = FILE_TYPE_COMPAT; }
    break;

  case 15: /* FileType: XKB_SYMBOLS  */
                                                { (yyval.file_type) = FILE_TYPE_SYMBOLS; }
    break;

  case 16: /* FileType: XKB_GEOMETRY  */
                                                { (yyval.file_type) = FILE_TYPE_GEOMETRY; }
    break;

  case 17: /* OptFlags: Flags  */
                                                { (yyval.mapFlags) = (yyvsp[0].mapFlags); }
    break;

  case 18: /* OptFlags: %empty  */
                                                { (yyval.mapFlags) = 0; }
    break;

  case 19: /* Flags: Flags Flag  */
                                                { (yyval.mapFlags) = ((yyvsp[-1].mapFlags) | (yyvsp[0].mapFlags)); }
    break;

  case 20: /* Flags: Flag  */
                                                { (yyval.mapFlags) = (yyvsp[0].mapFlags); }
    break;

  case 21: /* Flag: PARTIAL  */
                                                { (yyval.mapFlags) = MAP_IS_PARTIAL; }
    break;

  case 22: /* Flag: DEFAULT  */
                                                { (yyval.mapFlags) = MAP_IS_DEFAULT; }
    break;

  case 23: /* Flag: HIDDEN  */
                                                { (yyval.mapFlags) = MAP_IS_HIDDEN; }
    break;

  case 24: /* Flag: ALPHANUMERIC_KEYS  */
                                                { (yyval.mapFlags) = MAP_HAS_ALPHANUMERIC; }
    break;

  case 25: /* Flag: MODIFIER_KEYS  */
                                                { (yyval.mapFlags) = MAP_HAS_MODIFIER; }
    break;

  case 26: /* Flag: KEYPAD_KEYS  */
                                                { (yyval.mapFlags) = MAP_HAS_KEYPAD; }
    break;

  case 27: /* Flag: FUNCTION_KEYS  */
                                                { (yyval.mapFlags) = MAP_HAS_FN; }
    break;

  case 28: /* Flag: ALTERNATE_GROUP  */
                                                { (yyval.mapFlags) = MAP_IS_ALTGR; }
    break;

  case 29: /* DeclList: DeclList Decl  */
                        {
                            if ((yyvsp[0].any)) {
                                if ((yyvsp[-1].anyList).head) {
                                    (yyval.anyList).head = (yyvsp[-1].anyList).head; (yyvsp[-1].anyList).last->next = (yyvsp[0].any); (yyval.anyList).last = (yyvsp[0].any);
                                } else {
                                    (yyval.anyList).head = (yyval.anyList).last = (yyvsp[0].any);
                                }
                            }
                        }
    break;

  case 30: /* DeclList: DeclList OptMergeMode VModDecl  */
                        {
                            for (VModDef *vmod = (yyvsp[0].vmodList).head; vmod; vmod = (VModDef *) vmod->common.next)
                                vmod->merge = (yyvsp[-1].merge);
                            if ((yyvsp[-2].anyList).head) {
                                (yyval.anyList).head = (yyvsp[-2].anyList).head; (yyvsp[-2].anyList).last->next = &(yyvsp[0].vmodList).head->common; (yyval.anyList).last = &(yyvsp[0].vmodList).last->common;
                            } else {
                                (yyval.anyList).head = &(yyvsp[0].vmodList).head->common; (yyval.anyList).last = &(yyvsp[0].vmodList).last->common;
                            }
                        }
    break;

  case 31: /* DeclList: %empty  */
                        { (yyval.anyList).head = (yyval.anyList).last = NULL; }
    break;

  case 32: /* Decl: OptMergeMode VarDecl  */
                        {
                            (yyvsp[0].var)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].var);
                        }
    break;

  case 33: /* Decl: OptMergeMode InterpretDecl  */
                        {
                            (yyvsp[0].interp)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].interp);
                        }
    break;

  case 34: /* Decl: OptMergeMode KeyNameDecl  */
                        {
                            (yyvsp[0].keyCode)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].keyCode);
                        }
    break;

  case 35: /* Decl: OptMergeMode KeyAliasDecl  */
                        {
                            (yyvsp[0].keyAlias)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].keyAlias);
                        }
    break;

  case 36: /* Decl: OptMergeMode KeyTypeDecl  */
                        {
                            (yyvsp[0].keyType)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].keyType);
                        }
    break;

  case 37: /* Decl: OptMergeMode SymbolsDecl  */
                        {
                            (yyvsp[0].syms)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].syms);
                        }
    break;

  case 38: /* Decl: OptMergeMode ModMapDecl  */
                        {
                            (yyvsp[0].modMask)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].modMask);
                        }
    break;

  case 39: /* Decl: OptMergeMode GroupCompatDecl  */
                        {
                            (yyvsp[0].groupCompat)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].groupCompat);
                        }
    break;

  case 40: /* Decl: OptMergeMode LedMapDecl  */
                        {
                            (yyvsp[0].ledMap)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].ledMap);
                        }
    break;

  case 41: /* Decl: OptMergeMode LedNameDecl  */
                        {
                            (yyvsp[0].ledName)->merge = (yyvsp[-1].merge);
                            (yyval.any) = (ParseCommon *) (yyvsp[0].ledName);
                        }
    break;

  case 42: /* Decl: OptMergeMode ShapeDecl  */
                                                        { (yyval.any) = NULL; }
    break;

  case 43: /* Decl: OptMergeMode SectionDecl  */
                                                        { (yyval.any) = NULL; }
    break;

  case 44: /* Decl: OptMergeMode DoodadDecl  */
                                                        { (yyval.any) = NULL; }
    break;

  case 45: /* Decl: MergeMode STRING  */
                        {
                            (yyval.any) = (ParseCommon *) IncludeCreate(param->ctx, (yyvsp[0].str), (yyvsp[-1].merge));
                            free((yyvsp[0].str));
                        }
    break;

  case 46: /* VarDecl: Lhs EQUALS Expr SEMI  */
                        { (yyval.var) = VarCreate((yyvsp[-3].expr), (yyvsp[-1].expr)); }
    break;

  case 47: /* VarDecl: Ident SEMI  */
                        { (yyval.var) = BoolVarCreate((yyvsp[-1].atom), true); }
    break;

  case 48: /* VarDecl: EXCLAM Ident SEMI  */
                        { (yyval.var) = BoolVarCreate((yyvsp[-1].atom), false); }
    break;

  case 49: /* KeyNameDecl: KEYNAME EQUALS KeyCode SEMI  */
                        { (yyval.keyCode) = KeycodeCreate((yyvsp[-3].atom), (yyvsp[-1].num)); }
    break;

  case 50: /* KeyAliasDecl: ALIAS KEYNAME EQUALS KEYNAME SEMI  */
                        { (yyval.keyAlias) = KeyAliasCreate((yyvsp[-3].atom), (yyvsp[-1].atom)); }
    break;

  case 51: /* VModDecl: VIRTUAL_MODS VModDefList SEMI  */
                        { (yyval.vmodList) = (yyvsp[-1].vmodList); }
    break;

  case 52: /* VModDefList: VModDefList COMMA VModDef  */
                        { (yyval.vmodList).head = (yyvsp[-2].vmodList).head; (yyval.vmodList).last->common.next = &(yyvsp[0].vmod)->common; (yyval.vmodList).last = (yyvsp[0].vmod); }
    break;

  case 53: /* VModDefList: VModDef  */
                        { (yyval.vmodList).head = (yyval.vmodList).last = (yyvsp[0].vmod); }
    break;

  case 54: /* VModDef: Ident  */
                        { (yyval.vmod) = VModCreate((yyvsp[0].atom), NULL); }
    break;

  case 55: /* VModDef: Ident EQUALS Expr  */
                        { (yyval.vmod) = VModCreate((yyvsp[-2].atom), (yyvsp[0].expr)); }
    break;

  case 56: /* InterpretDecl: INTERPRET InterpretMatch OBRACE VarDeclList CBRACE SEMI  */
                        { (yyvsp[-4].interp)->def = (yyvsp[-2].varList).head; (yyval.interp) = (yyvsp[-4].interp); }
    break;

  case 57: /* InterpretMatch: KeySym PLUS Expr  */
                        { (yyval.interp) = InterpCreate((yyvsp[-2].keysym), (yyvsp[0].expr)); }
    break;

  case 58: /* InterpretMatch: KeySym  */
                        { (yyval.interp) = InterpCreate((yyvsp[0].keysym), NULL); }
    break;

  case 59: /* VarDeclList: VarDeclList VarDecl  */
                        { (yyval.varList).head = (yyvsp[-1].varList).head; (yyval.varList).last->common.next = &(yyvsp[0].var)->common; (yyval.varList).last = (yyvsp[0].var); }
    break;

  case 60: /* VarDeclList: VarDecl  */
                        { (yyval.varList).head = (yyval.varList).last = (yyvsp[0].var); }
    break;

  case 61: /* KeyTypeDecl: TYPE String OBRACE VarDeclList CBRACE SEMI  */
                        { (yyval.keyType) = KeyTypeCreate((yyvsp[-4].atom), (yyvsp[-2].varList).head); }
    break;

  case 62: /* SymbolsDecl: KEY KEYNAME OBRACE SymbolsBody CBRACE SEMI  */
                        { (yyval.syms) = SymbolsCreate((yyvsp[-4].atom), (yyvsp[-2].varList).head); }
    break;

  case 63: /* SymbolsBody: SymbolsBody COMMA SymbolsVarDecl  */
                        { (yyval.varList).head = (yyvsp[-2].varList).head; (yyval.varList).last->common.next = &(yyvsp[0].var)->common; (yyval.varList).last = (yyvsp[0].var); }
    break;

  case 64: /* SymbolsBody: SymbolsVarDecl  */
                        { (yyval.varList).head = (yyval.varList).last = (yyvsp[0].var); }
    break;

  case 65: /* SymbolsVarDecl: Lhs EQUALS Expr  */
                                                { (yyval.var) = VarCreate((yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 66: /* SymbolsVarDecl: Lhs EQUALS ArrayInit  */
                                                { (yyval.var) = VarCreate((yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 67: /* SymbolsVarDecl: Ident  */
                                                { (yyval.var) = BoolVarCreate((yyvsp[0].atom), true); }
    break;

  case 68: /* SymbolsVarDecl: EXCLAM Ident  */
                                                { (yyval.var) = BoolVarCreate((yyvsp[0].atom), false); }
    break;

  case 69: /* SymbolsVarDecl: ArrayInit  */
                                                { (yyval.var) = VarCreate(NULL, (yyvsp[0].expr)); }
    break;

  case 70: /* ArrayInit: OBRACKET OptKeySymList CBRACKET  */
                        { (yyval.expr) = (yyvsp[-1].expr); }
    break;

  case 71: /* ArrayInit: OBRACKET ActionList CBRACKET  */
                        { (yyval.expr) = ExprCreateActionList((yyvsp[-1].exprList).head); }
    break;

  case 72: /* GroupCompatDecl: GROUP Integer EQUALS Expr SEMI  */
                        { (yyval.groupCompat) = GroupCompatCreate((yyvsp[-3].num), (yyvsp[-1].expr)); }
    break;

  case 73: /* ModMapDecl: MODIFIER_MAP Ident OBRACE ExprList CBRACE SEMI  */
                        { (yyval.modMask) = ModMapCreate((yyvsp[-4].atom), (yyvsp[-2].exprList).head); }
    break;

  case 74: /* LedMapDecl: INDICATOR String OBRACE VarDeclList CBRACE SEMI  */
                        { (yyval.ledMap) = LedMapCreate((yyvsp[-4].atom), (yyvsp[-2].varList).head); }
    break;

  case 75: /* LedNameDecl: INDICATOR Integer EQUALS Expr SEMI  */
                        { (yyval.ledName) = LedNameCreate((yyvsp[-3].num), (yyvsp[-1].expr), false); }
    break;

  case 76: /* LedNameDecl: VIRTUAL INDICATOR Integer EQUALS Expr SEMI  */
                        { (yyval.ledName) = LedNameCreate((yyvsp[-3].num), (yyvsp[-1].expr), true); }
    break;

  case 77: /* ShapeDecl: SHAPE String OBRACE OutlineList CBRACE SEMI  */
                        { (yyval.geom) = NULL; }
    break;

  case 78: /* ShapeDecl: SHAPE String OBRACE CoordList CBRACE SEMI  */
                        { (void) (yyvsp[-2].expr); (yyval.geom) = NULL; }
    break;

  case 79: /* SectionDecl: SECTION String OBRACE SectionBody CBRACE SEMI  */
                        { (yyval.geom) = NULL; }
    break;

  case 80: /* SectionBody: SectionBody SectionBodyItem  */
                                                        { (yyval.geom) = NULL;}
    break;

  case 81: /* SectionBody: SectionBodyItem  */
                                                        { (yyval.geom) = NULL; }
    break;

  case 82: /* SectionBodyItem: ROW OBRACE RowBody CBRACE SEMI  */
                        { (yyval.geom) = NULL; }
    break;

  case 83: /* SectionBodyItem: VarDecl  */
                        { FreeStmt((ParseCommon *) (yyvsp[0].var)); (yyval.geom) = NULL; }
    break;

  case 84: /* SectionBodyItem: DoodadDecl  */
                        { (yyval.geom) = NULL; }
    break;

  case 85: /* SectionBodyItem: LedMapDecl  */
                        { FreeStmt((ParseCommon *) (yyvsp[0].ledMap)); (yyval.geom) = NULL; }
    break;

  case 86: /* SectionBodyItem: OverlayDecl  */
                        { (yyval.geom) = NULL; }
    break;

  case 87: /* RowBody: RowBody RowBodyItem  */
                                                { (yyval.geom) = NULL;}
    break;

  case 88: /* RowBody: RowBodyItem  */
                                                { (yyval.geom) = NULL; }
    break;

  case 89: /* RowBodyItem: KEYS OBRACE Keys CBRACE SEMI  */
                                                     { (yyval.geom) = NULL; }
    break;

  case 90: /* RowBodyItem: VarDecl  */
                        { FreeStmt((ParseCommon *) (yyvsp[0].var)); (yyval.geom) = NULL; }
    break;

  case 91: /* Keys: Keys COMMA Key  */
                                                { (yyval.geom) = NULL; }
    break;

  case 92: /* Keys: Key  */
                                                { (yyval.geom) = NULL; }
    break;

  case 93: /* Key: KEYNAME  */
                        { (yyval.geom) = NULL; }
    break;

  case 94: /* Key: OBRACE ExprList CBRACE  */
                        { FreeStmt((ParseCommon *) (yyvsp[-1].exprList).head); (yyval.geom) = NULL; }
    break;

  case 95: /* OverlayDecl: OVERLAY String OBRACE OverlayKeyList CBRACE SEMI  */
                        { (yyval.geom) = NULL; }
    break;

  case 96: /* OverlayKeyList: OverlayKeyList COMMA OverlayKey  */
                                                        { (yyval.geom) = NULL; }
    break;

  case 97: /* OverlayKeyList: OverlayKey  */
                                                        { (yyval.geom) = NULL; }
    break;

  case 98: /* OverlayKey: KEYNAME EQUALS KEYNAME  */
                                                        { (yyval.geom) = NULL; }
    break;

  case 99: /* OutlineList: OutlineList COMMA OutlineInList  */
                        { (yyval.geom) = NULL;}
    break;

  case 100: /* OutlineList: OutlineInList  */
                        { (yyval.geom) = NULL; }
    break;

  case 101: /* OutlineInList: OBRACE CoordList CBRACE  */
                        { (void) (yyvsp[-1].expr); (yyval.geom) = NULL; }
    break;

  case 102: /* OutlineInList: Ident EQUALS OBRACE CoordList CBRACE  */
                        { (void) (yyvsp[-1].expr); (yyval.geom) = NULL; }
    break;

  case 103: /* OutlineInList: Ident EQUALS Expr  */
                        { FreeStmt((ParseCommon *) (yyvsp[0].expr)); (yyval.geom) = NULL; }
    break;

  case 104: /* CoordList: CoordList COMMA Coord  */
                        { (void) (yyvsp[-2].expr); (void) (yyvsp[0].expr); (yyval.expr) = NULL; }
    break;

  case 105: /* CoordList: Coord  */
                        { (void) (yyvsp[0].expr); (yyval.expr) = NULL; }
    break;

  case 106: /* Coord: OBRACKET SignedNumber COMMA SignedNumber CBRACKET  */
                        { (yyval.expr) = NULL; }
    break;

  case 107: /* DoodadDecl: DoodadType String OBRACE VarDeclList CBRACE SEMI  */
                        { FreeStmt((ParseCommon *) (yyvsp[-2].varList).head); (yyval.geom) = NULL; }
    break;

  case 108: /* DoodadType: TEXT  */
                                { (yyval.num) = 0; }
    break;

  case 109: /* DoodadType: OUTLINE  */
                                { (yyval.num) = 0; }
    break;

  case 110: /* DoodadType: SOLID  */
                                { (yyval.num) = 0; }
    break;

  case 111: /* DoodadType: LOGO  */
                                { (yyval.num) = 0; }
    break;

  case 112: /* FieldSpec: Ident  */
                                { (yyval.atom) = (yyvsp[0].atom); }
    break;

  case 113: /* FieldSpec: Element  */
                                { (yyval.atom) = (yyvsp[0].atom); }
    break;

  case 114: /* Element: ACTION_TOK  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "action"); }
    break;

  case 115: /* Element: INTERPRET  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "interpret"); }
    break;

  case 116: /* Element: TYPE  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "type"); }
    break;

  case 117: /* Element: KEY  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "key"); }
    break;

  case 118: /* Element: GROUP  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "group"); }
    break;

  case 119: /* Element: MODIFIER_MAP  */
                        {(yyval.atom) = xkb_atom_intern_literal(param->ctx, "modifier_map");}
    break;

  case 120: /* Element: INDICATOR  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "indicator"); }
    break;

  case 121: /* Element: SHAPE  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "shape"); }
    break;

  case 122: /* Element: ROW  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "row"); }
    break;

  case 123: /* Element: SECTION  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "section"); }
    break;

  case 124: /* Element: TEXT  */
                        { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "text"); }
    break;

  case 125: /* OptMergeMode: MergeMode  */
                                        { (yyval.merge) = (yyvsp[0].merge); }
    break;

  case 126: /* OptMergeMode: %empty  */
                                        { (yyval.merge) = MERGE_DEFAULT; }
    break;

  case 127: /* MergeMode: INCLUDE  */
                                        { (yyval.merge) = MERGE_DEFAULT; }
    break;

  case 128: /* MergeMode: AUGMENT  */
                                        { (yyval.merge) = MERGE_AUGMENT; }
    break;

  case 129: /* MergeMode: OVERRIDE  */
                                        { (yyval.merge) = MERGE_OVERRIDE; }
    break;

  case 130: /* MergeMode: REPLACE  */
                                        { (yyval.merge) = MERGE_REPLACE; }
    break;

  case 131: /* MergeMode: ALTERNATE  */
                {
                    /*
                     * This used to be MERGE_ALT_FORM. This functionality was
                     * unused and has been removed.
                     */
                    (yyval.merge) = MERGE_DEFAULT;
                }
    break;

  case 132: /* OptExprList: ExprList  */
                                        { (yyval.exprList) = (yyvsp[0].exprList); }
    break;

  case 133: /* OptExprList: %empty  */
                                        { (yyval.exprList).head = (yyval.exprList).last = NULL; }
    break;

  case 134: /* ExprList: ExprList COMMA Expr  */
                        { (yyval.exprList).head = (yyvsp[-2].exprList).head; (yyval.exprList).last->common.next = &(yyvsp[0].expr)->common; (yyval.exprList).last = (yyvsp[0].expr); }
    break;

  case 135: /* ExprList: Expr  */
                        { (yyval.exprList).head = (yyval.exprList).last = (yyvsp[0].expr); }
    break;

  case 136: /* Expr: Expr DIVIDE Expr  */
                        { (yyval.expr) = ExprCreateBinary(EXPR_DIVIDE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 137: /* Expr: Expr PLUS Expr  */
                        { (yyval.expr) = ExprCreateBinary(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 138: /* Expr: Expr MINUS Expr  */
                        { (yyval.expr) = ExprCreateBinary(EXPR_SUBTRACT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 139: /* Expr: Expr TIMES Expr  */
                        { (yyval.expr) = ExprCreateBinary(EXPR_MULTIPLY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 140: /* Expr: Lhs EQUALS Expr  */
                        { (yyval.expr) = ExprCreateBinary(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 141: /* Expr: Term  */
                        { (yyval.expr) = (yyvsp[0].expr); }
    break;

  case 142: /* Term: MINUS Term  */
                        { (yyval.expr) = ExprCreateUnary(EXPR_NEGATE, (yyvsp[0].expr)->expr.value_type, (yyvsp[0].expr)); }
    break;

  case 143: /* Term: PLUS Term  */
                        { (yyval.expr) = ExprCreateUnary(EXPR_UNARY_PLUS, (yyvsp[0].expr)->expr.value_type, (yyvsp[0].expr)); }
    break;

  case 144: /* Term: EXCLAM Term  */
                        { (yyval.expr) = ExprCreateUnary(EXPR_NOT, EXPR_TYPE_BOOLEAN, (yyvsp[0].expr)); }
    break;

  case 145: /* Term: INVERT Term  */
                        { (yyval.expr) = ExprCreateUnary(EXPR_INVERT, (yyvsp[0].expr)->expr.value_type, (yyvsp[0].expr)); }
    break;

  case 146: /* Term: Lhs  */
                        { (yyval.expr) = (yyvsp[0].expr);  }
    break;

  case 147: /* Term: FieldSpec OPAREN OptExprList CPAREN  */
                        { (yyval.expr) = ExprCreateAction((yyvsp[-3].atom), (yyvsp[-1].exprList).head); }
    break;

  case 148: /* Term: Terminal  */
                        { (yyval.expr) = (yyvsp[0].expr);  }
    break;

  case 149: /* Term: OPAREN Expr CPAREN  */
                        { (yyval.expr) = (yyvsp[-1].expr);  }
    break;

  case 150: /* ActionList: ActionList COMMA Action  */
                        { (yyval.exprList).head = (yyvsp[-2].exprList).head; (yyval.exprList).last->common.next = &(yyvsp[0].expr)->common; (yyval.exprList).last = (yyvsp[0].expr); }
    break;

  case 151: /* ActionList: Action  */
                        { (yyval.exprList).head = (yyval.exprList).last = (yyvsp[0].expr); }
    break;

  case 152: /* Action: FieldSpec OPAREN OptExprList CPAREN  */
                        { (yyval.expr) = ExprCreateAction((yyvsp[-3].atom), (yyvsp[-1].exprList).head); }
    break;

  case 153: /* Lhs: FieldSpec  */
                        { (yyval.expr) = ExprCreateIdent((yyvsp[0].atom)); }
    break;

  case 154: /* Lhs: FieldSpec DOT FieldSpec  */
                        { (yyval.expr) = ExprCreateFieldRef((yyvsp[-2].atom), (yyvsp[0].atom)); }
    break;

  case 155: /* Lhs: FieldSpec OBRACKET Expr CBRACKET  */
                        { (yyval.expr) = ExprCreateArrayRef(XKB_ATOM_NONE, (yyvsp[-3].atom), (yyvsp[-1].expr)); }
    break;

  case 156: /* Lhs: FieldSpec DOT FieldSpec OBRACKET Expr CBRACKET  */
                        { (yyval.expr) = ExprCreateArrayRef((yyvsp[-5].atom), (yyvsp[-3].atom), (yyvsp[-1].expr)); }
    break;

  case 157: /* Terminal: String  */
                        { (yyval.expr) = ExprCreateString((yyvsp[0].atom)); }
    break;

  case 158: /* Terminal: Integer  */
                        { (yyval.expr) = ExprCreateInteger((yyvsp[0].num)); }
    break;

  case 159: /* Terminal: Float  */
                        { (yyval.expr) = ExprCreateFloat(/* Discard $1 */); }
    break;

  case 160: /* Terminal: KEYNAME  */
                        { (yyval.expr) = ExprCreateKeyName((yyvsp[0].atom)); }
    break;

  case 161: /* OptKeySymList: KeySymList  */
                                        { (yyval.expr) = (yyvsp[0].expr); }
    break;

  case 162: /* OptKeySymList: %empty  */
                                        { (yyval.expr) = NULL; }
    break;

  case 163: /* KeySymList: KeySymList COMMA KeySym  */
                        { (yyval.expr) = ExprAppendKeysymList((yyvsp[-2].expr), (yyvsp[0].keysym)); }
    break;

  case 164: /* KeySymList: KeySymList COMMA KeySyms  */
                        { (yyval.expr) = ExprAppendMultiKeysymList((yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 165: /* KeySymList: KeySym  */
                        { (yyval.expr) = ExprCreateKeysymList((yyvsp[0].keysym)); }
    break;

  case 166: /* KeySymList: KeySyms  */
                        { (yyval.expr) = ExprCreateMultiKeysymList((yyvsp[0].expr)); }
    break;

  case 167: /* KeySyms: OBRACE KeySymList CBRACE  */
                        { (yyval.expr) = (yyvsp[-1].expr); }
    break;

  case 168: /* KeySym: IDENT  */
                        {
                            if (!resolve_keysym((yyvsp[0].str), &(yyval.keysym))) {
                                parser_warn(
                                    param,
                                    XKB_WARNING_UNRECOGNIZED_KEYSYM,
                                    "unrecognized keysym \"%s\"",
                                    (yyvsp[0].str)
                                );
                                (yyval.keysym) = XKB_KEY_NoSymbol;
                            }
                            free((yyvsp[0].str));
                        }
    break;

  case 169: /* KeySym: SECTION  */
                                { (yyval.keysym) = XKB_KEY_section; }
    break;

  case 170: /* KeySym: Integer  */
                        {
                            if ((yyvsp[0].num) < XKB_KEYSYM_MIN) {
                                parser_warn(
                                    param,
                                    XKB_WARNING_UNRECOGNIZED_KEYSYM,
                                    "unrecognized keysym \"%"PRId64"\"",
                                    (yyvsp[0].num)
                                );
                                (yyval.keysym) = XKB_KEY_NoSymbol;
                            }
                            /* Special case for digits 0..9 */
                            else if ((yyvsp[0].num) < 10) {      /* XKB_KEY_0 .. XKB_KEY_9 */
                                (yyval.keysym) = XKB_KEY_0 + (xkb_keysym_t) (yyvsp[0].num);
                            }
                            else {
                                if ((yyvsp[0].num) <= XKB_KEYSYM_MAX) {
                                    (yyval.keysym) = (xkb_keysym_t) (yyvsp[0].num);
                                } else {
                                    parser_warn(
                                        param, XKB_WARNING_UNRECOGNIZED_KEYSYM,
                                        "unrecognized keysym \"0x%"PRIx64"\" "
                                        "(%"PRId64")", (yyvsp[0].num), (yyvsp[0].num)
                                    );
                                    (yyval.keysym) = XKB_KEY_NoSymbol;
                                }
                                parser_warn(
                                    param, XKB_WARNING_NUMERIC_KEYSYM,
                                    "numeric keysym \"0x%"PRIx64"\" (%"PRId64")",
                                    (yyvsp[0].num), (yyvsp[0].num)
                                );
                            }
                        }
    break;

  case 171: /* SignedNumber: MINUS Number  */
                                        { (yyval.num) = -(yyvsp[0].num); }
    break;

  case 172: /* SignedNumber: Number  */
                                        { (yyval.num) = (yyvsp[0].num); }
    break;

  case 173: /* Number: FLOAT  */
                                { (yyval.num) = (yyvsp[0].num); }
    break;

  case 174: /* Number: INTEGER  */
                                { (yyval.num) = (yyvsp[0].num); }
    break;

  case 175: /* Float: FLOAT  */
                                { (yyval.num) = 0; }
    break;

  case 176: /* Integer: INTEGER  */
                                { (yyval.num) = (yyvsp[0].num); }
    break;

  case 177: /* KeyCode: INTEGER  */
                                { (yyval.num) = (yyvsp[0].num); }
    break;

  case 178: /* Ident: IDENT  */
                                { (yyval.atom) = xkb_atom_intern(param->ctx, (yyvsp[0].str), strlen((yyvsp[0].str))); free((yyvsp[0].str)); }
    break;

  case 179: /* Ident: DEFAULT  */
                                { (yyval.atom) = xkb_atom_intern_literal(param->ctx, "default"); }
    break;

  case 180: /* String: STRING  */
                                { (yyval.atom) = xkb_atom_intern(param->ctx, (yyvsp[0].str), strlen((yyvsp[0].str))); free((yyvsp[0].str)); }
    break;

  case 181: /* OptMapName: MapName  */
                                { (yyval.str) = (yyvsp[0].str); }
    break;

  case 182: /* OptMapName: %empty  */
                                { (yyval.str) = NULL; }
    break;

  case 183: /* MapName: STRING  */
                                { (yyval.str) = (yyvsp[0].str); }
    break;



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
      yyerror (param, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= END_OF_FILE)
        {
          /* Return failure if at end of input.  */
          if (yychar == END_OF_FILE)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, param);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, param);
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
  yyerror (param, YY_("memory exhausted"));
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
                  yytoken, &yylval, param);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, param);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}



XkbFile *
parse(struct xkb_context *ctx, struct scanner *scanner, const char *map)
{
    int ret;
    XkbFile *first = NULL;
    struct parser_param param = {
        .scanner = scanner,
        .ctx = ctx,
        .rtrn = NULL,
        .more_maps = false,
    };

    /*
     * If we got a specific map, we look for it exclusively and return
     * immediately upon finding it. Otherwise, we need to get the
     * default map. If we find a map marked as default, we return it
     * immediately. If there are no maps marked as default, we return
     * the first map in the file.
     */

    while ((ret = yyparse(&param)) == 0 && param.more_maps) {
        if (map) {
            if (streq_not_null(map, param.rtrn->name))
                return param.rtrn;
            else
                FreeXkbFile(param.rtrn);
        }
        else {
            if (param.rtrn->flags & MAP_IS_DEFAULT) {
                FreeXkbFile(first);
                return param.rtrn;
            }
            else if (!first) {
                first = param.rtrn;
            }
            else {
                FreeXkbFile(param.rtrn);
            }
        }
        param.rtrn = NULL;
    }

    if (ret != 0) {
        FreeXkbFile(first);
        return NULL;
    }

    if (first)
        log_vrb(ctx, 5,
                XKB_WARNING_MISSING_DEFAULT_SECTION,
                "No map in include statement, but \"%s\" contains several; "
                "Using first defined map, \"%s\"\n",
                scanner->file_name, first->name);

    return first;
}
