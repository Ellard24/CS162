
#include "Queue.h"
#include <iostream>
using namespace std;

/********************************************************************************
**Function: Queue constructor
**Description: Sets the front and back of the Queue to 0 
**Parameters: - 
**Pre-Conditions: Queue must be created
**Post-Conditions: Nodes can be added to the Queue
*******************************************************************************/
Queue::Queue()
{

	front = 0;
	back = 0;
}

/********************************************************************************
**Function: Queue destructor
**Description: Destroys all nodes in the Queue
**Parameters: - 
**Pre-Conditions: Queue must exist
**Post-Conditions: - 
*******************************************************************************/
Queue::~Queue()
{

	Queuenode *nodePointer = front;
	Queuenode *nextNode = 0;

	while (nodePointer->next != 0)
	{
		nextNode = nodePointer->next;
		delete nodePointer;
		nodePointer = nextNode;
	}


}

/********************************************************************************
**Function: add()
**Description: Adds a node to the Queue to the end and gives the value given
**Parameters: int value
**Pre-Conditions: A Queue must be in existance 
**Post-Conditions: Nodes can be added, removed, or displayed
*******************************************************************************/
void Queue::add(int value)
{
	
	Queuenode *newNode = new Queuenode;
	Queuenode *nodePointer = front;

	newNode->data = value; 


	if (front == 0)
	{
		newNode->previous = 0;
		newNode->next = 0;
		front = newNode;
		back = newNode;
	}
	else
	{
		while (nodePointer->next != 0)
			nodePointer = nodePointer->next;

		nodePointer->next = newNode;

		newNode->next = 0;
		back->next = newNode;
		newNode->previous = back;
		back = newNode;
	}








}

/********************************************************************************
**Function: remove()
**Description: Removes a node from the Queue from the beginning 
**Parameters: - 
**Pre-Conditions: A node must be in existant at the start of the Queue
**Post-Conditions: More nodes can be added or removed
*******************************************************************************/
int Queue::remove()
{

	Queuenode *nodePointer;

	nodePointer = front;

	while (nodePointer->next != 0)
	{
		int i = front->data;
		
		front = front->next;
		front->previous = 0;
		delete nodePointer; 
		return i;

	}




}

/********************************************************************************
**Function: display()
**Description: Displays all values in the data of the nodes in the Queue
**Parameters: - 
**Pre-Conditions: Nodes need to be in existant 
**Post-Conditions: -
*******************************************************************************/
void Queue::display()
{


	Queuenode *nodePointer = front;

	while (nodePointer)
	{
		cout << nodePointer->data << endl;

		nodePointer = nodePointer->next;
	}

	cout << endl;
	cout << endl;


}