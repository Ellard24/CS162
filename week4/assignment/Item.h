#include <string>
using namespace std;
#pragma once

class Item
{
private:
	string itemName;
	string unit;
	int numberBuy;
	int price;

public:
	Item();
	Item(string name1, string unit1, int num1, int price1);
	string getName();

	string getUnit();

	void setNumber(int num1);
	int getNumber();

	int getPrice();
	friend bool operator==(Item a, Item b);








};