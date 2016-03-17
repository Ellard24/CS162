#include "Goblin.h"
#include <iostream>
using namespace std;

/********************************************************************************
**Function: Goblin Constructor
**Description: Calls upon Creature constructor to input proper stats
**Parameters:-
**Pre-Conditions:-
**Post-Conditions: Goblin can be used as a fighter
**********************************************************************************/
Goblin::Goblin() : Creature(6, 6, 3, 8, "Goblin")
{



}

/********************************************************************************
**Function:rollDefend
**Description:Calls upon the defensive die to carry out the appropriate roll
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage can be determined from roll
**********************************************************************************/
int Goblin::rollDefend()
{
	int roll = defenseDie.rollDice();
	
	cout << "Goblin rolls a " << roll << " for defense" << endl;
	
	return roll;

}


/********************************************************************************
**Function: rollAttack
**Description:Returns value for attack roll 
**Parameters:Creature *c1
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage done can be determined from roll
**********************************************************************************/
int Goblin::rollAttack(Creature *c1)
{
	int roll = attackDie.rollDice() + attackDie.rollDice();

	if (c1->getName() == "Shadow")
	{
		if ((rand() % 2) + 1 == 2)
		{
			cout << "Goblin rolls a " << roll << " for attack" << endl;
			cout << "The Shadow eludes the enemy and no damage is taken" << endl;
			return false;
		}
		else
			return roll;
	}
		
	else
	{
		cout << "Goblin rolls a " << roll << " for attack" << endl;

		return roll;
	}
	
}