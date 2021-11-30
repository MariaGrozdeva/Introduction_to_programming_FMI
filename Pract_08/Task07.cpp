#include <iostream>
using namespace std;

void lowerToUpperCase(char str[])
{
	size_t len = strlen(str);

	for (size_t i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int main()
{
	const int maxSize = 64;

	char str[maxSize];
	cin.getline(str, maxSize);

	lowerToUpperCase(str);
	cout << str;
}