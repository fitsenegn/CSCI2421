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

    int lineCount = 0;

    while(!infile.eof()){

      count++;

      std::string temp;

      int startRead = infile.tellg();
      std::getline(infile, temp, '\n'); //read the current word up to newline
      lineCount++;

      bool line = false;
      for(int i = 0; i < temp.size()+1; i++){ //check for spaces
        if(temp[i] == ' '){  //if index is space
          line = true;
          lineCount--;
          break;
        }
      }

      if(line == true){ //if a line was read in
        infile.seekg(startRead); //Move back to the start of read
        std::getline(infile, temp, ' '); //read until spaces instead
      }

      for(int i = 0; i < temp.size()+1; i++){ //strip punctuation
        if(ispunct(temp[i])){  //if index is punctuation
          temp.erase(i, i-1); //remove the current character
        }else{
          temp[i] = tolower(temp[i]); //capitals cause problems with sort
        }
      }

      if(temp.size() > 0){ //if the read thing wasn't ONLY punctuation
        if(temp != " ") // and wasn't just a space
            hashMap->insert({temp, count});

      }

    if (infile.fail()) {
        // set error
        error.badCall("input_error_line_");
        error.which = lineCount;
        return error; // if the file didn't read correctly, no need to continue.
    }

    infile >> std::ws;
  }

  return error;
}




/**Checks how many places are used for an int. Used to determine number of
   Characters needed to represent a number. Used for carriage return.
   @param n is the int to check;
   @return places is the amount of Characters   */
int getPlaces(int n){
int places = 0;
  while(n > 0){
    n /= 10;
    places++;
  }
return places;
}
