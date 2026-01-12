#include <stdio.h>

unsigned getCharCountCondition(const char* str, int(*pred)(char))
{
    unsigned count = 0;
    while (*str)
    {
        if (pred(*str))
        {
            count++;
        }
        str++;
    }
    return count;
}

int isLower(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

int isCapital(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

int isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int isWhitespace(char ch)
{
    return ch == ' ';
}

unsigned getLowersCount(const char* str)
{
    return getCharCountCondition(str, isLower);
}

unsigned getCapitalsCount(const char* str)
{
    return getCharCountCondition(str, isCapital);
}

unsigned getDigitsCount(const char* str)
{
    return getCharCountCondition(str, isDigit);
}

unsigned getWhitespacesCount(const char* str)
{
    return getCharCountCondition(str, isWhitespace);
}

int main()
{
    char str[] = "Hello World";
    printf("%u\n", getCapitalsCount(str));
    return 0;
}
