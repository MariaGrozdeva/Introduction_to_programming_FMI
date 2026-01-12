#include <iostream>
#include <cstddef>
#include <cmath>
#include <iomanip>

constexpr std::size_t MAX_SIZE = 100;
constexpr double EPS = 1e-9;

void readMatrix(double matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(const double matrix[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	std::cout << std::fixed << std::setprecision(6);

	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void swapRows(double aug[MAX_SIZE][2 * MAX_SIZE], const std::size_t cols, const std::size_t r1, const std::size_t r2)
{
	if (r1 == r2)
	{
		return;
	}

	for (std::size_t j = 0; j < cols; j++)
	{
		double temp = aug[r1][j];
		aug[r1][j] = aug[r2][j];
		aug[r2][j] = temp;
	}
}

void buildAugmented(const double a[MAX_SIZE][MAX_SIZE], double aug[MAX_SIZE][2 * MAX_SIZE], const std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < 2 * n; j++)
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

bool inverseMatrix(const double a[MAX_SIZE][MAX_SIZE], double inv[MAX_SIZE][MAX_SIZE], const std::size_t n)
{
	double aug[MAX_SIZE][2 * MAX_SIZE];
	buildAugmented(a, aug, n);

	for (std::size_t col = 0; col < n; col++)
	{
		std::size_t pivotRow = col;
		double best = std::fabs(aug[col][col]);

		for (std::size_t r = col + 1; r < n; r++)
		{
			double val = std::fabs(aug[r][col]);
			if (val > best)
			{
				best = val;
				pivotRow = r;
			}
		}

		if (best < EPS)
		{
			return false;
		}

		swapRows(aug, 2 * n, col, pivotRow);

		double pivot = aug[col][col];
		for (std::size_t j = 0; j < 2 * n; j++)
		{
			aug[col][j] /= pivot;
		}

		for (std::size_t r = 0; r < n; r++)
		{
			if (r == col)
			{
				continue;
			}

			double factor = aug[r][col];
			if (std::fabs(factor) < EPS)
			{
				continue;
			}

			for (std::size_t j = 0; j < 2 * n; j++)
			{
				aug[r][j] -= factor * aug[col][j];
			}
		}
	}

	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = 0; j < n; j++)
		{
			inv[i][j] = aug[i][n + j];
		}
	}

	return true;
}

int main()
{
	std::size_t n = 0;
	do
	{
		std::cin >> n;
	} while (n == 0 || n > MAX_SIZE);

	double a[MAX_SIZE][MAX_SIZE];
	double inv[MAX_SIZE][MAX_SIZE];

	readMatrix(a, n);

	if (!inverseMatrix(a, inv, n))
	{
		std::cout << "Matrix is not invertible\n";
		return 0;
	}

	printMatrix(inv, n);
	return 0;
}
