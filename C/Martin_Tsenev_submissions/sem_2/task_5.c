#include <stdio.h>

/*
Да се напише програма, която при подадени радиус r и двумерна точка (х, у) проверява дали точката се намира вътре/извън или по контура на окръжност с център (0,0).
*Вход: 5 0 5, Изход: On the circle
Вход: 5 10 30, Изход: Out of the circle
Вход: 5 0 2, Изход: In the circle*
*/
int main()
{
    int r = 0, x = 0, y = 0;
    scanf("%d%d%d", &r, &x, &y);
    int pointDistanceFromCenterSquared = x * x + y * y;
    int rSquared = r * r;
    if (pointDistanceFromCenterSquared == rSquared)
    {
        printf("On the cirlce");
    }
    else if (pointDistanceFromCenterSquared < rSquared)
    {
        printf("In the cirlce");
    }
    else
    {
        printf("Out of the cirlce");
    }
    return 0;
}