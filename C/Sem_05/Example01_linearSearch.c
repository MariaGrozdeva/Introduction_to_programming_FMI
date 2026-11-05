#include <stdio.h>

int linearSearch(const int arr[], const size_t len, const int element)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    const int arrSize = sizeof(arr) / sizeof(int);

    printf("%d", linearSearch(arr, arrSize, 2) >= 0);
    return 0;
}
