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

bool isValidInput(const unsigned short x, const unsigned short y)
{
	return (x >= 0 && x < BOARD_SIZE) && (y >= 0 && y < BOARD_SIZE);
}
bool isCellFree(const char board[][BOARD_SIZE], const unsigned short x, const unsigned short y)
{
	return board[x][y] == ' ';
}
void inputCoordinates(const char board[][BOARD_SIZE], unsigned short& x, unsigned short& y)
{
	do
	{
		cout << "Enter a valid cell... ";
		cin >> x >> y;
	} while (!isValidInput(x, y) || !isCellFree(board, x, y));
}

bool checkIfRowColContainsSameMarks(const char board[][BOARD_SIZE], const char mark, const unsigned short markRow, const unsigned short markCol, const bool checkRow)
{
	unsigned short row = checkRow ? markRow : 0;
	unsigned short col = checkRow ? 0 : markCol;

	for (; row < BOARD_SIZE && col < BOARD_SIZE; row += !checkRow, col += checkRow)
	{
		if (board[row][col] != mark)
		{
			return false;
		}
	}
	return true;
}
bool rowOrColFilledWithMark(const char board[][BOARD_SIZE], const char mark, const unsigned short markRow, const unsigned short markCol)
{
	return checkIfRowColContainsSameMarks(board, mark, markRow, markCol, true) ||
		checkIfRowColContainsSameMarks(board, mark, markRow, markCol, false);
}

bool isInPrincipalDiagonal(const unsigned short markRow, const unsigned short markCol)
{
	return markRow == markCol;
}
bool isInSecondaryDiagonal(const unsigned short markRow, const unsigned short markCol)
{
	return markRow + markCol == BOARD_SIZE - 1;
}

bool checkIfDiagonalContainsSameMarks(const char board[][BOARD_SIZE], const char mark, const unsigned short markRow, const unsigned short markCol, const bool checkPrincipal)
{
	int row = checkPrincipal ? 0 : BOARD_SIZE - 1;
	int col = 0;
	int updateRow = checkPrincipal ? 1 : -1;
	int updateCol = 1;

	for (; row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE; row += updateRow, col += updateCol)
	{
		if (board[row][col] != mark)
		{
			return false;
		}
	}
	return true;
}
bool diagonalsFilledWithMark(const char board[][BOARD_SIZE], const char mark, const unsigned short markRow, const unsigned short markCol)
{
	// 1. checks the elements in the principal diagonal
	// 2. checks the elements in the secondary diagonal

	return (isInPrincipalDiagonal(markRow, markCol) && checkIfDiagonalContainsSameMarks(board, mark, markRow, markCol, true)) ||
		(isInSecondaryDiagonal(markRow, markCol) && checkIfDiagonalContainsSameMarks(board, mark, markRow, markCol, false));
}

bool isWinner(const char board[][BOARD_SIZE], const char mark, const unsigned short markRow, const unsigned short markCol)
{
	return rowOrColFilledWithMark(board, mark, markRow, markCol) || diagonalsFilledWithMark(board, mark, markRow, markCol);
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

		system("clear"); // Clears everything which is currently on the console. For Windows use system("cls").
		board[x][y] = isFirstPlayersTurn ? 'x' : 'o';
		print(board);

		isFirstPlayersTurn = !isFirstPlayersTurn;
	} while (!isWinner(board, board[x][y], x, y));

	cout << "You won!";
}
