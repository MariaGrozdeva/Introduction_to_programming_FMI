#include <iostream>
#include <cstring>
using namespace std;

void extractDigits(const char* inputStr, char* resultStr)
{
	if (inputStr == nullptr || resultStr == nullptr)
	{
		return;
	}

	while (*inputStr != '\0')
	{
		if (*inputStr >= '0' && *inputStr <= '9')
		{
			*resultStr = *inputStr;
			resultStr++;
		}
		inputStr++;
	}
	*resultStr = '\0';
}

unsigned int convertStringToNumber(const char* str)
{
	if (str == nullptr)
	{
		return 0;
	}

	unsigned int number = 0;
	while (*str != '\0')
	{
		(number *= 10) += *str - '0';
		str++;
	}
	return number;
}

int main()
{
	constexpr size_t MAX_SIZE = 64;

	char inputStr[MAX_SIZE];
	cin.getline(inputStr, MAX_SIZE);

	char resultStr[MAX_SIZE];

	extractDigits(inputStr, resultStr);
	cout << convertStringToNumber(resultStr);
}
