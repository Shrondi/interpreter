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
#line 7 "interpreter.y"

#include <iostream>
#include <string>
#include <map>

/*******************************************/
/* NEW in example 5 */
/* pow */
#include <math.h>
/*******************************************/

/*******************************************/
/* NEW in example 6 */
/* Use for recovery of runtime errors */
#include <setjmp.h>
#include <signal.h>
/*******************************************/

/* Error recovery functions */
#include "../error/error.hpp"

/* Macros for the screen */
#include "../includes/macros.hpp"


/*******************************************/
/* 
  NEW in example 16
  AST class
  IMPORTANT: this file must be before init.hpp
*/
#include "../ast/ast.hpp"


/*******************************************/
/* NEW in example 7 */
/* Table of symbol */
#include "../table/table.hpp"
/*******************************************/

/*******************************************/
#include "../table/numericVariable.hpp"
/*******************************************/

/* NEW in example 15 */
#include "../table/logicalVariable.hpp"

/*******************************************/
/* NEW in example 11 */
#include "../table/numericConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 15 */
#include "../table/logicalConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 13 */
#include "../table/builtinParameter1.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 14 */
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
/*******************************************/


/*******************************************/
/* NEW in example 10 */
#include "../table/init.hpp"
/*******************************************/

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
extern "C" int yylex (void);


extern int lineNumber; //!< External line counter


/* NEW in example 15 */
extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

/* New in example 17 */
extern int control; //!< External: to control the interactive mode in "if" and "while" sentences 


/////////////////
bool ParserError = false; /* Usamos esta variable para señalar que ha habido algún error sintáctico en el modo interactivo  */

/////////////////

/***********************************************************/
/* NEW in example 2 */
extern std::string progname; //!<  Program name
/***********************************************************/

/*******************************************/
/* NEW in example 6 */
/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
jmp_buf begin; //!<  It enables recovery of runtime errors 
/*******************************************/


/*******************************************/
/* NEW in example 7 */
extern lp::Table table; //!< Extern Table of Symbols

/*******************************************/
/* NEW in example 16 */
extern lp::AST *root; //!< External root of the abstract syntax tree AST

std::list<lp::Statement *> *top;


#line 197 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 148 "interpreter.y"

	namespace lp{
		 struct values {
			std::map<int, std::list<lp::Statement *> > *valuesNum;
			std::map<std::string, std::list<lp::Statement *> > *valuesCad;
			std::map<bool, std::list<lp::Statement *> > *valuesLog; 

    	};
	}

#line 243 "y.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* YYEOF  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    COLON = 258,                   /* COLON  */
    SEMICOLON = 259,               /* SEMICOLON  */
    PRINT = 260,                   /* PRINT  */
    PRINT_STRING = 261,            /* PRINT_STRING  */
    READ = 262,                    /* READ  */
    READ_STRING = 263,             /* READ_STRING  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    END_IF = 266,                  /* END_IF  */
    CASE = 267,                    /* CASE  */
    VALUE = 268,                   /* VALUE  */
    DEFAULT = 269,                 /* DEFAULT  */
    END_CASE = 270,                /* END_CASE  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    DO = 273,                      /* DO  */
    END_WHILE = 274,               /* END_WHILE  */
    REPEAT = 275,                  /* REPEAT  */
    UNTIL = 276,                   /* UNTIL  */
    FOR = 277,                     /* FOR  */
    FROM = 278,                    /* FROM  */
    TO = 279,                      /* TO  */
    STEP = 280,                    /* STEP  */
    END_FOR = 281,                 /* END_FOR  */
    CLEAR = 282,                   /* CLEAR  */
    PLACE = 283,                   /* PLACE  */
    STYLE = 284,                   /* STYLE  */
    CONST = 285,                   /* CONST  */
    LETFCURLYBRACKET = 286,        /* LETFCURLYBRACKET  */
    RIGHTCURLYBRACKET = 287,       /* RIGHTCURLYBRACKET  */
    PLUS_ASSIGNMENT = 288,         /* PLUS_ASSIGNMENT  */
    MINUS_ASSIGNMENT = 289,        /* MINUS_ASSIGNMENT  */
    MULTIPLICATION_ASSIGNMENT = 290, /* MULTIPLICATION_ASSIGNMENT  */
    INTEGER_DIVISION_ASSIGNMENT = 291, /* INTEGER_DIVISION_ASSIGNMENT  */
    DIVISION_ASSIGNMENT = 292,     /* DIVISION_ASSIGNMENT  */
    MODULO_ASSIGNMENT = 293,       /* MODULO_ASSIGNMENT  */
    POWER_ASSIGNMENT = 294,        /* POWER_ASSIGNMENT  */
    ASSIGNMENT = 295,              /* ASSIGNMENT  */
    COMMA = 296,                   /* COMMA  */
    NUMBER = 297,                  /* NUMBER  */
    BOOL = 298,                    /* BOOL  */
    VARIABLE = 299,                /* VARIABLE  */
    UNDEFINED = 300,               /* UNDEFINED  */
    NUMERIC_CONSTANT = 301,        /* NUMERIC_CONSTANT  */
    LOGICAL_CONSTANT = 302,        /* LOGICAL_CONSTANT  */
    STRING_CONSTANT = 303,         /* STRING_CONSTANT  */
    BUILTIN = 304,                 /* BUILTIN  */
    STRING = 305,                  /* STRING  */
    CONCATENATION = 306,           /* CONCATENATION  */
    OR = 307,                      /* OR  */
    AND = 308,                     /* AND  */
    GREATER_OR_EQUAL = 309,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 310,           /* LESS_OR_EQUAL  */
    GREATER_THAN = 311,            /* GREATER_THAN  */
    LESS_THAN = 312,               /* LESS_THAN  */
    EQUAL = 313,                   /* EQUAL  */
    NOT_EQUAL = 314,               /* NOT_EQUAL  */
    NOT = 315,                     /* NOT  */
    PLUS = 316,                    /* PLUS  */
    MINUS = 317,                   /* MINUS  */
    MULTIPLICATION = 318,          /* MULTIPLICATION  */
    DIVISION = 319,                /* DIVISION  */
    INTEGER_DIVISION = 320,        /* INTEGER_DIVISION  */
    MODULO = 321,                  /* MODULO  */
    PLUSPLUS = 322,                /* PLUSPLUS  */
    MINUSMINUS = 323,              /* MINUSMINUS  */
    LPAREN = 324,                  /* LPAREN  */
    RPAREN = 325,                  /* RPAREN  */
    UNARY = 326,                   /* UNARY  */
    POWER = 327                    /* POWER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define COLON 258
#define SEMICOLON 259
#define PRINT 260
#define PRINT_STRING 261
#define READ 262
#define READ_STRING 263
#define IF 264
#define THEN 265
#define END_IF 266
#define CASE 267
#define VALUE 268
#define DEFAULT 269
#define END_CASE 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define END_WHILE 274
#define REPEAT 275
#define UNTIL 276
#define FOR 277
#define FROM 278
#define TO 279
#define STEP 280
#define END_FOR 281
#define CLEAR 282
#define PLACE 283
#define STYLE 284
#define CONST 285
#define LETFCURLYBRACKET 286
#define RIGHTCURLYBRACKET 287
#define PLUS_ASSIGNMENT 288
#define MINUS_ASSIGNMENT 289
#define MULTIPLICATION_ASSIGNMENT 290
#define INTEGER_DIVISION_ASSIGNMENT 291
#define DIVISION_ASSIGNMENT 292
#define MODULO_ASSIGNMENT 293
#define POWER_ASSIGNMENT 294
#define ASSIGNMENT 295
#define COMMA 296
#define NUMBER 297
#define BOOL 298
#define VARIABLE 299
#define UNDEFINED 300
#define NUMERIC_CONSTANT 301
#define LOGICAL_CONSTANT 302
#define STRING_CONSTANT 303
#define BUILTIN 304
#define STRING 305
#define CONCATENATION 306
#define OR 307
#define AND 308
#define GREATER_OR_EQUAL 309
#define LESS_OR_EQUAL 310
#define GREATER_THAN 311
#define LESS_THAN 312
#define EQUAL 313
#define NOT_EQUAL 314
#define NOT 315
#define PLUS 316
#define MINUS 317
#define MULTIPLICATION 318
#define DIVISION 319
#define INTEGER_DIVISION 320
#define MODULO 321
#define PLUSPLUS 322
#define MINUSMINUS 323
#define LPAREN 324
#define RPAREN 325
#define UNARY 326
#define POWER 327

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 159 "interpreter.y"

  double number;
  char * string; 				 /* NEW in example 7 */
  bool logic;						 /* NEW in example 15 */
  lp::ExpNode *expNode;  			 /* NEW in example 16 */
  std::list<lp::ExpNode *>  *parameters;    // New in example 16; NOTE: #include<list> must be in interpreter.l, init.cpp, interpreter.cpp
  std::list<lp::Statement *> *stmts; /* NEW in example 16 */
  lp::Statement *st;				 /* NEW in example 16 */
  lp::AST *prog;					 /* NEW in example 16 */
  /* std::map<int, std::list<lp::Statement *> > *values;
  std::map<std::string, std::list<lp::Statement *> > *valuesCad;  */ 
  struct lp::values *caseValues;

