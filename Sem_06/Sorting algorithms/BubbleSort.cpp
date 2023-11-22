#include <iostream>
using namespace std;

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
		bool isSwapped = false;
		for (size_t j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				isSwapped = true;
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
        constexpr size_t ARR_SIZE = 8;
	int arr[ARR_SIZE] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	bubbleSort(arr, ARR_SIZE);

	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << arr[i] << " ";
	}
}
