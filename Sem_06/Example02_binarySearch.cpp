#include <iostream>
using namespace std;

int binarySearch(const int arr[], size_t len, int element)
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
	int arr[] = { -8, 5, 22, 23, 44, 100 };
	size_t size = sizeof(arr) / sizeof(int);

	int toFind = 50;
	cout << (binarySearch(arr, size, toFind) >= 0) ? true : false;
}