#include <iostream>
using namespace std;

const int digitsCount = 4;

int getDigitsCount(int number)
{
	int digitsCount = 0;

	while (number)
	{
		number /= 10;
		digitsCount++;
	}

	return digitsCount;
}
bool containsDigit(int number, int digit)
{
	while (number)
	{
		if (number % 10 == digit)
			return true;

		number /= 10;
	}
	return false;
}
bool areDigitsDifferent(int number)
{
	while (number)
	{
		int currentDigit = number % 10;
		number /= 10;

		if (containsDigit(number, currentDigit))
			return false;
	}
	return true;
}
bool isInputValid(int input)
{
	return (getDigitsCount(input) == digitsCount) && areDigitsDifferent(input);
}

void input(int& toGuess)
{
	do
	{
		cin >> toGuess;
	} while (!isInputValid(toGuess));
}

int getBulls(int toGuess, int myGuess)
{
	int bulls = 0;

	while (toGuess)
	{
		if (toGuess % 10 == myGuess % 10)
			bulls++;

		toGuess /= 10;
		myGuess /= 10;
	}

	return bulls;
}
int getCows(int toGuess, int myGuess, int bulls)
{
	int cows = 0;

	while (myGuess)
	{
		int currentDigit = myGuess % 10;

		if (containsDigit(toGuess, currentDigit))
			cows++;

		myGuess /= 10;
	}

	return cows - bulls;
}
void getBullsAndCows(int toGuess, int myGuess, int& bulls, int& cows)
{
	bulls = getBulls(toGuess, myGuess);
	cows = getCows(toGuess, myGuess, bulls);
}

int main()
{
	cout << "Enter number to be guessed:" << endl;
	int toGuess;
	input(toGuess);

	int bulls = 0;
	int cows = 0;

	while (bulls != digitsCount)
	{
		cout << endl << "Enter a guess:" << endl;
		int myGuess;
		input(myGuess);

		getBullsAndCows(toGuess, myGuess, bulls, cows);

		cout << "Bulls: " << bulls << ' ' << ", Cows: " << cows << endl;
	}

	cout << "Success!" << endl;
}