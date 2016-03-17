#include "Creature.h"
#pragma once

class Barbarian : public Creature
{

protected:
	//Barbarian *b1;


public:
	
	Barbarian();
	int rollDefend();
	int rollAttack(Creature *c1);


};