#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;

	bool isPrime = true;
	unsigned sqrtOfN = sqrt(n);

	if (n <= 1)
	{
		isPrime = false;
	}
	for (size_t divisorCandidate = 2; divisorCandidate <= sqrtOfN; divisorCandidate++)
	{
		if (n % divisorCandidate == 0)
		{
			isPrime = false;
			break;
		}
	}
	cout << isPrime << endl;
}
