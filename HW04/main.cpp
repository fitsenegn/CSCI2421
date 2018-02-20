#include <iostream>
#include "node1.h"
#include "kaest_functions.h"


using std::cin;
using std::cout;
using std::endl;



int main(int argc, char* argv[]){
  exception_status exception; //used to check input status
  std::string filename = "";

//------Only take one commandline argument in the specified form--------

  if(argc < 2){
    cout << "No file specified. Call with: " << endl;
    cout << "     ./subset [filename]" << endl;
    return 0;
  }else if(argc > 2){
    cout << "Too many arguments. Call with: " << endl;
    cout << "     ./subset [filename]" << endl;
    return 0;

  }else{ //if currect, this is the file we are opening

    filename = argv[1];
  }

//----------------------------------------------------------------------

  node* head = new node(); //this is the main list

  exception = readIn(head, filename);

  if(exception.error == true){ //check error and report to user
    cout << exception.what() << exception.which << endl;
    return 0;
  }


  node* cursor = head; //cursor will be used to manipulate the list


  std::string word1 = "So";
  std::string word2 = "node";
  node* start = NULL;
  node* end = NULL;
  bool m_exit = false;



  while(m_exit == false){ //as long as the specified words aren't in list

      //---------------Get sublist specifiers---
  cout << "\n\nSetting the sublist . . . \n";
  cout << "   First word: ";
  cin >> word1;
  cout << "   Second word: ";
  cin >> word2;

     //-------------Search and set

    if(list_search(head, word1) != NULL){ //exists in set
      start = list_search(head, word1); //set
      m_exit = true; //first was set
    }else{
      m_exit = false; //fail
    }

    if(list_search(head, word2) != NULL){ //if it exists, coolio.

      if(m_exit == true){
        end = list_search(start, word2); //search for end word after first word

        if(end != NULL){ //if it still exists coolio
            m_exit = true;
          }else{
            m_exit = false; //fail
          }

      }

    }else{
      m_exit = false; //fail
    }

    if(m_exit == true){ //if success leave
      break;
    }else{ //else request input again
        cout << "\nUnable to find specified words.\n";
    }

}


node* partial_head = new node();
node* partial_tail = partial_head;

if(list_bounds(head, start, end) == false){
    list_piece(start, end, partial_head, partial_tail);
}else{
  cout << "First word must come before the last word.\n";
}


cursor = partial_head;


  for(int i = 0; i < list_length(head); i++){
    if(cursor->link() != NULL){
      cout << cursor->data() << endl;
      cursor = cursor->link();
    }

  }


  list_sort(partial_head, partial_tail);

  cursor = partial_head;

  for(int i = 0; i < list_length(head); i++){
    if(cursor->link() != NULL){
      cout << cursor->data() << endl;
      cursor = cursor->link();
    }
    cursor = cursor->link();

  }

  return 0;
}
