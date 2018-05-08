#ifndef HOUSEKEEPING_H_
#define HOUSEKEEPING_H_

#include "exception.h"
#include "BinaryNodeTree.h"

exception_status readInPeople(std::string, BinaryNodeTree<Actor_Actress,std::string>*);
exception_status readInPictures(std::string, BinaryNodeTree<Picture,std::string>*);

exception_status readOutPeople(std::string, BinaryNodeTree<Actor_Actress,std::string>*);
exception_status readOutPictures(std::string, BinaryNodeTree<Picture,std::string>*);

int getSearchTerm(std::string&, std::string);
int getPlaces(int);


struct misspelling{ //used to give details on the misspelling
  std::string word;
  int line;

  misspelling(std::string s, int n) : word(s),line(n) //quick vector push
  { }
};
#endif
