#include <limits.h>
#include <stdio.h>

int minElementHelper(const int *arr, size_t size, int minEl)
{
    if (size == 0)
    {
        return minEl;
    }
    return minElementHelper(arr + 1, size - 1, (*arr < minEl) ? *arr : minEl);
}

int minElement(const int *arr, size_t size)
{
    return minElementHelper(arr, size, INT_MAX);
}

int main()
{
    int arr[] = { 1, 5, -10, -11, 0 };
    printf("%d", minElement(arr, 5));
    return 0;
}
