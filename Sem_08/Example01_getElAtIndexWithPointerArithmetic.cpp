#include <iostream>
#include <cassert>
using namespace std;

int getElAtIndex(const int* arr, const size_t size, const unsigned short index)
{
	assert(index < size);
	return *(arr + index);
}

int main()
{
	int arr[] = { 0, 13, 22, 8, 24, 5 };
	size_t size = sizeof(arr) / sizeof(int);

	unsigned short index = 3;
	cout << getElAtIndex(arr, size, index);
}
