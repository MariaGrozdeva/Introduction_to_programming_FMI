#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// Upper part of the hourglass
	int numOfStars = 2 * n + 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 0; j < numOfStars; j++)
			cout << '*';
		for (int j = 0; j < i; j++)
			cout << ' ';

		numOfStars -= 2;
		cout << endl;
	} // numOfStars = 1;

	for (int i = 0; i < n; i++)
		cout << ' ';

	cout << '*'; // middle star

	for (int i = 0; i < n; i++)
		cout << ' ';
	cout << endl;

	// Lower part of the hourglass
	for (int i = 0; i < n; i++)
	{
		numOfStars += 2;

		for (int j = 0; j < n - i - 1; j++)
			cout << ' ';
		for (int j = 0; j < numOfStars; j++)
			cout << '*';
		for (int j = 0; j < n - i - 1; j++)
			cout << ' ';

		cout << endl;
	}
}