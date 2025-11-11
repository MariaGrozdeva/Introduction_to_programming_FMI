#include <stdio.h>

/*
Въвеждат се две реални числа и една операция **(+, -, *, /)**. Напишете примитивен калкулатор, който поддържа изброените операции върху реални числа.
*Вход: 7 9 +, Изход: 16
Вход: 10 3 /, Изход: 3.33333
Вход: 5 23 $, Изход: Invalid operation!*
*/

int main()
{
    char operator = '0';
    double a = 0.0, b = 0.0;
    scanf("%lf%lf %c", &a, &b, &operator);
    switch (operator)
    {
    case '+':
        printf("%g", a + b);
        break;
    case '-':
        printf("%g", a - b);
        break;
    case '*':
        printf("%g", a * b);
        break;
    case '/':
        printf("%g", a / b);
        break;
    default:
        printf("Invalid operation!");
        break;
    }
    return 0;
}