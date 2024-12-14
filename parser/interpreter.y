/*! 
  \file interpreter.y
  \brief Grammar file
*/


%{
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
extern int yylex (void);


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

%}

/* In case of a syntactic error, more information is shown */
/* DEPRECATED */
/* %error-verbose */

/* ALTERNATIVA a %error-verbose */
%define parse.error verbose


/* Initial grammar symbol */
%start program

/*******************************************/
/* Data type YYSTYPE  */
/* NEW in example 4 */

%code requires {
	namespace lp{
		 struct values {
			std::map<int, std::list<lp::Statement *> > *valuesNum;
			std::map<std::string, std::list<lp::Statement *> > *valuesCad;
			std::map<bool, std::list<lp::Statement *> > *valuesLog; 

    	};
	}
}

%union {
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
}

/* Type of the non-terminal symbols */
// New in example 17: cond
%type <expNode> exp cond expnum explog expcad auxcad auxasgn

%type <caseValues> listOfValues

/* New in example 14 */
%type <parameters> listOfExp restOfListOfExp

%type <stmts> stmtlist default

// New in example 17: if, while, block
%type <st> stmt asgn print print_string read read_string if case while do_while block repeat for command

%type <prog> program

/* Defined tokens */

/* Minimum precedence */

%token YYEOF 0

/*******************************************/
/* NEW in example 5 */
%token COLON SEMICOLON
/*******************************************/

/* NEW in example 17: IF, ELSE, WHILE */
%token PRINT PRINT_STRING READ READ_STRING IF THEN END_IF CASE VALUE DEFAULT END_CASE ELSE WHILE DO END_WHILE REPEAT UNTIL FOR FROM TO STEP END_FOR CLEAR PLACE STYLE CONST

/* NEW in example 17 */
%token LETFCURLYBRACKET RIGHTCURLYBRACKET

/* NEW in example 7 */
%right PLUS_ASSIGNMENT MINUS_ASSIGNMENT MULTIPLICATION_ASSIGNMENT INTEGER_DIVISION_ASSIGNMENT DIVISION_ASSIGNMENT MODULO_ASSIGNMENT POWER_ASSIGNMENT ASSIGNMENT

/* NEW in example 14 */
%token COMMA

/*******************************************/
/* MODIFIED in example 4 */
%token <number> NUMBER
/*******************************************/

/*******************************************/
/* NEW in example 15 */
%token <logic> BOOL
/*******************************************/

/* MODIFIED in examples 11, 13 */
%token <string> VARIABLE UNDEFINED NUMERIC_CONSTANT LOGICAL_CONSTANT STRING_CONSTANT BUILTIN STRING

/* Left associativity */

/*******************************************************/
/* NEW in example 15 */

%left CONCATENATION

%left OR

%left AND

%nonassoc GREATER_OR_EQUAL LESS_OR_EQUAL GREATER_THAN LESS_THAN  EQUAL NOT_EQUAL

%left NOT
/*******************************************************/

/* MODIFIED in example 3 */
%left PLUS MINUS 

/* MODIFIED in example 5 */
%left MULTIPLICATION DIVISION INTEGER_DIVISION MODULO

%nonassoc PLUSPLUS MINUSMINUS

%left LPAREN RPAREN

%nonassoc  UNARY

// Maximum precedence 
/* MODIFIED in example 5 */
%right POWER


%%
 //! \name Grammar rules

/* MODIFIED  Grammar in example 16 */

program : stmtlist
		  { 
			// Create a new AST
			$$ = new lp::AST($1); 

			// Assign the AST to the root
			root = $$;

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

;

stmtlist:  /* empty: epsilon rule */
		  { 

			// create a empty list of statements
			top = new std::list<lp::Statement *>();
			$$ = top;
		  }    

        | stmtlist stmt 
		  { 
			// copy up the list and add the stmt to it
			$$ = $1;
			$$->push_back($2);

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = $$->begin(); 
						it != $$->end(); 
						it++)
				{
					/* (*it)->printAST(); */
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				$$->clear();
			}
		}

    /* | stmtlist error
      { 
			 // just copy up the stmtlist when an error occurs
				$$ = $1;
			 
			/* The parser stays in the error state for three input tokens following the error. 
			 If the corrected line contains an error in the first three tokens, 
			 the parser deletes the tokens and does not produce a message. 
			 To allow for this condition, use the following yacc statement:
			 

			 //if (interactiveMode == true){ //Util para el modo interactivo. Evitar cuando se analiza ficheros, puede generar bucles infinitos.
			 	//yyerrok;

			 //}
			 
			 $$->clear();

			 ParserError = true;
			 control = 0;
			
			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 //yyclearin;
       }  */
