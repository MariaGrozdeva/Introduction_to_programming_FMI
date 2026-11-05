#include <iostream>
using namespace std;

const short DIGITS_COUNT = 4;

short getDigitsCount(unsigned number)
{
	short digitsCount = 0;

	while (number)
	{
		number /= 10;
		digitsCount++;
	}

	return digitsCount;
}

bool containsDigit(unsigned number, short digit)
{
	while (number)
	{
		if (number % 10 == digit)
		{
			return true;
		}

		number /= 10;
	}
	return false;
}

bool areDigitsDifferent(unsigned number)
{
	while (number)
	{
		short currentDigit = number % 10;
		number /= 10;

		if (containsDigit(number, currentDigit))
		{
			return false;
		}
	}
	return true;
}

bool isInputValid(unsigned input)
{
	return (getDigitsCount(input) == DIGITS_COUNT) && areDigitsDifferent(input);
}

void input(unsigned& toGuess)
{
	do
	{
		cin >> toGuess;
	} while (!isInputValid(toGuess));
}

short getBulls(unsigned toGuess, unsigned myGuess)
{
	short bulls = 0;

	while (toGuess)
	{
		if (toGuess % 10 == myGuess % 10)
		{
			bulls++;
		}

		toGuess /= 10;
		myGuess /= 10;
	}

	return bulls;
}

short getCows(unsigned toGuess, unsigned myGuess, short bulls)
{
	short cows = 0;

	while (myGuess)
	{
		short currentDigit = myGuess % 10;
		if (containsDigit(toGuess, currentDigit))
		{
			cows++;
		}

		myGuess /= 10;
	}

	return cows - bulls;
}

void getBullsAndCows(unsigned toGuess, unsigned myGuess, short& bulls, short& cows)
{
	bulls = getBulls(toGuess, myGuess);
	cows = getCows(toGuess, myGuess, bulls);
}

int main()
{
	cout << "Enter a number to be guessed:" << endl;
	unsigned toGuess;
	input(toGuess);

	short bulls = 0;
	short cows = 0;

	while (bulls != DIGITS_COUNT)
	{
		cout << endl << "Enter a guess:" << endl;
		unsigned myGuess;
		input(myGuess);

		getBullsAndCows(toGuess, myGuess, bulls, cows);

		cout << "Bulls: " << bulls << ' ' << ", Cows: " << cows << endl;
	}

	cout << "Success!" << endl;
}
