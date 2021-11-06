#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 || i == n || j == 1 || j == n)
				std::cout << '.';
			else
				std::cout << ' ';
		}

		if (n % 2 == 0)
		{
			for (int j = 1; j < n - 1; j++)
			{
				if (i == n / 2 || i == n / 2 + 1)
					std::cout << '.';
				else
					std::cout << ' ';
			}
		}
		else
		{
			for (int j = 1; j < n - 1; j++)
			{
				if (i == n / 2 + 1)
					std::cout << '.';
				else
					std::cout << ' ';
			}
		}

		for (int j = 1; j <= n; j++)
		{
			if (i == 1 || i == n || j == 1 || j == n)
				std::cout << '.';
			else
				std::cout << ' ';
		}

		std::cout << '\n';
	}
	return 0;
}
