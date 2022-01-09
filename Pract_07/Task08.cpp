#include <iostream>
using namespace std;

bool containsNumber(const int arr[], int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			return true;
	}
	return false;
}

bool areSequencesOfSameSet(const int arr1[], int size1, const int arr2[], int size2)
{
	for (int i = 0; i < size1; i++)
	{
		if (!containsNumber(arr2, size2, arr1[i]))
			return false;
	}

	for (int i = 0; i < size2; i++)
	{
		if (!containsNumber(arr1, size1, arr2[i]))
			return false;
	}
	
	return true;
}

int main()
{
	int arr1[] = { 1, 3, 4, 1, 3 };
	int len1 = sizeof(arr1) / sizeof(int);

	int arr2[] = { 1, 3, 3, 4, 1, 0, 3 };
	int len2 = sizeof(arr2) / sizeof(int);

	cout << areSequencesOfSameSet(arr1, len1, arr2, len2) ? "Yes" : "No";

	return 0;
}
