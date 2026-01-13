#include <iostream>
#include <cstring>
using namespace std;

bool isUppercase(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}
bool isLowercase(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void getUppercaseAndLowercaseCount(const char* str, unsigned int& uppercaseCount, unsigned int& lowercaseCount)
{
	while (*str != '\0')
	{
		if (isUppercase(*str))
		{
			uppercaseCount++;
		}
		else if (isLowercase(*str))
		{
			lowercaseCount++;
		}
		str++;
	}
}

void getuppercaseStrandlowercaseStr(const char* str, char*& uppercaseStr, char*& lowercaseStr)
{
	if (!str)
	{
		return;
	}
	
	unsigned int uppercaseCount = 0;
	unsigned int lowercaseCount = 0;

	getUppercaseAndLowercaseCount(str, uppercaseCount, lowercaseCount);

	uppercaseStr = new char[uppercaseCount + 1];
	lowercaseStr = new char[lowercaseCount + 1];

	unsigned int uppercaseStrIter = 0;
	unsigned int lowerCaseStrIter = 0;

	while (*str != '\0')
	{
		if (isUppercase(*str))
		{
			uppercaseStr[uppercaseStrIter++] = *str;
		}
		else if (isLowercase(*str))
		{
			lowercaseStr[lowerCaseStrIter++] = *str;
		}
		str++;
	}
	uppercaseStr[uppercaseStrIter] = lowercaseStr[lowerCaseStrIter] = '\0';
}

int main()
{
	constexpr size_t MAX_SIZE = 256;

	char str[MAX_SIZE + 1];
	cin.getline(str, MAX_SIZE);

	char* uppercaseStr = nullptr;
	char* lowercaseStr = nullptr;
	getuppercaseStrandlowercaseStr(str, uppercaseStr, lowercaseStr);
	cout << uppercaseStr << endl;
	cout << lowercaseStr << endl;

	delete[] uppercaseStr;
	delete[] lowercaseStr;
}
