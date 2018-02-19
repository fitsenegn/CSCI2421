#include <iostream>


using std::cin;
using std::cout;
using std::endl;



int main(int argc, char* argv[]){
  std::string filename = "";

  if(argc < 2){
    cout << "No file specified. Call with: " << endl;
    cout << "     ./subset [filename]" << endl;
    return 0;
  }else if(argc > 2){
    cout << "Too many arguments. Call with: " << endl;
    cout << "     ./subset [filename]" << endl;
    return 0;
  }else{
    filename = argv[1];
  }

  cout << filename << endl;





  return 0;
}
