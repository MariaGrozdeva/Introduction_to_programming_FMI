#include <stdio.h>
#include <stdlib.h>

void insertAt(int** arr, size_t* size, unsigned int index, int element)
{
    if (index > *size)
    {
        return; // error
    }

    ++(*size);
    *arr = (int*)realloc(*arr, *size * sizeof(int));
    
    if (!arr)
    {
        perror("Failed to reallocate memory");
        return;
    }

    for (int i = *size - 1; i > index; i--)
    {
        (*arr)[i] = (*arr)[i - 1];
    }
    
    (*arr)[index] = element;
}

int main()
{
    size_t n = 0;
    printf("Enter array size:\n");
    scanf("%zu", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr)
    {
        perror("Failed to allocate memory");
        return 1;
    }

    printf("Enter array:\n");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    unsigned int index = 0;
    int element = 0;
    printf("Enter an index and an element:\n");
    scanf("%u %d", &index, &element);

    insertAt(&arr, &n, index, element);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
