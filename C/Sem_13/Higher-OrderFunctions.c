#include <stdio.h>
#include <limits.h>

#define SIZE 4

int applyOnArray(const int* arr, const size_t size, int initValue, int(*func)(int, int))
{
	if (size == 0)
	{
		return initValue;
	}

	return applyOnArray(arr + 1, size - 1, func(*arr, initValue), func);
}

int sumFunc(int x, int y)
{
	return x + y;
}

int productFunc(int x, int y)
{
	return x * y;
}

int maxFunc(int x, int y)
{
	return x > y ? x : y;
}

int sumInArray(const int* arr, const size_t size)
{
	return applyOnArray(arr, size, 0, sumFunc);
}

int productInArray(const int* arr, const size_t size)
{
	return applyOnArray(arr, size, 1, productFunc);
}

int maxElInArray(const int* arr, const size_t size)
{
	return applyOnArray(arr, size, INT_MIN, maxFunc);
}

int main()
{
	int arr[SIZE] = { 1, 2, 3, 4 };

	printf("Sum: %d\nProduct: %d\nMax: %d\n", sumInArray(arr, SIZE), productInArray(arr, SIZE), maxElInArray(arr, SIZE));
	return 0;
}
