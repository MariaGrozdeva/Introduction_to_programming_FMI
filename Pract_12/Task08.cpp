#include <iostream>

bool binarySearchRec(const int* arr, int size, int num, int lhs, int rhs)
{
	if (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (arr[mid] == num)
			return true;
		else if (arr[mid] > num)
			binarySearchRec(arr, size, num, lhs, mid - 1);
		else if (arr[mid] < num)
			binarySearchRec(arr, size, num, mid + 1, rhs);
	}
	else
		return false;
}

bool binarySearchWrapper(const int* arr, int size, int num)
{
	int lhs = 0;
	int rhs = size - 1;
	int mid = lhs + (rhs - lhs) / 2;
	return binarySearchRec(arr, size, num, lhs, rhs);
}

int main()
{
	int arr[] = { 2,5,7,10,15 };
	int len = sizeof(arr) / sizeof(int);
	std::cout << (binarySearchWrapper(arr, len, 5) ? "Yes" : "No");

	return 0;
}