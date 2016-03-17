#pragma once
#include "Barbarian.h"
#include <iostream>
using namespace std;

class Combat
{





public:
	/********************************************************
	**Function:attack1()
	**Description:This is the main combat function that the created 
	subclasses get passed to to see who wins.
	**Parameters: Creature *b1, Creature *r1
	**Pre-Conditions: Monsters must be created and passed to function
	**Post-Conditions: Results get displayed to screen
	*********************************************************/
	
	
	void attack1(Creature *b1, Creature *r1)
	{
		while (b1->getStrength() > 0 && r1->getStrength() > 0)
		{
			int attack1 = r1->rollAttack(b1);
			
			if (r1->getName() == "Goblin" && b1->getName() != "Goblin")
			{
				if (attack1 >= 12 && b1->getAchilles() != true)
				{
					b1->setAchilles(true);
					cout << "Goblin activates his special ability." << endl;
				}
			}

			if (attack1 == false)
			{
				cout << "No defense roll happens" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				int defend1 = b1->rollDefend();


				if (attack1 > defend1)
				{



					int damage = attack1 - defend1 - b1->getArmor();
					cout << b1->getName() << " has " << b1->getArmor() << " armor" << endl;

					if (damage >= 1)
					{
						//cout << "Barbarian has " << b1->getArmor() << " armor" << endl;
						cout << "Damage after mitigation is " << damage << endl;

						cout << b1->getName() << " has " << b1->getStrength() << " strength" << endl;
						b1->setStrength(damage);
						cout << b1->getName() << "'s strength is reduced by " << damage << " and now has " << b1->getStrength() << " strength" << endl;
						if (b1->getStrength() <= 0)
						{
							cout << b1->getName() << " won't make it but does one last attack :( " << endl;

						}

					}
					else
						cout << "No damage was taken this turn" << endl;
				}

				else
				{

					cout << "No damage was taken this turn" << endl;
				}




				cout << b1->getName() << " now counter attacks" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;


			}


			int attack2 = b1->rollAttack(r1);

			if (b1->getName() == "Goblin" && r1->getName() != "Goblin")
			{
				if (attack2 >= 12 && r1->getAchilles() != true)
				{
					r1->setAchilles(true);
					cout << "Goblin activates his special ability." << endl;
				}
			}
			
			if (attack2 == false)
			{
				cout << "No Defense roll happens" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				int defend2 = r1->rollDefend();

				if (attack2 > defend2)
				{



					int damage = attack2 - defend2 - r1->getArmor();
					cout << r1->getName() << " has " << r1->getArmor() << " armor" << endl;

					if (damage >= 1)
					{

						cout << "Damage after mitigation is " << damage << endl;

						cout << r1->getName() << " has " << r1->getStrength() << " strength" << endl;
						r1->setStrength(damage);
						cout << r1->getName() << "'s strength is reduced by " << damage << " and now has " << r1->getStrength() << " strength" << endl;

						if (r1->getStrength() <= 0)
						{
							cout << r1->getName() << " didn't make it :( " << endl;

						}
					}
					else
						cout << "No damage taken this turn" << endl;
				}

				else
				{

					cout << "No damage was taken this turn" << endl;
				}
				cout << endl;
				cout << endl;
				cout << endl;
			}
			
			
		}

		cout << "The fight is over" << endl;





	}




};
