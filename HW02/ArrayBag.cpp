//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <algorithm>


//-------------------------------------------------------------------


ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if

	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if

	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if

      searchIndex++;
   }  // end while

   return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains



std::vector<ItemType> ArrayBag::toVector() const
{
    std::vector<ItemType> ArrayBagContents;
	for (int i = 0; i < itemCount; i++)
                ArrayBagContents.push_back(items[i]);
   return ArrayBagContents;
}  // end toVector

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      }
      else
      {
         searchIndex++;
      }  // end if
   }  // end while

   return result;
}  // end getIndexOf

/*Fill the bag with a set of numbers by passing a numberset to the "=" operator
	*\@param contents is the setting value
	*\@return contents is returns for sidechain setting */
std::vector<ItemType> ArrayBag::operator=(std::vector<ItemType> contents){
	for(int i = 0; i < contents.size(); i++){
    this->add(contents[i]);
  }

	return contents;
}


/* Create Union set of numbers and return left
*\@param other is the right-most bag */
std::vector<ItemType> ArrayBag::operator+(ArrayBag& other){
	std::vector<ItemType> bagA = this->toVector();
	std::vector<ItemType> bagB = other.toVector();
	std::vector<ItemType> unionContents;

	for( int i = 0; i < bagA.size(); i ++){ //shove in bagA
			unionContents.push_back(bagA[i]);
	}

	for( int i = 0; i < bagB.size(); i ++){ //shove in bagB
			unionContents.push_back(bagB[i]);
	}

	std::sort(unionContents.begin(), unionContents.end());

	//remove duplicates
	for(int i = 0; i < unionContents.size()-1; i++){
		if(unionContents[i] == unionContents[1+i]){
			unionContents.erase(unionContents.begin()+i);
			i--;
		}

	}

	std::sort(unionContents.begin(), unionContents.end());

	return unionContents;
}

/* Create difference set of numbers and return left
*\@param other is the right-most bag */
std::vector<ItemType> ArrayBag::operator-(ArrayBag& other){
	std::vector<ItemType> bagB = other.toVector();
	std::vector<ItemType> temp = this->toVector();
 	ArrayBag subtractionBag;


	std::sort(temp.begin(), temp.end());
    std::sort(bagB.begin(), bagB.end());
    
    for(int i = 0; i < temp.size()-1; i++){
        if(temp[i] == temp[1+i]){
            temp.erase(temp.begin()+i);
            i--;
        }
        
    }
    
	for(int i = 0; i < temp.size(); i++){ //instantiate temporary bag
    subtractionBag.add(temp[i]);
  }

	int i = 0;

	while(i < bagB.size()){ //before end
		if(subtractionBag.contains(bagB[i])){
			subtractionBag.remove(bagB[i]);
		}
        i++;
	}

	temp.clear(); temp = subtractionBag.toVector();
	//remove duplicates
	for(int i = 0; i < temp.size()-1; i++){
		if(temp[i] == temp[1+i]){
			temp.erase(temp.begin()+i);
			i--;
		}

	}

	std::sort(temp.begin(), temp.end());

	return temp;
}




std::ostream &operator<<(std::ostream &out, ArrayBag &bag){
	std::vector<ItemType> contents = bag.toVector();
	std::stringstream outstream;
	outstream << "{ ";
	for(int i = 0; i < contents.size(); i++){
		outstream <<  contents[i] << " ";
	}
	outstream << "}";

	out << outstream.str();

	return out;
}
