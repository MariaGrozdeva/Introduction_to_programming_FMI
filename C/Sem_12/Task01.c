#include <stdio.h>

int isPrefix(const char* text, const char* pattern)
{
	if (*pattern == '\0')
	{
		return 1;
	}

	return (*text == *pattern) && isPrefix(text + 1, pattern + 1);
}

int searchInText(const char* text, const char* pattern)
{
	if (*text == '\0')
	{
		return (*pattern == '\0');
	}

	return isPrefix(text, pattern) || searchInText(text + 1, pattern);
}

int main()
{
	char str[] = "There is thunderstorm!";
	char pattern[] = "storm!";

	printf("%d", searchInText(str, pattern));
	return 0;
}
