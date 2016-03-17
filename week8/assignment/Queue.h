#pragma once
#include "Barbarian.h"

class Queue
{

private:
	struct LineUp
	{
		Creature *c1;
		LineUp *next;
		LineUp *prev;

	};

	LineUp *front;
	LineUp *back;
	int size;

public:
	Queue();
	~Queue();
	void addFighter(Creature *creature);
	void removeFighter();
	void display();
	Creature *returnFront();
	int getSize();
	void moveBack();




};
