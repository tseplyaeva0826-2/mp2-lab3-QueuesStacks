// sample.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include <iostream>
#include "queue.h"
#include "stack.h"
#include <string>
#include "conio.h"

using namespace std;

int main()
{

	string str1[20];
	int k = 0;
	string str = "2 + 3* 12 - 10";
	string op = "+-*/";
	str += " ";
	int n = str.length();
	string s = "";
	for (int i = 0; i < n; i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			s += str[i];
		}
		else
		{
			if (str[i] == ' ')
			{
				if (s.size()>0)
				{
					str1[k] = s;
					s = "";
					k++;
				}
			}
			else
			{
				if (op.find(str[i]) >= 0)
				{
					if (s.size()>0)
					{
						str1[k] = s;
						s = "";
						k++; //положить в очередь 
					}
					str1[k] = str[i];
					s = "";
					k++;
				}
			}
		}
	}


	printf("str1: (%d)\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%s  \n", str1[i].c_str());

	}

	int sum = atoi(str1[0].c_str());
	for (int i = 1; i < k; i += 2)
	{
		int val = atoi(str1[i + 1].c_str());
		if (str1[i][0] == '+') sum += val;
		if (str1[i][0] == '-') sum -= val;
		if (str1[i][0] == '*') sum *= val;
		if (str1[i][0] == '/')
		{
			if (val != 0) sum /= val;

			else  throw "can`t perform an operation";
		}
	}

	printf("result: %d\n", sum);

    return 0;
}

