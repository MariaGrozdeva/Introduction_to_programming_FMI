#include <stdio.h>

void printSubsets(int arr[], unsigned size);
void readArray(int arr[], unsigned size);

int main()
{
    const int size = 3;
    int arr[3] = {0};
    readArray(arr, size);
    printSubsets(arr, size);

    return 0;
}

void printSubsets(int arr[], unsigned size)
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
void readArray(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}