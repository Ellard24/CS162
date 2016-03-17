/************************************************************
**Author: Ellard Gerritsen van der Hoop
**Description: This program takes predefined text files and allows
				users to find target values, seach for 0, and sort
				them into new files
**Input: All input received during runtime
**Output: Displays to screen whether a target value was found 
			and position
*************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int targetSearch(string name1);
void sort(string inFile1, string outFile);
int binarySearch(string file1, int number);


int main()
{
	int option = 0;
	int results = 0;

	string choice = "yes";

	while (choice == "yes")
	{
		cout << "This program will allow you to do 3 different functions." << endl;
		cout << "1.) Searches for the target value of '0' " << endl;
		cout << "2.) Sort a set of values" << endl;
		cout << "3.) Search for binary value.This option requires a sorted file so please do 2 first." << endl;

		cin >> option;


		if (option == 1)
		{

			cout << "Pick which file you want to search. The options are early, middle, end, or original. Format is file.txt" << endl;

			string file1;
			cin >> file1;
			results = targetSearch(file1);

			if (results == -1)
				cout << "There was no 0 in the file" << endl;
			else
				cout << "A 0 was found in the file at element " << results << endl;


		}


		if (option == 2)
		{
			string inFile1 = "early.txt";
			string inFile2 = "middle.txt";
			string inFile3 = "end.txt";
			string inFile4 = "original.txt";

			string outFile;

			cout << "All four(Early, Middle,End, Original) files will be sorted" << endl;
			cout << "Please enter the name of the four output files you want." << endl;

			cout << "Please name the file you want to use as output file 1. Format is file.txt" << endl;
			cin >> outFile;
			sort(inFile1, outFile);

			cout << "Please name the file you want to use as output file 2. Format is file.txt" << endl;
			cin >> outFile;
			sort(inFile2, outFile);
			cout << "Please name the file you want to use as output file 3. Format is file.txt" << endl;
			cin >> outFile;
			sort(inFile3, outFile);

			cout << "Please name the file you want to use as output file 4. Format is file.txt" << endl;
			cin >> outFile;
			sort(inFile4, outFile);






		}


		if (option == 3)
		{
			string file1;
			int number;
			int results;
			cout << "Please enter the name of an output file you created in the second option" << endl;
			cin >> file1;

			cout << "Please enter the value you want to find" << endl;
			cin >> number;

			results = binarySearch(file1, number);

			if (results == number)
			{
				cout << "Value " << number << " was found in element " << results << " of the vector" << endl;
			}
			else
			{

				cout << "Value was not found" << endl;
			}


		}


		cout << "Do you want to try a different option?" << endl;
		cin >> choice;

	}
	return 0;
}

/*************************************************************
** Function: targetSearch
** Description: Reads all values from a text file and sees whether
**				0 is located in the file. Then it displays location
** Parameters: string file1
** Pre-Conditions: Input text files need to exist
** Post-Conditions: Input files can be read and then sorted into another new file
**************************************************************/
int targetSearch(string file1)
{
	vector<int> vector1;
	ifstream myFile;
	myFile.open(file1.c_str());

	int index = 0;
	int position = -1;
	bool found = false;


	while (!myFile.peek() == myFile.eof())
	{
		int i;
		while (myFile >> i)
			vector1.push_back(i);
	
	}

	while (index < vector1.size() && !found)
	{
		if (vector1[index] == 0)
		{
			found = true;
			position = index;
		}
		index++;
	}

	myFile.close();
	return position;


}




/*************************************************************
** Function: sort
** Description: Sorts integers from text files in ascending order using bubble format
**				and writing into desired output file
** Parameters: string inFile1, string outFile
** Pre-Conditions: Input files need to exist and be correctly input into function
** Post-Conditions: Sorted files can be then be searched using a binary search
**************************************************************/
void sort(string inFile1, string outFile)
{
	
	ifstream myFile(inFile1.c_str());
	ofstream myFile2(outFile.c_str());
	
	vector<int> sortVector;

	while (!myFile.peek() == myFile.eof())
	{
		int i;
		while (myFile >> i)
			sortVector.push_back(i);

	}
	

	int temp;
	bool swap;

	do
	{
		swap = false;
		for (int i = 0; i < (sortVector.size() - 1); i++)
		{
			if (sortVector[i] > sortVector[i + 1])
			{
				temp = sortVector[i];
				sortVector[i] = sortVector[i + 1];
				sortVector[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	for (int i = 0; i <sortVector.size(); i++)
		cout << sortVector[i]<< endl;
	
	for (int i = 0; i < sortVector.size(); i++)
		myFile2 << sortVector[i];

	myFile.close();
	myFile2.close();
}



/*************************************************************
** Function: binarySearch
** Description: Searches for a specified value within a text 
**				file and displays whether its there and its 
**				position
** Parameters: string inFile1, int number
** Pre-Conditions: A sorted text file needs to exist 
** Post-Conditions: -
**************************************************************/
int binarySearch(string inFile1, int number)
{

	ifstream myFile;
	myFile.open(inFile1.c_str());

	vector<int> binVector;
	

	while (!myFile.peek() == myFile.eof())
	{
		char i;
		while (myFile.get(i))
		{
			binVector.push_back(i - '0');         //Since the sorting made the numbers into one big number, i used this to read one digit at a time
		}
	}
	

	
	int first = 0;
	int last = binVector.size() - 1;
	bool found = false;
	int position = -1;
	int middle = binVector.size() / 2;

	while (found == false && first <= last)
	{
		
		middle = (first + last) / 2; 
		if (binVector[middle] == number)
		{
			found = true;
			position = middle;
		}
		else if (binVector[middle] > number)
		{
			last = middle - 1;
		}
		else
			first = middle + 1;
	}


	myFile.close();

	return position;
}
