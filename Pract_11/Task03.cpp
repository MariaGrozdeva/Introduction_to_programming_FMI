#include <iostream>
using namespace std;

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
int getDigitsCount(const char* str)
{
	int len = strlen(str);
	int digitsCount = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (isDigit(str[i]))
			digitsCount++;
	}

	return digitsCount;
}

void removeDigits(const char* str, char*& result)
{
	int strLen = strlen(str);
	result = new char[strLen - getDigitsCount(str) + 1];

	char newStrIter = 0;
	for (size_t i = 0; i < strLen; i++)
	{
		if (!isDigit(str[i]))
			result[newStrIter++] = str[i];
	}
	result[newStrIter] = '\0';
}

int main()
{
	const int maxSize = 128;

	char str[maxSize + 1];
	cin.getline(str, maxSize);

	char* result;
	removeDigits(str, result);
	cout << result;

	delete[] result;
}