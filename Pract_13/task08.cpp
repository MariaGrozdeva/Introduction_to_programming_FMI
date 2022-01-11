#include<iostream>
using namespace std;

const size_t maxSize = 26;
const size_t maxColumns = 2;

void free(char** table, size_t rowsCount) 
{
	for (size_t i = 0; i < rowsCount; i++)
		delete[] table[i];
	delete[] table;
}
void print(char** const result, size_t rowsCount, size_t colsCount) 
{
	for (size_t i = 0; i < rowsCount; i++) 
	{
		for (size_t j = 0; j < colsCount; j++)
			cout << result[i][j];
		cout << endl;
	}
}

void input(char**& table, size_t& rowsCount, size_t& colsCount) 
{
	cin >> rowsCount >> colsCount;
	table = new char* [rowsCount];

	for (size_t i = 0; i < rowsCount; i++) 
	{
		table[i] = new char[colsCount + 1];
		cin >> table[i];
	}
}

size_t findNumberOfAlpha(char** const table, char ch, size_t rowsCount, size_t colsCount) 
{
	size_t count = 0;
	for (size_t i = 0; i < rowsCount; i++) 
	{
		for (size_t j = 0; j < colsCount; j++) 
		{
			if (ch == table[i][j])
				count++;
		}
	}
	return count;
}
void differentSymbols(char** const table, char alpha[maxSize], int countSymbols[maxSize], size_t rowsCount, size_t colsCount) 
{
	char ch = 'a';
	for (size_t i = 0; i < maxSize && ch <= 'z'; i++, ch++)
		alpha[i] = ch;	

	for (size_t a = 0; a < maxSize; a++) 
		countSymbols[a] = findNumberOfAlpha(table, alpha[a], rowsCount, colsCount);
}

void createArray(char**& result, char alpha[maxSize], int countSymbols[maxSize], size_t& newSize) 
{
	for (size_t i = 0; i < maxSize; i++) 
	{
		if (countSymbols[i] != 0) 
			newSize++;
	}

	if (!newSize)
		return;

	result = new char* [newSize];
	for (size_t i = 0; i < newSize; i++) 
		result[i] = new char[maxColumns + 1];
	
	size_t j = 0;
	for (size_t i = 0; i < maxSize; i++) 
	{
		if (countSymbols[i] != 0 && j < maxSize) 
		{
			result[j][0] = alpha[i];
			result[j][1] = (char)(48 + countSymbols[i]);
			result[j][2] = '\0';
			j++;
		}
	}
}

int main() 
{
	size_t rowsCount, colsCount;
	char** table;
	input(table, rowsCount, colsCount);

	char alpha[maxSize];
	int countSymbols[maxSize];
	differentSymbols(table, alpha, countSymbols, rowsCount, colsCount);

	size_t newSize = 0;
	char** result;
	createArray(result, alpha, countSymbols, newSize);
	print(result, newSize, maxColumns);

	free(table, rowsCount);
	free(result, newSize);
}