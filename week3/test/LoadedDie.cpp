#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LoadedDie.h"





int loaded_die::loaded_roll()
{
	if (rand() % 2 == 0)
	{
		int t = 0;
		t = rand() % 4 + 3;
		cout << "the loaded roll was " << t << endl;
		return t;




	}

	else{
		int h = 0;
		h = rand() % sides + 1;
		cout << "the loaded roll was " << h << endl;
		return h;
	}
}
