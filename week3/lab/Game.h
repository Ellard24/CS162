#include "Die.h"
#include "LoadedDie.h"
#include <iostream>
#pragma once


class Game
{


private:

	int scoreP1;
	int scoreP2;
	int round;
	bool player1Fair;
	bool player2Fair;
	Die die1;
	loaded_die die2;


public:

	Game();
	int getScoreP1();
	void setScoreP1();
	int getScoreP2();
	void setScoreP2();
	int getRound();
	void setRound(int rounds);
	bool getFairnessP1();
	bool getFairnessP2();
	void setFairnessP1();
	void setFairnessP2();
	void pickWinner();
	void setSides(int sides);
	void setsides(int sides);
	int roll();
	int loadedRoll();

	/***
	Die setSides(int sides);
	loaded_die setsides(int sides);
	Die roll(Die die1);
	loaded_die loadedRoll();
	***/

};