;
 

stmt: SEMICOLON  /* Empty statement: ";" */
	  {
		// Create a new empty statement node
		$$ = new lp::EmptyStmt(); 
	  }
	| command SEMICOLON
	  {
		$$ = $1;
	  }
	| asgn  SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| print SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| print_string SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| read SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| read_string SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	/*  NEW in example 17 */
	| if SEMICOLON
	 {
		// Default action
		// $$ = $1;
	 }
	 | case SEMICOLON
	 {
		// Default action
		// $$ = $1;
	 }
	/*  NEW in example 17 */
	| while SEMICOLON
	 {
		// Default action
		// $$ = $1;
	 }
	 | do_while SEMICOLON
	 {
		// Default action
		// $$ = $1;
	 }
	/*  NEW in example 17 */
	| block 
	 {
		// Default action
		// $$ = $1;
	 }
	| repeat SEMICOLON
	 {
		// Default action
		// $$ = $1;
	 }
	 | for SEMICOLON
	 {
		// Default action
		// $$ = $1;
	 }
	 | 	VARIABLE PLUSPLUS 
	 { 
		lp::IncrementNode($1, 0).evaluateNumber();
		$$ = new lp::EmptyStmt();
	 }
	| 	PLUSPLUS VARIABLE 
	 { 
		lp::IncrementNode($2, 1).evaluateNumber();
		$$ = new lp::EmptyStmt();
	 }
	 | 	VARIABLE MINUSMINUS 
	{ 
		lp::DecrementNode($1, 0).evaluateNumber();
		$$ = new lp::EmptyStmt();
	}
	| 	MINUSMINUS VARIABLE 
	{ 
		lp::DecrementNode($2, 1).evaluateNumber();
		$$ = new lp::EmptyStmt();
	}
	 
;

command: 
	CLEAR
	{
		$$ = new lp::ClearStmt();
	}
	| PLACE LPAREN expnum COMMA expnum RPAREN
	{
		$$ = new lp::PlaceStmt($3,$5);

	}
	| STYLE LPAREN STRING RPAREN
	{
		$$ = new lp:: StyleStmt($3);
	}

;

block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  
		{
			// Create a new block of statements node
			$$ = new lp::BlockStmt($2); 
		}
;

