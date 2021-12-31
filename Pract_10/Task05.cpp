#include <iostream>
using namespace std;

bool isEven(int number)
{
	return number % 2 == 0;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void print(const int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
}

void swapElementsOfEvenPositions(int* arr, int size)
{
	int end = isEven(size) ? size - 1 : size;

	for (int i = 0; i < end / 2; i++)
	{
		if (i % 2 == 0)
			Swap(*(arr + i), *(arr + end - 1 - i));
	}
}

int main()
{ 
	const int maxSize = 100;
	int arr[maxSize];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	swapElementsOfEvenPositions(arr, n);
	print(arr, n);
}