#include <iostream>

int strLen(const char* str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

int findNewLenOfTheString(const char* str)
{
	int len = strLen(str);
	const int toRepaceLen = 5;
	int newLen = 0;

	for (int i = 0; i < len; i++)
	{
		bool flag = false;
		while (isDigit(str[i]))
		{
			flag = true;
			i++;
		}
		
		if (flag)
			newLen += toRepaceLen;
		
		newLen++;
	}

	return newLen;
}

void censor(char*& str)
{
	const char* toReplace = "_NUM_";
	const int toRepaceLen = 5;
	int len = strLen(str);
	int newLen = findNewLenOfTheString(str);
	
	char* newStr = new char[newLen + 1];
	if (!newStr)
	{
		std::cerr << "Can't allocate memory!\n";
		return;
	}

	for (int i = 0, j = 0; i < len; i++)
	{
		int idx = 0; // Index of toReplace

		// Move the index to the last position that has a digit + 1
		if (isDigit(str[i]))
		{
			while (isDigit(str[i]))
				i++;
		}

		// Here "i - 1" is the last position that has a digit
		if (isDigit(str[i - 1]))
		{
			// Copying _NUM_ in newStr
			while (idx < toRepaceLen)
				newStr[j++] = toReplace[idx++];
		}

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
	std::cin.getline(str, maxSize);

	int len = strLen(str);

	char* buffer = new char[len + 1];
	if (!buffer)
	{
		std::cerr << "can't allocate memory!\n";
		return -1;
	}

	for (int i = 0; i < len; i++)
		buffer[i] = str[i];

	buffer[len] = '\0';

	censor(buffer);
	std::cout << buffer;

	delete[] buffer;
	

	return 0;
}