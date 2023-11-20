#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	if (a < 2)
		a = 2;

	int number = 0;
	for (int i = a; i <= b; i++)
	{
		bool prime = true;
		double temp = sqrt(i);
		
		for (int j = 2; j <= temp; j++) // N.B.!! checks for divisors ONLY IN THE RANGE [2..sqrt(i)]. If there aren't any divisors in this interval, then there are NO DIVISORS AT ALL!
		{
			if (!(i % j))
				prime = false;
		}
		
		if (prime)
			cout << i << ' ';
	}
}