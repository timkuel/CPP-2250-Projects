/*
 * Student.h
 *
 *      Author: Tim Kuelker
 */

#include <string>

#ifndef STUDENT_H_
#define STUDENT_H_

using namespace std;
														//making structure to hold first and last name
	struct Name
	{
		string firstName;
		string lastName;
	};
														//making year an enum, declaring freshman as 1
	enum Year {Freshman = 1, Sophomore, Junior, Senior};

class Student
{
														//declaring private members
	private:
		Name name;
		int idNumber;
		string department;
		Year year;
														//declaring public members
	public:
		Student(Name name, int idNumber, string department, Year year);
		Student(Name name, int idNumber);
		Student();

														//Setters/Mutators
		void setName(Name name) {this-> name = name;}
		void setidNumber(int idNumber) {this-> idNumber = idNumber;}
		void setDepartment(string department) {this-> department = department;}
		void setYear(Year year) {this-> year = year;}

														//Getters/Accessors
		Name getName() const {return name;}
		int getidNumber() const {return idNumber;}
		string getDepartment() const {return department;}
		Year getYear() const {return year;}

};


#endif /* STUDENT_H_ */

