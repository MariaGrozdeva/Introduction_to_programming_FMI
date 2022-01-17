#include <iostream>
#include <algorithm>
using namespace std;

int maxElRec(const int* arr, size_t size)
{
	if (size == 0)
		return INT_MIN;

	return max(*arr, maxElRec(arr + 1, size - 1));
}

int main()
{
	const size_t SIZE = 2000;   // OK!
	//           SIZE = 20000;  // works ONLY IN RELEASE BUILD
	//           SIZE = 200000; // DOESN'T work EVEN IN RELEASE BUILD

	int arr[SIZE];
	for (size_t i = 0; i < SIZE; i++)
		arr[i] = i*2;

	cout << maxElRec(arr, SIZE);
}