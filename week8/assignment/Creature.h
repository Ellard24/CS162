#include <string>
#include "Dice.h"
#pragma once
using namespace std;

class Creature
{
protected:

	

	string name;
	Dice attackDie; 
	Dice defenseDie;
	int armor;
	int strength;
	bool achilles;
	int score; 

public:
	Creature();
	Creature(int attackSides, int defenseSides, int armor1, int strength1, string name1);
	virtual int rollAttack(Creature *c1);					// this should roll the die for the attacker
	virtual int rollDefend() = 0;						//this should roll the die for the defender
	int getArmor();
	int getStrength();
	void setStrength(int s);
	void setAchilles(bool achilles1);
	bool getAchilles();
	string getName();
	void setName(string displayName);
	void drinkPotion();		//regeneration of health function
	int returnScore();
	void increaseScore();



};