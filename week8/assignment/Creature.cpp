#include "Creature.h"

/********************************************************************************
**Function: Creature constructor
**Description: Sets achilles attribute to false 
**Parameters: -
**Pre-Conditions:-
**Post-Conditions:-
**********************************************************************************/
Creature::Creature()
{
	achilles = false;

	score = 0;

}


/********************************************************************************
**Function:Creature constructor
**Description:Takes parameters and sets the fighters to the appropriate stats
**Parameters: attackSides, defenseSides, armor1,strength1, name1
**Pre-Conditions: -
**Post-Conditions: Functions can retrieve stats 
**********************************************************************************/
Creature::Creature(int attackSides, int defenseSides, int armor1, int strength1, string name1)
{
	attackDie.setSides(attackSides);
	defenseDie.setSides(defenseSides);
	armor = armor1;
	strength = strength1;
	name = name1; 

}

/********************************************************************************
**Function: rollAttack
**Description:Virtual function that is redefined in subclasses
**Parameters:Creature *c1
**Pre-Conditions:-
**Post-Conditions:-
**********************************************************************************/
int Creature::rollAttack(Creature *c1)
{

	return 0; 
	
}


/********************************************************************************
**Function:getArmor
**Description:Returns value for armor
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Armor can be used to calculate damage
**********************************************************************************/
int Creature::getArmor()
{

	return armor;
}

/********************************************************************************
**Function:getStrength
**Description: Returns value for strength
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Strength determines live or death
**********************************************************************************/
int Creature::getStrength()
{

	return strength;

}


/********************************************************************************
**Function: sStrength
**Description:Sets the strength value
**Parameters:int s
**Pre-Conditions: Fighter must be created
**Post-Conditions: Figher's modified strength used in following fight sequences
**********************************************************************************/
void Creature::setStrength(int s)
{

	strength = strength - s; 



}

/********************************************************************************
**Function:getAchilles
**Description: Returns the value for achilles
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Can be used to determine if fighter has reduced roll for attack
**********************************************************************************/
bool Creature::getAchilles()
{

	return achilles;



}



/********************************************************************************
**Function:setAchilles
**Description:Sets the achilles data member to true or false 
**Parameters:bool achilles1
**Pre-Conditions: Fighter must be created
**Post-Conditions: Fighter might have reduced roll if achilles is set to true
**********************************************************************************/
void Creature::setAchilles(bool achilles1)
{

	achilles = achilles1;

	



}

/********************************************************************************
**Function: getName
**Description: Returns name of fighter
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Name can be used to see if Shadow or Goblin is fighting
**********************************************************************************/
string Creature::getName()
{

	return name;

}


/**********************************************************
**Function: setName
**Description: Sets the name of the Fighter
**Parameters: string displayName
**Pre-Conditions: User needs to be prompt for desired name
**Post-Conditions: Fighter gets created with allocated name
****************************************************************/
void Creature::setName(string displayName)
{

	name = displayName;


}


/**********************************************************
**Function:drinkPotion
**Description: Returns a portion of strength to winning fighter
**Parameters:-
**Pre-Conditions: Fighters need to exist and a fighter needs to win a round
**Post-Conditions: Fighter gets sent to the back of the LineUp
****************************************************************/


void Creature::drinkPotion()
{
	

	int potion = rand() % 6;

	strength = potion + strength;



}

/**********************************************************
**Function:increaseScore
**Description: Increases the score data member for the fighter
**Parameters:-
**Pre-Conditions: Fighter needs to exist
**Post-Conditions: Score can be used to determine winner
****************************************************************/


void Creature::increaseScore()
{

	score++;


}

/**********************************************************
**Function: returnScore
**Description: Returns the value of the score data member
**Parameters:-
**Pre-Conditions: Fighter needs to exist
**Post-Conditions: Score can be used to determine winner
****************************************************************/
int Creature::returnScore()
{

	return score;


}

