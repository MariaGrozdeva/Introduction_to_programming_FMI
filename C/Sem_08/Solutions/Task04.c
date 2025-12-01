#include <stdio.h>
#include <string.h>

int isPrefix(const char* pattern, const char* str)
{
	while (*pattern != '\0' && *str != '\0')
	{
		if (*pattern != *str)
		{
			return 0;
		}
		pattern++;
		str++;
	}

	return *pattern == '\0';
}

int isSubstring(const char* str, const char* pattern)
{
	size_t strLen = strlen(str);
	size_t patternLen = strlen(pattern);

	while (patternLen <= strLen)
	{
		if (isPrefix(pattern, str))
		{
			return 1;
		}
		str++;
		strLen--;
	}

	return 0;
}

int main()
{
	char str[] = "nightlife";
	char pattern[] = "night";

	printf("%d", isSubstring(str, pattern));
}
