#include <iostream>
#include "Guess.h"


using std::endl;
using std::cin;
using std::cout;



int main(){
  srand((int)time(0)); // seed with system clock (true random)

  Guess test;

  test.startGuess();

  std::cout << "Good-Bye!" << std::endl;


  return 0;
}
