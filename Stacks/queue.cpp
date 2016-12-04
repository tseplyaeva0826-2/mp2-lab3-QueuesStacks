
#include "queue.h"



Queue::Queue(int n)
{
	this->n = n;
	pq = new Value[n];
	si = 0; ei = 1;
	
}

Queue::~Queue()
{
	delete[]pq;
	pq = NULL;
}

bool Queue::ifEmpty()
{
	return (si + 1) % n == ei;
}

bool Queue::ifFull()
{
	if ((si + 2) % n == ei) { return 1; }
	{return 0; }
}

void Queue::Qpush(int m)
{
	if (ifFull()) throw "no";
	si = (si + 1) % n;
	pq[si].datel = m;
	pq[si].type = value;
	
}

void Queue::Qpushchar(char m)
{
	if (ifFull()) throw "no";
	si = (si + 1) % n;
	pq[si].datel =(int)(m);
	pq[si].type = operation;

}


int Queue::Qtake()
{
	if (ifEmpty()) throw "no";
	int temp = pq[ei].datel;
	ei = (ei + 1) % n;
	return temp;
}

ostream & operator<<(ostream &v, Queue &q)
{
	for (int i = q.si; i != (q.ei + 1) % q.n; i = (i + 1) % q.n)
		v << q.pq[i].datel;
	return v;
}

istream & operator>>(istream &v, Queue &q)
{
	for (int i = q.si; i != (q.ei + 1) % q.n; i = (i + 1) % q.n)
		v >> q.pq[i].datel;
	return v;
}

