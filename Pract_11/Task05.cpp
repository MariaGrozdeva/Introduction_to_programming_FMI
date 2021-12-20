#include <iostream>

bool isPrime(int num)
{
	if (num < 2)
		return false;

	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;

	return true;
}

void readArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cin >> arr[i];
	std::cout << '\n';
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

int nonPrimeNumbersInArray(int* arr, int size)
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
		std::cerr << "Can't allocate memory!\n";
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
	std::cout << "n = ";
	std::cin >> n;
	int* arr = new int[n];
	readArr(arr, n);
	filter(arr, n);
	printArr(arr, n);
	delete[] arr;

	return 0;
}