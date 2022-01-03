#include <iostream>

bool isPalindrome(const char* str, int start, int size)
{
	if (str[start] != str[size - 1])
		return false;
	if (start >= size)
		return true;

	return isPalindrome(str, start + 1, size - 1);
}

bool isPalindromeWrapper(const char* str, int size)
{
	return isPalindrome(str, 0, size);
}

int main()
{
	char str[] = "abcdcba";
	int len = strlen(str);
	std::cout << (isPalindromeWrapper(str, len) ? "Yes" : "No");

	return 0;
}
