#include <iostream>
#include "calculatorOperations.h"


using std::cout;
using std::cin;
using std::endl;




int main(){
  Calculator calculator;
  std::string infix;
  cout << "Please enter an infix expression to be calculated.\n";
  // cin.ignore();
  getline(cin,infix);
  cout << "\n\n        Computing \"" << infix << "\"\n" << endl;

  std::string postFix = calculator.toPostfix(infix);
// "1-(2+3*4)/5"
  cout << "\n  Converted to postFix \"" << postFix << "\"\n" << endl;

  cout << "Result: " << calculator.solve(postFix) << endl;

    return 0;
}
