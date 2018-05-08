#include "inputCheckers.h"

std::string stripPunctuation(std::string temp){
for(int i = 0; i < temp.size()+1; i++){ //strip punctuation
  if(ispunct(temp[i])){  //if index is punctuation
    temp.erase(i, i); //remove the current character
  }else{
    temp[i] = tolower(temp[i]); //capitals cause problems with sort
  }
}
return temp;
}

/*Read in an int within bounds
\param 'prompt' is displayed to the user,int& n is user input
\return int| -1 if fail, 0 if success  */
int getInt(int &n, std::string prompt) {
  std::cout << prompt;
  std::cin >> n;

  if (std::cin.fail()) // check type
  {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    std::cout << "*** invalid ***" << '\n';
    return -1;                                       // fail
  }
  return 0; // success!
}

/*Read in a a double within bounds
\param 'prompt' is displayed to the user,int& n is user input
\return int| -1 if fail, 0 if success  */
int getDouble(double &d, std::string prompt) {
  std::string temp;
  std::cout << prompt;
  std::cin.ignore();
  std::getline(std::cin, temp);
  d = std::stod(temp);

  if (std::cin.fail()) // check type
  {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    std::cout << "*** invalid ***" << '\n';
    return -1;                                       // fail
  }
  return 0; // success!
}

/** Screens user input for validity
\param 'prompt' is displayed to the user, 'readVal' is the input variable
\return '-1' returned if invalid input, '0' returned if validity */
int getString(std::string& readVal, std::string prompt){
  std::cout << prompt;
  std::getline(std::cin, readVal);
  std::cin.ignore();

  if (std::cin.fail()) // check type
  {
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    std::cout << "***invalid***" << '\n';
    return -1;
  } else {
    return 0;
  }

  return -1;
};
