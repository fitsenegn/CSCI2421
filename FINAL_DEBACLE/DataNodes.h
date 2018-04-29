#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <string>

struct Full_Name
{
  std::string First;
  std::string Last;
};
struct Actor_Actress //Year,Award,Winner,Name,Film
{
    int Year;
	  std::string Award; //maybe Enum?
    int Winner; // 0 means they lost 1 means they won
    Full_Name Name;
    std::string Film;
};

struct Picture{ //name,year,nominations,rating,duration,
                //genre1,genre2,release,metacritic,synopsis
  std::string Name;
  int Year;
  int Nominations;
  double Rating;
  int Duration;
  std::string Genre1;
  std::string Genre2;
  std::string Release;
  int Metacritic;
  std::string Synopsis;
};

struct GeneralData
{
    int number; //Update this to your data field
	  std::string name;
};

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
