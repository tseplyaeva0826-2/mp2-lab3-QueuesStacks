// sample.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include <iostream>
#include "queue.h"
#include "stack.h"
#include <string>
#include "conio.h"
#include "func.h"


using namespace std;
#define SIZE 256



int main()
{
	
	int k = 0;
	string str = "(2 + 3)* 12 - 10";
	string op = "+-*/";
	str += " ";
	int n = str.length();
	string str1[15];
	string s = "";
	string sn = "";
	int m;
	int c, c1;
	Value z, elem;
	int prior, prior1;
	Value p, p1;
	
	Queue que(n+1);
	Queue qw(n + 1);
	Queue qw1(n + 1);
	Queue result(n + 1);

	Stack abc(k);

/////////////////////////////////////////////////////////////////////////////////////////////

	

////////////////////////////////////////////////////////////////////////////////////////////

//считать с клавиатуры 
// cin >> str; 

/////////////////////////////////////////////////////////////////////////////////////////////

// СОЗДАЮ СТРОКУ ИЗ СТРОК ( ЧИСЛА И СИМВОЛЫ )


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

/////////////////////////////////////////////////////////////////////////////////////////////


// вывод строки без пробелов

	printf("str1: (%d)\n", k);

	printf("String of dates and signs : \n");
	for (int i = 0; i < k; i++)
	{
		printf("%s  \n", str1[i].c_str());

	}

/////////////////////////////////////////////////////////////////////////////////////////////

	printf("\n");
	printf("\n");

/////////////////////////////////////////////////////////////////////////////////////////////
	
// СОЗДАЮ ОЧЕРЕДЬ ИЗ СТРУКТУР 
	
	
	for (int i = 0; i < k; i++)  							  
	{
		if ((str1[i][0] >= '0') && (str1[i][0] <= '9'))               // i-й элемент цифра
		{
			sn += str1[i][0];                                    
			
			if ((str1[i][1] >= '0') && (str1[i][1] <= '9'))   
			{

				sn += str1[i][1];        
				m = atoi(sn.c_str());
						
				que.Qpush(m);             
				sn = "";
			}

			else						
			{
				m = atoi(sn.c_str());
										
				que.Qpush(m);			
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
				{ m = 45;
				 
				}
				else 
				{
					if (str1[i][0] == '*')
						{ m = 42; 
						  
					}
						else
						{
							if (str1[i][0] == '/')
							{
								m = 47; 
								
							}
							else
							{
								if (str1[i][0] == '(')
								{
									m = 40;
									
								}
								else
								{
									m = 41;
									
								}
							 } 
						}
				}
			}
			
			               
			que.Qpushchar(m);			 
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////////

	qw = que;
	qw1 = qw;

/////////////////////////////////////////////////////////////////////////////////////////////	
// вывод очереди 1
	
	printf("String of dates and signs 1 : \n");

	for (int i = 0; i < k; i++)
	{
		cout << que.Qtake().datel << endl;
	}

/////////////////////////////////////////////////////////////////////////////////////////////

	printf("\n");
	printf("\n");

/////////////////////////////////////////////////////////////////////////////////////////////
	/*
// вывод очереди 2	  !!!   не видит числа   !!! 

	printf("String of dates and signs 2 : \n");

	for (int i = 0; i < k; i++)
	{
		z = qw.Qtake();
		
		if (IfValue(z) == 1)
		{
			c = z.datel;
			cout << c; 
		}
		else
		{
			
			c = z.datel;
			switch (c)
			{
			case 40: { cout << "("; break;  }
			case 41: { cout << ")"; break;  }
			case 42: { cout << "*"; break;  }
			case 43: { cout << "+"; break;  }
			case 45: { cout << "-"; break;  }
			case 47: { cout << "/"; break;  }
			}

		}
	}
	*/
//////////////////////////////////////////////////////////////////////////////////////////////

	printf("\n");
	printf("\n");

/////////////////////////////////////////////////////////////////////////////////////////////
	// обратная польская запись  с qw1
	
	for (int i = 0; i < k; i++)
	{

		cout << i + 1;
		elem = qw1.Qtake();
		if (IfValue(elem) == 1)  // если это число - помещаю в выходную очередь
		{
			c = elem.datel;
			result.Qpush(c);
		}
		else
		{
			c = elem.datel;

			switch (c)
			{
			case 40: { prior = 0; break;  }               // приор, то что проверяем 
			case 41: { prior = 0; break;  }					//приор 1 то, с чем сравниваем
			case 42: { prior = 2; break;  } // *
			case 43: { prior = 1; break;  } // +
			case 45: { prior = 1; break;  } // -
			case 47: { prior = 2; break;  } // /
			}


			Value l;
			if (abc.StackIsEmpty() == false)
			{
				l = abc.Stake();				// взяла вершину стека
				c1 = l.datel;

				// узнаю приоритет операции на вершине стека

				switch (c)
				{
				case 40: { prior1 = 0; break;  }                
				case 41: { prior1 = 0; break;  }					
				case 42: { prior1 = 2; break;  } // *
				case 43: { prior1 = 1; break;  } // +
				case 45: { prior1 = 1; break;  } // -
				case 47: { prior1 = 2; break;  } // /
				}

				abc.Spush(l); // положила обратно вершину стека

				if (prior < prior1) //если приоритет ниже 
				{
					// все выталкиваю из стека
					while (abc.StackIsEmpty() == false)
					{
						p1 = abc.Stake();
						result.Qpushchar(p1.datel);
					}

					abc.Spush(elem);    // элемент, чем приоритет был ниже, кладу в стек
				}
				else // если приоритет выше - просто кладу в стек
				{
					abc.Spush(elem);
				}

			}
			else   // если в стеке еще не было операций
			{
				abc.Spush(elem);
			}
		}
			
	}

	// остатки выталкиваю из стека 
	while (abc.StackIsEmpty() == false)
	{
		p1 = abc.Stake();
		result.Qpushchar(p1.datel);
	}

/////////////////////////////////////////////////////////////////////////////////////////////	

	printf("\n");
	printf("\n");

/////////////////////////////////////////////////////////////////////////////////////////////	
// вывод очереди result

	printf(" Result Queue ( obratnaya Polskaya )  : \n");

	for (int i = 0; i < k; i++)
	{
		cout << result.Qtake().datel;
	}

/////////////////////////////////////////////////////////////////////////////////////////////
	



/////////////////////////////////////////////////////////////////////////////////////////////	

	/*   СУММА В САМОМ НАЧАЛЕ

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

