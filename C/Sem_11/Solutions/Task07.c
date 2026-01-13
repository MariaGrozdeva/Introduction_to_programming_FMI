#include <stdio.h>

char firstCapital(const char* str)
{
    if (*str == '\0' || (*str >= 'A' && *str <= 'Z'))
    {
        return *str;
    }
    return firstCapital(++str);
}

int main()
{
    printf("%c", firstCapital("todayIsMonday"));
    return 0;
}
