#include <stdio.h>
#include <limits.h>

unsigned int getMinimumOperations(unsigned int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2 || n == 3)
    {
        return 1;
    }

    unsigned int v1 = n % 3 == 0 ? getMinimumOperations(n / 3) : UINT_MAX;
    unsigned int v2 = n % 2 == 0 ? getMinimumOperations(n / 2) : UINT_MAX;
    unsigned int v3 = getMinimumOperations(n - 1);

    unsigned int minVal = v1;
    if (v2 < minVal) minVal = v2;
    if (v3 < minVal) minVal = v3;

    return 1 + minVal;
}

int main()
{
    printf("The minimum number of operations is %u\n", getMinimumOperations(117));
    return 0;
}
