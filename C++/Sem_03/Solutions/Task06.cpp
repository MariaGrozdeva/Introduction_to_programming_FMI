#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int number = 0;
	for (size_t i = 0; i < n; i++)
	{
		int digit;
		cin >> digit;

		if (!(digit % 2))
		{
			(number *= 10) += digit;
		}
	}

	cout << number * 2;
}
