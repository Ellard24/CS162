#pragma once
#include "Barbarian.h"

class Stack
{

private:
	struct LoserPile
	{
		Creature *c1;
		LoserPile *next;
		//LoserPile *prev;

	};
	int size;
	LoserPile *head;

public:
	Stack();
	~Stack();
	void addFighter(Creature *c1);
	void display();
	string returnWinners();
	int getSize();

};
