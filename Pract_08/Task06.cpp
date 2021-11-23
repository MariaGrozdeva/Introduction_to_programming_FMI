#include <iostream>

bool isSymbol(char ch)
{
	return ch < '0' || ch > '9';
}

unsigned strLen(const char str[])
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}

int transferToDigit(char ch)
{
	return ch - '0';
}

void removeAt(char str[], unsigned idx)
{
	unsigned len = strLen(str);
	for (size_t i = idx; i < len; i++)
	{
		str[i] = str[i + 1];
	}
	str[len - 1] = '\0';
}

int allDigitsAsNumber(char str[])
{
	int number = 0;
	unsigned len = strLen(str);
	for (size_t i = 0; i < len; i++)
	{
		if (isSymbol(str[i]))
		{
			removeAt(str, i);
			len--;
			i--;
		}
		else
			number = number * 10 + transferToDigit(str[i]);
	}

	return number;
}

int main()
{
	char str[] = "2hello5world9";
	std::cout << allDigitsAsNumber(str);

	return 0;
}