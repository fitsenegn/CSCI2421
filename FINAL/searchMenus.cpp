#include "searchMenus.h"

int Actress_Actor_Search(BinaryNodeTree<Actor_Actress>* People){
  char user;
   system("clear");
   // Actress_ActorBanner();
   std::cout << std::endl;
   std::cout << "1) Partial Search\n"
             << "2) Complete Search\n"
             << "3) Back\n";
   std::cout << "  > ";
   std::cin >> user;
   switch(user){
     case '1':{
        cin.clear();
        std::string searching;
        getSearchTerm(searching,"Please enter a name: ");
        Actor_Actress searchTerm;
        // std::cout << searching;
        // std::cout << searchTerm.print();
        searchTerm.setName(searching);

        if(People->findItem(searchTerm) != nullptr){
          std::vector<Actor_Actress> test;

          Actor_Actress Person = People->findItem(searchTerm)->getItem();

          std::cout << Person.print();
          std::cout << "\nEntry found. What would you like to do?"
                    << "\n1) Modify"
                    << "\n2) Delete"
                    << "\n3) Back"
                    << "\n> ";
          int c;
          std::cin >> c;
          switch(c){
            case 1:{
                // People->deleteBinaryNode(Person);
                Actor_Actress temp = Person;
                Person.modifyField();
                People->replace(temp, Person);
              }break;
            case 2:
                People->deleteBinaryNode(Person);
                std::cout << "\n***Deleted***\n.";
              break;
            case 3:
              break;
            default: std::cout << "\n***invalid***\n";
          }
          std::cin.ignore();
        }else{
          std::cout << "Not Found";
        }
           return -1;
       break;
     }case '2':{
     Actor_Actress searchTerm;
     searchTerm.setFilm("In Old Arizona");
     Actor_Actress Person = People->findItem(searchTerm)->getItem();
     cout << Person.print();
           return -1;
       break;
     }case '3':
           return 0;
       break;
     default:
       std::cout<<"invalid input\n";
     }

   return -1;
}


int Film_Search(BinaryNodeTree<Picture>* Pictures){
  char user;
   system("clear");
   // PictureBanner();
   std::cout << std::endl;
   std::cout << "1) Partial Search\n"
             << "2) Complete Search\n"
             << "3) Back\n";
   std::cout << "  > ";
   std::cin >> user;
   switch(user){
     case '1':{
           Picture newFilm;
           newFilm.userInput();
           Pictures->addBinaryNode(newFilm);
           return -1;
       break;}
     case '2':
           return -1;
       break;
     case '3':
           return 0;
       break;
     default:
       std::cout<<"invalid input\n";
     }

   return -1;
}
