#include <iostream>
using namespace std;

void printString(const char* str)
{
	cout << str << endl;
}
void generateAllStringsOfLenK(const char* set, int setLen, int k, char* currentString, int currentPos)
{
	if (k == 0)
	{
		currentString[currentPos] = '\0';
		printString(currentString);
		return;
	}

	for (size_t i = 0; i < setLen; i++)
	{
		currentString[currentPos] = set[i];
		generateAllStringsOfLenK(set, setLen, k - 1, currentString, currentPos + 1);
	}
}
void generateAllStringsOfLenKWrapper(const char* set, int setLen, int k)
{
	char* currentString = new char[k + 1];
	int currentPos = 0;

	generateAllStringsOfLenK(set, setLen, k, currentString, currentPos);

	delete[] currentString;
}

int main()
{
	char set[] = { 'a', 'b', '\0' };
	int setLen = strlen(set);
	int k = 3;

	generateAllStringsOfLenKWrapper(set, setLen, k);
}