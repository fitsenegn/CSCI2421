#include "searchMenus.h"

/**This is the submenu in charge of searching for Actor_Actress things*/
int Actress_Actor_Search(BinaryNodeTree<Actor_Actress,std::string>* People){
  char user;
   system("clear");
   // Actress_ActorBanner();
   std::cout << std::endl;
   std::cout << "1) Complete Name Search\n"
             << "2) Partial Name Search\n"
             << "3) Back\n";
   std::cout << "  > ";
   std::cin >> user;
   switch(user){
     case '1':{
        cin.clear();
        std::string searching;
        getSearchTerm(searching,"Please enter a name: ");

        if(People->findItem(searching) != nullptr){
          std::vector<Actor_Actress> test = People->findAllMatches(searching);

          Actor_Actress Person;
          int index;
          if(test.size() == 1){
            Person = test[0];
            std::cout << "\nEntry found.\n";
          }else{
            for(int i = 0; i < test.size(); i++){
              cout << "##### " << i << " #####" << endl;
              std::cout << test[i].print();
            }
            getBoundedInt(0, index, test.size(), "\nMultiple Entries Found. Please select one.\n");
            Person = test[index];
          }


          std::cout << Person.print();
          std::cout << " What would you like to do?"
                    << "\n1) Modify"
                    << "\n2) Delete"
                    << "\n3) Back"
                    << "\n> ";
          int c;
          std::cin >> c;
          switch(c){
            case 1:{
              std::vector<Actor_Actress> deleteVector = People->getVector(); //export contents

              BinaryNodeTree<Actor_Actress,int>* deleteTemp = new BinaryNodeTree<Actor_Actress,int>; //make an integer based tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //fill
                deleteTemp->addBinaryNode(deleteVector[i].getKey(),deleteVector[i]);
              }

              deleteTemp->deleteBinaryNode(Person.getKey()); //delete the selection

              deleteVector = deleteTemp->getVector(); //export modified

              People->clear(); //clear the old tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //re-fill
                People->addBinaryNode(stripPunctuation(deleteVector[i].getName()),deleteVector[i]);
              }
              Person.modifyField();

              People->addBinaryNode(stripPunctuation(Person.getName()),Person);

              break;
            }case 2:{
              std::vector<Actor_Actress> deleteVector = People->getVector(); //export contents

              BinaryNodeTree<Actor_Actress,int>* deleteTemp = new BinaryNodeTree<Actor_Actress,int>; //make an integer based tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //fill
                deleteTemp->addBinaryNode(deleteVector[i].getKey(),deleteVector[i]);
              }

              deleteTemp->deleteBinaryNode(Person.getKey()); //delete the selection

              deleteVector = deleteTemp->getVector(); //export modified

              People->clear(); //clear the old tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //re-fill
                People->addBinaryNode(stripPunctuation(deleteVector[i].getName()),deleteVector[i]);
              }

                std::cout << "\n***Deleted***\n.";
              break;
            }case 3:
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
          std::cout << "\n*** not implemented ****\n";
             cin.ignore();
             cin.ignore();
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

/**This is the submenu in charge of searching for Picture things*/
int Film_Search(BinaryNodeTree<Picture,std::string>* Pictures){
  char user;
   system("clear");
   // PictureBanner();
   std::cout << std::endl;
   std::cout << "1) Complete Name Search\n"
             << "2) Partial Name Search\n"
             << "3) Back\n";
   std::cout << "  > ";
   std::cin >> user;
   switch(user){
     case '1':{
        cin.clear();
        std::string searching;
        getSearchTerm(searching,"Please enter a name: ");

        if(Pictures->findItem(searching) != nullptr){
          std::vector<Picture> test = Pictures->findAllMatches(searching);

          Picture picture;
          int index;
          if(test.size() == 1){
            picture = test[0];
            std::cout << "\nEntry found.\n";
          }else{
            for(int i = 0; i < test.size(); i++){
              cout << "##### " << i << " #####" << endl;
              std::cout << test[i].print();
            }
            getBoundedInt(0, index, test.size(), "\nMultiple Entries Found. Please select one.\n");
            picture = test[index];
          }


          std::cout << picture.print();
          std::cout << " What would you like to do?"
                    << "\n1) Modify"
                    << "\n2) Delete"
                    << "\n3) Back"
                    << "\n> ";
          int c;
          std::cin >> c;
          switch(c){
            case 1:{
              std::vector<Picture> deleteVector = Pictures->getVector(); //export contents

              BinaryNodeTree<Picture,int>* deleteTemp = new BinaryNodeTree<Picture,int>; //make an integer based tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //fill
                deleteTemp->addBinaryNode(deleteVector[i].getKey(),deleteVector[i]);
              }

              deleteTemp->deleteBinaryNode(picture.getKey()); //delete the selection

              deleteVector = deleteTemp->getVector(); //export modified

              Pictures->clear(); //clear the old tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //re-fill
                Pictures->addBinaryNode(stripPunctuation(deleteVector[i].getName()),deleteVector[i]);
              }
              picture.modifyField();

              Pictures->addBinaryNode(stripPunctuation(picture.getName()),picture);

              }break;
            case 2:{
              std::vector<Picture> deleteVector = Pictures->getVector(); //export contents

              BinaryNodeTree<Picture,int>* deleteTemp = new BinaryNodeTree<Picture,int>; //make an integer based tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //fill
                deleteTemp->addBinaryNode(deleteVector[i].getKey(),deleteVector[i]);
              }

              deleteTemp->deleteBinaryNode(picture.getKey()); //delete the selection

              deleteVector = deleteTemp->getVector(); //export modified

              Pictures->clear(); //clear the old tree

              for(int i = 0; i < deleteVector.size()-1; i++){ //re-fill
                Pictures->addBinaryNode(stripPunctuation(deleteVector[i].getName()),deleteVector[i]);
              }

                std::cout << "\n***Deleted***\n.";
              break;
            }case 3:
              break;
            default: std::cout << "\n***invalid***\n";
          }
          std::cin.ignore();
        }else{
          std::cout << "Not Found";
        }
           return -1;
       break;
     }case '2':
         std::cout << "\n*** not implemented ****\n";
         cin.ignore();
          cin.ignore();
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
