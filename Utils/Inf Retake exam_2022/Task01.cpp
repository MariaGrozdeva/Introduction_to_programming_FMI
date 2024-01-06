#include <iostream>
#include <cmath>

unsigned int removeFirstAndLastDigits(unsigned int n)
{
	unsigned short int digitsCount = log10(n) + 1;
	unsigned int newNumber = 0;

	size_t i = digitsCount - 1;
	unsigned int power = pow(10, i - 1);

	while (i > 1)
	{
		newNumber *= power;
		newNumber += (n / power) % 10;

		power /= 10;
		i--;
	}
	return newNumber;
}

unsigned int reverse(unsigned int n)
{
	unsigned int result = 0;

	while (n != 0)
	{
		unsigned short int lastDigit = n % 10;
		(result *= 10) += lastDigit;
		n /= 10;
	}

	return result;
}

bool isSuffix(unsigned int n, unsigned int k)
{
	if (k == 0 && (n % 10 != 0))
		return false;

	while (k != 0)
	{
		unsigned short int lastDigitOfN = n % 10;
		unsigned short int lastDigitOfK = k % 10;

		if (lastDigitOfN != lastDigitOfK)
			return false;

		n /= 10;
		k /= 10;
	}

	return true;
}
bool isPrefix(unsigned int n, unsigned  int k)
{
	return isSuffix(reverse(n), reverse(k));
}
bool isInfix(unsigned int n, unsigned int k)
{
	if (n == 0 && k == 0)
		return true;

	while (n > 0)
	{
		if (isSuffix(n, k))
			return true;
		n /= 10;
	}
	return false;
}

bool task01(unsigned int n, unsigned int k)
{
	n = removeFirstAndLastDigits(n);
	return isInfix(n, k);
}

int main()
{
	std::cout << task01(1234, 23);
}