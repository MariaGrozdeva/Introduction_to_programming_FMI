#define _CRT_SECURE_NO_WARNINGS
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

int isReflexive(const int matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (matrix[i][i] != 1)
		{
			return 0;
		}
	}
	return 1;
}

int isSymmetric(const int matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				return 0;
			}
		}
	}
	return 1;
}

int isTransitive(const int matrix[][MAX_SIZE], const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				continue;
			}

			for (size_t k = 0; k < n; k++)
			{
				if (matrix[j][k] == 1 && matrix[i][k] == 0)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int isEquivalenceRelation(const int matrix[][MAX_SIZE], const size_t n)
{
	return isReflexive(matrix, n) && isSymmetric(matrix, n) && isTransitive(matrix, n);
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

	if (isEquivalenceRelation(matrix, n))
	{
		printf("it is\n");
	}
	else
	{
		printf("it is not\n");
	}

	return 0;
}
