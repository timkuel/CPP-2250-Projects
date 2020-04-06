/*
 * MyString.cpp
 *
 *  Created on: Jul 8, 2018
 *      Author: timkuelker
 */
#include <iostream>
#include "MyString.h"

using namespace std;

int MyString::strCount = 0;									//initializing strcount to 0

MyString::MyString(const char *str)							//constructor that takes char parameter
{
	setStr(new char [strlen(str) + 1]);
	strcpy(this-> str, str);
	setSize(strlen(str));
	strCount++;
}

MyString::MyString()									//default constructor
{
	setSize(0);
	setStr(new char [getSize() + 1]);
	*str = '\0';
	strCount++;
}

MyString::MyString(const MyString &mstr)					//copy constructor
{
	setStr(new char[mstr.getSize() + 1]);
	strcpy(str, mstr.str);
	setSize(mstr.getSize());
	strCount++;
}

MyString MyString::operator=(const MyString &mstr)				//class = operator
{
	delete [] str;											//removing private string data
	size = mstr.size ;
	str = new char [size + 1];
	for (int i = 0; i < size + 1; i++)
		str[i] = mstr.str[i];
	return *this;
}

MyString MyString::operator+=(const MyString &mstr)						//class += operator
{
	size = mstr.size + this-> size;
	char *ptr = new char[size + 1];
	strcpy(ptr, str);												//copying class string to new dynamically allocated pointer
	delete [] str;													//deleting class string to make room
	strcat(ptr, mstr.str);											//splicing the added string to the pointer string
	for(int i = 0; i < size + 1; i++)													//setting whole string back to private member
		str[i] = ptr[i];
	setSize(strlen(str));

	return *this;
}

MyString::~MyString()									//class deconstructor
{
	delete [] str;
	setSize(0);
	strCount--;
}

void MyString::display()												//display function shows string and string length
{
	cout << "MyStirng object string: " << getStr() << endl;
	cout << "Size of object string : " << getSize() << endl << endl;
}

