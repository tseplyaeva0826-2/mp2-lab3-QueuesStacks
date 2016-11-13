#include "queue.h"

int main()
{
	char str[15]; int len;

	cin >> str; len = strlen(str);

	Queue a(5);

	for (int i = 0; i < len; i++)
	{
		if ((str[i] < '0') || (str[i] > '9'))
			a.Qpush(str[i]);
	}

	cout << str << " ";

	cout << a; // ошибка
	
	return 0;
}