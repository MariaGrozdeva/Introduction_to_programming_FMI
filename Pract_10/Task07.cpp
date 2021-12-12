#include <iostream>

const int SIZE = 4;

void rotateMatrixClockWise(int mat[SIZE][SIZE])
{
	for (int i = 0; i < SIZE / 2; i++) 
	{
		for (int j = i; j < SIZE - i - 1; j++) 
		{
			int temp = mat[i][j];
			*(*(mat + i) + j) = *(*(mat + (SIZE - j - 1)) + i);
			*(*(mat + (SIZE - j - 1)) + i) = *(*(mat + (SIZE - i - 1)) + (SIZE - j - 1));
			*(*(mat + (SIZE - i - 1)) + (SIZE - j - 1)) = *(*(mat + j) + (SIZE - i - 1));
			*(*(mat + j) + (SIZE - i - 1)) = temp;
		}
	}
}


void printMatrix(const int mat[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << mat[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int main()
{
	int mat[SIZE][SIZE] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	printMatrix(mat);
	rotateMatrixClockWise(mat);
	printMatrix(mat);

	return 0;
}