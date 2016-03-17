#include "Reptile.h"
#include <iostream>
using namespace std;


/********************************************************************************
**Function: Reptile Constructor
**Description: Calls upon Creature constructor to input proper stats
**Parameters: -
**Pre-Conditions: -
**Post-Conditions: Created object can be used in combat function
**********************************************************************************/
Reptile::Reptile() : Creature(6, 6, 7, 18, "Reptile")
{



}

/********************************************************************************
**Function:rollDefend
**Description: Calls upon the defensive die to carry out the appropriate roll
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage can be calculated from roll
**********************************************************************************/
int Reptile::rollDefend()
{
	int roll = defenseDie.rollDice();
	
	cout << "Reptile People roll a " << roll << " for defense" << endl;
	
	return roll;

}

/********************************************************************************
**Function: rollAttack
**Description: Calls upon the attackDie to carry out the appropriate roll. Also 
**				checks for Shadow and Achilles moves. 
**Parameters:Creature *c1
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage can be determined 
**********************************************************************************/
int Reptile::rollAttack(Creature *c1)
{
	
	int roll = attackDie.rollDice() + attackDie.rollDice() + attackDie.rollDice();
	
	if (achilles == true)
	{
		cout << "Reptile rolls a " << roll / 2 << " for attack" << endl;
		return roll / 2;
	}

	if (c1->getName() == "Shadow")
	{
		if ((rand() % 2) + 1 == 2)
		{
			cout << "Reptile People roll a " << roll << " for attack" << endl;
			cout << "The Shadow eludes the enemy and no damage is taken" << endl;
			return false;
		}
		else
			return roll;
	}

	else
	{

		cout << "Reptile People roll a " << roll << " for attack" << endl;

		return roll;
	}

}