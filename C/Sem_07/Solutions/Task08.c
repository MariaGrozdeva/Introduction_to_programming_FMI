#include <stdio.h>
#define CAP 3

void printSubsets(const int *arr, const size_t size)
{
    int total = 1 << size;
    printf("[], ");
    for (int mask = 1; mask < total; mask++)
    {
        int first = 1;
        printf("[");
        for (int i = 0; i < size; i++)
        {
            if ((mask >> i) & 1)
            {
                if (!first)
                    printf(",");
                printf("%d", arr[i]);
                first = 0;
            }
        }
        printf("], ");
    }
}

void readArray(int *arr, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int arr[CAP] = {0};
    const size_t size = sizeof(arr) / sizeof(int);
    readArray(arr, size);
    printSubsets(arr, size);

    return 0;
}

