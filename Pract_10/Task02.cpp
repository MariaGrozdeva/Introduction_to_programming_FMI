#include <iostream>
using namespace std;

int main()
{
	const int rows = 4;
	const int maxCols = 100;
	int matrix[rows][maxCols];

	int n;
	cin >> n;

	const int cols = n / 4;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cin >> matrix[i][j];
	}

	cout << matrix << endl; // address of the first element of the first row
	cout << matrix + rows - 1 << endl; // address of the first element of the last row
	cout << *(matrix + 2) << endl; // address of the first element of the third row
	cout << **(matrix + 2) << endl; // value of the first element of the third row
	cout << *(*(matrix + rows - 1) + cols - 1) << endl; // value of the last element of the last row
}