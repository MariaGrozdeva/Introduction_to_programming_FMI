#include <iostream>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;
	
	for (size_t i = 2; i <= n; i++)
	{
		// check how many times i divides n
		unsigned count = 0;
		while (n % i == 0)
		{
			count++;
			n /= i;
		}
		if (count >= 1)
		{
			cout << i << '^' << count << ' ';
		}
	}
}
