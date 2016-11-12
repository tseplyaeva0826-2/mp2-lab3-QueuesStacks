#include "queue.h"

Queue::Queue(int n)
{
	this->n = n;
	p = new int[n];
	si = 0; ei = 0;
}

Queue::~Queue()
{
	delete[]p;
	p = NULL;
}

bool Queue::ifEmpty()
{
	return (si + 1) % n == ei;
}

bool Queue::ifFull()
{
	if ((si + 2) % n == 2) { return 1; }
	{return 0; }
}

void Queue::push(int m)
{
	if (ifFull()) throw "no";
	si = (si + 1) % n;
	p[si] = m;
}

int Queue::take()
{
	if (ifEmpty()) throw "no";
	int temp = p[ei];
	ei = (ei + 1) % n;
	return temp;
}

ostream & operator<<(ostream &v, Queue &q)
{
	for (int i = q.si; i != (q.ei + 1) % q.n; i = (i + 1) % q.n)
		v << q.p[i];
	return v;
}

istream & operator>>(istream &v, Queue &q)
{
	for (int i = q.si; i != (q.ei + 1) % q.n; i = (i + 1) % q.n)
		v >> q.p[i];
	return v;
}