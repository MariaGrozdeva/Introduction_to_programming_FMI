#include <iostream>
using namespace std;

bool isUppercase(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}
bool isLowercase(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void getUppercaseAndLowercaseCount(const char* str, int& uppercaseCount, int& lowercaseCount)
{
	int len = strlen(str);

	for (size_t i = 0; i < len; i++)
	{
		if (isUppercase(str[i]))
			uppercaseCount++;
		else if (isLowercase(str[i]))
			lowercaseCount++;
	}
}

void getXandY(const char* str, char*& X, char*& Y)
{
	int uppercaseCount = 0;
	int lowercaseCount = 0;

	getUppercaseAndLowercaseCount(str, uppercaseCount, lowercaseCount);

	int strLen = strlen(str);
	X = new char[uppercaseCount + 1];
	Y = new char[lowercaseCount + 1];

	char XIter = 0;
	char YIter = 0;
	for (size_t i = 0; i < strLen; i++)
	{
		if (isUppercase(str[i]))
			X[XIter++] = str[i];
		else if (isLowercase(str[i]))
			Y[YIter++] = str[i];
	}
	X[XIter] = '\0';
	Y[YIter] = '\0';
}

int main()
{
	const int maxSize = 256;

	char* str = new char[maxSize + 1];
	cin.getline(str, maxSize);

	char* X;
	char* Y;
	getXandY(str, X, Y);
	cout << X << endl;
	cout << Y << endl;

	delete[] str;
	delete[] X;
	delete[] Y;
}