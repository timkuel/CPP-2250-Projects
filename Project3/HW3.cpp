//============================================================================
// Name        : HW3.cpp
// Author      : Tim Kuelker
//============================================================================

#include "Student.h"
#include <iostream>
#include <iomanip>

void displayStudent(Student);

int main() {

	Name n1, n2, n3, n4;
	//filling names
	n1.firstName = "Johnny";
	n1.lastName = "Appleseed";

	n2.firstName = "Paul";
	n2.lastName = "Bunyan";

	n3.firstName = "John";
	n3.lastName = "Henry";

	n4.firstName = "Pecos";
	n4.lastName = "Bill";
													//filling first student object
	Student s1(n1,101,"Agricultural Engineering",Senior);

	Student s2(n2,202);								//filling 2nd object
		s2.setDepartment("Environmental Science");
		s2.setYear(Junior);

	Student s3;
		s3.setName(n3);								//filling 3rd object
		s3.setidNumber(303);
		s3.setDepartment("Mechanical Engineering");
		s3.setYear(Freshman);

	Student s4;										//filling 4th object
		s4.setName(n4);
		s4.setidNumber(404);
		s4.setDepartment("Meteorology");
		s4.setYear(Sophomore);
													//displaying student objects
	displayStudent(s1);
	displayStudent(s2);
	displayStudent(s3);
	displayStudent(s4);

	return 0;
}


void displayStudent(Student s)
{
	Name temp = s.getName();
	cout << setw(20) << "\nStudent Name      : " << temp.firstName << " " << temp.lastName << endl;
	cout << setw(20) << "Student IDNumber  : " << s.getidNumber() << endl;
	cout << setw(20) << "Student Department: " << s.getDepartment() << endl;
	cout << setw(20) << "Student Year      : " << s.getYear() << endl;
}

