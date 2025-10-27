#include <iostream>
using namespace std;

int main()
{
	int grade;
	cin >> grade;

	if (grade == 2)
	{
		cout << "Bad";
	}
	else if (grade == 3)
	{
		cout << "Average";
	}
	else if (grade == 4)
	{
		cout << "Good";
	}
	else if (grade == 5)
	{
		cout << "Very good";
	}
	else if (grade == 6)
	{
		cout << "Excellent";
	}
	else
	{
		cout << "Invalid grade!";
	}
}