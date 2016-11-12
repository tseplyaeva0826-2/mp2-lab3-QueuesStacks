#pragma once
#include <iostream>

using namespace std;

class Queue 
{
	int *p, n;
	int si, ei;

	// methods
public :
	Queue(int n);
	~Queue();

	// access to a queue
	bool ifEmpty();
	bool ifFull();
	void push(int m);
	int  take();

	friend istream & operator>>(istream &v, Queue &q);
	friend ostream & operator<<(ostream &v, Queue &q);

};