#include <iostream>
#include <cstring>

int isPalindrome(const char* str, const int start, const int end)
{
    if (start > end)
    {
        return 1;
    }
    return str[start] == str[end] && isPalindrome(str, start + 1, end - 1);
}

int isPalindrome(const char* str)
{
    if (*str == '\0')
    {
        return 1;
    }
    return isPalindrome(str, 0, std::strlen(str) - 1);
}

int main()
{
    std::cout << isPalindrome("madam");
    return 0;
}
