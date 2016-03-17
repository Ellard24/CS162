#include "Stack.h"
#include <iostream>
#include <vector>
using namespace std;

/**********************************************************
**Function: Stack constructor
**Description: Sets head and size variables to 0
**Parameters:-
**Pre-Conditions: -
**Post-Conditions: LoserPile can add fighters
****************************************************************/

Stack::Stack()
{

	head = 0;
	size = 0;

}


Stack::~Stack()
{

	LoserPile *nodePointer = head;
	LoserPile *nextNode = 0;

	while(nodePointer)
	{
		nextNode = nodePointer->next;
		delete nodePointer;
		nodePointer = nextNode;
	}






}




/**********************************************************
**Function: addFighter
**Description: Adds a new fighter into the Stack LoserPile.
**Parameters: Creature *creature
**Pre-Conditions: Stack needs to be created
**Post-Conditions: Stack can be displayed or more fighters can be added
****************************************************************/
void Stack::addFighter(Creature *creature)
{

	LoserPile *newNode = new LoserPile;
	LoserPile *nodePointer = 0;


	newNode->c1 = creature;

	newNode->next = 0;

	size++;

	if (!head)
	{
		head = newNode;
		
	}
	else
	{
		nodePointer = head;

		while (nodePointer->next != 0)
			nodePointer = nodePointer->next;


		nodePointer->next = newNode;

		

	}
	



}


/**********************************************************
**Function: display()
**Description: Displays the contents of the LoserPile stack
**Parameters:-
**Pre-Conditions: Stack must be created
**Post-Conditions: Fighters can be added and displayed
****************************************************************/
void Stack::display()
{

	vector<string> vector1;

	LoserPile *nodePointer = head;

	if (head == 0)
	{
		cout << "Empty" << endl;
	}


	while (nodePointer != 0)
	{
		//cout << nodePointer->c1->getName() << endl;
		vector1.push_back(nodePointer->c1->getName());
		nodePointer = nodePointer->next;

	}

	

	for (int i = 0; i != vector1.size(); i++)
	{
		cout << vector1[vector1.size() - i - 1] << endl;
	}



	cout << endl;
	cout << endl;


}


/**********************************************************
**Function: returnWinners
**Description: Removes last three fighters in LoserPile. Used to display 
				first, second, and third place winners
**Parameters:-
**Pre-Conditions: LoserPile needs fighters in it
**Post-Conditions: Winners are displayed. Team score is settled
****************************************************************/
string Stack::returnWinners()
{

	LoserPile *nodePointer = head;

	if (size =  0)
	{
		cout << "No fighter left" << endl;
		return 0;
	}

	else
	{
		while (nodePointer->next && nodePointer->next->next != 0)
			nodePointer = nodePointer->next;

		string i = nodePointer->next->c1->getName();
		delete nodePointer->next;
		nodePointer->next = 0;
		size--;

		return i;
	}

	 

}


/**********************************************************
**Function:getSize
**Description:Returns the value for size 
**Parameters:-
**Pre-Conditions: Stack needs to be created
**Post-Conditions: When size of pile increases, can be used for additional calculations
****************************************************************/
int Stack::getSize()
{

	return size;

}
