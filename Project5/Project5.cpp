//============================================================================
// Name        : HW5.cpp
// Author      : Tim Kuelker
// Description : Example of manipulating a linked list of strings
//============================================================================

#include <iostream>
#include "StringList.h"

using namespace std;

int main() {

	cout << "NOW BEGINNING FILLING OF NODES FOR LINKED LIST\n\n\n";
	StringList s;

	s.insertFront("nodes in front");
	s.display();

	s.insertBack("of or back of");
	s.display();

	s.insertFront("inserting/deleting");
	s.display();

	s.insertBack("a string");
	s.display();

	s.insertFront("example of");
	s.display();

	s.insertBack("linked list");
	s.display();

	s.insertFront("This is an");
	s.display();

	cout << "\n\nTHE FULL STRING IS : "; s.display();			//displaying full string before deleting
	cout << "\n\nNOW DELETING NODES\n\n\n";

	s.deleteBack();
	s.display();

	s.deleteFront();
	s.display();

	s.deleteBack();
	s.display();

	s.deleteFront();
	s.display();

	s.deleteBack();
	s.display();

	s.deleteFront();
	s.display();

	s.deleteBack();
	s.display();

	return 0;
}

