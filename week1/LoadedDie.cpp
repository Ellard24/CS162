#include "LoadedDie.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

/***********************************************************
** Function: Constructor for LoadedDie
**Description: Sets the sides based on userSides input
** Paramters: int userSides
** Pre-Conditions: userSides must be known
** Post-Conditions: sides will be used for RollDie function 
**********************************************************/

LoadedDie::LoadedDie(int userSides)
{
	sides = userSides;
}


/***********************************************************
** Function: Default Constructor
** Description: Built when class is made
** Paramters: -
** Preconditions: -
** PostConditions: -
************************************************************/
LoadedDie::LoadedDie()
{

}


/***********************************************************
** Function: rollDie
** Description: rollDie function that uses a counter to make a biased roll *
** and then returns double the roll if it is below half  the number of sides
** Parameters: int sides, int userRoll
** Pre-Conditions: sides and userRoll must be known from input
** Post-Conditions: Number of rolls and what the rolls were will be output
***********************************************************/

void LoadedDie::rollDie(int sides, int userRoll)
{
	
	
	int increm1 = 0;

	for (int counter = 0; counter < userRoll; counter++)
	{
		int roll = (rand() % sides) + 1;

		
		if (counter % 1 == 0)    /*Initually used counter % 2 ==0 but the biased die becomes more obvious when counter % 1 == 0 */
		{
			


			if (roll <= (sides / 2))
			{
				cout << roll * 2 << endl;
				
				if ((roll * 2) >(sides / 2))
				{
					increm1++;
					

				}

				 cout << roll * 2 << endl;


			}
			else
			{
				cout  << roll << endl;
				if (roll >= (sides / 2))
					increm1++;
				
			}
		}

		else
		{
			cout << roll << endl; 
			if (roll >= (sides / 2))
				increm1++;
			
		}


		


	}
	cout << "Rolls that are above half the number of sides: " << increm1 << endl;   // This line just makes it easier to compare Loaded Die vs Die 
}

