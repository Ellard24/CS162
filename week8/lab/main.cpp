/**********************************************************
**Author:Ellard Gerritsen van der Hoop
**Description: Circular Doubly Linked List program that allows 
			 user to add nodes, remove nodes, display data from
			 the front node. Front and Back point at each other
**Input: All input taken during runtime
**Output: Displays front node and corresponding messages when 
		 adding or removing nodes
***********************************************************/





#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;




int main()
{
	Queue q1; 



	string answer = "yes";
	int choice = 0;




	do
	{

		cout << endl << "Please make a selection" << endl;
		cout << "1) Add Node to Back. If an empty node exists, this will just change the value" << endl;
		cout << "2) Delete node" << endl;
		cout << "3) Display value in front" << endl;
		cout << "4) Exit Program" << endl;

		cin >> choice;




		switch (choice)
		{
		case 1:
			cout << "Adding node" << endl;
			q1.addBack(); 
		//	cout << "Node check" << endl;
			break;
		case 2:
			cout << "Removing front node" << endl;
			q1.removeFront();
			break;
		case 3:
			cout << "Displaying Front Value" << endl;
			cout << q1.getFront() << endl;
		//	cout << q1.getBack() << endl;				For Testing Purposes 
			break;
		case 4:
			return 0;
			break;


		}



		
		cout << "Do you want to make another selection?" << endl;
		cin >> answer;

	} while (answer == "yes");





	return 0;

}
