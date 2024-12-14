/*!	
	\file    ast.cpp
	\brief   Code of funcitons of AST clas
	\author  
	\date    2018-12-13
	\version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <map>
#include <limits>
#include <cstdlib>
#include <stdexcept>      // std::out_of_range
#include <algorithm> /* Uso de transform */

// Para usar la funciones pow y std::abs
#include <cmath>

#include "ast.hpp"

#include "../table/table.hpp"

// warning
#include "../error/error.hpp"

// Macros for the screen
#include "../includes/macros.hpp"

// 
#include "../table/numericVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/stringVariable.hpp"

#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"
#include "../table/stringConstant.hpp"


#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/interpreter.tab.h"



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

extern lp::Table table; //!< Reference to the Table of Symbols


extern lp::AST *root; //!< Reference to the object at the base of the AST


///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::VariableNode::getType() 
{ 
	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Return the type of the Variable
	return var->getType();
}


void lp::VariableNode::printAST() 
{
  std::cout << "VariableNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}


double lp::VariableNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->_id);

		// Copy the value of the NumericVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the variable is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


bool lp::VariableNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalVariable
		lp::LogicalVariable *var = (lp::LogicalVariable *) table.getSymbol(this->_id);

		// Copy the value of the LogicalVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the variable is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}


std::string lp::VariableNode::evaluateString() 
{ 
	std::string result = "";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as StringVariable
		lp::StringVariable *var = (lp::StringVariable *) table.getSymbol(this->_id);

		// Copy the value of the StringVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateString(): the variable is not string",
				   this->_id);
	}

	// Return the value of the StringVariable
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::ConstantNode::getType() 
{ 
	// Get the identifier in the table of symbols as Constant
	lp::Constant *var = (lp::Constant *) table.getSymbol(this->_id);

	// Return the type of the Constant
	return var->getType();
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::LogicalConstantNode::printAST() 
{
  std::cout << "LogicalConstantNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

bool lp::LogicalConstantNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalConstant
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		// Copy the value of the LogicalConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}

double lp::LogicalConstantNode::evaluateNumber() 
{ 
    double result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalConstant
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		// Copy the value of the LogicalConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	// Return 0->false or 1->true
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NumericConstantNode::printAST() 
{
  std::cout << "NumericConstantNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}


double lp::NumericConstantNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericConstant
		lp::NumericConstant *constant = (lp::NumericConstant *) table.getSymbol(this->_id);

		// Copy the value of the NumericConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the constant is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::StringConstantNode::printAST() 
{
  std::cout << "StringConstantNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}


std::string lp::StringConstantNode::evaluateString() 
{ 
	std::string result = "";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as NumericConstant
		lp::StringConstant *constant = (lp::StringConstant *) table.getSymbol(this->_id);

		// Copy the value of the NumericConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateString(): the constant is not string", 
				   this->_id);
	}

	// Return the value of the StringConstant
	return result;
}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
 

int lp::NumberNode::getType()
{
	return NUMBER;
}


void lp::NumberNode::printAST()
{
  std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber() 
{ 
    return this->_number; 
}

bool lp::NumberNode::evaluateBool() 
{
	return this->_number;
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
 

int lp::StringNode::getType()
{
	return STRING;
}


void lp::StringNode::printAST()
{
  std::cout << "StringNode: " << this->_string << std::endl;
}

double lp::StringNode::evaluateNumber() 
{ 
    return atof(this->_string.c_str()); 
}

std::string lp::StringNode::evaluateString() 
{ 
    return this->_string; 
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::NumericUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == NUMBER)
	{
		result = NUMBER;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Numeric Unary Operator");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == BOOL)
	{
		result = BOOL;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Logical Unary Operator");
	}
	
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = NUMBER;
	else
		warning("Runtime error: incompatible types for", "Numeric Operator");

	return	result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::RelationalOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = BOOL;
	else if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
		result = BOOL;
	else if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
		result = BOOL;
	else
		warning("Runtime error: incompatible types for", "Relational Operator");

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalOperatorNode:: getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
	{
		// 
		result = BOOL;
	}
	else
		warning("Runtime error: incompatible types for", "Logical Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::StringOperatorNode:: getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
	{
		// 
		result = STRING;
	}
	else
		warning("Runtime error: incompatible types for", "String Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryMinusNode::printAST() 
{
  std::cout << "UnaryMinusNode: -"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryMinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Minus
		result = - this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

  return result;
}

bool lp::UnaryMinusNode::evaluateBool()
{
	bool result = false;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPlusNode::printAST() 
{
  std::cout << "UnaryPlusNode: +"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryPlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}

bool lp::UnaryPlusNode::evaluateBool()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::IncrementNode::getType(){
	return NUMBER;
}


void lp::IncrementNode::printAST() 
{
  std::cout << "IncrementNode: ++"  << std::endl;
  std::cout << this->_id; 
  std::cout << "\t"; 

}

double lp::IncrementNode::evaluateNumber() 
{
	double result = 0.0;

	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check the type of the varible
	switch (var->getType())
	{
		case NUMBER:
		{
			// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

			// Assignment the value to the identifier in the table of symbols
			double value = v->getValue();
						

			if (this->_typeOp){
				v->setValue(value+1);
				result = value+1;
			}else{
				v->setValue(value+1);
				result = value;
			}
		}
		break;

		case UNDEFINED:
			warning("Runtime error: The variable is undeclared", this->_id);
		break;

		case BOOL:
			warning("Runtime error: Incompatible type for increment operator. The variable cannot be logic type", this->_id);
		break;

		case STRING:
			warning("Runtime error: Incompatible type for increment operator. The variable cannot be string type", this->_id);
		break;

	}
	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::DecrementNode::getType(){
	return NUMBER;
}


void lp::DecrementNode::printAST() 
{
  std::cout << "DecrementNode: ++"  << std::endl;
  std::cout << this->_id; 
  std::cout << "\t"; 

}

double lp::DecrementNode::evaluateNumber() 
{
	double result = 0.0;

	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check the type of the varible
	switch (var->getType())
	{
		case NUMBER:
		{
			// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

			// Assignment the value to the identifier in the table of symbols
			double value = v->getValue();
						

			if (this->_typeOp){
				v->setValue(value+1);
				result = value+1;
			}else{
				v->setValue(value+1);
				result = value;
			}
		}
		break;

		case UNDEFINED:
			warning("Runtime error: The variable is undeclared", this->_id);
		break;

		case BOOL:
			warning("Runtime error: Incompatible type for increment operator. The variable cannot be logic type", this->_id);
		break;

		case STRING:
			warning("Runtime error: Incompatible type for increment operator. The variable cannot be string type", this->_id);
		break;

	}
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusNode::printAST() 
{
  std::cout << "PlusNode: +"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Plus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusNode::printAST() 
{
  std::cout << "MinusNode: -"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MinusNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Minus");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::MultiplicationNode::printAST() 
{
  std::cout << "MultiplicationNode: *"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MultiplicationNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","Multiplication");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionNode::printAST()
{
  std::cout << "DivisionNode: /" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::DivisionNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::IntegerDivisionNode::printAST()
{
  std::cout << "IntegerDivisionNode: //" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::IntegerDivisionNode::evaluateNumber() 
{
	int result = 0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloNode::printAST()
{
  std::cout << "ModuloNode: %" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::ModuloNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
    	if(std::abs(rightNumber) > ERROR_BOUND)
				result = (int) leftNumber % (int) rightNumber;
		else
			warning("Runtime error", "Division by zero");
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Modulo");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerNode::printAST() 
{
  std::cout << "PowerNode: ^"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PowerNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Power");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConcatenationNode::printAST() 
{
  std::cout << "ConcatenationNode: ||"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

std::string lp::ConcatenationNode::evaluateString() 
{
	std::string result = "";

	// Ckeck the types of the expressions
	if (this->getType() == STRING)
	{
		result = this->_left->evaluateString() + this->_right->evaluateString();
	}
	else
	{
		warning("Runtime error: the expressions are not string for", "Concatenation");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::BuiltinFunctionNode_0::getType()
{
	return	NUMBER;
}


void lp::BuiltinFunctionNode_0::printAST() 
{
  std::cout << "BuiltinFunctionNode_0: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
}

double lp::BuiltinFunctionNode_0::evaluateNumber() 
{
	// Get the identifier in the table of symbols as BuiltinParameter0
	lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *) table.getSymbol(this->_id);

	// Apply the function and copy the result
   	return f->getFunction()();
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_1::getType()
{
	int result = 0;
		
	if (this->_exp->getType() == NUMBER)
		result = NUMBER;
	else
		warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

	return	result;
}

void lp::BuiltinFunctionNode_1::printAST() 
{
  std::cout << "BuiltinFunctionNode_1: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;  
  std::cout << "\t";
	this->_exp->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_1::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter1
		lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *) table.getSymbol( this->_id);

		// Apply the function to the parameter and copy the result
		result = f->getFunction()(this->_exp->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible type of parameter for ", this->_id);
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_2::getType()
{
	int result = 0;
		
	if (this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");

	return	result;
}


void lp::BuiltinFunctionNode_2::printAST() 
{
  std::cout << "BuiltinFunctionNode_2: " << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";
  this->_exp1->printAST();
  std::cout << "\t";
	this->_exp2->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_2::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter2
		lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *) table.getSymbol(this->_id);

		// Apply the function to the parameters and copy the result
	  	result = f->getFunction()(this->_exp1->evaluateNumber(),this->_exp2->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", this->_id);
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterThanNode::printAST()
{
  std::cout << "GreaterThanNode: >" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber > rightNumber);
			break;
			case STRING:{
				
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();
				std::cout << leftString << leftString.size();
				std::cout << rightString << rightString.size();

				result = leftString > rightString;
				break;
			}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"operator Greater than");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterOrEqualNode::printAST()
{
  std::cout << "GreaterOrEqualNode: >= " << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber >= rightNumber);
			break;
			case STRING:{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = leftString >= rightString;
				break;
			}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"operator Greater than");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessThanNode::printAST()
{
  std::cout << "LessThanNode: <" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber < rightNumber);
			break;
			case STRING:{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = leftString < rightString;
				break;
			}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"operator Greater than");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessOrEqualNode::printAST()
{
  std::cout << "LessOrEqualNode: <=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber <= rightNumber);
			break;
			case STRING:{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = leftString <= rightString;
				break;
			}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"operator Greater than");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EqualNode::printAST()
{
  std::cout << "EqualNode: ==" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::EqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) < ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean == rightBoolean);
				break;
			case STRING:{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				// 
				result = (leftString == rightString);
				break;
			}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Equal operator");				
		}

	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", 
						"Equal operator");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotEqualNode::printAST()
{
  std::cout << "NotEqualNode: !=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::NotEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) >= ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean != rightBoolean);
				break;
			case STRING:{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				// 
				result = (leftString != rightString);
				break;
			}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Not Equal operator");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "Not Equal operator");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AndNode::printAST()
{
  std::cout << "AndNode: &&" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::AndNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool and rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator And");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::OrNode::printAST()
{
  std::cout << "OrNode: ||" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::OrNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool or rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Or");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotNode::printAST()
{
  std::cout << "NotNode: !" << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
}

bool lp::NotNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		result = not this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Not");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AssignmentStmt::printAST() 
{
  std::cout << "assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::AssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value 
					lp::NumericVariable *v = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,value);
					table.installSymbol(v);

				}
			}
			break;

			case BOOL:
			{
				bool value;
				// evaluate the expression as BOOL
			 	value = this->_exp->evaluateBool();

				if (firstVar->getType() == BOOL)
				{
				  	// Get the identifier in the table of symbols as LogicalVariable
					lp::LogicalVariable *v = (lp::LogicalVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not BOOL
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value 
					lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,value);
					table.installSymbol(v);
				}
			}
			break;

			case STRING:
			{
				std::string value;
				// evaluate the expression as STRING
			 	value = this->_exp->evaluateString();

				if (firstVar->getType() == STRING)
				{
				  	// Get the identifier in the table of symbols as StringVariable
					lp::StringVariable *v = (lp::StringVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not STRING
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type STRING and the value 
					lp::StringVariable *v = new lp::StringVariable(this->_id,
											VARIABLE,STRING,value);
					table.installSymbol(v);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->_id);

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == NUMBER)
				{
				/* Get the identifier of the first variable in the table of symbols as NumericVariable */
				lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value of the previous variable 
					lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case BOOL:
			{
				/* Get the identifier of the previous asgn in the table of symbols as LogicalVariable */
				lp::LogicalVariable *secondVar = (lp::LogicalVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == BOOL)
				{
				/* Get the identifier of the first variable in the table of symbols as LogicalVariable */
				lp::LogicalVariable *firstVar = (lp::LogicalVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not BOOL
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value of the previous variable 
					lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case STRING:
			{
				/* Get the identifier of the previous asgn in the table of symbols as StringVariable */
				lp::StringVariable *secondVar = (lp::StringVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == STRING)
				{
				/* Get the identifier of the first variable in the table of symbols as StringVariable */
				lp::StringVariable *firstVar = (lp::StringVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not STRING
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type STRING and the value of the previous variable 
					lp::StringVariable *firstVar = new lp::StringVariable(this->_id,
											VARIABLE,STRING,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusAssignmentStmt::printAST() 
{
  std::cout << " plus assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::PlusAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				switch (firstVar->getType())
				{
					case NUMBER:
					{
						// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						v->setValue(v->getValue() + value);
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for plus assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for plus assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: The expression should be numeric ", "Plus Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->getId());
				// Check the type of the first variable
				switch (firstVar->getType())
				{
					case NUMBER:{
						/* Get the identifier of the first variable in the table of symbols as NumericVariable */
						lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						firstVar->setValue(secondVar->getValue()+firstVar->getValue());
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for plus assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for plus assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

		
			default:
				warning("Runtime error: incompatible type of expression for ", "Plus Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusAssignmentStmt::printAST() 
{
  std::cout << " Minus assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::MinusAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				switch (firstVar->getType())
				{
					case NUMBER:
					{
						// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						v->setValue(v->getValue() - value);
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Minus assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Minus assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: The expression should be numeric ", "Minus Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->getId());
				// Check the type of the first variable
				switch (firstVar->getType())
				{
					case NUMBER:{
						/* Get the identifier of the first variable in the table of symbols as NumericVariable */
						lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						firstVar->setValue(secondVar->getValue()-firstVar->getValue());
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Minus assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Minus assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

		
			default:
				warning("Runtime error: incompatible type of expression for ", "Minus Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MultiplicationAssignmentStmt::printAST() 
{
  std::cout << " Multiplication assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::MultiplicationAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				switch (firstVar->getType())
				{
					case NUMBER:
					{
						// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						v->setValue(v->getValue() * value);
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Multiplication assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Multiplication assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: The expression should be numeric ", "Multiplication Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->getId());
				// Check the type of the first variable
				switch (firstVar->getType())
				{
					case NUMBER:{
						/* Get the identifier of the first variable in the table of symbols as NumericVariable */
						lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						firstVar->setValue(secondVar->getValue()*firstVar->getValue());
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Multiplication assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Multiplication assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;
			
		
			default:
				warning("Runtime error: incompatible type of expression for ", "Multiplication Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::IntegerDivisionAssignmentStmt::printAST() 
{
  std::cout << " IntegerDivision assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::IntegerDivisionAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				switch (firstVar->getType())
				{
					case NUMBER:
					{
						// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						 // The divisor is not zero
						if(std::abs(value) > ERROR_BOUND)
						{
							v->setValue(v->getValue()/value);

						}
						else
						{
							warning("Runtime error", "Division by zero");
						}
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for IntegerDivision assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for IntegerDivision assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: The expression should be numeric ", "IntegerDivision Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->getId());
				// Check the type of the first variable
				switch (firstVar->getType())
				{
					case NUMBER:{
						/* Get the identifier of the first variable in the table of symbols as NumericVariable */
						lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						 // The divisor is not zero
						if(std::abs(firstVar->getValue()) > ERROR_BOUND)
						{
							firstVar->setValue(secondVar->getValue()/firstVar->getValue());
						}
						else
						{
							warning("Runtime error", "Division by zero");
						}
						
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for IntegerDivision assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for IntegerDivision assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;
			
		
			default:
				warning("Runtime error: incompatible type of expression for ", "IntegerDivision Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionAssignmentStmt::printAST() 
{
  std::cout << " Division assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::DivisionAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				switch (firstVar->getType())
				{
					case NUMBER:
					{
						// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						 // The divisor is not zero
						if(std::abs(value) > ERROR_BOUND)
						{
							v->setValue(v->getValue()/value);

						}
						else
						{
							warning("Runtime error", "Division by zero");
						}
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Division assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Division assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: The expression should be numeric ", "Division Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->getId());
				// Check the type of the first variable
				switch (firstVar->getType())
				{
					case NUMBER:{
						/* Get the identifier of the first variable in the table of symbols as NumericVariable */
						lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						 // The divisor is not zero
						if(std::abs(firstVar->getValue()) > ERROR_BOUND)
						{
							firstVar->setValue(secondVar->getValue()/firstVar->getValue());
						}
						else
						{
							warning("Runtime error", "Division by zero");
						}
						
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Division assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Division assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;
			
		
			default:
				warning("Runtime error: incompatible type of expression for ", "Division Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerAssignmentStmt::printAST() 
{
  std::cout << " Power assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::PowerAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				switch (firstVar->getType())
				{
					case NUMBER:
					{
						// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						v->setValue(pow(v->getValue(), value));
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Power assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Power assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: The expression should be numeric ", "Power Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->getId());
				// Check the type of the first variable
				switch (firstVar->getType())
				{
					case NUMBER:{
						/* Get the identifier of the first variable in the table of symbols as NumericVariable */
						lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						firstVar->setValue(pow(secondVar->getValue(), firstVar->getValue()));
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Power assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Power assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;


			default:
				warning("Runtime error: incompatible type of expression for ", "Power Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloAssignmentStmt::printAST() 
{
  std::cout << " Modulo assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::ModuloAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				switch (firstVar->getType())
				{
					case NUMBER:
					{
						// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						 // The divisor is not zero
						if(std::abs(value) > ERROR_BOUND)
						{
							v->setValue((int) v->getValue() % (int)value);

						}
						else
						{
							warning("Runtime error", "Modulo by zero");
						}
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Modulo assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Modulo assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: The expression should be numeric ", "Modulo Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->getId());
				// Check the type of the first variable
				switch (firstVar->getType())
				{
					case NUMBER:{
						/* Get the identifier of the first variable in the table of symbols as NumericVariable */
						lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						 // The divisor is not zero
						if(std::abs(firstVar->getValue()) > ERROR_BOUND)
						{
							firstVar->setValue((int) secondVar->getValue() % (int) firstVar->getValue());
						}
						else
						{
							warning("Runtime error", "Modulo by zero");
						}
						
					}
					break;

					case UNDEFINED:
						warning("Runtime error: The variable is undeclared", this->_id);
					break;

					case BOOL:
						warning("Runtime error: Incompatible type for Modulo assignment. The variable cannot be logic type", this->_id);
					break;

					case STRING:
						warning("Runtime error: Incompatible type for Modulo assignment. The variable cannot be string type", this->_id);
					break;

				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Modulo Assigment");
		}
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConstAssignmentStmt::printAST() 
{
  std::cout << "assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::ConstAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;

				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Delete the variable from the table of symbols 
				table.eraseSymbol(this->_id);

				// Insert the variable in the table of symbols as NumericVariable 
				// with the type NUMBER and the value 
				lp::NumericConstant *v = new lp::NumericConstant(this->_id,
											NUMERIC_CONSTANT,NUMBER,value);
				table.installSymbol(v);
	
			}
			break;

			case BOOL:
			{
				bool value;

				// evaluate the expression as BOOL
			 	value = this->_exp->evaluateBool();

				// Delete the variable from the table of symbols 
				table.eraseSymbol(this->_id);

				// Insert the variable in the table of symbols as NumericVariable 
				// with the type BOOL and the value 
				lp::LogicalConstant *v = new lp::LogicalConstant(this->_id,
										LOGICAL_CONSTANT,BOOL,value);
				table.installSymbol(v);
			
			}
			break;

			case STRING:
			{
				std::string value;
				// evaluate the expression as STRING
			 	value = this->_exp->evaluateString();

				// Delete the variable from the table of symbols 
				table.eraseSymbol(this->_id);

				// Insert the variable in the table of symbols as NumericVariable 
				// with the type STRING and the value 
				lp::StringConstant *v = new lp::StringConstant(this->_id,
										STRING_CONSTANT,STRING,value);
				table.installSymbol(v);
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Const Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->getId());

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericConstant *secondVar = (lp::NumericConstant *) table.getSymbol(this->_asgn->getId());
				
				// Delete the first variable from the table of symbols 
				table.eraseSymbol(this->_id);

				// Insert the first variable in the table of symbols as NumericVariable 
				// with the type NUMBER and the value of the previous variable 
				lp::NumericConstant *firstVar = new lp::NumericConstant(this->_id,
										NUMERIC_CONSTANT,NUMBER,secondVar->getValue());
				table.installSymbol(firstVar);
			}
			break;

			case BOOL:
			{
				/* Get the identifier of the previous asgn in the table of symbols as LogicalConstant */
				lp::LogicalConstant *secondVar = (lp::LogicalConstant *) table.getSymbol(this->_asgn->getId());
				
				// Delete the first variable from the table of symbols 
				table.eraseSymbol(this->_id);

				// Insert the first variable in the table of symbols as NumericVariable 
				// with the type BOOL and the value of the previous variable 
				lp::LogicalConstant *firstVar = new lp::LogicalConstant(this->_id,
										LOGICAL_CONSTANT,BOOL,secondVar->getValue());
				table.installSymbol(firstVar);
			}
			break;

			case STRING:
			{
				/* Get the identifier of the previous asgn in the table of symbols as StringConstant */
				lp::StringConstant *secondVar = (lp::StringConstant *) table.getSymbol(this->_asgn->getId());
				
				// Delete the first variable from the table of symbols 
				table.eraseSymbol(this->_id);

				// Insert the first variable in the table of symbols as NumericVariable 
				// with the type STRING and the value of the previous variable 
				lp::StringConstant *firstVar = new lp::StringConstant(this->_id,
										STRING_CONSTANT,STRING,secondVar->getValue());
				table.installSymbol(firstVar);
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Const Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStringStmt::printAST() 
{
  std::cout << "printASTStmt: printAST"  << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
  std::cout << std::endl;
}


void lp::PrintStringStmt::evaluate() 
{
	/* std::cout << BIYELLOW; 
	std::cout << "print: ";
	std::cout << RESET;  */

	if (this->_exp->getType() == STRING){
		for (std::string::size_type i = 0; i < this->_exp->evaluateString().size(); i++) {
    		if (this->_exp->evaluateString()[i] == '\\' && this->_exp->evaluateString()[i+1] == 't'){
				std::cout << "\t";
				i = i+1;
			}else if (this->_exp->evaluateString()[i] == '\\' && this->_exp->evaluateString()[i+1] == 'n'){
				std::cout << "\n";
				i = i+1;

			}else if (this->_exp->evaluateString()[i] == '\\' && this->_exp->evaluateString()[i+1] == '\''){
				std::cout << "'";
				i = i+1;

			}else{
				std::cout << this->_exp->evaluateString()[i];
			}
    	}
		/* std::cout << std::endl; */
	}else if(this->_exp->getType() == UNDEFINED){
		warning("Runtime error: The variable is not declare ", "print_string");
	
	}else if(this->_exp->getType() == NUMBER || this->_exp->getType() == BOOL){
		warning("Runtime error: The variable should be string type ", "print_string");

	}else{
		warning("Runtime error: incompatible type for ", "print_string");
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStmt::printAST() 
{
  std::cout << "printASTStmt: printAST"  << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
  std::cout << std::endl;
}


void lp::PrintStmt::evaluate() 
{
	/* std::cout << BIYELLOW; 
	std::cout << "print: ";
	std::cout << RESET;  */

	switch(this->_exp->getType())
	{
		case NUMBER:
				std::cout << this->_exp->evaluateNumber();
				break;
		case BOOL:
			if (this->_exp->evaluateBool())
				std::cout << "true";
			else
				std::cout << "false";
		
			break;
		case STRING:
			for (std::string::size_type i = 0; i < this->_exp->evaluateString().size(); i++) {
        		if (this->_exp->evaluateString()[i] == '\\' && this->_exp->evaluateString()[i+1] == 't'){
					std::cout << "\t";
					i = i+1;
				}else if (this->_exp->evaluateString()[i] == '\\' && this->_exp->evaluateString()[i+1] == 'n'){
					std::cout << "\n";
					i = i+1;

				}else if (this->_exp->evaluateString()[i] == '\\' && this->_exp->evaluateString()[i+1] == '\''){
					std::cout << "'";
					i = i+1;

				}else{
					std::cout << this->_exp->evaluateString()[i];
				}
    		}
			/* std::cout << std::endl; */
			break;
		case UNDEFINED:
			warning("Runtime error: The variable is not declare ", "print");
			break;
		default:
			warning("Runtime error: incompatible type for ", "print");
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStmt::printAST() 
{
  std::cout << "ReadStmt: read"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}


void lp::ReadStmt::evaluate() 
{   
	double value;
	/* std::cout << BIYELLOW; 
	std::cout << "Insert a numeric value --> " ;
	std::cout << RESET;  */
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        warning("Runtime error in Read(): the input is not numeric", "read");
		exit(EXIT_FAILURE);
    }else{
		/* Get the identifier in the table of symbols as Variable */
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		// Check if the type of the variable is NUMBER
		if (var->getType() == NUMBER)
		{
			/* Get the identifier in the table of symbols as NumericVariable */
			lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);
							
			/* Assignment the read value to the identifier */
			n->setValue(value);
		}
		// The type of variable is not NUMBER
		else
		{
			// Delete $1 from the table of symbols as Variable
			table.eraseSymbol(this->_id);

				// Insert $1 in the table of symbols as NumericVariable 
			// with the type NUMBER and the read value 
			lp::NumericVariable *n = new lp::NumericVariable(this->_id, 
										VARIABLE,NUMBER,value);

			table.installSymbol(n);
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStringStmt::printAST() 
{
  std::cout << "ReadStringStmt: ReadString"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}


void lp::ReadStringStmt::evaluate() 
{   
	std::string value;
	/* std::cout << BIYELLOW; 
	std::cout << "Insert a aphanumeric value --> " ;
	std::cout << RESET;  */
	getline(std::cin >> std::ws, value);
	//value.erase(remove(value.begin(), value.end(), '\''), value.end());
	
	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check if the type of the variable is STRING
	if (var->getType() == STRING)
	{
		/* Get the identifier in the table of symbols as NumericVariable */
		lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);
						
		/* Assignment the read value to the identifier */
		n->setValue(value);
	}
	// The type of variable is not STRING
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as NumericVariable 
		// with the type NUMBER and the read value 
		lp::StringVariable *n = new lp::StringVariable(this->_id, 
									  VARIABLE,STRING,value);

		table.installSymbol(n);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EmptyStmt::printAST() 
{
  std::cout << "EmptyStmt "  << std::endl;
}

void lp::EmptyStmt::evaluate() 
{
  // Empty
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::IfStmt::printAST() 
{
	std::list<Statement *>::iterator stmtIter;

  std::cout << "IfStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Consequent
  std::cout << "\t";
  	for (stmtIter = this->_stmts1->begin(); stmtIter != this->_stmts1->end(); stmtIter++) 
  	{
		(*stmtIter)->printAST();
	}

 // The alternative is printASTed if exists
  if (this->_stmts2 != NULL)
     {  
       std::cout << "\t";
	   for (stmtIter = this->_stmts2->begin(); stmtIter != this->_stmts2->end(); stmtIter++) 
  		{
    		(*stmtIter)->printAST();
  		}
     }

  std::cout << std::endl;
}


void lp::IfStmt::evaluate() 
{
	std::list<Statement *>::iterator stmtIter;

   // If the condition is true,
	if (this->_cond->evaluateBool() == true )
    	for (stmtIter = this->_stmts1->begin(); stmtIter != this->_stmts1->end(); stmtIter++) 
  		{
    		(*stmtIter)->evaluate();
  		}

    // Otherwise, the alternative is run if exists
	else if (this->_stmts2 != NULL)
		for (stmtIter = this->_stmts2->begin(); stmtIter != this->_stmts2->end(); stmtIter++) 
  		{
    		(*stmtIter)->evaluate();
  		}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::CaseStmt::printAST()
{
	/* std::list<ValueNode*>::iterator caseIter;
	std::cout << "CasesStmt: " << std::endl;
	std::cout << "\t";
	//Expression
	this->_cond->printAST();
	// Body of the cases statement
	std::cout << "\t";
	for (caseIter = this->_values->begin(); caseIter != this->_values->end(); caseIter++)
	{
		(*caseIter)->printAST();
	} */
	
	/* if (this->_defaultCase != NULL)
	{
	this->_defaultCase->print();
	} */
	std::cout << std::endl;
}

void lp::CaseStmt::evaluate()
{
	bool enteredCase = true;

	std::list<Statement *> *stmts = new std::list<Statement *>();


	int type = this->_cond->getType();
	int sizeNum = this->_caseValues->valuesNum->size();
	int sizeCad = this->_caseValues->valuesCad->size();
	int sizeLog = this->_caseValues->valuesLog->size();

	if (type == UNDEFINED){
		warning("Runtime error: Variable undeclared in condition", "case");

	}else if (sizeNum != 0 && type != NUMBER){
		warning("Semantic error: Condition and value(s) type are different", "case");

	}else if(sizeCad != 0 && type != STRING){
		warning("Semantic error: Condition and value(s) type are different", "case");

	}else if(sizeLog != 0 && type != BOOL){
		warning("Semantic error: Condition and value(s) type are different", "case");

	}else{
		if (type == NUMBER){
				
			try{
				*stmts = this->_caseValues->valuesNum->at(this->_cond->evaluateNumber());
			}catch (const std::out_of_range& oor) {
				enteredCase = false;
			}

		}else if(type == BOOL){
			try{
				*stmts = this->_caseValues->valuesLog->at(this->_cond->evaluateBool());
			}catch (const std::out_of_range& oor) {
				enteredCase = false;
			}
				
		}else if (type == STRING){

			try{
				*stmts = this->_caseValues->valuesCad->at(this->_cond->evaluateString());
			}catch (const std::out_of_range& oor) {
				enteredCase = false;
			}

		}else{
			warning("Runtime error: incompatible types for ", "case");
		}


		std::list<Statement *>::iterator stmtIter;

		for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
		{
			(*stmtIter)->evaluate();
		}


		if (!enteredCase && this->_defaultCase != NULL)
		{
			for (stmtIter = this->_defaultCase->begin(); stmtIter != this->_defaultCase->end(); stmtIter++) 
			{
				(*stmtIter)->evaluate();
			}
		} 
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::WhileStmt::printAST() 
{
  std::cout << "WhileStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the while loop
  std::cout << "\t";
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
	(*stmtIter)->printAST();
  }

  std::cout << std::endl;
}


void lp::WhileStmt::evaluate() 
{
	std::list<Statement *>::iterator stmtIter;

  // While the condition is true. the body is run 
  while (this->_cond->evaluateBool() == true)
  {	
	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
  	}
  }

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::DoWhileStmt::printAST() 
{
  std::cout << "DoWhileStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the Repeat loop
  std::cout << "\t";
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
	(*stmtIter)->printAST();
  }

  std::cout << std::endl;
}


void lp::DoWhileStmt::evaluate() 
{
	std::list<Statement *>::iterator stmtIter;

  // While the condition is true the body is run and its run at least once
  
  do{	
	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
  	}
  }while (this->_cond->evaluateBool() == true);

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::RepeatStmt::printAST() 
{
  std::cout << "RepeatStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the Repeat loop
  std::cout << "\t";
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
	(*stmtIter)->printAST();
  }

  std::cout << std::endl;
}


void lp::RepeatStmt::evaluate() 
{
	std::list<Statement *>::iterator stmtIter;

  // While the condition is false the body is run and its run at least once
  
  do{	
	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
  	}
  }while (this->_cond->evaluateBool() == false);

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::ForStmt::printAST() 
{
  /* std::cout << "RepeatStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the Repeat loop
  std::cout << "\t";
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
	(*stmtIter)->printAST();
  }

  std::cout << std::endl; */
}


void lp::ForStmt::evaluate() 
{
	double from = this->_from->evaluateNumber(); //Get the from value: $5
	double to = this->_to->evaluateNumber(); //Get the to value: $7

	double step;

	/* Default step */
	if (this->_step == NULL){
		step = 1;
	}else{
		step = this->_step->evaluateNumber(); //Get the step value: $9 (Not default step)
	}

	/* Check the for loop ranges */

	if (from < to && step < 0){ //Ex: from 2 to 10 step -1
		warning("Semantic error: Step is negative", "For Loop");
	
	}else if (from > to && step > 0){ //Ex: from 10 to 2 step 1
		warning("Semantic error: Step is positive", "For Loop");
	
	}else if (step == 0){
		warning("Semantic error: Step cannot be 0", "For Loop");

	}else{

		// Delete from the table of symbols
		table.eraseSymbol(this->_id);

		// Insert it in the table of symbols as NumericVariable 
		// with the type NUMBER and the "from" value 
		lp::NumericVariable *n = new lp::NumericVariable(this->_id,VARIABLE,NUMBER,from);

		table.installSymbol(n);	
	
		// The body is run until the break conditions ocurrs
		while(true){

			std::list<Statement *>::iterator stmtIter;
			for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
			{
				(*stmtIter)->evaluate();
			}

			//Calculate the next value = actual value + step
			double next = n->getValue()+step;

			/* Only do the next iteration if actual value + step is not greather than final value */
			if (next <= to && from < to){
				n->setValue(next);

			/* Only do the next iteration if actual value + step is not smaller than final value */
			}else if (next >= to && from > to){
				n->setValue(next);

			}else{
				break;
			}
		}

	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::PlaceStmt::printAST() 
{
  std::cout << "PlaceStmt: "  << std::endl;

  std::cout << "\t";
  this->_x->printAST();

   std::cout << "\t";
  this->_y->printAST();

  std::cout << std::endl;
}


void lp::PlaceStmt::evaluate() 
{
	PLACE((int)this->_x->evaluateNumber(),(int)this->_y->evaluateNumber());
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::ClearStmt::printAST() 
{
  std::cout << "ClearStmt: "  << std::endl;
  std::cout << std::endl;
}


void lp::ClearStmt::evaluate() 
{
	std::cout << CLEAR_SCREEN;
	PLACE(0,0);	
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::StyleStmt::printAST() 
{
  std::cout << "StyleStmt: "  << std::endl;
  std::cout << std::endl;
}


void lp::StyleStmt::evaluate() 
{	
		std::transform(this->_style.begin(), this->_style.end(), this->_style.begin(), ::toupper);
		
			if (_style == "BLACK") {
				std::cout << BLACK;
			} else if (_style == "RED") {
				std::cout << RED;
			} else if (_style == "GREEN") {
				std::cout << GREEN;
			} else if (_style == "YELLOW") {
				std::cout << YELLOW;
			} else if (_style == "BLUE") {
				std::cout << BLUE;
			} else if (_style == "PURPLE") {
				std::cout << PURPLE;
			} else if (_style == "CYAN") {
				std::cout << CYAN;
			} else if (_style == "WHITE") {
				std::cout << WHITE;
			} else if (_style == "RESET") {
				std::cout << RESET;
			} else if (_style == "INTENSITY") {
				std::cout << INTENSITY;
			} else if (_style == "FAINT") {
				std::cout << FAINT;
			} else if (_style == "ITALIC") {
				std::cout << ITALIC;
			} else if (_style == "UNDERLINE") {
				std::cout << UNDERLINE;
			} else if (_style == "BLINK") {
				std::cout << BLINK;
			} else if (_style == "INVERSE") {
				std::cout << INVERSE;
			}else{
				warning("Semantic error: The string doesnt correspond with a color", _style);
			}
	
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::BlockStmt::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}


void lp::BlockStmt::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}





///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AST::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}



void lp::AST::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}

