#include "BinaryNodeTree.h"
#include <cstddef>
#include <memory>
// Constructors


template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
    :rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
                            :rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                                                            copyTree(leftTreePtr->rootPtr),
                                                                            copyTree(rightTreePtr->rootPtr)))
{
}

// copyTree
template<class ItemType>
std::shared_ptr::<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::copyTree(
                    const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
  std::shared_ptr::<BinaryNode<ItemType>> newTreePtr;
// Copy tree nodes during a preorder traversal
  if (oldTreeRootPtr != nullptr)
    {
// Copy node
      newTreePtr = std::_make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(),
                                                           nullptr,
                                                           nullptr);

      newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
      newTreePtr->setRightChildPtr (copyTree (oldTreeRootPtr->getRightChildPtr()));
    }	// end if
// Else tree is empty (newTreePtr is nullptr)
  return newTreePtr;
}   // end copyTree


// Copy Constructor
template<class ItemType>
BinaryNodeTree < ItemType >::
                     BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
  rootPtr = copyTree(treePtr.rootPtr);
}   // end copy constructor


// destroyTree
template<class ItemType>
void BinaryNodeTree<ItemType>::
     destroyTree(std::shared_ptr<<BinaryNode<ItemType>> subTreePtr)
{
  if (subTreePtr != nullptr)
    {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      subTreePtr.reset();
      // delete subTreePtr;
    }	// end if
}   // end destroyTree

// getHeight
template<class ItemType>
int BinaryNodeTree<ItemType>::
    getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
  if (subTreePtr == nullptr)
    return 0;
  else
    return 1 + max (getHeightHelper(subTreePtr->getLeftChildPtr()),
                    getHeightHelper (subTreePtr->getRightChildPtr()));
}   // end getHeightHelper


// add
template<class ItemType>
bool BinaryNodeTree<ItemType>::
     add(const ItemType& newData)
{
  auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
  rootPtr = balancedAdd(rootPtr, newNodePtr);
  return true;
}   // end add


//  balanceAdd
template<class ItemType>
auto BinaryNodeTree<ItemType>::
     balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
							   std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
  if (subTreePtr == nullptr)
    return newNodePtr;
  else
    {
      auto leftPtr = subTreePtr->getLeftChildPtr();
      auto rightPtr = subTreePtr->getRightChildPtr();

      if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
    	{
    	  rightPtr = balancedAdd(rightPtr, newNodePtr);
    	  subTreePtr->setRightChildPtr(rightPtr);
    	}
      else
    	{
    	  leftPtr = balancedAdd(leftPtr, newNodePtr);
    	  subTreePtr->setLeftChildPtr(leftPtr);
    	}	// end if
          return subTreePtr;
    }	// end if
}   // end balancedAdd

//  inorder
template<class ItemType>
void BinaryNodeTree<ItemType>::
     inorder(void visit(ItemType &),
						 std::shared_ptr<BinaryNode<ItemType> treePtr) const
{
  if (treePtr != nullptr)
    {
      inorder (visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit (theItem);
      inorder (visit, treePtr->getRightChildPtr());
    }	// end if
}   // end inorder
