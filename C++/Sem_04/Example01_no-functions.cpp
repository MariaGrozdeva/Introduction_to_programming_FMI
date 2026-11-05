#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;

	for (size_t i = 6; i < n - 1; i += 6)
	{
		unsigned firstToCheck = i - 1;
		unsigned secondToCheck = i + 1;

		// prime check
		bool isFirstPrime = true;
		double sqrtFirstToCheck = sqrt(firstToCheck);
		for (size_t divisorCandidate = 2; divisorCandidate <= sqrtFirstToCheck; divisorCandidate++)
		{
			if (firstToCheck % divisorCandidate == 0)
			{
				isFirstPrime = false;
			}
		}

		if (!isFirstPrime)
		{
			continue;
		}

		// prime check
		bool isSecondPrime = true;
		double sqrtSecondToCheck = sqrt(secondToCheck);
		for (size_t divisorCandidate = 2; divisorCandidate <= sqrtSecondToCheck; divisorCandidate++)
		{
			if (secondToCheck % divisorCandidate == 0)
			{
				isSecondPrime = false;
			}
		}

		if (isSecondPrime)
		{
			cout << '<' << i - 1 << ", " << i + 1 << '>' << endl;
		}
	}
}
