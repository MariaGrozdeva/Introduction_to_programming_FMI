#include <stdio.h>

unsigned myStrlenHelper(const char *str, unsigned res)
{
    if (*str == '\0')
    {
        return res;
    }
    return myStrlenHelper(++str, ++res);
}

unsigned myStrlen(const char *str)
{
    return myStrlenHelper(str, 0);
}

int main()
{
    printf("%u\n", myStrlen("informatika_3"));
    return 0;
}
