#include <stdio.h>

void swap(int arr[], const int i, const int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selectionSort(int arr[], const size_t len)
{
	for (size_t i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for (size_t j = minIndex + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
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

int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	const int arrSize = sizeof(arr) / sizeof(int);
	
	selectionSort(arr, arrSize);

	for (size_t i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
