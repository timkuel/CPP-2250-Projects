/*
 * Student.cpp
 *
 *      Author: Tim Kuelker
 */
#include "Student.h"
#include <string>
#include <iostream>

//constructor that takes 4 parameters
Student::Student(Name name, int idNumber, string department, Year year)
{
	this-> name = name;
	this-> idNumber = idNumber;
	this-> department = department;
	this-> year = year;
}
//constructor that takes 2 parameters
Student::Student(Name name, int idNumber)
{
	Year year = Freshman;
	this-> name = name;
	this-> idNumber = idNumber;
	department = "";
	this-> year = year;
}
//default constructor
Student::Student()
{
	Year year = Freshman;
	name.firstName = "";
	name.lastName = "";
	idNumber = 0;
	department = "";
	this-> year = year;
}

