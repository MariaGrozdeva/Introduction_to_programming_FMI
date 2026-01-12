#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printBitstring(const int* bitstring, const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%d", bitstring[i]);
	}
	printf("\n");
}

void generateAllBitstrings(int* bitstring, unsigned int pos, const size_t n, int(*pred)(const int* bitstring, const size_t n))
{
	if (pos == n)
	{
	    if (pred(bitstring, n))
	    {
		    printBitstring(bitstring, n);
	    }
	    return;
	}

	bitstring[pos] = 0;
	generateAllBitstrings(bitstring, pos + 1, n, pred);

	bitstring[pos] = 1;
	generateAllBitstrings(bitstring, pos + 1, n, pred);
}

void printBitstrings(const size_t n, int(*pred)(const int* bitstring, const size_t n))
{
	int* bitstring = (int*)malloc(n * sizeof(int));
	if (!bitstring)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	generateAllBitstrings(bitstring, 0, n, pred);
	free(bitstring);
}

int hasEqualOnesCountInBothHalves(const int* bitstring, const size_t n)
{
	assert(n % 2 == 0);
	
	int sum = 0;
	for (size_t i = 0; i < n / 2; i++)
	{
		sum += bitstring[i];
	}
	for (size_t i = n / 2; i < n; i++)
	{
		sum -= bitstring[i];
	}
	return sum == 0;
}

int main()
{
	printBitstrings(4, hasEqualOnesCountInBothHalves);
	return 0;
}
