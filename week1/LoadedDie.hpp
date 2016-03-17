#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP


class LoadedDie{

private:
	int sides;


public:
	LoadedDie();
	LoadedDie(int userSides);
	void rollDie(int sides, int userRoll);



};

#endif