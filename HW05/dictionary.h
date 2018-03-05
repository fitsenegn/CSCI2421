/* Dr. Augustine
 dictionary.h
 Last Updated:02/14/2016
 Status: Compiles and all requirements met*/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <list>
#include <iostream>
#include "DictEntry.h"
#include "exception.h"
#include <fstream>

using namespace std;
typedef list<DictEntry> somePages;

class dictionary
{
public:
    //typedef string wordType;
    dictionary()
    { }

    dictionary(somePages init): wordList(init)
    {   }

    /*Searches the list starting at the front of the list and moving to the back
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    int searchForward(wordType &findString);

    /*Searches the list starting at the back of the list and moving to the front
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    int searchBackward(wordType &findString);

    /*Prints the list of words in reverse alphabetic order to a file*/
    void revPrintList(ostream& output);

    /*Sorts the list of words in alphabetical order*/
    void sortList(){ this->wordList.sort(); }

    /*Debug print*/
    void print();

private:
    list<DictEntry> wordList;


};

/*******************************/



#endif /* dictionary_h */
