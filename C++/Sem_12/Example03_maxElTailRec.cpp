#include <iostream>
#include <algorithm>
using namespace std;

int maxElTailRec(const int* arr, size_t size, int maxEl)
{
	if (size == 0)
	{
		return maxEl;
	}
	return maxElTailRec(arr + 1, size - 1, max(*arr, maxEl));
}
int maxElTailRec(const int* arr, size_t size)
{
	return maxElTailRec(arr, size, INT_MIN);
}

int main()
{
	constexpr size_t SIZE = 2000;   // OK!
	//               SIZE = 20000;  // OK in RELEASE BUILD
	//               SIZE = 200000; // OK in RELEASE BUILD

	int arr[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = i * 2;
	}

	cout << maxElTailRec(arr, SIZE);
}
