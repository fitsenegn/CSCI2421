#include <iostream>
#include <unordered_map>
#include "housekeeping.h"
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]){
  std::string filename = "";

	//------Only take one commandline argument in the specified form--------

	  if(argc < 2){
	    cout << "No file specified. Using default file \"check.txt\": " << endl;
			filename = "check.txt";
	  }else if(argc > 2){
	    cout << "Too many arguments. Call with: " << endl;
	    cout << "     ./spell_checker [filename]" << endl;
	    return 0;

	  }else{ //if currect, this is the file we are opening

	    filename = argv[1];
	  }

    std::unordered_map<std::string,int> dict;
    dict.reserve(1373);
    std::unordered_map<std::string,int> toCheck;
    toCheck.reserve(1373);

    //---------------read dict-------------

    exception_status exception; //catch any errors

    exception = readIn("dict.txt", &dict);

    if(exception.error == true){ //check error and report to user
        cout << exception.what() << exception.which << endl;
        return 0;
    }

    //----------------read user file----------------

    exception = readIn(filename, &toCheck);

    if(exception.error == true){ //check error and report to user
        cout << exception.what() << exception.which << endl;
        return 0;
    }

    //----------------check spelling----------------

    int countWords = 0;

    std::vector<misspelling> misspelledWords;

    for(std::unordered_map<std::string,int>::iterator it = toCheck.begin();
        it != toCheck.end(); it++){

          if (dict.count(it->first) > 0){
            // std::cout << "\nFound " + it->first + "!!\n\n";
          }else{
            // std::cout << "\nI couldn't find " + it->first + "..\n\n";
            misspelledWords.emplace_back(it->first, it->second); //save the misspelled word
            countWords++; //count
          };
        }


    //----------------print results----------------

    std::cout << "\n\nThe following words were misspelled in your document:" << std::endl;
    int carriageReturn = 0;
    std::string buffer = ": on line "; //Chose to not implement this functionality
    std::string buffer1 = "     |    ";
    for(int i = 0; i < misspelledWords.size(); i++){
      cout  << buffer1 << misspelledWords[i].word; //show errors
            // << buffer << misspelledWords[i].line; //used to specify location

      carriageReturn += (misspelledWords[i].word.size()
                     // +  getPlaces(misspelledWords[i].line)
                     // +  buffer.size()
                     +  buffer1.size()); //count the line size for formatting

       if(carriageReturn > 50){ //if the text needs to wrap
          std::cout << std::endl;
          carriageReturn = 0;
        }

    }

    std::cout << "\nThere were " << dict.size() << " unique words in dict.txt.\n\n";
    std::cout << "\nThere were " << toCheck.size() << " unique words in " + filename + "\n\n";
    std::cout << "\nThere were " << countWords << " words in " + filename +
                 " that did not exist in dict.txt\n\n";

  return 0;
}



// if (dict.count("ababa") > 0){
//   std::cout << "\nFound ababa!!\n\n";
// }else{
//   std::cout << "\nI couldn't find ababa..\n\n";
// };
//
// if (dict.count("advisory") > 0){
//   std::cout << "\nFound advisory!!\n\n";
// }else{
//   std::cout << "\nI couldn't find advisory..\n\n";
// };
//
// if (dict.count("a&m") > 0){
//   std::cout << "\nFound a&m!!\n\n";
// }else{
//   std::cout << "\nI couldn't find a&m..\n\n";
// };
//
// if (dict.count("zygote") > 0){
//   std::cout << "\nFound zygote!!\n\n";
// }else{
//   std::cout << "\nI couldn't find zygote..\n\n";
// };
//
// if (dict.count("winifred") > 0){
//   std::cout << "\nFound winifred!!\n\n";
// }else{
//   std::cout << "\nI couldn't find winifred..\n\n";
// };
