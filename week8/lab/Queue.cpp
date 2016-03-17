#include "Queue.h"
#include <iostream>
using namespace std;


/****************************************************************************
**Function: Queue constructor
**Description: Sets the front of the Queue to 0 
**Parameters: -
**Pre-Conditions: Queue must be created
**Post-Conditions: The first node can be added. Null pointer gets removed
****************************************************************************/

Queue::Queue()
{
	front = 0;
}

/****************************************************************************
**Function: Queue destructor
**Description: Destroys all nodes in the Queue
**Parameters: -
**Pre-Conditions: Queue must exist
**Post-Conditions: -
****************************************************************************/

Queue::~Queue()
{
	QueueNode *nodePointer = front;
	QueueNode *nextNode = 0;

	while (!nodePointer)
	{
		nextNode = nodePointer->next;
		delete nodePointer;
		nodePointer = nextNode;
	}





}




/****************************************************************************
**Function: addBack()
**Description: Adds a node to the Queue to the end unless an empty node is detected
**				in which the value of that node is changed
**Parameters:	-
**Pre-Conditions: A Queue must be in existance
**Post-Conditions: Nodes can be added, removed, displayed, and values can be changed
****************************************************************************/
void Queue::addBack()
{
	//QueueNode *nodePointer = front;
	int x = 0;
	

	// No nodes are created yet
	if (front == 0)
	{
		QueueNode *newNode = new QueueNode;
		cout << "What value do you want for this node?" << endl;
		cout << "This is first node being created" << endl;
		cin >> x;
		newNode->data = x;
		
		
		
		front = newNode;
		back = newNode;


		front->prev = back;
		front->next = back;
		back->next = front;
		back->prev = front; 
	}
	
	// Nodes exist (checks for empty node)
	else if (back->data == -1)
	{
		
		if (back->prev->data != -1)
		{
			cout << "what value do you want for this node?" << endl;
			cin >> x;
			back->data = x;

		}
		else
		{


			QueueNode *nodePointer = front;
			
			while (nodePointer->data != -1)
			{

				nodePointer = nodePointer->next;
			}
				
			if (nodePointer->data == -1)
			{
				cout << "What value do you want for this node?" << endl;
				cin >> x;
				nodePointer->data = x;
			}
			
			
			
		}
		
	}
	
	
	
	
	
	else
	{
		QueueNode *newNode = new QueueNode;

		int x = 0;

		cout << "What value do you want for this node?" << endl;
		cin >> x;
		newNode->data = x;


		back->next = newNode;
		newNode->prev = back;
		back = newNode;
		back->next = front;
		front->prev = back;
		



	}




}

/****************************************************************************
**Function: removeFront()
**Description:Removes a node from the Queue from the beginning 
**Parameters: - 
**Pre-Conditions: A node must be in existance at the front of Queue
**Post-Conditions: More nodes can be added or removed
****************************************************************************/
void Queue::removeFront()
{
	if (front == 0)
		cout << "Queue is empty" << endl;
	else if (front->data == -1)
		cout << "Queue is empty" << endl;
	else
	{

		back = front;
		back->data = -1;
		front = front->next;
		front->prev = back;





	}


}

/****************************************************************************
**Function: getFront()
**Description: Returns the value of the front node
**Parameters: - 
**Pre-Conditions: Front node must be in existance 
**Post-Conditions: -
****************************************************************************/
int Queue::getFront()
{

	cout << "Showing Front" << endl;
	return front->data; 





}

//function used for testing only
/*****
int Queue::getBack()
{
	cout << "Lets first see what front->prev shows" << endl;
	cout << front->prev->data << endl;

	return back->data;

}
****/