// CLASS IMPLEMENTED: my_string (see mystring.h for documentation)
// INVARIANT for the my_string class:
// 1. The string is stored as a null-terminated string in the dynamic array
//    that characters points to.
// 2. The total length of the dynamic array is stored in the member variable
//    allocated.
// 3. The total number of characters prior to the null character is stored in
//    current_length, which is always less than allocated.

#include <ctype.h>		// Provides stream tools
#include <assert.h>		// Provides assert()
#include <string.h>		// Provides strcpy(), strcat(), strlen(), strcmp()
#include <stdlib.h>		// Provides size_t, NULL
#include <iostream>		// Provides stream types
#include "mystring.h"
using namespace std;

namespace hw4
{

// CONSTRUCTORS and DESTRUCTOR
my_string::my_string(const char str[ ])
// Library facilities used: string.h
{
    partition_amount = 0;
    current_length = strlen(str);
    allocated = current_length + 1;
    sequence = new char[allocated];
    strcpy(sequence, str);
}

my_string::my_string(const my_string& source)
// Library facilities used: string.h
{
    partition_amount = 0;
    sequence = new char[source.allocated];
    current_length = source.current_length;
    allocated = source.allocated;
    strcpy(sequence, source.sequence);
}

my_string::~my_string( )
{
    delete [ ] sequence;
}

// MODIFICATION MEMBER FUNCTIONS

/**This function splits a long string into an array of individual strings of
  * determined size
  *\param splitSize is the amount of elements in a column.
  *\param return splitString is the sliced array of individual parts. */
my_string* my_string::split(int splitSize){ //Added by TRYSTAN KAES

  //lines is how many rows are included
  // this is the amount of elements in a string divided
  //by the amount of elements in a column.
  int lines = 0;


  if(this->length() % splitSize > 0){
    lines = (this->length()/splitSize + 1);
  }else{
    lines = (this->length()/splitSize);
  }


  // pointer points to a list of each row the size of columns
  my_string* splitString = new my_string[lines];

  int cursor = 0; //current character that is pointed at in the string
  int end_position = 0; //column size past the cursor
  int index = 0; //current row


  while(cursor < this->length() - 1 ){ //prevent overflow

    my_string temp;

    end_position = cursor + splitSize;



    for(; cursor < end_position; cursor++){ //count out column size into this row

          if(cursor == this->length()) //fault check
              break;

        temp += this->privateAccess(cursor); //fill row
    }



    //insert the split character if in the middle of a word
    if(this->privateAccess(cursor - 1) != ' ') //previous character
      if(this->privateAccess(cursor) != ' ') //this character
        if(cursor != this->length()) //dont add at end
          temp += "-";


    splitString[index] = temp; //place the row into the array




    index++; //next row
  }
  splitString->partition_amount = lines; //set a partitions variable,
                                        //this is an abstracted "length"
  return splitString; //return the formatted my_string array
}


// CONSTANT MEMBER FUNCTIONS
// In-lined: size_t length( ) const;
char my_string::operator [ ](size_t position) const
// Library facilities used: assert.h
{
    assert(position < current_length);
    return sequence[position];
}

/** My access might be dodgy but the algorithm is tight. This allows for free
  * access of the pointers without checking viability first. UNSAFE
  *\param position is the index
  *\return sequence[position] is the element here.*/
// In-lined: size_t length( ) const;
char my_string::privateAccess(size_t position) const //Added by Trystan Kaes
// Library facilities used: assert.h
{
    // assert(position < current_length);
    return sequence[position];
}

// += Operator overloading.
void my_string::operator +=(const my_string& addend)
// Library facilities used: string.h
{
    size_t totalLength;

    totalLength = (current_length+1+addend.current_length);
    if (allocated < totalLength)
        reserve(totalLength);
    strcat(sequence, addend.sequence);
    current_length = totalLength - 1;
}


// += Operator overloading.
void my_string::operator +=(const char addend[ ])
// Library facilities used: string.h
{
    size_t totalLength;

    totalLength = current_length+1+strlen(addend);
    if (allocated < totalLength)
        reserve(totalLength);
    strcat(sequence, addend);
    current_length = totalLength - 1;
}


// += Operator overloading.
void my_string::operator +=(char addend)
// Library facilities used: string.h
{
    char addstring[2];
    addstring[0]=addend;
    addstring[1]='\0';
    size_t totalLength;

    totalLength = (current_length+2);
    if (allocated < totalLength)
        reserve(totalLength);
    strcat(sequence, addstring);
    current_length = totalLength - 1;
}


void my_string::reserve(size_t n)
{
    size_t i;
    char *larger_string;

    if (n == allocated)
        return; // The allocated memory is already the right size
    if (n < current_length+1)
        n = current_length+1; // Can't allocate less than is being used

    larger_string = new char[n];
    for(i=0; i < current_length+1; i++)
        larger_string[i] = sequence[i];
    delete [ ] sequence;
    sequence = larger_string;
    allocated = n;
}


void my_string::insert(size_t n)
// Function to insert a hyphen between words in a string
{
	size_t totalLength;
	totalLength = current_length+2;
	reserve(totalLength);
	current_length = totalLength-1;
	// Insert necessary hyphen at appropriate position
	if ((sequence[n-1] == ' ') && (sequence[n+1] != ' '))
	// Insert hyphen at column + 1 position
	{
		for (int i=current_length; i>n+1; --i)
			sequence[i] = sequence[i-1];
		sequence[n+1] = '-';
	}
	else
	// Insert hyphen at column position
	{
		for (int i=current_length; i>n; --i)
			sequence[i] = sequence[i-1];
		sequence[n] = '-';
	}
}


// = Operator overloading.
void my_string::operator =(const my_string& source)
{
    size_t i;
    char *new_string;

    if (allocated != source.allocated)
    {
        new_string = new char[source.allocated];
        delete [ ] sequence;
        sequence = new_string;
        allocated = source.allocated;
    }
    current_length = source.current_length;
    for (i=0; i < current_length+1; i++)
        sequence[i] = source.sequence[i];
}


// FRIEND FUNCTIONS
// << Operator overloading.
ostream& operator <<(ostream& outs, const my_string& source)
{
    size_t i;

    for (i=0; i < source.current_length; i++)
        outs << source.sequence[i];
    return outs;
}


// == Operator overloading.
bool operator ==(const my_string& s1, const my_string& s2)
// Library facilities used: string.h
{
    int comp = strcmp(s1.sequence, s2.sequence);

    return (comp==0);
}


// != Operator overloading.
bool operator !=(const my_string& s1, const my_string& s2)
// Library facilities used: string.h
{
    int comp = strcmp(s1.sequence, s2.sequence);

    return (comp!=0);
}


// >= Operator overloading.
bool operator >=(const my_string& s1, const my_string& s2)
// Library facilities used: string.h
{
    int comp = strcmp(s1.sequence, s2.sequence);

    return ((comp>0)||(comp==0));
}


// <= Operator overloading.
bool operator <=(const my_string& s1, const my_string& s2)
// Library facilities used: string.h
{
    int comp = strcmp(s1.sequence, s2.sequence);

    return ((comp<0)||(comp==0));
}


// > Operator overloading.
bool operator > (const my_string& s1, const my_string& s2)
// Library facilities used: string.h
{
    int comp = strcmp(s1.sequence, s2.sequence);

    return (comp>0);
}

// < Operator overloading.
bool operator < (const my_string& s1, const my_string& s2)
// Library facilities used: string.h
{
    int comp = strcmp(s1.sequence, s2.sequence);

    return (comp<0);
}



// + Operator overloading.
// NON-MEMBER FUNCTIONS for the String class
my_string operator +(const my_string& s1, const my_string& s2)
{
    my_string combinedString;

    combinedString += s1;
    combinedString += s2;

    return combinedString;
}


// >> Operator overloading.
istream& operator >>(istream& ins, my_string& target)
{
    char c;

    while (ins && isspace(ins.peek()))
        ins.ignore();
    target=""; // Set the target to the empty string.
    while (ins && !isspace(ins.peek()))
    {
        ins >> c;
        target += c; // Call the operator += with a char argument.
    }

    return ins;
}


void getline(istream& ins, my_string& target)
{
    char c;

    eat_white(ins, target);   // Removes initial whitespace
    target="";
    ins.get(c);
    while (ins && (c!='\n'))
    {
        target += c;
		if (ins && isspace(ins.peek()) && ins.peek()!='\n')
		{
			eat_white(ins, target); // Removes additional
                                                // whitespace between words
			target += ' ';
		}
		ins.get(c);
    }
}

void eat_white(istream& ins, my_string& target)
{
	while (ins && isspace(ins.peek()))
		ins.ignore();
}

}
