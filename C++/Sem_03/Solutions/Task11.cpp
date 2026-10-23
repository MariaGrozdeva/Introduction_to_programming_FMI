#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int p = 1;
		for (int j = 1; j <= i; j++)
			std::cout << p++ << ' ';

		for (int j = i; j <= n; j++)
			std::cout << "  ";

		for (int j = 1; j <= n; j++)
		{
			if (i == n)
				std::cout << "- ";
			else
				std::cout << "  ";
		}

		for (int j = i; j <= n; j++)
			std::cout << "  ";

		for (int j = 1; j <= i; j++)
			std::cout << --p << ' ';

		std::cout << '\n';
	}

	for (int i = 1; i < n; i++)
	{
		int p = 1;
		for (int j = i; j < n; j++)
			std::cout << p++ << ' ';

		for (int j = 1; j <= i; j++)
			std::cout << "  ";

		for (int j = 1; j <= n + 2; j++)
			std::cout << "  ";

		for (int j = 1; j <= i; j++)
			std::cout << "  ";

		for (int j = i; j < n; j++)
			std::cout << --p << ' ';

		std::cout << '\n';
	}

	return 0;
}