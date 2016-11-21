#pragma once

#include <iostream>


using namespace std;

const int MAX_QUEUE_SIZE = 100;

enum Type { value , operation };

struct Value
{
	int datel;
	Type type;
};

class Queue 
{
	Value *pq;
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