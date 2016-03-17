#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Die.h"
#pragma once
using namespace std;

class loaded_die : public Die
{


public:
	int loaded_roll();
};


