//============================================================================
// Name        : Character.cpp
// Author      : Tim Kuelker
// Description : Program that asks user for amount of randomly generated letters,
//				 and reverses it.
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

void showArray(char *);
void reverseArray(char *);

int main() {
	int numb;
	char *arrayptr = nullptr;
	string rerun;
	
	do {
		
		cout << "Enter the number of randomized letters\nyou would like to generate: \n";
		cin >> numb;
		cout << endl;

		if(numb <= 0) {
			cout << "You did not put in a proper number, good job!\n\n";
			return 0;
		}

		else {

			arrayptr = new char [numb + 1];					//dynamically allocating
			arrayptr[numb] = '\0';							//making sure there is null

			unsigned seed = time(0);						//declaring seed
			srand(seed);

			for(int count = 0; count < numb; count++)
				arrayptr[count] = 97 + (rand() % 26);		//randomly assigning number between 97 & 122, ascii a-z

			showArray(arrayptr);
			cout << endl;

			reverseArray(arrayptr);

			showArray(arrayptr);
			cout << endl << endl;

			cout << "Enter <y,Y> if you would like to rerun the program.\n";
			cin >> rerun;
			cout << endl << endl;

			delete [] arrayptr;
		}
	} while(rerun == "y" || rerun == "Y");

	cout << "Thanks for using my program!";

	return 0;
}


void showArray(char *arr) {
	while(*arr != '\0')	{				//using while loop to stop array at end
		cout << *arr << " ";
		arr++;
	}
}


void reverseArray(char *arr) {
	int length = 0;

	for(int i = 0; *(arr + i) != '\0'; i++)		//finding length of array with
		length++;

	char *arstart = arr;							//pointer for start of array
	char *arend = (arstart + length -1);			//pointer for end of array

	while (arend > arstart) {
		char temp = *arstart;		//beginning of swapping
		*arstart = *arend;
		*arend = temp;

		arstart++;
		arend--;
	}
}