controlSymbol:  /* Epsilon rule*/
		{
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
;

	/*  NEW in example 17 */
if:	/* Simple conditional statement */
	IF controlSymbol cond THEN stmtlist END_IF
    {
		
			// Create a new if statement node
			$$ = new lp::IfStmt($3, $5);

			// To control the interactive mode
			control--;		
	}
	/* Compound conditional statement */
	| IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF
	 {

		// Create a new if statement node
		$$ = new lp::IfStmt($3, $5, $7);
		control--;
		
	 }
	 | error END_IF {$$ = new lp::EmptyStmt(); top->clear();yyclearin;
			yyerrok;}
	
;


case: 
	CASE controlSymbol LPAREN exp RPAREN listOfValues default END_CASE
	{
		$$ = new lp::CaseStmt($4, $6, $7);

		control--;
	}

;

default:
	{
		$$ = NULL;
	} 
| DEFAULT COLON stmtlist
	{
		$$ = $3;
	}
; 

listOfValues: 
	{
		$$ = new struct lp::values;

		$$->valuesNum = new std::map<int, std::list<lp::Statement *> >();
		$$->valuesCad = new std::map<std::string, std::list<lp::Statement *> >();
		$$->valuesLog = new std::map<bool, std::list<lp::Statement *> >();
	}

| listOfValues VALUE exp COLON stmtlist

	{
		$$ = $1;

		/* First time a map is filled */
		if ($$->valuesNum->size() == 0 && $$->valuesCad->size() == 0 && $$->valuesLog->size() == 0){
			
			/* Fill a map according to the type of the label */
			switch($3->getType()){

				case NUMBER:

					$$->valuesNum->insert(std::make_pair($3->evaluateNumber(), *$5));

				break;
				case BOOL:
					
					$$->valuesLog->insert(std::make_pair($3->evaluateBool(), *$5));

				break;
				case STRING:
					
					$$->valuesCad->insert(std::make_pair($3->evaluateString(), *$5));

				break;

			} 

		/* Other times */
		}else{ 
			
			/* The numeric map was filled */
			if ($$->valuesNum->size() != 0){

				/* Check label type */
				if ($3->getType() == NUMBER){

					if ($$->valuesNum->count($3->evaluateNumber())){
						execerror("Syntax error in \"case statement\": There are duplicate values", "case");
				
					}else{
						$$->valuesNum->insert(std::make_pair($3->evaluateNumber(), *$5));
					}

				}else{
					execerror("Semantic error: The values type are different", "case");
				}

			/* The string map was filled */
			}else if ($$->valuesCad->size() != 0){

				/* Check the label type */
				if ($3->getType() == STRING){

					if ($$->valuesCad->count($3->evaluateString())){
						execerror("Syntax error in \"case statement\": There are duplicate values", "case");
				
					}else{
						$$->valuesCad->insert(std::make_pair($3->evaluateString(), *$5));
					}
				}else{
					execerror("Semantic error: The values type are different", "case");


				}

			/* The logic map was filled */	
			}else if ($$->valuesLog->size() != 0){

				/* Check the label type */
				if ($3->getType() == BOOL){

					if ($$->valuesLog->count($3->evaluateBool())){
						execerror("Syntax error in \"case statement\": There are duplicate values", "case");
				
					}else{
						$$->valuesLog->insert(std::make_pair($3->evaluateBool(), *$5));
					}
				}else{
					execerror("Semantic error: The values type are different", "case");

				}
			}
		}


		
	}

;



	/*  NEW in example 17 */
while:  WHILE controlSymbol cond DO stmtlist END_WHILE
		{
		
			// Create a new while statement node
			$$ = new lp::WhileStmt($3, $5);

			// To control the interactive mode
			control--;
        }
		
;

do_while: DO stmtlist WHILE controlSymbol cond
		{
			// Create a new do-while statement node
			$$ = new lp::DoWhileStmt($5, $2);

			// To control the interactive mode
			control--;
		}
;

repeat:  REPEAT controlSymbol stmtlist UNTIL cond
		{
			// Create a new while statement node
			$$ = new lp::RepeatStmt($5, $3);

			// To control the interactive mode
			control--;
        }
;

for:  FOR controlSymbol VARIABLE FROM expnum TO expnum STEP expnum DO stmtlist END_FOR
	  {
			// Create a new for statement node
			$$ = new lp::ForStmt($3, $5, $7, $9, $11);

			// To control the interactive mode
			control--;
      }

	  | FOR controlSymbol VARIABLE FROM expnum TO expnum DO stmtlist END_FOR
	  {
			
			// Create a new for statement node
			$$ = new lp::ForStmt($3, $5, $7, $9);

			// To control the interactive mode
			control--;
      }
	  | FOR NUMERIC_CONSTANT FROM expnum TO expnum DO stmtlist END_FOR
	  {
		execerror("Syntax error: The variable cannot be a numeric constant", $2);
	  }
	  | FOR LOGICAL_CONSTANT FROM expnum TO expnum DO stmtlist END_FOR
	  {
		execerror("Syntax error: The variable cannot be a logical constant", $2);
	  }
	  | FOR STRING_CONSTANT FROM expnum TO expnum DO stmtlist END_FOR
	  {
		execerror("Syntax error: The variable cannot be a string constant", $2);
	  }
	  
	  | error END_FOR {$$ = new lp::EmptyStmt(); top->clear(); control = 0; yyclearin;
			yyerrok;}
	
;

	/*  NEW in example 17 */
cond: 	LPAREN exp RPAREN
		{ 
			$$ = $2;
		}
;


asgn:   /*** SIMPLE ASSIGNMENT ***/
	// Variable assignment
	VARIABLE ASSIGNMENT exp 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, $3);
		}
	| VARIABLE PLUS_ASSIGNMENT expnum 
		{ 
			// Create a new assignment node
			$$ = new lp::PlusAssignmentStmt($1, $3);

		}
	| VARIABLE MINUS_ASSIGNMENT expnum 
		{ 
			// Create a new assignment node
			$$ = new lp::MinusAssignmentStmt($1, $3);

		}
	| VARIABLE MULTIPLICATION_ASSIGNMENT expnum 
		{ 
			// Create a new assignment node
			$$ = new lp::MultiplicationAssignmentStmt($1, $3);

		}
	| VARIABLE DIVISION_ASSIGNMENT expnum 
		{ 
			// Create a new assignment node
			$$ = new lp::DivisionAssignmentStmt($1, $3);

		}
	| VARIABLE INTEGER_DIVISION_ASSIGNMENT expnum 
		{ 
			// Create a new assignment node
			$$ = new lp::IntegerDivisionAssignmentStmt($1, $3);

		}
	| VARIABLE POWER_ASSIGNMENT expnum 
		{ 
			// Create a new assignment node
			$$ = new lp::PowerAssignmentStmt($1, $3);

		}
	| VARIABLE MODULO_ASSIGNMENT expnum 
		{ 
			// Create a new assignment node
			$$ = new lp::ModuloAssignmentStmt($1, $3);

		}
	// Const assignment
	| CONST VARIABLE ASSIGNMENT exp 
		{ 
			// Create a new const assignment node
			$$ = new lp::ConstAssignmentStmt($2, $4);
		}
	
	/*** MULTIPLE ASSIGNMENT ***/
	// Variable assignment
	|  VARIABLE ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, (lp::AssignmentStmt *) $3);
		}
	|  VARIABLE PLUS_ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::PlusAssignmentStmt($1, (lp::PlusAssignmentStmt *) $3);
		}
	|  VARIABLE MINUS_ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::MinusAssignmentStmt($1, (lp::MinusAssignmentStmt *) $3);
		}
	|  VARIABLE MULTIPLICATION_ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::MultiplicationAssignmentStmt($1, (lp::MultiplicationAssignmentStmt *) $3);
		}
	|  VARIABLE DIVISION_ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::DivisionAssignmentStmt($1, (lp::DivisionAssignmentStmt *) $3);
		}
	|  VARIABLE INTEGER_DIVISION_ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::IntegerDivisionAssignmentStmt($1, (lp::IntegerDivisionAssignmentStmt *) $3);
		}
	|  VARIABLE POWER_ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::PowerAssignmentStmt($1, (lp::PowerAssignmentStmt *) $3);
		}
	|  VARIABLE MODULO_ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::ModuloAssignmentStmt($1, (lp::ModuloAssignmentStmt *) $3);
		}
	
	// Const assingment
	|  CONST VARIABLE ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::ConstAssignmentStmt($2, (lp::ConstAssignmentStmt *) $4);
		}

	/*** ERROR ASSIGN STRING OR LOGICAL EXPRESSION ***/
	| VARIABLE PLUS_ASSIGNMENT auxasgn 
		{ 
			execerror("Syntax error: The expression should be numeric", $1);

		}
	| VARIABLE MINUS_ASSIGNMENT auxasgn 
		{ 
			execerror("Syntax error: The expression should be numeric", $1);

		}
	| VARIABLE MULTIPLICATION_ASSIGNMENT auxasgn 
		{ 
			execerror("Syntax error: The expression should be numeric", $1);

		}
	| VARIABLE DIVISION_ASSIGNMENT auxasgn 
		{ 
			execerror("Syntax error: The expression should be numeric", $1);

		}
	| VARIABLE INTEGER_DIVISION_ASSIGNMENT auxasgn 
		{ 
			execerror("Syntax error: The expression should be numeric", $1);

		}
	| VARIABLE POWER_ASSIGNMENT auxasgn 
		{ 
			execerror("Syntax error: The expression should be numeric", $1);

		}
	| VARIABLE MODULO_ASSIGNMENT auxasgn 
		{ 
			execerror("Syntax error: The expression should be numeric", $1);

		}

	/*** ERROR ASSIGN A CONSTANT ***/
	| NUMERIC_CONSTANT ASSIGNMENT exp 
		{   
 			execerror("Semantic error in assignment: it is not allowed to modify a numeric constant ", $1);
		} 
	| LOGICAL_CONSTANT ASSIGNMENT exp 
		{   
 			execerror("Semantic error in assignment: it is not allowed to modify a logical constant ", $1);
		}
	| STRING_CONSTANT ASSIGNMENT exp 
		{   
 			execerror("Semantic error in assignment: it is not allowed to modify a string constant ", $1);
		}

	/*** ERROR MULTIPLE ASSIGN CONSTANT ***/
	| NUMERIC_CONSTANT ASSIGNMENT asgn 
		{   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a numeric constant ",$1);
		}
	| LOGICAL_CONSTANT ASSIGNMENT asgn 
		{   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a logical constant ",$1);
		}
	| STRING_CONSTANT ASSIGNMENT asgn 
		{   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a string constant ",$1);
		}

	/*** ERROR REASIGN A CONSTANT ***/
	| CONST NUMERIC_CONSTANT ASSIGNMENT exp 
		{ 
			execerror("Semantic error in assignment: it is not allowed to reassing a numeric constant",$2);

		}
	| CONST LOGICAL_CONSTANT ASSIGNMENT exp 
		{ 
			execerror("Semantic error in assignment: it is not allowed to reassing a logical constant",$2);

		}
	| CONST STRING_CONSTANT ASSIGNMENT exp 
		{ 
			execerror("Semantic error in assignment: it is not allowed to reassing a string constant",$2);

		}

	/*** ERROR REASSING MULTIPLE CONSTANT ***/
	|  CONST NUMERIC_CONSTANT ASSIGNMENT asgn 
		{ 
			execerror("Semantic error in multiple assignment: it is not allowed to reassing a numeric constant ",$2);

		}
	|  CONST LOGICAL_CONSTANT ASSIGNMENT asgn 
		{ 
			execerror("Semantic error in multiple assignment: it is not allowed to reassing a logical constant ",$2);

		}
	|  CONST STRING_CONSTANT ASSIGNMENT asgn 
		{ 
			execerror("Semantic error in multiple assignment: it is not allowed to reassing a string constant ",$2);

		}    
	
