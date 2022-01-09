#include <iostream>

int strlenRec(const char* str)
{
	if (*str == '\0')
		return 0;

	return 1 + strlenRec(str + 1);
}

int main()
{
	char str[] = "abcdcba";
	std::cout << strlenRec(str);	
}