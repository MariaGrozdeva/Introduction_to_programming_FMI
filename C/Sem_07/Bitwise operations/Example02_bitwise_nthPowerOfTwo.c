#include <stdio.h>

unsigned int nthPowerOfTwo(unsigned int n)
{
    if (n > 31)
    {
        return 0; // Indicate an error; in real applications, you might handle this differently
    }

    return 1 << n;
}

int main()
{
    printf("%u\n", nthPowerOfTwo(8));
    return 0;
}
