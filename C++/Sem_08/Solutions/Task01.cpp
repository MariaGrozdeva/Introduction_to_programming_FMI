#include <iostream>
using namespace std;

int getSingleElement(const int* arr, size_t size)
{
	int result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result ^= arr[i];
	}

	return result;
}

int main()
{
	int arr[] = { 9, 18, 9, -50, 12, 18, 15, 12, -50 };
	size_t size = sizeof(arr) / sizeof(int);

	cout << getSingleElement(arr, size);
}