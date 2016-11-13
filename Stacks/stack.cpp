#include "stack.h"

Stack::Stack(int size)
{
	ps = new char[size];

	top = 0;
}

Stack::~Stack()
{
	delete[]ps;
	ps = NULL;
}

void Stack::Spush(char m)
{
	ps[top++] = m;
}

char Stack::Stake()
{
	char temp = ps[top];
	--top;
	return temp;
}

bool Stack::StackIsFull()
{
	if (top == size) return 1;
	return 0;
}

bool Stack::StackIsEmpty()
{
	if (top == 0)  return 1; 
	return 0;
}