//============================================================================
// Name        : Project4.cpp
// Author      : Tim
// Description : Use of overloaded operators in class
//============================================================================

#include <iostream>
#include "MyString.h"
#include <cstring>

using namespace std;


int main(){

	MyString s1("RACE");			//Initializing s1 object to RACE
	s1.display();

	MyString s2("CAR");				//Initializing s2 object to CAR
	s2.display();

	s1 += s2 += s2;						//using += operator to catinate s2 onto the end of s1
	s1.display();

	MyString s3 = s2;				//setting default object s3 to s2 using equal operator
	s3.display();

	MyString s4("PET");				//Initializing s4 object to PET
	s4.display();

	s3 += s4 += s4;						//using += operator to catinate s4 onto end of s3
	s3.display();

	MyString s5("PUP");				//Initializing s5 object to PUP
	s5.display();

	MyString s6;					//creating default s6 object
	s6 = s4 = s1;						//using = operator setting s6 = s4
	s6.display();

	MyString s7(s5);				//using copy constructor to set object s7 to s5

	s5 += s6;						//using += operator to catinate s6 onto the end of s5
	s5.display();

	s6.display();
	s7.display();

	s6+=s7;							//using += operator to catinate s7 onto the end of s6
	s6.display();

	cout << "\nThere were " << s1.getStrCount() << " objects created during this program.\n";

	return 0;
}

