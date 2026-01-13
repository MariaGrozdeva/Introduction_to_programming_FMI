#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    short thirdDigit = n % 10; // get the last digit
    n /= 10; // remove the last digit

    short secondDigit = n % 10; // get the second digit
    n /= 10; // remove the second digit

    int reversed = thirdDigit * 100 + secondDigit * 10 + n; // n is already consisting of only one digit
    reversed++;

    printf("%d\n", reversed);

    return 0;
}
