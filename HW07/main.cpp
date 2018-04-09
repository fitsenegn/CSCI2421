#include <iostream>
#include "BinaryNodeTree.h"
#include "housekeeping.h"

using std::endl;
using std::cin;
using std::cout;


int main(){

	BinaryNodeTree<std::string> *tree = new BinaryNodeTree<std::string>;

	cout << "Reading in words. . . \n\n";

  readIn("text.txt", tree);

	cout << "Searching for \"better\". . . \n";
	if(tree->findItem("better") != nullptr){
		cout << "Found the word in the tree.\n\n" << endl;
	}else{
		cout << "The word does not exist in the tree.\n\n" << endl;
	}

	cout << "Replacing \"better\" with \"HOLYCRAPTHISWORKS\". . . \n\n";
  tree->replace("better", "HOLYCRAPTHISWORKS");


	cout << "Searching for \"better\" again. . . \n";

  if(tree->findItem("better") != nullptr){
	  cout << "Found the word in the tree.\n\n" << endl;
  }else{
	  cout << "The word does not exist in the tree.\n\n" << endl;
  }

return 0;
}
