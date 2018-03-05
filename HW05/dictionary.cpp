#include "dictionary.h"


/*Searches the list starting at the front of the list and moving to the back
 Returns the number of searches it took to find the findString, or a -1 if not found*/
int dictionary::searchForward(wordType &findString){
  int count = 1; //keep track of comparisons
  //iterate through the list and compare findString until end()
  for(somePages::iterator i = this->wordList.begin(); i != this->wordList.end(); ++i){
          if(i->getWord() == findString){
            return count; //success case
          }
      count++;
  }
  return -1; //fail case
}

/*Searches the list starting at the back of the list and moving to the front
 Returns the number of searches it took to find the findString, or a -1 if not found*/
int dictionary::searchBackward(wordType &findString){
  int count = 1; //keep track of comparisons
  //iterate in reverse through the list and compare findString until rend()
  for(somePages::reverse_iterator i = this->wordList.rbegin(); i != this->wordList.rend(); ++i){
          if(i->getWord() == findString){
            return count; //success case
          }
      count++;
  }
  return -1; //fail case
}

/*Prints the list of words in reverse alphabetic order to a file*/
void dictionary::revPrintList(ostream& output){
  //iterate in reverse through the list and print out each element
  for(somePages::reverse_iterator i = this->wordList.rbegin(); i != this->wordList.rend(); ++i){
      output << i->getWord() << " ";
  }
}

/*Iterate through the list and print out each element*/
void dictionary::print(){
  somePages print = this->wordList;

  for(somePages::iterator i = print.begin(); i != print.end(); ++i){
          std::cout << (*i);
          std::cout << "\n";
  }
}
