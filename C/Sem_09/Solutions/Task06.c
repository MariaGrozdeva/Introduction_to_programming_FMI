#include <stdio.h>
#include <stdlib.h>

void readArray(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void printArray(const int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(const int* arr1, size_t size1, const int* arr2, size_t size2, int* result) // Only for sorted arrays !!!
{
    unsigned int arr1Iter = 0;
    unsigned int arr2Iter = 0;
    unsigned int resIter = 0;

    while (arr1Iter < size1 && arr2Iter < size2)
    {
        if (arr1[arr1Iter] < arr2[arr2Iter])
        {
            result[resIter++] = arr1[arr1Iter++];
        }
        else
        {
            result[resIter++] = arr2[arr2Iter++];
        }
    }

    for (size_t i = arr1Iter; i < size1; i++)
    {
        result[resIter++] = arr1[i];
    }
    for (size_t i = arr2Iter; i < size2; i++)
    {
        result[resIter++] = arr2[i];
    }
}

int main()
{
    printf("Input first array size:\n");
    size_t n1;
    scanf("%zu", &n1);
    int* arr1 = (int*)malloc(n1 * sizeof(int));
    if (!arr1)
    {
        perror("Failed to allocate memory");
        return 1;
    }

    printf("Input sorted array:\n");
    readArray(arr1, n1);

    printf("Input second array size:\n");
    size_t n2;
    scanf("%zu", &n2);
    int* arr2 = (int*)malloc(n2 * sizeof(int));
    if (!arr2)
    {
        perror("Failed to allocate memory");
        free(arr1);
        return 1;
    }

    printf("Input sorted array:\n");
    readArray(arr2, n2);

    size_t newSize = n1 + n2;
    int* newArr = (int*)malloc(newSize * sizeof(int));
    if (!newArr)
    {
        perror("Failed to allocate memory");
        free(arr1);
        free(arr2);
        return 1;
    }

    merge(arr1, n1, arr2, n2, newArr);
    printf("Merged array:\n");
    printArray(newArr, newSize);

    free(arr1);
    free(arr2);
    free(newArr);

    return 0;
}
