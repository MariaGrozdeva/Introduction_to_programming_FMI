#include <iostream>
#include <cstring>
using namespace std;

void printString(const char* str)
{
	cout << str << endl;
}

void generateAllStringsOfLenK(char* string, unsigned int pos, size_t size, const char* set, unsigned int k)
{
	if (k == 0)
	{
		string[pos] = '\0';
		printString(string);
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		string[pos] = set[i];
		generateAllStringsOfLenK(string, pos + 1, size, set, k - 1);
	}
}

void printStringsOfLenK(const char* set, size_t size, unsigned int k)
{
	char* string = new char[k + 1];
	generateAllStringsOfLenK(string, 0, size, set, k);
	delete[] string;
}

int main()
{
	const char str[] = { 'a', 'b', '\0' };
	const unsigned int k = 3;

	printStringsOfLenK(str, strlen(str), k);
}