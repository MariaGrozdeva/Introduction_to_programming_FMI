#include <iostream>
using namespace std;

void removeAt(int*& arr, size_t& size, unsigned int index)
{
	if (index >= size)
	{
		return; // error
	}

	size_t newSize = --size;
	int* temp = new int[newSize];

	for (size_t i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	for (size_t i = index; i < newSize; i++)
	{
		temp[i] = arr[i + 1];
	}

	delete[] arr;
	arr = temp;
}

int main()
{
	size_t n;
	cout << "Enter array size:" << endl;
	cin >> n;

	int* arr = new int[n];
	cout << "Enter array:" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	unsigned int index;
	cout << "Enter an index:" << endl;
	cin >> index;

	removeAt(arr, n, index);

	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	delete[] arr; // !!!!!
}
