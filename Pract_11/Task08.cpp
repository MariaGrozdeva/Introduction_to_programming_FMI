#include <iostream>
using namespace std;

const int maxDigitsNumber = 10;
const char arrayOfDigits[][maxDigitsNumber] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const int digitsLen[maxDigitsNumber] = { 4,     3,     3,       5,      4,      4,     3,       5,      5,       4 }; // Not the finest way, but 'enum' is not studied

int strLen(const char* str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return  len;
}

bool isDigit(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

int calculateLenOfNewString(const char* str)
{
	int lenOfOriginalString = strLen(str);
	int newLen = 0;

	for (int i = 0; i < lenOfOriginalString; i++)
	{
		if (isDigit(str[i]))
		{
			switch (str[i])
			{
			case '0':
			case '4':
			case '5':
			case '9':
				newLen += 4;
				break;

			case '1':
			case '2':
			case '6':
				newLen += 3;
				break;

			case '3':
			case '7':
			case '8':
				newLen += 5;
				break;

			default:
				break;
			}
		}
		else
			newLen++;
	}

	return newLen;
}

void convertDigitIntoWord(char*& newStr, int digit, int digitWordLen, int& newStrIdx)
{
	for (int k = 0; k < digitWordLen; k++)
		newStr[newStrIdx++] = arrayOfDigits[digit][k];
}

void digitsTransformInString(char*& str)
{
	int len = strLen(str);
	int newLen = calculateLenOfNewString(str);

	char* newStr = new char[newLen + 1];
	if (!newStr)
	{
		cerr << "Can't allocate memory!" << endl;
		return;
	}

	for (int i = 0, j = 0; i < len; i++)
	{
		if (isDigit(str[i]))
		{
			switch (str[i])
			{
			case '0':
				convertDigitIntoWord(newStr, 0, digitsLen[0], j);
				break;

			case '1':
				convertDigitIntoWord(newStr, 1, digitsLen[1], j);
				break;

			case '2':
				convertDigitIntoWord(newStr, 2, digitsLen[2], j);
				break;

			case '3':
				convertDigitIntoWord(newStr, 3, digitsLen[3], j);
				break;

			case '4':
				convertDigitIntoWord(newStr, 4, digitsLen[4], j);
				break;

			case '5':
				convertDigitIntoWord(newStr, 5, digitsLen[5], j);
				break;

			case '6':
				convertDigitIntoWord(newStr, 6, digitsLen[6], j);
				break;

			case '7':
				convertDigitIntoWord(newStr, 7, digitsLen[7], j);
				break;

			case '8':
				convertDigitIntoWord(newStr, 8, digitsLen[8], j);
				break;

			case '9':
				convertDigitIntoWord(newStr, 9, digitsLen[9], j);
				break;

			default:
				break;
			}
		}
		else
			newStr[j++] = str[i];

	}
	newStr[newLen] = '\0';

	delete[] str;
	str = newStr;
}

int main()
{
	const int maxSize = 512;
	char str[maxSize];

	cin.getline(str, maxSize);
	int len = strLen(str);

	char* buffer = new char[len + 1];
	if (!buffer)
	{
		cerr << "Can't allocate memory!\n";
		return -1;
	}

	for (int i = 0; i < len; i++)
		buffer[i] = str[i];

	buffer[len] = '\0';

	digitsTransformInString(buffer);
	cout << buffer;

	delete[] buffer;
}
