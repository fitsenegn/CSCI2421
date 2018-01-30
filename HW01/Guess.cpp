#include "Guess.h"
#include <iostream>
#include <sstream>

//------------------- USEFUL FUNCTIONS

/**A basic swap function used in the sort function*/
void swapnum(int &xptr, int &yptr){
    int temp = xptr;
    xptr = yptr;
    yptr = temp;
}



/**Launched all the implementations of the actual game. Runs from front to back.
  *\@return (-1 || 0) -1 signifies play again, 0 signifies quit.*/
int Guess::startGuess(){
    this->createRandomNumbers();
  bool menu_exit = false;
    while(menu_exit == false){ //User decides whether sorted or unsorted to play
      char select;
      std::cout << "Would you like to play against\n"
                << "1) Sorted numbers\n"
                << "2) Unsorted numbers\n";
      std::cin.clear();
      std::cin >> select;

      switch(select){

        case '1': std::cout<< "*** playing against sorted numbers ***\n\n";
          this->sortNumbers();
          menu_exit = true;
          break;


        case '2': std::cout << "*** playing against unsorted numbers ***\n\n";
          menu_exit = true;
          break;


        default: std::cout << "*** please enter a valid selection ***\n\n";
        break;

      }
    }

    //___________________GAMEPLAY______________________
while(true){
    int guess_array[4];


    // // ****************************************
    // // ** Un-comment below to have the       **
    // // ** computer show its selected number  **
    // // ****************************************
    // std::cout << this->printNumbers();



    std::cout << "Enter your guesses for the 4 integers int the range from "
              << "1 to 10 that have been selected [seperated by spaces]: "
              << std::endl;

    //input guess into seperated array
    std::cin >> guess_array[0] >> guess_array[1]
             >> guess_array[2] >> guess_array[3];

    if(this->compareGuess(guess_array) < 4){ //if guess is failed
      std::cout << "\n\n      " << this->compareGuess(guess_array)
                << " of your guesses are correct. Guess again.\n\n";

    } else{ //else play again?

      bool sub_exit = false;
        while(sub_exit == false){
        char restart;
        std::cout << "\n\n      " << "You're are correct! Guess again? [y/n]\n";
        std::cin >> restart;
          if(tolower(restart) == 'y'){
            return -1; //not finished signal
          }else if(tolower(restart) == 'n'){
            return 0; //finished signal
          }else{
            std::cout << "**invalid input**" << std::endl;
          }
        }
    }
}
  return 0; //last stitch call, clear " control reaches end"
}


/** This function generates a set of four numbers(1-10),
  * placing them in randomVector*/
int Guess::createRandomNumbers(){

  int randomNumber = 0;

      randomNumber = (rand() % 10 + 1); //number between 1 and 10
      this->randomVector.push_back(randomNumber);

      randomNumber = (rand() % 10 + 1);
      this->randomVector.push_back(randomNumber);

      randomNumber = (rand() % 10 + 1);
      this->randomVector.push_back(randomNumber);

      randomNumber = (rand() % 10 + 1);
      this->randomVector.push_back(randomNumber);


  return 0;
}


/**A basic sort function that uses a bubble sort method*/
void Guess::sortNumbers(){

    for (int i = 0; i < this->randomVector.size()-1; i++){

        // outside "i" checks to make sure this is sorted, jumps when done.
        for (int j = 0; j < this->randomVector.size()-i-1; j++){
          //if the next element is smaller move it back
            if (this->randomVector[j] > this->randomVector[j+1])
               swapnum(this->randomVector[j], this->randomVector[j+1]);
         };

    }
}

/** This function places all numbers in vector into a printable stringstream
  * \@return out is the set of numbers seperated by a space*/
std::string Guess::printNumbers(){
  std::stringstream outStream; //stringstream allows use of "<<" operators

  for(int i = 0; i < 4; i++){ //iterate and add numbers in vector
    outStream << this->randomVector[i];
    outStream << " ";
  }

  std::string out = outStream.str(); //convert string stream to string

  return out;
}


/** Function recieves user guess and compares each element to the respective
  * element in the random number.
  \@return count is the amount of matches.*/
int Guess::compareGuess(int guess_array[]){
  int count = 0;

  for( int i = 0; i < this->randomVector.size(); i++){
    if(this->randomVector[i] == guess_array[i])
      count++;
  }

  return count;
}

/** Housekeeping function to make sure that before generating random numbers
  * vector is clear with 0 elements. Public Access. */
void Guess::reset(){
  this->randomVector.clear();
}
