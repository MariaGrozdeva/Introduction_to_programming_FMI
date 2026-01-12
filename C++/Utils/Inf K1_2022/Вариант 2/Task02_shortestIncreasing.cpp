#include <iostream>
using namespace std;

void printShortestSubsequenceOfEqualNumbers(unsigned long long n) // It's actually subarray, not subsequence, but arrays are not studied yet
{
	short min = SHRT_MAX; // identity element for the min operation
	short currentMin = 1;
	short digitFromMinSubseq = n % 10;

	while (n >= 10)
	{
		short lastDigit = n % 10;
		short preLastDigit = (n / 10) % 10;

		if (preLastDigit == lastDigit)
		{
			currentMin++;
		}                                         
		else
		{
			if (currentMin < min)
			{
				min = currentMin;
				digitFromMinSubseq = lastDigit;
			}
			currentMin = 1;
		}

		n /= 10;
	}

	if (currentMin < min) // Corner case when the min subsequence is in the beginning and consists of >= 2 digits
	{
		cout << currentMin << " (" << n << ")";
		return;
	}
	cout << min << " (" << digitFromMinSubseq << ")";
}

int main()
{
	printShortestSubsequenceOfEqualNumbers(11133335555);
}