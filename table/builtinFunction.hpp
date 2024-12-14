/*! 
  \file builtinFunction.hpp
  \brief Prototypes of builtin functions 
*/

#ifndef _BULTINFUNCTION_HPP_
#define _BUILTINFUNCTION_HPP_

#include <string>


/*!	
	\brief   Compute the neperian logarithm of a real number
	\note    Check first if there is an error in the argument.
	\param	 x: double
	\return  log(x)
	\sa		 errcheck, log
*/
double Log(double x);

/*!	
	\brief   Compute the decimal logarithm of a real number
	\note    Check first if there is an error in the argument.
	\param	 x: double
	\return  log10(x)
	\sa		 errcheck, log10
*/
double Log10(double x);

/*!	
	\brief   Compute the exponential of a real number
	\note    Check first if there is an error in the argument.
	\param	 x: double
	\return  exp(x)
	\sa		 errcheck, exp
*/
double Exp(double x);

/*!	
	\brief   Compute the square root of a real number
	\note    Check first if there is an error in the argument.
	\param	 x: double
	\return  sqrt(x)
	\sa		 errcheck, sqrt
*/
double Sqrt(double x);


/*!	
	\brief   Compute the integer part a real number
	\param	 x: double
	\return  (double) (long) x;		 
*/
double integer(double x);


/*!	
	\brief   Convert radians in degrees
	\param	 x: double
	\return  x * (180.0 / M_PI)		 
*/
double to_degrees(double x);

/*!	
	\brief   Convert degrees in radians
	\param	 x: double
	\return  x * (M_PI / 180.0)	 
*/
double to_radians(double x);


/////////////////////////////////
/*!	
	\brief   Compute a random number
	\return  (double) (long) rand() / RAND_MAX;		 
*/
double Random();



////////////////////////////////

/*!	
	\brief   Compute the atan(x/y) 
	\param	 x: double
	\param	 y: double
	\return  atan(x/y)
	\sa		 
*/
double Atan2(double x, double y);



#endif
