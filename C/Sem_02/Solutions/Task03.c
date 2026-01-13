#include <stdio.h>

const double PI = 3.14;

int main()
{
    char figure;
    scanf(" %c", &figure);

    if (figure == 's')
    {
        double side;
        scanf("%lf", &side);

        printf("%.2lf\n", side * side);
    }
    else if (figure == 'r')
    {
        double sideA, sideB;
        scanf("%lf %lf", &sideA, &sideB);

        printf("%.2lf\n", sideA * sideB);
    }
    else if (figure == 'c')
    {
        double R;
        scanf("%lf", &R);

        printf("%.2lf\n", PI * R * R);
    }
    else if (figure == 't')
    {
        double width, height;
        scanf("%lf %lf", &width, &height);

        printf("%.2lf\n", (width * height) / 2);
    }
    else
    {
        printf("Invalid figure!\n");
    }

    return 0;
}
