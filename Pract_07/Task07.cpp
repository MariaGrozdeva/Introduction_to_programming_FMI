#include <iostream>

const int SIZE = 5;

// Sum of the array from index do index
int sumOfArray(int arr[], int size, int startIdx, int endIdx) 
{
	int sum = 0;

	if (startIdx >= size || endIdx >= size)
	{
		std::cerr << "Wrong arguments!\n";
		return -1;
	}

	for (size_t i = startIdx; i <= endIdx; i++)
		sum += arr[i];

	return sum;
}

// We accept that one element of the array is also subarray
void findSubArray(int arr[], int size, int k)
{
	int startIdx = 0;
	int endIdx = 0;
	int idx = 0;
	bool hasFound = false;
	while (idx < size)
	{
		int sum = 0;
		startIdx = 0;
		endIdx = 0;

		for (int i = idx; i < size; i++)
		{
			sum = sumOfArray(arr, size, idx, i);
			if (sum == k)
			{
				startIdx = idx;
				endIdx = i;
				hasFound = true;
				break;
			}
		}

		if (hasFound)
			break;

		idx++;
	}


	if (hasFound)
		std::cout << "Yes!\n" << "Indexes: " << startIdx << ", " << endIdx;
	else
		std::cout << "No sum found in any subarray!\n";
}

int main()
{
	int arr[SIZE];
	std::cout << "Input array: ";
	for (int i = 0; i < SIZE; i++)
		std::cin >> arr[i];

	int k;
	std::cout << "Input k: ";
	std::cin >> k;

	findSubArray(arr, SIZE, k);

	return 0;
}