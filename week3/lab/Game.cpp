#include <iostream>
#include "Game.h"

/***********************************************
*Function:Game Constructor
*Description: Sets Score, rounds to 0 and
sets fairness to False.
*Parameters: None
*Pre-Conditions: -
*Post-Conditions:-
************************************************/
Game::Game()
{
	scoreP1 = 0;
	scoreP2 = 0;
	round = 0;
	player1Fair = false;
	player2Fair = false;

}
/***********************************************
*Function:getScoreP1
*Description: Getter function for ScoreP1
*Parameters: None
*Pre-Conditions: -
*Post-Conditions:-
************************************************/

int Game::getScoreP1()
{
	return scoreP1;


}
/***********************************************
*Function:setScoreP1
*Description: Increases the score for P1 by an
increment of 1
*Parameters: None
*Pre-Conditions: Score set to 0 by constructor
or in middle of game
*Post-Conditions:Score retrieved to check who wins
************************************************/
void Game::setScoreP1()
{
	scoreP1++;


}
/***********************************************
*Function:getScoreP2()
*Description: Getter function for ScoreP2
*Parameters: None
*Pre-Conditions: -
*Post-Conditions:-
************************************************/
int Game::getScoreP2()
{
	return scoreP2;


}
/***********************************************
*Function:setScoreP2()
*Description: Increases the score for P1 by an
increment of 1
*Parameters: None
*Pre-Conditions: -
*Post-Conditions:-
************************************************/
void Game::setScoreP2()
{
	scoreP2++;


}

/***********************************************
*Function:getRound()
*Description: Getter function for data member
Rounds
*Parameters: None
*Pre-Conditions: Rounds must be initiliazed
*Post-Conditions: Round can be retrieved
************************************************/
int Game::getRound()
{

	return round;

}
/***********************************************
*Function: setRound
*Description: Sets the number of rounds to be played
by the Game of War
*Parameters: int rounds
*Pre-Conditions: -
*Post-Conditions: Rounds can be retrieved or increased
************************************************/
void Game::setRound(int rounds)
{

	round = rounds;


}

/***********************************************
*Function:getFairnessP1()
*Parameters: None
*Description: Getter function for FairnessP1
*Pre-Conditions: FairnessP1 needs to be set
to false or true
*Post-Conditions:Determines the dice picked
************************************************/
bool Game::getFairnessP1()
{
	return player1Fair;


}
/***********************************************
*Function:getFairnessP2()
*Description: Getter function for FairnessP2
*Parameters: None
*Pre-Conditions: FairnessP2 needs to be set
to false or true
*Post-Conditions:Determines the dice picked
************************************************/
bool Game::getFairnessP2()
{

	return player2Fair;

}
/***********************************************
*Function:setFairnessP1()
*Description: Sets the fairness for Player1 which
will determine the dice picked
*Parameters: None
*Pre-Conditions: -
*Post-Conditions: Fairness sets dice pick
************************************************/
void Game::setFairnessP1()
{
	player1Fair = true;




}
/***********************************************
*Function:setFairnessP2()
*Description: Sets the fairness for Player2 which
will determine the dice picked
*Parameters: None
*Pre-Conditions: -
*Post-Conditions: Fairness sets dice pick
************************************************/
void Game::setFairnessP2()
{
	player2Fair = true;
}


/***********************************************
*Function:pickWinner
*Description: Checks score and determines winner
based on which player has highest score
*Parameters: None
*Pre-Conditions: Rounds must be finished looping
*Post-Conditions: User is prompted to restart game
************************************************/
void Game::pickWinner()
{
	if (scoreP1 > scoreP2)
		cout << "Player 1 wins" << endl;
	else if (scoreP1 == scoreP2)
		cout << "It is a tie" << endl;
	else
		cout << "Player 2 wins" << endl;
}

/***********************************************
*Function:setSides
*Description: Sets the sides for die1 which is
the normal dice.
*Parameters: int sides
*Pre-Conditions: -
*Post-Conditions: Sides can be used to start
roll function
************************************************/
void Game::setSides(int sides)
{

	die1.set_sides(sides);


}

/***********************************************
*Function:setsides
*Description: Sets the sides for die2 which is the
loaded_dice
*Parameters: int sides
*Pre-Conditions: -
*Post-Conditions: Sides can be used to start
loaded roll function.
************************************************/
void Game::setsides(int sides)
{
	die2.set_sides(sides);

}


/***********************************************
*Function:roll()
*Description: Rolls the normal dice
*Parameters: None
*Pre-Conditions: Sides must be set
*Post-Conditions: Score can be determined based
on higher roll between two players
************************************************/
int Game::roll()
{

	return die1.die_roll();


}


/***********************************************
*Function:loadedRoll()
*Description: Rolls the loaded dice
*Parameters: None
*Pre-Conditions: Sides must be set
*Post-Conditions: Score can be determined based
on higher roll between two players
************************************************/
int Game::loadedRoll()
{


	return die2.loaded_roll();

}