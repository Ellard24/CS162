#include "Queue.h"
#include <iostream>
using namespace std;


/**********************************************************
**Function: Queue Constructor
**Description: Sets front and size to 0 
**Parameters:-
**Pre-Conditions: -
**Post-Conditions: Fighters can be added to LineUp
****************************************************************/

Queue::Queue()
{
	front = 0;

	size = 0;

}



Queue::~Queue()
{
	LineUp *nodePointer = front;
	LineUp *nextNode = 0;


	while (nodePointer)
	{
		nextNode = nodePointer->next;
		delete nodePointer;
		nodePointer = nextNode;
	}


}





/**********************************************************
**Function: addFighter
**Description: Adds a new fighter to the back of the LineUp
**Parameters: Creature *creature
**Pre-Conditions: Queue must exist
**Post-Conditions: Fighters can be removed, displayed, used for combat
****************************************************************/
void Queue::addFighter(Creature *creature)
{
	LineUp *newNode = new LineUp;
	//LineUp *nodePointer = front;
	string name;

	newNode->c1 = creature;
	
	cout << "What do you want to name this fighter?" << endl;
	cin >> name;
	newNode->c1->setName(name);

	if (front == 0)
	{
		newNode->prev = 0;
		newNode->next = 0;
		front = newNode;
		back = newNode;
		size++;

	}
	else
	{
		newNode->next = 0;
		back->next = newNode;
		newNode->prev = back;
		back = newNode;
		size++;



	}
	



}

/**********************************************************
**Function: removeFighter
**Description: Removes fighter from the LineUp 
**Parameters:-
**Pre-Conditions: Queue must exist and a fighter should already be in it
**Post-Conditions: Fighter gets added onto LoserPile
****************************************************************/
void Queue::removeFighter()
{

	LineUp *nodePointer;

	nodePointer = front;

	front = front->next;
	//front->prev = 0;
	delete nodePointer;
		
	

	size--; 




}

/**********************************************************
**Function: display
**Description: Displays the contents of the Queue LineUp
**Parameters:-
**Pre-Conditions: Queue needs to exist and fighters should be in it
**Post-Conditions: Fighters can be added, removed, or used in combat
****************************************************************/
void Queue::display()
{

	LineUp *nodePointer = front;
	
	while (nodePointer != 0)
	{

		cout << nodePointer->c1->getName() << endl;
		cout << nodePointer->c1->getStrength() << endl;
		cout << nodePointer->c1->getArmor() << endl;

		nodePointer = nodePointer->next;


	}




}


/**********************************************************
**Function: moveBack
**Description: Moves a fighter from the front to the back of the LineUp
**Parameters:-
**Pre-Conditions: Fighters need to be in the Queue
**Post-Conditions: Next fighter moves to the front and is set in combat
****************************************************************/
void Queue::moveBack()
{
	LineUp *nodePointer = front;
	
	

	front = nodePointer->next;
	
	nodePointer->next = 0;
	
	back->next = nodePointer;
	back = nodePointer;






}





/**********************************************************
**Function: returnFront
**Description: Returns the fighter at the front of the Queue
**Parameters:-
**Pre-Conditions: Queue should exist and fighter should be in it
**Post-Conditions: Fighters can be removed, manipulated, displayed
****************************************************************/
Creature* Queue::returnFront()
{

	return front->c1;


}


/**********************************************************
**Function:getSize
**Description: Returns the size of the Queue
**Parameters:-
**Pre-Conditions: Queue needs to exist
**Post-Conditions: 
****************************************************************/
int Queue::getSize()
{

	return size;

}


