#include <iostream>
using namespace std;

void printTriangle(const int* arr, int len)
{
	if (len == 0)
		return;

	int* temp = new int[len - 1];

	for (size_t i = 0; i < len - 1; i++)
	{
		int x = arr[i] + arr[i + 1];
		temp[i] = x;
	}

	printTriangle(temp, len - 1);

	for (size_t i = 0; i < len; i++)
	{
		if (i == len - 1)
			cout << arr[i] << ' ';
		else
			cout << arr[i] << ", ";
	}

	cout << endl;
	delete[] temp;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int len = sizeof(arr) / sizeof(int);

	printTriangle(arr, len);
}