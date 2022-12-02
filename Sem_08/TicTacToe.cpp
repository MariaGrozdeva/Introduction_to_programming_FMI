#include <iostream>
using namespace std;

const int BOARD_SIZE = 4;

void init(char board[][BOARD_SIZE])
{
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print(const char board[][BOARD_SIZE])
{
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			cout << '[' << board[i][j] << ']';
		}
		cout << endl;
	}
	cout << endl;
}

bool isValidInput(unsigned short x, unsigned short y)
{
	return (x >= 0 && x < BOARD_SIZE) && (y >= 0 && y < BOARD_SIZE);
}
bool isCellFree(const char board[][BOARD_SIZE], unsigned short x, unsigned short y)
{
	return board[x][y] == ' ';
}
void inputCoordinates(const char board[][BOARD_SIZE], unsigned short& x, unsigned short& y)
{
	do
	{
		cout << "Enter a cell with its valid coordinates: ";
		cin >> x >> y;
	} while (!isValidInput(x, y) || !isCellFree(board, x, y));
}

bool checkIfRowColContainsSameMarks(const char board[][BOARD_SIZE], char mark, unsigned short markRow, unsigned short markCol, bool checkRow)
{
	unsigned row = checkRow ? markRow : 0;
	unsigned col = checkRow ? 0 : markCol;

	for (; row < BOARD_SIZE && col < BOARD_SIZE; row += !checkRow, col += checkRow)
	{
		if (board[row][col] != mark)
		{
			return false;
		}
	}
	return true;
}
bool rowOrColFilledWithMark(const char board[][BOARD_SIZE], char mark, unsigned short markRow, unsigned short markCol)
{
	return checkIfRowColContainsSameMarks(board, mark, markRow, markCol, true) ||
		checkIfRowColContainsSameMarks(board, mark, markRow, markCol, false);
}

bool isInPrincipalDiagonal(unsigned short markRow, unsigned short markCol)
{
	return markRow == markCol;
}
bool isInSecondaryDiagonal(unsigned short markRow, unsigned short markCol)
{
	return markRow + markCol == BOARD_SIZE - 1;
}

bool checkIfDiagonalContainsSameMarks(const char board[][BOARD_SIZE], char mark, unsigned short markRow, unsigned short markCol, int rowChange, int colChange)
{
	for (int rowInd = markRow, colInd = markCol; rowInd >= 0 && rowInd < BOARD_SIZE && colInd >= 0 && colInd < BOARD_SIZE;
		rowInd += rowChange, colInd += colChange)
	{
		if (board[rowInd][colInd] != mark)
		{
			return false;
		}
	}
	return true;
}
bool diagonalFilledWithMark(const char board[][BOARD_SIZE], char mark, unsigned short markRow, unsigned short markCol)
{
	// 1. checks the elements in the PRINCIPAL diagonal BELOW the given cell
	// 2. checks the elements in the PRINCIPAL diagonal ABOVE the given cell
	// 3. checks the elements in the SECONDARY diagonal BELOW the given cell
	// 4. checks the elements in the SECONDARY diagonal ABOVE the given cell

	return (isInPrincipalDiagonal(markRow, markCol) &&
		checkIfDiagonalContainsSameMarks(board, mark, markRow, markCol, 1, 1) &&
		checkIfDiagonalContainsSameMarks(board, mark, markRow, markCol, -1, -1)) ||
		(isInSecondaryDiagonal(markRow, markCol) &&
			checkIfDiagonalContainsSameMarks(board, mark, markRow, markCol, 1, -1) &&
			checkIfDiagonalContainsSameMarks(board, mark, markRow, markCol, -1, 1));
}

bool isWinner(const char board[][BOARD_SIZE], char mark, unsigned short markRow, unsigned short markCol)
{
	return rowOrColFilledWithMark(board, mark, markRow, markCol) || diagonalFilledWithMark(board, mark, markRow, markCol);
}

int main()
{
	char board[BOARD_SIZE][BOARD_SIZE];
	init(board);
	print(board);

	bool isFirstPlayersTurn = true;
	unsigned short x, y;

	do
	{
		cout << "It's " << (isFirstPlayersTurn ? "first" : "second") << " player's turn!" << endl;
		inputCoordinates(board, x, y);

		system("CLS"); // clears everything which is currently on the console
		board[x][y] = isFirstPlayersTurn ? 'x' : 'o';
		print(board);

		isFirstPlayersTurn = !isFirstPlayersTurn;
	} while (!isWinner(board, board[x][y], x, y));

	cout << "You won!";
}