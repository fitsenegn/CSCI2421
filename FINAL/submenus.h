#ifndef interface_h_
#define interface_h_
#include <iostream>
#include "BinaryNodeTree.h"
#include "housekeeping.h"


void banner();
void optionBanner();
void importBanner();
int Actress_Actor(BinaryNodeTree<Actor_Actress,std::string>*);
int Film_menu(BinaryNodeTree<Picture,std::string>*);
int Film_menu_sorts(BinaryNodeTree<Picture,std::string>* Pictures);
void duelPrint();
int options();
int importExport(BinaryNodeTree<Picture,std::string>*, BinaryNodeTree<Actor_Actress,std::string>*);
void test();

#endif
