#include <iostream>
using namespace std;

void readArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	cout << endl;
}
void printArr(const int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

bool isPrime(int num)
{
	if (num == 2)
		return true;
	if (num < 2 || num % 2 == 0)
		return false;

	for (int i = 3; i * i <= num; i += 2)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

int nonPrimeNumbersInArray(const int* arr, int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
		if (!isPrime(arr[i]))
			cnt++;
	
	return cnt;
}

void filter(int*& arr, int& size)
{
	int nonPrimes = nonPrimeNumbersInArray(arr, size);

	int newSize = size - nonPrimes;
	int* buffer = new int[newSize];
	
	if (!buffer)
	{
		cerr << "Can't allocate memory!" << endl;
		return;
	}

	for (int i = 0, idx = 0; i < size && idx < newSize; i++)
	{
		if (isPrime(arr[i]))
			buffer[idx++] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	size = newSize;
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	
	int* arr = new int[n];
	readArr(arr, n);
	filter(arr, n);
	printArr(arr, n);
	
	delete[] arr;
}
