#include <iostream>
#include <cstring>

bool isPalindrome(const char* str, int size, int start)
{
	int len = strlen(str);

	if (len % 2 == 0)
	{
		if (start == size)
			return true;

		if (str[start] != str[size - 1])
			return false;
	}
	else
	{
		if (start == size - 1)
			return true;

		if (str[start] != str[size - 1])
			return false;
	}

	isPalindrome(str, size - 1, start + 1);
}

bool isPalindromeWrapper(const char* str, int size)
{
	return isPalindrome(str, size, 0);
}

int main()
{
	char str[] = "abcdcba";
	int len = strlen(str);
	std::cout << (isPalindromeWrapper(str, len) ? "Yes" : "No");

	return 0;
}