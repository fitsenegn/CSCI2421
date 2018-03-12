#include <iostream>
#include "calculatorOperations.h"
#include "MyArrayStack.h"

using std::cout;
using std::cin;
using std::endl;




int main(){
  Calculator calculator;
  std::string infix = calculator.toPostfix("a*(b+c)");

  cout << infix << endl;

    return 0;
}
