#ifndef interface_h_
#define interface_h_
#include <iostream>
#include "BinaryNodeTree.h"
#include "housekeeping.h"


void banner();
void optionBanner();
void importBanner();
int Actress_Actor(BinaryNodeTree<Actor_Actress>*);
int Film_menu(BinaryNodeTree<Picture>*);
void duelPrint();
int options();
int importExport(BinaryNodeTree<Picture>*, BinaryNodeTree<Actor_Actress>*);
void test();

#endif
