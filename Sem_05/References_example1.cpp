#include <iostream>
using namespace std;

// lvalue ("променлива")
// rvalue ("стойност/константа")

// Референция - друго име за съществуваща променлива

// Пример: 
// Напишете функция, която приема цяло число n и връща най-голямата и най-малката му цифри.

void getMaxAndMinDigit(unsigned n, short& maxDigit, short& minDigit)
{
	short max = 0;
	short min = 9;

	while (n != 0)
	{
		short lastDigit = n % 10;

		if (lastDigit > max)
		{
			max = lastDigit;
		}
		if (lastDigit < min)
		{
			min = lastDigit;
		}

		n /= 10;
	}

	maxDigit = max;
	minDigit = min;
}

int main()
{
	
}