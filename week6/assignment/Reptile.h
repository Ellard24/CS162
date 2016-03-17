#include "Creature.h"
#pragma once

class Reptile : public Creature
{




public:
	Reptile();
	int rollDefend();
	int rollAttack(Creature *c1);




};