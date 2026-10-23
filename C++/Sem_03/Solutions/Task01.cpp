#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int countOfLeapYears = 0;

	for (size_t i = 0; i < n; i++)
	{
		int year;
		cin >> year;

		if ((!(year % 4) && (year % 100)) || !(year % 400))
		{
			countOfLeapYears++;
		}
	}

	cout << countOfLeapYears;
}
