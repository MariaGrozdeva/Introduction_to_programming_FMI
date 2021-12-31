#include <iostream>
using namespace std;

void insertAt(int*& arr, size_t& size, size_t index, int element)
{
	size_t newSize = ++size;
	int* temp = new int[newSize];

	for (size_t i = 0; i < index; i++)
		temp[i] = arr[i];

	temp[index] = element;

	for (size_t i = index + 1; i < newSize; i++)
		temp[i] = arr[i - 1];

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
		cin >> arr[i];

	size_t index;
	int element;
	cout << "Enter an index and an element:" << endl;
	cin >> index >> element;

	insertAt(arr, n, index, element);

	for (size_t i = 0; i < n; i++)
		cout << arr[i] << ' ';

	delete[] arr;
}