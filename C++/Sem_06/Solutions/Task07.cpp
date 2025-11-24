#include <iostream>
using namespace std;

bool containsNumber(const int arr[], const size_t len, const int num)
{
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] == num)
		{
			return true;
		}
	}
	return false;
}

bool areSequencesOfSameSet(const int arr1[], const size_t len1, const int arr2[], const size_t len2)
{
	for (size_t i = 0; i < len1; i++)
	{
		if (!containsNumber(arr2, len2, arr1[i]))
		{
			return false;
		}
	}

	for (size_t i = 0; i < len2; i++)
	{
		if (!containsNumber(arr1, len1, arr2[i]))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int arr1[] = { 1, 3, 4, 1, 3 };
	size_t len1 = sizeof(arr1) / sizeof(int);

	int arr2[] = { 1, 3, 3, 4, 1, 0, 3 };
	size_t len2 = sizeof(arr2) / sizeof(int);

	cout << (areSequencesOfSameSet(arr1, len1, arr2, len2) ? "Yes" : "No");
}
