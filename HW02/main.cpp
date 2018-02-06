#include <iostream>
#include "ArrayBag.h"
#include "SetFunctions.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
exception_status exception;
SetFunctions input;
ArrayBag bagA;
ArrayBag bagB;
ArrayBag unionBag;
ArrayBag subtractionBag;

exception = input.readIn(bagA, bagB); //check for errors

if(exception.error == true){
  cout << exception.status << " with element " << exception.which;

}

unionBag = bagA + bagB;
subtractionBag = bagA - bagB;



cout << "Bag A: " << bagA << endl;
cout << "Bag B: " << bagB << endl;
cout << "Union Bag: " << unionBag << endl;
cout << "Subtraction Bag: " << subtractionBag << endl;


return 0;
}
