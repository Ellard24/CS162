#include <time.h>
#pragma once
using namespace std;

class Die
{
protected:
	int sides;
public:
	void set_sides(int);
	int die_roll();
};


