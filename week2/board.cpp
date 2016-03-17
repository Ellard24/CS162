#include <iostream>
#include <string>
using namespace std;
#include "board.hpp"

/****************************************************
** Function: Board 
** Description: Constructor
** Parameters: - 
** Pre-Conditions: -
** Post Conditions: -
****************************************************/


board::board()
{




}

/****************************************************
** Function: checkX
** Description: Searches through array to check for neighboring X's
** Parameters: string array1 and string tempArray
** Pre-Conditions: Arrays must have values stored 
** Post Conditions: Values are stored in the tempArray and array1 is checked for empty cells
****************************************************/

void board::checkX(string array1[40][80], string tempArray[40][80])
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 80; j++)
		{

			if (array1[i][j] == "x")
			{
				int cells = 0;

				if ((i - 1) >= 0 && (j - 1) >= 0 && array1[i - 1][j - 1] == "x")
					cells++;
				if ((i - 1) >= 0 && array1[i - 1][j] == "x")
					cells++;
				if (array1[i - 1][j + 1] == "x")
					cells++;
				if ((i - 1) >= 0 && (j + 1) >= 0 && array1[i][j - 1] == "x")
					cells++;
				if ((j + 1) >= 0 && array1[i][j + 1] == "x")
					cells++;
				if ((i + 1) < 20 && (j - 1) >= 0 && array1[i + 1][j - 1] == "x")
					cells++;
				if ((i + 1) < 20 && array1[i + 1][j] == "x")
					cells++;
				if ((i + 1) < 20 && (j + 1) < 40 && array1[i + 1][j + 1] == "x")
					cells++;


				if (cells == 2 || cells == 3)
					tempArray[i][j] = "x";
				if (cells <= 1)
					tempArray[i][j] = "-";
				if (cells > 3)
					tempArray[i][j] = "-";

			}


		}
	}





}

/***************************************************************************
** Function: checkEmpty
** Description: Checks array for empty cells and then sees if life will happen
** Parameters: string array1 and string tempArray
** Pre-Conditions: array1 needs to have values for some of its contents. 
** Post Conditions: array1 will get new values stored from temp
****************************************************/

void board::checkEmpty(string array1[40][80], string tempArray[40][80])
{
	for (int i = 1; i < 39; i++)
	{
		for (int j = 1; j < 79; j++)
		{

			if (array1[i][j] == "-")
			{
				int cells = 0;

				if (array1[i - 1][j - 1] == "x")
					cells++;
				if (array1[i - 1][j] == "x")
					cells++;
				if (array1[i - 1][j + 1] == "x")
					cells++;
				if (array1[i][j - 1] == "x")
					cells++;
				if (array1[i][j + 1] == "x")
					cells++;
				if (array1[i + 1][j - 1] == "x")
					cells++;
				if (array1[i + 1][j] == "x")
					cells++;
				if (array1[i + 1][j + 1] == "x")
					cells++;

				//check for life or death


				if (cells == 3)
					tempArray[i][j] = "x";

			}

		}
	}






}

/****************************************************
** Function: displayBoard
** Description: Displays the array to show live and dead cells
** Parameters: string arrayName
** Pre-Conditions:  array needs values
** Post Conditions: Loops into life and death sequence
****************************************************/
void board::displayBoard(string arrayName[40][80])
{

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
			cout << arrayName[i][j];
		cout << endl;
	}

}

/****************************************************
** Function: checkGun
** Description: Checks GunnArray for "x" and then stores them in tempArray
** Parameters: string gunArray and string tempArray, int ycord
** Pre-Conditions: arrays need stored values 
** Post Conditions: gunArray will be checked for empty cells after
****************************************************/

void board::checkGun(string gunArray[40][80], string tempArray[40][80], int ycord)
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 80; j++)
		{

			if (gunArray[i][j] == "x")
			{
				int cells = 0;

				if ((i - 1) >= 0 && (j - 1) > 0 && gunArray[i - 1][j - 1] == "x")
					cells++;
				if ((i - 1) >= 0 && gunArray[i - 1][j] == "x")
					cells++;
				if (gunArray[i - 1][j + 1] == "x")
					cells++;
				if ((i - 1) >= 0 && (j + 1) > 0 && gunArray[i][j - 1] == "x")
					cells++;
				if ((j + 1) > 0 && gunArray[i][j + 1] == "x")
					cells++;
				if ((i + 1) < 20 && (j - 1) > 0 && gunArray[i + 1][j - 1] == "x")
					cells++;
				if ((i + 1) < 20 && gunArray[i + 1][j] == "x")
					cells++;
				if ((i + 1) < 20 && (j + 1) < 40 && gunArray[i + 1][j + 1] == "x")
					cells++;


				if (cells == 2 || cells == 3)
					tempArray[i][j] = "x";
				if (cells <= 1)
					tempArray[i][j] = "-";
				if (cells > 3)
					tempArray[i][j] = "-";

			}


		}
	}





}


/****************************************************
** Function: checkGunEmpty
** Description: Checks gunArray for empty cells and their neighbors to decide life or death
** Parameters: gunArray, tempArray, ycoord
** Pre-Conditions: gunArray needs to have values stored 
** Post Conditions: New values are stored in array and board gets displayed before next loop
****************************************************/
void board::checkGunEmpty(string gunArray[40][80], string tempArray[40][80], int ycord)
{
	for (int i = 1; i < 39; i++)
	{
		for (int j = 1; j < 79; j++)
		{

			if (gunArray[i][j] == "-")
			{
				int cells = 0;

				if (gunArray[i - 1][j - 1] == "x")
					cells++;
				if (gunArray[i - 1][j] == "x")
					cells++;
				if (gunArray[i - 1][j + 1] == "x")
					cells++;
				if (gunArray[i][j - 1] == "x")
					cells++;
				if (gunArray[i][j + 1] == "x")
					cells++;
				if (gunArray[i + 1][j - 1] == "x")
					cells++;
				if (gunArray[i + 1][j] == "x")
					cells++;
				if (gunArray[i + 1][j + 1] == "x")
					cells++;

				//Determins whether life or death


				if (cells == 3)
					tempArray[i][j] = "x";

			}

		}
	}






}

