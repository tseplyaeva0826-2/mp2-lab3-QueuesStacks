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

//������� � ���������� 
// cin >> str; 

/////////////////////////////////////////////////////////////////////////////////////////////

// ������ ������ �� ����� ( ����� � ������� )


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


// ����� ������ ��� ��������

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
	
// ������ ������� �� �������� 
	
	
	for (int i = 0; i < k; i++)  							  
	{
		if ((str1[i][0] >= '0') && (str1[i][0] <= '9'))               // i-� ������� �����
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
		else                             // ���� ������ 
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
// ����� ������� 1
	
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
// ����� ������� 2	  !!!   �� ����� �����   !!! 

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
	// �������� �������� ������  � qw1
	
	for (int i = 0; i < k; i++)
	{

		cout << i + 1;
		elem = qw1.Qtake();
		if (IfValue(elem) == 1)  // ���� ��� ����� - ������� � �������� �������
		{
			c = elem.datel;
			result.Qpush(c);
		}
		else
		{
			c = elem.datel;

			switch (c)
			{
			case 40: { prior = 0; break;  }               // �����, �� ��� ��������� 
			case 41: { prior = 0; break;  }					//����� 1 ��, � ��� ����������
			case 42: { prior = 2; break;  } // *
			case 43: { prior = 1; break;  } // +
			case 45: { prior = 1; break;  } // -
			case 47: { prior = 2; break;  } // /
			}


			Value l;
			if (abc.StackIsEmpty() == false)
			{
				l = abc.Stake();				// ����� ������� �����
				c1 = l.datel;

				// ����� ��������� �������� �� ������� �����

				switch (c)
				{
				case 40: { prior1 = 0; break;  }                
				case 41: { prior1 = 0; break;  }					
				case 42: { prior1 = 2; break;  } // *
				case 43: { prior1 = 1; break;  } // +
				case 45: { prior1 = 1; break;  } // -
				case 47: { prior1 = 2; break;  } // /
				}

				abc.Spush(l); // �������� ������� ������� �����

				if (prior < prior1) //���� ��������� ���� 
				{
					// ��� ���������� �� �����
					while (abc.StackIsEmpty() == false)
					{
						p1 = abc.Stake();
						result.Qpushchar(p1.datel);
					}

					abc.Spush(elem);    // �������, ��� ��������� ��� ����, ����� � ����
				}
				else // ���� ��������� ���� - ������ ����� � ����
				{
					abc.Spush(elem);
				}

			}
			else   // ���� � ����� ��� �� ���� ��������
			{
				abc.Spush(elem);
			}
		}
			
	}

	// ������� ���������� �� ����� 
	while (abc.StackIsEmpty() == false)
	{
		p1 = abc.Stake();
		result.Qpushchar(p1.datel);
	}

/////////////////////////////////////////////////////////////////////////////////////////////	

	printf("\n");
	printf("\n");

/////////////////////////////////////////////////////////////////////////////////////////////	
// ����� ������� result

	printf(" Result Queue ( obratnaya Polskaya )  : \n");

	for (int i = 0; i < k; i++)
	{
		cout << result.Qtake().datel;
	}

/////////////////////////////////////////////////////////////////////////////////////////////
	



/////////////////////////////////////////////////////////////////////////////////////////////	

	/*   ����� � ����� ������

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

