#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initMatrix(char*** matrix, const size_t rowsCount)
{
	const size_t MAX_SIZE = 32;
	char currentWord[MAX_SIZE];

	*matrix = (char**)malloc(rowsCount * sizeof(char*));
	if (!*matrix)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}

	for (size_t i = 0; i < rowsCount; i++)
	{
		scanf("%s", currentWord);
		(*matrix)[i] = (char*)malloc((strlen(currentWord) + 1) * sizeof(char));
		if (!(*matrix)[i])
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(1);
		}
		strcpy((*matrix)[i], currentWord);
	}
}

void freeMatrix(char** matrix, const size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void swapRows(char** lhs, char** rhs)
{
	char* temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

void printPermutationOfWords(char** words, const size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		printf("%s ", words[i]);
	}
	printf("\n");
}

void generateAllPermutationsOfWords(char** words, const size_t rowsCount, const unsigned pos)
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
	initMatrix(&words, n);

	printAllPermutationsOfWords(words, n);

	freeMatrix(words, n);
	return 0;
}
