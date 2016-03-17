#include "garden.h"
#include <iostream>
using namespace std;

/****************************************************************************
**Function: garden constructor
**Description: Sets roomName, roomID, door1, and gardenKey
**Parameters: string name1, int room
**Pre-Conditions: Garden needs to exist
**Post-Conditions: Garden can be traversed and interacted with
******************************************************************************/
garden::garden(string name1, int room)
{

	roomName = name1;
	roomID = room;
	door1 = true;
	gardenKey = false;
	plantCheck = 0;
}

/****************************************************************************
**Function: garden default constructor
**Description:-
**Parameters:-
**Pre-Conditions:-
**Post-Conditions:-
******************************************************************************/
garden::garden()
{


	door1 = false;


}

/****************************************************************************
**Function:checkRoom()
**Description: Gives user option to get description of room or look around
**Parameters:-
**Pre-Conditions: Garden must exist
**Post-Conditions: Puzzle can be done 
******************************************************************************/
void garden::checkRoom()
{

	int choice = 0;

	cout << "**************" << endl;
	cout << "1.) Description" << endl;
	cout << "2.) Look around" << endl;
	cout << "**************" << endl;

	cin >> choice;

	if (choice == 1)
		description();
	if (choice == 2)
	{
		string plant;
		cout << "The strange looking plant seems to follow you as you move around the room" << endl;
		cout << "Do you want to approach it?" << endl;

		cin >> plant;

		if (plant == "yes" && plantCheck != 1)
		{
			cout << "Suddenly you feel your body trapped by ivy" << endl;
			cout << "The plant pulls you close" << endl;
			cout << "If you guess the number I am thinking of, I might just help you" << endl;
			puzzle();
		}
		else
		{
			cout << "Lets not do that again" << endl;

		}
	}
	


}


/****************************************************************************
**Function:description
**Description: Gives description of room to user
**Parameters:-
**Pre-Conditions: Garden must exist
**Post-Conditions: -
******************************************************************************/
void garden::description()
{
	cout << "You find yourself outside" << endl;
	cout << " A canopy of luminous stars materialized amongst the ocean of blackness." << endl;
	cout << "The garden is filled with a variety of different plants" << endl;
	cout << "Carefully hidden in the back is a certain plant that seems to pull you in" << endl;
	cout << "Maybe it's worth looking at" << endl;




}


/****************************************************************************
**Function: puzzle
**Description: Prompts user with puzzle to solve
**Parameters:-
**Pre-Conditions: Garden needs to exist
**Post-Conditions: Key can be acquired 
******************************************************************************/
void garden::puzzle()
{

	int n = 8;
	int g = 0;
	cout << "I'm thinking of a number between 1 and 10.\nTry to guess it! ";
	while (g != n)
	{
		cin >> g;
		if (g == n)
		{
			cout << "You've guessed my number. You passed my test" << endl;
			cout << "I will aid you in your quest. Here is a silvery thing" << endl;
			cout << "You receive a key" << endl;
			
		}
		else
			cout << "That's not my number.\nTry another guess! ";
	}

	gardenKey = true;
	plantCheck = 1;
}