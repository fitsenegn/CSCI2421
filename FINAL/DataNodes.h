#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <string>
#include "dataContainers.h"
#include "inputCheckers.h"


/**@class*/
/** BinaryNode is the substructure of BinaryNodeTree*/
template <typename itemType, typename KEY>
class BinaryNode {
public:
    BinaryNode() {left=nullptr; right=nullptr; parent = nullptr;};

    void setParentPtr(BinaryNode<itemType,KEY> * aParent) { parent = aParent; };
    void setRightChildPtr(BinaryNode<itemType,KEY> * aRight) { right = aRight; };
    void setLeftChildPtr(BinaryNode<itemType,KEY> * aLeft) { left = aLeft; };

    BinaryNode<itemType,KEY> * getParentPtr() { return parent; };
    BinaryNode<itemType,KEY> * getRightChildPtr() { return right; };
    BinaryNode<itemType,KEY> * getLeftChildPtr() { return left; };

	  void setItem(itemType newItem) { item = newItem; }
    void setKey(KEY akey) {key = akey;}
	  itemType getItem(){ return item; }
    KEY getKey(){return key;}

private:
    itemType item;
    KEY key;
    BinaryNode<itemType,KEY> * left;
    BinaryNode<itemType,KEY> * right;
    BinaryNode<itemType,KEY> * parent;
};

#endif
