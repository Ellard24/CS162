#include "space.h"
#include <iostream>
using namespace std;

/****************************************************************************
**Function: space default constructor
**Description: -
**Parameters:-
**Pre-Conditions:-
**Post-Conditions:-
******************************************************************************/
space::space()
{
	
	

}


/****************************************************************************
**Function: space constructor
**Description: abstract class 
**Parameters: string name1, int room
**Pre-Conditions:-
**Post-Conditions:-
******************************************************************************/
space::space(string name1, int room)
{

	roomName = name1;


}


/****************************************************************************
**Function: returnNorth
**Description: Returns value for North
**Parameters: -
**Pre-Conditions: North needs to point towards something
**Post-Conditions: Rooms can be changed
******************************************************************************/
space *space::returnNorth()
{

	return north;


}


/****************************************************************************
**Function: returnSouth
**Description: Returns value for South
**Parameters:-
**Pre-Conditions: South needs to point towards something
**Post-Conditions: Rooms can be changed
******************************************************************************/
space *space::returnSouth()
{

	return south;

}



/****************************************************************************
**Function: returnEast
**Description: Returns value for East
**Parameters:-
**Pre-Conditions: East needs to point towards something
**Post-Conditions: Rooms can be changed
******************************************************************************/
space *space::returnEast()
{

	return east;

}


/****************************************************************************
**Function: returnWest
**Description: Returns value for west
**Parameters: -
**Pre-Conditions: West needs to point towards something
**Post-Conditions: Rooms can be changed
******************************************************************************/
space *space::returnWest()
{

	return west; 

}


/****************************************************************************
**Function: setNorth
**Description: Sets value for north 
**Parameters: space *room
**Pre-Conditions:  room pointed to needs to exist
**Post-Conditions: rooms can be changed
******************************************************************************/
void space::setNorth(space *room)
{
	north = room;

}

/****************************************************************************
**Function: setEast
**Description: Sets value for East
**Parameters: space *room
**Pre-Conditions: room pointed to needs to exist
**Post-Conditions: rooms can be changed
******************************************************************************/
void space::setEast(space *room)
{
	east = room;


}


/****************************************************************************
**Function: setSouth
**Description: Sets value for South
**Parameters: space *room
**Pre-Conditions: rooms pointed to needs to exist
**Post-Conditions: rooms can be changed
******************************************************************************/
void space::setSouth(space *room)
{
	south = room;
	
}

/****************************************************************************
**Function:setWest
**Description: Sets value for West
**Parameters: space *room
**Pre-Conditions: rooms pointed to needs to exist
**Post-Conditions: rooms can be changed
******************************************************************************/
void space::setWest(space *room)
{
	west = room;

}


/****************************************************************************
**Function: setDirections
**Description:Uses setNorth,setSouth,setEast,setWest to set directions
**Parameters: space *room, *room2, *room3, *room4
**Pre-Conditions: rooms need to exist
**Post-Conditions: rooms can be changed
******************************************************************************/
void space::setDirections(space *room, space *room2, space *room3, space *room4)
{
	setNorth(room);
	setSouth(room2);
	setEast(room3);
	setWest(room4);





}


/****************************************************************************
**Function: returnRoomName
**Description: Return room's name
**Parameters:-
**Pre-Conditions: room needs to exist
**Post-Conditions: rooms can be changed or manipulated
******************************************************************************/
string space::returnRoomName()
{

	return roomName;



}


/****************************************************************************
**Function:checkDirection
**Description: Checks rooms around what room you are in
**Parameters:int x
**Pre-Conditions: Room needs to be pointed towards other rooms
**Post-Conditions: rooms can be changed or manipulated
******************************************************************************/
void space::checkDirection(int x)
{
	if (x == 1)
	{
		if (returnNorth() != 0)
		{
			cout << "There appears to be a door" << endl;
			cout << returnNorth()->returnRoomName() << endl;

		}
		
		else
			cout << "This is a wall" << endl;

	}

	if (x == 2)
	{
		if (returnSouth() != 0)
		{
			cout << "There appears to be a door" << endl;
			cout << returnSouth()->returnRoomName() << endl;
		}
		else
			cout << "This is a wall" << endl;

	}

	if (x == 3)
	{
		if (returnEast() != 0)
		{
			cout << "There appears to be a door" << endl;
			cout << returnEast()->returnRoomName() << endl;
		}
		else
			cout << "This is a wall" << endl;

	}

	if (x == 4)
	{
		if (returnWest() != 0)
		{
			cout << "There appears to be a door" << endl;
			cout << returnWest()->returnRoomName() << endl;
		}	
		else
			cout << "This is a wall" << endl;

	}



}


