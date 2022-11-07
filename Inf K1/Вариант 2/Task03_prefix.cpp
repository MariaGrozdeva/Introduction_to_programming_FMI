#include <iostream>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;

	for (size_t i = 1, currentPrefix;; i *= 10)
	{
		currentPrefix = n / i;
		if (currentPrefix == 0)
			break;

		unsigned tempCurrentPrefix = currentPrefix;
		unsigned reversedCurrentPrefix = 0;
		while (tempCurrentPrefix != 0)
		{
			short lastDigit = tempCurrentPrefix % 10;
			(reversedCurrentPrefix *= 10) += lastDigit;
			tempCurrentPrefix /= 10;
		}

		if (currentPrefix == reversedCurrentPrefix)
		{
			cout << currentPrefix << endl;
		}
	}
}