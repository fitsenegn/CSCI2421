#include <iostream>
#include "dictionary.h"
#include "housekeeping.h"

using std::cout;
using std::cin;
using std::endl;




int main(){
  somePages searchTerms;
  somePages initializingList;

  readIn("dictionary.txt", initializingList); //read in the dictionary terms
  dictionary newDictionary(initializingList);


  readIn("findwords.txt",searchTerms); //read in the terms to be searched

  newDictionary.sortList();

  cout << "\n\nFORWARD SEARCHING TERMS. . . \n";
//Search every term forward
  for(somePages::iterator i = searchTerms.begin(); i != searchTerms.end(); i++){
    wordType term = i->getWord();
    int count = newDictionary.searchForward(term); //search
    if(count == -1){ //print to interface
      cout << term << " was not found in the dictionary." << endl;
    }else if(count > 0){
      cout << term << " was found in " << count << " comparisons." << endl;
    }else{
      cout << "Something went wrong.";
    }
  }

  cout << "\n\nBACKWARD SEARCHING TERMS. . . \n";
//Search every term backwards
  for(somePages::iterator i = searchTerms.begin(); i != searchTerms.end(); i++){
    wordType term = i->getWord(); //search
    int count = newDictionary.searchBackward(term);
    if(count == -1){//print to interface
      cout << term << " was not found in the dictionary." << endl;
    }else if(count > 0){
      cout << term << " was found in " << count << " comparisons." << endl;
    }else{
      cout << "Something went wrong.";
    }
  }

//Print out reversed list
cout << "\n\nPrinting out revsorted.txt. . .\n\n";
std::filebuf fileOutput; //create a buffer
fileOutput.open("revsorted.txt", std::ios::out); //open buffer and connect to file
std::ostream outFile(&fileOutput); //initialize ostream with this new buffer
newDictionary.revPrintList(outFile); //write out newDictionary



    return 0;
}
