#include <stdio.h>
#include <limits.h>

#define SIZE 2000   // OK!
//      SIZE 20000  // works ONLY IN RELEASE BUILD
//      SIZE 200000 // DOESN'T work EVEN IN RELEASE BUILD

int maxElRec(const int* arr, size_t size)
{
	if (size == 0)
	{
		return INT_MIN;
	}
	int maxInRest = maxElRec(arr + 1, size - 1);
	return (*arr > maxInRest) ? *arr : maxInRest;
}

int main()
{
	int arr[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = i * 2;
	}

	printf("%d", maxElRec(arr, SIZE));
}
