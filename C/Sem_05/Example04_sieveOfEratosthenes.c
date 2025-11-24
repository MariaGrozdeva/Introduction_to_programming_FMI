#include <stdio.h>
#include <math.h>

void init(int arr[], const size_t len, const int value)
{
	for (size_t i = 2; i <= len; i++)
	{
		arr[i] = value;
	}
}

void printSolution(const int sieve[], const size_t len)
{
	for (size_t i = 2; i <= len; i++)
	{
		if (sieve[i])
		{
			printf("%zu ", i);
		}
	}
}

void destroyNumbers(int arr[], const size_t len, const unsigned i)
{
	unsigned toDestroy = i + i;
	while (toDestroy <= len)
	{
		arr[toDestroy] = 0;
		toDestroy += i;
	}
}

void sieveEratosthenes(int sieve[], const size_t len)
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

int main()
{
	#define MAX_SIZE 10000
	int sieve[MAX_SIZE + 1];

	int n;
	scanf("%d", &n);
	if (n > MAX_SIZE)
	{
            printf(stderr, "n must be <= %d\n", MAX_SIZE);
            return 1;
        }
        
	init(sieve, n, 1);
	sieveEratosthenes(sieve, n);
	printSolution(sieve, n);
	
	return 0;
}
