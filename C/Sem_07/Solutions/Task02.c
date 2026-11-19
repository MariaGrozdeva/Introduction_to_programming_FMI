#include <stdio.h>

void findTwoUnique(const int *arr, const int n, int *first, int *second)
{
    unsigned x = 0;
    for (int i = 0; i < n; ++i)
    {
        x ^= (unsigned)arr[i];
    }

    // най-десният бит 1: тук a и b се различават
    unsigned diff = x & -x;

    unsigned a = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((unsigned)arr[i] & diff)
        {
            a ^= (unsigned)arr[i]; // двойките в групата се унищожават
        }
    }

    *first = (int)a;
    *second = (int)(x ^ a);
}

int main()
{
    int arr[] = {9, 18, 9, -50, 12, 18, 15, 12, -50, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a, b;

    findTwoUnique(arr, n, &a, &b);
    printf("%d %d\n", a, b);

    return 0;
}
