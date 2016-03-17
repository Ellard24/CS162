#pragma once




class Stack
{
private:
	struct Stacknode
	{
		int data;
		Stacknode *next;

	};

	Stacknode *head;

public:
	Stack();
	~Stack();
	void add(int value);
	int remove();
	void display();


};