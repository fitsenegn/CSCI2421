#include "BinaryNodeTree.h"

// Constructor
template <class itemType>
BinaryNodeTree<itemType>::BinaryNodeTree() {
  root = nullptr;
}

// Destructor
template <class itemType>
BinaryNodeTree<itemType>::~BinaryNodeTree() {
  if (root != nullptr)
    freeBinaryNode(root);
}

// Free the node
template <class itemType>
void BinaryNodeTree<itemType>::freeBinaryNode(BinaryNode<itemType> *leaf) {
  // Student must fill in
  if (this->Root() == leaf) { // if the root is the leaf, delete that leaf
    delete leaf;
  } else if (leaf != nullptr) { // otherwise if the leaf is not null
    freeBinaryNode(leaf->getLeftChildPtr());     // recursive call of the leaf's left
    freeBinaryNode(leaf->getRightChildPtr());    // recursive call of the leaf's right
    delete leaf;                // now delete the leaf
  }
}

// Add a node
template <class itemType>
void BinaryNodeTree<itemType>::addBinaryNode(itemType& item) {
  if (Root() == nullptr) {
    BinaryNode<itemType> *newNodePtr = new BinaryNode<itemType>;
    newNodePtr->setItem(item);
    root = newNodePtr;
    root->setParentPtr(root);

  } else
    addBinaryNode(root, item);
}

// Add a node (private)
template <class itemType>
void BinaryNodeTree<itemType>::addBinaryNode(BinaryNode<itemType> *leaf,
                                        itemType &item) {

  if (this->Root() == nullptr) { // First check if root is null
    BinaryNode<itemType> *newNodePtr =
        new BinaryNode<itemType>; // make a new node
    newNodePtr->setItem(item);       // set the item
    root = newNodePtr;               // set the root
  } else {

    if (item < leaf->getItem()) { // Check to see if the value is < the leaf's value

      if (leaf->getLeftChildPtr() != nullptr) { // if left is not null then
        addBinaryNode(leaf->getLeftChildPtr(), item); // Add the node to the left (recursively)
      } else {         // Otherwise make a new node and attach it to the left
        BinaryNode<itemType> *newNodePtr = new BinaryNode<itemType>;
        newNodePtr->setItem(item);
        newNodePtr->setParentPtr(leaf);
        leaf->setLeftChildPtr(newNodePtr);
      }
    }
    // Otherwise

    if (item >= leaf->getItem()) { // Check to see if the value >= leaf's value

      if (leaf->getRightChildPtr() != nullptr) { // if leaf's right is not null then
        addBinaryNode(leaf->getRightChildPtr(),
                item); // Add the node to the right (recursively)
      } else {         // Otherwise make new node and attach it to the right
        BinaryNode<itemType> *newNodePtr = new BinaryNode<itemType>;
        newNodePtr->setItem(item);
        newNodePtr->setParentPtr(leaf);
        leaf->setRightChildPtr(newNodePtr);
      }
    }
  }
}

template <class itemType>
BinaryNode<itemType> *BinaryNodeTree<itemType>::findItem(itemType searchable) {
  return findBinaryNode(searchable, root);
}

// Find a node
template <class itemType>
BinaryNode<itemType> *
BinaryNodeTree<itemType>::findBinaryNode(itemType target, BinaryNode<itemType> *node) {
  if((node == nullptr) || (target == node->getItem())){
		return node;
	} else {

    if (target < node->getItem()) {
      return findBinaryNode(target, node->getLeftChildPtr());
    }else if (target > node->getItem()) {
      return findBinaryNode(target, node->getRightChildPtr());
    } else {
      return nullptr; // not found
    }
  }
}

template <class itemType>
void BinaryNodeTree<itemType>::printInorder() {
  printInorder(root);
}

template <class itemType>
void BinaryNodeTree<itemType>::printInorder(BinaryNode<itemType> *node) {

  // first, make sure the root node is not null
  if (node != nullptr) {
    printInorder(node->getLeftChildPtr());  // go to the left
    print(cout, node->getItem());  // visit the root node
    printInorder(node->getRightChildPtr()); // go to the right
  }
}

template <class itemType>
void BinaryNodeTree<itemType>::print(ostream &out, const itemType &item) {
  out << item.print() << endl << endl;
}

template <class itemType>
void BinaryNodeTree<itemType>::deleteBinaryNode(itemType toRemove) {
  setRoot(deleteBinaryNode(Root(), toRemove));
}

