#ifndef BINARYNODETREE_H_
#define BINARYNODETREE_H_
#include <iostream>
#include <sstream>
using namespace std;
#include "DataNodes.h"
#include <iomanip>
#include <vector>



/** @subsection outType
@details Used as commands to determine whether outputting to file or to screen*/
enum outType{consoleFormat,fileFormat};

/**@class*/
/** BinaryNodeTree does the brunt of the labor for this program*/
template <typename itemType, typename KEY>
class BinaryNodeTree {
private:
    BinaryNode<itemType,KEY> * root;
    void addBinaryNode(BinaryNode<itemType,KEY> * leaf, itemType& item,KEY key);
    BinaryNode<itemType,KEY> * deleteBinaryNode(BinaryNode<itemType,KEY> * BinaryNode, KEY key);
    void freeBinaryNode(BinaryNode<itemType,KEY> * leaf);
	  void printInorder(BinaryNode<itemType,KEY> * BinaryNode,ostream &,outType);
    BinaryNode<itemType,KEY> * findBinaryNode(KEY key, BinaryNode<itemType,KEY> * BinaryNode);
    BinaryNode<itemType,KEY> * findBinaryNodePartial(KEY key, BinaryNode<itemType,KEY> * BinaryNode);
    void findAllBinaryNode(KEY key, BinaryNode<itemType,KEY>*, std::vector<itemType>&);
    void findAllBinaryNodePartial(KEY key, BinaryNode<itemType,KEY>*, std::vector<itemType>&);
    void getVector(BinaryNode<itemType,KEY>*, std::vector<itemType>&);
  // void debugPrint(BinaryNode<itemType> *, int);
    int getHeightHelper(BinaryNode<itemType,KEY>* );
  // void storeNodes(BinaryNode<itemType>*, int,vector<itemType>&);

public:
    void clear();
    BinaryNodeTree<itemType,KEY> duplicate();
    BinaryNodeTree<itemType,KEY>();
    ~BinaryNodeTree<itemType,KEY>();
    BinaryNode<itemType,KEY> * Root() { return root; }
    void setRoot(BinaryNode<itemType,KEY> * _root) {root = _root;}
    void addBinaryNode(KEY key, itemType &item);
    BinaryNode<itemType,KEY> * findItem(KEY key);
    BinaryNode<itemType,KEY> * findItemPartial(KEY key);
    std::vector<itemType> findAllMatches(KEY key);
    std::vector<itemType> findAllMatchesPartial(KEY key);
    std::vector<itemType> getVector();
  	void printInorder(outType,ostream&);
  	void print(outType, ostream & out, const itemType & item);
    void deleteBinaryNode(KEY);
  	BinaryNode<itemType,KEY> * min(BinaryNode<itemType,KEY> * BinaryNode);
  	BinaryNode<itemType,KEY> * max(BinaryNode<itemType,KEY> * BinaryNode);
    bool replace(itemType item, itemType replacementItem); //THIS IS THE ASSIGNMENT FUNCTION XXX
  // void coolView(int);

};
#include "BinaryNodeTree.hpp"
#endif  //BST