#line 421 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* YYEOF  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COLON = 3,                      /* COLON  */
  YYSYMBOL_SEMICOLON = 4,                  /* SEMICOLON  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_PRINT_STRING = 6,               /* PRINT_STRING  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_READ_STRING = 8,                /* READ_STRING  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_END_IF = 11,                    /* END_IF  */
  YYSYMBOL_CASE = 12,                      /* CASE  */
  YYSYMBOL_VALUE = 13,                     /* VALUE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_END_CASE = 15,                  /* END_CASE  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_END_WHILE = 19,                 /* END_WHILE  */
  YYSYMBOL_REPEAT = 20,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 21,                     /* UNTIL  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_FROM = 23,                      /* FROM  */
  YYSYMBOL_TO = 24,                        /* TO  */
  YYSYMBOL_STEP = 25,                      /* STEP  */
  YYSYMBOL_END_FOR = 26,                   /* END_FOR  */
  YYSYMBOL_CLEAR = 27,                     /* CLEAR  */
  YYSYMBOL_PLACE = 28,                     /* PLACE  */
  YYSYMBOL_STYLE = 29,                     /* STYLE  */
  YYSYMBOL_CONST = 30,                     /* CONST  */
  YYSYMBOL_LETFCURLYBRACKET = 31,          /* LETFCURLYBRACKET  */
  YYSYMBOL_RIGHTCURLYBRACKET = 32,         /* RIGHTCURLYBRACKET  */
  YYSYMBOL_PLUS_ASSIGNMENT = 33,           /* PLUS_ASSIGNMENT  */
  YYSYMBOL_MINUS_ASSIGNMENT = 34,          /* MINUS_ASSIGNMENT  */
  YYSYMBOL_MULTIPLICATION_ASSIGNMENT = 35, /* MULTIPLICATION_ASSIGNMENT  */
  YYSYMBOL_INTEGER_DIVISION_ASSIGNMENT = 36, /* INTEGER_DIVISION_ASSIGNMENT  */
  YYSYMBOL_DIVISION_ASSIGNMENT = 37,       /* DIVISION_ASSIGNMENT  */
  YYSYMBOL_MODULO_ASSIGNMENT = 38,         /* MODULO_ASSIGNMENT  */
  YYSYMBOL_POWER_ASSIGNMENT = 39,          /* POWER_ASSIGNMENT  */
  YYSYMBOL_ASSIGNMENT = 40,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_NUMBER = 42,                    /* NUMBER  */
  YYSYMBOL_BOOL = 43,                      /* BOOL  */
  YYSYMBOL_VARIABLE = 44,                  /* VARIABLE  */
  YYSYMBOL_UNDEFINED = 45,                 /* UNDEFINED  */
  YYSYMBOL_NUMERIC_CONSTANT = 46,          /* NUMERIC_CONSTANT  */
  YYSYMBOL_LOGICAL_CONSTANT = 47,          /* LOGICAL_CONSTANT  */
  YYSYMBOL_STRING_CONSTANT = 48,           /* STRING_CONSTANT  */
  YYSYMBOL_BUILTIN = 49,                   /* BUILTIN  */
  YYSYMBOL_STRING = 50,                    /* STRING  */
  YYSYMBOL_CONCATENATION = 51,             /* CONCATENATION  */
  YYSYMBOL_OR = 52,                        /* OR  */
  YYSYMBOL_AND = 53,                       /* AND  */
  YYSYMBOL_GREATER_OR_EQUAL = 54,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 55,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN = 56,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 57,                 /* LESS_THAN  */
  YYSYMBOL_EQUAL = 58,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 59,                 /* NOT_EQUAL  */
  YYSYMBOL_NOT = 60,                       /* NOT  */
  YYSYMBOL_PLUS = 61,                      /* PLUS  */
  YYSYMBOL_MINUS = 62,                     /* MINUS  */
  YYSYMBOL_MULTIPLICATION = 63,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 64,                  /* DIVISION  */
  YYSYMBOL_INTEGER_DIVISION = 65,          /* INTEGER_DIVISION  */
  YYSYMBOL_MODULO = 66,                    /* MODULO  */
  YYSYMBOL_PLUSPLUS = 67,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 68,                /* MINUSMINUS  */
  YYSYMBOL_LPAREN = 69,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 70,                    /* RPAREN  */
  YYSYMBOL_UNARY = 71,                     /* UNARY  */
  YYSYMBOL_POWER = 72,                     /* POWER  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_program = 74,                   /* program  */
  YYSYMBOL_stmtlist = 75,                  /* stmtlist  */
  YYSYMBOL_stmt = 76,                      /* stmt  */
  YYSYMBOL_command = 77,                   /* command  */
  YYSYMBOL_block = 78,                     /* block  */
  YYSYMBOL_controlSymbol = 79,             /* controlSymbol  */
  YYSYMBOL_if = 80,                        /* if  */
  YYSYMBOL_case = 81,                      /* case  */
  YYSYMBOL_default = 82,                   /* default  */
  YYSYMBOL_listOfValues = 83,              /* listOfValues  */
  YYSYMBOL_while = 84,                     /* while  */
  YYSYMBOL_do_while = 85,                  /* do_while  */
  YYSYMBOL_repeat = 86,                    /* repeat  */
  YYSYMBOL_for = 87,                       /* for  */
  YYSYMBOL_cond = 88,                      /* cond  */
  YYSYMBOL_asgn = 89,                      /* asgn  */
  YYSYMBOL_auxasgn = 90,                   /* auxasgn  */
  YYSYMBOL_print = 91,                     /* print  */
  YYSYMBOL_print_string = 92,              /* print_string  */
  YYSYMBOL_read = 93,                      /* read  */
  YYSYMBOL_read_string = 94,               /* read_string  */
  YYSYMBOL_expnum = 95,                    /* expnum  */
  YYSYMBOL_explog = 96,                    /* explog  */
  YYSYMBOL_exp = 97,                       /* exp  */
  YYSYMBOL_expcad = 98,                    /* expcad  */
  YYSYMBOL_auxcad = 99,                    /* auxcad  */
  YYSYMBOL_listOfExp = 100,                /* listOfExp  */
  YYSYMBOL_restOfListOfExp = 101           /* restOfListOfExp  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  312

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   263,   263,   333,   340,   390,   395,   399,   404,   409,
     414,   419,   425,   430,   436,   441,   447,   452,   457,   462,
     467,   472,   477,   486,   490,   495,   502,   510,   518,   528,
     536,   543,   553,   556,   563,   571,   666,   678,   688,   698,
     707,   716,   720,   724,   729,   735,   744,   749,   755,   761,
     767,   773,   779,   785,   792,   800,   805,   810,   815,   820,
     825,   830,   835,   842,   849,   854,   859,   864,   869,   874,
     879,   886,   890,   894,   900,   904,   908,   914,   919,   924,
     931,   936,   941,   949,   949,   952,   957,   960,   964,   971,
     977,   981,   985,   991,   998,  1002,  1006,  1013,  1019,  1023,
    1027,  1031,  1035,  1041,  1047,  1053,  1059,  1065,  1071,  1077,
    1083,  1090,  1096,  1102,  1109,  1159,  1164,  1170,  1176,  1182,
    1188,  1194,  1200,  1206,  1212,  1218,  1227,  1228,  1229,  1234,
    1240,  1244,  1249,  1257,  1259,  1269,  1274,  1285,  1290
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "YYEOF", "error", "\"invalid token\"", "COLON", "SEMICOLON", "PRINT",
  "PRINT_STRING", "READ", "READ_STRING", "IF", "THEN", "END_IF", "CASE",
  "VALUE", "DEFAULT", "END_CASE", "ELSE", "WHILE", "DO", "END_WHILE",
  "REPEAT", "UNTIL", "FOR", "FROM", "TO", "STEP", "END_FOR", "CLEAR",
  "PLACE", "STYLE", "CONST", "LETFCURLYBRACKET", "RIGHTCURLYBRACKET",
  "PLUS_ASSIGNMENT", "MINUS_ASSIGNMENT", "MULTIPLICATION_ASSIGNMENT",
  "INTEGER_DIVISION_ASSIGNMENT", "DIVISION_ASSIGNMENT",
  "MODULO_ASSIGNMENT", "POWER_ASSIGNMENT", "ASSIGNMENT", "COMMA", "NUMBER",
  "BOOL", "VARIABLE", "UNDEFINED", "NUMERIC_CONSTANT", "LOGICAL_CONSTANT",
  "STRING_CONSTANT", "BUILTIN", "STRING", "CONCATENATION", "OR", "AND",
  "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "GREATER_THAN", "LESS_THAN",
  "EQUAL", "NOT_EQUAL", "NOT", "PLUS", "MINUS", "MULTIPLICATION",
  "DIVISION", "INTEGER_DIVISION", "MODULO", "PLUSPLUS", "MINUSMINUS",
  "LPAREN", "RPAREN", "UNARY", "POWER", "$accept", "program", "stmtlist",
  "stmt", "command", "block", "controlSymbol", "if", "case", "default",
  "listOfValues", "while", "do_while", "repeat", "for", "cond", "asgn",
  "auxasgn", "print", "print_string", "read", "read_string", "expnum",
  "explog", "exp", "expcad", "auxcad", "listOfExp", "restOfListOfExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-135)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -57,     6,   293,   -57,    14,   -57,   -31,   -27,   -24,   -23,
     -57,   -57,   -57,   -57,   -57,     9,   -57,   -11,    -3,   -20,
     -57,   991,    27,    29,    30,    31,    32,   -57,    74,   -57,
      75,    77,    78,    92,    97,   108,   109,   120,   121,   125,
     145,   -57,   -57,   -57,  1007,    82,   146,   173,    79,    81,
      79,   863,   -57,   130,   132,   133,   122,   190,   115,   128,
     134,   147,   155,   436,   953,   953,   953,   953,   953,   953,
     953,   953,   -57,   -57,   953,   953,   953,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,    35,   -57,   -57,   -57,   101,   -57,  1036,   190,
     190,   142,   161,  1036,   203,   755,   -57,   420,   180,   182,
     -57,    82,   -57,   -47,   167,   168,   170,   171,   172,   183,
     185,   197,  1036,   244,  1036,   251,   -57,   488,   190,   190,
     190,   247,   -37,   190,  1000,   201,   953,   953,   953,   953,
     -57,   972,    27,    29,    30,   -57,   -57,    -1,   272,  1066,
      17,   -57,   -57,    80,   -57,   -57,   119,   -57,   -57,   150,
     -57,   -57,   163,   -57,   -57,   184,   -57,   -57,   264,   -57,
    1066,   -57,  1066,   -57,  1066,   -57,  1066,   -57,   -57,  1036,
     -57,   205,   205,   -57,   -57,  1029,   208,   -29,   -57,   190,
     190,   190,   190,   190,   190,   190,  1036,  1036,  1036,  1036,
    1036,  1036,  1036,  1036,   -57,    82,   209,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   505,   -57,   590,   -57,
      79,    79,    56,   898,   914,   190,  1029,   190,   -57,   -57,
    1066,   -57,  1066,   -57,  1066,   -57,  1066,   675,   216,   -57,
     -57,   -57,   218,   218,   205,   205,   205,   205,   205,   979,
     328,   686,   686,   686,   686,   686,   686,   -57,   -57,   403,
     -57,   521,   251,   -57,   190,   190,   190,   926,  1045,  1036,
     -57,   -57,   -57,   -57,    20,   -57,   200,   855,   871,   190,
     -57,   675,   573,  1036,   285,   274,   -57,   -57,   -57,   327,
     -57,   -57,   144,   -57,   -57,   606,   658,   691,   -57,   190,
     -57,   745,   -57,   -57,   -57,   778,   883,   350,   -57,   -57,
     830,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     5,     0,     0,     0,     0,
      27,    27,    27,     3,    27,    27,    23,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     4,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    30,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    21,     0,     0,     0,    20,    22,     6,
      12,    13,    14,    15,    17,    18,     7,     8,     9,    10,
      11,    97,   112,   113,   116,   131,     0,   130,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,   128,     0,
     134,     0,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
      26,   112,   113,   116,   131,    56,    64,   126,   127,     0,
     128,    57,    65,   126,    58,    66,   126,    60,    68,   126,
      59,    67,   126,    62,    70,   126,    61,    69,   126,    55,
      46,    74,    71,    75,    72,    76,    73,    98,   100,   135,
     125,   108,   109,    99,   101,   126,   127,   128,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,   133,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     3,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    63,
      54,    80,    77,    81,    78,    82,    79,   137,     0,   107,
     115,   129,   102,   103,   104,   105,   106,   110,   111,   124,
     123,   118,   120,   117,   119,   121,   122,   132,    45,     0,
      34,     0,    37,    38,     0,     0,     0,     0,     0,     0,
     136,   114,    28,     3,    32,    36,     0,     0,     0,     0,
      24,   137,     0,     0,     0,     0,     3,     3,     3,     0,
     138,    29,     0,     3,    31,     0,     0,     0,     3,     0,
       3,     0,    41,    42,    43,     0,     0,     0,    40,     3,
       0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -13,   -57,   -57,   -57,     5,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -48,    40,   977,   -57,   -57,
     -57,   -57,   -56,    24,   -39,   -16,   -30,   -57,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    27,    28,    29,    48,    30,    31,   285,
     274,    32,    33,    34,    35,   123,    36,   146,    37,    38,
      39,    40,   105,   106,   149,   108,   109,   238,   270
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,   134,   125,   -47,   205,   107,     3,    63,   147,   153,
     156,   159,   162,   165,   168,   113,    49,    50,    41,    52,
      56,   -84,  -133,   207,    59,    42,    60,    61,    62,   112,
     177,   178,   170,   283,   284,   172,   174,   176,    44,   127,
      43,   241,    45,   181,   182,    46,    47,   185,   150,   150,
     150,   150,   150,   150,   150,    53,    54,    55,    57,   180,
     189,   190,   191,   192,   193,   194,    58,    74,  -133,    75,
      76,   195,   222,   223,   224,    77,    78,   226,    79,    80,
     264,    81,    82,   216,   -48,   218,  -134,   187,   148,   148,
     148,   148,   148,   148,   148,   206,    83,   230,   232,   234,
     236,    84,   177,   178,   145,   151,   154,   157,   160,   163,
     166,   169,    85,    86,   171,   173,   175,   189,   190,   191,
     192,   193,   194,   -49,    87,    88,   110,   186,   195,    89,
      95,   220,    97,   242,   243,   244,   245,   246,   247,   248,
     237,   189,   190,   191,   192,   193,   194,   300,   122,    90,
     124,   111,   195,   128,   -51,   129,   130,   249,   250,   251,
     252,   253,   254,   255,   256,   135,   131,   -50,   136,   267,
     179,   268,   262,   263,   137,   257,   229,   231,   233,   235,
     189,   190,   191,   192,   193,   194,   183,   138,   -53,   112,
     114,   195,   115,   116,   117,   139,   196,   197,   198,   199,
     200,   201,   202,   203,   259,   184,   261,   188,   276,   277,
     278,   189,   190,   191,   192,   193,   194,   118,   286,   119,
     120,   121,   195,   289,   189,   190,   191,   192,   193,   194,
     281,  -133,    91,   205,   132,   195,    93,   208,   209,    96,
     210,   211,   212,   306,   292,   189,   190,   191,   192,   193,
     194,    99,   100,   213,   217,   214,   195,   101,   102,   133,
     282,   189,   190,   191,   192,   193,   194,   215,   -52,   219,
     225,   228,   195,   295,   296,   297,   -83,   195,   240,   241,
     301,   191,   192,   193,   194,   305,   271,   307,   293,   294,
     195,   290,     0,    -2,     4,     0,   310,     5,     6,     7,
       8,     9,    10,     0,     0,    11,     0,     0,     0,     0,
      12,    13,     0,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,    19,    20,   189,   190,   191,   192,   193,
     194,     0,     0,     0,     0,     0,   195,    21,     0,    22,
      23,    24,     0,     0,     0,   298,     0,     0,     0,     0,
       0,     4,   299,     0,     5,     6,     7,     8,     9,    10,
      25,    26,    11,   -35,   -35,   -35,     0,    12,    13,     0,
      14,     0,    15,     0,     0,     0,     0,    16,    17,    18,
      19,    20,   198,   199,   200,   201,   202,   203,   189,   190,
     191,   192,   193,   194,    21,     0,    22,    23,    24,   195,
       0,     0,     0,     0,     4,     0,     0,     5,     6,     7,
       8,     9,    10,     0,   272,    11,     0,    25,    26,   273,
      12,    13,     0,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,    19,    20,     0,     0,     4,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    21,    11,    22,
      23,    24,     0,    12,    13,     0,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,    19,    20,   140,     0,
      25,    26,   196,   197,   198,   199,   200,   201,   202,   203,
      21,     0,    22,    23,    24,     0,     0,     0,     0,     4,
     204,     0,     5,     6,     7,     8,     9,    10,     0,     0,
      11,     0,     0,    25,    26,    12,    13,     0,    14,   221,
      15,     0,     0,     0,     0,    16,    17,    18,    19,    20,
       0,     0,     4,     0,     0,     5,     6,     7,     8,     9,
      10,     0,    21,    11,    22,    23,    24,     0,    12,    13,
     275,    14,     0,    15,     0,     0,     0,     0,    16,    17,
      18,    19,    20,     0,     0,    25,    26,   196,   197,   198,
     199,   200,   201,   202,   203,    21,     0,    22,    23,    24,
       0,     0,     0,     0,     4,   258,     0,     5,     6,     7,
       8,     9,    10,     0,   291,    11,     0,     0,    25,    26,
      12,    13,     0,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,    19,    20,     0,     0,     4,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    21,    11,    22,
      23,    24,     0,    12,    13,     0,    14,     0,    15,     0,
       0,     0,   302,    16,    17,    18,    19,    20,     0,     0,
      25,    26,   196,   197,   198,   199,   200,   201,   202,   203,
      21,     0,    22,    23,    24,     0,     0,     0,     0,     4,
     260,     0,     5,     6,     7,     8,     9,    10,     0,     0,
      11,     0,     0,    25,    26,    12,    13,     0,    14,     0,
      15,     0,     0,     0,   303,    16,    17,    18,    19,    20,
       0,     0,     4,     0,     0,     5,     6,     7,     8,     9,
      10,     0,    21,    11,    22,    23,    24,     0,    12,    13,
       0,    14,     0,    15,     0,     0,   269,   304,    16,    17,
      18,    19,    20,     0,     0,    25,    26,   196,   197,   198,
     199,   200,   201,   202,   203,    21,     0,    22,    23,    24,
    -135,  -135,  -135,  -135,  -135,  -135,     4,     0,     0,     5,
       6,     7,     8,     9,    10,     0,     0,    11,    25,    26,
     -33,     0,    12,    13,     0,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,    19,    20,     0,     0,     4,
       0,     0,     5,     6,     7,     8,     9,    10,     0,    21,
      11,    22,    23,    24,     0,    12,    13,     0,    14,     0,
      15,     0,     0,     0,   308,    16,    17,    18,    19,    20,
       0,     0,    25,    26,     0,     0,   189,   190,   191,   192,
     193,   194,    21,     0,    22,    23,    24,   195,     0,     0,
       0,     4,     0,     0,     5,     6,     7,     8,     9,    10,
       0,     0,    11,     0,     0,    25,    26,    12,    13,     0,
      14,     0,    15,     0,     0,     0,   311,    16,    17,    18,
      19,    20,     0,     0,     4,     0,     0,     5,     6,     7,
       8,     9,    10,   287,    21,    11,    22,    23,    24,     0,
     126,    13,     0,    14,     0,    15,     0,     0,     0,   288,
      16,    17,    18,    19,    20,     0,     0,    25,    26,     0,
       0,   309,     0,     0,     0,     0,     0,    21,     0,    22,
      23,    24,     0,     0,     0,     0,   189,   190,   191,   192,
     193,   194,   265,     0,     0,     0,     0,   195,     0,     0,
      25,    26,   189,   190,   191,   192,   193,   194,   266,     0,
       0,     0,     0,   195,   189,   190,   191,   192,   193,   194,
     279,     0,     0,     0,     0,   195,     0,     0,     0,   189,
     190,   191,   192,   193,   194,     0,     0,     0,     0,     0,
     195,     0,     0,     0,     0,   189,   190,   191,   192,   193,
     194,     0,     0,    19,     0,     0,   195,   189,   190,   191,
     192,   193,   194,     0,     0,    91,     0,   141,   195,   142,
     143,   144,    96,    97,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    98,    99,   100,     0,     0,     0,     0,
     101,   102,   103,  -134,    64,    65,    66,    67,    68,    69,
      70,    71,   197,   198,   199,   200,   201,   202,   203,   177,
     178,   227,   152,   155,   158,   161,   164,   167,     0,    91,
       0,    92,     0,    93,    94,    95,    96,    97,    72,    73,
       0,   189,   190,   191,   192,   193,   194,    98,    99,   100,
       0,     0,   195,     0,   101,   102,   103,   104,    91,     0,
      92,     0,    93,    94,    95,    96,    97,     0,     0,     0,
     189,   190,   191,   192,   193,   194,    98,    99,   100,   239,
       0,   195,     0,   101,   102,   103,   189,   190,   191,   192,
     193,   194,     0,     0,     0,   280,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203
};

static const yytype_int16 yycheck[] =
{
      13,    57,    50,     4,    51,    44,     0,    20,    64,    65,
      66,    67,    68,    69,    70,    45,    11,    12,     4,    14,
      15,     4,    51,    70,    44,    11,    46,    47,    48,    45,
      67,    68,    71,    13,    14,    74,    75,    76,    69,    52,
      26,    70,    69,    99,   100,    69,    69,   103,    64,    65,
      66,    67,    68,    69,    70,    46,    47,    48,    69,    98,
      61,    62,    63,    64,    65,    66,    69,    40,    51,    40,
      40,    72,   128,   129,   130,    44,    44,   133,     4,     4,
      24,     4,     4,   122,     4,   124,    51,   103,    64,    65,
      66,    67,    68,    69,    70,   111,     4,   136,   137,   138,
     139,     4,    67,    68,    64,    65,    66,    67,    68,    69,
      70,    71,     4,     4,    74,    75,    76,    61,    62,    63,
      64,    65,    66,     4,     4,     4,    44,   103,    72,     4,
      48,   126,    50,   189,   190,   191,   192,   193,   194,   195,
     179,    61,    62,    63,    64,    65,    66,     3,    69,     4,
      69,    69,    72,    23,     4,    23,    23,   196,   197,   198,
     199,   200,   201,   202,   203,    50,    44,     4,    40,   225,
      69,   227,   220,   221,    40,   205,   136,   137,   138,   139,
      61,    62,    63,    64,    65,    66,    44,    40,     4,   205,
      44,    72,    46,    47,    48,    40,    52,    53,    54,    55,
      56,    57,    58,    59,   217,    44,   219,     4,   264,   265,
     266,    61,    62,    63,    64,    65,    66,    44,    18,    46,
      47,    48,    72,   279,    61,    62,    63,    64,    65,    66,
     269,    51,    42,    51,    44,    72,    46,    70,    70,    49,
      70,    70,    70,   299,   283,    61,    62,    63,    64,    65,
      66,    61,    62,    70,    10,    70,    72,    67,    68,    69,
     273,    61,    62,    63,    64,    65,    66,    70,     4,    18,
      23,    70,    72,   286,   287,   288,     4,    72,    70,    70,
     293,    63,    64,    65,    66,   298,    70,   300,     3,    15,
      72,   281,    -1,     0,     1,    -1,   309,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    44,    -1,    46,
      47,    48,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,     1,    25,    -1,     4,     5,     6,     7,     8,     9,
      67,    68,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    54,    55,    56,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    44,    -1,    46,    47,    48,    72,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    67,    68,    16,
      17,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    -1,     1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    44,    12,    46,
      47,    48,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      67,    68,    52,    53,    54,    55,    56,    57,    58,    59,
      44,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,     1,
      70,    -1,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    67,    68,    17,    18,    -1,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    -1,     1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    44,    12,    46,    47,    48,    -1,    17,    18,
      19,    20,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    67,    68,    52,    53,    54,
      55,    56,    57,    58,    59,    44,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,     1,    70,    -1,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    67,    68,
      17,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    -1,     1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    44,    12,    46,
      47,    48,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    -1,    -1,
      67,    68,    52,    53,    54,    55,    56,    57,    58,    59,
      44,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,     1,
      70,    -1,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    67,    68,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      -1,    -1,     1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    44,    12,    46,    47,    48,    -1,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    41,    26,    27,    28,
      29,    30,    31,    -1,    -1,    67,    68,    52,    53,    54,
      55,    56,    57,    58,    59,    44,    -1,    46,    47,    48,
      54,    55,    56,    57,    58,    59,     1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    67,    68,
      15,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    -1,     1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    44,
      12,    46,    47,    48,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      -1,    -1,    67,    68,    -1,    -1,    61,    62,    63,    64,
      65,    66,    44,    -1,    46,    47,    48,    72,    -1,    -1,
      -1,     1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    -1,    -1,    67,    68,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    -1,    -1,     1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    18,    44,    12,    46,    47,    48,    -1,
      17,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,    18,
      27,    28,    29,    30,    31,    -1,    -1,    67,    68,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    24,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      67,    68,    61,    62,    63,    64,    65,    66,    24,    -1,
      -1,    -1,    -1,    72,    61,    62,    63,    64,    65,    66,
      24,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    -1,    -1,    30,    -1,    -1,    72,    61,    62,    63,
      64,    65,    66,    -1,    -1,    42,    -1,    44,    72,    46,
      47,    48,    49,    50,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    51,    33,    34,    35,    36,    37,    38,
      39,    40,    53,    54,    55,    56,    57,    58,    59,    67,
      68,    41,    65,    66,    67,    68,    69,    70,    -1,    42,
      -1,    44,    -1,    46,    47,    48,    49,    50,    67,    68,
      -1,    61,    62,    63,    64,    65,    66,    60,    61,    62,
      -1,    -1,    72,    -1,    67,    68,    69,    70,    42,    -1,
      44,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    60,    61,    62,    70,
      -1,    72,    -1,    67,    68,    69,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    -1,    72,    52,    53,
      54,    55,    56,    57,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    74,    75,     0,     1,     4,     5,     6,     7,     8,
       9,    12,    17,    18,    20,    22,    27,    28,    29,    30,
      31,    44,    46,    47,    48,    67,    68,    76,    77,    78,
      80,    81,    84,    85,    86,    87,    89,    91,    92,    93,
      94,     4,    11,    26,    69,    69,    69,    69,    79,    79,
      79,    75,    79,    46,    47,    48,    79,    69,    69,    44,
      46,    47,    48,    75,    33,    34,    35,    36,    37,    38,
      39,    40,    67,    68,    40,    40,    40,    44,    44,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,    42,    44,    46,    47,    48,    49,    50,    60,    61,
      62,    67,    68,    69,    70,    95,    96,    97,    98,    99,
      44,    69,    98,    99,    44,    46,    47,    48,    44,    46,
      47,    48,    69,    88,    69,    88,    17,    75,    23,    23,
      23,    44,    44,    69,    95,    50,    40,    40,    40,    40,
      32,    44,    46,    47,    48,    89,    90,    95,    96,    97,
      98,    89,    90,    95,    89,    90,    95,    89,    90,    95,
      89,    90,    95,    89,    90,    95,    89,    90,    95,    89,
      97,    89,    97,    89,    97,    89,    97,    67,    68,    69,
      97,    95,    95,    44,    44,    95,    96,    98,     4,    61,
      62,    63,    64,    65,    66,    72,    52,    53,    54,    55,
      56,    57,    58,    59,    70,    51,    98,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    97,    10,    97,    18,
      79,    21,    95,    95,    95,    23,    95,    41,    70,    89,
      97,    89,    97,    89,    97,    89,    97,    97,   100,    70,
      70,    70,    95,    95,    95,    95,    95,    95,    95,    97,
      97,    97,    97,    97,    97,    97,    97,    99,    70,    75,
      70,    75,    88,    88,    24,    24,    24,    95,    95,    41,
     101,    70,    11,    16,    83,    19,    95,    95,    95,    24,
      70,    97,    75,    13,    14,    82,    18,    18,    18,    95,
     101,    11,    97,     3,    15,    75,    75,    75,    18,    25,
       3,    75,    26,    26,    26,    75,    95,    75,    26,    18,
      75,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    73,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    78,    79,    80,    80,
      80,    81,    82,    82,    83,    83,    84,    85,    86,    87,
      87,    87,    87,    87,    87,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    91,    92,    93,
      93,    93,    93,    94,    94,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    98,    99,    99,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     1,     6,     4,     3,     0,     6,     8,
       2,     8,     0,     3,     0,     5,     6,     5,     5,    12,
      10,     9,     9,     9,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     1,     1,     4,     4,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     1,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     1,     1,     4,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     3,
       1,     1,     3,     1,     1,     0,     2,     0,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: stmtlist  */
