#include <iostream>
using namespace std;

void printLongestSubsequenceOfEqualNumbers(unsigned n) // It's actually subarray, not subsequence, but arrays are not studied yet
{
	short max = 1; // The LSEN will always consist of at least one element
	short currentMax = 1;
	short digitFromMaxSubseq = n % 10;

	while (n >= 10)
	{
		short lastDigit = n % 10;
		short preLastDigit = (n / 10) % 10;

		if (preLastDigit == lastDigit)
		{
			currentMax++;
			if (currentMax > max)
			{
				max = currentMax;
				digitFromMaxSubseq = preLastDigit;
			}
		}
		else
		{
			currentMax = 1;
		}

		n /= 10;
	}
	cout << max << " (" << digitFromMaxSubseq << ")";
}

int main()
{
	printLongestSubsequenceOfEqualNumbers(1777444329);
}