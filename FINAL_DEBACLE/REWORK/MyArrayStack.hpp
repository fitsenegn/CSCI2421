#include <cassert>

template<class ItemType>
MyArrayStack<ItemType>::MyArrayStack() : top(-1){   } //constructor

template<class ItemType>
bool MyArrayStack<ItemType>::isEmpty() const {
  return top < 0; //if empty, top = -1 and this expression evaluates to true
}//end isEmpty


template<class ItemType>
bool MyArrayStack<ItemType>::push(const ItemType& newEntry){
  bool success = false; //return false if fail
  if (top < DEFAULT_CAPACITY -1){ //make sure theres room
    top++;
    items[top] = newEntry;
    success = true; //sucess
  }
  return success;
}//end push


template<class ItemType>
bool MyArrayStack<ItemType>::pop(){
  bool success = false; //return false if fail
  if (!isEmpty()){ //dont remove something from nothing. Thats real bad.
    top--; // no need to change this value until we need its memory, just move top
    success = true; //sucess
  }
  return success;
}//end pop

template<class ItemType>
ItemType MyArrayStack<ItemType>::peek() const throw(PrecondViolatedException){
  // assert(!isEmpty()); //crash if accessed bad
  if(isEmpty()){
    throw PrecondViolatedException("peek() called with empty stack");
  }else{
    return items[top];
  }

}//end peek
