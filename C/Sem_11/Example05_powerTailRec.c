#include <stdio.h>

unsigned long long powerTailRec(unsigned int n, unsigned int k, unsigned long long result)
{
	if (k == 0)
	{
		return result;
	}

	if (k % 2 == 1)
	{
		return powerTailRec(n, k - 1, n * result);
	}
	else
	{
		return powerTailRec(n * n, k / 2, result);
	}
}

unsigned long long power(unsigned int n, unsigned int k)
{
	return powerTailRec(n, k, 1);
}

int main()
{
	printf("%llu", power(5, 4));
	return 0;
}
