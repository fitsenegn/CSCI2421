// #include "BinaryNodeTree.h"

// Constructor
template <typename itemType, typename KEY>
BinaryNodeTree<itemType,KEY>::BinaryNodeTree() {
  root = nullptr;
}

// Destructor
template <typename itemType, typename KEY>
BinaryNodeTree<itemType,KEY>::~BinaryNodeTree() {
  if (root != nullptr)
    freeBinaryNode(root);
}

/**Delete the whole tree*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::clear(){
  this->freeBinaryNode(this->Root());
}

/** Free a node and all of its respective children*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::freeBinaryNode(BinaryNode<itemType,KEY> *leaf) {
  // Student must fill in
  if (this->Root() == leaf) { // if the root is the leaf, delete that leaf
    delete leaf;
  } else if (leaf != nullptr) { // otherwise if the leaf is not null
    freeBinaryNode(leaf->getLeftChildPtr());     // recursive call of the leaf's left
    freeBinaryNode(leaf->getRightChildPtr());    // recursive call of the leaf's right
    delete leaf;                // now delete the leaf
  }
}

/**The public access add function*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::addBinaryNode(KEY key, itemType& item) {
  if (Root() == nullptr) {
    BinaryNode<itemType,KEY> *newNodePtr = new BinaryNode<itemType,KEY>;
    newNodePtr->setItem(item);
    newNodePtr->setKey(key);
    root = newNodePtr;
    root->setParentPtr(root);

  } else
    addBinaryNode(root, item, key);
}

/**The add helper*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::addBinaryNode(BinaryNode<itemType,KEY> *leaf,
                                        itemType &item, KEY key) {

  if (this->Root() == nullptr) { // First check if root is null
    BinaryNode<itemType,KEY> *newNodePtr =
        new BinaryNode<itemType,KEY>; // make a new node
    newNodePtr->setItem(item);       // set the item
    newNodePtr->setKey(key);
    root = newNodePtr;               // set the root
  } else {

    if (key < leaf->getKey()) { // Check to see if the value is < the leaf's value

      if (leaf->getLeftChildPtr() != nullptr) { // if left is not null then
        addBinaryNode(leaf->getLeftChildPtr(), item, key); // Add the node to the left (recursively)
      } else {         // Otherwise make a new node and attach it to the left
        BinaryNode<itemType,KEY> *newNodePtr = new BinaryNode<itemType,KEY>;
        newNodePtr->setItem(item);
        newNodePtr->setKey(key);
        newNodePtr->setParentPtr(leaf);
        leaf->setLeftChildPtr(newNodePtr);
      }
    }
    // Otherwise

    if (key >= leaf->getKey()) { // Check to see if the value >= leaf's value

      if (leaf->getRightChildPtr() != nullptr) { // if leaf's right is not null then
        addBinaryNode(leaf->getRightChildPtr(),
                item, key); // Add the node to the right (recursively)
      } else {         // Otherwise make new node and attach it to the right
        BinaryNode<itemType,KEY> *newNodePtr = new BinaryNode<itemType,KEY>;
        newNodePtr->setItem(item);
        newNodePtr->setKey(key);
        newNodePtr->setParentPtr(leaf);
        leaf->setRightChildPtr(newNodePtr);
      }
    }
  }
}

/**The basic find. This will find the first matching key and return it*/
template <typename itemType, typename KEY>
BinaryNode<itemType,KEY> *BinaryNodeTree<itemType,KEY>::findItem(KEY key) {
  return findBinaryNode(key, root);
}

/**The Helper function for findItem(KEY key)*/
template <typename itemType, typename KEY>
BinaryNode<itemType,KEY> *
BinaryNodeTree<itemType,KEY>::findBinaryNode(KEY target, BinaryNode<itemType,KEY> *node) {
  if((node == nullptr) || (target == node->getKey())){
		return node;
	} else {

    if (target < node->getKey()) {
      return findBinaryNode(target, node->getLeftChildPtr());
    }else if (target > node->getKey()) {
      return findBinaryNode(target, node->getRightChildPtr());
    } else {
      return nullptr; // not found
    }
  }
}


