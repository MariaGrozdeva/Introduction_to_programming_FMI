#include <stdio.h>
#include <stdlib.h>

double** createMatrix(const size_t rowsCount, const size_t colsCount)
{
    double** matrix = (double**)malloc(rowsCount * sizeof(double*));
    for (size_t i = 0; i < rowsCount; i++)
    {
        matrix[i] = (double*)malloc(colsCount * sizeof(double));
    }

    return matrix;
}

void freeMatrix(double** matrix, const size_t rowsCount)
{
    for (size_t i = 0; i < rowsCount; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void initMatrix(double** matrix, const size_t rowsCount, const size_t colsCount)
{
    for (size_t i = 0; i < rowsCount; i++)
    {
        for (size_t j = 0; j < colsCount; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(double* const* matrix, const size_t rowsCount, const size_t colsCount)
{
    for (size_t i = 0; i < rowsCount; i++)
    {
        for (size_t j = 0; j < colsCount; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printArray(const double* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%lf ", arr[i]);
    }
}

void divideBy(double* arr, const size_t size, const double value)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] /= value;
    }
}

void substractRows(double* toSubstractFrom, const double* toBeSubstracted, const size_t size, const double coeff)
{
    for (size_t i = 0; i < size; i++)
    {
        toSubstractFrom[i] -= toBeSubstracted[i] * coeff;
    }
}

void makeColumnZero(double** matrix, const size_t rowsCount, const size_t colsCount, const unsigned rowWithOne)
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

double* solve(double** matrix, const size_t rowsCount, const size_t colsCount)
{
    for (size_t i = 0; i < rowsCount; i++)
    {
        if (matrix[i][i] != 1) // no need to divide by 1
        {
            divideBy(matrix[i], colsCount, matrix[i][i]);
        }
        makeColumnZero(matrix, rowsCount, colsCount, i);
    }

    double* result = (double*)malloc(rowsCount * sizeof(double));
    for (size_t i = 0; i < rowsCount; i++)
    {
        result[i] = matrix[i][colsCount - 1];
    }

    return result;
}

int main()
{
    size_t n;
    scanf("%zu", &n);

    double** matrix = createMatrix(n, n + 1);
    initMatrix(matrix, n, n + 1);

    double* result = solve(matrix, n, n + 1);
    printArray(result, n);

    free(result);
    freeMatrix(matrix, n);
}
