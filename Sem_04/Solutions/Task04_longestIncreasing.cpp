#include <iostream>
using namespace std;

short longestIncreasingSubsequence(unsigned n) // It's actually subarray, not subsequence, but arrays are not studied yet
{
	short max = 1; // The LIS will always consist of at least one element
	short currentMax = 1;

	while (n >= 10)
	{
		short lastDigit = n % 10;
		short preLastDigit = (n / 10) % 10;

		if (preLastDigit < lastDigit)
		{
			currentMax++;
			if (currentMax > max)
			{
				max = currentMax;
			}
		}
		else
		{
			currentMax = 1;
		}

		n /= 10;
	}
	return max;
}

int main()
{
	cout << longestIncreasingSubsequence(781234489);
}