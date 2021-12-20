#include <iostream>

void readArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cin >> arr[i];
	std::cout << '\n';
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

void merge(int* arr1, int size1, int* arr2, int size2, int*& result) // Only for sorted arrays
{
	int arr1Iter = 0;
	int arr2Iter = 0;
	int resIter = 0;

	while (arr1Iter < size1 && arr2Iter < size2)
	{
		if (arr1[arr1Iter] < arr2[arr2Iter])
			result[resIter++] = arr1[arr1Iter++];
		else
			result[resIter++] = arr2[arr2Iter++];
	}

	if (arr1Iter == size1)
	{
		for (int i = arr2Iter; i < size2; i++)
			result[resIter++] = arr2[i];
	}
	else if (arr2Iter == size2)
	{
		for (int i = arr1Iter; i < size1; i++)
			result[resIter++] = arr1[i];
	}
	
}

int main()
{
	int n1;
	std::cout << "n1 = ";
	std::cin >> n1;
	int* arr1 = new int[n1];
	if (!arr1)
	{
		std::cerr << "Can't allocate memory!\n";
		return -1;
	}
	std::cout << "Input sorted array: ";
	readArray(arr1, n1); 

	int n2;
	std::cout << "n2 = ";
	std::cin >> n2;
	int* arr2 = new int[n2];
	if (!arr2)
	{
		std::cerr << "Can't allocate memory!\n";
		return -1;
	}
	std::cout << "Input sorted array: ";
	readArray(arr2, n2);

	int newSize = n1 + n2;
	int* newArr = new int[newSize];
	if (!newArr)
	{
		std::cerr << "Can't allocate memory!\n";
		return -1;
	}

	merge(arr1, n1, arr2, n2, newArr);
	printArray(newArr, newSize);

	delete[] arr1;
	delete[] arr2;
	delete[] newArr;

	return 0;
}