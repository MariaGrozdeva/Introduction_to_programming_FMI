#include <stdio.h>

int myAtoiHelper(const char *str, int res)
{
    if (*str == '\0')
    {
        return res;
    }

    res *= 10;
    return myAtoiHelper(++str, res + *str - '0');
}

int myAtoi(const char *str)
{
    return *str == '-' ? -myAtoiHelper(++str, 0) : myAtoiHelper(str, 0);
}

int main()
{
    printf("%d\n", myAtoi("-42"));
    return 0;
}
