#include <iostream>
using namespace std;

void extractDigits(const char inputStr[], char resultStr[])
{
	size_t len = strlen(inputStr);
	int currentResPos = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (inputStr[i] >= '0' && inputStr[i] <= '9')
			resultStr[currentResPos++] = inputStr[i];
	}
	resultStr[currentResPos] = '\0';
}

int convertStringToNumber(const char str[])
{
	size_t len = strlen(str);
	int number = 0;

	for (size_t i = 0; i < len; i++)
		(number *= 10) += str[i] - '0';

	return number;
}

int main()
{
	const int maxSize = 64;

	char inputStr[maxSize];
	cin.getline(inputStr, maxSize);

	char resultStr[maxSize];

	extractDigits(inputStr, resultStr);
	cout << convertStringToNumber(resultStr);
}