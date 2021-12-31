#include <iostream>
using namespace std;

int main()
{
	const int maxSize = 100;
	int arr[maxSize];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << arr << endl; // address of the first element
	cout << arr + (n / 2) << endl; // address of the element of n/2-th position
	cout << *(arr + (n / 2)) << endl; // value of the element of n/2-th position
	cout << arr + n - 1 << endl; // address of the last element
}