;

auxasgn: explog | expcad ;


print:  PRINT LPAREN exp RPAREN
		{
			// Create a new print node
			$$ = new lp::PrintStmt($3);
		}
		| PRINT LPAREN RPAREN SEMICOLON{
			execerror("Syntax error: Missing argument", "print");
		}
		| error SEMICOLON{$$ = new lp::EmptyStmt(); top->clear(); control = 0; yyclearin;
			yyerrok;}
;

print_string:  PRINT_STRING LPAREN auxcad RPAREN
		{
			// Create a new print node
			$$ = new lp::PrintStringStmt($3);
		}
;

read:  READ LPAREN VARIABLE RPAREN  
		{	
			$$ = new lp::ReadStmt($3);
		}

  	  /* NEW rule in example 11 */
	| READ LPAREN NUMERIC_CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a numeric constant ",$3);
		}
	| READ LPAREN LOGICAL_CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a logical constant ",$3);
		}
	| READ LPAREN STRING_CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a string constant ",$3);
		}
;

read_string:  READ_STRING LPAREN VARIABLE RPAREN  
		{
			// Create a new read node
			 $$ = new lp::ReadStringStmt($3);
		}

  	  /* NEW rule in example 11 */
	| READ_STRING LPAREN NUMERIC_CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read_string statement\": it is not allowed to modify a numeric constant ",$3);
		}
	| READ_STRING LPAREN LOGICAL_CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read_string statement\": it is not allowed to modify a logical constant ",$3);
		}
	| READ_STRING LPAREN STRING_CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read_string statement\": it is not allowed to modify a string constant ",$3);
		}
