#include <iostream>
using namespace std;

int Strcmp(const char lhs[], const char rhs[])
{
	size_t lenLhs = strlen(lhs);
	size_t lenRhs = strlen(rhs);

	size_t biggerSize = lenLhs > lenRhs ? lenLhs : lenRhs;

	for (size_t i = 0; i < biggerSize; i++)
	{ 
		if (lhs[i] < rhs[i])
			return -1;
		else if (lhs[i] > rhs[i])
			return 1;
	}
	return 0;
}

int main()
{
	char str1[] = "three";
	char str2[] = "tree";

	cout << Strcmp(str1, str2);
}