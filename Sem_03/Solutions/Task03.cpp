#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	for (size_t i = a; i <= b; i++)
	{
		int keepI = i;
		bool unique = true;

		while (keepI != 0)
		{
			int quotient = keepI / 10;
			int remainder = keepI % 10;

			while (quotient != 0)
			{
				if (remainder == quotient % 10)
				{
					unique = false;
					break;
				}
				quotient /= 10;
			}

			if (!unique)
			{
				break;
			}

			keepI /= 10;
		}

		if (unique)
		{
			cout << i << "    ";
		}
	}
}
