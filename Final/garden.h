#include "space.h"
#pragma once



class garden : public space
{




public:
	void checkRoom();
	void description();

	garden(string name1, int room);
	garden();
	void puzzle();


};