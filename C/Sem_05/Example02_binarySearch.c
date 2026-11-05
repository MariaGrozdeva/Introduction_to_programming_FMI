#include <stdio.h>

int binarySearch(const int arr[], const size_t len, const int element)
{
    int low = 0;
    int high = len - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = { -8, 5, 22, 23, 44, 100 };
    const int arrSize = sizeof(arr) / sizeof(int);

    int toFind = 50;
    printf("%d", binarySearch(arr, arrSize, toFind) >= 0);
    
    return 0;
}
