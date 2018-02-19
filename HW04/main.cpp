#include <iostream>
#include "node1.h"
#include "kaest_functions.h"


using std::cin;
using std::cout;
using std::endl;



int main(int argc, char* argv[]){
  exception_status exception;
  std::string filename = "";

  if(argc < 2){
    cout << "No file specified. Call with: " << endl;
    cout << "     ./subset [filename]" << endl;
    return 0;
  }else if(argc > 2){
    cout << "Too many arguments. Call with: " << endl;
    cout << "     ./subset [filename]" << endl;
    return 0;
  }else{
    filename = argv[1];
  }

  node* head = new node();
  exception = readIn(head, filename);

  if(exception.error == true){
    cout << exception.what() << exception.which << endl;
    return 0;
  }

  node* cursor = head;

  // cout << cursor->data() << endl;
  //
  // cout << cursor->link()->data();

  for(int i = 0; i < list_length(head); i++){
    cout << cursor->data() << endl;
    cursor = cursor->link();
  }





  return 0;
}
