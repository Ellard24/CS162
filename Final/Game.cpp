#include "Game.h"

#include <iostream>
using namespace std;



/****************************************************************************
**Function: Game default constructor
**Description: Sets sanity level and moveMade
**Parameters: -
**Pre-Conditions: -
**Post-Conditions: Game can start
******************************************************************************/
Game::Game()
{

	sanity = 75;
	moveMade = true;

}



/****************************************************************************
**Function: readInstructions
**Description: Reads the basic instructions to the user at the beginning of game
**Parameters:-
**Pre-Conditions: Game must exist
**Post-Conditions: Movement can begin 
******************************************************************************/
void Game::readInstructions()
{
	cout << "You wake up on the floor in a house you are unfamiliar with" << endl;
	cout << "The door behind you has been covered with bricks and no one seems to be around" << endl;
	cout << "The objective of this game is to explore the house and find a way out" << endl;
	cout << "Be warned, however. If you take too long, you might just lose yourself" << endl;
	
	cout << endl;
	cout << endl;
	


}


/****************************************************************************
**Function:displaySanity
**Description: Displays current sanity level
**Parameters:-
**Pre-Conditions: Game must exist
**Post-Conditions: User can decide next action
******************************************************************************/
void Game::displaySanity()
{


	cout << "Sanity is currently at: " << sanity << endl;



}


/****************************************************************************
**Function: decreaseSanity
**Description: Decreases the sanity level
**Parameters:-
**Pre-Conditions: Game must exist
**Post-Conditions: User can set next action
******************************************************************************/
void Game::decreaseSanity()
{

	sanity--;


}


/****************************************************************************
**Function: showMenu
**Description: Displays options to user
**Parameters:-
**Pre-Conditions: Game must exist
**Post-Conditions: User can decide what to do next
******************************************************************************/
void Game::showMenu()
{
	

	cout << "************************" << endl;
	cout << "1.)Check Directions" << endl;
	cout << "2.)Move in a direction" << endl;
	cout << "3.)Check the Room" << endl;
	cout << "4.)Display Sanity level" << endl;
	cout << "5.)Check inventory" << endl;
	cout << "************************" << endl;
	
	
	
}



/****************************************************************************
**Function: displayDirections
**Description: Displays directions to user
**Parameters:-
**Pre-Conditions: Game must exist
**Post-Conditions: user can decide what direction to go
******************************************************************************/
int Game::displayDirections()
{
	int direction = 0;
	
	cout << "************************" << endl;
	cout << "1.)North" << endl;
	cout << "2.)South" << endl;
	cout << "3.)East" << endl;
	cout << "4.)West" << endl;
	cout << "************************" << endl;

	cin >> direction;


	return direction;

}


/****************************************************************************
**Function:getSanity
**Description: Returns value of sanity
**Parameters:-
**Pre-Conditions: Game must exist
**Post-Conditions: -
******************************************************************************/
int Game::getSanity()
{

	return sanity;

}

/****************************************************************************
**Function: getMoveMade
**Description: Returns value of moveMade
**Parameters:-
**Pre-Conditions: Game must exist 
**Post-Conditions: Sanity is decreased if move is made
******************************************************************************/
bool Game::getMoveMade()
{

	return moveMade;

}


/****************************************************************************
**Function: setMoveMade
**Description: Sets the moveMade data member 
**Parameters: -
**Pre-Conditions: Game must exist 
**Post-Conditions: Sanity is decreased based on move Made
******************************************************************************/
void Game::setMoveMade()
{

	if (moveMade == true)
		moveMade = false;
	else
		moveMade = true;


}
