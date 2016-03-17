#include "Creature.h"
#pragma once

class Blue : public Creature
{




public:
	Blue();
	int rollDefend();
	int rollAttack(Creature *c1);



};