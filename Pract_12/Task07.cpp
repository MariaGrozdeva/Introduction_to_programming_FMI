#include <iostream>

bool containsNumber(const int* arr, int size, int num)
{
	if (size == 0)
		return false;

	int currElem = arr[size - 1];
	if (currElem == num)
		return true;

	containsNumber(arr, size - 1, num);
}

int main()
{
	int arr[] = { 3,4,5,-2,0,8,9 };
	int len = sizeof(arr) / sizeof(int);
	std::cout << (containsNumber(arr, len, 5) ? "Yes" : "No");

	return 0;
}