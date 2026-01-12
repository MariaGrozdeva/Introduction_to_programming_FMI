#include <stdio.h>

#define MAX_SIZE 100

void readMatrix(int matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}

void printMatrix(const int matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void swapElements(int matrix[][MAX_SIZE], const size_t i, const size_t j)
{
	int temp = matrix[i][j];
	matrix[i][j] = matrix[j][i];
	matrix[j][i] = temp;
}

void transposeMatrix(int matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			swapElements(matrix, i, j);
		}
	}
}

int main()
{
	size_t n = 0;
	int matrix[MAX_SIZE][MAX_SIZE];

	do
	{
		scanf("%zu", &n);
	} while (n == 0 || n > MAX_SIZE);

	readMatrix(matrix, n);
	transposeMatrix(matrix, n);
	printMatrix(matrix, n);

	return 0;
}
