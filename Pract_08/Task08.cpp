#include <iostream>

unsigned strLen(const char str[])
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}

bool areTwoWordsSame(const char str1[], const char str2[], unsigned startIdx)
{
	unsigned len2 = strLen(str2);
	unsigned newLen = startIdx + len2;
	for (size_t i = startIdx, j = 0; i < newLen; i++, j++)
	{
		if (str1[i] != str2[j])
			return false;
	}

	return true;
}

bool isSubString(const char str[], const char subStr[])
{
	unsigned idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == subStr[0] && areTwoWordsSame(str, subStr, idx))
			return true;

		idx++;
	}

	return false;
}

int main()
{
	char str[] = "helloC++World";
	char subStr[] = "C++";
	std::cout << (isSubString(str, subStr) ? "Yes" : "No");

	return 0;
}