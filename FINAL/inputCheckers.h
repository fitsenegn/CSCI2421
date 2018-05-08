#ifndef INPUTCHECKERS_H_
#define INPUTCHECKERS_H_

#include <string>
#include <iostream>

std::string stripPunctuation(std::string temp);

int getInt(int &n, std::string prompt);

int getDouble(double &d, std::string prompt);

int getString(std::string& readVal, std::string prompt);



#endif
