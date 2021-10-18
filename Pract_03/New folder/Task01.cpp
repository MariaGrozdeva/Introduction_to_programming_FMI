#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int reversed = (n % 10) * 100 + ((n / 10) % 10) * 10 + n / 100;
	reversed += 1;

	cout << reversed;
}