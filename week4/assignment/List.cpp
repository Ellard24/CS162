#include "List.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;

/******************************************************
** Function: List constructor
** Description: Reserves vector room
** Parameters:- 
** Pre-Conditions: -
** Post-Conditions: Items can be added to vector
*******************************************************/
List::List()
{
	List1.reserve(100);

}

/******************************************************
** Function: getItemName
** Description: Returns name of item
** Parameters: int i
** Pre-Conditions: Item must be initialized
** Post-Conditions: Item name can be displayed to screen
*******************************************************/
string List::getItemName(int i)
{
	return List1[i].getName();

}
/******************************************************
** Function: getItemUnit
** Description: Returns unit of item in vector
** Parameters: int i
** Pre-Conditions: Item must be initialized
** Post-Conditions: Item unit can be displayed to screen
*******************************************************/
string List::getItemUnit(int i)
{
	return List1[i].getUnit();


}
/******************************************************
** Function: getItemNumber
** Description: Returns the number of item
** Parameters: int i
** Pre-Conditions: Item must be initialized
** Post-Conditions: Item number can be displayed to screen and used to calculate extended price
*******************************************************/
int List::getItemNumber(int i)
{
	return List1[i].getNumber();
	
	
}

/******************************************************
** Function: getItemPrice
** Description: Returns price of item in vector
** Parameters: int i
** Pre-Conditions: Item must be initialized
** Post-Conditions: Item price can be displayed to screen and used to calculate extended price
*******************************************************/
int List::getItemPrice(int i)
{
	return List1[i].getPrice();
	
	

}


/******************************************************
** Function: additem
** Description: Adds an item to the list vector
** Parameters: Item name
** Pre-Conditions: List must be created
** Post-Conditions: Items can be removed, displayed to screen, or checked for duplicates
*******************************************************/
void List::addItem(Item name)
{
	
	bool merged = false;
	for (int i = 0; i < List1.size(); ++i)
	{
		if (List1[i] == name)
		{
			List1[i].setNumber(List1[i].getNumber() + name.getNumber());
			cout << "Combining items" << endl;
			merged = true;
		}
	}
	if (!merged)
	{
		List1.push_back(name);
		cout << "Successfully added an item" << endl;
	}
	else return;
}

/******************************************************
** Function: getVector
** Description: Returns the vector of items
** Parameters: -
** Pre-Conditions: List must be created
** Post-Conditions: Items can be manipulated from vector
*******************************************************/
vector<Item> &List::getVector()
{
	return List1;


}
