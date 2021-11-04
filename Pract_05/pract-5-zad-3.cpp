#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int numOfSpace = n * 5 - 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";

			if (j == n)
			{
				for (int h = 0; h < n; h++)
					cout << "-";
			}

			if (j == i)
			{
				for (int k = 1; k <= numOfSpace; k++)
				{
					if (k == numOfSpace)
					{
						for (int g = j; g > 0; g--)
						{
							cout << g << " ";
						}
						if (j == n - 1)
							numOfSpace -= (n + 4);
						else
							numOfSpace -= 4;
					}
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	numOfSpace = n + 6;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			cout << j << " ";

			if (j == n - i)
			{
				for (int k = 1; k <= numOfSpace; k++)
				{
					if (k == numOfSpace)
					{
						for (int g = j; g > 0; g--)
						{
							cout << g << " ";
						}
					}
					cout << " ";

				}
				numOfSpace += 4;
			}


		}
		cout << endl;
	}
}
//