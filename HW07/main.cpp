#include <iostream>
#include "BinaryNodeTree.h"
#include "housekeeping.h"

using std::endl;
using std::cin;
using std::cout;


int main(int argc, char* argv[]){
	BinaryNodeTree<std::string> *tree = new BinaryNodeTree<std::string>;

	std::string filename = "";

	//------Only take one commandline argument in the specified form--------

	  if(argc < 2){
	    cout << "No file specified. Using default file \"text.txt\": " << endl;
			filename = "text.txt";
	  }else if(argc > 2){
	    cout << "Too many arguments. Call with: " << endl;
	    cout << "     ./binaryTree [filename]" << endl;
	    return 0;

	  }else{ //if currect, this is the file we are opening

	    filename = argv[1];
	  }


	cout << "Reading in words. . . \n\n";

  exception_status exception = readIn(filename, tree);

	if(exception.error == true){ //check error and report to user
		cout << exception.what() << exception.which << endl;
		return 0;
	}

	std::string searchTerm;

	//Get a term to search and find if it exists. If not, bail.
	while(getSearchTerm(searchTerm, "Enter the search term: \n") == -1){ };

	cout << "\nSearching for \"" << searchTerm << "\". . . \n";
	if(tree->findItem(searchTerm) != nullptr){
		cout << "Found the word in the tree.\n\n" << endl;
	}else{
		cout << "The word does not exist in the tree.\n\n" << endl;
		return 0;
	}

	//Get a term to replace searchTerm with then repeat.
	std::string replacementTerm;
	while(getSearchTerm(replacementTerm,
										 "Enter a word to replace \"" + searchTerm + "\": \n") == -1){ };

	cout << "\nReplacing \"" << searchTerm << "\" with \""<< replacementTerm << "\". . . \n\n";
  tree->replace(searchTerm, replacementTerm);


	cout << "Searching for \"" << searchTerm << "\" again. . . \n";

  if(tree->findItem(searchTerm) != nullptr){
	  cout << "Found the word in the tree.\n\n" << endl;
  }else{
	  cout << "The word does not exist in the tree.\n\n" << endl;
  }

	// tree->printInorder();

return 0;
}
