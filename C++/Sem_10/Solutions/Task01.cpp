#include <iostream>
using namespace std;

void insertAt(int*& arr, size_t& size, unsigned int index, int element)
{
	if (index > size)
	{
		return; // error
	}

	size_t newSize = ++size;
	int* temp = new int[newSize];

	for (size_t i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}

	temp[index] = element;

	for (size_t i = index; i < newSize - 1; i++)
	{
		temp[i + 1] = arr[i];
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
	int element;
	cout << "Enter an index and an element:" << endl;
	cin >> index >> element;

	insertAt(arr, n, index, element);

	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	delete[] arr; // !!!!!
}
