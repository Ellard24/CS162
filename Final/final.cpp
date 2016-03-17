#include "final.h"
#include <iostream>
using namespace std;



/****************************************************************************
**Function: finalRoom constructor
**Description: Sets roomName, roomID, door1, finalTest, victory
**Parameters: string name1, int room
**Pre-Conditions: -
**Post-Conditions: finalRoom can be accessed and traversed
******************************************************************************/
finalRoom::finalRoom(string name1, int room)
{

	roomName = name1;
	roomID = room;
	door1 = true;
	finalTest = false;
	victory = false;
}



/****************************************************************************
**Function:finalRoom default constructor
**Description:
**Parameters:
**Pre-Conditions:
**Post-Conditions:
******************************************************************************/
finalRoom::finalRoom()
{


	door1 = false;


}


/****************************************************************************
**Function: checkRoom
**Description:Gives user option to get description of room or look around
**Parameters:-
**Pre-Conditions: finalRoom must exist
**Post-Conditions: user can finish the game 
******************************************************************************/
void finalRoom::checkRoom()
{
	int choice = 0;

	cout << "**************" << endl;
	cout << "1.) Description" << endl;
	cout << "2.) Approach " << endl;
	cout << "**************" << endl;

	cin >> choice;

	if (choice == 1)
		description();
	if (choice == 2)
	{
		if (potion == false)
		{
			cout << "The man screams for your help" << endl;
			cout << "You can see a light come from an open door in the back" << endl;
			cout << "The man always appears to be holding something in his hands" << endl;
			cout << endl << endl << endl;


			string answer;

			cout << "Help the man? If not, you will head towards the door" << endl;
			cout << endl << endl << endl;

			cin >> answer;

			if (answer == "yes")
				lastTest();
			else
			{
				cout << "You've had enough of this place and sprint towards the door" << endl;
				cout << "Suddenly the room is enveloped in darkness and the door disappears" << endl;
				cout << "Maybe the man can help" << endl;
				cout << endl << endl << endl;


			}

		}

		else
		{
			cout << "You hand the potion over to the man but he refuses to take it" << endl;
			cout << "With his dying breath he signals for you to take it" << endl;
			cout << "You drink the potion" << endl;
			
			cout << endl << endl << endl;


			victory = true;



		}
		

	}




}


/****************************************************************************
**Function: description
**Description:Gives description of room to the user
**Parameters: -
**Pre-Conditions: finalRoom must exist
**Post-Conditions:
******************************************************************************/
void finalRoom::description()
{
	cout << "In the middle of the room you spot a hunched over man" << endl;
	cout << "Something appears wrong with him " << endl;



}



/****************************************************************************
**Function: lastTest
**Description: Gives user text based instructions on a puzzle 
**Parameters: -
**Pre-Conditions: finalRoom must exist
**Post-Conditions: Laboratory puzzle can be accessed
******************************************************************************/
void finalRoom::lastTest()
{
	cout << "You approach the man. He is clearly in too much pain too talk" << endl;
	cout << "He grudgingly handles over a piece of paper in his hands" << endl;
	cout << "It contains instructions regarding the laboratory" << endl;
	cout << "It's time to head back that way" << endl;

	finalTest = true;

}