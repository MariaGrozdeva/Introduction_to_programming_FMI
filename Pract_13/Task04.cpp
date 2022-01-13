#include <iostream>

void printCurrentArr(const int* currentArr, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << currentArr[i];
	std::cout << ' ';
}

void allNumbersWithNDigits(int n, int* currentArr, int len, int pos, int start)
{
	if (!n)
	{
		printCurrentArr(currentArr, len);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		currentArr[pos] = i;	
		if (i - start + 1 > pos)
		{
			allNumbersWithNDigits(n - 1, currentArr, len, pos + 1, start);
			start++;
		}
	}
}

void allNumbersWithNDigits(int n)
{
	int len = n;
	int* current = new int[len];
	int pos = 0;
	int start = 0;
	allNumbersWithNDigits(n, current, len, pos, start);

	delete[] current;
}

int main()
{
	int n;
	std::cin >> n;
	allNumbersWithNDigits(n);

	return 0;
}