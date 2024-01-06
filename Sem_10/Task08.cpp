#include <iostream>
#include <string>
#include <cstring>

#pragma warning (disable : 4996)

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool containsNinesOnly(const char*& str)
{
	while (*str != '\0' && isDigit(*str))
	{
		if (*str != '9')
		{
			return false;
		}
		str++;
	}
	return true;
}

unsigned int getNumsWithNinesOnlyCount(const char* str)
{
	unsigned int count = 0;
	while (*str != '\0')
	{
		if (*str == '9' && containsNinesOnly(++str))
		{
			count++;
		}
		str++;
	}
	return count;
}

unsigned int getNumber(const char*& str)
{
	unsigned int number = 0;
	while (*str != '\0' && isDigit(*str))
	{
		(number *= 10) += *str - '0';
		str++;
	}
	return number;
}

char* incrementEachNumber(const char* str)
{
	unsigned int numsWithNinesOnlyCount = getNumsWithNinesOnlyCount(str);
	char* resultStr = new char[strlen(str) + numsWithNinesOnlyCount + 1];
	*resultStr = '\0';

	while (*str != '\0')
	{
		if (!isDigit(*str))
		{
			char toAppend[2] = { *str, '\0' };
			strcat(resultStr, toAppend);

			str++;
		}
		else
		{
			unsigned int incrementedNum = getNumber(str) + 1;
			strcat(resultStr, std::to_string(incrementedNum).c_str());
		}
	}

	return resultStr;
}

int main()
{
	const size_t MAX_SIZE = 1024;
	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	char* result = incrementEachNumber(str);
	std::cout << result;

	delete[] result;
}