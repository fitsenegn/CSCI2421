#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <string>
#include "dataContainers.h"


//Binary Tree Node
template <class itemType>
class BinaryNode {
public:
    BinaryNode() {left=nullptr; right=nullptr; parent = nullptr;};

    void setParentPtr(BinaryNode<itemType> * aParent) { parent = aParent; };
    void setRightChildPtr(BinaryNode<itemType> * aRight) { right = aRight; };
    void setLeftChildPtr(BinaryNode<itemType> * aLeft) { left = aLeft; };

    BinaryNode<itemType> * getParentPtr() { return parent; };
    BinaryNode<itemType> * getRightChildPtr() { return right; };
    BinaryNode<itemType> * getLeftChildPtr() { return left; };

	  void setItem(itemType newItem) { item = newItem; }
	  itemType getItem() const { return item; }

private:
    itemType item;
    BinaryNode<itemType> * left;
    BinaryNode<itemType> * right;
    BinaryNode<itemType> * parent;
};

#endif
