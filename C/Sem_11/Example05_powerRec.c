#include <stdio.h>

unsigned long long power(unsigned int n, unsigned int k)
{
	if (k == 0)
	{
		return 1;
	}

	if (k % 2 == 1)
	{
		return n * power(n, k - 1);
	}
	else
	{
		unsigned long long temp = power(n, k / 2);
		return temp * temp;
	}
}

int main()
{
	printf("%llu", power(5, 4));
	return 0;
}
