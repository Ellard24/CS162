/***************************************************************************************
**Author: Ellard Gerritsen
**Description: This program runs two simulations of people entering and leaving a queue(s).
				In the first simulation, there is only one queue. In the second, there are multiple
				The user suggests the number of servers(part1) and servers/queues(part2)
**Input:	All input received during runtime
**Output:   Displays people waiting in queue and the number loops it took for the queue to empty
*******************************************************************************************/

#include <iostream>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


void addQueue(int n, int servers, queue<string> &q1);
void addQueue2(int n, int servers, vector<queue<string> > &v1);

/****************************************************************
**Function: main
**Description: Sets up the simulations and allows user to pick
**Parameters: -
**Pre-Conditions: -
**Post-Conditions: Displays results of simulations to user
******************************************************************/

int main()
{
	int choice = 0;
	int serNum = 0;

	srand(time(0));

	cout << "Queue Waiting Line Simulation" << endl;

	cout << "Two separate simulations will be run" << endl;
	cout << "1.) Simulation using 1 Queue " << endl;
	cout << "2.) Simulation using a Queue per Server" << endl;

	cout << "Please pick the simulation you want to see" << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "You get to pick how many servers you want to have" << endl;
		cout << "How many do you want?" << endl;

		cin >> serNum;


		


		queue<string> q1;

		
		int mult = 1;

		int loopCount = 0;					//amount of loops
		int totalCount = 0;					//total amount of people serviced
		int count = 10;

		while (!q1.empty() || count > 0)
		{
			int n = 0;
			
			if (serNum <= 2)
			{
				n = serNum + 1;
			}
			else
			{
			    n = serNum - 1;
			}

			if (count == 10)
			{
				n = n;
				totalCount += n;
				addQueue(n, serNum, q1);
				mult++;
			}
			else if (count > 5)
			{
				n = (n * mult) + (rand() % n + 1);
				totalCount += n;
				addQueue(n, serNum, q1);
				mult++;
			}
			else
			{
				n = n-n;
				totalCount += n;
				addQueue(n, serNum, q1);


			}


			count--;
			loopCount++;
		}


		cout << "Simulation looped: " << loopCount << " times" << endl;
		cout << "Total amount of people serviced: " << totalCount << endl;


		int result = totalCount / loopCount;
		cout << "People per loop serviced: " << result << endl;

		cout << "End of Simulation 1" << endl;
	}
	
	if (choice == 2)
	{

		cout << "Beginning Simulation 2" << endl;
		cout << "In this simulation, there is a queue for each server" << endl;


		cout << "You get to pick how many servers you want to have" << endl;
		cout << "How many do you want?" << endl;

		cin >> serNum;
		int mult = 1;
		int count = 10;
		int loopCount = 0;
		int totalCount = 0;

		vector<queue<string> > vec1(serNum);

		
		int total = 0;
		for (int i = 0; i < vec1.size(); i++)
		{
			total += vec1[i].size();


		}
		
		while (count > 0 || total != 0)
		{
			int n = 0;

			if (serNum <= 2)
			{
				n = serNum + 1;
				
			}
			else
			{
				n = serNum - 1;
				
			}

			if (count == 10)
			{
				n = n;
				totalCount += n;
				addQueue2(n, serNum, vec1);
				mult++;
			}
			else if (count > 5)
			{
				n = (n * mult) + (rand() % n + 1);
				totalCount += n;
				addQueue2(n, serNum, vec1);
				mult++;
			}
			else
			{
				n = n-n;
				totalCount += n;
				addQueue2(n, serNum, vec1);


			}

			
			total = 0;
			for (int i = 0; i < vec1.size(); i++)
			{
				total += vec1[i].size();


			}

			cout << "Number of people in all queues: " << total << endl;

			count--;
			loopCount++;

		}







		cout << "Simulation looped: " << loopCount << " times" << endl; 
		cout << "Total amount of people serviced: " << totalCount << endl;

		int result = totalCount / loopCount;
		cout << "People per loop serviced: " << result << endl;

		cout << "End of simulation 2" << endl;
	}




	return 0;
}



/****************************************************************
**Function: addQueue
**Description: Runs simulation of one queue as people enter and leave.
			  Displays people waiting and number of loops
**Parameters: int n, int servers, queue<string> &q1
**Pre-Conditions: User must have specified amount of servers
**Post-Conditions: Displays all time related information
******************************************************************/
void addQueue(int n, int servers, queue<string> &q1)
{
	int number = n; 
	
	string person = "customer";

	cout << "People are being added to Queue" << endl;

	
	


	if (number + q1.size() <= servers)
	{
		for (int i = 0; i < q1.size(); i++)
		{
			q1.pop();
		}

		
	}
	else if (number + q1.size() > servers)
	{
		for (int i = 0; i < number; i++)
		{
			q1.push(person);
		}
		
		
		
		for (int i = 0; i < servers; i++)
		{
			q1.pop();

		}
	}
	

	cout << "Size of Queue: " << q1.size() << endl;


}

/****************************************************************
**Function: addQueue2
**Description: Simulates people entering leaving multiple queues.
			 Displays people waiting and number of loops to user
**Parameters: int n, int servers, vector<queue<string>> &v1
**Pre-Conditions: User must have specified number of servers/queues
**Post-Conditions: Differences can be seen between use of single/multi queues
******************************************************************/
void addQueue2(int n, int servers, vector<queue<string> > &v1)
{
	int number = n;
	int total = 0;
	string person = "customer";

	cout << "People are being added to Queues" << endl;
	
	
	
	int j = 0;
	for (int i = 0; i < number; i++)
	{
		
		v1[j].push(person);
		j++;

		if (j > servers -1)
			j = 0;
	}

	
	

	for (int i = 0; i < v1.size(); i++)
	{
		total += v1[i].size();


	}

	j = 0;
	
	if (total - servers > 0)
	{
		int i = servers;
		while (i != 0)
		{
			if (!v1[j].empty())
			{
				v1[j].pop();
				j++;
				i--;
			}
			else if (j < servers - 1)
				j++;
			else
				j = 0;
		}
		


	}
	else
	{
		while (total != 0)
		{
			if (!v1[j].empty())
			{
				v1[j].pop();
				j++;
				total--;
			}
			else if (j < servers - 1)
				j++;
			else
				j = 0;


		}
	}
	



}









