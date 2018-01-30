#include <iostream>
#include "Guess.h"


using std::endl;
using std::cin;
using std::cout;



int main(){
  srand((int)time(0)); // seed with system clock (true random)

  Guess test;

  while(test.startGuess() ==  -1); //do while user selects "play again"

  std::cout << "Good-Bye!" << std::endl;


  return 0;
}