/** These following prints serve the function of printing to screen and to file
  * When called, they are passed both the ostream and the type of output.
  * Console output is formatted for the screen
  * file output is formatted for the file. i.e. A csv format
  \param type is an enum switch type designed to be a command
  \param out is the printed out content.*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::printInorder(outType type, ostream &out) {
  printInorder(root,out, type);
}
/**refer to the detailed print in order*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::printInorder(BinaryNode<itemType,KEY> *node,ostream &out,outType type) {

  // first, make sure the root node is not null
  if (node != nullptr) {
    printInorder(node->getLeftChildPtr(), out, type);  // go to the left
    print(type, out, node->getItem());  // visit the root node
    printInorder(node->getRightChildPtr(), out, type); //m go to the right
  }
}
/**refer to the detailed print in order*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::print(outType type, ostream &out, const itemType &item) {
  if(type == consoleFormat){
    out << item.print() << endl << endl;
  }else if(type == fileFormat){
    out << item.printToFile() << endl;
  }

}
/**The basic deleteBinaryNode public function*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::deleteBinaryNode(KEY toRemove) {
  setRoot(deleteBinaryNode(Root(), toRemove));
}

/// deleteNode (Private)
template <typename itemType, typename KEY>
BinaryNode<itemType,KEY> *
BinaryNodeTree<itemType,KEY>::deleteBinaryNode(BinaryNode<itemType,KEY> *aRoot, KEY value) {

 /** Given a binary search tree and a key, this function deletes the key
 and returns the new root */

 // base case
 if (aRoot == nullptr) return aRoot;

 // If the key to be deleted is smaller than the aRoot's key,
 // then it lies in left subtree
 if (value < aRoot->getKey())
   aRoot->setLeftChildPtr(deleteBinaryNode(aRoot->getLeftChildPtr(), value));

 // If the key to be deleted is greater than the root's key,
 // then it lies in right subtree
 else if (value > aRoot->getKey())
   root->setRightChildPtr(deleteBinaryNode(aRoot->getRightChildPtr(), value));

 // if key is same as root's key, then This is the node
 // to be deleted
 else
 {
   // node with only one child or no child
   if (aRoot->getLeftChildPtr() == nullptr)
   {
     BinaryNode<itemType,KEY> *temp = aRoot->getRightChildPtr();
     delete aRoot;
     return temp;
   }
   else if (aRoot->getRightChildPtr() == nullptr)
   {
    BinaryNode<itemType,KEY> *temp = aRoot->getLeftChildPtr();
     delete aRoot;
     return temp;
   }

   // node with two children: Get the inorder successor (smallest
   // in the right subtree)
   BinaryNode<itemType,KEY> * temp = min(aRoot->getRightChildPtr());

   // Copy the inorder successor's content to this node
   aRoot->setKey(temp->getKey());
   aRoot->setItem(temp->getItem());

   // Delete the inorder successor
   aRoot->setRightChildPtr(deleteBinaryNode(aRoot->getRightChildPtr(), temp->getKey()));
 }
 return aRoot;
}

/** Find the node with min value
    Traverse the left sub-BinaryNodeTree recursively
    till left sub-BinaryNodeTree is empty to get min */
template <typename itemType, typename KEY>
BinaryNode<itemType,KEY> *
BinaryNodeTree<itemType,KEY>::min(BinaryNode<itemType,KEY> *node) {
  BinaryNode<itemType,KEY> *current = node;

  /* loop down to find the leftmost leaf */
  while (current->getLeftChildPtr() != nullptr)
    current = current->getLeftChildPtr();

  return current;
}

/** Find the node with max value
    Traverse the right sub-BinaryNodeTree recursively
    till right sub-BinaryNodeTree is empty to get max */
template <typename itemType, typename KEY>
BinaryNode<itemType,KEY> *
BinaryNodeTree<itemType,KEY>::max(BinaryNode<itemType,KEY> *node) {
  BinaryNode<itemType,KEY> *tempNode = node;
  if (node == nullptr)
    tempNode = nullptr;
  else if (node->getRightChildPtr())
    tempNode = max(node->getRightChildPtr());
  else
    tempNode = node;

  return tempNode;
}


