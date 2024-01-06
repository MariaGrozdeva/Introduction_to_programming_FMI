#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)

void initMatrix(char**& matrix, const size_t rowsCount)
{
	constexpr size_t MAX_SIZE = 32;
	char currentWord[MAX_SIZE];

	matrix = new char* [rowsCount];
	for (size_t i = 0; i < rowsCount; i++)
	{
		std::cin >> currentWord;
		matrix[i] = new char[strlen(currentWord) + 1];
		strcpy(matrix[i], currentWord);
	}
}

void freeMatrix(char** matrix, const size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void swapRows(char*& lhs, char*& rhs)
{
	char* temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void printPermutationOfWords(const char* const* words, const size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		std::cout << words[i] << ' ';
	}
	std::cout << std::endl;
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
		swapRows(words[pos], words[i]);
		generateAllPermutationsOfWords(words, rowsCount, pos + 1);
		swapRows(words[i], words[pos]);
	}
}

void printAllPermutationsOfWords(char** words, const size_t rowsCount)
{
	generateAllPermutationsOfWords(words, rowsCount, 0);
}

int main()
{
	size_t n;
	std::cin >> n;

	char** words = nullptr;
	initMatrix(words, n);

	printAllPermutationsOfWords(words, n);

	freeMatrix(words, n);
}
