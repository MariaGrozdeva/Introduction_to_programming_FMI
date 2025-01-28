#include <stdio.h>

#define ARR_SIZE 8

void swap(int* arr, const int i, const int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selectionSort(int* arr, const size_t len, int(*comp)(int x, int y))
{
	for (size_t i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for (size_t j = minIndex + 1; j < len; j++)
		{
			if (comp(arr[j], arr[minIndex]))
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			swap(arr, i, minIndex);
		}
	}
}

// every even number is before every odd one
int customComparator(int x, int y)
{
	return (x % 2 == 0) && (y % 2 == 1);
}

int main()
{
	int arr[ARR_SIZE] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	selectionSort(arr, ARR_SIZE, customComparator);

	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
