#include "Creature.h"
#pragma once

class Shadow : public Creature
{



public:
	
	Shadow();
	int rollDefend();
	int rollAttack(Creature *c1);




};