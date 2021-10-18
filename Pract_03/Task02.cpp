#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int thirdDigit = n % 10;
	int secondDigit = (n / 10) % 10;
	int firstDigit = n / 100;

	int maxDigit, minDigit;

	if (thirdDigit >= secondDigit && thirdDigit >= firstDigit)
	{
		maxDigit = thirdDigit;	

		if (secondDigit >= firstDigit)
		{
			minDigit = firstDigit;
		}
		else
		{
			minDigit = secondDigit;
		}
	}
	else if (secondDigit >= thirdDigit && secondDigit >= firstDigit)
	{
		maxDigit = secondDigit;

		if (thirdDigit >= firstDigit)
		{
			minDigit = firstDigit;
		}
		else
		{
			minDigit = thirdDigit;
		}
	}
	else
	{
		maxDigit = firstDigit;

		if (thirdDigit >= secondDigit)
		{
			minDigit = secondDigit;
		}
		else
		{
			minDigit = thirdDigit;
		}
	}

	cout << "Min digit is: " << minDigit << endl << "Max digit is: " << maxDigit;
}