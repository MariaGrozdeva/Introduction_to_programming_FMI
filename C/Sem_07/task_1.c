#include <stdio.h>

int getUniqueEl(int arr[], unsigned size)
{
    int uniqueNum = 0;
    for (int i = 0; i < size; i++)
    {
        uniqueNum ^= arr[i];
    }

    return uniqueNum;
}

void readArray(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int main()
{
    const int size = 9;
    int arr[9] = {0};
    readArray(arr, size);
    printf("%d", getUniqueEl(arr, sizeof(arr) / sizeof(int)));
    return 0;
}