#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int evenDigits = 0, oddDigits = 0;

	if ((n % 10) % 2)
	{
		oddDigits++;
	}
	else
	{
		evenDigits++;
	}

	if (((n / 10) % 10) % 2)
	{
		oddDigits++;
	}
	else
	{
		evenDigits++;
	}

	if (((n / 100) % 10) % 2)
	{
		oddDigits++;
	}
	else
	{
		evenDigits++;
	}

	if ((n / 1000) % 2)
	{
		oddDigits++;
	}
	else
	{
		evenDigits++;
	}

	cout << (evenDigits == oddDigits);
}