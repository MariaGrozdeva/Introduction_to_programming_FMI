#include <iostream>

int sumOfArray(const int* arr, int len)
{
	if (len == 0)
		return 0;

	return *arr + sumOfArray(arr + 1, len - 1);
}

int main()
{
	int arr[] = { 2,3,4,5,6 };
	int len = sizeof(arr) / sizeof(int);
	std::cout << sumOfArray(arr, len);

	return 0;
}