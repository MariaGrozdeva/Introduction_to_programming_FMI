#include <iostream>

unsigned strLen(const char str[])
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}

void toCapicalLetter(char& letter)
{
	if (letter >= 'a' && letter <= 'z')
		letter -= 'a' - 'A';
}

void allToCapitalLetter(char str[])
{
	unsigned len = strLen(str);
	for (size_t i = 0; i < len; i++)
		toCapicalLetter(str[i]);
}

int main()
{
	char str[] = "heLLo_WorLd";
	allToCapitalLetter(str);
	std::cout << str;

	return 0;
}