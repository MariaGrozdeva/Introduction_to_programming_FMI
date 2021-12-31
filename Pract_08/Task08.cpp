#include <iostream>
using namespace std;

bool isSubstring(const char lhs[], const char rhs[])
{
	size_t lenLhs = strlen(lhs);
	size_t lenRhs = strlen(rhs);

	for (size_t i = 0; i < lenLhs; i++)
	{
		bool differenceFound = false;

		if (lhs[i] == rhs[0])
		{
			int rhsIndex = 1;
			int begin = i + 1;

			for (int j = begin; j < begin + lenRhs - 1; j++)
			{
				if (lhs[j] != rhs[rhsIndex++])
				{
					differenceFound = true;
					break;
				}
			}
			if (!differenceFound)
				return true;
		}
	}
	return false;
}

int main()
{
	const int maxSize = 64;

	char firstStr[maxSize];
	char secondStr[maxSize];

	cin.getline(firstStr, maxSize);
	cin.getline(secondStr, maxSize);

	cout << isSubstring(firstStr, secondStr);
}