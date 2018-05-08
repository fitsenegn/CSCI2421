#include "housekeeping.h"
#include <fstream>
#include <iostream>


/**Read in Actor and Actress data line by line into a Binary Search Tree
   *\param PersonTree is the tree to be read into
   *\param file is the name of the file to be readIn
                                      | std::ifstream needs std::string
   *\return error tracks if there was an error, what type, and where in the
                                                                          file.*/
exception_status readInPeople(std::string file, BinaryNodeTree<Actor_Actress,std::string>* PersonTree){
  exception_status error;

    int count = 0;

    std::ifstream infile;

        infile.open(file);

        ///////////check file/////////
      if (!infile.is_open() || infile.fail()) {
          // set error
          error.badCall("file_invalid");
          return error; // if the file didn't read, no need to continue.
      }




    count = 0; //what line are we on?


    std::string strip;
    std::getline(infile, strip , '\n'); //strip the format information

    infile >> std::ws; //strip initial whitespace

    while(!infile.eof()){

      count++;

      Actor_Actress_temp tempContainer;
      std::string temp;

      //---------YEAR--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Year = std::atoi(temp.c_str());

      //---------AWARD--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Award = temp;

      //---------WINNER--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Winner = std::atoi(temp.c_str());


      //---------NAME--------
      if(infile.peek()=='"'){
        infile.ignore(1);
        std::getline(infile, temp, '"'); //read the current word up to quote
        infile.ignore(1);
      }else{
        std::getline(infile, temp, ','); //read the current word up to comma
      }

      tempContainer.Name = temp;

      //---------FILM--------
        std::getline(infile, temp, '\n'); //read the current word up to newline

        tempContainer.Film = temp;

        tempContainer.key = count;
      Actor_Actress newPerson(tempContainer);

      PersonTree->addBinaryNode(newPerson.getComp(), newPerson);

      infile >> std::ws;

    if (infile.fail()) {
        // set error
        error.badCall("input_error_line_");
        error.which = count;
        return error; // if the file didn't read correctly, no need to continue.
    }
  }

  return error;
}


exception_status readOutPeople(std::string file, BinaryNodeTree<Actor_Actress,std::string>* peopleOut){
  exception_status error;

  std::ofstream outFile;
  outFile.open(file, std::ofstream::out);
  outFile << "Year,Award,Winner,Name,Film\n";

  peopleOut->printInorder(fileFormat, outFile);


  return error;
}
/**Read in text continuously into linked list and strip all whitespace and
   punctuation leaving only spaces.
   *\param root is the tree to be read into
   *\param file is the name of the file to be readIn
                                      | std::ifstream needs std::string
   *\return error tracks if there was an error, what type, and where in the
                                                                          file.*/
/*Read each entry in a specified file into the tree*/
exception_status readInPictures(std::string file, BinaryNodeTree<Picture,std::string>* Picturetree){
  exception_status error;

    int count = 0;

    std::ifstream infile;

        infile.open(file);

        ///////////check file/////////
      if (!infile.is_open() || infile.fail()) {
          // set error
          error.badCall("file_invalid");
          return error; // if the file didn't read, no need to continue.
      }




    count = 0; //what line are we on?

    std::string strip;
    std::getline(infile, strip , '\n'); //strip the format information

    infile >> std::ws; //strip initial whitespace


    while(!infile.eof()){
      //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
      count++;

      Picture_temp tempContainer;
      std::string temp;

      //---------NAME--------
      if(infile.peek()=='"'){
        infile.ignore(1);
        std::getline(infile, temp, '"'); //read the current word up to quote
        infile.ignore(1);
      }else{
        std::getline(infile, temp, ','); //read the current word up to comma
      }


      tempContainer.Name = temp;

      //---------YEAR--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Year = std::atoi(temp.c_str());

      //---------NOMINATIONS--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Nominations = std::atoi(temp.c_str());


      //---------RATING--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Rating = std::stod(temp.c_str());

      //---------DURATION--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Duration = std::atoi(temp.c_str());

      //---------GENRE1--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Genre1 = temp;

      //---------GENRE2--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Genre2 = temp;

      //---------RELEASE--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Release = temp;

      //---------METACRITIC--------
      std::getline(infile, temp, ','); //read the current word up to comma

      tempContainer.Metacritic = std::atoi(temp.c_str());

      //---------SYNOPSIS--------
      std::getline(infile, temp, '\n'); //read the current word up to newline

      tempContainer.Synopsis = temp;

      tempContainer.key = count;

      Picture newFilm(tempContainer);
      Picturetree->addBinaryNode(newFilm.getComp(), newFilm);
      // cout << newFilm.print() << endl << endl;
      infile >> std::ws; //strip upcoming whitespace

    if (infile.fail()) {
        // set error
        error.badCall("input_error_line_");
        error.which = count;
        return error; // if the file didn't read correctly, no need to continue.
    }
  }

  return error;
}


exception_status readOutPictures(std::string file, BinaryNodeTree<Picture,std::string>* filmOut){
  exception_status error;

  std::ofstream outFile;
  outFile.open(file, std::ofstream::out);
  outFile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis\n";

  filmOut->printInorder(fileFormat, outFile);


  return error;
}

/** Screens user input for validity
\param 'prompt' is displayed to the user, 'readVal' is the input variable
\return '-1' returned if invalid input, '0' returned if validity */
int getSearchTerm(std::string& readVal, std::string prompt){
  std::cout << prompt;
  std::cin.ignore();
  std::getline(std::cin,readVal);

  for(int i = 0; i < readVal.size()+1; i++){ //strip punctuation
    if(ispunct(readVal[i])){  //if index is punctuation
      readVal.erase(i, i-1); //remove the current character
    }else{
      readVal[i] = tolower(readVal[i]); //capitals cause problems with sort
    }
  }

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
