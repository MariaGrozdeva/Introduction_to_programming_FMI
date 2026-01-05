#include <stdio.h>

#define SIZE 2000   // OK!
//      SIZE 20000  // works ONLY IN RELEASE BUILD
//      SIZE 200000 // DOESN'T work EVEN IN RELEASE BUILD

int sumRec(const int* arr, size_t size)
{
	if (size == 0)
	{
		return 0;
	}
	return *arr + sumRec(arr + 1, size - 1);
}

int main()
{
	int arr[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = 1;
	}

	printf("%d", sumRec(arr, SIZE));
}
