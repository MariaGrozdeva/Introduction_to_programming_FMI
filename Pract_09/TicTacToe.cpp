#include <iostream>
using namespace std;

const int tableSize = 4;

void init(char table[tableSize][tableSize])
{
	for (int i = 0; i < tableSize; i++)
	{
		for (int j = 0; j < tableSize; j++)
			table[i][j] = ' ';
	}
}

void print(const char table[tableSize][tableSize])
{
	for (int i = 0; i < tableSize; i++)
	{
		for (int j = 0; j < tableSize; j++)
			cout << '[' << table[i][j] << ']';

		cout << endl;
	}
	cout << endl;
}

bool isValidInput(int x, int y)
{
	return (x >= 0 && x <= tableSize) && (y >= 0 && y <= tableSize);
}
bool isCellFree(const char table[tableSize][tableSize], int x, int y)
{
	return table[x][y] == ' ';
}

void inputK(int& k)
{
	do
	{
		cin >> k;
	} while (k > tableSize);
}
void inputCoordinates(const char table[tableSize][tableSize], int& x, int& y)
{
	do
	{
		cin >> x >> y;
	} while (!isValidInput(x, y) || !isCellFree(table, x, y));
}

bool isWinner(const char table[tableSize][tableSize], int k, char mark)
{
	// k consecutive marks in any row
	for (int i = 0; i < tableSize; i++)
	{
		int count = 0;
		for (int j = 0; j < tableSize; j++)
		{
			if (table[i][j] == mark)
				count++;
			else
				count = 0;

			if (count == k)
				return true;
		}
	}

	// k consecutive marks in any column
	for (int i = 0; i < tableSize; i++)
	{
		int count = 0;
		for (int j = 0; j < tableSize; j++)
		{
			if (table[j][i] == mark)
				count++;
			else
				count = 0;

			if (count == k)
				return true;
		}
	}

	// k consecutive marks in any diagonal above and below the principal one
	for (int i = 0; i < tableSize; i++)
	{
		int count = 0;
		int countSecondPart = 0;

		for (int rowInd = i, colInd = 0; rowInd < tableSize; rowInd++, colInd++)
		{
			if (table[rowInd][colInd] == mark)
				count++;
			else
				count = 0;

			if (count == k)
				return true;


			if (table[colInd][rowInd] == mark)
				countSecondPart++;
			else
				countSecondPart = 0;

			if (countSecondPart == k)
				return true;
		}
	}

	// k consecutive marks in any diagonal above the secondary one (including it)
	for (int i = 0; i < tableSize; i++)
	{
		int count = 0;
		for (int rowInd = 0, colInd = i; colInd >= 0; rowInd++, colInd--)
		{
			if (table[rowInd][colInd] == mark)
				count++;
			else
				count = 0;

			if (count == k)
				return true;
		}
	}

	// k consecutive marks in any diagonal below the secondary one
	for (int i = 1; i < tableSize; i++)
	{
		int count = 0;
		for (int rowInd = i, colInd = tableSize - 1; rowInd < tableSize; rowInd++, colInd--)
		{
			if (table[rowInd][colInd] == mark)
				count++;
			else
				count = 0;

			if (count == k)
				return true;
		}
	}

	return false;
}

int main()
{
	char table[tableSize][tableSize];
	init(table);

	cout << "Enter the number of consecutive marks which should be placed: ";
	int k; // The player who succeeds in placing k of their marks in a horizontal, vertical, or diagonal row is the winner.
	inputK(k);
	print(table);

	bool isFirstPlayersTurn = true;
	int x, y; // coordinates of a cell

	do
	{
		cout << "It's " << (isFirstPlayersTurn ? "first" : "second") << " player's turn!" << endl;
		cout << "Enter a cell with its coordinates: ";
		inputCoordinates(table, x, y);

		system("CLS"); // clears everything which is currently on the console
		table[x][y] = isFirstPlayersTurn ? 'x' : 'o';
		print(table);

		isFirstPlayersTurn = !isFirstPlayersTurn;
	} while (!isWinner(table, k, table[x][y]));

	cout << "You won!";
}