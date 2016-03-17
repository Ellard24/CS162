#include <fstream>

#pragma once
using namespace std;

class FileFilter
{
public:
	virtual void doFilter(ifstream &in, ofstream &out);
	virtual char transform(char ch) = 0;
	







};

class CaseChange : public FileFilter
{

public:
	CaseChange();
	virtual char transform(char ch);





};


class Copy : public FileFilter
{

public:
	Copy();
	virtual char transform(char ch);







};

class Encrypt : public FileFilter
{
public:

	Encrypt();
	Encrypt(int encrypt1);
	virtual char transform(char ch);
	int getKey();

private:
	int key;



};
