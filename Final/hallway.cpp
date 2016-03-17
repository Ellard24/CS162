#include "hallway.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std; 


/****************************************************************************
**Function: hallway constructor
**Description: Sets roomName, roomID
**Parameters: string name1, int room
**Pre-Conditions: -
**Post-Conditions: Hallway can be traversed
******************************************************************************/
hallway::hallway(string name1, int room)
{

	roomName = name1;
	roomID = room;
	
	if (roomID == 2 || roomID == 9 || roomID == 8 || roomID == 15)
		door1 = false;
	else
		door1 = true;

}


/****************************************************************************
**Function: hallway default constructor
**Description: 
**Parameters:
**Pre-Conditions:
**Post-Conditions:
******************************************************************************/
hallway::hallway()
{

	

}



/****************************************************************************
**Function:CheckRoom
**Description: Allows user to get description or look around
**Parameters:-
**Pre-Conditions: hallway needs to exist
**Post-Conditions: Lever puzzle can be attempted if locked room
******************************************************************************/
void hallway::checkRoom()
{
	int choice = 0;
	srand(time(0));
	cout << "**************" << endl;
	cout << "1.) Description" << endl;
	cout << "2.) Look around" << endl;
	cout << "**************" << endl;

	cin >> choice;

	if (choice == 1)
		description();
	if (choice == 2)
	{


		if (roomID == 2 || roomID == 8 || roomID == 9 || roomID == 15)
		{
			string lever;
			int time1 = rand() % 2 + 1;
			cout << "There are two levers to pick from" << endl;
			cout << "Which one do you want to pull ? left or right " << endl;

			cin >> lever;
			
			if (time1 == 1)
			{
				if (lever == "right")
					cout << "Nothing happens. Maybe try the other?" << endl;
				if (lever == "left")
				{
					cout << "You hear the gate open" << endl;
					door1 = true;
				}
			}
			else
			{
				if (lever == "right")
				{
					cout << "You hear the gate open" << endl;
					door1 = true;
				}
				if (lever == "left")
				{
					cout << "Nothing happens. Maybe try the other?" << endl;
				}
			}
		}
		
		
		
		
		if (roomID == 4 || roomID ==5 || roomID == 14)
			cout << "There is nothing to interact with" << endl;
	}

}



/****************************************************************************
**Function: description
**Description: Gives user description of room
**Parameters:-
**Pre-Conditions: hallway needs to exist
**Post-Conditions: User can perform other actions in room
******************************************************************************/
void hallway::description()
{
	if (roomID == 2 || roomID == 9 || roomID == 8 || roomID == 15)
	{
		cout << "Appears to be a plain hallway" << endl;
		cout << "However, it looks like two levers are placed next to the door" << endl;

	}
	else
	{

		cout << "Just an ordinary hallway" << endl;


	}



}