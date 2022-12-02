#include <iostream>
using namespace std;

int getElAtIndex(const int* arr, size_t size, unsigned short index)
{
	return *(arr + index);
}

int main()
{
	int arr[] = { 0, 13, 22, 8, 24, 5 };
	size_t size = sizeof(arr) / sizeof(int);

	unsigned short index = 3;
	cout << getElAtIndex(arr, size, index);
}