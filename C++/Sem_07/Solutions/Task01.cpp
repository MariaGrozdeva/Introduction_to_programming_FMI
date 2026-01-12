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

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void swapElements(int matrix[MAX_SIZE][MAX_SIZE], const std::size_t i, const std::size_t j)
{
	int temp = matrix[i][j];
	matrix[i][j] = matrix[j][i];
	matrix[j][i] = temp;
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = i + 1; j < n; j++)
		{
			swapElements(matrix, i, j);
		}
	}
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
	transposeMatrix(matrix, n);
	printMatrix(matrix, n);

	return 0;
}
