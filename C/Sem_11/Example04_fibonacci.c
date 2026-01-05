#include <stdio.h>
#include <stdlib.h>

// naive
unsigned long long fibRecNaive(unsigned int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fibRecNaive(n - 1) + fibRecNaive(n - 2);
}

// memoization
unsigned long long fibMemoization(unsigned int n, unsigned long long* cache)
{
    if (n <= 2)
    {
        return 1;
    }

    if (cache[n] != 0) // fib(n) is already calculated
    {
        return cache[n];
    }

    unsigned long long res = fibMemoization(n - 1, cache) + fibMemoization(n - 2, cache);
    cache[n] = res;
    return res;
}

unsigned long long fib(unsigned int n)
{
    unsigned long long* cache = (unsigned long long*)malloc((n + 1) * sizeof(unsigned long long));
    for (size_t i = 0; i < n + 1; i++)
    {
        cache[i] = 0;
    }

    unsigned long long res = fibMemoization(n, cache);
    free(cache);
    return res;
}

int main()
{
    printf("%llu", fib(40));
    return 0;
}
