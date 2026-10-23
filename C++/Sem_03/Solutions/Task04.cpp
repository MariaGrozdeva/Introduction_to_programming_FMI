#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int inputNumber = n;
	int reversed = 0;

	while (n > 0)
	{
		(reversed *= 10) += n % 10;
		n /= 10;
	}

	cout << (inputNumber == reversed);
}