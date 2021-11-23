#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void input(int& n)
{	
	cout << "Input number: ";
	cin >> n;
	
	while (n < 0 || n > MAX_SIZE)
	{
		cout << "Invalid input! Try again: ";
		cin >> n;
	}
}

void eratosthenes(bool arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = true;

	for (int i = 2; i * i < size; i++)
	{
		if (arr[i])
		{
			for (int j = i + i; j < size; j += i)
				arr[j] = false;
		}
	}

	for (int i = 2; i <= size; i++)
	{
		if (arr[i])
			cout << i << ' ';
	}
	cout << endl;
}

int main()
{
	int n;
	input(n);

	bool arr[MAX_SIZE];
	eratosthenes(arr, n);

	return 0;
}