#line 264 "interpreter.y"
                  { 
			// Create a new AST
			(yyval.prog) = new lp::AST((yyvsp[0].stmts)); 

			// Assign the AST to the root
			root = (yyval.prog);

			if (interactiveMode == true){
				// End of parsing
				std::cout << std::endl;
				std::cout <<  BICYAN;
				std::cout <<  ">>>>>>> End of program <<<<<<<";
				std::cout << std::endl;
				std::cout << RESET;

				YYACCEPT;

			}else if (interactiveMode == false && yynerrs == 0){
				// End of parsing
				std::cout << std::endl;
				std::cout <<  BIGREEN;
				std::cout <<  ">>>>>>> Correct parsing " << progname << " <<<<<<<";
				std::cout << std::endl;
				std::cout << RESET;

				char answer;

				do{
					std::cout << std::endl;
					std::cout <<  BIYELLOW;
					std::cout << "¿Do you want to run the program? (y/n): ";
					std::cout << RESET;

					std::cin >> answer; 
					if (char(tolower(answer)) == 'y') {
						system("clear");
						break;
					} else if (char(tolower(answer)) == 'n') {

						root = new lp::AST(new std::list<lp::Statement *>());
						break;
					} else {
						std::cout <<  RED;
						std::cout << "Invalid answer" << std::endl;
						std::cout << RESET;
					}
				}while(char(tolower(answer)) != 'y' || char(tolower(answer)) != 'n');

				YYACCEPT;

			}else if (interactiveMode == false && yynerrs != 0){
				 // End of parsing
				std::cout << std::endl;
				std::cout <<  BIRED;
				std::cout << std::endl;
				std::cout <<  "*******************************************" << std::endl;
				std::cout <<  ">>>>>>> End of Parsing with "  << yynerrs << " errors <<<<<<<" << std::endl;
				std::cout <<  "*******************************************";
				std::cout << std::endl;
				std::cout << RESET;

				YYABORT;
			}	
			
		  }
