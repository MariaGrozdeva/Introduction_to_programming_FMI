#include <iostream>
using namespace std;

// naive recursive solution
unsigned long long factorialRecNaive(unsigned int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorialRecNaive(n - 1);
	}
}

// solution with tail recursion (equivalent to iterative solution)
unsigned long long factorialTailRec(unsigned int n, unsigned int result)
{
	if (n == 0)
	{
		return result;
	}

	return factorialTailRec(n - 1, n * result);
}
unsigned long long factorial(unsigned int n)
{
	return factorialTailRec(n, 1);
}

int main()
{
	cout << factorial(5);
}