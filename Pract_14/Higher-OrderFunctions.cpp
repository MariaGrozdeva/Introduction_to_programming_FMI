#include <iostream>
using namespace std;

int applyOpOnArray(const int* arr, size_t size, int result, int(*func)(int, int))
{
	if (size == 0)
		return result;

	return applyOpOnArray(arr + 1, size - 1, func(*arr, result), func);
}

int sum(int x, int y)
{
	return x + y;
}
int sumTailRec(const int* arr, size_t size)
{
	return applyOpOnArray(arr, size, 0, sum);
}

int max(int x, int y)
{
	return x > y ? x : y;
}
int maxElTailRec(const int* arr, size_t size)
{
	return applyOpOnArray(arr, size, INT_MIN, max);
}

int main()
{
	const size_t SIZE = 4;
	int arr[SIZE] = { 1,2,3,4 };

	cout << "Sum: " << sumTailRec(arr, SIZE) << endl << "Max: " << maxElTailRec(arr, SIZE);
}