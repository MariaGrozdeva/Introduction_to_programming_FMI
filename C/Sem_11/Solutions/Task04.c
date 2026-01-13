#include <stdio.h>

int linearSearch(const int* arr, const size_t size, const int searched)
{
	if (size == 0)
	{
		return 0;
	}
	if (*arr == searched)
	{
	    return 1;
	}
	return linearSearch(arr + 1, size - 1, searched);
}

int main()
{
	int arr[] = {1, 5, -10, -11, 0};
	printf("%d", linearSearch(arr, 5, 0));
}