/****************************************************************************
**Function: changeRoom
**Description: Lets player change rooms
**Parameters: space **player
**Pre-Conditions: rooms need to exist
**Post-Conditions: player can continue to change rooms
******************************************************************************/
void space::changeRoom(space **player)
{
	int direction = 0;

	
	
	cout << "************************" << endl;
	cout << "1.)North" << endl;
	cout << "2.)South" << endl;
	cout << "3.)East" << endl;
	cout << "4.)West" << endl;
	cout << "************************" << endl;

	cin >> direction;


	switch (direction)
	{
	case 1:
		if ((*player)->returnNorth() == 0)
			cout << "You walk into a wall." << endl;
		else
		{
			if (door1 == true)
			{
				cout << "You walk into " << (*player)->returnNorth()->returnRoomName() << endl;
				(*player) = (*player)->returnNorth();
			}
			else
			{
				cout << "A locked door blocks your way" << endl;
			}
		}
		break;
	case 2:
		if ((*player)->returnSouth() == 0)
			cout << "You walk into a wall" << endl;
		else
		{
			if (door1 == true)
			{
				cout << "You walk into " << (*player)->returnSouth()->returnRoomName() << endl;
				(*player) = (*player)->returnSouth();
			}
			else
				cout << "A locked door blocks your way" << endl;
		}
		break;
	case 3:
		if ((*player)->returnEast() == 0)
			cout << "You walk into a wall." << endl;
		else
		{
			if (door1 == true)
			{
				cout << "You walk into " << (*player)->returnEast()->returnRoomName() << endl;
				(*player) = (*player)->returnEast();
			}
			else if (roomID == 16)
			{
				cout << "You walk into " << (*player)->returnEast()->returnRoomName() << endl;
				(*player) = (*player)->returnEast();
			}
			else
				cout << "A locked door blocks your way" << endl;
		}
		break;
	case 4:
		if ((*player)->returnWest() == 0)
			cout << "You walk into a wall" << endl;
		else
		{
			if (door1 == true)
			{
				cout << "You walk into " << (*player)->returnWest()->returnRoomName() << endl;
				(*player) = (*player)->returnWest();
			}
			else if (roomID == 16)
			{
				cout << "You walk into " << (*player)->returnWest()->returnRoomName() << endl;
				(*player) = (*player)->returnWest();
			}
			else
				cout << "A locked door blocks your way" << endl;
		}
		break;
	}




}



/****************************************************************************
**Function: doorCheck
**Description: Sets door1 to true
**Parameters: -
**Pre-Conditions: Room needs to exist
**Post-Conditions: Player can walk through open doors
******************************************************************************/
void space::doorCheck()
{


	door1 = true;


}


/****************************************************************************
**Function: getBedKey
**Description: Returns value for bedkey
**Parameters:-
**Pre-Conditions: Room needs to exist
**Post-Conditions: Keys can be acquired
******************************************************************************/
bool space::getBedKey()
{

	return bedKey;


}


/****************************************************************************
**Function: setBedKey
**Description: Sets bedKey to false. Stops multiple keys being made
**Parameters:-
**Pre-Conditions: room needs to exist
**Post-Conditions: Final door can be opened with keys
******************************************************************************/
void space::setBedKey()
{

	bedKey = false;


}


/****************************************************************************
**Function: getGardenKey
**Description: Returns value for gardenKey
**Parameters: -
**Pre-Conditions: Room needs to exist
**Post-Conditions: Final door can be opened with keys
******************************************************************************/
bool space::getGardenKey()
{
	return gardenKey;
}


/****************************************************************************
**Function: setGardenKey
**Description: Sets gardenKey to false
**Parameters: -
**Pre-Conditions: Room needs to exist
**Post-Conditions: Final room can be opened with keys
******************************************************************************/
void space::setGardenKey()
{

	gardenKey = false;
}


/****************************************************************************
**Function: getDiningKey
**Description: Returns value for DiningKey
**Parameters:-
**Pre-Conditions: Room needs to exist
**Post-Conditions: Final room can be opened with keys
******************************************************************************/
bool space::getDiningKey()
{
	return diningKey;

}


/****************************************************************************
**Function: setDiningKey
**Description: sets diningKey to false
**Parameters: -
**Pre-Conditions: Room needs to exist
**Post-Conditions: Final room can be opened with keys
******************************************************************************/
void space::setDiningKey()
{

	diningKey = false;

}



/****************************************************************************
**Function: getFinalTest
**Description: Returns value for finalTest
**Parameters: -
**Pre-Conditions: Room needs to exist
**Post-Conditions: Laboratory puzzle can be attempted
******************************************************************************/
bool space::getFinalTest()
{

	return finalTest;


}



/****************************************************************************
**Function: setFinalTest
**Description: Sets finalTest to true if false 
**Parameters: -
**Pre-Conditions: Room needs to exist
**Post-Conditions: Puzzle can be attempted
******************************************************************************/
void space::setFinalTest()
{

	if (finalTest == false)
		finalTest = true;


}


/****************************************************************************
**Function: getPotion
**Description: Returns value for potion
**Parameters: -
**Pre-Conditions: Item Potion needs to exist
**Post-Conditions: Final sequence of game can be won
******************************************************************************/
bool space::getPotion()
{

	return potion;

}


/****************************************************************************
**Function: setPotion
**Description: Sets potion to false for all rooms besides room 17
**Parameters:- 
**Pre-Conditions: Potion needs to exist
**Post-Conditions: Game can be won
******************************************************************************/
void space::setPotion()
{
	potion = false;

	if (roomID == 17)
		potion = true;

}


/****************************************************************************
**Function: getVictory
**Description: Returns value for victory
**Parameters: -
**Pre-Conditions: Room needs to exist
**Post-Conditions: Winning conditions can fulfilled
******************************************************************************/
bool space::getVictory()
{

	return victory;

}


/****************************************************************************
**Function: setVictory
**Description: Sets the victory data member to true
**Parameters:-
**Pre-Conditions: Room needs to exist
**Post-Conditions: Winning conditions can be fulfilled
******************************************************************************/
void space::setVictory()
{

	victory = true;

}