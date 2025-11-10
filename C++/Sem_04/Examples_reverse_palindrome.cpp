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

bool isPalindrome(unsigned n)
{
	return n == reverse(n);
}

int main()
{
	cout << isPalindrome(12321);
}