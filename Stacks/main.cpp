#include "queue.h"

int main()
{
	char str[15]; int len;
	cin >> str; len = strlen(str);
	Queue a(5);
	for (int i = 0; i < len; i++)
	{
		if ((str[i] < '0') || (str[i] > '9'))
			a.push(str[i]);
	}

	cout << str ;

	for (int i = 0; i < len; ++i)
	{
		int l;
		l = a.take();
		printf("%d", a);
	}
	return 0;
}