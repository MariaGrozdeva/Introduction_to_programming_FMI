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

// - lhs < rhs
// 0 lhs == rhs
// + lhs > rhs
int myStrcmp(const char* lhs, const char* rhs)
{
	if (lhs == nullptr || rhs == nullptr)
	{
		return 0; // some error value
	}

	while (*lhs && *rhs && (*lhs == *rhs))
	{
		lhs++;
		rhs++;
	}

	return (*lhs - *rhs);
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
int myAtoi(const char* str)
{
	if (str == nullptr)
	{
		return 0; // some error value
	}

	bool negative = false;
	if (*str == '-')
	{
		str++;
		negative = true;
	}

	int result = 0;
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
