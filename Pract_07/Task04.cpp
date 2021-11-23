#include <iostream>
using namespace std;

void printArray(const int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
 	b = temp;
}

void convertToTrion(int arr[], int size)
{
	for (int i = 1; i < size - 1; i++)
	{
		if ((arr[i - 1] < arr[i] && arr[i] < arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] > arr[i + 1]))
			swap(arr[i], arr[i + 1]);
	}

	printArray(arr, size);
}

int main()
{
	int arr[] = { 1,5,1,0,3 };
	int len = sizeof(arr) / sizeof(int);

	convertToTrion(arr, len);

	return 0;
}
