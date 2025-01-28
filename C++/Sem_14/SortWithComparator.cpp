#include <iostream>

void swap(int* arr, const int i, const int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selectionSort(int* arr, const size_t len, bool(*comp)(int x, int y) = [](int x, int y) { return x < y; })
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

int main()
{
        constexpr size_t ARR_SIZE = 8;
	int arr[ARR_SIZE] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	selectionSort(arr, ARR_SIZE, [](int x, int y) { return x % 2 == 0 && y % 2 == 1; });

	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
}
