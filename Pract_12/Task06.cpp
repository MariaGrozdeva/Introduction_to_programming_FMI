#include <iostream>

int minElem(const int* arr, int size, int min)
{
	if (size == 1)
		return min;

	int currElem = arr[size - 2];
	if (currElem < min)
		min = currElem;

	return minElem(arr, size - 1, min);
}

int minElemWrapper(const int* arr, int size)
{
	return minElem(arr, size, arr[size - 1]);
}

int main()
{
	int arr[] = { 3,-1,0,44,5 };
	int len = sizeof(arr) / sizeof(int);
	std::cout << minElemWrapper(arr, len);

	return 0;
}