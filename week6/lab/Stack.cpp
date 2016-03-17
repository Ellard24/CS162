#include "Stack.h"
#include <iostream>
using namespace std;

/********************************************************************************
**Function: Stack constructor
**Description: Sets the head of the stack to 0
**Parameters: - 
**Pre-Conditions: Stack must be created
**Post-Conditions: Nodes can be added 
*******************************************************************************/
Stack::Stack()
{

	head = 0;
}

/********************************************************************************
**Function: Stack destructor
**Description: destroys all nodes in the stack
**Parameters: - 
**Pre-Conditions: Nodes must exist to be deleted
**Post-Conditions: Empty stack
*******************************************************************************/
Stack::~Stack()
{

	Stacknode *nodePointer = head;
	Stacknode *nextNode = 0;

	while (nodePointer->next != 0)
	{
		nextNode = nodePointer->next;
		delete nodePointer;
		nodePointer = nextNode;
	}


}


/********************************************************************************
**Function: add()
**Description: Adds a new new node to the end of the list with the value given
**Parameters: int value
**Pre-Conditions: A list must exist
**Post-Conditions: Node can be removed or another added, displayed
*******************************************************************************/
void Stack::add(int value)
{

	//create node
	// make data member = value
	//adjust pointers


	//create two pointers
	Stacknode *newNode = new Stacknode;
	Stacknode *nodePointer = 0;

	// create node and set data to int value
	newNode->data = value;

	//the new node must become the last node so nullptr from head is now on newNode
	newNode->next = 0;


	// if head is still null pointer, the condition is true
	if (!head)
		head = newNode;
	else 
	{
		nodePointer = head;


		//make nodePointer equal to next if nodePointer next does not equal 0
		while (nodePointer->next != 0)
			nodePointer = nodePointer->next;

		//creates a node at the end of the list
		nodePointer->next = newNode;

	}

}


/********************************************************************************
**Function: remove()
**Description:	Removes a node at the back of the stack
**Parameters: - 
**Pre-Conditions: A node must exist in the stack
**Post-Conditions: More nodes can be added 
*******************************************************************************/
int Stack::remove()
{
	Stacknode *nodePointer = head;



	if (head == 0)
	{
		cout << "List is currently empty. No Nodes." << endl;
		return 0;
	}
	else
	{
		
		while (nodePointer->next && nodePointer->next->next != 0)
			nodePointer = nodePointer->next;
		

		int i = nodePointer->next->data;
		delete nodePointer->next;
		nodePointer->next = 0;
	
		

		//nodePointer = head->next;
		//delete 
		//head = nodePointer;

		return i;
		

	}
}

/********************************************************************************
**Function: display()
**Description: Used for test purposes. Displays all nodes data that currently exit
**Parameters: - 
**Pre-Conditions: A value must be placed in a node to be displayed
**Post-Conditions: -
*******************************************************************************/
void Stack::display()
{

	Stacknode *nodePointer = head;

	while (nodePointer)
	{
		cout << nodePointer->data << endl;

		nodePointer = nodePointer->next;
	}

	cout << endl;
	cout << endl;
}

