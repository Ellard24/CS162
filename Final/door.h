#include "space.h"
#pragma once



class door : public space
{
	
private:
	bool keyCheck;




public:
	void checkRoom();
	void description();
	door(string name1, int room);
	door();
	void getKeys();


};