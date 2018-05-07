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

std::string Actor_Actress::printToFile() const { //this will return a formatted string for printing
std::stringstream out;
  out << _self.Year;
  out << ", " << _self.Award;
  out << ", " << _self.Winner;
  out << ", " << _self.Name;
  out << ", " << _self.Film;

  return out.str();

}

int Actor_Actress::modifyField(){
  std::cout << "\n---------MODIFY---------\n       ";
  std::cout << "\n1) Name"
            << "\n2) Award"
            << "\n3) Winner"
            << "\n4) Film"
            << "\n5) Year\n";
  int check;
  std::cin >> check;

  switch(check){
    case 1:{
      std::string temp;
      std::cout << "\nExisting Name: " << this->getName();
      while( -1 == getString(temp ,"\nEdit Name:  "));
      this->setName(temp);

      break;
    }case 2:{
      std::string temp;
      std::cout << "\nExisting Award: " << this->getAward();
      while( -1 == getString(temp ,"\nEdit Award:  "));
      this->setAward(temp);

      break;
    }case 3:{
      int number;
      std::cout << "\nExisting Winner: " << this->getWinner();
      while( -1 == getInt(number, "\nEdit Winner:  "));
      this->setWinner(number);
      break;
    }case 4:{
      std::string temp;
      std::cout << "\nExisting Film: " << this->getFilm();
      while( -1 == getString(temp ,"\nEdit Film:  "));
      this->setFilm(temp);

      break;
    }case 5:{
      int number;
      std::cout << "\nExisting year: " << this->getYear();
      while( -1 == getInt(number, "\nEdit Year:  "));
      this->setYear(number);
      break;
    }default: std::cout << "\n***invalid***\n";
      break;
  }
  return -1;
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

bool Actor_Actress::completeCompare(Actor_Actress comp){
  if(_self.Compare == comp.getComp()){
    return true;
  }
  if(comp.getYear() == _self.Year){
    return true;
  }
  if(comp.getAward() == _self.Award){
    return true;
  }
  if(comp.getWinner() == _self.Winner){
    return true;
  }
  if(comp.getName() == _self.Name){
    return true;
  }
  if(comp.getFilm() == _self.Film){
    return true;
  }
  return false;
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

int Picture::modifyField(){
  std::cout << "\n---------MODIFY---------\n       ";
  std::cout << "\n1) Name"
            << "\n2) Year"
            << "\n3) Nominations"
            << "\n4) Rating"
            << "\n5) Duration"
            << "\n6) Genre1"
            << "\n7) Genre2"
            << "\n8) Release"
            << "\n9) Metacritic"
            << "\n10) Synopsis\n";
  int check;
  std::cin >> check;


  switch(check){
    case 1:{
      std::string temp;
      std::cout << "\nExisting name: " << this->getName();
      while( -1 == getString(temp ,"\nEdit Name:  "));
      this->setName(temp);

      break;
    }case 2:{
      int number;
      std::cout << "\nExisting year: " << this->getYear();
      while( -1 == getInt(number, "\nEdit Year:  "));
      this->setYear(number);
      break;
    }case 3:{
      int number;
      std::cout << "\nExisting Nomination: " << this->getNom();
      while( -1 == getInt(number, "\nEdit Nomination count:  "));
      this->setNom(number);

      break;
    }case 4:{
      double decimal;
      std::cout << "\nExisting rating: " << this->getRating();
      while( -1 == getDouble(decimal, "\nEdit Rating:  "));
      this->setRating(decimal);

      break;
    }case 5:{
      int number;
      std::cout << "\nExisting duration: " << this->getDuration();
      while( -1 == getInt(number, "\nEdit Duration:  "));
      this->setDuration(number);

      break;
    }case 6:{
      std::string temp;
      std::cout << "\nExisting Genre1: " << this->getGenre1();
      while( -1 == getString(temp ,"\nEdit Genre1:  "));
      this->setGenre1(temp);

      break;
    }case 7:{
      std::string temp;
      std::cout << "\nExisting Genre2: " << this->getGenre2();
      while( -1 == getString(temp ,"\nEdit Genre2:  "));
      this->setGenre2(temp);

      break;
    }case 8:{
      std::string temp;
      std::cout << "\nExisting Release: " << this->getRelease();
      while( -1 == getString(temp ,"\nEdit Release month:  "));
      this->setRelease(temp);

      break;
    }case 9:{
      int number;
      std::cout << "\nExisting MetaCritic: " << this->getMetacritic();
      while( -1 == getInt(number, "\nEdit MetaCritic score:  "));
      this->setMetacritic(number);

      break;
    }case 10:{
      std::string temp;
      std::cout << "\nExisting Synopsis: " << this->getSynopsis();
      while( -1 == getString(temp ,"\nEdit Synopsis:  "));
      this->setSynopsis(temp);

      break;
    }default: std::cout << "\n***invalid***\n";
      break;
  }
//
  return -1;
}

bool Picture::completeCompare(Picture comp){
  if(_self.Compare == comp.getComp()){
    return true;
  }
  if(_self.Name == comp.getName()){
    return true;
  }
  if(_self.Year == comp.getYear()){
    return true;
  }
  if(_self.Nominations == comp.getNom()){
    return true;
  }
  if(_self.Rating == comp.getRating()){
    return true;
  }
  if(_self.Duration == comp.getDuration()){
    return true;
  }
  if(_self.Genre1 == comp.getGenre1()){
    return true;
  }
  if(_self.Genre2 == comp.getGenre2()){
    return true;
  }
  if(_self.Release == comp.getRelease()){
    return true;
  }
  if(_self.Metacritic == comp.getMetacritic()){
    return true;
  }
  if(_self.Synopsis == comp.getSynopsis()){
    return true;
  }
  return false;
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


std::string Picture::printToFile() const {
  std::stringstream out;
  out  << _self.Name;

  out << "," << _self.Year;

  out << "," << _self.Nominations;

  out << "," << _self.Rating;

  out << "," << _self.Duration;

  out << "," << _self.Genre1;

  out << "," << _self.Genre2;

  out << "," << _self.Release;

  out << "," << _self.Metacritic;
  out << "," << _self.Synopsis;

  return out.str();
}
