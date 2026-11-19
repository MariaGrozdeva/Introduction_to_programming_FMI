#include <stdio.h>

unsigned int isEven(unsigned int n)
{
    return !(n & 1);
}

int main()
{
    printf("%u\n", isEven(23));
    return 0;
}
