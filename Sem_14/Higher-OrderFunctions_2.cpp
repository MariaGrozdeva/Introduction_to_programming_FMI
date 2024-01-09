#include <iostream>

unsigned getCharCountCondition(const char* str, bool(*pred)(char))
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

unsigned getLowersCount(const char* str)
{
    return getCharCountCondition(str, [](char ch) { return ch >= 'a' && ch <= 'z'; });
}

unsigned getCapitalsCount(const char* str)
{
    return getCharCountCondition(str, [](char ch) { return ch >= 'A' && ch <= 'Z'; });
}

unsigned getDigitsCount(const char* str)
{
    return getCharCountCondition(str, [](char ch) { return ch >= '0' && ch <= '9'; });
}

unsigned getWhitespacesCount(const char* str)
{
    return getCharCountCondition(str, [](char ch) {return ch == ' '; });
}

int main()
{
    char str[] = "Hello World";
    std::cout << getCapitalsCount(str);
}
