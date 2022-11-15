#include <iostream>
#include <cmath>
using namespace std;

void printSolution(const bool sieve[], size_t len)
{
	for (size_t i = 2; i <= len; i++)
	{
		if (sieve[i])
		{
			cout << i << ' ';
		}
	}
}

void destroyNumbers(bool arr[], size_t len, unsigned i)
{
	unsigned toDestroy = i + i;
	while (toDestroy <= len)
	{
		arr[toDestroy] = false;
		toDestroy += i;
	}
}
void sieveEratosthenes(bool sieve[], size_t len)
{
	unsigned sqrtLen = sqrt(len);
	for (size_t i = 2; i <= sqrtLen; i++)
	{
		if (sieve[i])
		{
			destroyNumbers(sieve, len, i);
		}
	}
}

void init(bool arr[], size_t len, bool value)
{
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = value;
	}
}

int main()
{
	const int MAX_SIZE = 10000;
	bool sieve[MAX_SIZE];

	int n;
	cin >> n;
	init(sieve, n, true);

	sieveEratosthenes(sieve, n);
	printSolution(sieve, n);
}