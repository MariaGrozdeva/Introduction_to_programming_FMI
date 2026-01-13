#include <iostream>
#include <cstring>

void printString(const char* str)
{
	std::cout << str << std::endl;
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
	char* string = new char[k + 1];
	generateAllStringsOfLenK(string, 0, set, n, k);
	delete[] string;
}

int main()
{
	const char str[] = { 'a', 'b', '\0' };
	const unsigned int k = 3;

	printStringsOfLenK(str, strlen(str), k);
}
