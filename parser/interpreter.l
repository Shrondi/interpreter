/*! 
  \file interpreter.l
  \brief Lexical or scanner file
*/
%{
#include <iostream>

/*********************/
/* NEW in example 4 */
/* atof */
#include <stdlib.h>
/*********************/

/* Macros for the screen */
#include "../includes/macros.hpp"

/*********************/
/* 
  NEW in example 16 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "../ast/ast.hpp"
/*********************/

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"

/********************/
/* NEW in example 3 */
#include "../error/error.hpp"
/********************/


/*********************************************/
/* NEW in example 7 */
/* Table of symbols */
#include "../table/table.hpp"

#include "../table/numericVariable.hpp"


extern lp::Table table; //!< External Table of Symbols
/*********************************************/

extern int lineNumber; //!< External line counter

extern int yynerrs;

/* uso de strdup */
#include <string.h>

#include <algorithm> /* Uso de transform */

std::string comment;
%}

%option noyywrap


/*! \name REGULAR DEFINITIONS  */

DIGIT  [0-9] 

LETTER [a-zA-Z]

UNDERLINE [_]

NUMBER {DIGIT}+(\.?{DIGIT}*((E|e)[+-]?{DIGIT}+)?)?

NUMBER2 {DIGIT}*(\.?{DIGIT}+((E|e)[+-]?{DIGIT}+)?)?

IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|{UNDERLINE}({LETTER}|{DIGIT}))*

/* NEW in example 3 */
/* STATE  */
%x ERROR ESTADO_COMENTARIO ESTADO_CADENA

/*! \name REGULAR EXPRESSIONS  */
%%

[ \t] 	{ ; }    /* skip white space and tabular */

#.*		{ ; }	/* One line comments */

<INITIAL><<+         {BEGIN(ESTADO_COMENTARIO); comment = yytext;}
<INITIAL>>>+	{BEGIN(INITIAL); warning("Lexical error: unopen comment", yytext);}
<ESTADO_COMENTARIO>>>+      BEGIN(INITIAL);
<ESTADO_COMENTARIO>.  // eat comment in chunks
<ESTADO_COMENTARIO><<EOF>> {++yynerrs; warning("Lexical error: unterminated comment", comment); yyterminate();}
<ESTADO_COMENTARIO>\n       	lineNumber++;


\n      { 
			/* Line counter */
           	lineNumber++; 
	
			/* MODIFIED in example 3 */
			/* COMMENTED in example 5 */
        	/* return NEWLINE; */
        }

":"		{return COLON;}

";"		{
			/* NEW in example 5 */
			return SEMICOLON;
		}


","		{
			/* NEW in example 14 */
			return COMMA;
		}

{NUMBER}|{NUMBER2}  {
					  /* MODIFIED in example 4 */
					  /* Conversion of type and sending of the numerical value to the parser */
					   yylval.number = atof(yytext); 

                       return NUMBER; 
                      }


<INITIAL>"'"			   {
			    /* Se activa el reconocimiento de la cadena */
			    BEGIN(ESTADO_CADENA);
			  }


<ESTADO_CADENA>"'"  { /* Fin de la cadena: se vuelve al estado por defecto */
			         BEGIN(INITIAL); 

					 yytext[yyleng-1] = '\0';

					yylval.string =  strdup(yytext);
					return STRING;
					}
					
<ESTADO_CADENA><<EOF>> {++yynerrs; yyrestart(yyin); warning("Lexical error: unterminated string", yytext); BEGIN(INITIAL);}


<ESTADO_CADENA>"\\\'"     {yymore();}

<ESTADO_CADENA>.          {yymore();}

<ESTADO_CADENA>\n         {yymore();}


{IDENTIFIER}   		 {
						 /* NEW in example 7 */
						 std::string identifier(yytext);

						 /*Convertimos a minusculas */

						 std::transform(identifier.begin(), identifier.end(), identifier.begin(), ::tolower);

						/* 
                          strdup() function returns a pointer to a new string 
                          which  is a duplicate of the string yytext
                        */
						  yylval.string =  strdup(identifier.c_str()); /* Con c_str() obtenemos la string a char * como en C */

						/* If the identifier is not in the table of symbols then it is inserted */	
						 if (table.lookupSymbol(identifier) == false)
							{
								/* 
								 The identifier is inserted into the symbol table 
								 as undefined Variable with value 0.0
								*/
								lp::NumericVariable *n = new lp::NumericVariable(identifier,VARIABLE,UNDEFINED,0.0);

								/* A pointer to the new NumericVariable is inserted into the table of symbols */
								table.installSymbol(n);

								/* std::cout << "lex: "<< n->getName() 
										  << "token " << n->getToken()
  										  << std::endl;  */

								return VARIABLE;
							}

						/* MODIFIED in example 11 */
						/* 
							If the identifier is in the table of symbols then its token is returned 
								The identifier can be a variable or a numeric constant
						*/
						else 
							{
								lp::Symbol	*s = table.getSymbol(identifier);


								/* std::cout << "lex: "<< s->getName() 
										  << "token " << s->getToken()
  										  << std::endl; */


								/*  If the identifier is in the table then its token is returned  */
								return s->getToken();
							}
                     }
					 
"--"			{return MINUSMINUS; }
"++"			{return PLUSPLUS; }

"-"				{ return MINUS;  } 			
"+"				{ return PLUS;   } 			

"*"	    		{ return MULTIPLICATION; } 	
"/"     		{ return DIVISION; } 		
"//"			{ return INTEGER_DIVISION; }

"("     		{ return LPAREN; } 			
")"	    		{ return RPAREN; } 			


"||"			{return CONCATENATION; }


"%"     		{ return MODULO; }			

"^"	    		{ return POWER; }			

"+:="			{ return PLUS_ASSIGNMENT; }
"-:= "			{ return MINUS_ASSIGNMENT; }
"*:= "			{ return MULTIPLICATION_ASSIGNMENT; }
"/:= "			{ return DIVISION_ASSIGNMENT; }
"//:= "			{ return INTEGER_DIVISION_ASSIGNMENT; }
"%:= "			{ return MODULO_ASSIGNMENT; }
"^:= "			{ return POWER_ASSIGNMENT; }



":=" 			{ return ASSIGNMENT; }		


"="				{ return EQUAL; }			

"<>"			{ return NOT_EQUAL; }		
		
">="			{ return GREATER_OR_EQUAL; }
		
"<="			{ return LESS_OR_EQUAL; }	
		
">"				{ return GREATER_THAN; }	
		
"<"				{ return LESS_THAN; }		
		
"{"				{ return LETFCURLYBRACKET; } 	
		
"}"				{ return RIGHTCURLYBRACKET; }	


<<EOF>> { /* The interpreter finishes when finds the end of file character */
		
	  	  return 0;
	}


.								{ 	
									/* Any other character */
									/* MODIFIIED in example 3 */
									/* Change to error state */
									BEGIN(ERROR);
									++yynerrs; 
									/* 
										The current value of yytext 
										will be concatenated with the next character
									*/
									yymore();  
								}

<ERROR>[^0-9+\-*/()\^% \t\n\;a-zA-Z=<>!&]	{ /* MODIFIED in examples 5, 7, 15 */
								  /* NEW in example 3 */
								  /* 
									The current value of yytext 
									will be concatenated with the next character
								  */
									yymore(); 
								}

<ERROR>(.|\n)                { 
								/* NEW in example 3 */
								/* Rewind one position */
								yyless(yyleng-1); 

								/* Display the error message */
								warning("Lexical error", yytext);

								/* Restore the initial state */
   								BEGIN(INITIAL);
							}
%%

