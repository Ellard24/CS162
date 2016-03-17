/****************************************************************
**Author: Ellard Gerritsen van der Hoop
**Description: This program takes characters from an inputfile
and then either copies, changes the case, or encrypts
the contents before moving to a new output file
**Input: All input during runtime as well as input from
file
**Output: Input File contents moved/transformed to output file
****************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Headers.h"



using namespace std;

/**********************************************************
** Function: main
** Description: Menu driven program that prompts whether
a user wants to copy, change chase, or
encrypt the input file of choice
** Parameters:  -
** Pre-Conditions: -
** Post-Conditions:-
**********************************************************/

int main()
{
	int option = 0;
	ofstream output;
	ifstream input;

	string file, outputFile;

	cout << "Welcome to the FileFilter Program" << endl;
	cout << "This program allows you to input an alphanumeric sequence from an existing file"
		<< " and then perform some transformative function on it which will then be sent to a new file" << endl;
	cout << "In this program you will have 4 options" << endl;
	cout << "1.) Create an unchanged version of the original file" << endl;
	cout << "2.) Transform each character in the file to uppercase" << endl;
	cout << "3.) Perform an encryption on the characters in the file" << endl;
	cout << "4.) Exit the Program" << endl;

	cin >> option;

	//Read stuff from file
	cout << "What file do you want to read out of?" << endl;
	cout << "The format for typing in all filenames in this program should be filename.txt" << endl;
	cin >> file;

	input.open(file.c_str());


	//Transform the results 

	if (option == 1)
	{
		cout << "The File will now be copied over" << endl;
		cout << "Please enter the name of the Output file" << endl;
		cin >> outputFile;
		output.open(outputFile.c_str());

		Copy *c1 = new Copy;
		c1->doFilter(input, output);
		input.close();
		output.close();
		cout << "Copy finished" << endl;
	}

	if (option == 2)
	{
		cout << "The letters in the file will now all become uppercase"
			<< "and move to a new file" << endl;
		cout << "Please enter the name of the Output file" << endl;
		cin >> outputFile;
		output.open(outputFile.c_str());

		CaseChange *cc1 = new CaseChange;
		cc1->doFilter(input, output);

		input.close();
		output.close();
		cout << "Finished" << endl;
	}

	if (option == 3)
	{
		int num1 = 0;
		cout << "You have chosen to encrypt" << endl;


		cout << "Please enter the name of the Output file" << endl;
		cin >> outputFile;
		output.open(outputFile.c_str());

		Encrypt *e1 = new Encrypt;
		e1->doFilter(input, output);
		cout << "File has been Encrypted" << endl;
		input.close();
		output.close();
	}

	if (option == 4)
	{
		cout << "Program is Ending :)" << endl;
		return 0;

	}




	return 0;











}


