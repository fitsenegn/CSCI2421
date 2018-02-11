#include <iostream>
#include "mystring.h"
#include "kaest_functions.h"


using std::endl;
using std::cin;
using std::cout;


int main(){
my_string test;
exception_status check;

check = readIn(test);

if(check.error == true){
  cout << check.what() << check.which;
}

// ___<br/>____
for(int i = 0; i < test.length(); i++){
  if(test[i] == '_')
    if(test[i+1] == '_')
      if(test[i+2] == '_')
        if(test[i+3] == '<')
          if(test[i+4] == 'b')
            if(test[i+5] == 'r')
              if(test[i+6] == '/')
                if(test[i+7] == '>')
                  if(test[i+8] == '_')
                    if(test[i+9] == '_')
                      if(test[i+10] == '_')
                        if(test[i+11] == '_'){
                          cout << endl << endl;
                          i += 12;
                        }


  cout << test[i];
}




  return 0;
}
