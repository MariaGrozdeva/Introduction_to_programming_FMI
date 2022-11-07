#include <iostream>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;

	for (size_t i = 10, currentSuffix = 0; n != currentSuffix; i *= 10)
	{
		currentSuffix = n % i;

		unsigned tempCurrentSuffix = currentSuffix;
		unsigned reversedCurrentSuffix = 0;
		while (tempCurrentSuffix != 0)
		{
			short lastDigit = tempCurrentSuffix % 10;
			(reversedCurrentSuffix *= 10) += lastDigit;
			tempCurrentSuffix /= 10;
		}

		if (currentSuffix == reversedCurrentSuffix)
		{
			cout << currentSuffix << endl;
		}
	}
}