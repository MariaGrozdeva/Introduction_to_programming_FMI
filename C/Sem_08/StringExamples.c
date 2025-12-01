#include <stdio.h>

size_t myStrlen(const char* str)
{
	if (str == NULL)
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
	if (dest == NULL || src == NULL)
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
	if (lhs == NULL || rhs == NULL)
	{
		return 0; // some error value
	}

	while (*lhs && *rhs && (*lhs == *rhs))
	{
		lhs++;
		rhs++;
	}

	return *lhs - *rhs;
}

int isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
int myAtoi(const char* str)
{
	if (str == NULL)
	{
		return 0; // some error value
	}

	int negative = 0;
	if (*str == '-')
	{
		str++;
		negative = 1;
	}

	int result = 0;
	while (*str != '\0' && isDigit(*str))
	{
		unsigned short digit = *str - '0';
		result *= 10;
		result += digit;
		str++;
	}

	return negative ? -result : result;
}

int main()
{
	printf("%d", myAtoi("-57452"));
}
