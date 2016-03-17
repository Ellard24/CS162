#include "Die.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

/***********************************************************
** Function: Default Constructor
** Description: Performed when class is created
** Parameters: None
** Pre-Conditions: -
** Post-Conditions:-
**********************************************************/

Die::Die()
{

}

/***********************************************************
** Function: Constructor
** Description:  Constructor that makes sides equal to sides picked by user *
** Parameters: int userSides
** Pre-Conditions: userSides needs to be input 
** Post-Conditions: Number of sides will be determined from userSides
************************************************************/

Die::Die(int userSides)
{
	sides = userSides;
}

/***********************************************************
** Function: rollDie
** Description:  rollDie function that uses a loop to roll the total
**		 number requested by user and then prints number that
**		 were above half the number of sides of the die
** Parameters: int sides, int userRoll
** Pre-Conditions: Sides must be known and userRoll must be input
** Post-Conditions: After function is complete, number of rolls and 
** 		    what the rolls were will be output
***********************************************************/


void Die::rollDie(int sides, int userRoll)
{
	int increm1 = 0;		/* this variable keeps track of number of rolls above half the side of the die */
	
	for (int counter = 0; counter < userRoll; counter++)
	{
		int roll = (rand() % sides) + 1;
		cout << roll << endl;
		if (roll >= (sides / 2))
			increm1++;
	}
	cout << "Rolls that are above half the number of sides: " << increm1 << endl;    
}
