#include <iostream>
using namespace std;

void print(const char* str)
{
	cout << str << endl;
}
void getAllNumbersWithIncreasingDigits(int n, char* currentNum, int start)
{
	if (n == 0)
	{
		currentNum[start] = '\0';
		print(currentNum);
		return;
	}
	for (char i = '0'; i <= '9'; i++)
	{
		currentNum[start] = i;
		getAllNumbersWithIncreasingDigits(n - 1, currentNum, start + 1);
	}
}
void getAllNumbersWithIncreasingDigits(int n)
{
	char* currentNum = new char[n + 1];
	getAllNumbersWithIncreasingDigits(n, currentNum, 0);

	delete[] currentNum;
}

int main()
{
	int n;
	cin >> n;

	getAllNumbersWithIncreasingDigits(n);
}