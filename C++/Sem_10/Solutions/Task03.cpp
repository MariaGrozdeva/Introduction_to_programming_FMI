#include <iostream>
#include <cstring>
using namespace std;

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
unsigned int getDigitsCount(const char* str)
{
	unsigned int digitsCount = 0;
	while (*str != '\0')
	{
		if (isDigit(*str))
		{
			digitsCount++;
		}
		str++;
	}
	return digitsCount;
}

void removeDigits(const char* str, char*& result)
{
	size_t strLen = strlen(str);
	result = new char[strLen - getDigitsCount(str) + 1];

	unsigned int newStrIter = 0;
	for (size_t i = 0; i < strLen; i++)
	{
		if (!isDigit(str[i]))
		{
			result[newStrIter++] = str[i];
		}
	}
	result[newStrIter] = '\0';
}

int main()
{
	constexpr size_t MAX_SIZE = 128;

	char str[MAX_SIZE + 1];
	cin.getline(str, MAX_SIZE);

	char* result = nullptr;
	removeDigits(str, result);
	cout << result;

	delete[] result;
}
