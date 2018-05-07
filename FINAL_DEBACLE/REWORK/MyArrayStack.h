#ifndef MY_ARRAY_STACK_
#define MY_ARRAY_STACK_

#include "StackInterface.h"
#include "exception.h"



template<class ItemType>
class MyArrayStack : public StackInterface<ItemType> {

private:
  static const int DEFAULT_CAPACITY = 100000;
  ItemType items[DEFAULT_CAPACITY];
  int top;

public:
  MyArrayStack();
  bool isEmpty() const;
  bool push(const ItemType& newEntry);
  bool pop();
  ItemType peek() const throw(PrecondViolatedException);
};

#include "MyArrayStack.hpp"

#endif
