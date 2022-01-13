#include <iostream>
using namespace std;

const int MAX_WORD_SIZE = 32;
const int ALPHABET_SIZE = 26;
const int RESULT_ROWS = 2;

void input(char**& arrayOfStrings, int& numberOfStrings)
{
	cin >> numberOfStrings;
	arrayOfStrings = new char* [numberOfStrings];
	for (int i = 0; i < numberOfStrings; i++)
	{
		arrayOfStrings[i] = new char[MAX_WORD_SIZE];
		cin >> arrayOfStrings[i];
	}
}

void free(char** arrayOfStings, int numberOfStrings)
{
	for (int i = 0; i < numberOfStrings; i++)
		delete[] arrayOfStings[i];
	delete[] arrayOfStings;
}

int meetLetter(char** const arrayOfStrings, int numberOfStrings, char ch)
{
	int cnt = 0;
	for (int i = 0; i < numberOfStrings; i++)
	{
		int currentWordLen = strlen(arrayOfStrings[i]);
		int idx = 0;
		while (idx < currentWordLen)
		{
			if (arrayOfStrings[i][idx++] == ch)
				cnt++;
		}
	}
	return cnt;
}

void numberOfLettersMeet(char** const arrayOfStrings, int numberOfStrings, int arrWithValues[ALPHABET_SIZE])
{
	int currentWordMeeting = 0;
	char ch = 'a';
	for (int i = 0; i < ALPHABET_SIZE && ch <= 'z'; i++, ch++)
	{
		currentWordMeeting = meetLetter(arrayOfStrings, numberOfStrings, ch);
		arrWithValues[i] = currentWordMeeting;
	}
}

int newSizeOfColums(int arrayOfValues[ALPHABET_SIZE])
{
	int cnt = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (arrayOfValues[i] != 0)
			cnt++;
	}
	return cnt;
}

void createResult(char**& result, int newSize)
{
	result = new char* [RESULT_ROWS];
	for (int i = 0; i < RESULT_ROWS; i++)
		result[i] = new char[newSize + 1];
}

void clearResult(char** result, int size)
{
	for (int i = 0; i < size; i++)
		delete[] result[i];
	delete[] result;
}

void fillResult(char**& result, int cols, int arrayWithValues[ALPHABET_SIZE])
{
	char ch = 'a';
	for (int i = 0, j = 0; i < ALPHABET_SIZE && j < cols && ch <= 'z'; i++, ch++)
	{
		if (arrayWithValues[i] != 0)
		{
			result[0][j] = ch;
			result[1][j] = (char)(arrayWithValues[i] + '0');	
			j++;
		}
	}

	result[0][cols] = '\0';
	result[1][cols] = '\0';
}

void printMatrix(char** const arrayOfStrings, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << arrayOfStrings[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	char** arrayOfStrings;
	int numberOfStrings;
	input(arrayOfStrings, numberOfStrings);

	int arrayWithValues[ALPHABET_SIZE] = {};
	numberOfLettersMeet(arrayOfStrings, numberOfStrings, arrayWithValues);
	
	char** result;
	int newSize = newSizeOfColums(arrayWithValues);
	createResult(result, newSize);
	fillResult(result, newSize, arrayWithValues);
	printMatrix(result, RESULT_ROWS, newSize);

	clearResult(result, RESULT_ROWS);
	free(arrayOfStrings, numberOfStrings);
}