#line 2204 "y.tab.c"
    break;

  case 3: /* stmtlist: %empty  */
#line 333 "interpreter.y"
                  { 

			// create a empty list of statements
			top = new std::list<lp::Statement *>();
			(yyval.stmts) = top;
		  }
#line 2215 "y.tab.c"
    break;

  case 4: /* stmtlist: stmtlist stmt  */
#line 341 "interpreter.y"
                  { 
			// copy up the list and add the stmt to it
			(yyval.stmts) = (yyvsp[-1].stmts);
			(yyval.stmts)->push_back((yyvsp[0].st));

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = (yyval.stmts)->begin(); 
						it != (yyval.stmts)->end(); 
						it++)
				{
					/* (*it)->printAST(); */
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				(yyval.stmts)->clear();
			}
		}
#line 2241 "y.tab.c"
    break;

  case 5: /* stmt: SEMICOLON  */
#line 391 "interpreter.y"
          {
		// Create a new empty statement node
		(yyval.st) = new lp::EmptyStmt(); 
	  }
#line 2250 "y.tab.c"
    break;

  case 6: /* stmt: command SEMICOLON  */
#line 396 "interpreter.y"
          {
		(yyval.st) = (yyvsp[-1].st);
	  }
#line 2258 "y.tab.c"
    break;

  case 7: /* stmt: asgn SEMICOLON  */
