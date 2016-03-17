#pragma once




class Queue
{

private:
	struct QueueNode
	{
		int data;
		QueueNode *next;
		QueueNode *prev;


	};

	QueueNode *front;
	QueueNode *back;

public:

	Queue();
	~Queue();
	void addBack();
	int getFront();
	void removeFront();
	//int getBack();   For testing purposes



};