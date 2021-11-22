#include <iostream>
using namespace std;

void Strcpy(char lhs[], const char rhs[])
{
	size_t lenRhs = strlen(rhs);

	for (size_t i = 0; i < lenRhs; i++)
		lhs[i] = rhs[i];
	lhs[lenRhs] = '\0';
}

int main()
{
	const int maxSize = 64;

	char str1[maxSize] = "work";
	char str2[] = "vacation";

	Strcpy(str1, str2);
	cout << str1;
}