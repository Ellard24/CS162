/*************************************************************************************************
**Author: Ellard Gerritsen van der Hoop
** Description: This program showcases how a stack and queue works. New nodes are added or removed 
**				
**Input: -
**Output: Can display values in each node
*************************************************************************************************/

#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;





int main()
{
	cout << "This program makes a Queuenode and a Stacknode and displays the general process" << endl;
	cout << endl;
	cout << endl;


	Stack stack1;
	

	//Will return statement saying there are no nodes
	stack1.remove();
	cout << "A 5 will be now stored in the data in the first node" << endl;
	stack1.add(5);
	stack1.display();
	
	cout << "Lets store a 3 in a new node" << endl;
	stack1.add(3);
	stack1.display();

	cout << "Lets add an 8 as well" << endl;
	stack1.add(8);
	stack1.display();

	cout << "Now the bottom node will be removed" << endl; 
	cout << stack1.remove() << endl;
	cout << endl;
	stack1.display();
	




	cout << "Now lets test the Queue" << endl;
	Queue queue1; 
	
	cout << "Adding a 1 to a new node" << endl;
	
	queue1.add(1);
	queue1.display();


	cout << "Adding a 2 to a new node" << endl;

	queue1.add(2);
	queue1.display();

	cout << "Adding a 10 to a new node" << endl;
		
	queue1.add(10);
	queue1.display();

	cout << "Deleteing the front node" << endl;

	queue1.remove();
	queue1.display();











	return 0;
}