;


expnum:	NUMBER 
		{ 
			// Create a new number node
			$$ = new lp::NumberNode($1);
		}

	| 	VARIABLE PLUSPLUS 
		{ 
			$$ = new lp::IncrementNode($1, 0);
		}
	| 	PLUSPLUS VARIABLE 
		{ 
			$$ = new lp::IncrementNode($2, 1);
		}
	| 	VARIABLE MINUSMINUS 
		{ 
			$$ = new lp::DecrementNode($1, 0);
		}
	| 	MINUSMINUS VARIABLE 
		{ 
			$$ = new lp::DecrementNode($2, 1);	
		}
	| 	expnum PLUS expnum 
		{ 
			// Create a new plus node
			$$ = new lp::PlusNode($1, $3);
		}

	| 	expnum MINUS expnum
      	{
			// Create a new minus node
			$$ = new lp::MinusNode($1, $3);
		}

	| 	expnum MULTIPLICATION expnum 
		{ 
			// Create a new multiplication node
			$$ = new lp::MultiplicationNode($1, $3);
		}

	| 	expnum DIVISION expnum
		{
		  // Create a new division node	
		  $$ = new lp::DivisionNode($1, $3);
	   }

	| 	expnum INTEGER_DIVISION expnum
		{
		  // Create a new division node	
		  $$ = new lp::IntegerDivisionNode($1, $3);
	   }

	| 	LPAREN expnum RPAREN
       	{ 
		    // just copy up the expression node 
			$$ = $2;
		 }

  	| 	PLUS expnum %prec UNARY
		{ 
		  // Create a new unary plus node	
  		  $$ = new lp::UnaryPlusNode($2);
		}

	| 	MINUS expnum %prec UNARY
		{ 
		  // Create a new unary minus node	
  		  $$ = new lp::UnaryMinusNode($2);
		}

	|	expnum MODULO expnum 
		{
		  // Create a new modulo node	

		  $$ = new lp::ModuloNode($1, $3);
       }

	|	expnum POWER expnum 
     	{ 
		  // Create a new power node	
  		  $$ = new lp::PowerNode($1, $3);
		}

	| VARIABLE
		{
		  // Create a new variable node	
			$$ = new lp::VariableNode($1);  
		}

	 | NUMERIC_CONSTANT
		{
		  // Create a new constant node	
		  $$ = new lp::NumericConstantNode($1);

		}

	| BUILTIN LPAREN listOfExp RPAREN
		{
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol($1);

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) $3->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							$$ = new lp::BuiltinFunctionNode_0($1);
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = $3->front();

							// Create a new Builtin Function with 1 parameter node	
							$$ = new lp::BuiltinFunctionNode_1($1,e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = $3->front();
							$3->pop_front();
							lp::ExpNode *e2 = $3->front();

							// Create a new Builtin Function with 2 parameters node	
							$$ = new lp::BuiltinFunctionNode_2($1,e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", $1);
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", $1);
		}

;

explog:
	LPAREN explog RPAREN
		{ 
			// just copy up the expression node 
			$$ = $2;
		}
	| LOGICAL_CONSTANT
		{
		// Create a new constant node	
			$$ = new lp::LogicalConstantNode($1);

		}	
	| exp GREATER_THAN exp
	 	{
		  // Create a new "greater than" node	
 			$$ = new lp::GreaterThanNode($1,$3);
		}

	| exp GREATER_OR_EQUAL exp 
	 	{
		  // Create a new "greater or equal" node	
 			$$ = new lp::GreaterOrEqualNode($1,$3);
		}

	| exp LESS_THAN exp 	
	 	{
		  // Create a new "less than" node	
 			$$ = new lp::LessThanNode($1,$3);
		}

	| exp LESS_OR_EQUAL exp 
	 	{
		  // Create a new "less or equal" node	
 			$$ = new lp::LessOrEqualNode($1,$3);
		}

	| exp EQUAL exp 	
	 	{
		  // Create a new "equal" node	
 			$$ = new lp::EqualNode($1,$3);
		}

    | exp NOT_EQUAL exp 	
	 	{
		  // Create a new "not equal" node	
 			$$ = new lp::NotEqualNode($1,$3);
		}

    | exp AND exp 
	 	{
		  // Create a new "logic and" node	
 			$$ = new lp::AndNode($1,$3);
		}

    | exp OR exp 
	 	{
		  // Create a new "logic or" node	
 			$$ = new lp::OrNode($1,$3);
		}

    | NOT exp 
	 	{
		  // Create a new "logic negation" node	
 			$$ = new lp::NotNode($2);
		}

;

exp:
	expnum 
	| explog 
	| expcad

;

expcad:
	LPAREN expcad RPAREN
    	{ 
	    // just copy up the expression node 
		$$ = $2;
		}

	| STRING 
		{
 			$$ = new lp::StringNode($1);
		}
	| STRING_CONSTANT
		{
			// Create a new constant node	
			$$ = new lp::StringConstantNode($1);
		}
	| auxcad CONCATENATION auxcad 
	 	{
		  // Create a new "operator concatenation" node	
 			$$ = new lp::ConcatenationNode($1, $3);
		}
;

auxcad: 
	expcad 
		
	| VARIABLE
		{
		  // Create a new variable node
		  $$ = new lp::VariableNode($1);
		}

;

listOfExp: 
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

	|  exp restOfListOfExp
			{
				$$ = $2;

				// Insert the expression in the list of expressions
				$$->push_front($1);
			}
;

restOfListOfExp:
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

		|	COMMA exp restOfListOfExp
			{
				// Get the list of expressions
				$$ = $3;

				// Insert the expression in the list of expressions
				$$->push_front($2);
			}
;



%%