// deleteNode (Private)
template <class itemType>
BinaryNode<itemType> *
BinaryNodeTree<itemType>::deleteBinaryNode(BinaryNode<itemType> *aRoot, itemType value) {

  // base case
  if (aRoot == nullptr)
    return aRoot;

  // If the value to be deleted is smaller than the aRoot's value,
  // then it lies in left subtree
  if (value < aRoot->getItem())
    aRoot->setLeftChildPtr(deleteBinaryNode(aRoot->getLeftChildPtr(), value));

  // If the value to be deleted is greater than the root's value,
  // then it lies in right subtree
  else if (value > aRoot->getItem())
    root->setRightChildPtr(deleteBinaryNode(aRoot->getRightChildPtr(), value));

  // if value is same as root's value, then This is the node
  // to be deleted
  else {
    // node with only one child or no child
    if (aRoot->getLeftChildPtr() == nullptr) {
      BinaryNode<itemType> *temp = aRoot->getRightChildPtr();
      delete aRoot;
      return temp;
    } else if (aRoot->getRightChildPtr() == nullptr) {
      BinaryNode<itemType> *temp = aRoot->getLeftChildPtr();
      delete aRoot;
      return temp;
    }

    // node with two children: Get the inorder successor (smallest
    // in the right subtree)
    BinaryNode<itemType> *temp = min(aRoot->getRightChildPtr());

    // Copy the inorder successor's content to this node
    aRoot->setItem(temp->getItem());

    // Delete the inorder successor
    aRoot->setRightChildPtr(deleteBinaryNode(aRoot->getRightChildPtr(), temp->getItem()));
  }
  return aRoot;
}

// Find the node with min value
// Traverse the left sub-BinaryNodeTree recursively
// till left sub-BinaryNodeTree is empty to get min
template <class itemType>
BinaryNode<itemType> *
BinaryNodeTree<itemType>::min(BinaryNode<itemType> *node) {
  BinaryNode<itemType> *current = node;

  /* loop down to find the leftmost leaf */
  while (current->getLeftChildPtr() != nullptr)
    current = current->getLeftChildPtr();

  return current;
}

// Find the node with max value
// Traverse the right sub-BinaryNodeTree recursively
// till right sub-BinaryNodeTree is empty to get max
template <class itemType>
BinaryNode<itemType> *
BinaryNodeTree<itemType>::max(BinaryNode<itemType> *node) {
  BinaryNode<itemType> *tempNode = node;
  if (node == nullptr)
    tempNode = nullptr;
  else if (node->getRightChildPtr())
    tempNode = max(node->getRightChildPtr());
  else
    tempNode = node;

  return tempNode;
}



template<class itemType>
int BinaryNodeTree<itemType>::
    getHeightHelper(BinaryNode<itemType>* subTreePtr)
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper


template<class itemType>
bool BinaryNodeTree<itemType>::replace(itemType item, itemType replacementItem){
  BinaryNode<itemType>* nodeToReplace = findBinaryNode(item, root);
  if(nodeToReplace == nullptr){
    return false;
  }else{
  nodeToReplace->setItem(replacementItem);
    return true;
  }

}


// template<class itemType>
// std::string BinaryNodeTree<itemType>::debugPrint(){
//  std::string thisTree = "";
//
//  return debugPrint(root, thisTree);
// }
//
// template <class itemType>
// std::string BinaryNodeTree<itemType>::debugPrint(BinaryNode<itemType> * node, std::string &check){
//
// BinaryNode<itemType> * trackr = node;
//
//   // bases case
//   if (node == nullptr){
//       return check;
//   }
//
//   // push the root data as character
//   check+=node->getItem();
//
//   // for left subtree
//
//   check.push_back('{');
//   debugPrint(trackr->getLeftChildPtr(), check);
//   check.push_back('}');
//
//   // avoid extra parenthesis
//   if (trackr->getRightChildPtr()) {
//       check.push_back('{');
//       debugPrint(trackr->getRightChildPtr(), check);
//       check.push_back('}');
//   }
//
//   return check;
// }

// template<class itemType>
// void BinaryNodeTree<itemType>::coolView(){
//   int height = getHeightHelper(this->root) * 2;
// for (int i = 0 ; i < height; i ++) {
//    debugPrint(this->root, height, i);
// }
// }
//
// template<class itemType>
// void BinaryNodeTree<itemType>::debugPrint(BinaryNode<itemType> *cursor, int height ,int depth){
//   vector<itemType> vec;
//   getLine(cursor, depth, vec);
//   cout << setw((height - depth)*2); // scale setw with depth
//   bool toggle = true; // start with left
//   if (vec.size() > 1) {
//           for (int v : vec) {
//                   if (v != cursor->getItem()) {
//                           if (toggle)
//                                   cout << "/" << "   ";
//                           else
//                                   cout << "\\" << "   ";
//                   }
//                   toggle = !toggle;
//           }
//           cout << endl;
//           cout << setw((height - depth)*2);
//   }
//   for (int v : vec) {
//           if (v != cursor->getItem())
//                   cout << v << "   ";
//   }
//   cout << endl;
// }
//
// template<class itemType>
// void BinaryNodeTree<itemType>::storeNodes(BinaryNode<itemType> *cursor, int depth ,vector<itemType>& row){
//   if (depth <= 0 && root != nullptr) {
//         row.push_back(root->getItem());
//         return;
// }
// if (root->left != nullptr)
//         getLine(root->getLeftChildPtr(), depth-1, row);
// else if (depth-1 <= 0)
//         row.push_back(cursor->getItem());
// if (root->right != nullptr)
//         getLine(root->getRightChildPtr(), depth-1, row);
// else if (depth-1 <= 0)
//         row.push_back(cursor->getItem());
// }
