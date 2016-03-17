
#pragma once



class Queue
{
	
private:

	struct Queuenode
	{
		int data;
		Queuenode *next;
		Queuenode *previous;
	
	};

	Queuenode *front;
	Queuenode *back;


public:
	Queue();
	~Queue();
	void add(int value);
	int remove();
	void display();

};



