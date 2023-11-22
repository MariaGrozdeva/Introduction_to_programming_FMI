#include <iostream>
using namespace std;

unsigned int toDecimal(unsigned long long n)
{
	unsigned int decimalNum = 0;
	unsigned int multiplier = 1;

	while (n != 0)
	{
		decimalNum += (n % 10 * multiplier);
		multiplier *= 2;
		n /= 10;
	}

	return decimalNum;
}

int main()
{
	cout << toDecimal(10111);
}
