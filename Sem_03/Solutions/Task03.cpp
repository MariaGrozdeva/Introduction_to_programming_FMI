#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		int keep_i = i;
		bool unique = true;

		while (keep_i != 0)
		{
			int quotient = keep_i / 10;
			int remainder = keep_i % 10;

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
				break;

			keep_i /= 10;
		}

		if (unique)
			cout << i << "    ";
	}
}