#include <iostream>
using namespace std;

bool isPrefix(const char* str1, const char* str2)
{
	if (*str2 == '\0')
		return true;

	return *str1 == *str2 && isPrefix(str1 + 1, str2 + 1);
}
bool isSubstring(const char* str1, const char* str2)
{
	if (*str1 == '\0')
		return *str2 == '\0';

	return isPrefix(str1, str2) || isSubstring(str1 + 1, str2);
}

int main()	
{
	char str1[] = "nanan nightlife";
	char str2[] = "night";

	cout << isSubstring(str1, str2);
}