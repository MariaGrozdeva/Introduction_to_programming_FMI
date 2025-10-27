#include <iostream>
using namespace std;

int main()
{
	unsigned n, m;
	cin >> n >> m;

	if (n < m)
	{
		unsigned temp = n;
		n = m;
		m = temp;
	}

	while (m != 0)
	{
		unsigned mod = n % m;
		n = m;
		m = mod;
	}
	cout << n;
}