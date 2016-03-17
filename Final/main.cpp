#include <iostream>
#include "Game.h"
#include "space.h"
#include "normal.h"
#include "bedroom.h"	
#include "door.h"
#include "garden.h"
#include "hallway.h"
#include "final.h"
#include "inventory.h"
#include <vector>
#include <algorithm>

using namespace std;

bool keyCheck(Inventory &inv1);
void cheatMenu();



/****************************************************************************
**Function: main
**Description: Runs the simulation 
**Parameters: -
**Pre-Conditions:-
**Post-Conditions:-
******************************************************************************/
int main()
{
	//creating rooms
	normal *room1 = new normal("Entrance- Room 1", 1);		//good
	hallway *room2 = new hallway("Hallway - Room 2", 2);		//good
	normal *room3 = new normal("Dining Hall- Room 3", 3);			//good
	hallway *room4 = new hallway("Hallway - Room4", 4);			//good
	hallway *room5 = new hallway("Hallway - Room 5", 5);		//good
	normal *room6 = new normal("Living Room - Room 6", 6);
	normal *room7 = new normal("Laboratory - Room 7", 7);
	hallway *room8 = new hallway("Hallway - Room 8", 8);		//good
	hallway *room9 = new hallway("Hallway - Room 9", 9);		//good, more maybe?
	normal *room10 = new normal("Conservatory - Room 10", 10);
	normal *room11 = new normal("Kitchen - Room 11", 11);			//good	
	garden *room12 = new garden("Garden - Room 12", 12);				//good maybe change dumb puzzle
	bedroom *room13 = new bedroom("Bedroom - Room 13", 13);
	hallway *room14 = new hallway("Hallway - Room 14", 14);
	hallway *room15 = new hallway("Hallway - Room 15", 15);
	door *room16 = new door("Door Room - Room 16", 16);
	finalRoom *room17 = new finalRoom("Final Room - Room 17", 17);		//need something special for this one


	//set pointers 
	room1->setDirections(room2, 0, 0, 0);
	room2->setDirections(room3, room1, 0, 0);
	room3->setDirections(0, room2, room4, room5);
	room4->setDirections(0, 0, room6, room3);
	room5->setDirections(0, 0, room3, room7);
	room6->setDirections(room8, 0, 0, room4);
	room7->setDirections(room9, 0, room5, 0);
	room8->setDirections(room10, room6, 0, 0);
	room9->setDirections(room11, room7, 0, 0);
	room10->setDirections(room12, room8, 0, room14);
	room11->setDirections(room13, room9, room15, 0);
	room12->setDirections(0, room10, 0, 0);
	room13->setDirections(0, room11, 0, 0);
	room14->setDirections(0, 0, room10, room16);
	room15->setDirections(0, 0, room16, room11);
	room16->setDirections(room17, 0, room14, room15);
	room17->setDirections(0, room16, 0, 0);
	
	//create game
	Game Game1;

	//show instructions 
	Game1.readInstructions();
	string cheat;
	cout << "For Grading Purposes: Do you want to see the answers?" << endl;
	cin >> cheat;
	if (cheat == "yes")
		cheatMenu();
	else
		cout << "Game is Starting " << endl;
	
	
	
	bool victory = false;

	//create inventory
	Inventory inventory1;
	
	
	//set location
	space *player = room1;
	string location = player->returnRoomName();
	int choice = 0;
	
	//Create items
	Item *bedroomKey = new Item("bedroom key");
	
	Item *gardenKey = new Item("garden key");
	Item *diningKey = new Item("dining key");
	Item *sanityPotion = new Item("sanity potion");

	


	while (room17->getVictory() == false && Game1.getSanity() != 0)
	{
		Game1.setMoveMade();    //sets to false for each turn
		
		//perform key check
		if (keyCheck(inventory1) == true)
				room16->getKeys();
		
		string location = player->returnRoomName();
		//cout << "You are currently in " << location << endl;
		cout << endl << endl << endl;



		while (Game1.getMoveMade() == false)
		{
			

			//check all key conditions
			if (room13->getBedKey() == true)				// we can change this checking process into a function later 
			{
				inventory1.addItem(bedroomKey);
				room13->setBedKey();
				
			}
			
			if (room12->getGardenKey() == true)
			{
				inventory1.addItem(gardenKey);
				room12->setGardenKey();
			}
			
			if (room3->getDiningKey() == true)
			{
				inventory1.addItem(diningKey);
				room3->setDiningKey();
			}

			if (room17->getFinalTest() == true)
			{
				room7->setFinalTest();
			}

			if (room7->getPotion() == true)
			{
				inventory1.addItem(sanityPotion);
				room7->setPotion();
				room17->setPotion();
			}

			Game1.showMenu();
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				int check = Game1.displayDirections();
				player->checkDirection(check);
				break;
			}
			case 2:
			{
				player->changeRoom(&player);
				Game1.setMoveMade();  //should set to true
				break;
			}
			case 3:
				cout << "Check Room" << endl;
				player->checkRoom();
				Game1.setMoveMade();
				break;
			case 4:
			{
				Game1.displaySanity();
				break;
			}
			case 5:
				inventory1.displayItems();
				break;

			}



		}
		



		Game1.decreaseSanity();
		location = player->returnRoomName();
	//	if (location == "Final Room - Room 17")
		//	victory = true;
	}

	if (Game1.getSanity() != 0)
	{
		cout << endl << endl << endl;

		cout << "The darkness disappears and the door is open again" << endl;
		cout << "You leave the house unsure of what really happened or if any of it was real" << endl;
		cout << "But a sense of relief washes over you and you never look back again" << endl;

	}

	else if (Game1.getSanity() == 0)
	{
		cout << endl << endl << endl;

		cout << "As you lose control of your mind, you realize that you are never going to make it out" << endl;
		cout << "Game Over" << endl;


	}
	
	delete room1;
	room1 = 0;
	delete room2;
	room2 = 0;
	delete room3;
	room3 = 0;
	delete room4;
	room4 = 0;
	delete room5;
	room5 = 0;
	delete room6;
	room6 = 0;
	delete room7;
	room7 = 0;
	delete room8;
	room8 = 0;
	delete room9;
	room9 = 0;
	delete room10;
	room10 = 0;
	delete room11;
	room11 = 0;
	delete room12;
	room12 = 0;
	delete room13;
	room13 = 0;
	delete room14;
	room14 = 0;
	delete room15;
	room15 = 0;
	delete room16;
	room16 = 0;
	delete room17;
	room17 = 0;
	delete bedroomKey;
	bedroomKey = 0;
	delete gardenKey;
	gardenKey = 0;
	delete diningKey;
	diningKey = 0;
	delete sanityPotion;
	sanityPotion = 0;

	return 0;
}


