#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Die.h"



void Die::set_sides(int x)
{
	sides = x;
	cout << "there are this many sides on the die " << sides << endl;
}

int Die::die_roll()
{
	int c = 0;
	c = rand() % sides + 1;
	cout << "the roll of the dice was " << c << endl;
	return c;
}