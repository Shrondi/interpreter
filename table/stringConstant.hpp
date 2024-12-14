/*!	
	\file    StringConstant.hpp
	\brief   Declaration of StringConstant class
	\author  
	\date    2017-12-5
	\version 1.0
*/

#ifndef _STRINGCONSTANT_HPP_
#define _STRINGCCONSTANT_HPP_

#include <string>
#include <iostream>

#include "constant.hpp"

/*!	
	\namespace lp
	\brief Name space for the subject Language Processors
*/
namespace lp{

/*!	
  \class StringConstant
  \brief Definition of atributes and methods of StringConstant class
  \note  StringConstant Class publicly inherits from Constant class
*/
class StringConstant:public lp::Constant
{
/*!		
\name Private atributes of StringConstant class
*/
	private:
		std::string      _value;   //!< \brief Numeric value of the StringConstant

/*!		
\name Public methods of StringConstant class
*/
	public:

/*!	
	\name Constructors
*/
		
/*!		
	\brief Constructor with arguments with default values
	\note  Inline function that uses Constant's constructor as members initializer
	\param name: name of the StringConstant
	\param token: token of the StringConstant
	\param type: type of the StringConstant
	\param value: numeric value of the StringConstant
	\pre   None
	\post  A new StringConstant is created with the values of the parameters
	\sa   setName, setValue
*/
	inline StringConstant(std::string name="", int token = 0, int type = 0, std::string value=""): 
 	Constant(name,token,type)
	{
		this->setValue(value);
	}
		
/*!		
	\brief Copy constructor
	\note  Inline function
	\param n: object of StringConstant class
	\pre   None
	\post  A new StringConstant is created with the values of an existent StringConstant
	\sa    setName, setValue
*/
	StringConstant(const StringConstant & n)
	{
		// Inherited methods
		this->setName(n.getName());

		this->setToken(n.getToken());

		this->setType(n.getType());
		
		// Own method
		this->setValue(n.getValue());
	}


/*!	
	\name Observer
*/
	
/*!	
	\brief  Public method that returns the value of the StringConstant
	\note   Función inline
	\pre    None
	\post   None
    \return Value of the StringConstant
	\sa		getValue
*/
	inline std::string getValue() const
	{
		return this->_value;
	}



/*!	
	\name Modifier
*/
		
/*!	
	\brief   This functions modifies the value of the StringConstant
	\note    Inline function
	\param   value: new value of the StringConstant
	\pre     None
	\post    The value of the StringConstant is equal to the parameter 
	\return  void
	\sa 	 setValue
*/
	inline void setValue(const std::string & value)
	{
	    this->_value = value;
	}



		
/*!	
	\name I/O Functions
*/
		
/*!		
	\brief Read a StringConstant
	\pre   None
	\post  The atributes of the StringConstant are modified with the read values
    \sa    write
*/
	void read();

	
/*!		
	\brief Write a StringConstant
	\pre   None
	\post  None
    \sa    read
*/
	void write() const;


/*!	
	\name Operators
*/
	
/*!		
	\brief  Assignment Operator
	\param  n: objectoof StringConstant class
	\post   The atributes of this object are equal to the atributes of the parameter
	\return Reference to this object
*/
	StringConstant &operator=(const StringConstant &n);
	

 //! \name Friend functions
/*!		
	\brief  Insertion operator
	\param  i: input stream
	\param  n: object of StringConstant class
	\pre    nome
	\post   The atributes of the StringConstant are modified with the inserted values from the input stream
	\return The input stream
*/
	friend std::istream &operator>>(std::istream &i, StringConstant &n);

/*!		
	\brief  Extraction operator
	\param  o: output stream
	\param  n: object of StringConstant class
	\pre    nome
	\post   The atributes of the StringConstant are written in the output stream
	\return The output stream
*/
	friend std::ostream &operator<<(std::ostream &o, StringConstant const &n);
	
// End of StringConstant class
};

// End of name space lp
}

// End of _StringConstant_HPP_
#endif
