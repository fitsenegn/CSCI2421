#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include "MyArrayStack.h"

class Calculator{
public:
  /** Convert an infix expression to postfix.
  \@param  The infix expression.
  \@return  The postfix expression.   */
  std::string toPostfix(std::string);

  int solve(std::string);

  /** Check whether character is an operator */
  bool isOperator(char);
  /** Verify that the character is in fact a number. */
  bool isNumber(char);
  /** Check the precedence of operators */
  int precedence(char);


};





#endif
