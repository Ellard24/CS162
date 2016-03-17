/*******************************************************************
 ** Program FileName: RollDie.cpp
 ** Author: Ellard Gerritsen van der Hoop
 ** Date: 10/1/15
 ** Description: main file for Roll die program. Rolls a die and a 
 ** loaded die and reports the number of times rolled as well as the 
 ** results. 
 ** Input:   All input taken during run time including sides/rolls
 ** Output:  The results of the rolls of the normal die class versus
 ** 	     the loadedDie class. The number of rolls and rolls higher
 ** 	     than half the number of sides are also reported.
 * ****************************************************************/





#include "Die.hpp"
#include "LoadedDie.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;



/************************************************************************
** Function: Main function
** Description: asks for sides of die as well as how many rolls
** Then it sets the seed for the random number generator. Two objects are 
** made one for each die class.
** Paramters: -
** Pre-Conditions:   -
** Post-Conditions:  Two objects are made that compare a die to loaded die
**		     Results are output to show the difference.
************************************************************************/

int main()
{
	int userRoll;
	int sides;


	cout << "How many sides do you want on your die?" << endl;
	cin >> sides;
	

	cout << "How many times do you want to roll a die ?" << endl;
	cin >> userRoll;

	srand(time(0));
	
	Die die1;
	LoadedDie die2;

	

	cout << "The normal die is rolled: " << userRoll << " times" << endl;

	
	die1.rollDie(sides, userRoll);
	

	cout << "The loaded die is rolled: " << userRoll << " times" << endl;
	
	
	die2.rollDie(sides, userRoll);

	




	return 0;
}
