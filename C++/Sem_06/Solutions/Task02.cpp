#include <iostream>
using namespace std;

int binarySearch(const int arr[], const size_t len, const int el)
{
	int low = 0;
	int high = len - 1;

	while (low < high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == el)
		{
			return mid;
		}
		
		if (arr[mid] > el)
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
	int toFind = -8;

	cout << binarySearch(arr, size, toFind);
}
