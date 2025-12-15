#include <stdio.h>
#include <limits.h>

unsigned short getBitCount(unsigned int value)
{
    unsigned short count = 0;
    do
    {
        count++;
        value >>= 1;
    } while (value != 0);
    return count;
}

int isNumberContained(unsigned int n, unsigned int k)
{
    unsigned short size = sizeof(unsigned int) * CHAR_BIT;
    unsigned short bitsCount = getBitCount(k);
    unsigned int mask = (1u << bitsCount) - 1u;
    
    for (unsigned int i = 0; i + bitsCount <= size; i++)
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
    unsigned int n = 0, k = 0;
    scanf("%u %u", &n, &k);
    isNumberContained(n, k) ? puts("true") : puts("false");
    return 0;
}
