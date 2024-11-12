#include <stdio.h>

unsigned reverse(unsigned n)
{
    unsigned reversedNumber = 0;
    while (n != 0)
    {
        short lastDigit = n % 10;
        reversedNumber *= 10;
        reversedNumber += lastDigit;
        
        n /= 10;
    }
    return reversedNumber;
}

int isSuffix(unsigned n, unsigned k)
{
    if (k > n)
    {
        return 0;
    }
    if (k == 0)
    {
        return n % 10 == 0;
    }
    while (k != 0)
    {
        short lastDigitOfN = n % 10;
        short lastDigitOfK = k % 10;

        if (lastDigitOfN != lastDigitOfK)
        {
            return 0;
        }

        n /= 10;
        k /= 10;
    }
    return 1;
}

int isPrefix(unsigned n, unsigned k)
{
    return isSuffix(reverse(n), reverse(k));
}

int isInfix(unsigned n, unsigned k)
{
    if (n == 0 && k == 0)
    {
        return 1;
    }
    while (n > 0)
    {
        if (isSuffix(n, k))
        {
            return 1;
        }
        n /= 10;
    }
    return 0;
}

int main()
{
    printf("%d\n", isInfix(2831, 83));
    return 0;
}
