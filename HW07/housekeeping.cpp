#include "housekeeping.h"
#include <fstream>

/**Read in text continuously into linked list and strip all whitespace and
   punctuation leaving only spaces.
   *\param root is the tree to be read into
   *\param file is the name of the file to be readIn
                                      | std::ifstream needs std::string
   *\return error tracks if there was an error, what type, and where in the
                                                                          file.*/
/*Read each entry in a specified file into the tree*/
exception_status readIn(std::string file, BinaryNodeTree<std::string>* root){
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

      std::getline(infile, temp, ' '); //read the current word up to space

      for(int i = 0; i < temp.size()+1; i++){ //strip punctuation
        if(ispunct(temp[i])){  //if index is punctuation
          temp.erase(i, i-1); //remove the current character
        }else{
          temp[i] = tolower(temp[i]); //capitals cause problems with sort
        }
      }

      if(temp.size() > 0){ //if the read thing wasn't ONLY punctuation

      root->addBinaryNode(temp);

      }

    if (infile.fail()) {
        // set error
        error.badCall("input_error_line_");
        error.which = count;
        return error; // if the file didn't read correctly, no need to continue.
    }
  }

  return error;
}
