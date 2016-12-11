
#include "queue.h"
#include "stack.h"

Stack::Stack(int size)
{
	ps = new Value[size];

	top = 0;
}

Stack::~Stack()
{
	delete[]ps;
	ps = NULL;
}

void Stack::Spush(Value m)
{
	ps[top++].datel = m.datel;
	if (m.type == value)
		ps[top++].type = value;
	else
		ps[top++].type = operation;
}

Value Stack::Stake()
{
	Value temp = ps[top];
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

