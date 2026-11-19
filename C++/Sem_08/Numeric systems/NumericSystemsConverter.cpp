#include <iostream>
using namespace std;

void print(const char arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

int getIndexOfSymbol(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'F')
	{
		return 10 + (ch - 'A');
	}
	else if (ch >= 'a' && ch <= 'f')
	{
		return 10 + (ch - 'a');
	}
	else
	{
		return -1;
	}
}

char getSymbolByIndex(unsigned short index)
{
	if (index <= 9)
	{
		return index + '0';
	}
	else if (index <= 15)
	{
		return (index - 10) + 'A';
	}
	else
	{
		return '?';
	}
}

bool isValidBase(unsigned short k)
{
	return k >= 2 && k <= 16;
}

bool isValidNumber(const char from[], size_t len, unsigned short k)
{
	for (size_t i = 0; i < len; i++)
	{
		int digit = getIndexOfSymbol(from[i]);
		if (digit < 0 || digit >= k)
		{
			return false;
		}
	}
	return true;
}

// Instead of computing every power of k separately:
//    A*16^2 + B*16^1 + 3*16^0
// factor out the base step by step:
//    A*16^2 + B*16^1 + 3*16^0
//    = (A*16 + B)*16 + 3
//    = ((0*16 + A)*16 + B)*16 + 3
unsigned int randomToDecimal(const char from[], size_t len, unsigned short k)
{
	unsigned int decimalNum = 0;
	for (size_t i = 0; i < len; i++)
	{
		decimalNum = decimalNum * k + getIndexOfSymbol(from[i]);
	}
	return decimalNum;
}

bool decimalToRandom(unsigned int decimalNum, char to[], size_t len, unsigned short k)
{
	for (int i = len; i > 0; i--)
	{
		to[i - 1] = getSymbolByIndex(decimalNum % k);
		decimalNum /= k;
	}
	return decimalNum == 0;
}

bool randomToRandom(const char from[], size_t fromSize, unsigned short k1, char to[], size_t toSize, unsigned short k2)
{
	if (!isValidBase(k1) || !isValidBase(k2) || !isValidNumber(from, fromSize, k1))
	{
		return false;
	}

	unsigned int decimalNum = randomToDecimal(from, fromSize, k1);
	return decimalToRandom(decimalNum, to, toSize, k2);
}

int main()
{
	const int SIZE = 5;
	char from[] = { '0', '0', 'A', 'B', '3' };
	char to[SIZE];

	if (randomToRandom(from, SIZE, 16, to, SIZE, 10))
	{
		print(to, SIZE);
	}
	else
	{
		cout << "Invalid input or result does not fit" << endl;
	}

	return 0;
}
