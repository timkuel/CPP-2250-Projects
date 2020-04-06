//============================================================================
// Name        : Rnd.cpp
// Author      : Timothy Kuelker
// Date		   : June 21, 2018
// Description : Program that populates array with 20 random integers from 1-100
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int *getRandomNumbers (int );
void sortArray (int[], int);
void checkDuplicates (int[], int);
void showArray (int[], int);
int binarySearch(int[], int, int);

const int SIZE = 20;

int main() {
	int numCheck, *numbers;
	string rerun;

	numbers = getRandomNumbers(SIZE);		//getting array

	sortArray(numbers, SIZE);

	checkDuplicates(numbers, SIZE);

	sortArray(numbers, SIZE); 				//resorting in case of a value exceeding 100

	showArray(numbers, SIZE);

	do
	{
	cout << "\n\nType in any number between 1-100\nto check if located in array:\n";
	cin >> numCheck;

	int results = binarySearch (numbers, SIZE, numCheck);

	if (results == -1)
		cout << "That number was not located within\nthe generated array.\n";
	else
	{
		cout << "That number is found at element " << results << "\nin the array.\n\n";
	}
		cout << "Would you like to research the array \nfor another number? <Y,N>\n";
		cin >> rerun;
	}while (rerun == "y" || rerun == "Y");

	cout << "Thanks for using my program!";

	return 0;
}


int *getRandomNumbers(int num)
{
	int *array = nullptr;

	if (num <= 0) 											//return null if num is zero or negative
		return nullptr;

	array = new int [num]; 									//dynamically allocate new array

	srand(time(0)); 										//seeding time
    for(int count = 0; count < (SIZE + 1); count++)			//populating matrix
	array[count] = (rand() % 100) + 1;

    return array;
}


void sortArray( int arr[], int size)
{
	bool swap;
	int temp;

	do
{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (arr[count] > arr[count + 1])				//swapping elements to put in ascending order
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	}
while (swap);
}


void checkDuplicates(int arr[], int SIZE)
{
	for(int i = 0; i < SIZE; i++) 						//entering loop looking for duplicates
	{
		for(int j = (i + 1); j < SIZE; j++)
		{
			if(arr[i] == arr[j])
			{
				arr[j] = arr[j] + 1;					//assigning element new value
				if(arr[j] > 100)
				{
					arr[j] = arr[j] - 7;				//keeping values under 100 (reason for resorting)
				}
			}
		}
	}
}


void showArray(int arr[], int SIZE)
{
    for (int count = 0; count < SIZE; count++)			//displaying the array
			cout << arr[count] << endl;
}


int binarySearch(int arr[], int SIZE, int value)
{
	int first = 0,
		last = SIZE - 1,
		middle,
		posistion = -1; 						//position of search value
	bool found = false; 						//flag

	while (!found && first <= last)
	{
		middle = (first + last)/2; 				//mid point calculation
		if (arr[middle] == value) 				// if value is found at midpoint
		{
			found = true;
			posistion = middle;
		}
		else if (arr[middle] > value) 			// if value is in lower half
			last = middle - 1;
		else
			first = middle + 1;
	}
	return posistion;
}

