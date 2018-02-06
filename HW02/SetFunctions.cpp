#include "SetFunctions.h"


exception_status SetFunctions::readIn(ArrayBag& a, ArrayBag& b){
  exception_status exception; //catch exception

  int count = 0;
  std::vector<int> numberSet;

  std::ifstream in;

      in.open("setInput.txt");

      ///////////check file/////////
    if (!in.is_open()) {
        // set exception
        exception.badCall("file_invalid::failed_prior_catch");
        return exception; // if the file didn't read, no need to continue.
    }

    while(in.peek() != '\n'){

      count++;
    //////////strips commas and spaces/////////
    if (in.peek() == ' ') { in >> std::ws; }
    if(in.peek() == ','){   in.ignore(' ', ' ');  };

    int temp;

    in >> temp;

    numberSet.push_back(temp);

    if (in.fail()) {
        // set exception
        exception.badCall("invalid_input_line_1");
        exception.which = count;
        return exception; // if the file didn't read, no need to continue.
    }
  }

  a = numberSet;


  count = 0;
  numberSet.clear();
  in >> std::ws;

  while(in.peek() != '\n'){
    count++;
  //////////strips commas and spaces/////////
  if (in.peek() == ' ') { in >> std::ws; }
  if(in.peek() == ','){   in.ignore(' ', ' ');  };

  int temp;

  in >> temp;

  numberSet.push_back(temp);

  if (in.fail()) {
      // set exception
      exception.badCall("invalid_input_line_2");
      exception.which = count;
      return exception; // if the file didn't read, no need to continue.
  }
}

b = numberSet;


      return exception;
}
