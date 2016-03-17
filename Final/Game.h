#pragma once
#include "normal.h"



class Game
{


private:
	int sanity;
	bool moveMade;


public:
	void decreaseSanity();
	void readInstructions();
	void displaySanity();
	bool getMoveMade();
	void setMoveMade();
	int getSanity();
	void showMenu();
	int displayDirections();
	Game();


















};