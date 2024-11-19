#include <stdio.h>

int containsNumber(const int arr[], const size_t len, const int num)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

int areSequencesOfSameSet(const int arr1[], const size_t len1, const int arr2[], const size_t len2)
{
    for (size_t i = 0; i < len1; i++)
    {
        if (!containsNumber(arr2, len2, arr1[i]))
        {
            return 0;
        }
    }

    for (size_t i = 0; i < len2; i++)
    {
        if (!containsNumber(arr1, len1, arr2[i]))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int arr1[] = { 1, 3, 4, 1, 3 };
    size_t len1 = sizeof(arr1) / sizeof(int);

    int arr2[] = { 1, 3, 3, 4, 1, 0, 3 };
    size_t len2 = sizeof(arr2) / sizeof(int);

    printf("%s", areSequencesOfSameSet(arr1, len1, arr2, len2) ? "Yes" : "No");
    return 0;
}
