#include <iostream>
using namespace std;

int findMissingElementInSortedArray(const int arr[], const size_t len)
{
    int low = 0, high = len - 1;   
    int diff = arr[0];

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + diff)
	{
            low = mid + 1;
	}
        else
	{
            high = mid - 1;
	}
    }

    if (arr[low] == low + diff)
    {
        return arr[low] + 1;
    }
    else
    {
	return arr[low] - 1;
    }
}

int main()
{
	int arr[] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20 };
	size_t len = sizeof(arr) / sizeof(int);
	
	cout << findMissingElementInSortedArray(arr, len);
}
