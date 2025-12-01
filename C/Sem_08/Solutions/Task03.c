#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 64

void lowerToUpperCase(char* str)
{
	if (str == NULL)
	{
		return;
	}

	unsigned short diffBetweenCapitalAndSmallA = abs('A' - 'a');
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= diffBetweenCapitalAndSmallA;
		}
		str++;
	}
}

int main()
{
	char str[MAX_SIZE];
	fgets(str, MAX_SIZE, stdin);
	str[strcspn(str, "\n")] = '\0'; // Remove newline
	lowerToUpperCase(str);
	fputs(str, stdout);
}
