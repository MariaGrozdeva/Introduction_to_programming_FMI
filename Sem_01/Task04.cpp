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

	short firstDigit = n % 10; // get the first digit

	int reversed = thirdDigit * 100 + secondDigit * 10 + firstDigit;
	reversed++;

	cout << reversed << endl;
}