#include "Barbarian.h"
#include <iostream>
using namespace std;

/********************************************************************************
**Function: Barbarian Constructor
**Description: Calls upon Creature constructor to input proper stats
**Parameters: -
**Pre-Conditions: -
**Post-Conditions: Barbarian can be used as a fighter
**********************************************************************************/
Barbarian::Barbarian() : Creature(6, 6, 0, 12, "Conan")
{


	// test class 

}


/********************************************************************************
**Function: rollDefend
**Description: Returns the value of the defensive dice roll
**Parameters:-
**Pre-Conditions: Fighter must be created and combat must be ongoing
**Post-Conditions: Damage can be determined
**********************************************************************************/
int Barbarian::rollDefend()
{

	int roll = defenseDie.rollDice() + defenseDie.rollDice();
	
	cout << "Barbarian rolls a " << roll << " for defense" << endl;

	return roll;


}

/********************************************************************************
**Function:rollAttack
**Description: Returns the value of the attack Dice 
**Parameters:Creature *c1 
**Pre-Conditions: Fighter must be created and in combat
**Post-Conditions: Damage done to opponent can be calculated 
**********************************************************************************/
int Barbarian::rollAttack(Creature *c1)
{
	
	int roll = attackDie.rollDice() + attackDie.rollDice();
	if (achilles == true)
	{
		cout << "Barbarian rolls a " << roll / 2 << " for attack" << endl;
		return roll / 2;
	}

	if (c1->getName() == "Shadow")
	{
		if ((rand() % 2) + 1 == 2)
		{
			cout << "Barbarian rolls a " << roll << " for attack" << endl;
			cout << "The Shadow eludes the enemy and no damage is taken" << endl;
			return false;
		}
		else
			return roll;
	}
	else
	{


		cout << "Barbarian rolls a " << roll << " for attack" << endl;

		return roll;
	}
	

}

