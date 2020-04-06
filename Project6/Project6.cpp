//============================================================================
// Name        : HW6.cpp
// Author      : Tim
// Description : Program that check if a user inputs a properly
// nested set of parentheses '()', braces '{}', or brackets '[]' and ignores
// other characters inserted within parentheses, braces, or brackets.
//============================================================================

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool IsBalanced(char );
bool IsOpen(char );
bool IsClosed(char );
bool Matches(char , char);

int main() {
	char input;
	string ans;

	do{
		cout << "Input parentheses (), braces {} or brackets []\nto check if they are properly nested: ";
		cin.get(input);

		if (IsBalanced(input))													//if balanced and starts with opening parentheses, brace, or bracket
			cout << "\nParentheses/Braces/Brackets are nested properly\n\n";
		else
			cout << "\nParentheses/Braces/Brackets are NOT nested properly\n\n";

		cout << "Would you like to test again? <Yes(y),No(n)> : ";
		getline(cin, ans);
		cout << endl << endl;
	}
	while(ans == "y" || ans == "Y" || ans == "yes" || ans == "Yes");

	if(ans == "n" || ans == "N" || ans == "no" || ans == "No")
		cout << "Thank you for using my program!!";

	else
		cout << "User entered unidentified answer, program terminating!";

	return 0;
}

bool IsBalanced(char input)
{
	stack< char > cStack;										//Initializing stack
	char openInput;
	bool balanced = true, flag = true;							//Initializing flags

	if(input != '(' && input != '{' && input != '[')			//making sure initial input contains opening parentheses, brace, or bracket
	{
		cout << "\nYou need to begin with 'OPEN' parentheses, brace or bracket!\n";
		balanced = false;
	}

	while(input != '\n' && balanced)
	{
		if (IsOpen(input))										//pushing stack if open parentheses, brace, or bracket
		{
			cStack.push(input);
		}
		else if (IsClosed(input))								//Checking if close parentheses, brace, or bracket
		{
			if (cStack.empty())
				balanced = false;
			else												//comparing current top of stack to current close parentheses, brace, or bracket
			{
				openInput = cStack.top();						//current top of stack
				cStack.pop();
				balanced = Matches(openInput, input);
			}
		}
		cin.get(input);
	}

	while(input != '\n' && flag)							//popping anything left in stack
	{
		cStack.push(input);
		if(cStack.empty())
			flag = false;

		cStack.pop();
		cin.get(input);
	}
	if(!cStack.empty())											//if there is anything left in stack, its not balanced
		balanced = false;

	return(balanced);
}

bool IsOpen(char input)											//checking if opening parentheses, brace, or bracket
{
    if ((input == '(') || (input == '{') || (input == '['))
        return true;
    else
        return false;
}

bool IsClosed(char input)										//checking if closing parentheses, brace, or bracket
{
    if ((input == ')') || (input == '}') || (input == ']'))
        return true;
    else
        return false;
}

bool Matches (char openInput, char input)						//Comparing current top of stack to the first closed parentheses, brace, or bracket
{
	if(openInput == '(' && input == ')') return true;
	else if(openInput == '{' && input == '}') return true;
	else if(openInput == '[' && input == ']') return true;
	else return false;
}

