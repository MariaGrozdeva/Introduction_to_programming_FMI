#include <iostream>
#include <cstring>

int posOfTheNthMeet(const char* str, int size, int n, char symbol, int start, int cnt)
{
	if (start == size)
		return -1;

	if (str[start] == symbol)
	{
		cnt++;
		if (cnt == n)
			return start;
		else
			return posOfTheNthMeet(str, size, n, symbol, start + 1, cnt);
	}
	else
		return posOfTheNthMeet(str, size, n, symbol, start + 1, cnt);
}

int posOfTheNthMeetWrapper(const char* str, int size, int n, char symbol)
{
	return posOfTheNthMeet(str, size, n, symbol, 0, 0);
}

int main()
{
	const char* str = "abcMdGREaama";
	int len = strlen(str);
	int n = 3;
	char symbol = 'a';
	std::cout << posOfTheNthMeetWrapper(str, len, n, symbol);

	return 0;
}