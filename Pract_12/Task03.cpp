#include <iostream>

int power(int n, int k)
{
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	if (n == 0)
		return 0;

	return n * power(n, k - 1);
}

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::cout << power(n, k);

	return 0;
}