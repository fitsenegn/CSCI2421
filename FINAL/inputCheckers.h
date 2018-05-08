#ifndef INPUTCHECKERS_H_
#define INPUTCHECKERS_H_

#include <string>
#include <iostream>

/** @subsection Input Checkers
  * All the trivial functions that make the data interfacing happen*/

std::string stripPunctuation(std::string temp);

int getInt(int &n, std::string prompt);

int getBoundedInt(int b, int &n, int t, std::string prompt);

int getDouble(double &d, std::string prompt);

int getString(std::string& readVal, std::string prompt);



#endif
