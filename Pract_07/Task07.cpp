#include <iostream>
using namespace std;

const int SIZE = 5;

int sumOfArray(const int arr[], int size, int startIdx, int endIdx) 
{
	int sum = 0;

	for (size_t i = startIdx; i <= endIdx; i++)
		sum += arr[i];

	return sum;
}

void findSubArray(const int arr[], int size, int k)
{	
	int startIdx = 0;
	int currentStartIdx = 0;
	int endIdx = 0;
	
	bool hasFound = false;
	
	while (currentStartIdx < size)
	{
		startIdx = 0;
		endIdx = 0;
		
		int sum = 0;

		for (size_t i = currentStartIdx; i < size; i++)
		{
			sum = sumOfArray(arr, size, currentStartIdx, i);
			if (sum == k)
			{
				startIdx = currentStartIdx;
				endIdx = i;
				hasFound = true;
				break;
			}
		}

		if (hasFound)
			break;

		currentStartIdx++;
	}


	if (hasFound)
		cout << "Yes!" << endl << "Indices: " << startIdx << ", " << endIdx;
	else
		cout << "No sum k found in any subarray" << endl;
}

int main()
{
	int arr[SIZE];
	cout << "Input array: ";
	for (size_t i = 0; i < SIZE; i++)
		cin >> arr[i];

	int k;
	cout << "Input k: ";
	cin >> k;

	findSubArray(arr, SIZE, k);

	return 0;
}
