#include <stdio.h>

void swap(int arr[], const int firstInd, const int secInd)
{
	int temp = arr[firstInd];
	arr[firstInd] = arr[secInd];
	arr[secInd] = temp;
}

void printArr(const int arr[], const size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		 printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverseArr(int arr[], const size_t len)
{
	for (size_t i = 0; i < len / 2; i++)
	{
		swap(arr, i, len - i - 1);
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	const int arrSize = sizeof(arr) / sizeof(int);

	printArr(arr, arrSize);
	reverseArr(arr, arrSize);
	printArr(arr, arrSize);
	
	return 0;
}
