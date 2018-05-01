#include "dataContainers.h"

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

/*Read in an int within bounds
\param 'prompt' is displayed to the user,int& n is user input
\return int| -1 if fail, 0 if success  */
int getDouble(double &d, std::string prompt) {
  std::cout << prompt;
  std::cin >> d;

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
  std::cin.ignore();
  std::cout << prompt;
  std::getline(std::cin, readVal);

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


//--------------------ACTOR_ACTRESS--------------------------

std::string Actor_Actress::print() const{ //this will return a formatted string for printing
  std::stringstream out;

  out << "Name:       " << _self.Name;


  out << "\nAward:      " << _self.Award;

  if(_self.Winner == 1){
    out << "\nWinner:     Yes";
  }else if(_self.Winner == 0){
    out << "\nWinner:     No";
  }

  out << "\nFilm:       " << _self.Film;

  out << "\nYear:       " << _self.Year;

  return out.str();

}


/**Take user input and sets self
\return success or failure as an int*/
int Actor_Actress::userInput(){ //Year,Award,Winner,Name,Film
  std::cout << "\nReady to add a new Actor?[Y/N]\n       ";
  char c;
  std::cin >> c;

  if(tolower(c) == 'n'){ //exit
    return -1;
  }else if(tolower(c) == 'y'){ //continue

  }else{ //fail
    return -1;
  }
  std::string temp;
  while( -1 == getString(temp ,"\nPlease input a name:  "));
  this->setName(temp);

  while( -1 == getString(temp, "\nPlease input award:  "));
  this->setAward(temp);

  std::cout << "\nDid they win?[Y/N]\n       ";
  std::cin >> c;

  if(tolower(c) == 'n'){ //exit
    this->setWinner(0);
  }else if(tolower(c) == 'y'){ //return
    this->setWinner(1);
  }else{
    std::cout << "\n     so no...    \n";
    this->setWinner(0);
  }


  while( -1 == getString(temp ,"\nPlease input a Film:  "));
  this->setFilm(temp);

  int number;
  while( -1 == getInt(number, "\nPlease input a year:  "));
  this->setYear(number);




  std::cout << this->print();
  std::cout << "\nConfirm[Y/N]\n       ";
  std::cin >> c;

  if(tolower(c) == 'n'){ //exit
    return -1;
  }else if(tolower(c) == 'y'){ //return
    return 0;
  }

  return -1;
}



//--------------------PICTURE------------------------------
/**Take user input and sets self
\return success or failure as an int*/
int Picture::userInput(){
  std::cout << "\nReady to add a new picture?[Y/N]\n       ";
  char c;
  std::cin >> c;

  if(tolower(c) == 'n'){ //exit
    return -1;
  }else if(tolower(c) == 'y'){ //continue

  }else{ //fail
    return -1;
  }
  std::string temp;
  while( -1 == getString(temp ,"\nPlease input a name:  "));
  this->setName(temp);


  int number;
  while( -1 == getInt(number, "\nPlease input a year:  "));
  this->setYear(number);

  while( -1 == getInt(number, "\nPlease input nomination count:  "));
  this->setNom(number);

  double decimal;
  while( -1 == getDouble(decimal, "\nPlease input a rating:  "));
  this->setRating(decimal);

  while( -1 == getInt(number, "\nPlease input duration:  "));
  this->setDuration(number);

  while( -1 == getString(temp ,"\nPlease input Genre1:  "));
  this->setGenre1(temp);

  while( -1 == getString(temp ,"\nPlease input a Genre2:  "));
  this->setGenre2(temp);

  while( -1 == getString(temp ,"\nPlease input a release month:  "));
  this->setRelease(temp);

  while( -1 == getInt(number, "\nPlease input a MetaCritic score:  "));
  this->setMetacritic(number);

  while( -1 == getString(temp ,"\nPlease input a synopsis:  "));
  this->setSynopsis(temp);

  std::cout << this->print();
  std::cout << "\nConfirm[Y/N]\n       ";
  std::cin >> c;

  if(tolower(c) == 'n'){ //exit
    return -1;
  }else if(tolower(c) == 'y'){ //return
    return 0;
  }

  return -1;
}


std::string Picture::print() const{
  std::stringstream out;

  out << "Name:         " << _self.Name;


  out << "\nYear:         " << _self.Year;

  out << "\nNominations:  " << _self.Nominations;

  out << "\nRating:       " << _self.Rating;

  out << "\nDuration:     " << _self.Duration;

  out << "\nGenre1:       " << _self.Genre1;

  out << "\nGenre2:       " << _self.Genre2;

  out << "\nRelease:      " << _self.Release;

  out << "\nMetacritic:   " << _self.Metacritic;

  out << "\nSynopsis:     \n";
  int lines = 0;
  for(int i = 0; i < _self.Synopsis.size(); i++){
    char temp;
    temp = _self.Synopsis[i];
    out << temp;
    lines++;

    if(lines == 65){
      if(_self.Synopsis[i] != ' ' && _self.Synopsis[1+i] != ' ')
        out << "-";
      out << "\n";
      lines = 0;
    }
  }

  return out.str();
}
