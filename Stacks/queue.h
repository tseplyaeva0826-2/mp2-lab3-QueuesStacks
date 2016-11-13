#pragma once
#include <iostream>

using namespace std;

class Queue 
{
	char *pq;
	int si, ei, n;

	//	methods
public :
	Queue(int n);
	~Queue();

	// access to a queue
	bool ifEmpty();
	bool ifFull();
	void Qpush(int m);
	int  Qtake();

	friend istream & operator>>(istream &v, Queue &q);
	friend ostream & operator<<(ostream &v, Queue &q);

};