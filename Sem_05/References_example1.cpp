#include <iostream>
using namespace std;

// lvalue ("променлива")
// rvalue ("стойност/константа")

// Референция - друго име за съществуваща променлива

// Пример: 
// Напишете функция, която приема цяло число n и връща най-голямата и най-малката му цифри.

void getMaxAndMinDigit(unsigned n, short& minDigit, short& maxDigit)
{
	while (n != 0)
	{
		short lastDigit = n % 10;

		if (lastDigit > maxDigit)
		{
			maxDigit = lastDigit;
		}
		if (lastDigit < minDigit)
		{
			minDigit = lastDigit;
		}

		n /= 10;
	}
}

int main()
{
	short min = 9, max = 0;
	getMaxAndMinDigit(391905, min, max);
	cout << "Min digit: " << min << ", max digit: " << max << endl;
}
