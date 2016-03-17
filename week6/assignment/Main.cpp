/*****************************************************************************************************
**Author: Ellard Gerritsen van der Hoop
**Description: This program will ask users to input what fighters they want to put against each other. 
**				The program will then create these fighters with appropriate stats and put them through
**				a combat scenario.
**Input:		All input is taken during runtime
**Output:		Displays all actions regarding combat between two fighters to the screen.
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

using namespace std;

void display(int &option1, int &option2);
void choice(int &option1, int &option2, Combat &Game1);


/******************************************************************
**Function: Main
**Description: Sets time seed, initializes options, creates Game, and then 
				calls other functions that handle the combat
**Parameters: -
**Pre-Conditions:-
**Post-Conditions: Fighters will be created and pitted against each other
********************************************************************/



int main()
{
	srand(time(0));

	
	int option1 = 0;
	int option2 = 0;

	Combat Game1;

	display(option1, option2);

	choice(option1, option2,  Game1);


	return 0;
}

/******************************************************************
**Function: Display
**Description: Displays the instructions and lets user pick fighters
**Parameters: &option1, &option2
**Pre-Conditions: Option1 and Option2 must be initialized.
**Post-Conditions: Parameters are used to create fighters in choice function
********************************************************************/
void display(int &option1, int &option2)
{

	cout << "This program pits a variety of creatures against each other in a Fantasy Combat Game" << endl;
	cout << "A set of test fights will be shown to see how they deal with each other" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	
	cout << "You will pick two units. Type in the corresponding number" << endl;
	cout << "1.) Barbarian   2.) Blue Men    3.) Reptile Men    4.) Goblin     5.) The Shadow" << endl;
	cout << "Pick your first fighter" << endl;

	cin >> option1;

	cout << "Pick your second fighter" << endl;

	cin >> option2;

}
	
/******************************************************************
**Function: choice
**Description:Creates the appropriate monsters based on user choice and 
passes to game.
**Parameters:&option, &option2, &game
**Pre-Conditions: Game must be created
**Post-Conditions: Monsters will be put into attack function from Combat class
********************************************************************/
void choice(int &option1, int &option2, Combat &game)
{
	

	Barbarian *barb = new Barbarian;
	Barbarian *barb2 = new Barbarian;
	Blue *blue = new Blue;
	Blue *blue2 = new Blue;
	Goblin *goblin = new Goblin;
	Goblin *goblin2 = new Goblin;
	Reptile *reptile = new Reptile;
	Reptile *reptile2 = new Reptile;
	Shadow *shadow = new Shadow;
	Shadow *shadow2 = new Shadow;

	if (option1 == 1 && option2 == 1)
		game.attack1(barb, barb2);
	else if (option1 == 1 && option2 == 2)
		game.attack1(barb, blue);
	else if (option1 == 1 && option2 == 3)
		game.attack1(barb, reptile);
	else if (option1 == 1 && option2 == 4)
		game.attack1(barb, goblin);
	else if (option1 == 1 && option2 == 5)
		game.attack1(barb, shadow);
	else if (option1 == 2 && option2 == 1)
		game.attack1(blue, barb);
	else if (option1 == 2 && option2 == 2)
		game.attack1(blue, blue2);
	else if (option1 == 2 && option2 == 3)
		game.attack1(blue, reptile);
	else if (option1 == 2 && option2 == 4)
		game.attack1(blue, goblin);
	else if (option1 == 2 && option2 == 5)
		game.attack1(blue, shadow);
	else if (option1 == 3 && option2 == 1)
		game.attack1(reptile, barb);
	else if (option1 == 3 && option2 == 2)
		game.attack1(reptile, blue);
	else if (option1 == 3 && option2 == 3)
		game.attack1(reptile, reptile2);
	else if (option1 == 3 && option2 == 4)
		game.attack1(reptile, goblin);
	else if (option1 == 3 && option2 == 5)
		game.attack1(reptile, shadow);
	else if (option1 == 4 && option2 == 1)
		game.attack1(goblin, barb);
	else if (option1 == 4 && option2 == 2)
		game.attack1(goblin, blue);
	else if (option1 == 4 && option2 == 3)
		game.attack1(goblin, reptile);
	else if (option1 == 4 && option2 == 4)
		game.attack1(goblin, goblin2);
	else if (option1 == 4 && option2 == 5)
		game.attack1(goblin, shadow);
	else if (option1 == 5 && option2 == 1)
		game.attack1(shadow, barb);
	else if (option1 == 5 && option2 == 2)
		game.attack1(shadow, blue);
	else if (option1 == 5 && option2 == 3)
		game.attack1(shadow, reptile);
	else if (option1 == 5 && option2 == 4)
		game.attack1(shadow, goblin);
	else if (option1 == 5 && option2 == 5)
		game.attack1(shadow, shadow2);

}