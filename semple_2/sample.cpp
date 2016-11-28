// sample.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{

	char str[15]; int len;
	char q;
	int k = 0;
	cin >> str; len = strlen(str);

	Queue a(50);


	for (int i = 0; i < len; i++)
	{
		if ((str[i] >= '0') || (str[i] <= '9'))
			a.Qpush(str[i]);
	}

	cout << str << " ";

	cout << a;
//	_getch();
	/*
	cout << "Enter an arithmetic expression" ;
	cin >> str; len = strlen(str);

	Queue exp(len), newexp(len);

	// добавляю все в очередь

	for (int i = 0; i < len; i++)
	{
	exp.Qpush(str[i]);
	}

	// вариант без скобок

	for (int i = exp.si; i != (exp.ei + 1) % len; i = (i + 1) % len)  // как запустить цикл прохода по очереди, если поля недоступны?
	{
	q = exp.pq[i];

	switch q
	{
	case 0,1,2,3,4,5,6,7,8,9 : // преобразование типов?
	newexp.Qpush(pq[i]); break;
	default :
	k++; break;
	}
	}

	for (int i = ; i ; i = )  // обратный цикл по очереди
	{
	q = exp.pq[i];

	switch q
	{
	case '+','-','*','/': // преобразование типов?
	newexp.Qpush(pq[i]); break;
	default:
	k++; break;
	}
	}
	*/

    return 0;
}

