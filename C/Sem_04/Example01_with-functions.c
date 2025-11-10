#include <stdio.h>
#include <math.h>

int isPrime(unsigned n)
{
    if (n <= 1)
    {
        return 0;
    }

    unsigned sqrtN = sqrt(n);
    for (size_t divisorCandidate = 2; divisorCandidate <= sqrtN; divisorCandidate++)
    {
        if (n % divisorCandidate == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    unsigned n;
    scanf("%u", &n);

    for (size_t i = 6; i < n - 1; i += 6)
    {
        if (isPrime(i - 1) && isPrime(i + 1))
        {
            printf("<%u, %u>\n", i - 1, i + 1);
        }
    }

    return 0;
}
