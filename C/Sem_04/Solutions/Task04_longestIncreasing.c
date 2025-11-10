#include <stdio.h>

short longestIncreasingSubarray(unsigned n) // It's actually a subarray, not a subsequence
{
    short max = 1; // The longest increasing subarray will always consist of at least one element
    short currentMax = 1;

    while (n >= 10)
    {
        short lastDigit = n % 10;
        short preLastDigit = (n / 10) % 10;

        if (preLastDigit < lastDigit)
        {
            currentMax++;
            if (currentMax > max)
            {
                max = currentMax;
            }
        }
        else
        {
            currentMax = 1;
        }
        n /= 10;
    }
    return max;
}

int main()
{
    printf("%d\n", longestIncreasingSubarray(781234489));
    return 0;
}
