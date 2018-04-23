#include "housekeeping.h"
#include <fstream>
#include <iostream>

/**Read in text continuously into hash and strip all whitespace and
   punctuation leaving only spaces.
   *\param hashMap is the tree to be read into
   *\param file is the name of the file to be readIn
                                      | std::ifstream needs std::string
   *\return error tracks if there was an error, what type, and where in the
                                                                          file.*/
/*Read each entry in a specified file into the tree*/
exception_status readIn(std::string file, std::unordered_map<std::string,int>* hashMap){
  exception_status error;

    int count = 0;

    std::ifstream infile;

        infile.open(file);

        ///////////check file/////////
      if (!infile.is_open() || infile.fail()) {
          // set error
          error.badCall("file_invalid");
          return error; // if the file didn't read, no need to continue.
      }




    count = 0; //what line are we on?

    infile >> std::ws; //strip initial whitespace


    while(!infile.eof()){

      count++;

      std::string temp;

      std::getline(infile, temp, '\n'); //read the current word up to newline

      for(int i = 0; i < temp.size()+1; i++){ //strip punctuation
        if(ispunct(temp[i])){  //if index is punctuation
          temp.erase(i, i-1); //remove the current character
        }else{
          temp[i] = tolower(temp[i]); //capitals cause problems with sort
        }
      }

      if(temp.size() > 0){ //if the read thing wasn't ONLY punctuation

      hashMap->insert({temp, count});

      }
      std::cout << "\n\nInserted " + temp + ".\n\n";

    if (infile.fail()) {
        // set error
        error.badCall("input_error_line_");
        error.which = count;
        return error; // if the file didn't read correctly, no need to continue.
    }
  }

  return error;
}


/** Screens user input for validity
\param 'prompt' is displayed to the user, 'readVal' is the input variable
\return '-1' returned if invalid input, '0' returned if validity */
int getSearchTerm(std::string& readVal, std::string prompt){
  std::cout << prompt;
  std::cin >> readVal;

  for(int i = 0; i < readVal.size()+1; i++){ //strip punctuation
    if(ispunct(readVal[i])){  //if index is punctuation
      readVal.erase(i, i-1); //remove the current character
    }else{
      readVal[i] = tolower(readVal[i]); //capitals cause problems with sort
    }
  }

  if (std::cin.fail()) // check type
  {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    std::cout << "***invalid***" << '\n';
    return -1;
  } else {
    return 0;
  }

  return -1;
};
