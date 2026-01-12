#include <iostream>
#include <cstddef>

constexpr std::size_t MAX_SIZE = 100;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], const std::size_t rows, const std::size_t cols)
{
	for (std::size_t i = 0; i < rows; i++)
	{
		for (std::size_t j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], const std::size_t rows, const std::size_t cols)
{
	for (std::size_t i = 0; i < rows; i++)
	{
		for (std::size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void multiplyMatrices(const int lhs[MAX_SIZE][MAX_SIZE],
					  const int rhs[MAX_SIZE][MAX_SIZE],
					  int result[MAX_SIZE][MAX_SIZE],
					  const std::size_t n,
					  const std::size_t m,
					  const std::size_t k)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < k; j++)
		{
			int sum = 0;
			for (std::size_t t = 0; t < m; t++)
			{
				sum += lhs[i][t] * rhs[t][j];
			}
			result[i][j] = sum;
		}
	}
}

int main()
{
	std::size_t n = 0, m = 0, k = 0;

	do
	{
		std::cin >> n >> m >> k;
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

