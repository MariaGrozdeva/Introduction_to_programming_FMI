#include <iostream>
using namespace std;

int linearSearch(const int arr[], const size_t len, const int toFind)
{
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] == toFind)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 17, 23, 5, -14, 0 };
	size_t size = sizeof(arr) / sizeof(int);
	int toFind = -14;

	cout << linearSearch(arr, size, toFind);
}
