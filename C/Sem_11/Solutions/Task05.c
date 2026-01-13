#include <stdio.h>

int binarySearchHelper(const int *arr, const int left, const int right, const int searched)
{
    if (left > right)
    {
        return 0;
    }

    int mid = left + (right - left) / 2;
    if (arr[mid] == searched)
    {
        return 1;
    }
    if (arr[mid] < searched)
    {
        return binarySearchHelper(arr, mid + 1, right, searched);
    }
    else
    {
        return binarySearchHelper(arr, left, mid - 1, searched);
    }
}

int binarySearch(const int *arr, const int size, const int searched)
{
    return binarySearchHelper(arr, 0, size, searched);
}

int main()
{
    int arr[] = { 0, 1, 5, 10, 11 };
    printf("%d", binarySearch(arr, 5, 0));
    return 0;
}

