#include <iostream>
using namespace std;

int toDigit(char ch)
{
	return ch - '0';
}
int Atoi(const char* str, int len)
{
	if (len == 1)
		return *str - '0';

	return Atoi(str, len - 1) * 10 + toDigit(str[len - 1]);
}

int main()
{
	char str[] = "112";
	int len = strlen(str);

	int number = Atoi(str, len);

	cout << number;
}