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


	
	int k = 0;
	string str = "2 + 3* 12 - 10";
	string op = "+-*/";
	str += " ";
	int n = str.length();
	string str1[15];
	string s = "";
	string sn = "";
	int m;

	Stack abc(n+1);
	Queue que(n+1);
	 
	for (int i = 0; i < n; i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			s += str[i];
			int m = str[i];
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
				}
			}
		}
	}


	// вывод строки ( из строк ) без пробелов

	

	printf("str1: (%d)\n", k);

	printf("String of dates and signs : \n");
	for (int i = 0; i < k; i++)
	{
		printf("%s  \n", str1[i].c_str());

	}

	printf("\n");
	printf("\n");
	printf("\n");


	
	// строку разбить на строки , содержащие тип чтобы двузн числа были
	
	
	for (int i = 0; i < k; i++)  							  // последний элемент как-то проверить тоже надо
	{
		if ((str1[i][0] >= '0') && (str1[i][0] <= '9'))               // i-й элемент цифра
		{
			sn += str1[i][0];                                    // в строку
			
			if ((str1[i][1] >= '0') && (str1[i][1] <= '9'))   // i+1 элемент цифра 
			{

				sn += str1[i][1];        // добавляю к строке
				m = atoi(sn.c_str());     // строку в инт
				que.Qpush(m);             // в очередь 
				sn = "";
			}

			else						// если дальше символ
			{
				m = atoi(sn.c_str());	// цифру в число 
				que.Qpush(m);			// в очередь
				sn = "";
			}
		}
		else                             // если символ 
		{
			if (str1[i][0] == '+')
			{
				m = 43;
			}
			else
			{
				if (str1[i][0] == '-')
				{ m = 45; }
				else 
				{
					if (str1[i][0] == '*')
						{ m = 42; }
						else
						{
							m = 47;
						}
				}
			}
			
			               
			que.Qpushchar(m);			 // в очередь
		}
	}


	
	

	// вывод очереди


	for (int i = 0; i < n; i++) {     
		cout << que.Qtake() << endl;
	}
	


	
	/*   -----------СУММА В САМОМ НАЧАЛЕ----------------------

	int sum = 0;
	 sum = atoi(str1[0].c_str());
	for (int i = 1; i < k; i += 2)
	{
		int val = atoi(str1[i + 1].c_str());
		if (str1[i][0] == '+') sum += val;
		if (str1[i][0] == '-') sum -= val;
		if (str1[i][0] == '*') sum *= val;
		if (str1[i][0] == '/') sum /= val;
		
	}

	printf("result: %d\n", sum);
	
	*/

    return 0;
}

