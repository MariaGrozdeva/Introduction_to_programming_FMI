#include <iostream>
using namespace std;

int binarySearch(const int arr[], const size_t len, const int element)
{
	int low = 0;
	int high = len - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == element)
		{
			return mid;
		}

		if (arr[mid] > element)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	constexpr size_t ARR_SIZE = 6;
	int arr[ARR_SIZE] = { -8, 5, 22, 23, 44, 100 };

	int toFind = 50;
	cout << (binarySearch(arr, ARR_SIZE, toFind) >= 0);
}
