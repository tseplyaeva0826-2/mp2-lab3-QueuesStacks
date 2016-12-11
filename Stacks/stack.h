#pragma once
#include <iostream>



using namespace std;

const int MAX_STACK_SIZE = 100;


class Stack
{
	Value *ps;
	int size, top;

	//	methods
public:
	Stack (int size);
	~Stack ();

	void Spush(Value m); // make elem top 
	Value Stake(); // take elem from top (delete from stack)
	bool StackIsFull();
	bool StackIsEmpty();
	
};