#line 400 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 2267 "y.tab.c"
    break;

  case 8: /* stmt: print SEMICOLON  */
#line 405 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 2276 "y.tab.c"
    break;

  case 9: /* stmt: print_string SEMICOLON  */
#line 410 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 2285 "y.tab.c"
    break;

  case 10: /* stmt: read SEMICOLON  */
#line 415 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 2294 "y.tab.c"
    break;

  case 11: /* stmt: read_string SEMICOLON  */
#line 420 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 2303 "y.tab.c"
    break;

  case 12: /* stmt: if SEMICOLON  */
#line 426 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2312 "y.tab.c"
    break;

  case 13: /* stmt: case SEMICOLON  */
#line 431 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2321 "y.tab.c"
    break;

  case 14: /* stmt: while SEMICOLON  */
#line 437 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2330 "y.tab.c"
    break;

  case 15: /* stmt: do_while SEMICOLON  */
#line 442 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2339 "y.tab.c"
    break;

  case 16: /* stmt: block  */
#line 448 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2348 "y.tab.c"
    break;

  case 17: /* stmt: repeat SEMICOLON  */
#line 453 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2357 "y.tab.c"
    break;

  case 18: /* stmt: for SEMICOLON  */
#line 458 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2366 "y.tab.c"
    break;

  case 19: /* stmt: VARIABLE PLUSPLUS  */
#line 463 "interpreter.y"
         { 
		lp::IncrementNode((yyvsp[-1].string), 0).evaluateNumber();
		(yyval.st) = new lp::EmptyStmt();
	 }
#line 2375 "y.tab.c"
    break;

  case 20: /* stmt: PLUSPLUS VARIABLE  */
#line 468 "interpreter.y"
         { 
		lp::IncrementNode((yyvsp[0].string), 1).evaluateNumber();
		(yyval.st) = new lp::EmptyStmt();
	 }
#line 2384 "y.tab.c"
    break;

  case 21: /* stmt: VARIABLE MINUSMINUS  */
#line 473 "interpreter.y"
        { 
		lp::DecrementNode((yyvsp[-1].string), 0).evaluateNumber();
		(yyval.st) = new lp::EmptyStmt();
	}
#line 2393 "y.tab.c"
    break;

  case 22: /* stmt: MINUSMINUS VARIABLE  */
#line 478 "interpreter.y"
        { 
		lp::DecrementNode((yyvsp[0].string), 1).evaluateNumber();
		(yyval.st) = new lp::EmptyStmt();
	}
#line 2402 "y.tab.c"
    break;

  case 23: /* command: CLEAR  */
#line 487 "interpreter.y"
        {
		(yyval.st) = new lp::ClearStmt();
	}
#line 2410 "y.tab.c"
    break;

  case 24: /* command: PLACE LPAREN expnum COMMA expnum RPAREN  */
#line 491 "interpreter.y"
        {
		(yyval.st) = new lp::PlaceStmt((yyvsp[-3].expNode),(yyvsp[-1].expNode));

	}
#line 2419 "y.tab.c"
    break;

  case 25: /* command: STYLE LPAREN STRING RPAREN  */
#line 496 "interpreter.y"
        {
		(yyval.st) = new lp:: StyleStmt((yyvsp[-1].string));
	}
#line 2427 "y.tab.c"
    break;

  case 26: /* block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  */
#line 503 "interpreter.y"
                {
			// Create a new block of statements node
			(yyval.st) = new lp::BlockStmt((yyvsp[-1].stmts)); 
		}
#line 2436 "y.tab.c"
    break;

  case 27: /* controlSymbol: %empty  */
#line 510 "interpreter.y"
                {
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
#line 2445 "y.tab.c"
    break;

  case 28: /* if: IF controlSymbol cond THEN stmtlist END_IF  */
#line 519 "interpreter.y"
    {
		
			// Create a new if statement node
			(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;		
	}
#line 2458 "y.tab.c"
    break;

  case 29: /* if: IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF  */
#line 529 "interpreter.y"
         {

		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), (yyvsp[-3].stmts), (yyvsp[-1].stmts));
		control--;
		
	 }
#line 2470 "y.tab.c"
    break;

  case 30: /* if: error END_IF  */
#line 536 "interpreter.y"
                        {(yyval.st) = new lp::EmptyStmt(); top->clear();yyclearin;
			yyerrok;}
#line 2477 "y.tab.c"
    break;

  case 31: /* case: CASE controlSymbol LPAREN exp RPAREN listOfValues default END_CASE  */
