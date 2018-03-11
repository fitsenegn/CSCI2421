#include "calculatorOperations.h"


std::string Calculator::toPostfix(std::string infix) {
  std::string postFix;
  MyStack<char> operatorStack;

  for(int i = 0; i <= infix.length(); i++){
    char C = infix[i];

    if(isNumber(C)){ // add the number to the postfix expression
      postFix =+C;
    }else if(C == '('){ //save this for processing operators
      operatorStack.push(C);
    }else if(isOperator(C)){ //check for precedence and process
      while(!operatorStack.isEmpty() &&
             operatorStack.peek() != '(' &&
             precedence(C) <= precedence(operatorStack.peek()))
             {
                  postFix+= operatorStack.peek();
                  operatorStack.pop();
             }
             operatorStack.push(C); //save current operator

    }else if(C == ')'){ //look for a matching '('
      while(operatorStack.peek() != '(')
      {
            postFix+= operatorStack.peek();
            operatorStack.pop();
      }
      operatorStack.pop(); //remove the found '('
    }
  }
  //Finish up processing the stack.
  while(!operatorStack.isEmpty()){
    postFix =+ operatorStack.peek();
    operatorStack.pop();
  }
  return postFix;
}


//------------------HOUSEKEEPING

/** Check whether character is an operator */
bool isOperator(char C) {
  if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
    return true;

  return false;
}

/** Verify that the character is in fact a number. */
bool isOperand(char C) {

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
int precedence(char C){
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
