#include <stdio.h>
#include <string.h>

#define MAX_SIZE 64

void extractDigits(const char* inputStr, char* resultStr)
{
	if (inputStr == NULL || resultStr == NULL)
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

int main()
{
	char inputStr[MAX_SIZE];
	fgets(inputStr, MAX_SIZE, stdin);
	inputStr[strcspn(inputStr, "\n")] = '\0'; // Remove newline

	char resultStr[MAX_SIZE];

	extractDigits(inputStr, resultStr);
	fputs(resultStr, stdout);
}
