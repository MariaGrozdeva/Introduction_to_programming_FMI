#include <iostream>

const int ROWS = 64;
const int COLS = 64;

bool isEven(const int num)
{
	return num % 2 == 0;
}

void inputMatrix(int matrix[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			std::cin >> matrix[i][j];
	std::cout << '\n';
}

void printMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int** matrixFromOddColumns(const int matrix[ROWS][COLS], int rows, int& cols)
{
	int newCols = 0;
	if (!isEven(cols))
		newCols = cols / 2 + 1;
	else
		newCols = cols / 2; 
	
	int** newMatrix = new int* [rows];
	for (int i = 0; i < rows; i++)
		newMatrix[i] = new int[newCols];

	for (int i = 0; i < rows; i++)
		for (int j = 0, idx = 1; j < newCols && idx < cols; j++, idx += 2)
			newMatrix[i][j] = matrix[i][idx];

	cols = newCols;
	return newMatrix;
}

void freeMatrixFromOddColumns(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

int** matrixFromEvenColumns(const int matrix[ROWS][COLS], int rows, int& cols)
{
	int newCols = 0;
	if (!isEven(cols))
		newCols = cols / 2 + 1;
	else
		newCols = cols / 2;

	int** newMatrix = new int* [rows];
	for (int i = 0; i < rows; i++)
		newMatrix[i] = new int[newCols];

	for (int i = 0; i < rows; i++)
		for (int j = 0, idx = 0; j < newCols && idx < cols; j++, idx += 2)
			newMatrix[i][j] = matrix[i][idx];

	cols = newCols;
	return newMatrix;
}

void freeMatrixFromEvenColumns(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

int** matrixFromOddRows(const int matrix[ROWS][COLS], int& rows, int cols)
{
	int newRows = 0;
	if (!isEven(rows))
		newRows = rows / 2 + 1;
	else
		newRows = rows / 2;

	int** newMatrix = new int* [newRows];
	for (int i = 0; i < newRows; i++)
		newMatrix[i] = new int[cols];

	for (int i = 0, idx = 1; i < newRows && idx < rows; i++, idx += 2)
		for (int j = 0; j < cols; j++)
			newMatrix[i][j] = matrix[idx][j];

	rows = newRows;
	return newMatrix;
}

void freeMatrixFromOddRows(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

int** matrixFromEvenRows(const int matrix[ROWS][COLS], int& rows, int cols)
{
	int newRows = 0;
	if (!isEven(rows))
		newRows = rows / 2 + 1;
	else
		newRows = rows / 2;

	int** newMatrix = new int* [newRows];
	for (int i = 0; i < newRows; i++)
		newMatrix[i] = new int[cols];

	for (int i = 0, idx = 0; i < newRows && idx < rows; i++, idx += 2)
		for (int j = 0; j < cols; j++)
			newMatrix[i][j] = matrix[idx][j];

	rows = newRows;
	return newMatrix;
}

void freeMatrixFromEvenRows(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void generateTwoNewMartices(int matrix[ROWS][COLS], int rows, int cols)
{
	if (cols > rows)
	{
		int newCols = cols;

		int** matFromOddColumns = matrixFromOddColumns(matrix, rows, cols);
		printMatrix(matFromOddColumns, rows, cols);
		freeMatrixFromOddColumns(matFromOddColumns, rows);

		int** matFromEvenColumns = matrixFromEvenColumns(matrix, rows, newCols);
		printMatrix(matFromEvenColumns, rows, newCols);
		freeMatrixFromEvenColumns(matFromEvenColumns, rows);
	}
	else if (rows >= cols)
	{
		int newRows = rows;

		int** matFromOddRows = matrixFromOddRows(matrix, rows, cols);
		printMatrix(matFromOddRows, rows, cols);
		freeMatrixFromOddRows(matFromOddRows, rows);

		int** matFromEvenRows = matrixFromEvenRows(matrix, newRows, cols);
		printMatrix(matFromEvenRows, newRows, cols);
		freeMatrixFromEvenRows(matFromEvenRows, newRows);
	}
}

int main()
{
	int matrix[ROWS][COLS];
	int rows, cols;

	std::cout << "Input matrix dimensions: ";
	std::cin >> rows >> cols;
	inputMatrix(matrix, rows, cols);

	generateTwoNewMartices(matrix, rows, cols);
	
	return 0;
}