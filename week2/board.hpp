#include <string>
using namespace std;
#ifndef BOARD_HPP
#define BOARD_HPP

class board
{

public:
	board();
	void checkX(string array1[40][80], string tempArray[40][80]);
	void checkEmpty(string array1[40][80], string tempArray[40][80]);
	void displayBoard(string arrayName[40][80]);
	void checkGun(string arrayName[40][80], string tempArray[40][80], int ycord);
	void checkGunEmpty(string arrayName[40][80], string tempArray[40][80], int ycord);


};

#endif