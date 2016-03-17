/************************************************************
** Program FileName: GameOfLife
** Author: Ellard Gerritsen van der Hoop
** Date: 10/4/15
** Description: Game of Life simulation with three different objects
** Input: All inputs taken during run time from user.
** Output: Text based board showing iterations of objects through life and death 
***************************************************************/


#include <iostream>
#include <string>
#include "board.hpp"
#include <cstdlib> 
#include <unistd.h>
using namespace std;

/****************************************************
** Function: main
** Description: Establishes board and then runs through 
**				simulations based on user input 
** Parameters: -
** Pre-Conditions: -
** Post Conditions: -
****************************************************/
int main()
{
	int option = 0;


	string array1[40][80];
	string tempArray[40][80];
	string gunArray[40][80];

	cout << "This is The Game Of Life by Conway" << endl;
	cout << "You will have the option to pick from three different options" << endl;
	cout << "1.) A Fixed Oscillator  2.) A Glider   3.) A Glider Cannon " << endl;

	cout << "What option do you want to go with? Please enter 1, 2, or 3 " << endl;

	cin >> option;

	board board1;

	//Create the array of 20 x 40(20 rows, 40 columns)

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 80; j++)
			array1[i][j] = "-";
			
	}
	
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 80; j++)
			gunArray[i][j] = "-";
			
	}


	/* User will be able to decide by typing '1' '2' or '3' for what object they want to use */


	if (option == 1)
	{
		int xcord, ycord;
		cout << "Beginning the Fixed Oscillator Scenario" << endl;
		cout << "What starting coordinates do you want? " << endl;
		cout << "X: " << endl;
		cin >> xcord;
		cout << "Y: " << endl;
		cin >> ycord;

		cout << "I'll show you the starting location on the board now" << endl;

		//Putting object on game board
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				if (i == xcord && j == ycord)
				{
					array1[i][j] = "x";
					array1[i][j - 1] = "x";
					array1[i][j + 1] = "x";
					
					
				}
			}
		}

		board1.displayBoard(array1);

		string answer = "frame";

		while (answer == "frame")
		{
			cout << "Beginning iterations of generation to generation" << endl;


			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 80; j++)
					tempArray[i][j] = array1[i][j];
			}


			// Checking for number of cells around each "x" that are also an "x" to determine life or death 

			board1.checkX(array1, tempArray);

			board1.checkEmpty(array1, tempArray);


			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 80; j++)
					array1[i][j] = tempArray[i][j];
			}

			cout << endl;
			cout << endl;
			cout << endl;

			board1.displayBoard(array1);

			cout << "Do you want to continue frame by frame or see it as an animation? Type 'frame' for frame by frame and 'animation' for the other" << endl;
			cin >> answer;


			if (answer == "animation")
			{
				cout << "How many loops do you want?" << endl;
				int count = 0;
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					for (int i = 0; i < 40; i++)
					{
						for (int j = 0; j < 80; j++)
							tempArray[i][j] = array1[i][j];
					}


					// Checking for number of cells around each "x" that are also an "x" to determine life or death 

					board1.checkX(array1, tempArray);

					board1.checkEmpty(array1, tempArray);


					for (int i = 0; i < 40; i++)
					{
						for (int j = 0; j < 80; j++)
							array1[i][j] = tempArray[i][j];
					}

					cout << endl;
					cout << endl;
					cout << endl;

					system("clear");
					board1.displayBoard(array1);
					usleep(25000);

				}
			}



		}
		cout << "Thanks for playing" << endl;
	}
	else if (option == 2)
	{
		cout << "Beginning the Glider Scenario" << endl;
		int xcord, ycord;

		cout << "What starting coordinates do you want? " << endl;
		cout << "X: " << endl;
		cin >> xcord;
		cout << "Y: " << endl;
		cin >> ycord;

		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				if (i == xcord && j == ycord)
				{
					array1[i][j + 1] = "x";
					array1[i - 1][j] = "x";
					array1[i + 1][j + 1] = "x";
					array1[i + 1][j] = "x";
					array1[i + 1][j - 1] = "x";

				}
			}
		}




		cout << "Glider will be built around the starting point you picked" << endl;
		cout << "I'll show you the starting location on the board now" << endl;

		board1.displayBoard(array1);

		string answer = "frame";

		while (answer == "frame")
		{
			cout << "Beginning iterations of generation to generation" << endl;


			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 80; j++)
					tempArray[i][j] = array1[i][j];
			}


			// Checking for number of cells around each "x" that are also an "x" to determine life or death 

			board1.checkX(array1, tempArray);

			board1.checkEmpty(array1, tempArray);


			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 80; j++)
					array1[i][j] = tempArray[i][j];
			}

			cout << endl;
			cout << endl;
			cout << endl;

			board1.displayBoard(array1);

			cout << "Do you want to continue frame by frame or see it as an animation ? Type 'frame' for frame by frame and 'animation' for the other? " << endl;
			cin >> answer;

			if (answer == "animation")
			{
				cout << "How many loops do you want?" << endl;
				int count = 0;
				cin >> count;
				for (int i = 0; i < count; i++)
				{
					for (int i = 0; i < 40; i++)
					{
						for (int j = 0; j < 80; j++)
							tempArray[i][j] = array1[i][j];
					}


					// Checking for number of cells around each "x" that are also an "x" to determine life or death 

					board1.checkX(array1, tempArray);

					board1.checkEmpty(array1, tempArray);


					for (int i = 0; i < 40; i++)
					{
						for (int j = 0; j < 80; j++)
							array1[i][j] = tempArray[i][j];
					}

					cout << endl;
					cout << endl;
					cout << endl;

					system("clear");
					board1.displayBoard(array1);
					usleep(25000);
				}
			}

		}
		cout << "Thanks for playing" << endl;



	}



	else if (option = 3)
	{
		cout << "Beginning the Glider Cannon Scenario" << endl;
		int xcord, ycord;
		cout << "What starting coordinates do you want? " << endl;
		cout << "X: " << endl;
		cin >> xcord;
		cout << "Y: " << endl;
		cin >> ycord;

		cout << "I'll show you the starting location on the board now" << endl;




		//Putting object on game board
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				if (i == xcord && j == ycord)
				{
					array1[i][j] = "x";
					array1[i][j + 1] = "x";
					array1[i + 1][j + 1] = "x";
					array1[i + 1][j] = "x";
					array1[i][j + 4] = "x";
					array1[i - 1][j + 3] = "x";
					array1[i + 1][j + 2] = "x";
					array1[i + 1][j + 3] = "x";
					array1[i + 1][j + 4] = "x";
				}
			}
		}
		
		

		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				if (i == xcord && j == ycord)
				{
					gunArray[i][j + 4] = "x";
					gunArray[i - 1][j + 3] = "x";
					gunArray[i + 1][j + 2] = "x";
					gunArray[i + 1][j + 3] = "x";
					gunArray[i + 1][j + 4] = "x";
				}
			}
		}

		
		


		board1.displayBoard(array1);
		cout << endl;
		cout << endl;

		string answer = "frame";

		while (answer == "frame")
		{
			cout << "Beginning iterations of generation to generation" << endl;




			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 80; j++)
					tempArray[i][j] = "-";
			}

			board1.checkX(gunArray, tempArray);
			board1.checkEmpty(gunArray, tempArray);

			for (int i = 0; i < 40; i++)
			{
				for (int j = ycord + 2; j < 80; j++)
				{
					array1[i][j] = tempArray[i][j];
					gunArray[i][j] = tempArray[i][j];
				}
			}


			cout << endl;
			cout << endl;
			cout << endl;



			board1.displayBoard(array1);
			
			cout << "Starting animation " << endl;
			
			
			answer = "animation";

			if (answer == "animation")
			{
				cout << "How many loops do you want?" << endl;
				int count = 0;
				int glideRestart = 0;
				cin >> count;



				for (int i = 0; i < count; i++)
				{
					

					// Checking for number of cells around each "x" that are also an "x" to determine life or death 

					board1.checkGun(gunArray, tempArray, ycord);

					board1.checkGunEmpty(gunArray, tempArray, ycord);

					
					for (int i = 0; i < 40; i++)
					{
						for (int j = ycord + 2; j < 80; j++)
						{
							array1[i][j] = tempArray[i][j];
							gunArray[i][j] = tempArray[i][j];
						}
						
					}

					

					
					cout << endl;
					cout << endl;
					cout << endl;

					system("clear");
					board1.displayBoard(array1);
					usleep(25000);
					glideRestart++; 

					if (glideRestart % 20 == 0)
					{
						for (int i = 0; i < 40; i++)
						{
							for (int j = 0; j < 80; j++)
							{ 
								if (i == xcord && j == ycord)
								{
									gunArray[i][j + 4] = "x";
									gunArray[i - 1][j + 3] = "x";
									gunArray[i + 1][j + 2] = "x";
									gunArray[i + 1][j + 3] = "x";
									gunArray[i + 1][j + 4] = "x";
								}
							}
								
						}

					}
					system("clear");
			
				}
			}
		}

	
	}

	return 0;
}
