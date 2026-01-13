#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int getMinimumOperations(unsigned int n)
{
	unsigned int* minOperations = (unsigned int*)malloc((n + 1) * sizeof(unsigned int));
	if (!minOperations)
	{
		return UINT_MAX;
	}

	for (size_t i = 0; i < n + 1; i++)
	{
		minOperations[i] = UINT_MAX;
	}

	minOperations[1] = 0;
	minOperations[2] = 1;
	minOperations[3] = 1;

	for (size_t i = 4; i <= n; i++)
	{
		unsigned int v1 = i % 3 == 0 ? minOperations[i / 3] : UINT_MAX;
		unsigned int v2 = i % 2 == 0 ? minOperations[i / 2] : UINT_MAX;
		unsigned int v3 = minOperations[i - 1];

		unsigned int minVal = v1;
		if (v2 < minVal) minVal = v2;
		if (v3 < minVal) minVal = v3;

		minOperations[i] = 1 + minVal;
	}

	unsigned int result = minOperations[n];
	free(minOperations);
	return result;
}

int main()
{
	printf("The minimum number of operations is %u\n", getMinimumOperations(962340));
	return 0;
}
