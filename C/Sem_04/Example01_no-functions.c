#include <stdio.h>
#include <math.h>

int main()
{
    unsigned n;
    scanf("%u", &n);

    for (size_t i = 6; i < n - 1; i += 6)
    {
        unsigned firstToCheck = i - 1;
        unsigned secondToCheck = i + 1;

        // Prime check for firstToCheck
        int isFirstPrime = 1; // true
        double sqrtFirstToCheck = sqrt(firstToCheck);
        for (size_t divisorCandidate = 2; divisorCandidate <= sqrtFirstToCheck; divisorCandidate++)
        {
            if (firstToCheck % divisorCandidate == 0)
            {
                isFirstPrime = 0; // false
                break;
            }
        }

        if (!isFirstPrime)
        {
            continue;
        }

        // Prime check for secondToCheck
        int isSecondPrime = 1; // true
        double sqrtSecondToCheck = sqrt(secondToCheck);
        for (size_t divisorCandidate = 2; divisorCandidate <= sqrtSecondToCheck; divisorCandidate++)
        {
            if (secondToCheck % divisorCandidate == 0)
            {
                isSecondPrime = 0; // false
                break;
            }
        }

        if (isSecondPrime)
        {
            printf("<%u, %u>\n", firstToCheck, secondToCheck);
        }
    }

    return 0;
}
