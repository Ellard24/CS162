#include <stdio.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "FibonacciR.h"
#include "FibonacciNR.h"
#include <vector>
#include <string>
using namespace std;


long rfactorial(int n);
long factorialHelper(int n, int result);
long factorial(int n);

void Usage()
{
	cout << "Correct Usage:" << endl;
	cout << "./Fibonacci [n]" << endl;
	
}



int main() 
{
	vector<int> Recursive;
	vector<int> NonRecursive;
	
	vector<int> TailRec;
	vector<int> NonTail;

	

	
	string answer = "yes";

	while (answer == "yes")
	{

		cout << "***************************" << endl;
		cout << "1.) Run Fibonacci simulations" << endl;
		cout << "2.) Display results" << endl;
		cout << "***************************" << endl;

		int choice = 0;
		cin >> choice;

		if (choice == 1)
		{

			try{

				int n = 0;
				cout << "Please enter which number term you want in the fibonacci sequence" << endl;
				cin >> n;

				cout << "Finding '" << n << "'th " << "fibonacci number...." << endl;
				cout << "Calling Recursive Fibonacci implementation" << endl;

				clock_t t;
				t = clock();


				for (int i = 0; i < 1000000; i++)
				{
					FibonacciR fr(n);
					fr.PrintFibonacci();
				}

				t = clock() - t;

				Recursive.push_back(t);

				printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
				cout << endl;

				cout << "Calling Non-Recursive Fibonacci implementation" << endl;

				clock_t t2;
				t2 = clock();

				for (int i = 0; i < 1000000; i++)
				{
					FibonacciNR fnr(n);
					fnr.PrintFibonacci();
				}
				t2 = clock() - t;
				NonRecursive.push_back(t2);
				printf("It took me %d clicks (%f seconds).\n", t2, ((float)t2) / CLOCKS_PER_SEC);
				



				//other functions
				cout << "Now testing the Not Tail recursive factorial function" << endl;
				cout << "What number do you want for this?" << endl;

				int rFvalue = 0;
				cin >> rFvalue;
				
				clock_t t3;
				t3 = clock();

				for (int i = 0; i < 1000000; i++)
				{
					rfactorial(rFvalue);


				}

				t3 = clock() - t3;
				printf("It took me %d clicks (%f seconds).\n", t3, ((float)t3) / CLOCKS_PER_SEC);

				NonTail.push_back(t3);

				cout << "Now testing the Tail Recursive factorial function" << endl;
				cout << "What number do you want for this?" << endl;

				int rFvlaue2 = 0;
				cin >> rFvlaue2;


				clock_t t4;
				t4 = clock();
				for (int i = 0; i < 1000000; i++)
				{
					factorial(rFvlaue2);


				}
				t4 = clock() - t4;
				printf("It took me %d clicks (%f seconds).\n", t4, ((float)t4) / CLOCKS_PER_SEC);
				TailRec.push_back(t4);

			}
			catch (...)
			{
				cout << "Oops an error occured! Please check usage" << endl;
				Usage();
				return 1;
			}
		}
		
		if (choice == 2)
		{
			cout << "Displaying all times for Recursive Fibonacci Function" << endl;

			for (int i = 0; i < Recursive.size(); i++)
				cout << Recursive[i] << endl;


			cout << "Displaying all times for Non Recursive Fibonacci Function" << endl;
			
			for (int i = 0; i < NonRecursive.size(); i++)
				cout << NonRecursive[i] << endl;

			cout << "Displaying all times for Not Tail Recursive Function" << endl;

			for (int i = 0; i < NonTail.size(); i++)
				cout << NonTail[i] << endl;

			cout << "Displaying all times for  Tail Recursive Function" << endl;

			for (int i = 0; i < TailRec.size(); i++)
				cout << TailRec[i] << endl;
		}
		
		
		cout << "Return to main menu?" << endl;
		cin >> answer;

	}
	

	return 0;
}



//Not tail recursive
long rfactorial(int n)
{
	if (n == 1)           
		return 1;      
	else      
		return n * rfactorial(n-1);
}


//Tail recursive
long factorialHelper(int n, int result) 
{
	if (n == 1)           
		return result;      
	else      
		return factorialHelper(n-1, n*result);
}

long factorial(int n) 
{ 
	return factorialHelper(n, 1); 
}
