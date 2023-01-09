#include <iostream>
using namespace std;

int sumTailRec(const int* arr, size_t size, int sum)
{
	if (size == 0)
		return sum;

	return sumTailRec(arr + 1, size - 1, sum + *arr);
}
int sumTailRec(const int* arr, size_t size)
{
	return sumTailRec(arr, size, 0);
}

int main()
{
	const size_t SIZE = 2000;   // OK!
	//           SIZE = 20000;  // OK in RELEASE BUILD
	//           SIZE = 200000; // OK in RELEASE BUILD

	int arr[SIZE];
	for (size_t i = 0; i < SIZE; i++)
		arr[i] = 1;

	cout << sumTailRec(arr, SIZE);
}