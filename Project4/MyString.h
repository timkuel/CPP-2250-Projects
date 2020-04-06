/*
 * MyString.h
 *
 *  Created on: Jul 8, 2018
 *      Author: timkuelker
 */
#include <iostream>
#include <cstring>

#ifndef MYSTRING_H_
#define MYSTRING_H_

class MyString
{
private:
	char *str;
	int size;
	static int strCount;

public:
	MyString();										//default constructor
	MyString(const char*);							//overloaded constructor for dynamic char array
	MyString(const MyString&);						//copy constructor

	MyString operator= (const MyString&);				//overloading = operator
	MyString operator+= (const MyString&);				//overloading += operator

	void setStr(char *str)
		{this-> str = new char[strlen(str) + 1];	//dynamically allocating character array
		strcpy(this-> str, str);}
	void setSize(int size) {this-> size = size;}
	void display();

	char *getStr() const {return str;}
	int getSize() const {return size;}
	int getStrCount() const {return strCount;}

	~MyString();									//destructor for MyString
};


#endif /* MYSTRING_H_ */

