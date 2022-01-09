#include <iostream>
using namespace std;

size_t Strlen(const char str[])
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return len;
}

int main()
{
	char str[] = "Informatics";
	cout << Strlen(str);
}