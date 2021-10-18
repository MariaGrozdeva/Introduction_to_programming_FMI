#include <iostream>
using namespace std;

int main()
{
	int n, initialSum;
	cin >> n;
	initialSum = n;

	int oneHundredLeva = 0;
	int fiftyLeva = 0;
	int twentyLeva = 0;
	int tenLeva = 0;
	int fiveLeva = 0;
	int twoLeva = 0;
	int oneLev = 0;

	oneHundredLeva = n / 100;
	n %= 100;
	fiftyLeva = n / 50;
	n %= 50;
	twentyLeva = n / 20;
	n %= 20;
	tenLeva = n / 10;
	n %= 10;
	fiveLeva = n / 5;
	n %= 5;
	twoLeva = n / 2;
	n %= 2;
	oneLev = n;

	cout << initialSum << " = " << oneHundredLeva << "*100 + " << fiftyLeva << "*50 + " << twentyLeva << "*20 + " << tenLeva << "*10 + " <<
		fiveLeva << "*5 + " << twoLeva << "*2 + " << oneLev << "*1" << endl;
}