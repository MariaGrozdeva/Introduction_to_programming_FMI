#include <iostream>
using namespace std;

unsigned long long toBinary(unsigned int n)
{
	unsigned long long binaryNum = 0;
	unsigned long long multiplier = 1;

	while (n != 0)
	{
		if (n % 2 == 1)
		{
			binaryNum += multiplier;
		}
		multiplier *= 10;
		n /= 2;
	}

	return binaryNum;
}

int main()
{
	cout << toBinary(55);
}
