#include "kaest_functions.h"
#include <iostream>

/**Read in text continuously into a string and strip all whitespace leaving
   only spaces.
   *\param in is the string to be read into
   *\param file is the name of the file to be readIn
                                      | std::ifstream needs std::string
   *\return exception tracks if there was an error, what type, and where in the
                                                                          file.*/
exception_status readIn(node* head, std::string file){
  exception_status exception; //catch exception

  int count = 0;

  std::ifstream infile;

      infile.open(file);

      ///////////check file/////////
    if (!infile.is_open() || infile.fail()) {
        // set exception
        exception.badCall("file_invalid");
        return exception; // if the file didn't read, no need to continue.
    }




  count = 0; //what line are we on?
  infile >> std::ws;
  node *cursor = head;
  while(!infile.eof()){
  // while(count < 3){
    count++;

    std::string temp;

    std::getline(infile, temp, ' ');

    std::cout << temp << std::endl;

    list_insert(cursor, temp);

    cursor = cursor->link();

  if (infile.fail()) {
      // set exception
      exception.badCall("input_error_line_");
      exception.which = count;
      return exception; // if the file didn't read correctly, no need to continue.
  }
}


      return exception;
}



// /**read out each element into a newly created file if not existent. Overwrites
//   *\param out is the formatted string to write out*/
// void readOut(my_string* out){
//   std::ofstream outfile;
//   outfile.open("data.out", std::ios::out); //overwrite
//
//   for(int i = 0; i < out->partitions(); i++){
//     outfile << out[i] << std::endl;
//   }
//   outfile.close();
// }
//
//
//
//
// /*Read in an int within bounds
// \@param lowerbound, int& n is user input, upperbound
// \@return int| -1 if fail, 0 if success  */
// int readInt(int lowerBound, int &n, int upperBound) {
//   std::cin >> n;
//
//   if (std::cin.fail()) // check type
//   {
//     std::cin.clear();//clear buffer
//     std::cin.ignore(1024, '\n'); //ignore some large bit size
//     std::cout << "*** invalid ***" << '\n';
//     return -1;                                       // fail
//   } else if ((n < lowerBound) || (upperBound < n)) { // check bounds
//     std::cout << "*** out of bounds ***" << '\n';
//     return -1; // fail
//   }
//   return 0; // success!
// }
