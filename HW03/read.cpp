#include "read.h"
#include <sstream>


exception_status readIn(my_string& in){
  exception_status exception; //catch exception

  int count = 0;

  std::ifstream reformat_file;

      reformat_file.open("sample.txt");

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

      getline(reformat_file, in); //read in a line up to '\n'

      reformat_file.seekg(1);//skip next newline

      if(reformat_file.peek() == '\n'){ //if theres a break, insert flag
          in += "___<br/>____";
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
