#include <stdio.h>
#include <string.h>

int isPalindromeHelper(const char* str, const int start, const int end)
{
    if (start > end)
    {
        return 1;
    }
    return str[start] == str[end] && isPalindromeHelper(str, start + 1, end - 1);
}

int isPalindrome(const char* str)
{
    if (*str == '\0')
    {
        return 1;
    }
    return isPalindromeHelper(str, 0, strlen(str) - 1);
}

int main()
{
    printf("%d", isPalindrome("madam"));
    return 0;
}
