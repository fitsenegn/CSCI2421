#include "exception.h"
#include <unordered_map>
exception_status readIn(std::string, std::unordered_map<std::string,int>*);

int getPlaces(int);

struct misspelling{ //used to give details on the misspelling
  std::string word;
  int line;

  misspelling(std::string s, int n) : word(s),line(n) //quick vector push
  { }
};
