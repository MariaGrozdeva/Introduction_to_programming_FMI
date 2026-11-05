#include <stdio.h>

void printArray(const int arr[], const size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], const int i, const int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// NB!! Works only for arrays with unique elements
void convertToTrion(int arr[], const size_t len)
{
    for (size_t i = 1; i < len - 1; i++)
    {
        if ((arr[i - 1] < arr[i] && arr[i] < arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] > arr[i + 1]))
        {
            swap(arr, i, i + 1);
        }
    }
    printArray(arr, len);
}

int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    size_t len = sizeof(arr) / sizeof(int);

    convertToTrion(arr, len);
    return 0;
}
