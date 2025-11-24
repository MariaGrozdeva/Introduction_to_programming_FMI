#include <iostream>
using namespace std;

int linearSearch(const int* arr, const size_t size, const int element)
{
	for (size_t i = 0; i < size; i++)
	{
		if (*arr == element)
		{
			return i;
		}
		arr++;
	}
	return -1;
}

int main()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	size_t size = sizeof(arr) / sizeof(int);

	cout << (linearSearch(arr, size, 2) >= 0);
}