/**Returns how tall the tree is. Used for debug print but not currently implemented*/
template <typename itemType, typename KEY>
int BinaryNodeTree<itemType,KEY>::
    getHeightHelper(BinaryNode<itemType,KEY>* subTreePtr)
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper


/**Unused however this function replaces one item with another*/
template <typename itemType, typename KEY>
bool BinaryNodeTree<itemType,KEY>::replace(itemType item, itemType replacementItem){
  BinaryNode<itemType,KEY>* nodeToReplace = findBinaryNode(item, root);
  if(nodeToReplace == nullptr){
    return false;
  }else{
  nodeToReplace->setItem(replacementItem);
    return true;
  }

}
/**This function finds every single matching item and returns a list of them*/
template <typename itemType, typename KEY>
std::vector<itemType> BinaryNodeTree<itemType,KEY>::findAllMatches(KEY searchable) {
  std::vector<itemType> collectionList;
  findAllBinaryNode(searchable, root, collectionList);
  return collectionList;
}

/**The helper function for findAllMatches(KEY)*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::findAllBinaryNode(KEY target, BinaryNode<itemType,KEY> *node, std::vector<itemType>& list) {
    if (node != nullptr) {
        if(target == node->getKey()){
          list.push_back(node->getItem());
        }
        // if (target < node->getItem()) {
          findAllBinaryNode(target, node->getLeftChildPtr(), list);
        // }else if (target > node->getItem()) {
          findAllBinaryNode(target, node->getRightChildPtr(), list);
        // }
      }
}


/**This function returns a vector containing the complete contents of the tree*/
template <typename itemType, typename KEY>
std::vector<itemType> BinaryNodeTree<itemType,KEY>::getVector() {
  std::vector<itemType> collectionList;
  getVector(root, collectionList);
  return collectionList;
}

/**The Helper Function for getVector();*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::getVector(BinaryNode<itemType,KEY> *node, std::vector<itemType>& list) {
    if (node != nullptr) {
      getVector(node->getLeftChildPtr(), list);
      list.push_back(node->getItem());
      getVector(node->getRightChildPtr(), list);
    }
}




//__________________________________________________PARTIAL SEARCHES_______________

/**Unimplemented*/
template <typename itemType, typename KEY>
BinaryNode<itemType,KEY> *BinaryNodeTree<itemType,KEY>::findItemPartial(KEY key) {
  return findBinaryNodePartial(key, root);
}

/**Unimplemented*/
template <typename itemType, typename KEY>
BinaryNode<itemType,KEY> *
BinaryNodeTree<itemType,KEY>::findBinaryNodePartial(KEY target, BinaryNode<itemType,KEY> *node) {
  std::string current = node->getKey();
  std::string search = target;
  if((node == nullptr) || (current.find(search))){
		return node;
	} else {

    if (target < node->getKey()) {
      return findBinaryNodePartial(target, node->getLeftChildPtr());
    }else if (target > node->getKey()) {
      return findBinaryNodePartial(target, node->getRightChildPtr());
    } else {
      return nullptr; // not found
    }
  }
}
/**Unimplemented*/
template <typename itemType, typename KEY>
std::vector<itemType> BinaryNodeTree<itemType,KEY>::findAllMatchesPartial(KEY searchable) {
  std::vector<itemType> collectionList;
  findAllBinaryNodePartial(searchable, root, collectionList);
  return collectionList;
}

/**Unimplemented*/
template <typename itemType, typename KEY>
void BinaryNodeTree<itemType,KEY>::findAllBinaryNodePartial(KEY target, BinaryNode<itemType,KEY> *node, std::vector<itemType>& list) {
    if (node != nullptr) {
      std::string current = node->getKey();
      std::string search = target;

        if((current.find(search))){
          list.push_back(node->getItem());
        }
        // if (target < node->getItem()) {
          findAllBinaryNodePartial(target, node->getLeftChildPtr(), list);
        // }else if (target > node->getItem()) {
          findAllBinaryNodePartial(target, node->getRightChildPtr(), list);
        // }
      }
}

// template<class itemType>
// std::string BinaryNodeTree<itemType>::debugPrint(){
//  std::string thisTree = "";
//
//  return debugPrint(root, thisTree);
// }
//
// template <typename itemType, typename KEY>
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
