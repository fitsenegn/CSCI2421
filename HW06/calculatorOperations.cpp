#include "calculatorOperations.h"


std::string Calculator::toPostfix(std::string infix) {
  std::string postFix;
  StackInterface<char>* operatorStackptr =  new MyArrayStack<char>();

  for(int i = 0; i <= infix.length(); i++){
    char C = infix[i];

    if(isNumber(C)){ // add the number to the postfix expression
      postFix.push_back(C);
    }else if(C == '('){ //save this for processing operators
      operatorStackptr->push(C);
    }else if(isOperator(C)){ //check for precedence and process
      while(!operatorStackptr->isEmpty() &&
             operatorStackptr->peek() != '(' &&
             precedence(C) <= precedence(operatorStackptr->peek()))
             {
                  postFix.push_back(operatorStackptr->peek());
                  operatorStackptr->pop();
             }
             operatorStackptr->push(C); //save current operator

    }else if(C == ')'){ //look for a matching '('
      while(operatorStackptr->peek() != '(')
      {
            postFix.push_back(operatorStackptr->peek());
            operatorStackptr->pop();
      }
      operatorStackptr->pop(); //remove the found '('
    }
  }
  //Finish up processing the stack.
  while(!operatorStackptr->isEmpty()){
    postFix.push_back(operatorStackptr->peek());
    operatorStackptr->pop();
  }
  return postFix;
}

#include <iostream>
int Calculator::solve(std::string postFix){
  int value = -1;
  StackInterface<char>* stackPtr =  new MyArrayStack<char>();

  for(int i = 0; i < postFix.length(); i++){
    char C = postFix[i];
    if(isNumber(C)){ // put on the number stack
      stackPtr->push(C);
    }else{
      int operand2 = ((stackPtr->peek()) - '0');
      stackPtr->pop();
      int operand1 = ((stackPtr->peek()) - '0');
      stackPtr->pop();

      switch(C){
        case '+': value = operand1 + operand2;
        stackPtr->push(value + '0');
          break;
        case '-': value = operand1 - operand2;
        stackPtr->push(value + '0');
          break;
        case '*': value = operand1 * operand2;
        stackPtr->push(value + '0');
          break;
        case '/': value = operand1 / operand2;
        stackPtr->push(value + '0');
          break;
        default: std::cout << "\nOHNOOOOOO\n";
          break;
      }
    }

  }

  return value;
}


//------------------HOUSEKEEPING

/** Check whether character is an operator */
bool Calculator::isOperator(char C) {
  if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
    return true;

  return false;
}

/** Verify that the character is in fact a number. */
bool Calculator::isNumber(char C) {

  if (C >= 'a' && C <= 'z') { // is a letter
    return true;
  } else if (C >= 'A' && C <= 'Z') { // is a letter
    return true;
  } else if (C >= '0' && C <= '9') { // is a number
    return true;
  } else {
    return false;
  }
}

/** Check the precedence of an operator and return its weight */
int Calculator::precedence(char C){
  	int precedence = -1; //fail case.

  	switch(C)
  	{
  	case '+':
  	case '-':
  		precedence = 1; //equal
      break;
  	case '*':
  	case '/':
  		precedence = 2; //equal
      break;
  	// case '$':
  		// precedence = 3;
  	}
  	return precedence;

}
