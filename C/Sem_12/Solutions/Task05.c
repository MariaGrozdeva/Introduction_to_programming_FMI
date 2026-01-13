#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeMatrix(char** matrix, const size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

int initMatrix(char*** matrix, const size_t rowsCount)
{
	const size_t MAX_SIZE = 32;
	char currentWord[MAX_SIZE + 1];

	*matrix = (char**)malloc(rowsCount * sizeof(char*));
	if (!*matrix)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return -1;
	}

	for (size_t i = 0; i < rowsCount; i++)
	{
		scanf("%s", currentWord);
		(*matrix)[i] = (char*)malloc((strlen(currentWord) + 1));
		if (!(*matrix)[i])
		{
			fprintf(stderr, "Memory allocation failed\n");
			freeMatrix(*matrix, i);
			return -1;
		}
		strcpy((*matrix)[i], currentWord);
	}
	return 0;
}

void swapRows(char** lhs, char** rhs)
{
	char* temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

void printPermutationOfWords(const char* const* words, const size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		printf("%s ", words[i]);
	}
	printf("\n");
}

void generateAllPermutationsOfWords(char** words, const size_t rowsCount, const size_t pos)
{
	if (pos == rowsCount)
	{
		printPermutationOfWords(words, rowsCount);
		return;
	}

	for (size_t i = pos; i < rowsCount; i++)
	{
		swapRows(&words[pos], &words[i]);
		generateAllPermutationsOfWords(words, rowsCount, pos + 1);
		swapRows(&words[i], &words[pos]);
	}
}

void printAllPermutationsOfWords(char** words, const size_t rowsCount)
{
	generateAllPermutationsOfWords(words, rowsCount, 0);
}

int main()
{
	size_t n;
	scanf("%zu", &n);

	char** words = NULL;
	if (initMatrix(&words, n) == -1) // failure
	{
	    return -1;
	}

	printAllPermutationsOfWords(words, n);

	freeMatrix(words, n);
	return 0;
}