#line 544 "interpreter.y"
        {
		(yyval.st) = new lp::CaseStmt((yyvsp[-4].expNode), (yyvsp[-2].caseValues), (yyvsp[-1].stmts));

		control--;
	}
#line 2487 "y.tab.c"
    break;

  case 32: /* default: %empty  */
#line 553 "interpreter.y"
        {
		(yyval.stmts) = NULL;
	}
#line 2495 "y.tab.c"
    break;

  case 33: /* default: DEFAULT COLON stmtlist  */
#line 557 "interpreter.y"
        {
		(yyval.stmts) = (yyvsp[0].stmts);
	}
#line 2503 "y.tab.c"
    break;

  case 34: /* listOfValues: %empty  */
#line 563 "interpreter.y"
        {
		(yyval.caseValues) = new struct lp::values;

		(yyval.caseValues)->valuesNum = new std::map<int, std::list<lp::Statement *> >();
		(yyval.caseValues)->valuesCad = new std::map<std::string, std::list<lp::Statement *> >();
		(yyval.caseValues)->valuesLog = new std::map<bool, std::list<lp::Statement *> >();
	}
#line 2515 "y.tab.c"
    break;

  case 35: /* listOfValues: listOfValues VALUE exp COLON stmtlist  */
#line 573 "interpreter.y"
        {
		(yyval.caseValues) = (yyvsp[-4].caseValues);

		/* First time a map is filled */
		if ((yyval.caseValues)->valuesNum->size() == 0 && (yyval.caseValues)->valuesCad->size() == 0 && (yyval.caseValues)->valuesLog->size() == 0){
			
			/* Fill a map according to the type of the label */
			switch((yyvsp[-2].expNode)->getType()){

				case NUMBER:

					(yyval.caseValues)->valuesNum->insert(std::make_pair((yyvsp[-2].expNode)->evaluateNumber(), *(yyvsp[0].stmts)));

				break;
				case BOOL:
					
					(yyval.caseValues)->valuesLog->insert(std::make_pair((yyvsp[-2].expNode)->evaluateBool(), *(yyvsp[0].stmts)));

				break;
				case STRING:
					
					(yyval.caseValues)->valuesCad->insert(std::make_pair((yyvsp[-2].expNode)->evaluateString(), *(yyvsp[0].stmts)));

				break;

			} 

		/* Other times */
		}else{ 
			
			/* The numeric map was filled */
			if ((yyval.caseValues)->valuesNum->size() != 0){

				/* Check label type */
				if ((yyvsp[-2].expNode)->getType() == NUMBER){

					if ((yyval.caseValues)->valuesNum->count((yyvsp[-2].expNode)->evaluateNumber())){
						execerror("Syntax error in \"case statement\": There are duplicate values", "case");
				
					}else{
						(yyval.caseValues)->valuesNum->insert(std::make_pair((yyvsp[-2].expNode)->evaluateNumber(), *(yyvsp[0].stmts)));
					}

				}else{
					execerror("Semantic error: The values type are different", "case");
				}

			/* The string map was filled */
			}else if ((yyval.caseValues)->valuesCad->size() != 0){

				/* Check the label type */
				if ((yyvsp[-2].expNode)->getType() == STRING){

					if ((yyval.caseValues)->valuesCad->count((yyvsp[-2].expNode)->evaluateString())){
						execerror("Syntax error in \"case statement\": There are duplicate values", "case");
				
					}else{
						(yyval.caseValues)->valuesCad->insert(std::make_pair((yyvsp[-2].expNode)->evaluateString(), *(yyvsp[0].stmts)));
					}
				}else{
					execerror("Semantic error: The values type are different", "case");


				}

			/* The logic map was filled */	
			}else if ((yyval.caseValues)->valuesLog->size() != 0){

				/* Check the label type */
				if ((yyvsp[-2].expNode)->getType() == BOOL){

					if ((yyval.caseValues)->valuesLog->count((yyvsp[-2].expNode)->evaluateBool())){
						execerror("Syntax error in \"case statement\": There are duplicate values", "case");
				
					}else{
						(yyval.caseValues)->valuesLog->insert(std::make_pair((yyvsp[-2].expNode)->evaluateBool(), *(yyvsp[0].stmts)));
					}
				}else{
					execerror("Semantic error: The values type are different", "case");

				}
			}
		}


		
	}
#line 2607 "y.tab.c"
    break;

  case 36: /* while: WHILE controlSymbol cond DO stmtlist END_WHILE  */
#line 667 "interpreter.y"
                {
		
			// Create a new while statement node
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
        }
#line 2620 "y.tab.c"
    break;

  case 37: /* do_while: DO stmtlist WHILE controlSymbol cond  */
#line 679 "interpreter.y"
                {
			// Create a new do-while statement node
			(yyval.st) = new lp::DoWhileStmt((yyvsp[0].expNode), (yyvsp[-3].stmts));

			// To control the interactive mode
			control--;
		}
#line 2632 "y.tab.c"
    break;

  case 38: /* repeat: REPEAT controlSymbol stmtlist UNTIL cond  */
#line 689 "interpreter.y"
                {
			// Create a new while statement node
			(yyval.st) = new lp::RepeatStmt((yyvsp[0].expNode), (yyvsp[-2].stmts));

			// To control the interactive mode
			control--;
        }
#line 2644 "y.tab.c"
    break;

  case 39: /* for: FOR controlSymbol VARIABLE FROM expnum TO expnum STEP expnum DO stmtlist END_FOR  */
#line 699 "interpreter.y"
          {
			// Create a new for statement node
			(yyval.st) = new lp::ForStmt((yyvsp[-9].string), (yyvsp[-7].expNode), (yyvsp[-5].expNode), (yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
      }
#line 2656 "y.tab.c"
    break;

  case 40: /* for: FOR controlSymbol VARIABLE FROM expnum TO expnum DO stmtlist END_FOR  */
#line 708 "interpreter.y"
          {
			
			// Create a new for statement node
			(yyval.st) = new lp::ForStmt((yyvsp[-7].string), (yyvsp[-5].expNode), (yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
      }
#line 2669 "y.tab.c"
    break;

  case 41: /* for: FOR NUMERIC_CONSTANT FROM expnum TO expnum DO stmtlist END_FOR  */
#line 717 "interpreter.y"
          {
		execerror("Syntax error: The variable cannot be a numeric constant", (yyvsp[-7].string));
	  }
#line 2677 "y.tab.c"
    break;

  case 42: /* for: FOR LOGICAL_CONSTANT FROM expnum TO expnum DO stmtlist END_FOR  */
#line 721 "interpreter.y"
          {
		execerror("Syntax error: The variable cannot be a logical constant", (yyvsp[-7].string));
	  }
#line 2685 "y.tab.c"
    break;

  case 43: /* for: FOR STRING_CONSTANT FROM expnum TO expnum DO stmtlist END_FOR  */
#line 725 "interpreter.y"
          {
		execerror("Syntax error: The variable cannot be a string constant", (yyvsp[-7].string));
	  }
#line 2693 "y.tab.c"
    break;

  case 44: /* for: error END_FOR  */
#line 729 "interpreter.y"
                          {(yyval.st) = new lp::EmptyStmt(); top->clear(); control = 0; yyclearin;
			yyerrok;}
#line 2700 "y.tab.c"
    break;

  case 45: /* cond: LPAREN exp RPAREN  */
#line 736 "interpreter.y"
                { 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 2708 "y.tab.c"
    break;

  case 46: /* asgn: VARIABLE ASSIGNMENT exp  */
#line 745 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2717 "y.tab.c"
    break;

  case 47: /* asgn: VARIABLE PLUS_ASSIGNMENT expnum  */
#line 750 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::PlusAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));

		}
#line 2727 "y.tab.c"
    break;

  case 48: /* asgn: VARIABLE MINUS_ASSIGNMENT expnum  */
#line 756 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::MinusAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));

		}
#line 2737 "y.tab.c"
    break;

  case 49: /* asgn: VARIABLE MULTIPLICATION_ASSIGNMENT expnum  */
#line 762 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::MultiplicationAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));

		}
#line 2747 "y.tab.c"
    break;

  case 50: /* asgn: VARIABLE DIVISION_ASSIGNMENT expnum  */
#line 768 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::DivisionAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));

		}
#line 2757 "y.tab.c"
    break;

  case 51: /* asgn: VARIABLE INTEGER_DIVISION_ASSIGNMENT expnum  */
#line 774 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::IntegerDivisionAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));

		}
#line 2767 "y.tab.c"
    break;

  case 52: /* asgn: VARIABLE POWER_ASSIGNMENT expnum  */
#line 780 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::PowerAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));

		}
#line 2777 "y.tab.c"
    break;

  case 53: /* asgn: VARIABLE MODULO_ASSIGNMENT expnum  */
#line 786 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::ModuloAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));

		}
#line 2787 "y.tab.c"
    break;

  case 54: /* asgn: CONST VARIABLE ASSIGNMENT exp  */
#line 793 "interpreter.y"
                { 
			// Create a new const assignment node
			(yyval.st) = new lp::ConstAssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2796 "y.tab.c"
    break;

  case 55: /* asgn: VARIABLE ASSIGNMENT asgn  */
#line 801 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2805 "y.tab.c"
    break;

  case 56: /* asgn: VARIABLE PLUS_ASSIGNMENT asgn  */
#line 806 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::PlusAssignmentStmt((yyvsp[-2].string), (lp::PlusAssignmentStmt *) (yyvsp[0].st));
		}
