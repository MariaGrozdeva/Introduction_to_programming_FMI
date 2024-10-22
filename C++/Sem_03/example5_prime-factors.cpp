#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;
	
	for (size_t i = n; i > 1; i--)
	{
		// primality check
		bool isPrime = true;
		double temp = sqrt(i);
		for (size_t divisorCandidate = 2; divisorCandidate <= temp; divisorCandidate++)
		{
			if (i % divisorCandidate == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (!isPrime)
		{
			continue; // we don't need this number
		}

		// check how many times i divides n
		unsigned count = 0;
		while (n % i == 0)
		{
			count++;
			n /= i;
		}
		if (count >= 1)
		{
			cout << i << '^' << count << ' ';
		}
	}
}
