#include <iostream>
#include "dictionary.h"
#include "housekeeping.h"

using std::cout;
using std::cin;
using std::endl;




int main(){
  somePages searchTerms;
  dictionary newDictionary;
  newDictionary.readDictionary("dictionary.txt");
  newDictionary.sortList();
  newDictionary.print();
  readIn("findwords.txt",searchTerms);


  cout << "SEARCHING TERMS FORWARD. . . \n";
//Search every term forward
  for(somePages::iterator i = searchTerms.begin(); i != searchTerms.end(); i++){
    wordType term = i->getWord();
    int count = newDictionary.searchForward(term);
    if(count == -1){
      cout << term << " was not found in the dictionary." << endl;
    }else if(count > 0){
      cout << term << " was found in " << count << " comparisons." << endl;
    }else{
      cout << "Something went wrong.";
    }
  }

  cout << "\n\nSEARCHING TERMS BACKWARD. . . \n";
//Search every term backwards
  for(somePages::iterator i = searchTerms.begin(); i != searchTerms.end(); i++){
    wordType term = i->getWord();
    int count = newDictionary.searchBackward(term);
    if(count == -1){
      cout << term << " was not found in the dictionary." << endl;
    }else if(count > 0){
      cout << term << " was found in " << count << " comparisons." << endl;
    }else{
      cout << "Something went wrong.";
    }
  }

//Print out reversed list
std::filebuf fileOutput;
fileOutput.open("revsorted.txt", std::ios::out);
std::ostream outFile(&fileOutput);
newDictionary.revPrintList(outFile);



    return 0;
}
