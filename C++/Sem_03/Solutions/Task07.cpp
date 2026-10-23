#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int start = (i * n) + 1;
		int end = (start + n) - 1;

		if (i % 2 == 0)
		{
			for (int j = start; j <= end; j++)
			{
				cout << j << ' ';
			}
			cout << endl;
		}
		else
		{
			for (int j = end; j >= start; j--)
			{
				cout << j << ' ';
			}
			cout << endl;
		}
	}
}
