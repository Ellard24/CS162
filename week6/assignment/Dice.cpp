#include "Dice.h"



Dice::Dice()
{

	


}


/********************************************************************************
**Function:setSides
**Description:Sets the side of the dice, not likely to be used besides testing purposes
**Parameters: int sides1
**Pre-Conditions: -
**Post-Conditions: Dice are used to determine attack and defense moves
**********************************************************************************/
void Dice::setSides(int sides1)
{
	sides = sides1;
}

/********************************************************************************
**Function:rollDice
**Description:Returns the value of a random roll for the side of dice specified
**Parameters:-
**Pre-Conditions: Fighter must be created
**Post-Conditions: Dice are used to determine attack and defense moves
**********************************************************************************/
int Dice::rollDice()
{

	return rand() % sides + 1;


}