/****************************************************************************
**Function: keyCheck
**Description: Checks inventory for keys
**Parameters: Inventory &inv1
**Pre-Conditions:  Inventory needs to need
**Post-Conditions:  If all three keys are in backpack, door opens
******************************************************************************/
bool keyCheck(Inventory &inv1)
{
	int keys = 0;
	for (int i = 0; i < inv1.getItems().size(); i++)
	{
		if (inv1.getItems()[i].getName() == "bedroom key")
			keys++;
		if (inv1.getItems()[i].getName() == "garden key")
			keys++;
		if (inv1.getItems()[i].getName() == "dining key")
			keys++;
	}


	if (keys == 3)
	{
		return true;
	}

}


//Cheat Menu for TA/Grading
void cheatMenu()
{

	cout << "The keys are the dining room, the garden, and the bedroom" << endl;
	cout << "For the dining key, just keep saying yes" << endl;
	cout << "For the garden key,the answer is 8" << endl;
	cout << "For the bedroom, its 3,7,4,8 " << endl;
	cout << "Insert keys into door in door room" << endl;
	cout << "Help the man out. Go to laboratory now" << endl;
	cout << "Put potions in this order" << endl;
	cout << "blue red green yellow orange" << endl;
	cout << "return to man, talk to him and win" << endl;

	cout << "You only have about 50 turns so go fast" << endl;





}
