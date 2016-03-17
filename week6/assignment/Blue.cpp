#include "Blue.h"
#include <iostream>
using namespace std;

/********************************************************************************
**Function: Blue men Constructor
**Description: Calls upon Creature constructor to input proper stats
**Parameters: -
**Pre-Conditions: -
**Post-Conditions: Created object can be used in combat function
**********************************************************************************/
Blue::Blue() : Creature(10, 6, 3, 12, "Blue Men")
{



}


/********************************************************************************
**Function: rollAttack
**Description: Calls upon the attackDie to carry out the appropriate roll. Also
**				checks for Shadow and Achilles moves.
**Parameters:Creature *c1
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage can be determined
**********************************************************************************/
int Blue::rollAttack(Creature *c1)
{
	
	int roll = attackDie.rollDice() + attackDie.rollDice();
	
	if (achilles == true)
	{
		cout << "Blue Men roll a " << roll / 2 << " for attack" << endl;
		return roll / 2;
	}

	if (c1->getName() == "Shadow")
	{
		if ((rand() % 2) + 1 == 2)
		{
			cout << "Blue men roll a " << roll << " for attack" << endl;
			cout << "The Shadow eludes the enemy and no damage is taken" << endl;
			return false;
		}
		else
			return roll;
	}

	else
	{





		cout << "Blue men roll a " << roll << " for attack" << endl;

		return roll;
	}

}



/********************************************************************************
**Function:rollDefend
**Description: Calls upon the defensive die to carry out the appropriate roll
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage can be calculated from roll
**********************************************************************************/
int Blue::rollDefend()
{

	int roll = defenseDie.rollDice() + defenseDie.rollDice() + defenseDie.rollDice();

	cout << "Blue men roll a " << roll << " for defense" << endl;

	return roll;

}