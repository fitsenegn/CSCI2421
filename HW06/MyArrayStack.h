#ifndef MY_ARRAY_STACK_
#define MY_ARRAY_STACK_

#include "StackInterface.h"



template<class ItemType>
class MyArrayStack : public StackInterface<ItemType> {

private:
  static const int DEFAULT_CAPACITY = 1000;
  ItemType items[DEFAULT_CAPACITY];
  int top;

public:
  MyArrayStack();
  bool isEmpty() const;
  bool push(const ItemType& newEntry);
  bool pop();
  ItemType peek() const;
};

// Include the implementation in the header so it is accessible to the compiler
// while still being separated for more modular reading.
#include "MyArrayStack.cpp"
#endif
