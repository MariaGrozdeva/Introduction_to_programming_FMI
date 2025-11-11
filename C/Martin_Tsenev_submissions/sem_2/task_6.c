#include <stdio.h>
/*
Въвежда се цяло число. Да се напише програма, която отпечата с думи кой ден от седмицата е.
*Вход: 1, Изход: Monday
Вход: 5, Изход: Friday
Вход: 250, Изход: Invalid day!*
*/

int main()
{
    unsigned short day = 0;
    scanf("%hu", &day);
    switch (day)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    default:
        printf("Invalid day!");
        break;
    }
    return 0;
}