#line 2814 "y.tab.c"
    break;

  case 57: /* asgn: VARIABLE MINUS_ASSIGNMENT asgn  */
#line 811 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::MinusAssignmentStmt((yyvsp[-2].string), (lp::MinusAssignmentStmt *) (yyvsp[0].st));
		}
#line 2823 "y.tab.c"
    break;

  case 58: /* asgn: VARIABLE MULTIPLICATION_ASSIGNMENT asgn  */
#line 816 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::MultiplicationAssignmentStmt((yyvsp[-2].string), (lp::MultiplicationAssignmentStmt *) (yyvsp[0].st));
		}
#line 2832 "y.tab.c"
    break;

  case 59: /* asgn: VARIABLE DIVISION_ASSIGNMENT asgn  */
#line 821 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::DivisionAssignmentStmt((yyvsp[-2].string), (lp::DivisionAssignmentStmt *) (yyvsp[0].st));
		}
#line 2841 "y.tab.c"
    break;

  case 60: /* asgn: VARIABLE INTEGER_DIVISION_ASSIGNMENT asgn  */
#line 826 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::IntegerDivisionAssignmentStmt((yyvsp[-2].string), (lp::IntegerDivisionAssignmentStmt *) (yyvsp[0].st));
		}
#line 2850 "y.tab.c"
    break;

  case 61: /* asgn: VARIABLE POWER_ASSIGNMENT asgn  */
#line 831 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::PowerAssignmentStmt((yyvsp[-2].string), (lp::PowerAssignmentStmt *) (yyvsp[0].st));
		}
#line 2859 "y.tab.c"
    break;

  case 62: /* asgn: VARIABLE MODULO_ASSIGNMENT asgn  */
#line 836 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::ModuloAssignmentStmt((yyvsp[-2].string), (lp::ModuloAssignmentStmt *) (yyvsp[0].st));
		}
#line 2868 "y.tab.c"
    break;

  case 63: /* asgn: CONST VARIABLE ASSIGNMENT asgn  */
#line 843 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::ConstAssignmentStmt((yyvsp[-2].string), (lp::ConstAssignmentStmt *) (yyvsp[0].st));
		}
#line 2877 "y.tab.c"
    break;

  case 64: /* asgn: VARIABLE PLUS_ASSIGNMENT auxasgn  */
#line 850 "interpreter.y"
                { 
			execerror("Syntax error: The expression should be numeric", (yyvsp[-2].string));

		}
#line 2886 "y.tab.c"
    break;

  case 65: /* asgn: VARIABLE MINUS_ASSIGNMENT auxasgn  */
#line 855 "interpreter.y"
                { 
			execerror("Syntax error: The expression should be numeric", (yyvsp[-2].string));

		}
#line 2895 "y.tab.c"
    break;

  case 66: /* asgn: VARIABLE MULTIPLICATION_ASSIGNMENT auxasgn  */
#line 860 "interpreter.y"
                { 
			execerror("Syntax error: The expression should be numeric", (yyvsp[-2].string));

		}
#line 2904 "y.tab.c"
    break;

  case 67: /* asgn: VARIABLE DIVISION_ASSIGNMENT auxasgn  */
#line 865 "interpreter.y"
                { 
			execerror("Syntax error: The expression should be numeric", (yyvsp[-2].string));

		}
#line 2913 "y.tab.c"
    break;

  case 68: /* asgn: VARIABLE INTEGER_DIVISION_ASSIGNMENT auxasgn  */
#line 870 "interpreter.y"
                { 
			execerror("Syntax error: The expression should be numeric", (yyvsp[-2].string));

		}
#line 2922 "y.tab.c"
    break;

  case 69: /* asgn: VARIABLE POWER_ASSIGNMENT auxasgn  */
#line 875 "interpreter.y"
                { 
			execerror("Syntax error: The expression should be numeric", (yyvsp[-2].string));

		}
#line 2931 "y.tab.c"
    break;

  case 70: /* asgn: VARIABLE MODULO_ASSIGNMENT auxasgn  */
#line 880 "interpreter.y"
                { 
			execerror("Syntax error: The expression should be numeric", (yyvsp[-2].string));

		}
#line 2940 "y.tab.c"
    break;

  case 71: /* asgn: NUMERIC_CONSTANT ASSIGNMENT exp  */
#line 887 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a numeric constant ", (yyvsp[-2].string));
		}
#line 2948 "y.tab.c"
    break;

  case 72: /* asgn: LOGICAL_CONSTANT ASSIGNMENT exp  */
#line 891 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a logical constant ", (yyvsp[-2].string));
		}
#line 2956 "y.tab.c"
    break;

  case 73: /* asgn: STRING_CONSTANT ASSIGNMENT exp  */
#line 895 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a string constant ", (yyvsp[-2].string));
		}
#line 2964 "y.tab.c"
    break;

  case 74: /* asgn: NUMERIC_CONSTANT ASSIGNMENT asgn  */
#line 901 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a numeric constant ",(yyvsp[-2].string));
		}
#line 2972 "y.tab.c"
    break;

  case 75: /* asgn: LOGICAL_CONSTANT ASSIGNMENT asgn  */
#line 905 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a logical constant ",(yyvsp[-2].string));
		}
#line 2980 "y.tab.c"
    break;

  case 76: /* asgn: STRING_CONSTANT ASSIGNMENT asgn  */
#line 909 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a string constant ",(yyvsp[-2].string));
		}
#line 2988 "y.tab.c"
    break;

  case 77: /* asgn: CONST NUMERIC_CONSTANT ASSIGNMENT exp  */
#line 915 "interpreter.y"
                { 
			execerror("Semantic error in assignment: it is not allowed to reassing a numeric constant",(yyvsp[-2].string));

		}
#line 2997 "y.tab.c"
    break;

  case 78: /* asgn: CONST LOGICAL_CONSTANT ASSIGNMENT exp  */
#line 920 "interpreter.y"
                { 
			execerror("Semantic error in assignment: it is not allowed to reassing a logical constant",(yyvsp[-2].string));

		}
#line 3006 "y.tab.c"
    break;

  case 79: /* asgn: CONST STRING_CONSTANT ASSIGNMENT exp  */
#line 925 "interpreter.y"
                { 
			execerror("Semantic error in assignment: it is not allowed to reassing a string constant",(yyvsp[-2].string));

		}
#line 3015 "y.tab.c"
    break;

  case 80: /* asgn: CONST NUMERIC_CONSTANT ASSIGNMENT asgn  */
#line 932 "interpreter.y"
                { 
			execerror("Semantic error in multiple assignment: it is not allowed to reassing a numeric constant ",(yyvsp[-2].string));

		}
#line 3024 "y.tab.c"
    break;

  case 81: /* asgn: CONST LOGICAL_CONSTANT ASSIGNMENT asgn  */
#line 937 "interpreter.y"
                { 
			execerror("Semantic error in multiple assignment: it is not allowed to reassing a logical constant ",(yyvsp[-2].string));

		}
#line 3033 "y.tab.c"
    break;

  case 82: /* asgn: CONST STRING_CONSTANT ASSIGNMENT asgn  */
#line 942 "interpreter.y"
                { 
			execerror("Semantic error in multiple assignment: it is not allowed to reassing a string constant ",(yyvsp[-2].string));

		}
#line 3042 "y.tab.c"
    break;

  case 85: /* print: PRINT LPAREN exp RPAREN  */
#line 953 "interpreter.y"
                {
			// Create a new print node
			(yyval.st) = new lp::PrintStmt((yyvsp[-1].expNode));
		}
#line 3051 "y.tab.c"
    break;

  case 86: /* print: PRINT LPAREN RPAREN SEMICOLON  */
#line 957 "interpreter.y"
                                               {
			execerror("Syntax error: Missing argument", "print");
		}
#line 3059 "y.tab.c"
    break;

  case 87: /* print: error SEMICOLON  */
#line 960 "interpreter.y"
                                 {(yyval.st) = new lp::EmptyStmt(); top->clear(); control = 0; yyclearin;
			yyerrok;}
#line 3066 "y.tab.c"
    break;

  case 88: /* print_string: PRINT_STRING LPAREN auxcad RPAREN  */
#line 965 "interpreter.y"
                {
			// Create a new print node
			(yyval.st) = new lp::PrintStringStmt((yyvsp[-1].expNode));
		}
#line 3075 "y.tab.c"
    break;

  case 89: /* read: READ LPAREN VARIABLE RPAREN  */
#line 972 "interpreter.y"
                {	
			(yyval.st) = new lp::ReadStmt((yyvsp[-1].string));
		}
#line 3083 "y.tab.c"
    break;

  case 90: /* read: READ LPAREN NUMERIC_CONSTANT RPAREN  */
#line 978 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a numeric constant ",(yyvsp[-1].string));
		}
#line 3091 "y.tab.c"
    break;

  case 91: /* read: READ LPAREN LOGICAL_CONSTANT RPAREN  */
#line 982 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a logical constant ",(yyvsp[-1].string));
		}
#line 3099 "y.tab.c"
    break;

  case 92: /* read: READ LPAREN STRING_CONSTANT RPAREN  */
