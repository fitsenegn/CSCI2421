#include "submenus.h"
#include <iostream>
#include "housekeeping.h"



void banner() {
std::cout << "   ███     ███     ███     ███     ███     ███     ███     ███     ███     ███  " << std::endl;
std::cout << "   ███     ███     ███     ███     ███     ███     ███     ███     ███     ███  " << std::endl;
std::cout << "                                                                                " << std::endl;
std::cout << "            ▓▌                                                    ▓▌           " << std::endl;
std::cout << "           ▓▓█▌                       THE                        ▓▓█▌          " << std::endl;
std::cout << "           ▀▓▌\"                                                  ▀▓▌\"           " << std::endl;
std::cout << "            ▓▓                      ACADEMY                       ▓▓           " << std::endl;
std::cout << "            ▓▓                                                    ▓▓            " << std::endl;
std::cout << "            ▓▌                       AWARDS                       ▓▌           " << std::endl;
std::cout << "          â▒█▌@⌂                                                â▒█▌@⌂          " << std::endl;
std::cout << "          ╫░╟▌\"▌                                                ╫░╟▌\"▌         " << std::endl;
std::cout << "         ╙▀ ╣╝ ⁿ\"                                              ╙▀ ╣╝ ⁿ\"         " << std::endl;
std::cout << "                                                                                " << std::endl;
std::cout << "   ███     ███     ███     ███     ███     ███     ███     ███     ███     ███  " << std::endl;
std::cout << "   ███     ███     ███     ███     ███     ███     ███     ███     ███     ███  " << std::endl;

}

void optionBanner(){

std::cout << "  ____  ____  _____  _  ____  _      ____ " << std::endl;
std::cout << " /  _ \\/  __\\/__ __\\/ \\/  _ \\/ \\  /|/ ___\\ " << std::endl;
std::cout << " | / \\||  \\/|  / \\  | || / \\|| |\\ |||    \\ " << std::endl;
std::cout << " | \\_/||  __/  | |  | || \\_/|| | \\||\\___ | " << std::endl;
std::cout << " \\____/\\_/     \\_/  \\_/\\____/\\_/  \\|\\____/ " << std::endl;

}

void importBanner(){

std::cout << "   ____  _     _  ____  ____  _  _      _____ " << std::endl;
std::cout << " / ___\\/ \\ /|/ \\/  __\\/  __\\/ \\/ \\  /|/  __/ " << std::endl;
std::cout << " |    \\| |_||| ||  \\/||  \\/|| || |\\ ||| |  _ " << std::endl;
std::cout << " \\___ || | ||| ||  __/|  __/| || | \\||| |_// " << std::endl;
std::cout << " \\____/\\_/ \\|\\_/\\_/   \\_/   \\_/\\_/  \\|\\____\\ " << std::endl;

}

void Actress_ActorBanner(){
std::cout << "              _                         __         _                    " << std::endl;
std::cout << "    /\\       | |                       / /\\       | |                 " << std::endl;
std::cout << "   /  \\   ___| |_ _ __ ___  ___ ___   / /  \\   ___| |_ ___  _ __      " << std::endl;
std::cout << "  / /\\ \\ / __| __| '__/ _ \\/ __/ __| / / /\\ \\ / __| __/ _ \\| '__| " << std::endl;
std::cout << " / ____ \\ (__| |_| | |  __/\\__ \\__ \\/ / ____ \\ (__| || (_) | |     " << std::endl;
std::cout << "/_/    \\_\\___|\\__|_|  \\___||___/___/_/_/    \\_\\___|\\__\\___/|_|  " << std::endl;

}

void PictureBanner(){
 std::cout << " _____ _____ _____ _______ _    _ _____  ______  _____       " << std::endl;
 std::cout << "|  __ \\_   _/ ____|__   __| |  | |  __ \\|  ____|/ ____|   " << std::endl;
 std::cout << "| |__) || || |       | |  | |  | | |__) | |__  | (___       " << std::endl;
 std::cout << "|  ___/ | || |       | |  | |  | |  _  /|  __|  \\___ \\    " << std::endl;
 std::cout << "| |    _| || |____   | |  | |__| | | \\ \\| |____ ____) |   " << std::endl;
 std::cout << "|_|   |_____\\_____|  |_|   \\____/|_|  \\_\\______|_____/  " << std::endl;
}


