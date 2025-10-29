#include <stdio.h>

/*
Въвежда се трицифрено цяло число n.
- Ако последната цифра на въведеното число е **0, 2, 4, 6 или 8**, тази цифра да се замени с остатъкът на цифрата по модул 3.
- Ако последната цифра на въведеното число е  **1, 3, 5, 7 или 9**, тази цифра да се замени с остатъкът на цифрата по модул 2.

*Вход: 123, Изход: 121
Вход: 718, Изход: 712*
*/

int main()
{
    int number = 0;
    scanf("%d", &number);

    unsigned short thirdDigit = number % 10;
    number -= thirdDigit;

    if (thirdDigit % 2 == 0)
    {
        thirdDigit %= 3;
    }
    else
    {
        thirdDigit %= 2;
    }
    printf("%d", number += thirdDigit);

    return 0;
}