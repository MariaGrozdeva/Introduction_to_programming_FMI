#include <stdio.h>

/*
**Задача 1:** Да се напише програма, която при подадено число, отговарящо на оценка, изписва оценката с думи.
*Вход: 3, Изход: Average
Вход: 4, Изход: Good
Вход: 10, Изход: Invalid grade!*
*/

int main()
{
    unsigned short grade = 0;
    scanf("%hu", &grade);
    switch (grade)
    {
    case 2:
        printf("Failing");
    case 3:
        printf("Average");
        break;
    case 4:
        printf("Good");
        break;
    case 5:
        printf("Very good");
        break;
    case 6:
        printf("Excellent");
        break;
    default:
        printf("Invalid grade!");
        break;
    }
    return 0;
}