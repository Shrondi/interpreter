/*!	
	\file   init.hpp
	\brief   Prototype of the function for the initialization of table of symbols
	\author  
	\date    2017-12-5
	\version 1.0
*/

#ifndef _INIT_HPP_
#define _INIT_HPP_

// sin, cos, atan, fabs, ...
#include <math.h>

#include "table.hpp"

// IMPORTANT: This file must be before y.tab.h
#include "../ast/ast.hpp"
///////////////////////////////////////

//  interpreter.tab.h contains the number values of the tokens produced by the parser
#include "../parser/interpreter.tab.h"

///////////////////////////////////////
// NEW in example 13
#include "builtinFunction.hpp"
#include "builtinParameter1.hpp"
///////////////////////////////////////

///////////////////////////////////////
// NEW in example 14
#include "builtinParameter0.hpp"
#include "builtinParameter2.hpp"
///////////////////////////////////////

/*!
  \ brief Predefined numeric constants
*/
static struct {
          std::string name ;
	      double value;
	      } numericConstant[] = {
	                    {"pi",    3.14159265358979323846},
	                    {"e",     2.71828182845904523536},
	                    {"gamma", 0.57721566490153286060},
	                    {"deg",  57.29577951308232087680},
	                    {"phi",   1.61803398874989484820},
						{"inf",   INFINITY},
						{"-inf",   -INFINITY},
	                    {"",      0}
	                   };

/*!
  \ brief Predefined logical constants
*/
// NEW in example 16
static struct {
          std::string name ;
	      bool value;
	      } logicalConstant[] = { 
	                    {"true", true},
	                    {"false", false},
	                    {"",      0}
	                   };


// NEW in example 12 
/*!
  \ brief Predefined keywords
*/
static struct {
          std::string name ;
	      int token;
	      } keyword[] = {
						{"or", OR},
						{"and", AND},
						{"not", NOT},
	                    {"print", PRINT},
						{"print_string", PRINT_STRING},
	                    {"read",  READ},
						{"read_string",  READ_STRING},
						{"if",	  IF},
						{"then",	  THEN},
						{"else",  ELSE}, 	
						{"end_if",	  END_IF},
						{"case", CASE},
						{"value", VALUE}, 
						{"default", DEFAULT},
						{"end_case", END_CASE},    	
						{"while", WHILE},	
						{"do",	  DO},
						{"end_while", END_WHILE},
						{"repeat", REPEAT},
						{"until", UNTIL},
						{"for", FOR},
						{"from", FROM},
						{"to", TO},
						{"step", STEP},
						{"end_for", END_FOR},
						{"clear_screen", CLEAR},
						{"place", PLACE},
						{"style", STYLE},
						{"const", CONST},
	                    {"",      0}
	                   };



// NEW in example 13

static struct {    /* Predefined functions names */ 
                std::string name ;
				lp::TypePointerDoubleFunction_1 function;
              } function_1 [] = {
	                   {"sin",     sin},
		               {"cos",     cos},
					   {"tan",     tan},
		               {"atan",    atan},
		               {"log",     Log},
		               {"log10",   Log10},
		               {"exp",     Exp},
		               {"sqrt",    Sqrt},
		               {"integer", integer},
		               {"abs",     fabs},
					   {"to_degrees", to_degrees},
					   {"to_radians", to_radians},    
		               {"",       0}
		              };

// NEW in example 14
static struct {   
                std::string name ;
				lp::TypePointerDoubleFunction_0 function;
              } function_0 [] = {
						{"random", Random},
		                {"",       0}
		              };


// NEW in example 14

static struct {    /* Nombres predefinidos de funciones con 2 argumentos */ 
                std::string name ;
				lp::TypePointerDoubleFunction_2 function;
              } function_2 [] = {
	                   {"atan2",   Atan2},
		               {"",       0}
		              };







/*!		
	\brief   Initialize the table of symbols
	\return  void 
*/

void init(lp::Table &t);

// End of _INIT_HPP_
#endif
