#include "Headers.h"
#include <iostream>

// FileFilter base class


/**********************************************************
** Function: doFilter
** Description: Takes contents from an inputfile
and passes it on to the transform function
before sending to output file
** Parameters:ifstream &in, ofstream &out
** Pre-Conditions: Ifstream file must be specified
** Post-Conditions: File is made with transformed text
**********************************************************/


void FileFilter::doFilter(ifstream &in, ofstream &out)
{
	char char1;


	while (!in.peek() == in.eof())
	{
		char1 = in.get();
		out.put(transform(char1));
	}

}






// Copy class


/**********************************************************
** Function: Copy Constructor
** Description: -
** Parameters: -
** Pre-Conditions: -
** Post-Conditions: -
**********************************************************/
Copy::Copy()
{


}



char Copy::transform(char ch)
{
	return ch;


}










// CaseChange class

CaseChange::CaseChange()
{


}


/**********************************************************
** Function: transform
** Description: Transforms each character from inputfile
**				to uppercase
** Parameters: char ch
** Pre-Conditions: Inputfile must be specified
** Post-Conditions: Transformed characters move to output file
**********************************************************/
char CaseChange::transform(char ch)
{
	return toupper(ch);



}









/**********************************************************
** Function: Encrypt constructor
** Description: calls getkey method
** Parameters:-
** Pre-Conditions: -
** Post-Conditions: key is passed onto other functions
**********************************************************/
Encrypt::Encrypt()
{

	getKey();
}



/**********************************************************
** Function: Encrypt constructor
** Description: Sets key to user specified value
** Parameters: int encrypt1
** Pre-Conditions: Default constructor must be called
** Post-Conditions: Key is passed onto other functions
**********************************************************/
Encrypt::Encrypt(int key)
{

	this->key = key;

}



/**********************************************************
** Function: transform
** Description: Encrypts characters from inputfile
** Parameters: char ch
** Pre-Conditions: Encrypt key must be set
** Post-Conditions: Contents passed on to output file
**********************************************************/
char Encrypt::transform(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		ch = ch - 'a' + key;
		ch %= 26;
		ch += 'a';
		return ch;
	}
	
	if (ch >= 'A' && ch <= 'Z')
	{
		ch = ch - 'A' + key;
		ch %= 26;
		ch += 'A';
		return ch;
	}

	else
		return ch;
}

/*******************************************
Function: getKey
Description:  Prompts for encryption key
Parameters: -
Pre-Conditions: Default constructor must be called
Post-Conditions: Key is passed onto second constructor
************************************************/

int Encrypt::getKey()
{
	cout << " Enter a number between 1 and 26 to set encryption key" << endl;
	cin >> key;

	return key;



}
