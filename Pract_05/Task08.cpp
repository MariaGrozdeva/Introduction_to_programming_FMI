#include <iostream>

int main()
{
	int num = 0;
	int k = 0;

	std::cin >> num;

	do
	{
		std::cin >> k;

		if (k == 0)
			std::cout << "Please enter a number greater than zero!\n";
	} while (k == 0);

	bool isInfix = true;
	bool hasChanged = false;
	int originalK = k;

	while (k > 0)
	{
		if (num == 0 && k > 0)
		{
			isInfix = false;
			break;
		}

		int reminder = k % 10;
		if (num % 10 == reminder)
		{
			k /= 10;
			num /= 10;
			hasChanged = true;
			continue;
		}

		if (hasChanged && !(num % 10 == reminder))
		{
			k = originalK;
			hasChanged = false;
			continue;
		}

		num /= 10;
	}

	std::cout << (isInfix ? "yes" : "no"); 

	return 0;
}