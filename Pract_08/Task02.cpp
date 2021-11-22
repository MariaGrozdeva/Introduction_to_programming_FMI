#include <iostream>
using namespace std;

void Strcat(char lhs[], const char rhs[])
{
	size_t lenLhs = strlen(lhs);
	size_t lenRhs = strlen(rhs);

	for (size_t i = 0; i < lenRhs; i++)
		lhs[lenLhs + i] = rhs[i];
}

int main()
{
	const int maxSize = 64;

	char str1[maxSize] = "pine";
	char str2[] = { 'a','p','p','l','e','\0' };

	Strcat(str1, str2);
	cout << str1;
}