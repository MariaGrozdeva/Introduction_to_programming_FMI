#include <iostream>
#include <new>
using namespace std;

void readArray(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << endl;
}
void printArray(const int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void merge(const int* arr1, size_t size1, const int* arr2, size_t size2, int*& result) // Only for sorted arrays !!!
{
	unsigned int arr1Iter = 0;
	unsigned int arr2Iter = 0;
	unsigned int resIter = 0;

	while (arr1Iter < size1 && arr2Iter < size2)
	{
		if (arr1[arr1Iter] < arr2[arr2Iter])
		{
			result[resIter++] = arr1[arr1Iter++];
		}
		else
		{
			result[resIter++] = arr2[arr2Iter++];
		}
	}

	for (size_t i = arr1Iter; i < size1; i++)
	{
		result[resIter++] = arr1[i];
	}
	for (size_t i = arr2Iter; i < size2; i++)
	{
		result[resIter++] = arr2[i];
	}
}

int main()
{
	cout << "Input first array size:" << endl;
	size_t n1;
	cin >> n1;
	int* arr1 = new (nothrow) int[n1];

	cout << "Input sorted array:" << endl;
	readArray(arr1, n1);

	cout << "Input second array size" << endl;
	size_t n2;
	cin >> n2;
	int* arr2 = new (nothrow) int[n2];

	cout << "Input sorted array:" << endl;
	readArray(arr2, n2);

	size_t newSize = n1 + n2;
	int* newArr = new (nothrow) int[newSize];

	merge(arr1, n1, arr2, n2, newArr);
	printArray(newArr, newSize);

	delete[] arr1;
	delete[] arr2;
	delete[] newArr;
}