int Actress_Actor(){
 char user;
  system("clear");
  Actress_ActorBanner();
  std::cout << std::endl;
  std::cout << "1) Add a record\n"
            << "2) Search for a record\n"
            << "3) Modify Record\n"
            << "4) Delete Record\n"
            << "5) Sort by specified value\n"
            << "6) Complete Search\n"
            << "7) Modify Records\n"
            << "8) Print out changes\n"
            << "9) Back\n";
  std::cout << "  > ";
  std::cin >> user;
  switch(user){
    case '1':
          return -1;
      break;
    case '2':
          return -1;
      break;
    case '3': return -1;
      break;
    case '4':
          return -1;
      break;
    case '5':
          return -1;
      break;
    case '6': return -1;
      break;
    case '7':
          return -1;
      break;
    case '8':{
          std::string file;
          std::cout << "\nPlease specify your file\n";
          std::cin.ignore();
          getline(std::cin, file);
          std::cin.clear();
          }
          return 0;
      break;
    case '9': return 0;
    default:
      std::cout<<"invalid input\n";
    }

  return -1;
}

int Pictures(){
 char user;
  system("clear");
  PictureBanner();
  std::cout << std::endl;
  std::cout << "1) Add a record\n"
            << "2) Search for a record\n"
            << "3) Modify Record\n"
            << "4) Delete Record\n"
            << "5) Sort by specified value\n"
            << "6) Complete Search\n"
            << "7) Modify Records\n"
            << "8) Print out changes\n"
            << "9) Back\n";
  std::cout << "  > ";
  std::cin >> user;
  switch(user){
    case '1':
          return -1;
      break;
    case '2':
          return -1;
      break;
    case '3': return -1;
      break;
    case '4':
          return -1;
      break;
    case '5':
          return -1;
      break;
    case '6': return -1;
      break;
    case '7':
          return -1;
      break;
    case '8':{
          std::string file;
          std::cout << "\nPlease specify your file\n";
          std::cin.ignore();
          getline(std::cin, file);
          std::cin.clear();
          }
          return 0;
      break;
    case '9':
          return 0;
      break;
    default:
      std::cout<<"invalid input\n";
    }

  return -1;
}

int options(){
 char user;
  system("clear");
  optionBanner();
  std::cout << std::endl;
  std::cout << "1) Some Option\n"
            << "2) Another Option\n"
            << "3) Back\n";
  std::cout << "  > ";
  std::cin >> user;
  switch(user){
    case '1':
          return 0;
      break;
    case '2':
          return 0;
      break;
    case '3': return 0;
    default:
      std::cout<<"invalid input\n";
    }

  return -1;
}



int importExport(){
  char user;
   system("clear");
   importBanner();
   std::cout << std::endl;
   std::cout << "1) Import Actress/Actor\n"
             << "2) Import Pictures\n"
             << "3) Back\n";
   std::cout << "  > ";
   std::cin >> user;
   switch(user){
     case '1':{
       std::string file;
       std::cout << "\nPlease specify your file\n";
       std::cin.ignore();
       getline(std::cin, file);
       std::cin.clear();
     }
       break;
       case '2':{
           std::string file;
           std::cout << "\nPlease specify your file\n";
           std::cin.ignore();
           getline(std::cin, file);
           std::cin.clear();
       }
       break;
     case '3': return 0;
     default:
       std::cout<<"invalid input\n";
     }

   return -1;
}

/////////////////////////////////////////////

void test(){ //Test crap here


  BinaryNodeTree<Actor_Actress> person;

  readInPeople("actor-actress.csv", &person);

  person.printInorder();

  ///////////////////////////////////
      std::cout << "\npress [ENTER] to continue\n";
      std::cin.get();
      std::cin.clear();
      std::cin.ignore();
}
