#include <iostream>

int binarySearch(const int *arr, const int left, const int right, const int searched)
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
        return binarySearch(arr, mid + 1, right, searched);
    }
    else
    {
        return binarySearch(arr, left, mid - 1, searched);
    }
}

int binarySearch(const int *arr, const int size, const int searched)
{
    return binarySearch(arr, 0, size, searched);
}

int main()
{
    int arr[] = { 0, 1, 5, 10, 11 };
    std::cout << binarySearch(arr, 5, 0);
    return 0;
}
