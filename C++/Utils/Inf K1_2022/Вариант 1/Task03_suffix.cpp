#include <iostream>
using namespace std;

unsigned reverse(unsigned n)
{
	unsigned reversed = 0;
	while (n != 0)
	{
		short lastDigit = n % 10;
		(reversed *= 10) += lastDigit;
		n /= 10;
	}

	return reversed;
}
bool isPalindrome(unsigned n)
{
	return n == reverse(n);
}

int main()
{
	unsigned n;
	cin >> n;

	for (size_t i = 10, currentSuffix = 0; n != currentSuffix; i *= 10)
	{
		currentSuffix = n % i;
		if (isPalindrome(currentSuffix))
		{
			cout << currentSuffix << endl;
		}
	}
}