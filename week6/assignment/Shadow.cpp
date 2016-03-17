#include "Shadow.h"
#include <iostream>
using namespace std;


/********************************************************************************
**Function: Shadow Constructor
**Description: Calls upon Creature constructor to input proper stats
**Parameters:-
**Pre-Conditions:-
**Post-Conditions: Shadow can be used as a fighter
**********************************************************************************/
Shadow::Shadow() : Creature(10, 6, 0, 12, "Shadow")
{



}


/********************************************************************************
**Function:rollDefend
**Description:Calls upon the defensive die to carry out the appropriate roll
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage can be determined from roll
**********************************************************************************/
int Shadow::rollDefend()
{


	int roll = defenseDie.rollDice();
	
	cout << "The Shadow rolls a " << roll << " for defense" << endl;
	
	return roll;


}

/********************************************************************************
**Function: rollAttack
**Description:Returns value for attack roll
**Parameters:Creature *c1
**Pre-Conditions: Fighter must be created
**Post-Conditions: Damage done can be determined from roll
**********************************************************************************/
int Shadow::rollAttack(Creature *c1)
{
	int roll = attackDie.rollDice() + attackDie.rollDice();
	
	if (achilles == true)
	{
		cout << "Shadow rolls a " << roll / 2 << " for attack" << endl;
		return roll / 2;
	}

	if (c1->getName() == "Shadow")
	{
		if ((rand() % 2) + 1 == 2)
		{
			cout << "The Shadow rolls a " << roll << " for attack" << endl;
			cout << "The Shadow eludes the enemy and no damage is taken" << endl;
			return false;
		}
		else
			return roll;
	}
	else
	{

		cout << "The Shadow rolls a " << roll << " for attack" << endl;

		return roll;
	}

}