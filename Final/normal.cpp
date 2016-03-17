#include "normal.h"
#include <iostream>
using namespace std;



/****************************************************************************
**Function:Normal constructor
**Description: Sets roomName, roomID, door1
**Parameters: string name1, int room
**Pre-Conditions: -
**Post-Conditions: normal room can be traversed
******************************************************************************/

normal::normal(string name1, int room) 
{

	roomName = name1;
	roomID = room;
	door1 = true;
	dining = 0;
}


/****************************************************************************
**Function: normal default constructor
**Description: -
**Parameters:-
**Pre-Conditions:-
**Post-Conditions:-
******************************************************************************/
normal::normal()
{

	door1 = false;

}

/****************************************************************************
**Function: checkRoom
**Description: Gives the user the option of getting a description or to look around
**Parameters:-
**Pre-Conditions: Normal room needs to exist
**Post-Conditions: Room can be interacted with
******************************************************************************/
void normal::checkRoom()
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
		if (roomID == 1)
		{
			string answer;

			cout << "Approach the sign?" << endl;
			cin >> answer;


			if (answer == "yes")
			{
				cout << endl;
				cout << endl;
				cout << "If you are reading this, well...welcome? " << endl;
				cout << "There are many rooms to this mansion" << endl;
				cout << "The hallways might be locked and might try to trick you" << endl;
				cout << "Be on the lookout for certain 'key' items. Ya, that's a pun ;) " << endl;
				cout << "Oh....and keep track of that sanity. " << endl;
				cout << "Signed, Mysterious Stranger" << endl;
				cout << endl << endl;

			}

		}
		
		else if (roomID == 3)
		{
			string answer;
			cout << "Do you want to reach your hand in?" << endl;
			cin >> answer;
			if (answer == "yes" && dining != 1)
			{
				cout << "Do you REALLY want to reach your hand in?" << endl;
				cin >> answer;
				if (answer == "yes")
				{
					cout << "Really? Like come on man. That's really gross " << endl;
					cout << "Last chance to turn back. Reach hand in?" << endl;
					cin >> answer;
					if (answer == "yes")
					{
						cout << "You pull out a nasty, slimy key and feel really really repulsed with yourself :(" << endl;
						diningKey = true;
						cout << endl;
						dining = 1;
					}
				}
			}
			else
			{
				cout << "Lets not do that again" << endl;    
			}
		
		}
		else if (roomID == 6)
		{
			string answer;
			cout << "Pick up letter? " << endl;
			cin >> answer;

			if (answer == "yes")
			{
				cout << "So I guess you started exploring a little bit by now" << endl;
				cout << "Hopefully the hallways haven't caused too much trouble" << endl;
				cout << "Maybe you even came across something useful" << endl;
				cout << "If you haven't, clearly you should retrace your steps" << endl;
				cout << "Signed, Mysterious Stranger" << endl;

			}

		}
		else if (roomID == 7)
		{
			string answer;
			cout << "Approach lab bench?" << endl;
			cin >> answer;
			

			if (answer == "yes" && finalTest == true)
			{
				cout << "You see a whole bunch of different potions in front of you" << endl;
				cout << "Maybe it's time to read the paper the man gave?Read paper?" << endl;
				cin >> answer;

				if (answer == "yes")
					labTest();

			}
			else if (answer == "yes")
			{
				cout << "You see a whole bunch of different ingredients and potions in front of you" << endl;
				cout << "Without knowledge of what they are though, you decide to turn back for now" << endl;
			}

		}

		else
			cout << "There appears to be nothing hidden" << endl;
			
	}
}

/****************************************************************************
**Function: description
**Description: Gives user description of room
**Parameters:-
**Pre-Conditions: normal needs to exist
**Post-Conditions: User can perform further actions
******************************************************************************/
void normal::description()
{
	if (roomID == 1)
	{
	
		cout << "This is the room you started out in" << endl;
		cout << "You can't turn back so your only option is to move forwards" << endl;
		cout << "There appears to be a sign in the corner" << endl;
		cout << endl;
		
		

	}

	if (roomID == 3)
	{
		cout << "This appears to be a dining hall" << endl;
		cout << "Remnants of decaying food can still be seen on the table" << endl;
		cout << "Something is glimmering from inside what could be called a turkey" << endl;
		cout << endl;
	}

	if (roomID == 6)
	{
		cout << "Looks like a living room that was enveloped in dust" << endl;
		cout << "Probably not a good idea to sit on anything here" << endl;
		cout << "There appears to be letter on the coffee table" << endl;

	}

	if (roomID == 7)
	{
		cout << "A bunch of lab equipment sits in this room" << endl;
		cout << "Strangely enough it seems as though it has been used recently" << endl;
		cout << "Maybe this can be of use later" << endl;


	}

	if (roomID == 11)
	{
		cout << "As you walked in the door, a cloud of dust spreads over you" << endl;
		cout << "Insects have claimed the kitchen as their own" << endl;
		cout << "The sink looked moldy and black" << endl;
		cout << "Maybe this is not a good time to be hungry" << endl;
	}
}

/****************************************************************************
**Function: labTest
**Description: Prompts user to solve a puzzle 
**Parameters:-
**Pre-Conditions: Normal room must exist
**Post-Conditions: Potion can be acquired
******************************************************************************/
void normal::labTest()
{
	cout << "In front of you, you see 5 potions: Orange, Green, Red, Yellow, Blue" << endl;
	cout << "You read the paper to figure out what the old man was trying to ask of you" << endl;
	cout << "Blue must be added before Green" << endl;
	cout << "Red must not be added right before yellow and never after yellow" << endl;
	cout << "Yellow can be added as long as long two additional potions are between it and blue" << endl;
	cout << "Orange is the last potion" << endl;

	cout << "What is the order you want to mix them in?Type one in at a time and hit enter " << endl;
	cout << "Use lowercase for all letters" << endl;
	string potion1, potion2, potion3, potion4, potion5;

	cin >> potion1 >> potion2 >> potion3 >> potion4 >> potion5;

	if (potion1 == "blue" && potion2 == "red" && potion3 == "green" && potion4 == "yellow" && potion5 == "orange")
	{
		cout << "You hear a fizzing sound and see small cloud of smoke rise then settle" << endl;
		cout << "You take the potion" << endl;
		cout << "Maybe its time to head back to that man" << endl;
		potion = true;
	}
	else
	{
		cout << "The potion mixes and then combusts on the spot" << endl;
		cout << "Maybe that was the wrong order" << endl;

	}






}