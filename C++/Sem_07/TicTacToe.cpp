#include <iostream>
using namespace std;

const size_t N = 3;
const unsigned LINE_LENGTH = N;
const unsigned PLAYERS = 2;

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
			cout << "[" << field[i][j] << "]";
		}
		cout << endl;
	}
}

bool areValidIndices(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void input(char field[][N], int& x, int& y)
{
	do
	{
		cin >> x >> y;
	} while (!areValidIndices(x,y) || field[x][y] != ' ');
}

int getConsecutiveDirection(const char field[][N], int row, int coll, int rowMove, int collMove)
{
	char ch = field[row][coll];
	int count = 0;
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
               getConsecutiveDirection(field, row, coll, -rowMove, -collMove) - 1; // because we count the starting point twice.
}

bool isWinningMove(const char field[][N], int row, int coll)
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
	
	bool haveWinner = false;
	for(int i = 0, currentPlayer = 0; i < N * N && !haveWinner; i++, (++currentPlayer) %= PLAYERS)
	{
		int row, coll;
		input(field, row, coll);
		
		field[row][coll] = currentPlayer ? 'x' : 'o';
		
		print(field);
		haveWinner = isWinningMove(field, row, coll);
	}
	cout << (haveWinner ? "Winner!" : "Draw!") << endl;
}
