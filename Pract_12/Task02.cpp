#include <iostream>

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;

	return n * factorial(n - 1);
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << factorial(n);

	return 0;
}