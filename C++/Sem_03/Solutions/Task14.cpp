#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	bool match = false;
	int cnt = 0;

	for (size_t i = a; i <= b; i++)
	{
		int sum = 0;
		int prod = 1;

		int temp = i;
		while (temp)
		{
			int reminder = temp % 10;

			if (reminder == 0)
			{
				prod = 1;
			}

			sum += reminder;
			prod *= reminder;

			temp /= 10;
		}

		if (sum == prod)
		{
			cnt++;
		}
	}

	cout << cnt;
}
