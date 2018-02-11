#include "kaest_functions.h"
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




void readOut(my_string* out){
  std::ofstream outfile;
  outfile.open("data.out", std::ios::out);

  for(int i = 0; i < out->partitions(); i++){
    outfile << out[i] << std::endl;
  }
  outfile.close();
}




/*Read in an int within bounds
\@param lowerbound, int& n is user input, upperbound
\@return int| -1 if fail, 0 if success  */
int readInt(int lowerBound, int &n, int upperBound) {
  std::cin >> n;

  if (std::cin.fail()) // check type
  {
    std::cin.clear();//clear buffer
    std::cin.ignore(1024, '\n'); //ignore some large bit size
    std::cout << "*** invalid ***" << '\n';
    return -1;                                       // fail
  } else if ((n < lowerBound) || (upperBound < n)) { // check bounds
    std::cout << "*** out of bounds ***" << '\n';
    return -1; // fail
  }
  return 0; // success!
}
