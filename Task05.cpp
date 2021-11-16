#include <iostream>

bool isPrime(int num)
{
	if (num < 2)
		return false;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	
	return true;
}

void eratosten(int n)
{
	for (size_t i = 2; i <= n; i++)
	{
		if (isPrime(i))
			std::cout << i << ' ';
	}
	std::cout << '\n';
}

void input(int& n)
{	
	std::cout << "Input number: ";
	std::cin >> n;
	while (n < 0 || n > 1000)
	{
		std::cout << "Wrong input! Try again: ";
		std::cin >> n;
	}
}

int main()
{
	int n;
	input(n);
	eratosten(n);

	return 0;
}