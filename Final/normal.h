#include "space.h"
#pragma once
#include <string>
using namespace std;



class normal : public space
{

public:

	void checkRoom();
	void description();


	normal(string name1, int room);

	normal();

	void labTest();

};