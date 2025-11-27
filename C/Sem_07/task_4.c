#include <stdio.h>

int isNumberContained(int number, unsigned short bitCount)
{
    int mask = 1;
    for (int i = 0; i < bitCount - 1; i++)
    {
        mask = (mask << 1) | 1;
    }

    return number & mask;
}

int main()
{
    int n = 0;
    unsigned short bitCount = 0;
    scanf("%d %hd", &n, &bitCount);
    printf("%d", isNumberContained(n, bitCount));
    return 0;
}