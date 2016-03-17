#pragma once
#include <string>
using namespace std;



class space
{


protected:


	

	space *north;
	space *east;
	space *south;
	space *west;

	string roomName;
	int roomID;
	bool door1; 
	
	bool bedKey;
	bool gardenKey;
	bool diningKey;
	bool finalTest;
	bool potion;
	bool victory;

	int plantCheck;
	int dining;
	int bedCheck;


public:
	virtual void description() = 0;
	space *returnNorth();
	space *returnSouth();
	space *returnEast();
	space *returnWest();

	string returnRoomName();

	void setNorth(space *room);
	void setEast(space *room);
	void setSouth(space *room);
	void setWest(space *room);


	void setDirections(space *room, space *room2, space *room3, space *room4);

	void checkDirection(int x);
	void changeRoom(space **player);

	space();
	space(string name1, int room);

	virtual void checkRoom() = 0;


	void doorCheck();				//sets door1 to true if all three keys are in inventory


	bool getBedKey();
	void setBedKey();
	
	bool getGardenKey();
	void setGardenKey();

	bool getDiningKey();
	void setDiningKey();


	bool getFinalTest();
	void setFinalTest();


	bool getPotion();
	void setPotion();


	bool getVictory();
	void setVictory();


};