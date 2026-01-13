#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	short thirdDigit = n % 10; // get the last digit
	n /= 10; // remove the last digit

	short secondDigit = n % 10; // get the second digit
	n /= 10; // remove the second digit

	int reversed = thirdDigit * 100 + secondDigit * 10 + n; // n is already consisting of only one digit
	reversed++;

	cout << reversed << endl;
}
