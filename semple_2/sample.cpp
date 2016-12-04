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

	Stack abc(n+1);
	Queue que(n+1);
	 
	for (int i = 0; i < n; i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			s += str[i];
			int m = str[i];
		que.Qpush(m); // положить цифру в очередь 
		
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
						k++;
						 
					}
					str1[k] = str[i];
					s = "";
					k++;
					char l = str[i];
					que.Qpushchar(l);// положить символ в очередь
				}
			}
		}
	}


	printf("str1: (%d)\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%s  \n", str1[i].c_str());

	}

	// ќЅ–ј“Ќјя ѕќЋ№— јя «јѕ»—№ 
	Stack temps(n+1);
	Queue final(n + 1);
	string pr1 = "/*";
	string pr2 = "+-";
	 // string pr3 = "()";
	int p = -1;
	for (int i = 0; i < k+1; i++)
	{
		if (isalnum(str1[i])) { final.Qpush(str[i]); }  // если число - помещаю в очередь 
		else
			{
			if ((pr1.find(str1[i]) >= 0) || (pr2.find(str[i]) >= 0) || (str1[i] = "(")) // если ( /* +- помещаю в стек 
			{

				
				if (pr1.find(str[i]) >= 0) p = 1;
				if (pr1.find(str[i]) >= 0) p = 2;
				if ( p < )								//сравнение приоритетов 


				temps.Spush(str1[i]); 
			}
			else
					{
					if (str1[i] = ")") 
					{
						while (temps.StackIsEmpty() == false) //выталкиваю элементы из стека в строку final
						{
							char l = temps.Stake();
							if (l != '(' ) final.Qpushchar(l);
						}
					}
					}
			}
		
		
	}



	while (temps.StackIsEmpty() == false) //выталкиваю элементы из стека в строку final
	{
		char l = temps.Stake();
		final.Qpushchar(l);
	}



	for (int i = 0; i < n; i++) {     // вывод очереди
		cout << que.Qtake() << endl;
	}

	
	/*for (int i = 0; i < n; i++) {     // вывод очереди
		cout << que.Qtake() << endl;
	}

	/*int sum = atoi(str1[0].c_str());
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

	printf("result: %d\n", sum);**/

    return 0;
}

