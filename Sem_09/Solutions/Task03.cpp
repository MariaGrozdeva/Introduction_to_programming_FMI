#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void lowerToUpperCase(char* str)
{
	if (str == nullptr)
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
	constexpr int MAX_SIZE = 64;

	char str[MAX_SIZE];
	cin.getline(str, MAX_SIZE);

	lowerToUpperCase(str);
	cout << str;
}
