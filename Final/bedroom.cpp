#include "bedroom.h"
#include <iostream>
#include <string>
using namespace std;


/****************************************************************************
**Function: bedroom constructor
**Description: sets roomName,roomID,door1, bedKey
**Parameters: string name1, int room
**Pre-Conditions: -
**Post-Conditions: bedRoom can be used
******************************************************************************/
bedroom::bedroom(string name1, int room)
{
	
	roomName = name1;
	roomID = room;
	door1 = true;
	bedKey = false;
	bedCheck = 0;
}

/****************************************************************************
**Function: bedroom default constructor
**Description:
**Parameters:
**Pre-Conditions:
**Post-Conditions:
******************************************************************************/
bedroom::bedroom()
{

	door1 = false;


}

/****************************************************************************
**Function: checkRoom
**Description:Gives user option to get description of room or look around
**Parameters: -
**Pre-Conditions: bedRoom must exist
**Post-Conditions: User can solve puzzle in room and traverse the room
******************************************************************************/
void bedroom::checkRoom()
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
		string lady;
		cout << "The picture on the wall is of an old lady. The frame looks crooked" << endl;
		cout << "Do you want to fix it?" << endl;

		cin >> lady;

		if (lady == "yes" && bedCheck != 1)
		{
			cout << "Suddenly the picture starts speaking to you" << endl;

			bedPuzzle();
		}
		else
		{
			cout << "Lets not do that again" << endl;
		}
	}

}

/****************************************************************************
**Function: description
**Description: Gives user description of room
**Parameters: -
**Pre-Conditions: bedRoom must exist
**Post-Conditions: -
******************************************************************************/
void bedroom::description()
{

	cout << "A dusty, unused bedroom. Probably hasn't been visisted in decades" << endl;
	cout << "A picture on the wall looks off compared to the rest of the room" << endl;


}


/****************************************************************************
**Function:bedPuzzle
**Description: Gives user a puzzle to solve
**Parameters: -
**Pre-Conditions: bedRoom must exist
**Post-Conditions: key can be earned if puzzle is solved
******************************************************************************/
void bedroom::bedPuzzle()
{
	cout << "Put the following numbers correctly into the equation" << endl;
	cout << "(_ - _ / _ ) x _ = 10   You have the numbers 3,4,7,8 " << endl;
	cout << "Input the answer in the format _,_,_,_ " << endl;

	string answer;

	while (answer != "3,7,4,8")
	{
		cout << "Please guess" << endl;
		cin >> answer;

		if (answer != "3,7,4,8")
			cout << "Wrong answer" << endl;

	}


	cout << "Well done. Now get out of here!" << endl;
	cout << "Here is a key for your efforts" << endl;

	bedKey = true;
	bedCheck = 1;


}