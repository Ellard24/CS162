/*************************************************
**Author: Ellard Gerritsen van der Hoop
**Description: A program that allows you to add or remove items
from a list and input all corresponding values for each item
**Input: All input taken during runtime
**Output: Displays name of items, price, unit, number
********************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "List.h"

using namespace std;



/******************************************************
** Function: main
** Description: Menu driven shopping cart simulator
** Parameters:- 
** Pre-Conditions: -
** Post-Conditions: Displays items in list 
*******************************************************/

int main()
{

	cout << "Welcome to the Shopping Cart Simulator" << endl;
	cout << "You will have the option to add items or remove items from the list" << endl;

	cout << endl;
	cout << endl;
	
	cout << "Then you can display the items in the list" << endl;
	cout << "as well as the total price of the trip" << endl;
	cout << endl;
	cout << endl;

	//Create a List
	List list1;



	string repeat = "yes";

	while (repeat == "yes")
	{
		cout << "Do you want to add, remove,  or display all items in list? Type in 1 for add, 2 for remove, 3 for display list, or 4 to end program." << endl;
		int choice = 0;
		cin >> choice;

		if (choice == 1)
		{
			

			//Ask for Name
			cout << "Please enter the name of the Item you want to add" << endl;

			string name;
			cin >> name;
			
			for (int i = 0; i < list1.getVector().size(); i++)
			{
				if (name == list1.getItemName(i))
					cout << name << " already exists and will be merged" << endl;
			}


			//Ask for Unit
			cout << "What is the Unit for the item?" << endl;
			string userUnit;
			cin >> userUnit;


			//Ask for Number to buy
			cout << "How many do you want to get?" << endl;
			int buyNum = 0;
			cin >> buyNum;


			//Ask for price
			cout << "What is the price?" << endl;
			int price = 0;
			cin >> price;

	
		
			Item newItem(name, userUnit, buyNum, price);
			list1.addItem(newItem);
		

			cout << "Number of Items in List: " << list1.getVector().size() << endl;


			cout << "Do you want to add, remove, or display your items? Type 'yes' or 'no'" << endl;
			cin >> repeat;

		}




		if (choice == 2)
		{
			//check to see if an item is even here
			if (list1.getVector().empty())
			{
				cout << "There are no items. Please add one" << endl;
			}

			else
			{
				string remove1;
				cout << "What item do you want to remove? Type in the name" << endl;
				cin >> remove1;



				for (int i = 0; i < list1.getVector().size(); i++)
				{
					if (list1.getItemName(i) == remove1)
					{
						list1.getVector().erase(list1.getVector().begin() + i);
					}
					else
					{
						cout << "Item does not exist" << endl;
					}

				}



			}



		}

		//display list

		if (choice == 3)
		{
			if (list1.getVector().empty())
			{
				cout << "There are no items. Please add one" << endl;
			}
			
			else
			{
				for (int i = 0; i < list1.getVector().size(); i++)
				{
					cout << "Item name: " << list1.getItemName(i) << endl;
					cout << "Unit name: " << list1.getItemUnit(i) << endl;
					cout << "Number to buy: " << list1.getItemNumber(i) << endl;
					cout << "Price: $" << list1.getItemPrice(i) << endl;
					cout << "Extended Price: $" << list1.getItemNumber(i) * list1.getItemPrice(i) << endl;
					cout << endl;

				}

				cout << endl;
				cout << endl;
		
				int sum = 0;
			
				for (int i = 0; i < list1.getVector().size(); i++)
				{
					 sum += list1.getItemNumber(i) * list1.getItemPrice(i);
				}
				cout << "The total cost for this trip: $" << sum << endl;
			}

		}
		if (choice == 4)
		{
			cout << "Program is ending :) " << endl;
			return 0;
		}
		
	}
		
	return 0;
}