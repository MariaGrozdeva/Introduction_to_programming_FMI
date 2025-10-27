#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    if ((a <= b && b >= c && c <= d && d >= e)
        || (a >= b && b <= c && c >= d && d <= e))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
