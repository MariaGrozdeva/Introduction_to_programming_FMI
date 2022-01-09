#include <iostream>
using namespace std;

void longestSubarrayWithSameElements(const int arr[], int size, size_t& begin, size_t& end)
{
	size_t max = 1;
	size_t currentBegin = 0, currentEnd = 0;

	int index = 0;
	while (index < size)
	{
		size_t currentMax = 1;
		int currentEl = arr[index];
		currentBegin = index;
		
		while (arr[++index] == currentEl)
		{
			currentMax++;
			currentEnd = index;
		}

		if (currentMax > max)
		{
			max = currentMax;
			begin = currentBegin;
			end = currentEnd;
		}
	}
}

int main()
{
	int arr[] = { -8, 22, 22, 22, 44, 44, -8, 100, -8, -8 };
	size_t size = sizeof(arr) / sizeof(int);

	size_t begin = 0;
	size_t end = 0;

	longestSubarrayWithSameElements(arr, size, begin, end);
	cout << "begin: " << begin << ", end: " << end;
}