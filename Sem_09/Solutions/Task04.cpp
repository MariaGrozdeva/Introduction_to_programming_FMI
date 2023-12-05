#include <iostream>
#include <cstring>
using namespace std;

bool isPrefix(const char* pattern, const char* str)
{
	while (*pattern != '\0' && *str != '\0')
	{
		if (*pattern != *str)
		{
			return false;
		}
		pattern++;
		str++;
	}

	return *pattern == '\0';
}

bool isSubstring(const char* str, const char* pattern)
{
	size_t strLen = strlen(str);
	size_t patternLen = strlen(pattern);

	while (patternLen <= strLen)
	{
		if (isPrefix(pattern, str))
		{
			return true;
		}
		str++;
		strLen--;
	}

	return false;
}

int main()
{
	char str[] = "nightlife";
	char pattern[] = "night";

	cout << isSubstring(str, pattern);
}
