
#include "Item.h"







/******************************************************
** Function: Item Constructor
** Description: Creates an item with user set vaues
** Parameters: name1, unit1, num1, price1
** Pre-Conditions: -
** Post-Conditions: Item will be added to list vector.
*******************************************************/
Item::Item(string name1, string unit1, int num1, int price1)
{
	itemName = name1;
	unit = unit1;
	numberBuy = num1;
	price = price1;
}


/******************************************************
** Function: getName
** Description: Returns item name 
** Parameters: -
** Pre-Conditions: Item and name must have name initialized
** Post-Conditions: Name can be displayed for an item
*******************************************************/
string Item::getName()
{

	return itemName;
}


/******************************************************
** Function: getUnit
** Description: Returns the unit for an item
** Parameters: -
** Pre-Conditions: Item and unit must have been initialized
** Post-Conditions: Unit can be displayed for an item
*******************************************************/
string Item::getUnit()
{
	return unit;
}


/******************************************************
** Function: setNumber
** Description: Sets the number to buy for an item
** Parameters: num1
** Pre-Conditions: Item must have been created
** Post-Conditions: Can be used to merge duplicate items
*******************************************************/
void Item::setNumber(int num1)
{
	numberBuy = num1;

}

/******************************************************
** Function: getNumber
** Description: Returns the number to buy 
** Parameters: -
** Pre-Conditions: Item and number must be initialized
** Post-Conditions: Number can be displayed to screen and be used to calculate extended price
*******************************************************/
int Item::getNumber()
{
	return numberBuy;

}



/******************************************************
** Function: getPrice()
** Description: Returns the price of an item
** Parameters: -
** Pre-Conditions: Item and price must be initialized
** Post-Conditions: Price can be displayed to screen and used to calculate extended price
*******************************************************/
int Item::getPrice()
{
	return price; 

}


/******************************************************
** Function: bool operator
** Description: Overloads the == operator 
** Parameters: Item a, Item b
** Pre-Conditions: An item needs to be initiliazed to compare the other item
** Post-Conditions: Items can be merged if there are duplicate entries
*******************************************************/
bool operator==(Item a, Item b)
{
	return a.getName() == b.getName();


}