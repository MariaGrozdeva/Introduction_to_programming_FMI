#include <iostream>

void printArray(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

void convertInTriton(int arr[], int size)
{
	for (int i = 1; i < size - 1; i++)
	{
		if ((arr[i - 1] < arr[i] && (arr[i] < arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] > arr[i + 1])))
			std::swap(arr[i], arr[i + 1]);
	}

	printArray(arr, size);
}

int main()
{
	int arr[] = { 1,5,1,0,3 };
	int len = sizeof(arr) / sizeof(int);

	convertInTriton(arr, len);

	return 0;
}