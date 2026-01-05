#include <stdio.h>
#include <limits.h>

#define SIZE 2000   // OK!
//      SIZE 20000  // OK in RELEASE BUILD
//      SIZE 200000 // OK in RELEASE BUILD

int maxElTailRec(const int* arr, size_t size, int maxEl)
{
	if (size == 0)
	{
		return maxEl;
	}
	return maxElTailRec(arr + 1, size - 1, (*arr > maxEl) ? *arr : maxEl);
}

int maxElTailRec(const int* arr, size_t size)
{
	return maxElTailRec(arr, size, INT_MIN);
}

int main()
{
	int arr[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = i * 2;
	}

	printf("%d", maxElTailRec(arr, SIZE));
}
