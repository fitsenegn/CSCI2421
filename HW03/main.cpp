#include <iostream>
#include "mystring.h"
#include "kaest_functions.h"


using std::endl;
using std::cin;
using std::cout;


int main(){
exception_status check;
my_string test;
std::string file;

bool m_exit = false;
while(m_exit == false){
  char selection;
  std::cout << "Select a file to reformat.\n"
            << "1) Custom File \n"
            << "2) Default File (sample.txt)\n    > ";
    cin >> selection;

    switch(selection){
      case '1': cout << "\nEnter the name of the file to be reformated.\n    > ";
        cin.ignore();
        getline(cin, file);
        cout << "\n    Reformating \"" << file << "\"";
        cout << "\n\n      press [ENTER] to continue     \n\n";
        cin.ignore();
        break;

      case '2': file = "sample.txt";
        break;

      default: cout << "\n\n***invalid input***\n\n";
        break;
    }

    check = readIn(test, file);

    if(check.error == true){
      cout << check.what() << check.which << endl << endl;
    }else{
      m_exit = true;
    }
}

int columnSize = 0;

std::cout << "\nSet column size: ";

while(readInt(0, columnSize, 999999) == -1){
  cout << "\n\n***invalid input***\n\n";
}


my_string* test_split;


test_split = test.split(columnSize);


for(int i = 0; i < test_split->partitions(); i++){
  cout << test_split[i];
  if(test_split[i].length() == columnSize){
    cout << "       ";
  }else{
    cout << "      ";
  }
  cout << test_split[i].length() << endl;
}



readOut(test_split);

cout << "\n\n***   Wrote out reformatted text to \"data.out\"   ***\n\n";


  return 0;
}
