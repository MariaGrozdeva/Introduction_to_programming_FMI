#include <stdio.h>
#include <limits.h>

unsigned short getBitCount(int value)
{
    unsigned short count = 0;
    while (value != 0)
    {
        count++;
        value >>= 1;
    }
    return count;
}

int isNumberContained(int n, int k)
{
    unsigned short size = sizeof(int) * CHAR_BIT;
    int mask = (1 << getBitCount(k)) - 1;
    for (int i = 0; i < size; i++)
    {
        if (((n >> i) & mask) == k)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    isNumberContained(n, k) ? puts("true") : puts("false");
    return 0;
}