#include <stdio.h>

void swap(int arr[], const int i, const int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubbleSort(int arr[], const size_t len)
{
	for (size_t i = 0; i < len - 1; i++)
	{
		int isSwapped = 0;
		for (size_t j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				isSwapped = 1;
			}
		}

		if (!isSwapped)
		{
			return;
		}
	}
}

int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	const int arrSize = sizeof(arr) / sizeof(int);
	
	bubbleSort(arr, arrSize);

	for (size_t i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
