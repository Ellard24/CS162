/*****************************************************************************************************
**Author: Ellard Gerritsen van der Hoop
**Description: This program will ask users to input what fighters they want to put against each other. 
**				The program will then create these fighters with appropriate stats and put them through
**				a combat scenario. Winners stay in the LineUp and losers get moved to the LoserPile.
**Input:		All input is taken during runtime
**Output:		Displays all actions regarding combat between the fighters to the screen. Displays score and winners as well.
*****************************************************************************************/


#include "Creature.h"
#include "Barbarian.h"
#include "Blue.h"
#include "Goblin.h"
#include "Reptile.h"
#include "Shadow.h"
#include "Game.h"
#include <time.h>
#include <iostream>
#include "Queue.h"
#include "Stack.h"


using namespace std;

void display(Queue &q, int size);

void combat1(Queue &p1, Queue &p2, Stack &sp1, int &total1, int &total2, Combat &game1);


/******************************************************************
**Function: Main
**Description: Sets time seed, initializes options, creates Game, and then 
				calls other functions that handle the combat. Queue and Stack 
				is also made that allows fighters to be moved to corresponding
				struct
**Parameters: -
**Pre-Conditions:-
**Post-Conditions: Fighters will be created and pitted against each other
********************************************************************/



int main()
{
	srand(time(0));

	
	

	cout << "This program pits a variety of creatures against each other in a Fantasy Combat Game" << endl;
	cout << "Two players will have the option to pick their LineUp and then battle it out" << endl;
	cout << "Player 1 will decide the size of the LineUp and then both players can pick from 5 monsters" << endl;
	cout << endl;
	cout << endl;


	int lineSize = 0;
	int totalP1 = 0;
	int totalP2 = 0;

	cout << "Player1: Please decide the size of the LineUp" << endl;

	cin >> lineSize;
	

	Queue p1LineUp;
	Queue p2LineUp;
	Stack p1Loser;
	Stack p2Loser;
	Combat game;

	cout << "Player 1 picks first" << endl;
	
	display(p1LineUp, lineSize);

	cout << "Player 2 now gets to pick" << endl;

	display(p2LineUp, lineSize);


	combat1(p1LineUp, p2LineUp, p1Loser, totalP1, totalP2, game);

	
	cout << "Losing Pile" << endl;
	p1Loser.display();									

	cout << endl;

	


	//send rest of winning team to pile and then pick out last 3 to pick first, second , third place
	if (p1LineUp.getSize() > 0)
	{
		while (p1LineUp.getSize() > 0)
		{
			p1Loser.addFighter(p1LineUp.returnFront());
			p1LineUp.removeFighter();
		}


	}

	if (p2LineUp.getSize() > 0)
	{
		while (p2LineUp.getSize() > 0)
		{
			p1Loser.addFighter(p2LineUp.returnFront());
			p2LineUp.removeFighter();
		}

	}

	//Deletes last 3 nodes from stack 
	cout << "First Place: " << endl;
	cout << p1Loser.returnWinners();
	cout << endl;
	cout << "Second Place: " << endl;
	cout << p1Loser.returnWinners();
	cout << endl;

	cout << "Third Place: " << endl;
	cout << p1Loser.returnWinners();
	cout << endl;






	//Player 1 total score
	cout << "Player 1's total score is " << totalP1 << endl;


	//Player 2 total score
	cout << "Player 2's total score is " << totalP2 << endl;


	if (totalP1 > totalP2)
		cout << "Player 1 wins" << endl;
	else if (totalP2 > totalP1)
		cout << "Player 2 wins" << endl;
	else
		cout << "Its a tie, which isnt possible" << endl;
	




	


	return 0;
}

/******************************************************************
**Function: Display
**Description: Displays the instructions and lets user pick fighters
**Parameters: Queue &q, int size
**Pre-Conditions: Queue needs to exist, and size needs to be initialized 
**Post-Conditions: Parameters are used to create fighters
********************************************************************/
void display(Queue &q, int size)
{
	
	int count = size;
	do
	{
		

		int selection = 0;
		string displayName;


		cout << "Select the fighter type that you want to add (" << count << " fighters remaining):" << endl;
		cout << "1. Barbarian" << endl;
		cout << "2. BlueMen" << endl;
		cout << "3. Reptile Men" << endl;
		cout << "4. Goblin" << endl;
		cout << "5. The Shadow" << endl;
		cout << "Selection: " << endl;
		
		
		
		cin >> selection;

		if (selection > 0 && selection < 6)
		{
			

			

			if (selection == 1)
			{
				q.addFighter(new Barbarian);
				q.display();
				cout << endl;
			}

			if (selection == 2)
			{
				q.addFighter(new Blue);
				q.display();
				cout << endl;
			}

			if (selection == 3)
			{
				q.addFighter(new Reptile);
				q.display();
				cout << endl;

			}


			if (selection == 4)
			{
				q.addFighter(new Goblin);
				q.display();
				cout << endl;
			}


			if (selection == 5)
			{

				q.addFighter(new Shadow);
				q.display();
				cout << endl;

			}

			count--;
		}
	} while (count > 0);

	




}
	

/**********************************************************
**Function: combat1
**Description: Takes care of the combat. Moves fighters to appropriate
				struct based on performance. Keeps track of score
**Parameters: Queue &p1, Queue &p2, Stack &sp1, int &total1, int &total2, Combat &game1
**Pre-Conditions: All Queues and Stack needs to be created, totals initialized, and game initialized
**Post-Conditions: Combat determines which player will win. 
****************************************************************/
void combat1(Queue &p1, Queue &p2, Stack &sp1,int &total1, int &total2, Combat &game1)
{

	while (p1.getSize() > 0 && p2.getSize() > 0)
	{

	


		game1.attack1(p1.returnFront(), p2.returnFront());
		if (p1.returnFront()->getStrength() <= 0)
		{

			cout << p2.returnFront()->getName() << " wins this round" << endl;

			sp1.addFighter(p1.returnFront());
			p1.removeFighter();

			cout << p2.returnFront()->getName() << " drinks a potion" << endl;
			p2.returnFront()->drinkPotion();
			p2.returnFront()->increaseScore();
			total2++;
			if (p2.getSize() > 1)
				p2.moveBack();




		}
		else
		{

			cout << p1.returnFront()->getName() << " wins this round" << endl;

			sp1.addFighter(p2.returnFront());
			p2.removeFighter();

			cout << p1.returnFront()->getName() << " drinks a potion" << endl;
			p1.returnFront()->drinkPotion();
			p1.returnFront()->increaseScore();
			total1++;
			if (p1.getSize() > 1)
				p1.moveBack();
		}

		cout << "Do you want to see the current score? Type 'yes' if you want " << endl;
		string scoreChoice; 

		cin >> scoreChoice;
		
		if (scoreChoice == "yes")
		{
			cout << "Team One's Current Score: " << total1 << endl;
			cout << "Team Two's Current Score: " << total2 << endl;

			
			
		}
		else
		{


			cout << "Next round is starting" << endl;
		}


	}





}
