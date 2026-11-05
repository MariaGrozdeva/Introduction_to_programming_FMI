#include <stdio.h>

unsigned reverse(unsigned n)
{
    unsigned reversedNumber = 0;

    while (n != 0)
    {
        unsigned lastDigit = n % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        n /= 10;
    }

    return reversedNumber;
}

int isPalindrome(unsigned n)
{
    return n == reverse(n);
}

int main()
{
    unsigned number = 12321;
    if (isPalindrome(number))
    {
        printf("%u is a palindrome.\n", number);
    }
    else
    {
        printf("%u is not a palindrome.\n", number);
    }
    return 0;
}
