#include <vector>
#include <cstdlib>
#include <string>


/**Guess contains all the neccesary methods to play a game of guessing a
  *Random number.
  *To play, create object of guess and call the .startGuess method.*/
class Guess{


public:

int startGuess();

int createRandomNumbers();

void sortNumbers();

int compareGuess(int *n);

int* convertGuess(std::string s);

std::string printNumbers();

void reset();

Guess()
{   }

~Guess()
{   }

private:

std::vector<int> randomVector; //(will contain n random integers)



};
