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

	// �������� ��� � �������

	for (int i = 0; i < len; i++)
	{
	exp.Qpush(str[i]);
	}

	// ������� ��� ������

	for (int i = exp.si; i != (exp.ei + 1) % len; i = (i + 1) % len)  // ��� ��������� ���� ������� �� �������, ���� ���� ����������?
	{
	q = exp.pq[i];

	switch q
	{
	case 0,1,2,3,4,5,6,7,8,9 : // �������������� �����?
	newexp.Qpush(pq[i]); break;
	default :
	k++; break;
	}
	}

	for (int i = ; i ; i = )  // �������� ���� �� �������
	{
	q = exp.pq[i];

	switch q
	{
	case '+','-','*','/': // �������������� �����?
	newexp.Qpush(pq[i]); break;
	default:
	k++; break;
	}
	}
	*/

    return 0;
}

