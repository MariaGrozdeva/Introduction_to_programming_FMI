#include <iostream>

int posOfTheNthMeet(const char* str, int size, char symbol, int n, int currentPos)
{
	if (size == 0)
		return -1;
	if (n == 0)
		return currentPos - 1;
	
	if (*str == symbol)
		return posOfTheNthMeet(str + 1, size - 1, symbol, n - 1, currentPos + 1);
	else
		return posOfTheNthMeet(str + 1, size - 1, symbol, n, currentPos + 1);
}

int posOfTheNthMeetWrapper(const char* str, int size, char symbol, int n)
{
	return posOfTheNthMeet(str, size, symbol, n, 0);
}

int main()
{
	char str[] = "abcMdGREaama";
	int len = strlen(str);
	char symbol = 'a';
	int n = 3;

	std::cout << posOfTheNthMeetWrapper(str, len, symbol, n);

	return 0;
}
