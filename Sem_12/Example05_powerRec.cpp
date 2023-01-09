#include <iostream>
using namespace std;

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
	cout << power(5, 4);
}