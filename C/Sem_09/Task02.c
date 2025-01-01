#include <stdio.h>
#include <stdlib.h>

void removeAt(int** arr, size_t* size, unsigned int index)
{
    if (index >= *size)
    {
        return; // error
    }
    
     for (size_t i = index; i < *size; i++)
    {
        (*arr)[i] = (*arr)[i + 1];
    }
    
    --(*size);
    *arr = (int*)realloc(*arr, *size * sizeof(int));
    
    if (!arr)
    {
        perror("Failed to reallocate memory");
        return;
    }

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
    printf("Enter an index:\n");
    scanf("%u", &index);

    removeAt(&arr, &n, index);

    printf("Array after removal:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
