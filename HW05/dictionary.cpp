#include "dictionary.h"


/*Searches the list starting at the front of the list and moving to the back
 Returns the number of searches it took to find the findString, or a -1 if not found*/
int dictionary::searchForward(wordType &findString){
  int count = 1;
  for(somePages::iterator i = this->wordList.begin(); i != this->wordList.end(); ++i){
          if(i->getWord() == findString){
            return count;
          }
      count++;
  }
  return -1;
}

/*Searches the list starting at the back of the list and moving to the front
 Returns the number of searches it took to find the findString, or a -1 if not found*/
int dictionary::searchBackward(wordType &findString){
  int count = 1;
  for(somePages::reverse_iterator i = this->wordList.rbegin(); i != this->wordList.rend(); ++i){
          if(i->getWord() == findString){
            return count;
          }
      count++;
  }
  return -1;
}

/*Prints the list of words in reverse alphabetic order to a file*/
void dictionary::revPrintList(ostream& output){
  for(somePages::reverse_iterator i = this->wordList.rbegin(); i != this->wordList.rend(); ++i){
      output << i->getWord() << " ";
  }
}

void dictionary::print(){
  somePages print = this->wordList;

  for(somePages::iterator i = print.begin(); i != print.end(); ++i){
          std::cout << (*i);
          std::cout << "\n";
  }
}

/*Get the entry at a specific index*/
DictEntry dictionary::getEntry(int i){

return DictEntry("","");
}

/**Read in text continuously into linked list and strip all whitespace and
   punctuation leaving only spaces.
   *\param head is the string to be read into
   *\param file is the name of the file to be readIn
                                      | std::ifstream needs std::string
   *\return error tracks if there was an error, what type, and where in the
                                                                          file.*/
/*Read each entry in a specified file into the dictionary*/
exception_status dictionary::readDictionary(std::string file){
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

    infile >> std::ws; //strip initial whitespace

    // node *cursor = head;

    while(!infile.eof()){

      count++;

      std::string temp;

      std::getline(infile, temp, '\n'); //read the current word up to enter

      for(int i = 0; i < temp.size()+1; i++){ //strip punctuation
        if(ispunct(temp[i])){  //if index is punctuation
          temp.erase(i, i-1); //remove the current character
        }else{
          temp[i] = tolower(temp[i]); //capitals cause problems with sort
        }
      }

      if(temp.size() > 0){ //if the read thing wasn't ONLY punctuation

      // this->wordList.emplace_back(temp,"no definition available");
      this->wordList.emplace_back(temp,"");

      }

    if (infile.fail()) {
        // set error
        error.badCall("input_error_line_");
        error.which = count;
        return error; // if the file didn't read correctly, no need to continue.
    }
  }

  return error;
}
