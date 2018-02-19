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

  // std::string word1 = "So";
  // std::string word2 = "store";
  // node* start = NULL;
  // node* end = NULL;
  //
  // if(list_search(head, word1) != NULL){
  //   if(list_search(head, word2) != NULL){
  //     start = list_search(head, word1);
  //     end = list_search(head, word2);
  //   }
  // }
  //
  // cout << start->data();
  // cout << end->data();



  // list_piece(start, end, head, list_locate(head, list_length(head)));
















  for(int i = 0; i < list_length(head); i++){
    cout << cursor->data() << endl;
    cursor = cursor->link();
  }





  return 0;
}
