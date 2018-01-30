#include <vector>
#include <cstdlib>

class Guess{


public:

int startGuess(); //startGuess member function

int createRandomNumbers(); //member function

void sortNumbers();

int compareGuess(int *n);

int* convertGuess(std::string);

std::string printNumbers();

void reset();

Guess()
{   }

~Guess()
{   }

private:

std::vector<int> randomVector; //(will contain n random integers)



};
