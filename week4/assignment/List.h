#include "Item.h"
#include <vector>
using namespace std;


class List
{

private:
	vector<Item> List1; 

public:
	List();
	string getItemName(int i);
	string getItemUnit(int i);
	int getItemNumber(int i);
	int getItemPrice(int i);
	void addItem(Item name);
	vector<Item> &getVector();

	
	void displayAll();






};