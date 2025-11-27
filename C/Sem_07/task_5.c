#include <stdio.h>

void isNumberContained(int n, int k)
{
    if (k == (n & k))
    {
        puts("true");
    }
    else
    {
        puts("false");
    }
}

int main()
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    isNumberContained(n, k);
    return 0;
}