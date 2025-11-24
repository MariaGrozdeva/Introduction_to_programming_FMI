#include <stdio.h>

void swap(int arr[], const int i, const int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void insertionSortNaive(int arr[], const size_t len)
{
	for (size_t i = 1; i < len; i++)
	{
		int index = i - 1;

		while (index >= 0 && arr[index] > arr[index + 1])
		{
			swap(arr, index, index + 1);
			index--;
		}
	}
}

void insertionSort(int arr[], const size_t len)
{
	for (size_t i = 1; i < len; i++)
	{
		int element = arr[i];
		int index = i - 1;

		while (index >= 0 && arr[index] > element)
		{
			arr[index + 1] = arr[index];
			index--;
		}

		arr[index + 1] = element;
	}
}

int main()
{
	int arr[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
	const int arrSize = sizeof(arr) / sizeof(int);
	
	insertionSort(arr, arrSize);

	for (size_t i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
