#include "searchData.h"


/**This function will traverse the BST in order using a stack.
  *\param tree to be traversed
  *\return a list that can be executed on of pointers to the BST */
template<class itemtype>
int stackTraversal(BinaryNodeTree<itemtype> root){
  MyArrayStack<itemtype> stack;
  BinaryNodeTree<itemtype> current = root;

  bool mExit = false;
  while(mExit == false)
    while(current != nullptr){
      stack.push(root);
      current = current.getLeftChildPtr();

      }



  return 0;
}