#line 986 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a string constant ",(yyvsp[-1].string));
		}
#line 3107 "y.tab.c"
    break;

  case 93: /* read_string: READ_STRING LPAREN VARIABLE RPAREN  */
#line 992 "interpreter.y"
                {
			// Create a new read node
			 (yyval.st) = new lp::ReadStringStmt((yyvsp[-1].string));
		}
#line 3116 "y.tab.c"
    break;

  case 94: /* read_string: READ_STRING LPAREN NUMERIC_CONSTANT RPAREN  */
#line 999 "interpreter.y"
                {   
 			execerror("Semantic error in \"read_string statement\": it is not allowed to modify a numeric constant ",(yyvsp[-1].string));
		}
#line 3124 "y.tab.c"
    break;

  case 95: /* read_string: READ_STRING LPAREN LOGICAL_CONSTANT RPAREN  */
#line 1003 "interpreter.y"
                {   
 			execerror("Semantic error in \"read_string statement\": it is not allowed to modify a logical constant ",(yyvsp[-1].string));
		}
#line 3132 "y.tab.c"
    break;

  case 96: /* read_string: READ_STRING LPAREN STRING_CONSTANT RPAREN  */
#line 1007 "interpreter.y"
                {   
 			execerror("Semantic error in \"read_string statement\": it is not allowed to modify a string constant ",(yyvsp[-1].string));
		}
#line 3140 "y.tab.c"
    break;

  case 97: /* expnum: NUMBER  */
#line 1014 "interpreter.y"
                { 
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 3149 "y.tab.c"
    break;

  case 98: /* expnum: VARIABLE PLUSPLUS  */
#line 1020 "interpreter.y"
                { 
			(yyval.expNode) = new lp::IncrementNode((yyvsp[-1].string), 0);
		}
#line 3157 "y.tab.c"
    break;

  case 99: /* expnum: PLUSPLUS VARIABLE  */
#line 1024 "interpreter.y"
                { 
			(yyval.expNode) = new lp::IncrementNode((yyvsp[0].string), 1);
		}
#line 3165 "y.tab.c"
    break;

  case 100: /* expnum: VARIABLE MINUSMINUS  */
#line 1028 "interpreter.y"
                { 
			(yyval.expNode) = new lp::DecrementNode((yyvsp[-1].string), 0);
		}
#line 3173 "y.tab.c"
    break;

  case 101: /* expnum: MINUSMINUS VARIABLE  */
#line 1032 "interpreter.y"
                { 
			(yyval.expNode) = new lp::DecrementNode((yyvsp[0].string), 1);	
		}
#line 3181 "y.tab.c"
    break;

  case 102: /* expnum: expnum PLUS expnum  */
#line 1036 "interpreter.y"
                { 
			// Create a new plus node
			(yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 3190 "y.tab.c"
    break;

  case 103: /* expnum: expnum MINUS expnum  */
#line 1042 "interpreter.y"
        {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 3199 "y.tab.c"
    break;

  case 104: /* expnum: expnum MULTIPLICATION expnum  */
#line 1048 "interpreter.y"
                { 
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 3208 "y.tab.c"
    break;

  case 105: /* expnum: expnum DIVISION expnum  */
#line 1054 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 3217 "y.tab.c"
    break;

  case 106: /* expnum: expnum INTEGER_DIVISION expnum  */
#line 1060 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::IntegerDivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 3226 "y.tab.c"
    break;

  case 107: /* expnum: LPAREN expnum RPAREN  */
#line 1066 "interpreter.y"
        { 
		    // just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 3235 "y.tab.c"
    break;

  case 108: /* expnum: PLUS expnum  */
#line 1072 "interpreter.y"
                { 
		  // Create a new unary plus node	
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 3244 "y.tab.c"
    break;

  case 109: /* expnum: MINUS expnum  */
#line 1078 "interpreter.y"
                { 
		  // Create a new unary minus node	
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 3253 "y.tab.c"
    break;

  case 110: /* expnum: expnum MODULO expnum  */
#line 1084 "interpreter.y"
                {
		  // Create a new modulo node	

		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 3263 "y.tab.c"
    break;

  case 111: /* expnum: expnum POWER expnum  */
#line 1091 "interpreter.y"
        { 
		  // Create a new power node	
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 3272 "y.tab.c"
    break;

  case 112: /* expnum: VARIABLE  */
#line 1097 "interpreter.y"
                {
		  // Create a new variable node	
			(yyval.expNode) = new lp::VariableNode((yyvsp[0].string));  
		}
#line 3281 "y.tab.c"
    break;

  case 113: /* expnum: NUMERIC_CONSTANT  */
#line 1103 "interpreter.y"
                {
		  // Create a new constant node	
		  (yyval.expNode) = new lp::NumericConstantNode((yyvsp[0].string));

		}
#line 3291 "y.tab.c"
    break;

  case 114: /* expnum: BUILTIN LPAREN listOfExp RPAREN  */
#line 1110 "interpreter.y"
                {
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol((yyvsp[-3].string));

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) (yyvsp[-1].parameters)->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_0((yyvsp[-3].string));
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 1 parameter node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_1((yyvsp[-3].string),e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = (yyvsp[-1].parameters)->front();
							(yyvsp[-1].parameters)->pop_front();
							lp::ExpNode *e2 = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 2 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_2((yyvsp[-3].string),e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", (yyvsp[-3].string));
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", (yyvsp[-3].string));
		}
#line 3341 "y.tab.c"
    break;

  case 115: /* explog: LPAREN explog RPAREN  */
#line 1160 "interpreter.y"
                { 
			// just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 3350 "y.tab.c"
    break;

  case 116: /* explog: LOGICAL_CONSTANT  */
#line 1165 "interpreter.y"
                {
		// Create a new constant node	
			(yyval.expNode) = new lp::LogicalConstantNode((yyvsp[0].string));

		}
#line 3360 "y.tab.c"
    break;

  case 117: /* explog: exp GREATER_THAN exp  */
#line 1171 "interpreter.y"
                {
		  // Create a new "greater than" node	
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3369 "y.tab.c"
    break;

  case 118: /* explog: exp GREATER_OR_EQUAL exp  */
#line 1177 "interpreter.y"
                {
		  // Create a new "greater or equal" node	
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3378 "y.tab.c"
    break;

  case 119: /* explog: exp LESS_THAN exp  */
#line 1183 "interpreter.y"
                {
		  // Create a new "less than" node	
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3387 "y.tab.c"
    break;

  case 120: /* explog: exp LESS_OR_EQUAL exp  */
#line 1189 "interpreter.y"
                {
		  // Create a new "less or equal" node	
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3396 "y.tab.c"
    break;

  case 121: /* explog: exp EQUAL exp  */
#line 1195 "interpreter.y"
                {
		  // Create a new "equal" node	
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3405 "y.tab.c"
    break;

  case 122: /* explog: exp NOT_EQUAL exp  */
#line 1201 "interpreter.y"
                {
		  // Create a new "not equal" node	
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3414 "y.tab.c"
    break;

  case 123: /* explog: exp AND exp  */
#line 1207 "interpreter.y"
                {
		  // Create a new "logic and" node	
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3423 "y.tab.c"
    break;

  case 124: /* explog: exp OR exp  */
#line 1213 "interpreter.y"
                {
		  // Create a new "logic or" node	
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 3432 "y.tab.c"
    break;

  case 125: /* explog: NOT exp  */
#line 1219 "interpreter.y"
                {
		  // Create a new "logic negation" node	
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 3441 "y.tab.c"
    break;

  case 129: /* expcad: LPAREN expcad RPAREN  */
#line 1235 "interpreter.y"
        { 
	    // just copy up the expression node 
		(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 3450 "y.tab.c"
    break;

  case 130: /* expcad: STRING  */
#line 1241 "interpreter.y"
                {
 			(yyval.expNode) = new lp::StringNode((yyvsp[0].string));
		}
#line 3458 "y.tab.c"
    break;

  case 131: /* expcad: STRING_CONSTANT  */
#line 1245 "interpreter.y"
                {
			// Create a new constant node	
			(yyval.expNode) = new lp::StringConstantNode((yyvsp[0].string));
		}
#line 3467 "y.tab.c"
    break;

  case 132: /* expcad: auxcad CONCATENATION auxcad  */
#line 1250 "interpreter.y"
                {
		  // Create a new "operator concatenation" node	
 			(yyval.expNode) = new lp::ConcatenationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 3476 "y.tab.c"
    break;

  case 134: /* auxcad: VARIABLE  */
#line 1260 "interpreter.y"
                {
		  // Create a new variable node
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].string));
		}
#line 3485 "y.tab.c"
    break;

  case 135: /* listOfExp: %empty  */
#line 1269 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 3494 "y.tab.c"
    break;

  case 136: /* listOfExp: exp restOfListOfExp  */
#line 1275 "interpreter.y"
                        {
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 3505 "y.tab.c"
    break;

  case 137: /* restOfListOfExp: %empty  */
#line 1285 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 3514 "y.tab.c"
    break;

  case 138: /* restOfListOfExp: COMMA exp restOfListOfExp  */
#line 1291 "interpreter.y"
                        {
				// Get the list of expressions
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 3526 "y.tab.c"
    break;


#line 3530 "y.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1302 "interpreter.y"

