#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	if (n == 0)
	{
		cout << "Invalid number!";
		return 0;
	}
	if (k == 0 || k == 1)
	{
		cout << "Invalid base!";
		return 0;
	}

	int log = 0;

	while (n >= k)
	{
		n /= k;
		log++;
	}

	cout << log;
}