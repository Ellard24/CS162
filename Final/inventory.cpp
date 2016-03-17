#include <iostream>
#include <string>
#include "inventory.h"
using namespace std;




/****************************************************************************
**Function: Inventory constructor
**Description: Sets maxSize and size
**Parameters:-
**Pre-Conditions: -
**Post-Conditions:Inventory can acquire items
******************************************************************************/
Inventory::Inventory()
{
	maxSize = 5;
	size = 0;


}



/****************************************************************************
**Function: addItem
**Description: Adds an key to the inventory. MaxSize limits this.
**Parameters: Item *item
**Pre-Conditions: Inventory needs to exist
**Post-Conditions: Keys can be gathered 
******************************************************************************/
void Inventory::addItem(Item *item)
{
	if (size == 5)
	{
		cout << "Your backpack is already full. Please remove an item first" << endl;
	}
	else
	{
		backpack.push_back(*item);
		cout << "Item has been added" << endl;
	}
}



/****************************************************************************
**Function: displayItems
**Description: Displays items in inventory
**Parameters:-
**Pre-Conditions: Inventory needs to exist with an item in it
**Post-Conditions: Items can be removed
******************************************************************************/
void Inventory::displayItems()
{
	if (backpack.size() == 0)
	{
		cout << "Backpack is empty" << endl;
	}
	else
	{

		cout << "Current Items:" << endl; 

		for (int i = 0; i < backpack.size(); i++)
		{
			cout << " -  " << backpack[i].getName() << endl;

		}

		cout << "Do you want to remove an item from your inventory? Type yes or no" << endl;
		string answer;
		cin >> answer;

		if (answer == "yes")
		{
			string itemRemoval;
			cout << "Type the name of the inventory item in lowercase letters to remove it " << endl;
			cin.ignore();
			getline(cin, itemRemoval);

			if (itemRemoval == "bedroom key" || itemRemoval == "dining key" || itemRemoval =="garden key")
				cout << "Removing a key would be pretty silly thing to do. ;) " << endl;
			else
			{

				for (int i = 0; i < backpack.size(); i++)
				{
					if (backpack[i].getName() == itemRemoval)
						backpack.erase(backpack.begin() + i);
				}

				cout << itemRemoval << " has been removed" << endl;
			}
		}
		else
		{
			cout << "Closing inventory screen" << endl;
		}
	}
}



/****************************************************************************
**Function: getItems
**Description: Returns vector of Items
**Parameters: -
**Pre-Conditions: Inventory needs to exist
**Post-Conditions: Iventory can be manipulated
******************************************************************************/
vector<Item> Inventory::getItems()
{

	return backpack;



}