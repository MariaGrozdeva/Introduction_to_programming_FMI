#include <stdio.h>

unsigned int toDecimal(unsigned long long n)
{
    unsigned int decimalNum = 0;
    unsigned int multiplier = 1;

    while (n != 0)
    {
        decimalNum += (n % 10 * multiplier);
        multiplier *= 2;
        n /= 10;
    }

    return decimalNum;
}

int main()
{
    printf("%u\n", toDecimal(0b10111));
    return 0;
}
