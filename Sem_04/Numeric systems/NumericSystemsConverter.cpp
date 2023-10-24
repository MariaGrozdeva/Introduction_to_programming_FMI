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

unsigned short getIndexOfSymbol(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'F')
	{
		return 10 + (ch - 'A');
	}
	else
	{
		return -1;
	}
}
char getSymbolByIndex(unsigned short index)
{
	if (index >= 0 && index <= 9)
	{
		return index + '0';
	}
	else if (index >= 10 && index <= 15)
	{
		return (index - 10) + 'A';
	}
	else
	{
		return 0;
	}
}

unsigned int randomToDecimal(const char from[], size_t len, unsigned short k)
{
	unsigned int decimalNum = 0;
	for (int i = len - 1, multiplier = 1; i >= 0; i--, multiplier *= k)
	{
		decimalNum += getIndexOfSymbol(from[i]) * multiplier;
	}
	return decimalNum;
}
void decimalToRandom(unsigned int decimalNum, char to[], size_t len, unsigned short k)
{
	for (int i = len - 1; i >= 0; i--)
	{
		to[i] = getSymbolByIndex(decimalNum % k);
		decimalNum /= k;
	}
}

void randomToRandom(const char from[], size_t fromSize, unsigned short k1, char to[], size_t toSize, unsigned short k2)
{
	unsigned int decimalNum = randomToDecimal(from, fromSize, k1);
	decimalToRandom(decimalNum, to, toSize, k2);
}

int main()
{
	const int SIZE = 5;
	char from[] = { '0', '0', 'A', 'B', '3' };
	char to[SIZE];

	randomToRandom(from, SIZE, 16, to, SIZE, 10);
	print(to, SIZE);
}
