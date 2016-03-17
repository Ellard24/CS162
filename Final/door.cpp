#include "door.h"
#include <iostream>
using namespace std;


/****************************************************************************
**Function: door constructor
**Description: Sets roomName, roomID, door1, and keycheck
**Parameters: string name1, int room
**Pre-Conditions: -
**Post-Conditions: door room can be used and traversed
******************************************************************************/
door::door(string name1, int room)
{

	roomName = name1;
	roomID = room;
	door1 = false;
	keyCheck = false;
}


/****************************************************************************
**Function: door default constructor
**Description:-
**Parameters:-
**Pre-Conditions:-
**Post-Conditions:-
******************************************************************************/
door::door()
{

	




}


/****************************************************************************
**Function:checkRoom
**Description: Gives user option to get description of room or look around
**Parameters:-
**Pre-Conditions: door must exist
**Post-Conditions: final room can be accessed if all three keys are on user
******************************************************************************/
void door::checkRoom()
{
	//give the option to check for three keys
	// if three keys in inventory->door opens
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
	
		cout << "You see three key holes in the door" << endl;

	
		string doorChoice;

		cout << "Try to open the door?" << endl;
		cin >> doorChoice;

		if (doorChoice == "yes")
		{
			
			
			
			//check for keys
			if (keyCheck == true)
			{
				door1 = true;
				cout << "The door becomes unlocked" << endl;
			}
			else
				cout << "Some keys might be useful" << endl;
		}
		
	
	}

}


/****************************************************************************
**Function: description
**Description: Gives description of current room
**Parameters: -
**Pre-Conditions: door must exist
**Post-Conditions:-
******************************************************************************/
void door::description()
{
	cout << "There appears to be a large door in this room" << endl;
	cout << "Something tells you that this must be where you need to go" << endl;
	cout << "You see three key holes in the door" << endl;



}


/****************************************************************************
**Function: getKeys
**Description: sets keyCheck to to true
**Parameters: -
**Pre-Conditions: Keys must be on user
**Post-Conditions: Door can be opened
******************************************************************************/
void door::getKeys()
{
	keyCheck = true;

}