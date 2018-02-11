#include "kaest_functions.h"
#include <sstream>
#include <iostream>

exception_status readIn(my_string& in, std::string file){
  exception_status exception; //catch exception

  int count = 0;

  std::ifstream reformat_file;

      reformat_file.open(file);

      ///////////check file/////////
    if (!reformat_file.is_open()) {
        // set exception
        exception.badCall("file_invalid");
        return exception; // if the file didn't read, no need to continue.
    }




  count = 0;
  reformat_file >> std::ws;

  while(!reformat_file.eof()){
    count++;


      reformat_file >> std::ws;

      my_string temp;
      getline(reformat_file, temp); //read in a line up to '\n'
      in += temp;

      if(reformat_file.peek() == '\n'){ //if theres a break, insert space
          in += " ";
      }

  if (reformat_file.fail()) {
      // set exception
      exception.badCall("input_error_line_");
      exception.which = count;
      return exception; // if the file didn't read correctly, no need to continue.
  }
}


      return exception;
}
