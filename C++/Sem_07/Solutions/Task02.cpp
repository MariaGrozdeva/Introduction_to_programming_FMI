#include <iostream>
#include <cstddef>

constexpr std::size_t MAX_SIZE = 100;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

bool isReflexive(const int matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		if (matrix[i][i] != 1)
		{
			return false;
		}
	}
	return true;
}

bool isSymmetric(const int matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = i + 1; j < n; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

bool isTransitive(const int matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				continue;
			}

			for (std::size_t k = 0; k < n; k++)
			{
				if (matrix[j][k] == 1 && matrix[i][k] == 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool isEquivalenceRelation(const int matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	return isReflexive(matrix, n) && isSymmetric(matrix, n) && isTransitive(matrix, n);
}

int main()
{
	std::size_t n = 0;
	int matrix[MAX_SIZE][MAX_SIZE];

	do
	{
		std::cin >> n;
	} while (n == 0 || n > MAX_SIZE);

	readMatrix(matrix, n);

	if (isEquivalenceRelation(matrix, n))
	{
		std::cout << "it is\n";
	}
	else
	{
		std::cout << "it is not\n";
	}

	return 0;
}

