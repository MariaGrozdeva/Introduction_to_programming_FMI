#include <iostream>
using namespace std;

// Напишете функция, която приема цяло число n и сортира цифрите му в низходящ ред.

unsigned concatDigitAtBack(unsigned n, short digit)
{
	return n * 10 + digit;
}

unsigned concatNTimesDigit(unsigned n, short digit, short count)
{
	for (short i = 0; i < count; i++)
	{
		n = concatDigitAtBack(n, digit);
	}
	return n;
}

short countDigitOccurrences(unsigned n, short digit)
{
	if (digit == 0 && n == 0)
	{
		return 1;
	}

	short count = 0;
	while (n != 0)
	{
		if (n % 10 == digit)
		{
			count++;
		}
		n /= 10;
	}
	return count;
}

unsigned sortNumberDecreasingOrder(unsigned n)
{
	unsigned result = 0;
	
	for (short i = 9; i >= 0; i--)
	{
		short count = countDigitOccurrences(n, i);
		result = concatNTimesDigit(result, i, count);
	}
	
	return result;
}

int main()
{
    cout << sortNumberDecreasingOrder(907380);
}
