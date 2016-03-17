/**************************************
** Program Filename: Lab4.cpp
** Author: Ellard Gerritsen van der Hoop 
** Date: 10/22/15
** Input: All input comes during runtime
** Output: String is reversed and shown to screen
**		   Array is summed up and shown to screen
**		   Total items in triangular number is 
**         added up and shown to screen
********************************************/

#include <iostream>
#include <string>
using namespace std;

int sumArray(int array2[], int numbers);
void revString2(string choice2);
int triNum(int row, int sum);

/**********************************************
**Function: Main
**Description: Menu based main function that allows 
				user to decide what they want to do
				and displays the results
**Parameters:-
**Pre-Conditions: -
**Post-Conditions: Displays result of functions
***********************************************/


int main()
{
	
	int answer = 0;
	string choice = "yes";
	int numbers;
	cout << "There are Three Different Options to choose" << endl;
	cout << "1.) Reverses a String " << endl;
	cout << "2.) Sums all numbers in an array" << endl;
	cout << "3.) Calculates trianglular numbers" << endl;
	cout << "4.) Exits Program" << endl;

	
	
	while (choice == "yes")
	{
		cout << "Please make your selection now" << endl;
		cin >> answer;


		if (answer == 1)
		{
			string choice2;
			
			cout << "Please input a string that you wish to have reversed" << endl;
			cin >> choice2;

			revString2(choice2);
			cout << endl;

		}



		if (answer == 2)
		{
			cout << "How many numbers do you want?" << endl;
			cin >> numbers;
			int *array2 = new int[numbers];
			
			cout << "Please enter " << numbers << " numbers you want to enter. Press enter after each one" << endl;
			for (int i = 0; i < numbers; i++)
				cin >> array2[i];
		
			cout << sumArray(array2, numbers) << endl;
			
			delete[] array2;
		}


		if (answer == 3)
		{
			int rows;
			int sum = 0;
			cout << "How many rows do you want?" << endl;
			cin >> rows;
			cout << triNum(rows, sum) << endl;




		}


		if (answer == 4)
		{
			cout << " Program is ending. Goodbye :) " << endl;
			return 0;
		
		}

		cout << "Do you want to make another selection?" << endl;
		cin >> choice;

	}
	
	return 0;
}

/**********************************************
**Function: sumArray
**Description: Sums up all values input by user into
			  an array
**Parameters: int array2[], int numbers
**Pre-Conditions: User must input total numbers wanted
				 and value of each item
**Post-Conditions: Array is summed up and displayed
***********************************************/

int sumArray(int array2[], int numbers)
{
		
	if (numbers == 0)
	{
		cout << "Summing up Numbers" << endl;
		return 0;
	}
	else
	{
		int total = array2[0] + sumArray(array2 + 1, numbers - 1);
		return total;
	}

}

/**********************************************
**Function: revString2
**Description: Reverses a string input by user 
			 and displays to screen
**Parameters: string choice2
**Pre-Conditions: String must be input by user
**Post-Conditions: String is reversed and displayed
***********************************************/
void revString2(string choice2)
{

	int wlength = choice2.length();

	if (wlength != 0)
	{
		cout << choice2[wlength - 1];

	//	choice2.pop_back(); Apparenty flip doesnt recognize this
		string temp = choice2.substr(0, wlength - 1);
		revString2(temp);
	}
	else
		cout << choice2;
}

/**********************************************
**Function:triNum
**Description: The function calculates the total number 
				of items based on row input by user
**Parameters: int rows, int sum
**Pre-Conditions: Sum needs to be initialized to 0
				  User needs to put in amount of rows
**Post-Conditions: Sum is calculated and displayed to screen
*********************************************************/

int triNum(int rows, int sum)
{
	
	if (rows > 0)
	{
		sum = sum + rows;
		triNum(rows - 1, sum);

	}
	else
		return sum;

}
