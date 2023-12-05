#include <iostream>
using namespace std;

size_t myStrlen(const char* str)
{
	if (str == nullptr)
	{
		return 0;
	}

	size_t count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

// we assume that dest has enough space
void myStrcpy(char* dest, const char* src)
{
	if (dest == nullptr || src == nullptr)
	{
		return;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

// we assume that dest has enough space
void myStrcat(char* dest, const char* src)
{
	size_t destLen = myStrlen(dest);
	dest += destLen;
	myStrcpy(dest, src);
}

int myStrcmp(const char* lhs, const char* rhs)
{
	if (lhs == nullptr || rhs == nullptr)
	{
		return -2; // an exception should be thrown here
	}

	while (*lhs != '\0' && *rhs != '\0')
	{
		if (*lhs < *rhs)
		{
			return -1;
		}
		if (*lhs > *rhs)
		{
			return 1;
		}
		lhs++;
		rhs++;
	}

	if (*lhs == '\0' && *rhs == '\0')
	{
		return 0;
	}
	return *lhs == '\0' ? -1 : 1;
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
int myAtoi(const char* str)
{
	if (str == nullptr)
	{
		return 0;
	}

	bool negative = false;
	if (*str == '-')
	{
		str++;
		negative = true;
	}

	unsigned int result = 0;
	while (*str != '\0' && isDigit(*str))
	{
		unsigned short digit = *str - '0';
		(result *= 10) += digit;
		str++;
	}

	return negative ? -result : result;
}

int main()
{
	cout << myAtoi("57452");
}
