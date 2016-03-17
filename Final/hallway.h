#include "space.h"
#pragma once



class hallway : public space
{

public:
	void checkRoom();
	void description();

	hallway(string name1,int room);

	hallway();

};