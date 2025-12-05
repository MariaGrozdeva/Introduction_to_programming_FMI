#include <stdio.h>
#include <limits.h>

int isNumberContained(int n, int k)
{
    unsigned short size = sizeof(int) * CHAR_BIT;

    for (int i = 0; i < size; i++)
    {
        if (k == ((n >> i) & k))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    isNumberContained(n, k) ? puts("true") : puts("false");
    return 0;
}