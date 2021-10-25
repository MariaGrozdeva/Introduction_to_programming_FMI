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
		for (int j = 2; j < i; j++)
		{
			if (!(i % j))
				prime = false;
		}
		
		if (prime)
			cout << i << ' ';
	}
}