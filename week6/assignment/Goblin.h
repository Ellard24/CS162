#include "Creature.h"
#pragma once

class Goblin : public Creature
{



public:
	
	Goblin();
	int rollDefend();
	int rollAttack(Creature *c1);






};