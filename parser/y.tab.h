/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 60 "y.tab.h"

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

#line 238 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
