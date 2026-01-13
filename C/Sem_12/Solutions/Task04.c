#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printString(const char* str)
{
	printf("%s\n", str);
}

void generateAllStringsOfLenK(char* string, unsigned int pos, const char* set, const size_t n, unsigned int k)
{
	if (k == 0)
	{
		string[pos] = '\0';
		printString(string);
		return;
	}

	for (size_t i = 0; i < n; i++)
	{
		string[pos] = set[i];
		generateAllStringsOfLenK(string, pos + 1, set, n, k - 1);
	}
}

void printStringsOfLenK(const char* set, const size_t n, unsigned int k)
{
	char* string = (char*)malloc((k + 1) * sizeof(char));
	if (!string)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	generateAllStringsOfLenK(string, 0, set, n, k);
	free(string);
}

int main()
{
	const char str[] = { 'a', 'b', '\0' };
	const unsigned int k = 3;

	printStringsOfLenK(str, strlen(str), k);
	return 0;
}
