#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printBitstring(const int* bitstring, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d", bitstring[i]);
	}
	printf("\n");
}

void generateAllBitstringsWithEqualSum(unsigned start, unsigned end, int diff, int* bitstring, const size_t size)
{
	if (abs(diff) > (int)((end - start + 1) / 2))
	{
		return;
	}
	if (start > end && diff == 0)
	{
		printBitstring(bitstring, size);
		return;
	}

	bitstring[start] = bitstring[end] = 0;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff, bitstring, size);

	bitstring[start] = bitstring[end] = 1;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff, bitstring, size);

	bitstring[start] = 0;
	bitstring[end] = 1;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff + 1, bitstring, size);

	bitstring[start] = 1;
	bitstring[end] = 0;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff - 1, bitstring, size);
}

void generateAllBitstringsWithEqualSum(size_t n)
{
	int* bitstring = (int*)malloc(2 * n * sizeof(int));
	if (!bitstring)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	generateAllBitstringsWithEqualSum(0, 2 * n - 1, 0, bitstring, 2 * n);
	
	free(bitstring);
}

int main()
{
	size_t n;
	scanf("%zu", &n);

	generateAllBitstringsWithEqualSum(n);
	return 0;
}
