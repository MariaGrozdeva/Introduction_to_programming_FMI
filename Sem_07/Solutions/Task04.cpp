#include <iostream>
using namespace std;

void printArray(const int arr[], const size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void convertToTrion(int arr[], const size_t len)
{
	for (size_t i = 1; i < len - 1; i++)
	{
		if ((arr[i - 1] < arr[i] && arr[i] < arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] > arr[i + 1]))
		{
			swap(arr[i], arr[i + 1]);
		}
	}
	printArray(arr, len);
}

int main()
{
	int arr[] = { 1, 5, 1, 0, 3 };
	size_t len = sizeof(arr) / sizeof(int);

	convertToTrion(arr, len);
}
