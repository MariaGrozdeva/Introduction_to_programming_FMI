#include <iostream>
#include <string>
#include <cstring>

#pragma warning (disable : 4996)

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

short getDigitsCount(unsigned int num)
{
	short count = 0;
    	while (num)
    	{
        	count++;
        	num /= 10;
    	}
    	return count;
}

bool containsNinesOnly(const char*& str)
{
	while (*str && isDigit(*str))
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
	while (*str)
	{
		if (*str == '9' && containsNinesOnly(++str))
		{
			count++;
		}
		str++;
	}
	return count;
}

unsigned int stringToNumber(const char*& str)
{
	unsigned int number = 0;
	while (*str && isDigit(*str))
	{
		(number *= 10) += *str - '0';
		str++;
	}
	return number;
}

const char* numberToString(unsigned int number)
{
	short digitsCount = getDigitsCount(number);
    	char* res = new char[digitsCount + 1];
    	for (int i = digitsCount - 1; i >= 0; i--)
    	{
        	res[i] = number % 10 + '0';
        	number /= 10;
    	}
    	res[digitsCount] = '\0';
    	return res;
}

const char* incrementEachNumber(const char* str)
{
	unsigned int numsWithNinesOnlyCount = getNumsWithNinesOnlyCount(str);
	char* resultStr = new char[strlen(str) + numsWithNinesOnlyCount + 1];
	*resultStr = '\0';

	while (*str)
	{
		if (!isDigit(*str))
		{
			char toAppend[2] = { *str, '\0' };
			strcat(resultStr, toAppend);
			str++;
		}
		else
		{
			unsigned int incrementedNumber = stringToNumber(str) + 1;
			const char* incrementedNumberAsString = numberToString(incrementedNumber);
			strcat(resultStr, incrementedNumberAsString);
			delete[] incrementedNumberAsString;
		}
	}

	return resultStr;
}

int main()
{
	constexpr size_t MAX_SIZE = 1024;
	char str[MAX_SIZE + 1];
	std::cin.getline(str, MAX_SIZE);

	const char* result = incrementEachNumber(str);
	std::cout << result;

	delete[] result;
}
