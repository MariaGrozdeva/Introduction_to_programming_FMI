#include <iostream>
using namespace std;

int main()
{
	unsigned n, m;
	cin >> n >> m;

	unsigned minNum = n < m ? n : m;
	unsigned gcd = 1;

	while (minNum >= 1)
	{
		if (n % minNum == 0 && m % minNum == 0)
		{
			gcd = minNum;
			break;
		}
		minNum--;
	}

	cout << gcd;
}