#include <iostream>
#include "mystring.h"
#include "kaest_functions.h"


using std::endl;
using std::cin;
using std::cout;


int main(){
my_string test;
exception_status check;
std::string file;

file = "sample.txt";
check = readIn(test, file);

if(check.error == true){
  cout << check.what() << check.which << endl << endl;
}


my_string* test_split;

test_split = test.split(86);


for(int i = 0; i < 24; i++){
  cout << test_split[i] << endl;
}





  return 0;
}
