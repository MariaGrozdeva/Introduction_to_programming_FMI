#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned n)
{
	if (n <= 1)
	{
		return false;
	}

	unsigned sqrtN = sqrt(n);
	for (size_t divisorCandidate = 2; divisorCandidate <= sqrtN; divisorCandidate++)
	{
		if (n % divisorCandidate == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	unsigned n;
	cin >> n;

	for (size_t i = 6; i < n - 1; i += 6)
	{
		if (isPrime(i - 1) && isPrime(i + 1))
		{
			cout << '<' << i - 1 << ", " << i + 1 << '>' << endl;
		}
	}
}
