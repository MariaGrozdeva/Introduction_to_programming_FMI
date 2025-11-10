#include <stdio.h>

unsigned reverse(unsigned n)
{
    unsigned reversed = 0;
    while (n != 0)
    {
        short lastDigit = n % 10;
        reversed = (reversed * 10) + lastDigit;
        n /= 10;
    }

    return reversed;
}

unsigned concatTwoNumbers(unsigned n, unsigned k)
{
    unsigned concatenated = n;
    unsigned reversedK = reverse(k);

    while (reversedK != 0)
    {
        short lastDigitOfReversedK = reversedK % 10;
        concatenated = (concatenated * 10) + lastDigitOfReversedK;
        reversedK /= 10;
    }

    return concatenated;
}

int main()
{
    printf("%u\n", concatTwoNumbers(22, 1995));
    return 0;
}
