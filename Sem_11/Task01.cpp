#include <iostream>
using namespace std;

double** createMatrix(size_t rowsCount, size_t colsCount)
{
	double** matrix = new double*[rowsCount];
	for (size_t i = 0; i < rowsCount; i++)
	{
		matrix[i] = new double[colsCount];
	}

	return matrix;
}

void freeMatrix(double** matrix, size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void initMatrix(double** matrix, size_t rowsCount, size_t colsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < colsCount; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(const double** matrix, size_t rowsCount, size_t colsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < colsCount; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void printArray(const double* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
}

void divideBy(double* arr, size_t size, double value)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] /= value;
	}
}

void substractRows(double* toSubstractFrom, const double* toBeSubstracted, size_t size, double coeff)
{
	for (size_t i = 0; i < size; i++)
	{
		toSubstractFrom[i] -= toBeSubstracted[i] * coeff;
	}
}
void makeColumnZero(double** matrix, size_t rowsCount, size_t colsCount, unsigned int rowWithOne)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		if (i == rowWithOne)
		{
			continue;
		}
		substractRows(matrix[i], matrix[rowWithOne], colsCount, matrix[i][rowWithOne]);
	}
}

double* solve(double** matrix, size_t rowsCount, size_t colsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		divideBy(matrix[i], colsCount, matrix[i][i]);
		makeColumnZero(matrix, rowsCount, colsCount, i);
	}

	double* result = new double[rowsCount];
	for (size_t i = 0; i < rowsCount; i++)
	{
		result[i] = matrix[i][colsCount - 1];
	}

	return result;
}

int main()
{
	size_t n;
	cin >> n;

	double** matrix = createMatrix(n, n + 1);
	initMatrix(matrix, n, n + 1);

	double* result = solve(matrix, n, n + 1);
	printArray(result, n);

	delete[] result;
	freeMatrix(matrix, n);
}