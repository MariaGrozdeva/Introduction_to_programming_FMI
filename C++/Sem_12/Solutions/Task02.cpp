#include <iostream>

int myAtoi(const char *str, int res)
{
    if (*str == '\0')
    {
        return res;
    }

    return myAtoi(++str, (res *= 10) + *str - '0');
}

int myAtoi(const char *str)
{
    return *str == '-' ? -myAtoi(++str, 0) : myAtoi(str, 0);
}

int main()
{
    std::cout << myAtoi("-42") << '\n';
    return 0;
}

