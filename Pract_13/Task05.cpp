#include <iostream>
using namespace std;

void print(int sum)
{
	cout << sum << ' ';
}
void sumsOfAllSubsets(const int* arr, int len, int currentPos, int currentSum)
{
	if (currentPos == len)
	{
		print(currentSum);
		return;
	}

	// include current element in the subset
	sumsOfAllSubsets(arr, len, currentPos + 1, currentSum + arr[currentPos]);

	// NOT include current element in the subset
	sumsOfAllSubsets(arr, len, currentPos + 1, currentSum);
}
void sumsOfAllSubsets(const int* arr, int len)
{
	sumsOfAllSubsets(arr, len, 0, 0);
}

int main()
{
	int arr[] = { 2,4,5 };
	int len = sizeof(arr) / sizeof(int);

	sumsOfAllSubsets(arr, len);
}