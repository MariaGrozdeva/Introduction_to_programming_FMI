#include <iostream>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;

	short lastDigit = n % 10;

	switch (lastDigit)
	{
	case 0: case 2: case 4: case 6: case 8: n = ((n / 10) * 10 + lastDigit % 3); break;
	case 1: case 3: case 5: case 7: case 9: n = ((n / 10) * 10 + lastDigit % 2); break;
	}

	cout << n; 
}