#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printArr(const int arr[], const size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void reverseArr(int arr[], const size_t len)
{
	for (size_t i = 0; i < len / 2; i++)
	{
		swap(arr[i], arr[len - i - 1]);
	}
}

int main()
{
	constexpr size_t ARR_SIZE = 5;
	int arr[ARR_SIZE] = { 1, 2, 3, 4, 5 };

	printArr(arr, ARR_SIZE);
	reverseArr(arr, ARR_SIZE);
	printArr(arr, ARR_SIZE);
}
