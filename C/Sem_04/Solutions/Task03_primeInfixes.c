#include <stdio.h>
#include <math.h>

int isPrime(unsigned n)
{
    if (n <= 1)
    {
        return 0;
    }

    unsigned sqrtN = (unsigned)sqrt(n);
    for (unsigned divisorCandidate = 2; divisorCandidate <= sqrtN; divisorCandidate++)
    {
        if (n % divisorCandidate == 0)
        {
            return 0;
        }
    }
    return 1;
}

void printPrimeInfixes(unsigned n)
{
    while (n != 0)
    {
        for (unsigned i = 10;; i *= 10)
        {
            unsigned currentInfix = n % i;
            if (isPrime(currentInfix))
            {
                printf("%u ", currentInfix);
            }

            if (currentInfix == n)
            {
                break;
            }
        }
        n /= 10;
    }
    printf("\n");
}

int main()
{
    printPrimeInfixes(753);
    return 0;
}
