#include <iostream>
#include <unordered_map>
#include "housekeeping.h"

using std::cin;
using std::cout;
using std::endl;




int main(int argc, char* argv[]){
  std::string filename = "";

	//------Only take one commandline argument in the specified form--------

	  if(argc < 2){
	    cout << "No file specified. Using default file \"text.txt\": " << endl;
			filename = "text.txt";
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

    readIn("dict.txt", &dict);

    if (dict.count("ababa") > 0){
      std::cout << "\nFound ababa!!\n\n";
    }else{
      std::cout << "\nI couldn't find ababa..\n\n";
    };

    if (dict.count("advisory") > 0){
      std::cout << "\nFound advisory!!\n\n";
    }else{
      std::cout << "\nI couldn't find advisory..\n\n";
    };

    if (dict.count("a&m") > 0){
      std::cout << "\nFound a&m!!\n\n";
    }else{
      std::cout << "\nI couldn't find a&m..\n\n";
    };

    if (dict.count("zygote") > 0){
      std::cout << "\nFound zygote!!\n\n";
    }else{
      std::cout << "\nI couldn't find zygote..\n\n";
    };

    if (dict.count("winifred") > 0){
      std::cout << "\nFound winifred!!\n\n";
    }else{
      std::cout << "\nI couldn't find winifred..\n\n";
    };

  return 0;
}
