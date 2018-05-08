#include <iostream>
#include "submenus.h"
#include "BinaryNodeTree.h"
#include "housekeeping.h"
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;

void test();

int main(){
    std::cin.clear();
    std::cout << "This program is designed to be run on "
              << "a Linux/Unix/Mac based system."
              << "\npress [ENTER] to continue\n";
    std::cin.ignore();

bool mExit = false;
BinaryNodeTree<Picture> Pictures;
BinaryNodeTree<Actor_Actress> People;
readInPictures("pictures.csv", &Pictures);
readInPeople("actor-actress.csv", &People);

while(mExit == false){
char user;
system("clear");
banner();
std::cout << std::endl;
std::cout << "1) Open Actress/Actor Database\n"
          << "2) Open Picture DataBase\n"
          << "3) Options\n"
          << "4) Import/Export\n"
          << "5) Save/Exit\n"
          << "6) Test's\n";
std::cout << "  > ";
cin >> user;
switch(user){
    case '1': while(Actress_Actor(&People) == -1){   }
    break;
  case '2': while(Film_menu(&Pictures) == -1){   }
    break;
  case '3':
      while(options() == -1){   }
    break;
  case '4':
    while(importExport(&Pictures,&People) == -1){   }
    break;
  case '5': mExit = true;
    break;
  case '6': test();
    break;
  default:
    std::cout<<"invalid input";
  }

}



  return 0;
}
