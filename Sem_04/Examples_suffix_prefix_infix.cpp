#include <iostream>
using namespace std;

unsigned reverse(unsigned n)
{
	unsigned reversedNumber = 0;

	while (n != 0)
	{
		short lastDigit = n % 10;
		(reversedNumber *= 10) += lastDigit;
		n /= 10;
	}

	return reversedNumber;
}

bool isSuffix(unsigned n, unsigned k)
{
	while (k != 0)
	{
		short lastDigitOfN = n % 10;
		short lastDigitOfK = k % 10;

		if (lastDigitOfN != lastDigitOfK)
		{
			return false;
		}

		n /= 10;
		k /= 10;
	}

	return true;
}

bool isPrefix(unsigned n, unsigned k)
{
	return isSuffix(reverse(n), reverse(k));
}

bool isInfix(unsigned int n, unsigned int k)
{
	if (n == 0 && k == 0)
	{
		return true;
	}

	while (n > 0)
	{
		if (isSuffix(n, k))
		{
			return true;
		}
		n /= 10;
	}
	return false;
}

int main()
{
	cout << isInfix(2831, 83);
}
