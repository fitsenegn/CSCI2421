#include <iostream>
#include "mystring.h"
#include "kaest_functions.h"


using std::endl;
using std::cin;
using std::cout;


int main(){
exception_status check;
my_string test;
std::string file; //std::ifstream needs std::string to parse filename

bool m_exit = false;
while(m_exit == false){ //run default(data.txt) or custom file through formatting
  char selection;
  std::cout << "Select a file to reformat.\n"
            << "1) Custom File \n"
            << "2) Default File (data.txt)\n    > ";
    cin >> selection;

    switch(selection){
      case '1': cout << "\nEnter the name of the file to be reformated.\n    > ";
        cin.ignore();
        getline(cin, file);
        cout << "\n    Reformating \"" << file << "\"";
        cout << "\n\n      press [ENTER] to continue     \n\n";
        cin.ignore();
        break;

      case '2': file = "data.txt";
        break;

      default: cout << "\n\n***invalid input***\n\n";
        break;
    }

    check = readIn(test, file);

    if(check.error == true){ //if there was an error with file,
                                              //insert user back into menu.
      cout << check.what() << check.which << endl << endl;
    }else{
      m_exit = true;
    }
}

int columnSize = 0;

std::cout << "\nSet column size: ";

while(readInt(0, columnSize, 999999) == -1){ //get a positive column size
                                                //that isn't crazy
  cout << "\n\n***invalid input***\n\n";
}


my_string* test_split; //container for the split string


test_split = test.split(columnSize);


for(int i = 0; i < test_split->partitions(); i++){ //print out the format
  cout << test_split[i];
  if(test_split[i].length() == columnSize){
    cout << "       ";
  }else{
    cout << "      ";
  }
  cout << test_split[i].length() << endl; //include the amount of elements
                                                //in a column for user to see
}



readOut(test_split); //write out

cout << "\n\n***   Wrote out reformatted text to \"data.out\"   ***\n\n";


  return 0;
}
