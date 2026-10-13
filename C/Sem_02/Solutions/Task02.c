#include <stdio.h>

int main()
{
    int hours, mins;
    scanf("%d %d", &hours, &mins);

    mins = (mins + 15) % 60;

    if (mins < 15)
    {
        hours = (hours + 1) % 24;
    }

    if (hours <= 9)
    {
        printf("0");
    }
    printf("%d:", hours);

    if (mins <= 9)
    {
        printf("0");
    }
    printf("%d\n", mins);

    return 0;
}
