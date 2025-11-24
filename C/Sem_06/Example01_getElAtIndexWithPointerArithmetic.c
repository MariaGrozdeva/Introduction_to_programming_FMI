#include <stdio.h>

int getElAtIndex(const int* arr, const size_t size, const unsigned index)
{
	if (index >= size)
	{
                printf("Index out of range");
                return -1;
        }
	return *(arr + index);
}

int main()
{
	int arr[] = { 0, 13, 22, 8, 24, 5 };
	size_t size = sizeof(arr) / sizeof(int);

	unsigned index = 3;
	printf("%d", getElAtIndex(arr, size, index));
}
