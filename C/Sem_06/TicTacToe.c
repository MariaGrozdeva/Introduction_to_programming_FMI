#include <stdio.h>

#define N 3
#define LINE_LENGTH N
#define PLAYERS 2

void init(char field[][N], char ch)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			field[i][j] = ch;
		}
	}
}

void print(const char field[][N])
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			printf("[%c]", field[i][j]);
		}
		printf("\n");
	}
}

int areValidIndices(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void input(char field[][N], int* x, int* y)
{
	do
	{
		scanf("%d%d", x, y);
	} while (!areValidIndices(*x, *y) || field[*x][*y] != ' ');
}

unsigned getConsecutiveDirection(const char field[][N], int row, int coll, int rowMove, int collMove)
{
	char ch = field[row][coll];
	unsigned count = 0;
	while (areValidIndices(row, coll) && field[row][coll] == ch)
	{
		count++;
		row += rowMove;
		coll += collMove;
	}
	return count;
}

unsigned getConsecutiveOnLine(const char field[][N], int row, int coll, int rowMove, int collMove)
{
        return getConsecutiveDirection(field, row, coll, rowMove, collMove) + 
               getConsecutiveDirection(field, row, coll, -rowMove, -collMove) - 1; // because we count the starting point twice
}

int isWinningMove(const char field[][N], int row, int coll)
{
        return getConsecutiveOnLine(field, row, coll, 0,  1) >= LINE_LENGTH || // horizontal
	       getConsecutiveOnLine(field, row, coll, 1,  0) >= LINE_LENGTH || // vertical
	       getConsecutiveOnLine(field, row, coll, 1,  1) >= LINE_LENGTH || // main diagonal
	       getConsecutiveOnLine(field, row, coll, 1, -1) >= LINE_LENGTH;   // secondary diagonal
}

int main()
{
	char field[N][N];
	init(field, ' ');
	print(field);
	
	int haveWinner = 0;
	int currentPlayer = 0;
	for (size_t i = 0; i < N * N && !haveWinner; i++)
	{
		int row, coll;
		input(field, &row, &coll);
		
		field[row][coll] = '0' + currentPlayer;
		
		print(field);
		haveWinner = isWinningMove(field, row, coll);

		currentPlayer = (currentPlayer + 1) % PLAYERS;
	}
	printf("%s\n", haveWinner ? "Winner!" : "Draw!");
}
