#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
#include <sstream>
using namespace std;
#include "DataNodes.h"
#include <iomanip>
#include <vector>

// Binary Search Tree class
template <class itemType>
class BinaryNodeTree {
private:
    BinaryNode<itemType> * root;
    void addBinaryNode(BinaryNode<itemType> * leaf, itemType& item);
    BinaryNode<itemType> * deleteBinaryNode(BinaryNode<itemType> * BinaryNode, itemType);
    void freeBinaryNode(BinaryNode<itemType> * leaf);
	void printInorder(BinaryNode<itemType> * BinaryNode);
	BinaryNode<itemType> * findBinaryNode(itemType, BinaryNode<itemType> * BinaryNode);
  // void debugPrint(BinaryNode<itemType> *, int);
  int getHeightHelper(BinaryNode<itemType>* );
  // void storeNodes(BinaryNode<itemType>*, int,vector<itemType>&);

public:
    BinaryNodeTree<itemType>();
    virtual ~BinaryNodeTree<itemType>();
    BinaryNode<itemType> * Root() { return root; }
    void setRoot(BinaryNode<itemType> * _root) {root = _root;}
    void addBinaryNode(itemType &item);
	BinaryNode<itemType> * findItem(itemType newthinger);
	void printInorder();
	void print(ostream & out, const itemType & item);
    void deleteBinaryNode(itemType badthinger);
	BinaryNode<itemType> * min(BinaryNode<itemType> * BinaryNode);
	BinaryNode<itemType> * max(BinaryNode<itemType> * BinaryNode);
  bool replace(itemType item, itemType replacementItem); //THIS IS THE ASSIGNMENT FUNCTION XXX
  // void coolView(int);

};
#include "BinaryNodeTree.hpp"
#endif  //BST
