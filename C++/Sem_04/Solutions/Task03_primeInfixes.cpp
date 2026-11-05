#include <iostream>
using namespace std;

bool isPrime(unsigned n)
{
	if (n <= 1)
	{
		return false;
	}

	unsigned sqrtN = sqrt(n);
	for (size_t divisorCandidate = 2; divisorCandidate <= sqrtN; divisorCandidate++)
	{
		if (n % divisorCandidate == 0)
		{
			return false;
		}
	}
	return true;
}

void printPrimeInfixes(unsigned n)
{
	while (n != 0)
	{
		for (size_t i = 10;; i *= 10)
		{
			unsigned currentInfix = n % i;
			if (isPrime(currentInfix))
			{
				cout << currentInfix << ' ';
			}

			if (currentInfix == n)
			{
				break;
			}
		}
		n /= 10;
	}
	cout << endl;
}

int main()
{
	printPrimeInfixes(753);
}