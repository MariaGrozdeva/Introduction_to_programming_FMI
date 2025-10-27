#include <stdio.h>

int main()
{
    double a, b;
    char op;

    scanf("%lf %lf %c", &a, &b, &op);

    switch (op)
    {
        case '+': printf("%.2lf\n", a + b); break;
        case '-': printf("%.2lf\n", a - b); break;
        case '*': printf("%.2lf\n", a * b); break;
        case '/': 
            if (b != 0)
            {
                printf("%.2lf\n", a / b);
            }
            else
            {
                printf("Division by zero is not allowed!\n");
            }
            break;
        default: printf("Invalid operation!\n"); break;
    }

    return 0;
}
