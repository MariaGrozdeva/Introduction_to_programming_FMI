#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100
#define EPS 1e-9

void readMatrix(double matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			scanf("%lf", &matrix[i][j]);
		}
	}
}

void printMatrix(const double matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf("%.6lf ", matrix[i][j]);
		}
		printf("\n");
	}
}

void swapRows(double aug[][2 * MAX_SIZE], const size_t cols, const size_t r1, const size_t r2)
{
	if (r1 == r2)
	{
		return;
	}

	for (size_t j = 0; j < cols; j++)
	{
		double temp = aug[r1][j];
		aug[r1][j] = aug[r2][j];
		aug[r2][j] = temp;
	}
}

void buildAugmented(const double a[][MAX_SIZE], double aug[][2 * MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < 2 * n; j++)
		{
			if (j < n)
			{
				aug[i][j] = a[i][j];
			}
			else
			{
				aug[i][j] = (j == n + i) ? 1.0 : 0.0;
			}
		}
	}
}

int inverseMatrix(const double a[][MAX_SIZE], double inv[][MAX_SIZE], const size_t n)
{
	double aug[MAX_SIZE][2 * MAX_SIZE];
	buildAugmented(a, aug, n);

	for (size_t col = 0; col < n; col++)
	{
		size_t pivotRow = col;
		double best = fabs(aug[col][col]);

		for (size_t r = col + 1; r < n; r++)
		{
			double val = fabs(aug[r][col]);
			if (val > best)
			{
				best = val;
				pivotRow = r;
			}
		}

		if (best < EPS)
		{
			return 0;
		}

		swapRows(aug, 2 * n, col, pivotRow);

		double pivot = aug[col][col];
		for (size_t j = 0; j < 2 * n; j++)
		{
			aug[col][j] /= pivot;
		}

		for (size_t r = 0; r < n; r++)
		{
			if (r == col)
			{
				continue;
			}

			double factor = aug[r][col];
			if (fabs(factor) < EPS)
			{
				continue;
			}

			for (size_t j = 0; j < 2 * n; j++)
			{
				aug[r][j] -= factor * aug[col][j];
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			inv[i][j] = aug[i][n + j];
		}
	}

	return 1;
}

int main()
{
	size_t n = 0;
	do
	{
		scanf("%zu", &n);
	} while (n == 0 || n > MAX_SIZE);

	double a[MAX_SIZE][MAX_SIZE];
	double inv[MAX_SIZE][MAX_SIZE];

	readMatrix(a, n);

	if (!inverseMatrix(a, inv, n))
	{
		printf("Matrix is not invertible\n");
		return 0;
	}

	printMatrix(inv, n);
	return 0;
}
