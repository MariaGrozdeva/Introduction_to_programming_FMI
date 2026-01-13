#include <stdio.h>
#include <stdlib.h>

void printBitstring(const int* bitstring, const unsigned int* set, const size_t size)
{
	printf("{ ");
	for (size_t i = 0; i < size; i++)
	{
		if (bitstring[i])
		{
			printf("%u ", set[i]);
		}
	}
	printf("}\n");
}

void generateAllSubsets(int* bitstring, unsigned int pos, const size_t size, const unsigned int* set)
{
	if (pos == size)
	{
		printBitstring(bitstring, set, size);
		return;
	}

	bitstring[pos] = 0;
	generateAllSubsets(bitstring, pos + 1, size, set);

	bitstring[pos] = 1;
	generateAllSubsets(bitstring, pos + 1, size, set);
}

void printSubsets(const unsigned int* set, const size_t size)
{
	int* bitstring = (int*)malloc(size * sizeof(int));
	if (!bitstring)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}

	generateAllSubsets(bitstring, 0, size, set);
	free(bitstring);
}

int main()
{
	unsigned int arr[] = { 1, 2, 3, 4 };
	printSubsets(arr, sizeof(arr) / sizeof(unsigned int));
	return 0;
}
