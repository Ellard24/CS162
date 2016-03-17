#pragma once
#include <vector>
#include "item.h"



class Inventory
{


private: 
	int size;
	int maxSize;

	vector<Item> backpack;




public:
	Inventory();
//	~Inventory();
	void addItem(Item *item);
	void removeItem(); //can either do front of list removal or maybe search for item of name and remove it via parameters 
 	void displayItems();
	vector<Item> getItems();









};