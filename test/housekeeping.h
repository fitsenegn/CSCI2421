#ifndef HOUSEKEEPING_H_
#define HOUSEKEEPING_H_

#include "exception.h"
#include "BinaryNodeTree.h"

/** @subsection Housekeeping
  * All the trivial functions that make it happen*/

exception_status readInPeople(std::string, BinaryNodeTree<Actor_Actress,std::string>*);
exception_status readInPictures(std::string, BinaryNodeTree<Picture,std::string>*);


exception_status readOutPeople(std::string, BinaryNodeTree<Actor_Actress,std::string>*);

exception_status readOutPictures(std::string, BinaryNodeTree<Picture,std::string>*);

int getSearchTerm(std::string&, std::string);


#endif
