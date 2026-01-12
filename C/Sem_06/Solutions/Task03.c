#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

void readMatrix(int matrix[][MAX_SIZE], const size_t rows, const size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}

void printMatrix(const int matrix[][MAX_SIZE], const size_t rows, const size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void multiplyMatrices(const int lhs[][MAX_SIZE],
					  const int rhs[][MAX_SIZE],
					  int result[][MAX_SIZE],
					  const size_t n,
					  const size_t m,
					  const size_t k)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < k; j++)
		{
			int sum = 0;
			for (size_t t = 0; t < m; t++)
			{
				sum += lhs[i][t] * rhs[t][j];
			}
			result[i][j] = sum;
		}
	}
}

int main()
{
	size_t n = 0, m = 0, k = 0;

	do
	{
		scanf("%zu %zu %zu", &n, &m, &k);
	} while (n == 0 || m == 0 || k == 0 || n > MAX_SIZE || m > MAX_SIZE || k > MAX_SIZE);

	int lhs[MAX_SIZE][MAX_SIZE];
	int rhs[MAX_SIZE][MAX_SIZE];
	int result[MAX_SIZE][MAX_SIZE] = { 0 };

	readMatrix(lhs, n, m);
	readMatrix(rhs, m, k);

	multiplyMatrices(lhs, rhs, result, n, m, k);
	printMatrix(result, n, k);

	return 0;
}
