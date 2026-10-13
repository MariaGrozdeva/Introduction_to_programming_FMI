#include <stdio.h>

int main()
{
    int x, y, radius;
    scanf("%d %d %d", &x, &y, &radius);

    if (x * x + y * y < radius * radius)
    {
        printf("In the circle\n");
    }
    else if (x * x + y * y == radius * radius)
    {
        printf("On the circle\n");
    }
    else
    {
        printf("Out of the circle\n");
    }

    return 0;
}
