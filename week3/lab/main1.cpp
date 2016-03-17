/***************************************************
*Program FileName: main1.cpp
*Author: Ellard Gerritsen van der Hoop
*Date: 10/15/2015
*Input: All input comes during runtime
*Output: Score is shown and winner is determined and
displayed to screen.
***************************************************/






#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "LoadedDie.h"
#include "Game.h"
#include <string>
using namespace std;


/***********************************************
*Function:Main
*Description: Runs the Game of War Program using
the Classes Game,Die, and Loaded_Die. Two Player
game that lets you pick what die you want and picks
winner
*Parameters: None
*Pre-Conditions: -
*Post-Conditions:-
************************************************/
int main()
{
	Game Game1;
	srand(time(0));
	string player1;
	string player2;
	int sides = 0;
	int rounds = 0;
	string repeat = "Yes";


	cout << "Welcome to the Game of War" << endl;

	while (repeat == "Yes")
	{

		cout << "How many rounds do you want to play" << endl;
		cin >> rounds;
		Game1.setRound(rounds);

		cout << "How many sides do you want to have on your die" << endl;
		cin >> sides;

		cout << "Player 1 and Player 2 have the option of using a Loaded Die if they please" << endl;
		cout << "Type in either 'true' if you want to use a loaded dice or 'false' if you want a normal dice" << endl;

		cout << "Player 1: " << endl;
		cin >> player1;

		cout << "Player 2: " << endl;
		cin >> player2;


		if (player1 == "true")
			Game1.setFairnessP1();
		if (player2 == "true")
			Game1.setFairnessP2();

		Game1.setSides(sides);
		Game1.setsides(sides);

		for (int i = 0; i < Game1.getRound(); i++)
		{
			// Situation where both Normal Dice
			if (Game1.getFairnessP1() == false && Game1.getFairnessP2() == false)
			{
				int P1 = Game1.roll();
				int P2 = Game1.roll();



				if (P1 > P2)
				{
					cout << "Player 1 Scores the point" << endl;
					Game1.setScoreP1();


				}

				else if (P1 < P2)
				{
					cout << "Player 2 Score the point" << endl;
					Game1.setScoreP2();
				}

				else
					cout << "It's a Draw. No point is given" << endl;


				cout << "Current Score" << endl;
				cout << " Player 1: " << Game1.getScoreP1() << endl;
				cout << " Player 2: " << Game1.getScoreP2() << endl;

			}


			//Situation where One Loaded and One Normal

			else if (Game1.getFairnessP1() == false && Game1.getFairnessP2() == true)
			{

				int P1 = Game1.roll();
				int P2 = Game1.loadedRoll();


				if (P1 > P2)
				{
					cout << "Player 1 Scores the point" << endl;
					Game1.setScoreP1();


				}

				else if (P1 < P2)
				{
					cout << "Player 2 Score the point" << endl;
					Game1.setScoreP2();
				}

				else
					cout << "It's a Draw. No point is given" << endl;


				cout << "Current Score" << endl;
				cout << " Player 1: " << Game1.getScoreP1() << endl;
				cout << " Player 2: " << Game1.getScoreP2() << endl;



			}

			else if (Game1.getFairnessP1() == true && Game1.getFairnessP2() == false)
			{

				int P1 = Game1.loadedRoll();
				int P2 = Game1.roll();

				if (P1 > P2)
				{
					cout << "Player 1 Scores the point" << endl;
					Game1.setScoreP1();


				}

				else if (P1 < P2)
				{
					cout << "Player 2 Score the point" << endl;
					Game1.setScoreP2();
				}

				else
					cout << "It's a Draw. No point is given" << endl;


				cout << "Current Score" << endl;
				cout << " Player 1: " << Game1.getScoreP1() << endl;
				cout << " Player 2: " << Game1.getScoreP2() << endl;

			}



			//Situation where Two Loaded Dice
			else if (Game1.getFairnessP1() == true && Game1.getFairnessP2() == true)
			{
				int P1 = Game1.loadedRoll();
				int P2 = Game1.loadedRoll();

				if (P1 > P2)
				{
					cout << "Player 1 Scores the point" << endl;
					Game1.setScoreP1();


				}

				else if (P1 < P2)
				{
					cout << "Player 2 Score the point" << endl;
					Game1.setScoreP2();
				}

				else
					cout << "It's a Draw. No point is given" << endl;


				cout << "Current Score" << endl;
				cout << " Player 1: " << Game1.getScoreP1() << endl;
				cout << " Player 2: " << Game1.getScoreP2() << endl;
			}



		}

		Game1.pickWinner();

		cout << "Do you want to play again? Type 'Yes' or 'No' " << endl;
		cin >> repeat;





	}
}